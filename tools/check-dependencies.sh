#!/bin/sh
# Report requiredAddons[] entries that don't resolve to either (a) a config
# class defined somewhere in THIS repo, or (b) a recognised external framework
# dependency (RHS/ACE/CBA/vanilla/etc.). Catches typos and missing internal
# deps like the "X requires Y" load errors players hit at startup.
#
# SCOPE / CAVEATS:
#   * It can only see this repo. A dependency that a *3rd-party* PBO declares
#     on one of our addons (e.g. Dagger Island -> drc_custom_billboards) lives
#     in that PBO's config, not here, so it can't be verified from here.
#   * External addon names are matched by prefix (see EXTERNAL below), not by a
#     real config, so a brand-new external mod with an unlisted prefix will be
#     reported even though it's valid. That's why this is ADVISORY by default:
#     eyeball new findings, then add the prefix here if legit.
#
# Usage:  tools/check-dependencies.sh [--strict]   (--strict exits 1 on finds)

set -u
strict=0
[ "${1:-}" = "--strict" ] && strict=1

repo=$(cd "$(dirname "$0")/.." && pwd)
cd "$repo"
tmp=$(mktemp -d); trap 'rm -rf "$tmp"' EXIT

# Prefixes/names of external framework addons we ship against but don't build.
# Anything a requiredAddons[] entry starts with here is treated as resolved.
EXTERNAL='^(A3_|ace_|acex_|cba_|rhs_|rhsusf_|rhsgref_|rhsafrf_|RHS_|USAF_|usaf_|Peral_|dega_|task_force_|tfar|TFAR|usp_|USP_|po_|boxloader|grad_|tsp_|TSP_|nds_|moe_|simunition|dagger|rhicc|drc_|ILBE|zen_|BettIR)'

# (a) Every config class defined anywhere in the repo — the superset that
#     includes every CfgPatches addon name, so a real internal dep always
#     resolves and is never falsely flagged.
find addons \( -name '*.cpp' -o -name '*.hpp' \) -type f 2>/dev/null \
    | xargs sed 's#//.*##' 2>/dev/null \
    | grep -oE 'class[[:space:]]+[A-Za-z0-9_]+' \
    | awk '{print $2}' | sort -u > "$tmp/defined"

# (b) Every requiredAddons[] entry (arrays may span multiple lines).
find addons \( -name '*.cpp' -o -name '*.hpp' \) -type f 2>/dev/null \
    | xargs sed 's#//.*##' 2>/dev/null \
    | awk '
        /requiredAddons/ { cap=1 }
        cap {
            buf = buf $0
            if ($0 ~ /}/) {
                while (match(buf, /"[A-Za-z0-9_]+"/)) {
                    tok = substr(buf, RSTART+1, RLENGTH-2)
                    print tok
                    buf = substr(buf, RSTART+RLENGTH)
                }
                cap = 0; buf = ""
            }
        }
    ' | sort -u > "$tmp/required"

unresolved=$(while IFS= read -r dep; do
    [ -z "$dep" ] && continue
    grep -qxF "$dep" "$tmp/defined" && continue          # internal
    printf '%s' "$dep" | grep -qE "$EXTERNAL" && continue # known external
    printf '%s\n' "$dep"
done < "$tmp/required")

echo "== requiredAddons that don't resolve (internal missing / typo / unlisted external) =="
if [ -n "$unresolved" ]; then
    printf '%s\n' "$unresolved" | sed 's/^/  /'
    echo ""
    echo "check-dependencies: $(printf '%s\n' "$unresolved" | grep -c .) unresolved dependency(ies)."
    if [ "$strict" -eq 1 ]; then exit 1; fi
else
    echo "  none"
fi
exit 0
