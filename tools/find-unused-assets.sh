#!/bin/sh
# Report texture/model assets under PTF_Textures / PTF_Models that nothing in
# the repo references. Reference sources include configs, SQF, rvmats AND the
# binary .p3d / .bin files (scanned as text), so an asset used only inside a
# model or material is NOT falsely flagged.
#
# Usage:  tools/find-unused-assets.sh [--strict]
#   --strict : exit 1 if any unreferenced asset is found (for CI gating);
#              default is informational (always exit 0).

set -u
strict=0
[ "${1:-}" = "--strict" ] && strict=1

repo=$(cd "$(dirname "$0")/.." && pwd)
cd "$repo"

tmp=$(mktemp -d)
trap 'rm -rf "$tmp"' EXIT

# Every .paa / .p3d filename referenced anywhere (basename, lowercased).
grep -rahoiE '[a-z0-9_.:-]+\.(paa|p3d)' addons mod.cpp meta.cpp 2>/dev/null \
    | tr 'A-Z' 'a-z' | sed 's#.*[\\/]##' | sort -u > "$tmp/refs"

scan() { # $1 = dir  $2 = extension
    find "$1" -type f -iname "*.$2" 2>/dev/null | while IFS= read -r f; do
        b=$(basename "$f" | tr 'A-Z' 'a-z')
        grep -qxF "$b" "$tmp/refs" || printf '%s\n' "$f"
    done
}

{ scan addons/PTF_Textures paa; scan addons/PTF_Models p3d; } | sort > "$tmp/dead"

n=$(wc -l < "$tmp/dead" | tr -d ' ')
if [ "$n" -eq 0 ]; then
    echo "find-unused-assets: no unreferenced assets found."
    exit 0
fi

echo "find-unused-assets: $n unreferenced asset(s):"
sed 's/^/  /' "$tmp/dead"
if [ "$strict" -eq 1 ]; then exit 1; fi
exit 0
