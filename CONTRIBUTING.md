# Contributing to PTF Core

Welcome! This guide walks you through making a change to the mod, start to
finish. It assumes you've never done this before — if a step is unclear, ask
in the unit's dev channel rather than getting stuck.

If you just want to know how to build, see [BUILDING.md](BUILDING.md). This
page is about the *workflow* around a change.

---

## 1. One-time setup

You need these installed once:

- **Git** — https://git-scm.com/ (includes "Git Bash", which we use for commands)
- **HEMTT** (the build/lint tool) — open a terminal and run:
  ```
  winget install BrettMayson.HEMTT
  ```
- **Arma 3 Tools** (from Steam) — only needed if you're building/binarizing
  models locally. Not required just to lint your work.

Then clone the repo and turn on the pre-commit check (this runs `hemtt check`
automatically every time you commit, so you catch mistakes early):

```
git clone https://github.com/ptf-arma/ptf-core.git
cd ptf-core
git config core.hooksPath .githooks
```

---

## 2. The workflow, step by step

### a. Start from an up-to-date `develop`
```
git checkout develop
git pull
```
`develop` is our integration branch. **Never commit directly to `develop` or
`master`** — always work on your own branch.

### b. Make a branch named after the issue you're working on
```
git checkout -b 123-fix-mrap-texture
```
Use the issue number + a short description. If there's no issue yet, make one
first (it takes 30 seconds and keeps things organized).

### c. Make your change
Edit the files. A few golden rules:
- **Keep it focused.** One PR = one thing. Don't fix five unrelated bugs in
  one branch.
- **Watch capitalization.** Our servers run Linux, which is *case-sensitive*.
  `#include "cfgImport.hpp"` will NOT find a file named `cfgIMPORT.hpp` on a
  server, even though it works on your Windows PC. Match filenames exactly.
- **Don't commit build output.** Never add `.pbo` files or the `.hemttout/`,
  `build/`, or `releases/` folders — they're generated. (`.gitignore` already
  blocks them.)

### d. Check your work
```
hemtt check
```
Fix anything reported as `error`. Warnings are usually fine, but if your
change *added* a warning, look at it. If you have Arma 3 Tools, also try
`hemtt build`, then load the mod in-game and verify your change actually
works (especially for anything visual — check it in the Arsenal).

You can also run the same automated checks CI runs (all optional locally, but
they save a round-trip):
```
sh tools/find-unused-assets.sh --strict     # no orphaned textures/models
sh tools/check-arsenal.sh --strict           # no duplicate/broken whitelist entries
python tools/check_asset_refs.py --strict    # every texture/model path resolves
python tools/check_class_collisions.py --strict  # no class defined in two addons
python tools/check_display_names.py --strict     # no blank arsenal names
python tests/run_tests.py                     # SQF unit tests (pip install sqflint first)
```

### e. Commit
```
git add <the files you changed>
git commit -m "Fix swapped MRAP camo textures"
```
The pre-commit hook runs `hemtt check` for you here. If it fails, fix the
errors and commit again.

### f. Push and open a Pull Request
```
git push -u origin 123-fix-mrap-texture
```
Then open a PR on GitHub **targeting `develop`**. The PR template will prompt
you for what changed and how you tested it — fill it in. It's fine to open a
**draft** PR if you want early feedback before it's finished.

---

## 3. What happens after you open a PR

GitHub Actions automatically runs several checks on your PR. You'll see a green
check ✓ or a red ✗ on the PR page. If it's red, click "Details" to see what
failed — usually it's the same thing the checks would tell you locally (often a
capitalization mismatch that only shows up on Linux). The checks are:

- **Lint (`hemtt check`)** + asset/whitelist checks — these **block** merging.
- **SQF unit tests** — run pure logic functions; blocks if a test fails.
- **Build** — a full `hemtt release` (unbinarized) must succeed.
- **No secrets or build artifacts** — blocks if a `.pbo` or the private key
  slips in.
- **PR hygiene** — a friendly bot comment with reminders (screenshots, issue
  link, size). It **never blocks** — just guidance.

A reviewer will look it over. Don't take review comments personally — they're
about the code, not you, and everyone's changes get reviewed.

Once approved and green, it's merged into `develop`. Releases happen later when
`develop` is merged into `master` and published to the Workshop.

---

## 4. Common gotchas

- **"It works on my PC but CI is red."** Almost always a capitalization
  mismatch (see above) — Linux is picky where Windows isn't.
- **"LF will be replaced by CRLF" warnings.** Harmless; `.gitattributes`
  handles line endings for you.
- **Huge diff you didn't expect.** You probably committed build output or a
  whole-file line-ending change. Ask before force-anything.
- **Not sure which addon your change belongs in?** Ask. See the addon list in
  [README.md](README.md).

When in doubt, open the PR as a draft and ask. Getting eyes on it early beats
struggling alone.
