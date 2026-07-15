# Building PTF Core

PTF Core is built with [HEMTT](https://hemtt.dev). Install it once with
`winget install BrettMayson.HEMTT` (or grab a release from GitHub).

## Everyday commands

| Command | What it does |
| --- | --- |
| `hemtt check` | Lint and validate every config and SQF file. Fast; run before committing. |
| `hemtt dev` | Development build (no binarization) into `.hemttout/dev`. |
| `hemtt launch` | Launch Arma 3 with the dev build and its framework mods (configured in `.hemtt/launch.toml`; `hemtt launch vr` also opens a bare VR mission). |
| `hemtt build` | Full build with binarization into `.hemttout/build`. |
| `hemtt release` | Signed release build; produces `releases/PTF-<version>.zip` containing `@[PTF] Paramarine Milsim Core`. |

## Versioning

The version is `X.Y.Z`, derived from git by `tools/gen-version.sh` (which
writes `MINOR`/`PATCH` into `addons/PTF_Main/script_version.hpp` at build
time):

- **X (MAJOR)** — hand-maintained in `script_version.hpp`. Bump it only for
  a major overhaul.
- **Y (MINOR)** — number of releases so far (count of `vX.*` tags). It bumps
  automatically when a release is cut off `master` (see below).
- **Z (PATCH)** — first-parent commits since the last release tag, i.e.
  develop updates since the last release. Resets to 0 at each release.

Both `hemtt` in CI and `tools/release.ps1` run `gen-version.sh` before
building, so you never edit `MINOR`/`PATCH` by hand — only `MAJOR`.

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
release: set `PTF_EXTERNAL_ADDONS` (or pass `-ExternalAddons`) to their
folder. The release script **requires** this — it refuses to run without
it, so a release can't silently ship without the ~40 external PBOs. For a
deliberate repo-only build (dev/testing the 18 tracked PBOs, never for
the Workshop) pass `-NoExternal`. A future build server needs a canonical
store for these PBOs (currently the subscribed Workshop copy is the
de-facto ground truth).

## Environment variables

Only `tools/release.ps1` (signed Workshop builds) reads these — **contributors
don't need any environment variables.** Set them once (Windows → *Edit the
system environment variables*) or pass the equivalent flag on each run.

| Variable | Equivalent flag | Points to |
| --- | --- | --- |
| `PTF_KEYS_DIR` | `-KeyDir` | Folder holding `ptf2.1.biprivatekey` + `ptf2.1.bikey` (the signing key — never committed). |
| `PTF_EXTERNAL_ADDONS` | `-ExternalAddons` | Folder holding the ~40 prebuilt external PBOs that get merged into a release. |
| `PTF_RELEASE_DIR` | `-OutputDir` | Where the finished zip is written. Defaults to `<repo>\releases`. |

### release.ps1 flags

| Flag | Effect |
| --- | --- |
| `-KeyName` | Signing key name (default `ptf2.1`). |
| `-NoExternal` | Repo-only build, skipping the external merge — **never upload it to the Workshop**. |
| `-NoSign` | Skip signing (no key / Arma 3 Tools needed). Output is UNSIGNED. |
| `-NoZip` | Skip compression. `.hemttout\release` is already the uploadable mod folder. |
| `-Force` | Full rebuild: wipe the build output, re-copy every external, re-sign everything, and overwrite an existing zip for this version. |

### Incremental by default

`release.ps1` keeps `.hemttout\release` between runs and only redoes what
changed:

- **External PBOs** are copied only when missing, a different size, or newer
  than the copy already in the output.
- **Signing** re-runs only when a PBO's `.bisign` is missing or older than the
  PBO. This is safe because `DSCheckSignatures` still verifies *every* PBO
  against the public key at the end, so a stale or wrong signature is still
  caught.
- Anything that isn't part of the current release (e.g. an external PBO removed
  upstream) is **pruned** from the output, which is what makes it safe to keep
  the folder between runs.

Use `-Force` if you ever want to rule out the cache and rebuild from scratch.

## Releasing to the Workshop

1. Merge `develop` into `master` and push. This triggers
   `.github/workflows/release.yml`, which computes the next version
   (`Y+1`, `Z=0`), tags it `vX.Y.0`, and cuts a GitHub Release with a
   changelog and an unsigned reference build. Tag/Release creation happens
   **only on master** — develop pushes never cut a release.
2. On a Windows machine with Arma 3 Tools installed, with `PTF_KEYS_DIR`
   and `PTF_EXTERNAL_ADDONS` set (or pass `-KeyDir`/`-ExternalAddons`),
   run `tools\release.ps1`. It fetches the tag CI just created, derives the
   matching `X.Y.0` version, runs `hemtt release` (binarizes the MLOD
   models), merges the external PBOs, signs everything with `ptf2.1`,
   ships the bikey, and writes `releases/PTF-<version>.zip`.
3. Unzip and upload the `@[PTF] Paramarine Milsim Core` folder with the
   Arma 3 Publisher, same as before.

Run `release.ps1` *after* the release workflow has tagged master, so its
git-derived version matches the tag. For a major overhaul, bump `MAJOR` in
`script_version.hpp` and commit that before merging to master.

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
  - `PTF_Menu` keeps the intro mission's `Description.ext` unrapified
    (`db + 0` sound syntax).

## CI

`.github/workflows/hemtt.yml` runs `hemtt check` and a full
`hemtt release` (unbinarized on Linux) on every PR and push to
`develop`/`master`, uploading the build as an artifact. It checks out full
history (`fetch-depth: 0`) so `gen-version.sh` can derive the version.

`.github/workflows/release.yml` runs **only on push to `master`** (or a
manual dispatch). It bumps the release version, tags `vX.Y.0`, and creates
a GitHub Release with a changelog and an unsigned reference build. It never
runs on `develop`, so only a `develop -> master` merge cuts a release.

## History

This mod was previously built with SCons + Arma 3 Tools AddonBuilder
(`scons -j 25`). That build was removed once HEMTT took over; the old
`SConstruct`/`tools/build.json` are in git history if ever needed. The
AddonBuilder build had packaging bugs the HEMTT build fixes:
`.p3d`/`.rvmat`/`.jpg`/`.ogg` files missing from the no-binarize PBOs and
the intro music, an empty drc config, and dropped Peral Zeus patches.
