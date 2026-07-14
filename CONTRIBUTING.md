# Contributing to PTF Core

Welcome! This guide walks you through making a change to the mod, start to
finish, using **[GitHub Desktop](https://desktop.github.com/)** — a point-and-
click app, no command line required. If a step is unclear, ask in the unit's
dev channel rather than getting stuck.

If you just want to know how to build, see [BUILDING.md](BUILDING.md). This
page is about the *workflow* around a change.

---

## 1. One-time setup

1. **Get access.** You need a GitHub account, and an admin has to add you to
   the `ptf-arma` organization. Post your GitHub username in the dev channel.
2. **Install [GitHub Desktop](https://desktop.github.com/)** and sign in. This
   is the only tool you strictly need.
3. **(Recommended) Install HEMTT** so you can check your work before pushing —
   open a terminal (Windows: *Command Prompt* or *PowerShell*) and run:
   ```
   winget install BrettMayson.HEMTT
   ```
   Not required — CI checks your PR automatically either way — but it catches
   mistakes faster.
4. **(Optional, advanced)** If you're comfortable with a terminal, run
   `git config core.hooksPath .githooks` inside the repo folder once. That runs
   `hemtt check` automatically on every commit. Skippable — CI runs the same
   checks on your PR.

> **Do I need environment variables?** No. The `PTF_KEYS_DIR` /
> `PTF_EXTERNAL_ADDONS` variables are only for **maintainers** building signed
> Workshop releases — see [BUILDING.md](BUILDING.md). Contributing needs none.

---

## 2. Making a change (in GitHub Desktop)

### a. Clone the repo (first time only)
**File → Clone repository →** find `ptf-arma/ptf-core` **→ Clone.** GitHub
Desktop downloads it to a folder on your PC.

### b. Start from an up-to-date `develop`
In the top bar, set **Current Branch** to `develop`, then click **Fetch
origin** and **Pull** so you have the latest. `develop` is our integration
branch — **never commit directly to `develop` or `master`.**

### c. Make a branch for your change
**Current Branch → New Branch.** Base it on `develop` and name it after the
issue you're fixing, e.g. `123-fix-mrap-texture`. (No issue yet? Create one
first — 30 seconds, and it keeps things organized.)

### d. Edit the files
Open the repo folder in your text editor and make your change. Golden rules:
- **Keep it focused.** One PR = one thing. Don't fix five unrelated bugs at once.
- **Watch capitalization.** Our servers run Linux, which is *case-sensitive*.
  `#include "cfgImport.hpp"` will NOT find a file named `cfgIMPORT.hpp` on a
  server, even though it works on your Windows PC. Match filenames exactly.
- **Don't commit build output.** Never add `.pbo` files or the `.hemttout/`,
  `build/`, or `releases/` folders — they're generated (`.gitignore` blocks them).

### e. Check your work (if you installed HEMTT)
In a terminal opened to the repo folder, run `hemtt check`. Fix anything
reported as `error`. If you have Arma 3 Tools, also try `hemtt build` and load
the mod in-game to verify your change (especially anything visual — check it in
the Arsenal). No HEMTT installed? Skip this — CI will check your PR for you.

### f. Commit (in GitHub Desktop)
Your changed files appear on the left. Type a short **Summary** of what you
changed (bottom-left), then click **Commit to `<your-branch>`**. If you enabled
the pre-commit check in step 4, `hemtt check` runs here — if it fails, fix the
errors and commit again.

### g. Publish and open a Pull Request
Click **Publish branch** (first push) or **Push origin**. GitHub Desktop then
shows a **Create Pull Request** button — click it. Your browser opens a new PR
**targeting `develop`**; fill in the template (what changed, how you tested it)
and submit. It's fine to open a **draft** PR if you want early feedback before
it's finished.

---

## 3. What happens after you open a PR

GitHub automatically runs several checks on your PR. You'll see a green check ✓
or a red ✗ on the PR page. If it's red, click "Details" to see what failed —
usually the same thing the checks would tell you locally (often a capitalization
mismatch that only shows up on Linux). The checks are:

- **Lint (`hemtt check`)** + asset/whitelist checks — these **block** merging.
- **SQF unit tests** — run pure logic functions; block if a test fails.
- **Build** — a full `hemtt release` (unbinarized) must succeed.
- **No secrets or build artifacts** — blocks if a `.pbo` or the private key
  slips in.
- **PR hygiene** — a friendly bot comment with reminders (screenshots, issue
  link, size). It **never blocks** — just guidance.

A maintainer will review it. Don't take review comments personally — they're
about the code, not you, and everyone's changes get reviewed.

Once approved and green, a maintainer merges it into `develop`. Releases happen
later when `develop` is merged into `master` and published to the Workshop.

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

---

<details>
<summary><b>Prefer the command line? Git equivalents</b></summary>

```
# one-time
git clone https://github.com/ptf-arma/ptf-core.git
cd ptf-core
git config core.hooksPath .githooks        # optional pre-commit hemtt check

# each change
git checkout develop && git pull
git checkout -b 123-fix-mrap-texture
# ...edit files...
hemtt check
git add <the files you changed>
git commit -m "Fix swapped MRAP camo textures"
git push -u origin 123-fix-mrap-texture
```
Then open a PR targeting `develop` on GitHub.
</details>
