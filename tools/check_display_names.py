#!/usr/bin/env python3
"""Flag asset classes that would show up blank/nameless in the Arsenal.

Two checks over direct children of the asset containers (CfgWeapons /
CfgVehicles / CfgMagazines / CfgGlasses):

  * empty name (GATING) - `displayName = ""` (or whitespace). An explicit empty
    name always renders blank; it's practically always a mistake.
  * arsenal-visible but unnamed (ADVISORY) - the class sets `scope = 2` (or
    scopeArsenal = 2) in its own body but declares no displayName of its own.
    Often fine (the name is inherited from a parent), so this is advisory —
    eyeball it for genuinely nameless entries.

Usage:  tools/check_display_names.py [--strict]   (--strict exits 1 on the
        GATING check only; advisory findings never fail)
"""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONTAINERS = {"cfgweapons", "cfgvehicles", "cfgmagazines", "cfgglasses"}

BLOCK_COMMENT = re.compile(r"/\*.*?\*/", re.DOTALL)
LINE_COMMENT = re.compile(r"//[^\n]*")
STRING = re.compile(r'"(?:[^"\\]|\\.)*"')
TOKEN = re.compile(r"class\s+(\w+)|[{};]")

DISPLAYNAME = re.compile(r'\bdisplayName\s*=\s*"([^"]*)"')
DISPLAYNAME_ANY = re.compile(r"\bdisplayName\s*=")
SCOPE2 = re.compile(r"\bscope(?:Arsenal)?\s*=\s*2\b")


def addon_of(path):
    return os.path.relpath(path, os.path.join(REPO, "addons")).split(os.sep)[0]


def iter_asset_bodies(text):
    """Yield (classname, body_text) for each direct child of an asset
    container. Strings are preserved (we need displayName values) but comments
    are stripped. Brace matching drives the body extraction."""
    clean = LINE_COMMENT.sub("", BLOCK_COMMENT.sub("", text))
    # Neutralise braces INSIDE strings so they don't confuse depth tracking,
    # while keeping a parallel copy with real strings for content checks.
    masked = STRING.sub(lambda m: '"' + "\0" * (len(m.group(0)) - 2) + '"', clean)

    stack = []       # (name_or_None, body_start_index, parent_name_or_None)
    pending = None
    for m in TOKEN.finditer(masked):
        tok = m.group(0)
        if m.group(1) is not None:
            pending = m.group(1)
        elif tok == "{":
            if pending is not None:
                parent = next((n for n, _s, _p in reversed(stack) if n), None)
                stack.append((pending, m.end(), parent))
                pending = None
            else:
                stack.append((None, m.end(), None))
        elif tok == "}":
            if stack:
                name, start, parent = stack.pop()
                if name and parent and parent.lower() in CONTAINERS:
                    yield name, clean[start:m.start()]
            pending = None
        else:
            pending = None


def main():
    strict = "--strict" in sys.argv[1:]
    empty, unnamed = [], []

    for root, _dirs, files in os.walk(os.path.join(REPO, "addons")):
        for f in files:
            if not f.lower().endswith((".cpp", ".hpp")):
                continue
            path = os.path.join(root, f)
            try:
                with open(path, encoding="utf-8", errors="ignore") as fh:
                    text = fh.read()
            except OSError:
                continue
            addon = addon_of(path)
            for name, body in iter_asset_bodies(text):
                # only look at THIS class's own body, not nested children
                own = re.split(r"\bclass\s+\w+\s*(?::[^{]*)?{", body)[0]
                dn = DISPLAYNAME.search(own)
                if dn is not None and dn.group(1).strip() == "":
                    empty.append(f"{addon}: {name}  (displayName = \"\")")
                elif dn is None and not DISPLAYNAME_ANY.search(own) and SCOPE2.search(own):
                    unnamed.append(f"{addon}: {name}")

    print("== Empty displayName (renders blank) ==")
    for e in empty:
        print("  " + e)
    if not empty:
        print("  none")

    print("== scope=2 but no displayName of its own (advisory - may inherit) ==")
    for u in unnamed:
        print("  " + u)
    if not unnamed:
        print("  none")

    print(f"\ncheck_display_names: {len(empty)} empty, {len(unnamed)} unnamed(advisory).")
    if empty and strict:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
