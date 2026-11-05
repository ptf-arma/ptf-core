#!/usr/bin/env python3
"""Compare two server RPTs from run_server.py: config classes, crate reports and errors.

Usage:  compare.py <baseline server.rpt> <new server.rpt> [--no-config-change]

Exits 1 when the new build logs more of a known problem than the baseline, or with
--no-config-change when any config class differs. Use that flag for refactors.
"""
import collections
import re
import sys
from pathlib import Path

ERROR_PATTERNS = ["Error in expression", "Undefined variable", "'/' is not a value", "requires addon",
                  "does not support Extended", "Updating base class"]


def read(path):
    return Path(path).read_text(encoding="utf-8", errors="replace").splitlines()


def config_dump(lines):
    shallow, deep = {}, {}
    for line in lines:
        match = re.search(r'"CFGDUMP\|([SD])\|(.*)"$', line)
        if match:
            fields = match.group(2).split("|")
            (shallow if match.group(1) == "S" else deep)[(fields[0], fields[1])] = fields[2:]
    return shallow, deep


def reports(lines):
    """The PTFSMOKE report lines, without timestamps, so two runs can be diffed."""
    found = collections.Counter()
    for line in lines:
        match = re.search(r'"(PTFSMOKE SERVER [^"]*)"', line)
        if match:
            found[match.group(1)] += 1
    return found


def main():
    args = [a for a in sys.argv[1:] if not a.startswith("--")]
    if len(args) != 2:
        raise SystemExit(__doc__)
    no_config_change = "--no-config-change" in sys.argv
    base, new = read(args[0]), read(args[1])
    base_shallow, base_deep = config_dump(base)
    new_shallow, new_deep = config_dump(new)
    if not base_shallow or not new_shallow:
        raise SystemExit("No CFGDUMP lines. Pass the server.rpt of a finished run.")
    failed = False

    removed = sorted(set(base_shallow) - set(new_shallow))
    added = sorted(set(new_shallow) - set(base_shallow))
    shallow = [k for k in base_shallow if k in new_shallow and base_shallow[k] != new_shallow[k]]
    deep = [k for k in base_deep if k in new_deep and base_deep[k] != new_deep[k]]
    only_one = sorted(set(base_deep) ^ set(new_deep))
    print(f"Classes: {len(base_shallow)} -> {len(new_shallow)}, with PTF content: {len(base_deep)} -> {len(new_deep)}")
    print(f"  removed {len(removed)}: {removed[:40]}")
    print(f"  added {len(added)}: {added[:40]}")
    print(f"  changed parent, scope, model or name {len(shallow)}:")
    for key in shallow[:40]:
        print("   ", key, base_shallow[key], "->", new_shallow[key])
    print(f"  changed values {len(deep)}: {deep[:60]}")
    print(f"  PTF content in only one build {len(only_one)}: {only_one[:30]}")
    if no_config_change and (removed or added or shallow or deep or only_one):
        failed = True

    base_reports, new_reports = reports(base), reports(new)
    print(f"Crate and arsenal reports: {sum(base_reports.values())} -> {sum(new_reports.values())}")
    for text in (base_reports - new_reports):
        print("  - ", text[:190])
    for text in (new_reports - base_reports):
        print("  + ", text[:190])

    print("Known problems in the RPT:")
    for pattern in ERROR_PATTERNS:
        before = sum(pattern in line for line in base)
        after = sum(pattern in line for line in new)
        print(f"  {pattern!r}: {before} -> {after}")
        if after > before:
            failed = True

    print("RESULT:", "FAILED" if failed else "ok")
    return 1 if failed else 0


if __name__ == "__main__":
    sys.exit(main())
