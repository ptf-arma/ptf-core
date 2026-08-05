#!/usr/bin/env python3
"""Validate that in-repo asset references actually resolve on disk.

Scans every config (.cpp/.hpp) and .rvmat for references to .paa/.p3d/.rvmat
paths in OUR namespace (the z\\PTF\\... PBO prefixes, plus drc_custom_billboards)
and checks each one against the files on disk. It reports two kinds of bug:

  * missing    - the referenced file isn't in the repo at all.
  * misrouted  - a z\\PTF\\ path that matches no PBO prefix (e.g. a missing
                 "addons\\" segment), so the in-game vpath won't exist even if
                 a similarly-named file is on disk.

Casing is deliberately IGNORED for the "does it exist" test: Arma's runtime
VFS resolves texture/model paths case-insensitively (this mod has shipped for
years with mixed-case texture refs on Linux servers), so a case difference is
not a real bug and flagging it would just churn 100+ files.

External references (\\rhsusf\\, \\A3\\, USAF_..., ace_..., etc.) can't be
verified from here and are skipped. Known-broken references awaiting art are
listed in tools/asset-refs-ignore.txt so this check can gate on NEW breakage.

Usage:  tools/check_asset_refs.py [--strict]   (--strict exits 1 on findings)
"""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IGNORE_FILE = os.path.join("tools", "asset-refs-ignore.txt")
ASSET_RE = re.compile(r'"([^"\n]*?\.(?:paa|p3d|rvmat))"', re.IGNORECASE)


def norm(p):
    """Backslashes -> slashes, strip leading slashes, lowercase."""
    return p.replace("\\", "/").lstrip("/").lower()


def build_prefix_map():
    """prefix (normalised) -> addon folder path, from each $PBOPREFIX$."""
    prefixes = {}
    addons = os.path.join(REPO, "addons")
    for name in sorted(os.listdir(addons)):
        pbo = os.path.join(addons, name, "$PBOPREFIX$")
        if os.path.isfile(pbo):
            with open(pbo, encoding="utf-8") as fh:
                pfx = fh.read().strip().splitlines()[0].strip()
            prefixes[norm(pfx)] = os.path.join("addons", name)
    return prefixes


def exists_any_case(rel_path):
    """True if rel_path exists on disk ignoring case (segment by segment)."""
    cur = REPO
    for part in rel_path.split("/"):
        try:
            entries = os.listdir(cur)
        except (FileNotFoundError, NotADirectoryError):
            return False
        match = next((e for e in entries if e.lower() == part.lower()), None)
        if match is None:
            return False
        cur = os.path.join(cur, match)
    return os.path.isfile(cur)


def resolve(ref, prefixes):
    """Map an 'ours' vpath to a repo-relative disk path, or None if it matches
    no prefix. Returns the disk path, or None."""
    n = norm(ref)
    for pfx in sorted(prefixes, key=len, reverse=True):
        if n == pfx or n.startswith(pfx + "/"):
            remainder = n[len(pfx):].lstrip("/")
            folder = prefixes[pfx].replace("\\", "/")
            return folder + "/" + remainder if remainder else folder
    return None


def load_ignore():
    path = os.path.join(REPO, IGNORE_FILE)
    ignored = set()
    if os.path.isfile(path):
        with open(path, encoding="utf-8") as fh:
            for line in fh:
                line = line.strip()
                if line and not line.startswith("#"):
                    ignored.add(norm(line))
    return ignored


def main():
    strict = "--strict" in sys.argv[1:]
    prefixes = build_prefix_map()
    ignored = load_ignore()

    # Addon folder names, used to spot references that clearly mean one of our
    # addons but were written without the PBO prefix (e.g. "\PTF_Main\..."
    # instead of "\z\PTF\addons\PTF_Main\..."). That resolves to nothing in game.
    addon_dir = os.path.join(REPO, "addons")
    addon_names = {n.lower() for n in os.listdir(addon_dir)
                   if os.path.isdir(os.path.join(addon_dir, n))}

    scan = []
    for root, _dirs, files in os.walk(addon_dir):
        scan += [os.path.join(root, f) for f in files
                 if f.lower().endswith((".cpp", ".hpp", ".rvmat"))]
    # mod.cpp / meta.cpp sit at the repo root (shipped to the mod folder root via
    # [files] in .hemtt/project.toml). Their logo/picture paths are real vpaths
    # into the PBOs, so they need checking too.
    scan += [os.path.join(REPO, f) for f in ("mod.cpp", "meta.cpp")
             if os.path.isfile(os.path.join(REPO, f))]

    refs = set()
    for path in scan:
        try:
            with open(path, encoding="utf-8", errors="ignore") as fh:
                text = fh.read()
        except OSError:
            continue
        for m in ASSET_RE.finditer(text):
            ref = m.group(1)
            if not ref.startswith("#"):  # skip procedural textures
                refs.add(ref)

    missing, misrouted, skipped = [], [], 0
    for ref in sorted(refs, key=str.lower):
        n = norm(ref)
        if n in ignored:
            skipped += 1
            continue
        disk = resolve(ref, prefixes)
        if disk is None:
            # Ours but unroutable: either under z\PTF\ with no matching prefix,
            # or it names one of our addon folders without the PBO prefix (e.g.
            # "\PTF_Main\..." instead of "\z\PTF\addons\PTF_Main\..."), which
            # silently resolves to nothing in game. Anything else is a genuine
            # external mod — not our problem.
            if n.startswith("z/ptf/") or n.split("/")[0] in addon_names:
                misrouted.append(ref)
            continue  # external — not our problem
        if not exists_any_case(disk):
            missing.append((ref, disk))

    def section(title, rows, fmt):
        print(f"== {title} ==")
        for r in rows:
            print("  " + fmt(r))
        if not rows:
            print("  none")

    section("Missing asset references", missing, lambda r: f"{r[0]}  ->  (no file at {r[1]})")
    section("Misrouted z\\PTF paths (no matching PBO prefix)", misrouted, lambda r: r)

    total = len(missing) + len(misrouted)
    note = f" ({skipped} known-broken ignored)" if skipped else ""
    print(f"\ncheck_asset_refs: {total} new problem(s) across {len(refs)} references{note}.")
    if total and strict:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
