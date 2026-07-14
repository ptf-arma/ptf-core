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
    # Build only the repo-tracked PBOs, skipping the external merge. The
    # resulting mod is incomplete — intended for dev/testing, not release.
    [switch]$NoExternal,
    # Skip signing entirely (no key or Arma 3 Tools needed). For quick local
    # dev builds; the output is UNSIGNED — never upload it to the Workshop.
    [switch]$NoSign
)
$ErrorActionPreference = "Stop"
$repo = Split-Path -Parent $PSScriptRoot

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
}

Push-Location $repo
try {
    # hemtt does not clean its release output; stale PBOs from previous runs
    # (e.g. earlier external merges) would otherwise leak into this release.
    $out = Join-Path $repo ".hemttout\release"
    if (Test-Path -LiteralPath $out) { Remove-Item -LiteralPath $out -Recurse -Force }

    & $hemtt release
    if ($LASTEXITCODE -ne 0) { throw "hemtt release failed" }

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
    if (-not $NoExternal) {
        if (-not (Test-Path -LiteralPath $ExternalAddons)) {
            throw "External addons folder not found: $ExternalAddons"
        }
        $built = (Get-ChildItem "$out\addons\*.pbo").Name
        $external = Get-ChildItem -LiteralPath $ExternalAddons -Filter *.pbo |
            Where-Object { $built -notcontains $_.Name }
        $skipped = (Get-ChildItem -LiteralPath $ExternalAddons -Filter *.pbo).Count - $external.Count
        Write-Host "Merging $($external.Count) external PBOs from $ExternalAddons"
        if ($skipped -gt 0) {
            Write-Host "Skipped $skipped external PBO(s) that this repo builds itself - repo builds always win."
        }
        $external | Copy-Item -Destination "$out\addons"
    }
    else {
        Write-Host "WARNING: -NoExternal set; the zip will contain only the" `
            "$((Get-ChildItem "$out\addons\*.pbo").Count) repo-built PBOs," `
            "not the full published mod. Do NOT upload this to the Workshop (see BUILDING.md)."
    }

    if ($NoSign) {
        Write-Host "WARNING: -NoSign set; the build is UNSIGNED. Do NOT upload it to the Workshop."
    }
    else {
        Get-ChildItem "$out\addons\*.bisign" -ErrorAction SilentlyContinue | Remove-Item
        $pbos = Get-ChildItem "$out\addons\*.pbo"
        foreach ($pbo in $pbos) {
            & $dsSign $privateKey $pbo.FullName
            if ($LASTEXITCODE -ne 0) { throw "Signing failed: $($pbo.Name)" }
        }
        # Verify a .bisign was actually produced for every PBO — DSSignFile can
        # exit 0 without writing output (e.g. a locked/read-only file), which
        # would otherwise let an unsigned PBO ship undetected.
        $signed = (Get-ChildItem "$out\addons\*.bisign").Count
        if ($signed -ne $pbos.Count) {
            throw "Signing produced $signed .bisign file(s) for $($pbos.Count) PBOs - some are unsigned."
        }

        $keysDir = Join-Path $out "keys"
        if (Test-Path $keysDir) { Remove-Item "$keysDir\*" }
        else { New-Item -ItemType Directory $keysDir | Out-Null }
        Copy-Item $publicKey $keysDir
    }

    # Version from script_version.hpp
    $ver = @{}
    foreach ($line in Get-Content (Join-Path $repo "addons\PTF_Main\script_version.hpp")) {
        if ($line -match '#define\s+(\w+)\s+(\d+)') { $ver[$Matches[1]] = $Matches[2] }
    }
    foreach ($k in 'MAJOR', 'MINOR', 'PATCH', 'BUILD') {
        if (-not $ver.ContainsKey($k)) {
            throw "script_version.hpp is missing #define $k - cannot form a valid version string."
        }
    }
    $version = "$($ver.MAJOR).$($ver.MINOR).$($ver.PATCH).$($ver.BUILD)"

    # Stage under the Workshop folder name and zip. The folder name contains
    # PowerShell wildcard characters ([PTF]), so use .NET IO throughout —
    # it treats paths literally.
    $staging = Join-Path $env:TEMP "ptf-release-staging"
    $modFolder = "@[PTF] Paramarine Milsim Core"
    if (Test-Path -LiteralPath $staging) { Remove-Item -LiteralPath $staging -Recurse -Force }
    $stagedMod = Join-Path $staging $modFolder
    [System.IO.Directory]::CreateDirectory($stagedMod) | Out-Null
    Copy-Item -Path "$out\*" -Destination $stagedMod -Recurse

    $releases = Join-Path $repo "releases"
    [System.IO.Directory]::CreateDirectory($releases) | Out-Null
    $zip = Join-Path $releases "PTF-$version.zip"
    if (Test-Path -LiteralPath $zip) {
        throw "Release $zip already exists - bump the version in addons\PTF_Main\script_version.hpp (or remove the old zip) before re-releasing."
    }
    Add-Type -AssemblyName System.IO.Compression.FileSystem
    [System.IO.Compression.ZipFile]::CreateFromDirectory($staging, $zip)
    Remove-Item -LiteralPath $staging -Recurse -Force

    if (-not (Test-Path -LiteralPath $zip)) { throw "Zip was not created: $zip" }

    Write-Host ""
    $signNote = if ($NoSign) { "UNSIGNED - local dev only" } else { "signed with $KeyName" }
    Write-Host "Release ready: $zip ($signNote)"
    Write-Host "Unzipped mod folder: $out"
}
finally { Pop-Location }
