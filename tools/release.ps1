# Build a signed, Workshop-ready release.
#
# Runs `hemtt release` (unsigned; see .hemtt/project.toml), signs every PBO
# with the community's ptf2.1 key using DSSignFile from Arma 3 Tools, ships
# the matching .bikey, and zips the mod folder into releases\.
#
# The private key is never copied anywhere; only the .bisign/.bikey outputs
# leave the key directory.
param(
    # Folder containing <KeyName>.biprivatekey and <KeyName>.bikey. Defaults
    # to $env:PTF_KEYS_DIR so no machine-specific path lives in the repo.
    [string]$KeyDir = $env:PTF_KEYS_DIR,
    [string]$KeyName = "ptf2.1",
    # Folder holding the PBOs that ship with the mod but are not in git
    # (reuploads / obfuscated third-party addons, incl. ctab — see
    # BUILDING.md). They are merged into the release and signed. Required
    # for a real release (defaults to $env:PTF_EXTERNAL_ADDONS); use
    # -NoExternal for a deliberate repo-only build.
    [string]$ExternalAddons = $env:PTF_EXTERNAL_ADDONS,
    # Where the ready-to-use "@[PTF] Paramarine Milsim Core" mod folder is
    # published. Defaults to $env:PTF_RELEASE_DIR, then <repo>\releases. Point
    # it at your Arma 3 mods folder and the build lands ready to load.
    [string]$OutputDir = $env:PTF_RELEASE_DIR,
    # Build only the repo-tracked PBOs, skipping the external merge. The
    # resulting mod is incomplete — intended for dev/testing, not release.
    [switch]$NoExternal,
    # Skip signing entirely (no key or Arma 3 Tools needed). For quick local
    # dev builds; the output is UNSIGNED — never upload it to the Workshop.
    [switch]$NoSign,
    # Also produce a .zip alongside the mod folder. Off by default: Arma and the
    # Arma 3 Publisher both take a folder, so zipping just means unzipping again.
    # Useful only for archiving or handing the build to someone else.
    [switch]$Zip,
    # Full rebuild: wipe the build output, re-copy every external PBO and
    # re-sign everything, and overwrite an existing zip for this version.
    # Default is incremental — externals are copied only when newer/different,
    # and a PBO is re-signed only when its .bisign is missing or out of date.
    [switch]$Force
)
$ErrorActionPreference = "Stop"
$repo = Split-Path -Parent $PSScriptRoot
if (-not $OutputDir) { $OutputDir = Join-Path $repo "releases" }

if (-not $NoSign -and -not $KeyDir) {
    throw "No signing key directory. Pass -KeyDir <folder> or set `$env:PTF_KEYS_DIR " +
          "(the folder holding $KeyName.biprivatekey and $KeyName.bikey), or pass " +
          "-NoSign for an unsigned local build."
}
if (-not $NoExternal -and -not $ExternalAddons) {
    throw "No external PBO folder. Pass -ExternalAddons <folder> or set " +
          "`$env:PTF_EXTERNAL_ADDONS (the ~40 PBOs not built from git, incl. ctab). " +
          "For a deliberate repo-only build, pass -NoExternal."
}
if (-not $NoSign) {
    $privateKey = Join-Path $KeyDir "$KeyName.biprivatekey"
    $publicKey  = Join-Path $KeyDir "$KeyName.bikey"
    if (-not (Test-Path $privateKey)) { throw "Private key not found: $privateKey" }
    if (-not (Test-Path $publicKey))  { throw "Public key not found: $publicKey" }
}

# hemtt: PATH first, then the winget install location
$hemtt = Get-Command hemtt -ErrorAction SilentlyContinue
if ($hemtt) { $hemtt = $hemtt.Source }
else {
    $hemtt = Get-ChildItem "$env:LOCALAPPDATA\Microsoft\WinGet\Packages" -Filter hemtt.exe -Recurse -ErrorAction SilentlyContinue |
        Select-Object -First 1 -ExpandProperty FullName
    if (-not $hemtt) { throw "hemtt not found; install with: winget install BrettMayson.HEMTT" }
}

# DSSignFile from Arma 3 Tools (registry lookup) — only needed for signing
if (-not $NoSign) {
    $a3tools = (Get-ItemProperty "HKCU:\SOFTWARE\Bohemia Interactive\Arma 3 Tools").path
    $dsSign = Join-Path $a3tools "DSSignFile\DSSignFile.exe"
    if (-not (Test-Path $dsSign)) { throw "DSSignFile not found: $dsSign" }
    # DSCheckSignatures verifies each PBO's signature against the public key.
    # It lives next to DSSignFile in some installs and in its own folder in
    # others; probe both. Optional — we warn (not fail) if it isn't present.
    $dsCheck = @(
        (Join-Path $a3tools "DSSignFile\DSCheckSignatures.exe"),
        (Join-Path $a3tools "DSCheckSignatures\DSCheckSignatures.exe")
    ) | Where-Object { Test-Path $_ } | Select-Object -First 1
}

$timings = [ordered]@{}
$swTotal = [System.Diagnostics.Stopwatch]::StartNew()

Push-Location $repo
try {
    $out = Join-Path $repo ".hemttout\release"
    # hemtt does not clean its release output. Rather than wipe the whole folder
    # every run (which forced a full multi-GB re-copy and re-sign of the ~40
    # external PBOs), we keep it and prune precisely: after the external merge
    # below, anything that isn't part of THIS release is deleted. That kills the
    # stale-PBO leak just as reliably while letting the copy/sign steps skip work
    # that's already current. -Force restores the old wipe-everything behaviour.
    if ($Force -and (Test-Path -LiteralPath $out)) {
        Write-Host "-Force: wiping $out for a full rebuild"
        Remove-Item -LiteralPath $out -Recurse -Force
    }

    # Derive the X.Y.Z version from git and write MINOR/PATCH into
    # script_version.hpp BEFORE building, so the PBOs carry the right version.
    # This mirrors tools/gen-version.sh (used by CI) but is implemented natively
    # so it needs no `sh` on PATH. Pull tags first (best effort) so a release tag
    # cut by CI is visible: on master after that tag exists this yields the
    # release version (X.Y.0); on develop it yields the dev version.
    #   X (MAJOR) : hand-maintained in script_version.hpp.
    #   Y (MINOR) : number of release tags at this major (v<MAJOR>.*).
    #   Z (PATCH) : first-parent commits since the most recent release tag.
    git fetch --tags --quiet 2>$null
    $verFile = Join-Path $repo "addons\PTF_Main\script_version.hpp"
    $vhText = Get-Content -Raw $verFile
    if ($vhText -notmatch '#define\s+MAJOR\s+(\d+)') {
        throw "script_version.hpp is missing #define MAJOR."
    }
    $major = [int]$Matches[1]

    $minor = @(git tag -l "v$major.*").Count
    $allTags = @(git tag -l 'v*')
    $lastTag = $allTags |
        Where-Object { $_ -match '^v(\d+)\.(\d+)\.(\d+)$' } |
        Sort-Object { [version]($_.Substring(1)) } |
        Select-Object -Last 1
    if ($lastTag) {
        $patch = [int](git rev-list --count --first-parent "$lastTag..HEAD")
    }
    else {
        $patch = [int](git rev-list --count --first-parent HEAD)
    }

    $vhText = $vhText -replace '#define\s+MINOR\s+\d+', "#define MINOR $minor"
    $vhText = $vhText -replace '#define\s+PATCH\s+\d+', "#define PATCH $patch"
    Set-Content -LiteralPath $verFile -Value $vhText -NoNewline
    $version = "$major.$minor.$patch"
    Write-Host "Version: $version"

    $swBuild = [System.Diagnostics.Stopwatch]::StartNew()
    & $hemtt release
    if ($LASTEXITCODE -ne 0) { throw "hemtt release failed" }
    $swBuild.Stop()
    $timings['hemtt release'] = $swBuild.Elapsed

    # HEMTT names PBOs "{prefix}_{folder}.pbo"; strip the added PTF_ so every
    # PBO keeps its historical "<folder>.pbo" name (PTF_PTF_Aircraft.pbo ->
    # PTF_Aircraft.pbo, PTF_riku_class_a.pbo -> riku_class_a.pbo). The
    # post_build Rhai hook does the same for `hemtt build`/`dev`, but hooks
    # tied to HEMTT's release stages don't run here because archiving is
    # disabled.
    foreach ($pbo in Get-ChildItem "$out\addons\PTF_*.pbo") {
        Rename-Item -LiteralPath $pbo.FullName -NewName $pbo.Name.Substring(4)
    }

    # Merge the PBOs that ship with the mod but are not built from git.
    # -NoExternal (validated above) is the only way to skip this.
    $built = @((Get-ChildItem "$out\addons\*.pbo").Name)
    $expected = [System.Collections.Generic.HashSet[string]]::new(
        [string[]]$built, [System.StringComparer]::OrdinalIgnoreCase)
    if (-not $NoExternal) {
        if (-not (Test-Path -LiteralPath $ExternalAddons)) {
            throw "External addons folder not found: $ExternalAddons"
        }
        $allExternal = @(Get-ChildItem -LiteralPath $ExternalAddons -Filter *.pbo)
        $external = @($allExternal | Where-Object { $built -notcontains $_.Name })
        $skipped = $allExternal.Count - $external.Count
        if ($skipped -gt 0) {
            Write-Host "Skipped $skipped external PBO(s) that this repo builds itself - repo builds always win."
        }

        # Incremental: only copy an external PBO if it's missing, a different
        # size, or newer than the copy already in the output. -Force copies all.
        $swCopy = [System.Diagnostics.Stopwatch]::StartNew()
        $copied = 0; $current = 0
        foreach ($src in $external) {
            [void]$expected.Add($src.Name)
            $dst = Join-Path "$out\addons" $src.Name
            $have = Get-Item -LiteralPath $dst -ErrorAction SilentlyContinue
            if (-not $Force -and $have -and
                $have.Length -eq $src.Length -and
                $have.LastWriteTimeUtc -ge $src.LastWriteTimeUtc) {
                $current++
                continue
            }
            Copy-Item -LiteralPath $src.FullName -Destination $dst -Force
            $copied++
        }
        $swCopy.Stop()
        $timings['External merge'] = $swCopy.Elapsed
        Write-Host "External PBOs from ${ExternalAddons}: $copied copied, $current already up to date"
    }
    else {
        Write-Host "WARNING: -NoExternal set; the build has only the" `
            "$($built.Count) repo-built PBOs, not the full published mod." `
            "It is incomplete and will not load correctly on its own." `
            "Do NOT upload this to the Workshop (see BUILDING.md)."
    }

    # Prune anything that isn't part of this release — an external PBO that was
    # removed upstream, or leftovers from a previous run. This is what makes it
    # safe to keep the output folder between runs (see the -Force note above).
    $pruned = 0
    foreach ($stale in @(Get-ChildItem "$out\addons\*.pbo")) {
        if (-not $expected.Contains($stale.Name)) {
            Write-Host "  pruning stale PBO: $($stale.Name)"
            Get-ChildItem "$out\addons\$($stale.Name).*.bisign" -ErrorAction SilentlyContinue |
                Remove-Item -Force
            Remove-Item -LiteralPath $stale.FullName -Force
            $pruned++
        }
    }
    if ($pruned -gt 0) { Write-Host "Pruned $pruned stale PBO(s) from a previous build." }

    if ($NoSign) {
        Write-Host "WARNING: -NoSign set; the build is UNSIGNED. Do NOT upload it to the Workshop."
    }
    else {
        $swSign = [System.Diagnostics.Stopwatch]::StartNew()
        $pbos = Get-ChildItem "$out\addons\*.pbo"
        # Drop signatures made with a different key (e.g. -KeyName changed), so a
        # stale one can never be mistaken for this key's signature.
        Get-ChildItem "$out\addons\*.bisign" -ErrorAction SilentlyContinue |
            Where-Object { $_.Name -notlike "*.$KeyName.bisign" } | Remove-Item -Force

        # Incremental: re-sign only when the .bisign is missing or older than the
        # PBO. Safe because DSCheckSignatures below verifies EVERY PBO against the
        # public key regardless, so a stale/bad signature still gets caught.
        $signedNow = 0; $sigCurrent = 0
        foreach ($pbo in $pbos) {
            $sigPath = Join-Path "$out\addons" "$($pbo.Name).$KeyName.bisign"
            $sig = Get-Item -LiteralPath $sigPath -ErrorAction SilentlyContinue
            if (-not $Force -and $sig -and $sig.LastWriteTimeUtc -ge $pbo.LastWriteTimeUtc) {
                $sigCurrent++
                continue
            }
            if ($sig) { Remove-Item -LiteralPath $sigPath -Force }
            & $dsSign $privateKey $pbo.FullName
            if ($LASTEXITCODE -ne 0) { throw "Signing failed: $($pbo.Name)" }
            $signedNow++
        }
        $swSign.Stop()
        $timings['Signing'] = $swSign.Elapsed
        Write-Host "Signing: $signedNow signed, $sigCurrent already current"
        # Verify a .bisign was actually produced for every PBO — DSSignFile can
        # exit 0 without writing output (e.g. a locked/read-only file), which
        # would otherwise let an unsigned PBO ship undetected.
        $signed = (Get-ChildItem "$out\addons\*.bisign").Count
        if ($signed -ne $pbos.Count) {
            throw "Signing produced $signed .bisign file(s) for $($pbos.Count) PBOs - some are unsigned."
        }
        # Cryptographically verify every PBO validates against the public key —
        # catches a signature made with the wrong key or a corrupted .bisign,
        # which the count check above can't see.
        if ($dsCheck) {
            $report = & $dsCheck $publicKey "$out\addons" 2>&1 | Out-String
            Write-Host $report
            if ($report -match '(?im)\b(wrong|bad|corrupt|missing|unsigned|not\s+signed|fail)') {
                throw "DSCheckSignatures reported a signature problem (see report above)."
            }
            Write-Host "All $($pbos.Count) PBOs verified against $KeyName.bikey."
        }
        else {
            Write-Host "NOTE: DSCheckSignatures.exe not found; skipped cryptographic verification (.bisign count check still passed)."
        }

        $keysDir = Join-Path $out "keys"
        if (Test-Path $keysDir) { Remove-Item "$keysDir\*" }
        else { New-Item -ItemType Directory $keysDir | Out-Null }
        Copy-Item $publicKey $keysDir
    }

    # $version was derived from git before the build (see the version block above).

    # Zip straight from the build output, writing each entry under the Workshop
    # mod folder name. Deliberately NOT staging a copy first: the release is
    # several GB, so copying it to %TEMP% just to zip it doubled the I/O for no
    # benefit (and Copy-Item's -Destination mangles the "[PTF]" in the folder
    # name, which PowerShell treats as a wildcard). .NET IO takes paths literally.
    $modFolder = "@[PTF] Paramarine Milsim Core"
    [System.IO.Directory]::CreateDirectory($OutputDir) | Out-Null
    $modPath = Join-Path $OutputDir $modFolder

    # Publish the mod as a ready-to-use folder. It's a directory junction onto
    # the build output rather than a copy: the release is several GB, and a copy
    # would undo the incremental work above (and go stale the moment you rebuild).
    # Arma and the Arma 3 Publisher read straight through a junction, so
    # "$OutputDir\@[PTF] Paramarine Milsim Core" behaves exactly like a real
    # folder — point Arma or the Publisher at it directly.
    if (Test-Path -LiteralPath $modPath) {
        $existing = Get-Item -LiteralPath $modPath -Force
        if ($existing.Attributes -band [System.IO.FileAttributes]::ReparsePoint) {
            # Remove only the link, never the folder it points at.
            [System.IO.Directory]::Delete($modPath, $false)
        }
        else {
            Remove-Item -LiteralPath $modPath -Recurse -Force
        }
    }
    # mklink is used over New-Item -ItemType Junction because New-Item's -Path
    # treats the "[PTF]" in the folder name as a wildcard; cmd takes it literally.
    cmd /c mklink /J "$modPath" "$out" | Out-Null
    if (-not (Test-Path -LiteralPath $modPath)) {
        throw "Could not publish the mod folder at $modPath"
    }

    $zip = $null
    if ($Zip) {
    $zip = Join-Path $OutputDir "PTF-$version.zip"
    if (Test-Path -LiteralPath $zip) {
        if (-not $Force) {
            throw "Release $zip already exists - delete it, pass -Force to overwrite, or bump MAJOR in addons\PTF_Main\script_version.hpp."
        }
        Write-Host "-Force: overwriting existing $zip"
        Remove-Item -LiteralPath $zip -Force
    }

    Add-Type -AssemblyName System.IO.Compression
    Add-Type -AssemblyName System.IO.Compression.FileSystem

    $files = @(Get-ChildItem -LiteralPath $out -Recurse -File)
    $srcMB = [math]::Round((($files | Measure-Object -Property Length -Sum).Sum / 1MB))
    Write-Host ""
    Write-Host "Compressing $($files.Count) files (~$srcMB MB) into $zip"
    Write-Host "PBOs are already compressed, so this uses Fastest - expect a couple of minutes."

    $sw = [System.Diagnostics.Stopwatch]::StartNew()
    $archive = [System.IO.Compression.ZipFile]::Open($zip, 'Create')
    try {
        $i = 0
        foreach ($f in $files) {
            $i++
            $rel = $f.FullName.Substring($out.Length).TrimStart('\')
            $entry = "$modFolder/" + ($rel -replace '\\', '/')
            [System.IO.Compression.ZipFileExtensions]::CreateEntryFromFile(
                $archive, $f.FullName, $entry,
                [System.IO.Compression.CompressionLevel]::Fastest) | Out-Null
            Write-Progress -Activity "Compressing release" -Status "$i of $($files.Count): $rel" `
                -PercentComplete ([int]($i * 100 / $files.Count))
            if ($i % 10 -eq 0 -or $i -eq $files.Count) {
                Write-Host ("  [{0,3}/{1}] {2}s elapsed" -f $i, $files.Count, [int]$sw.Elapsed.TotalSeconds)
            }
        }
    }
    finally {
        $archive.Dispose()
        Write-Progress -Activity "Compressing release" -Completed
    }
    $sw.Stop()
    $timings['Zip'] = $sw.Elapsed

    if (-not (Test-Path -LiteralPath $zip)) { throw "Zip was not created: $zip" }
    }  # end if ($Zip)

    $swTotal.Stop()
    $signNote = if ($NoSign) { "UNSIGNED - local dev only" } else { "signed with $KeyName" }

    Write-Host ""
    Write-Host "=============================================================="
    Write-Host " Release $version ready ($signNote) in $([int]$swTotal.Elapsed.TotalSeconds)s"
    foreach ($k in $timings.Keys) {
        Write-Host ("   {0,-16} {1,5}s" -f $k, [int]$timings[$k].TotalSeconds)
    }
    Write-Host ""
    Write-Host "   Mod folder: $modPath"
    Write-Host "   (build output: $out)"
    if ($zip) {
        $zipMB = [math]::Round(((Get-Item -LiteralPath $zip).Length / 1MB))
        Write-Host "   Zip:        $zip (~$zipMB MB)"
    }
    Write-Host ""
    if ($NoSign) {
        Write-Host " Next: load the mod folder above in Arma 3 to test."
        Write-Host "       (UNSIGNED - do not upload it to the Workshop.)"
    }
    else {
        Write-Host " Next: point the Arma 3 Publisher at the mod folder above."
    }
    Write-Host "=============================================================="
}
finally { Pop-Location }
