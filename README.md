# PTF Core

**Paramarine Task Force — Milsim Core**, the custom Arma 3 mod for the
[Paramarine Task Force](https://www.paramarines.com/) milsim community. It
bundles the unit's custom aircraft, vehicles, weapons, uniforms, gear, and
utility objects, plus a handful of third-party addons reused with the
original authors' permission. It is used on the PTF's own servers and
clients.

[![HEMTT](https://github.com/matthawkins2/ptf-core/actions/workflows/hemtt.yml/badge.svg)](https://github.com/matthawkins2/ptf-core/actions/workflows/hemtt.yml)

> This mod is not general-purpose content — it is built for the PTF and
> carries a no-derivatives license (see [License](#license)). You are
> welcome to read and build it, but not to reupload or redistribute it.

---

## What's in here

Each folder under [`addons/`](addons/) is one PBO. Everything uses the
prefix namespace `z\PTF\addons\<name>`. Broadly:

- **Framework** — `PTF_Main` (editor categories, root of the dependency
  tree), `PTF_Scripts` (SQF: healing/gestures/XEH handlers), `PTF_Models`,
  `PTF_Textures`.
- **Content** — `PTF_Aircraft`, `PTF_Vehicles`, `PTF_Weapons`,
  `PTF_Clothes`, `PTF_Helmets`, `PTF_Utility`, `PTF_Menu`, `PTF_Smoke`,
  `PTF_GCam`.
- **Third-party (in-repo, modified with permission)** — `DIHatUSMC`,
  `PTF_DICoverUSMC`, `drc_custom_billboards`, `riku_class_a`, `BettIR_PTF`.

The mod depends on external framework mods at runtime (RHS USAF/GREF/AFRF,
ACE3, CBA, TFAR, USAF mod, and others) — those are **not** part of this
repo; you subscribe to them separately to actually run the mod.

> **Not everything shipped is in git.** The published Workshop mod also
> includes ~40 prebuilt PBOs (ctab, boxloader, Peral, Dagger Island, and
> other reuploads) that are kept outside source control because they
> can't be rebuilt from source or are too large. They are merged in at
> release time — see [BUILDING.md](BUILDING.md).

---

## Building

The mod is built with [HEMTT](https://hemtt.dev). Full build, release, and
signing details live in **[BUILDING.md](BUILDING.md)** — the quick version:

### Prerequisites

- [HEMTT](https://hemtt.dev): `winget install BrettMayson.HEMTT`
- **Arma 3 Tools** (from Steam) — only needed for a full binarized build
  and for signing; `hemtt check` and `hemtt dev` work without it.

### Common commands

Run these from the repo root:

| Command | What it does |
| --- | --- |
| `hemtt check` | Lint/validate every config and SQF file. Fast — run before committing. |
| `hemtt dev` | Development build (no binarization) into `.hemttout/dev`. |
| `hemtt build` | Full build with binarization into `.hemttout/build`. |
| `tools\release.ps1` | Signed, Workshop-ready release (see BUILDING.md for the required env vars). |

`hemtt check` also runs automatically in CI on every pull request.

---

## Branching & workflow

| Branch | Purpose |
| --- | --- |
| `develop` | Integration branch and the **default** branch. All feature work merges here. |
| `master` | Release branch. `develop` is merged into `master` when shipping a Workshop update. |

- Cut **feature branches off `develop`**, named after the issue they
  address (e.g. `866-texture-not-found-error-fixes`,
  `t-853/peral-rifles`).
- Open a **pull request back into `develop`**; CI runs `hemtt check` on
  it. Keep changes scoped to one addon/feature where practical.
- When a release is ready, merge `develop` → `master`, then build and
  publish per [BUILDING.md](BUILDING.md).

New to contributing? **[CONTRIBUTING.md](CONTRIBUTING.md)** walks through the
whole process step by step (setup, branching, checking your work, opening a PR).

The GitHub repo is <https://github.com/matthawkins2/ptf-core>. Issues and
merge requests from before the GitHub migration live in the old GitLab
archive.

---

## Testing changes

Most content changes (gear, uniforms, weapons, vehicles) can be verified
in the in-game ACE / vanilla **Arsenal** or the editor after a
`hemtt build`. For a full local test, build and launch a local Arma 3
instance with the mod and its dependencies loaded.

---

## License

This pack contains content under **multiple licenses** — the original PTF
content is under the [Arma Public License No-Derivatives (APL-ND)](https://www.bohemia.net/community/licenses/arma-public-license-nd),
and the bundled third-party addons keep their own licenses. Per-PBO
authorship and license terms are documented in
[`credits_and_license.txt`](credits_and_license.txt).

In short: you may use this mod, but do not reupload it to the Workshop or
redistribute modified copies. Third-party PBOs (e.g. `riku_class_a`, GPLv3)
have their own redistribution terms — check the credits file before
reusing anything.
