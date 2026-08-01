#!/bin/sh
# Sanity-check the ACE arsenal whitelist and box config:
#   1. Duplicate classnames in the whitelist (copy-paste errors).
#   2. PTF_-prefixed whitelist entries not defined anywhere in this repo -
#      catches typos in PTF items. (Non-PTF RHS/vanilla entries can't be
#      verified without the full merged config, so they're skipped; and some
#      PTF_ entries may legitimately live in the external PBOs, so this list
#      is advisory - eyeball it.)
#   3. Arsenal-box texture paths in cfgArsenal.hpp that don't exist on disk.
#
# Usage:  tools/check-arsenal.sh [--strict]   (--strict exits 1 on 1+2+3 hits)

set -u
strict=0
[ "${1:-}" = "--strict" ] && strict=1

repo=$(cd "$(dirname "$0")/.." && pwd)
cd "$repo"

WL=addons/PTF_Scripts/fnc/arsenal/fn_arsenalWhitelist.sqf
ARS=addons/PTF_Utility/cfgArsenal.hpp
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT
issues=0

echo "== Duplicate whitelist entries =="
dups=$(grep -oE '"[A-Za-z0-9_]+"' "$WL" | sort | uniq -d)
if [ -n "$dups" ]; then printf '%s\n' "$dups" | sed 's/^/  /'; issues=$((issues + 1)); else echo "  none"; fi

echo "== PTF_ whitelist entries not defined in this repo (advisory) =="
grep -rhoE 'class (PTF_[A-Za-z0-9_]+)' addons --include='*.hpp' --include='*.cpp' \
    | awk '{print $2}' | sort -u > "$tmp/defined"
undef=$(grep -oE '"PTF_[A-Za-z0-9_]+"' "$WL" | tr -d '"' | sort -u | while IFS= read -r c; do
    grep -qxF "$c" "$tmp/defined" || printf '%s\n' "$c"
done)
if [ -n "$undef" ]; then printf '%s\n' "$undef" | sed 's/^/  /'; issues=$((issues + 1)); else echo "  none"; fi

echo "== Arsenal-box textures that don't exist =="
missing=$(grep -ohE '\\z\\PTF\\[^"]+\.paa' "$ARS" | sort -u | while IFS= read -r p; do
    d="addons/$(printf '%s' "$p" | sed 's#\\#/#g; s#^/z/PTF/addons/##')"
    [ -f "$d" ] || printf '%s\n' "$p"
done)
if [ -n "$missing" ]; then printf '%s\n' "$missing" | sed 's/^/  /'; issues=$((issues + 1)); else echo "  none"; fi

echo ""
if [ "$issues" -gt 0 ]; then
    echo "check-arsenal: $issues category(ies) with findings."
    if [ "$strict" -eq 1 ]; then exit 1; fi
fi
exit 0
