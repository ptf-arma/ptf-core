# Building PTF Core

PTF Core is built with [HEMTT](https://hemtt.dev). Install it once with
`winget install BrettMayson.HEMTT` (or grab a release from GitHub).

## Everyday commands

| Command | What it does |
| --- | --- |
| `hemtt check` | Lint and validate every config and SQF file. Fast; run before committing. |
| `hemtt dev` | Development build (no binarization) into `.hemttout/dev`. |
| `hemtt launch` | Launch Arma 3 with the dev build (requires a `.hemtt/launch.toml`, not yet configured). |
| `hemtt build` | Full build with binarization into `.hemttout/build`. |
| `hemtt release` | Signed release build; produces `releases/PTF-<version>.zip` containing `@[PTF] Paramarine Milsim Core`. |

The mod version lives in `addons/PTF_Main/script_version.hpp` — bump it
before a release.

## Signing

Releases are signed with the community's existing `ptf2.1` key (the same
key the published mod and the outside-repo reupload PBOs use), so servers
keep working with the bikey they already have. HEMTT cannot reuse a
`.biprivatekey`, so its own signing is disabled in `project.toml` and
`tools/release.ps1` signs with DSSignFile from Arma 3 Tools instead.

Point the script at the folder holding `ptf2.1.biprivatekey` and
`ptf2.1.bikey` by setting `PTF_KEYS_DIR` (or passing `-KeyDir`); use a
different key with `-KeyName`. The private key stays in that folder — it
is never copied into the repo or committed.

## External PBOs (not in git)

The published mod contains ~57 PBOs but this repo only builds 18. The
rest (~40: ctab, boxloader, grad_trenches, Peral, Dagger Island, Moe's,
NDS, sling-load-rigging, ptf_sql, and other reuploads) are kept outside
git because they cannot be rebuilt (binarized/obfuscated third-party
PBOs), are too large, or are complex third-party addons that rarely
change and don't need rebuilding (ctab). They must be merged into every
release — pass their folder to the release script with `-ExternalAddons`.
A future build server needs a canonical store for them (currently the
subscribed Workshop copy is the de-facto ground truth).

## Releasing to the Workshop

1. Merge `develop` into `master`.
2. Run `tools\release.ps1 -ExternalAddons <folder-with-untracked-pbos>`
   on a Windows machine with Arma 3 Tools installed. It runs
   `hemtt release` (binarizes the MLOD models), merges the external PBOs,
   signs everything with `ptf2.1`, ships the bikey, and writes
   `releases/PTF-<version>.zip`.
3. Unzip and upload the `@[PTF] Paramarine Milsim Core` folder with the
   Arma 3 Publisher, same as before.

## Project layout notes

- `.hemtt/project.toml` — main build config (prefix `z\PTF\addons\...`,
  lint tuning, release folder name).
- `.hemtt/hooks/` — a post_build Rhai hook that renames HEMTT's
  `PTF_<folder>.pbo` output back to the historical `<folder>.pbo` names
  for `hemtt build`/`dev`. (`hemtt release` renaming is done by
  `tools/release.ps1`, which owns the full release flow.)
- `addons/<X>/addon.toml` — per-addon overrides:
  - `DIHatUSMC`, `drc_custom_billboards`, `riku_class_a` ship pre-binarized
    (ODOL) models, so binarization is disabled;
    `drc_custom_billboards` also ships a pre-rapified `config.bin` and keeps
    the original flat `drc_custom_billboards` PBO prefix — the Dagger Island
    terrain references those paths, so do not "fix" it to `z\PTF\addons\...`.
  - `PTF_GCam` ships a plain-text config because its dialog positions use
    runtime-evaluated `SafeZoneW/H` expressions HEMTT cannot rapify.
  - `PTF_Menu` keeps the intro mission's `Description.ext` unrapified
    (`db + 0` sound syntax).

## CI

`.github/workflows/hemtt.yml` runs `hemtt check` and a full
`hemtt release` (unbinarized on Linux) on every PR and push to
`develop`/`master`, uploading the release zip as an artifact.

## History

This mod was previously built with SCons + Arma 3 Tools AddonBuilder
(`scons -j 25`). That build was removed once HEMTT took over; the old
`SConstruct`/`tools/build.json` are in git history if ever needed. The
AddonBuilder build had packaging bugs the HEMTT build fixes:
`.p3d`/`.rvmat`/`.jpg`/`.ogg` files missing from the no-binarize PBOs and
the intro music, an empty drc config, and dropped Peral Zeus patches.
