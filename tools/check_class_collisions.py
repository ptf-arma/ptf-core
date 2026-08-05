#!/usr/bin/env python3
"""Report game-asset classes defined in more than one addon.

When two addons both define e.g. `CfgWeapons >> Foo` with a body, one silently
overrides the other depending on load order — a subtle "why didn't my change
take effect" bug (the Hellfire ammo double-definition was one of these).

To avoid noise, this ONLY compares direct children of the real asset containers
(CfgWeapons/CfgVehicles/CfgMagazines/CfgAmmo/CfgGlasses) — not the structural
container classes (ItemInfo, Turrets, EventHandlers, …) that every addon is
meant to reopen. It parses brace depth so it knows a class's parent.

Still ADVISORY: two addons can legitimately patch the same external base class.
Eyeball the output. Forward declarations (`class Foo;`) don't count.

Usage:  tools/check_class_collisions.py [--strict]   (--strict exits 1 on hits)
"""
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
CONTAINERS = {"cfgweapons", "cfgvehicles", "cfgmagazines", "cfgammo", "cfgglasses"}

BLOCK_COMMENT = re.compile(r"/\*.*?\*/", re.DOTALL)
LINE_COMMENT = re.compile(r"//[^\n]*")
STRING = re.compile(r'"(?:[^"\\]|\\.)*"')
TOKEN = re.compile(r"class\s+(\w+)|[{};]")


def addon_of(path):
    return os.path.relpath(path, os.path.join(REPO, "addons")).split(os.sep)[0]


def asset_classes_in(text):
    """Yield classnames that are direct children of an asset container."""
    text = STRING.sub('""', LINE_COMMENT.sub("", BLOCK_COMMENT.sub("", text)))
    stack = []       # class names (or None for non-class braces), by brace depth
    pending = None   # last `class Name` seen, awaiting { or ;
    for m in TOKEN.finditer(text):
        tok = m.group(0)
        if m.group(1) is not None:          # "class Name"
            pending = m.group(1)
        elif tok == "{":
            if pending is not None:
                parent = next((n for n in reversed(stack) if n), None)
                if parent and parent.lower() in CONTAINERS:
                    yield pending
                stack.append(pending)
                pending = None
            else:
                stack.append(None)          # array / value brace
        elif tok == "}":
            if stack:
                stack.pop()
            pending = None
        else:                                # ";"  -> forward decl / statement
            pending = None


def main():
    strict = "--strict" in sys.argv[1:]

    defined = {}  # classname -> set(addons)
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
            for name in asset_classes_in(text):
                defined.setdefault(name, set()).add(addon)

    clashes = {n: sorted(a) for n, a in defined.items() if len(a) > 1}

    print("== Asset classes defined in more than one addon ==")
    if clashes:
        for name in sorted(clashes, key=str.lower):
            print(f"  {name}: {', '.join(clashes[name])}")
    else:
        print("  none")

    print(f"\ncheck_class_collisions: {len(clashes)} cross-addon asset clash(es).")
    if clashes and strict:
        return 1
    return 0


if __name__ == "__main__":
    sys.exit(main())
