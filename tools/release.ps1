# Build a signed, Workshop-ready release.
#
# Runs `hemtt release` (unsigned; see .hemtt/project.toml), signs every PBO
# with the community's ptf2.1 key using DSSignFile from Arma 3 Tools, ships
# the matching .bikey, and zips the mod folder into releases\.
#
# The private key is never copied anywhere; only the .bisign/.bikey outputs
# leave the key directory.
param(
    [string]$KeyDir  = "C:\A3Mods\Keys",
    [string]$KeyName = "ptf2.1",
    # Folder holding the PBOs that ship with the mod but are not in git
    # (reuploads / obfuscated third-party addons — see BUILDING.md).
    # When set, they are merged into the release and signed too.
    [string]$ExternalAddons = ""
)
$ErrorActionPreference = "Stop"
$repo = Split-Path -Parent $PSScriptRoot

$privateKey = Join-Path $KeyDir "$KeyName.biprivatekey"
$publicKey  = Join-Path $KeyDir "$KeyName.bikey"
if (-not (Test-Path $privateKey)) { throw "Private key not found: $privateKey" }
if (-not (Test-Path $publicKey))  { throw "Public key not found: $publicKey" }

# hemtt: PATH first, then the winget install location
$hemtt = Get-Command hemtt -ErrorAction SilentlyContinue
if ($hemtt) { $hemtt = $hemtt.Source }
else {
    $hemtt = Get-ChildItem "$env:LOCALAPPDATA\Microsoft\WinGet\Packages" -Filter hemtt.exe -Recurse -ErrorAction SilentlyContinue |
        Select-Object -First 1 -ExpandProperty FullName
    if (-not $hemtt) { throw "hemtt not found; install with: winget install BrettMayson.HEMTT" }
}

# DSSignFile from Arma 3 Tools (registry lookup)
$a3tools = (Get-ItemProperty "HKCU:\SOFTWARE\Bohemia Interactive\Arma 3 Tools").path
$dsSign = Join-Path $a3tools "DSSignFile\DSSignFile.exe"
if (-not (Test-Path $dsSign)) { throw "DSSignFile not found: $dsSign" }

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

    # Merge the PBOs that ship with the mod but are not built from git
    if ($ExternalAddons) {
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
        Write-Host "NOTE: no -ExternalAddons folder given; the zip will only" `
            "contain the $((Get-ChildItem "$out\addons\*.pbo").Count) repo-built PBOs," `
            "not the full published mod (see BUILDING.md)."
    }

    Get-ChildItem "$out\addons\*.bisign" -ErrorAction SilentlyContinue | Remove-Item
    foreach ($pbo in Get-ChildItem "$out\addons\*.pbo") {
        & $dsSign $privateKey $pbo.FullName
        if ($LASTEXITCODE -ne 0) { throw "Signing failed: $($pbo.Name)" }
    }

    $keysDir = Join-Path $out "keys"
    if (Test-Path $keysDir) { Remove-Item "$keysDir\*" }
    else { New-Item -ItemType Directory $keysDir | Out-Null }
    Copy-Item $publicKey $keysDir

    # Version from script_version.hpp
    $ver = @{}
    foreach ($line in Get-Content (Join-Path $repo "addons\PTF_Main\script_version.hpp")) {
        if ($line -match '#define\s+(\w+)\s+(\d+)') { $ver[$Matches[1]] = $Matches[2] }
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
    if (Test-Path -LiteralPath $zip) { Remove-Item -LiteralPath $zip }
    Add-Type -AssemblyName System.IO.Compression.FileSystem
    [System.IO.Compression.ZipFile]::CreateFromDirectory($staging, $zip)
    Remove-Item -LiteralPath $staging -Recurse -Force

    if (-not (Test-Path -LiteralPath $zip)) { throw "Zip was not created: $zip" }

    Write-Host ""
    Write-Host "Release ready: $zip (signed with $KeyName)"
    Write-Host "Unzipped signed mod folder: $out"
}
finally { Pop-Location }
