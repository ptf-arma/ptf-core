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
    [string]$KeyName = "ptf2.1"
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

# DSSignFile from Arma 3 Tools (registry lookup, same as the old SConstruct)
$a3tools = (Get-ItemProperty "HKCU:\SOFTWARE\Bohemia Interactive\Arma 3 Tools").path
$dsSign = Join-Path $a3tools "DSSignFile\DSSignFile.exe"
if (-not (Test-Path $dsSign)) { throw "DSSignFile not found: $dsSign" }

Push-Location $repo
try {
    & $hemtt release
    if ($LASTEXITCODE -ne 0) { throw "hemtt release failed" }

    $out = Join-Path $repo ".hemttout\release"

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
