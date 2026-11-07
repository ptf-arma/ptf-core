#!/usr/bin/env python3
"""Catch config shapes that build cleanly but break the game at runtime.

Follows each addon's config.cpp through its #includes, so it knows the full path
of every class, then reports:

  bare-eventhandlers  `class EventHandlers { ... }` on a CfgVehicles class, with no
                      parent and no CBA_Extended_EventHandlers inside. It replaces
                      the inherited class, which removes XEH from that vehicle.
  xeh-override        A value set inside a CBA_Extended_EventHandlers subclass.
                      CBA's base class sets those same handlers, so `init = ...` in
                      there replaces XEH's own init. Set it beside the subclass.
  parentless          A class with a body and no parent directly under CfgVehicles,
                      CfgWeapons, CfgMagazines, CfgAmmo or CfgGlasses. If the name
                      belongs to another mod, it wipes that mod's model, simulation
                      and crew. It needs `: Parent` and a forward declaration.
  duplicate           The same class given a body twice in one scope of one addon.
                      The second silently updates the first.

Classes generated inside a #define are not seen. Exceptions go in
tools/config-structure-ignore.txt, one finding per line as this script prints it.

Usage:  tools/check_config_structure.py [--strict] [--root DIR]
        (--strict exits 1 on findings, --root checks another copy of the repo)
"""
import bisect
import os
import re
import sys

REPO = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
IGNORE_FILE = os.path.join(REPO, "tools", "config-structure-ignore.txt")
CONTAINERS = {"cfgvehicles", "cfgweapons", "cfgmagazines", "cfgammo", "cfgglasses"}
XEH_CLASS = "cba_extended_eventhandlers"

INCLUDE = re.compile(r'^\s*#\s*include\s+[<"]([^">]+)[">]')
TOKEN = re.compile(
    r'"(?:[^"]|"")*"'                                   # string, "" is an escaped quote
    r"|\bclass\s+(?P<name>\w+)\s*(?::\s*(?P<parent>\w+)\s*)?(?P<end>[{;])"
    r"|(?P<prop>\b\w+)\s*(?:\[\s*\]\s*)?\+?="
    r"|[{}]"
)


def strip_comments(text):
    """Blank out comments, keeping newlines so line numbers stay true."""
    def blank(match):
        tok = match.group(0)
        if tok.startswith('"'):
            return tok
        return "\n" * tok.count("\n") + (" " if tok.startswith("/*") else "")
    return re.sub(r'"(?:[^"\n]|"")*"|/\*.*?\*/|//[^\n]*', blank, text, flags=re.S)


class Source:
    """One addon's config, flattened through its includes, with line mapping."""

    def __init__(self, root, prefixes):
        self.root = root
        self.prefixes = prefixes
        self.text = []
        self.starts = []       # offset where each flattened line begins
        self.where = []        # (repo-relative file, line) for each flattened line
        self.size = 0

    def resolve(self, include, current):
        path = include.replace("\\", "/")
        if path.startswith("/") or re.match(r"(?i)z/", path):
            norm = path.lstrip("/").lower()
            for pfx in sorted(self.prefixes, key=len, reverse=True):
                if norm.startswith(pfx + "/"):
                    return find_any_case(self.prefixes[pfx], path.lstrip("/")[len(pfx) + 1:])
            return None        # another mod's file
        return find_any_case(os.path.dirname(current), path)

    def add_file(self, path, seen=()):
        if path in seen:
            return
        with open(path, encoding="utf-8", errors="ignore") as handle:
            lines = strip_comments(handle.read()).split("\n")
        rel = os.path.relpath(path, self.root).replace(os.sep, "/")
        in_define = False
        for number, line in enumerate(lines, 1):
            if in_define or line.lstrip().startswith("#"):
                # Directives and macro bodies are not config. A body's braces
                # would throw off the depth count.
                include = None if in_define else INCLUDE.match(line)
                in_define = line.rstrip().endswith("\\")
                if include:
                    target = self.resolve(include.group(1), path)
                    if target:
                        self.add_file(target, seen + (path,))
                continue
            self.starts.append(self.size)
            self.where.append((rel, number))
            self.text.append(line)
            self.size += len(line) + 1

    def locate(self, offset):
        return self.where[bisect.bisect_right(self.starts, offset) - 1]


def find_any_case(base, rel):
    """Walk rel under base ignoring case. Windows and Linux then agree here, and
    wrong-case includes are reported by `hemtt check` instead (PW4)."""
    cur = base
    for part in rel.replace("\\", "/").split("/"):
        if part in ("", "."):
            continue
        if part == "..":
            cur = os.path.dirname(cur)
            continue
        try:
            entries = os.listdir(cur)
        except OSError:
            return None
        match = next((e for e in entries if e.lower() == part.lower()), None)
        if match is None:
            return None
        cur = os.path.join(cur, match)
    return cur if os.path.isfile(cur) else None


def scan(addon, source):
    """Yield (kind, location, description) findings for one flattened addon."""
    text = "\n".join(source.text)
    stack = []             # open class records
    seen_bodies = {}       # lowercased scope path -> first location
    for match in TOKEN.finditer(text):
        tok = match.group(0)
        if tok.startswith('"'):
            continue
        if match.group("name"):
            name, parent = match.group("name"), match.group("parent")
            if match.group("end") == ";":
                continue
            where = source.locate(match.start())
            location = f"{where[0]}:{where[1]}"
            path = [c["name"] for c in stack if c] + [name]
            scope = "/".join(path)
            key = scope.lower()
            if key in seen_bodies:
                yield "duplicate", location, f"{scope} (first at {seen_bodies[key]})"
            else:
                seen_bodies[key] = location
            named = [c for c in stack if c]
            if len(named) == 1 and named[0]["name"].lower() in CONTAINERS and not parent:
                yield "parentless", location, scope
            stack.append({"name": name, "parent": parent, "location": location,
                          "has_xeh": False, "scope": scope})
            if name.lower() == XEH_CLASS:
                for entry in stack[:-1]:
                    if entry:
                        entry["has_xeh"] = True
        elif match.group("prop"):
            current = next((c for c in reversed(stack) if c), None)
            if current and current["name"].lower() == XEH_CLASS:
                where = source.locate(match.start())
                yield ("xeh-override", f"{where[0]}:{where[1]}",
                       f"{current['scope']}: {match.group('prop')}")
        elif tok == "{":
            stack.append(None)  # array or value brace
        elif tok == "}":
            if not stack:
                continue
            closed = stack.pop()
            if closed and closed["name"].lower() == "eventhandlers":
                named = [c for c in stack if c]
                if (len(named) == 2 and named[0]["name"].lower() == "cfgvehicles"
                        and not closed["parent"] and not closed["has_xeh"]):
                    yield "bare-eventhandlers", closed["location"], closed["scope"]


def main():
    args = sys.argv[1:]
    strict = "--strict" in args
    root = args[args.index("--root") + 1] if "--root" in args else REPO
    addons_dir = os.path.join(root, "addons")

    prefixes = {}
    for name in sorted(os.listdir(addons_dir)):
        pbo = os.path.join(addons_dir, name, "$PBOPREFIX$")
        if os.path.isfile(pbo):
            with open(pbo, encoding="utf-8") as handle:
                prefix = handle.read().strip().splitlines()[0].strip()
            prefixes[prefix.replace("\\", "/").strip("/").lower()] = os.path.join(addons_dir, name)

    ignored = set()
    if os.path.isfile(IGNORE_FILE):
        with open(IGNORE_FILE, encoding="utf-8") as handle:
            ignored = {l.strip() for l in handle if l.strip() and not l.startswith("#")}

    findings, skipped, used = [], 0, set()
    for name in sorted(os.listdir(addons_dir)):
        config = find_any_case(os.path.join(addons_dir, name), "config.cpp")
        if not config:
            continue
        source = Source(root, prefixes)
        source.add_file(config)
        for kind, location, description in scan(name, source):
            line = f"{kind} {name} {description}"
            # Line numbers drift, so duplicates ignore on the scope alone.
            bare = re.sub(r" \(first at .*\)$", "", line)
            if bare in ignored:
                skipped += 1
                used.add(bare)
                continue
            findings.append((kind, location, bare))

    print("== Config structure ==")
    for kind, location, line in sorted(findings):
        print(f"  {line}  [{location}]")
    if not findings:
        print("  none")
    for stale in sorted(ignored - used):
        print(f"  (stale ignore entry, please delete: {stale})")
    note = f" ({skipped} known exceptions ignored)" if skipped else ""
    print(f"\ncheck_config_structure: {len(findings)} problem(s){note}.")
    return 1 if findings and strict else 0


if __name__ == "__main__":
    sys.exit(main())
