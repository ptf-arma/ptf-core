#!/bin/sh
# Compute the mod version (X.Y.Z) from git and write MINOR/PATCH into
# addons/PTF_Main/script_version.hpp (MAJOR is left as hand-maintained).
#
#   X (MAJOR) : from script_version.hpp — bumped by hand for major overhauls.
#   Y (MINOR) : number of release tags at this major (v<MAJOR>.*), i.e. how
#               many times master has been released.
#   Z (PATCH) : first-parent commits since the most recent release tag, i.e.
#               develop updates since the last release (0 at a release).
#
# Usage:
#   tools/gen-version.sh            # dev version   (Y = releases so far)
#   tools/gen-version.sh --release  # next release  (Y = releases + 1, Z = 0)
#
# Prints the computed X.Y.Z. Needs full git history (fetch-depth: 0 in CI).

set -u
repo=$(cd "$(dirname "$0")/.." && pwd)
cd "$repo"
VH=addons/PTF_Main/script_version.hpp

release=0
[ "${1:-}" = "--release" ] && release=1

major=$(grep -oE '#define[[:space:]]+MAJOR[[:space:]]+[0-9]+' "$VH" | grep -oE '[0-9]+$')
: "${major:=1}"

# Y: number of release tags at this major.
minor=$(git tag -l "v${major}.*" 2>/dev/null | wc -l | tr -d ' ')
# Z: first-parent commits since the most recent release tag (any major).
last=$(git tag -l 'v*' 2>/dev/null | sort -V | tail -1)
if [ -n "$last" ]; then
    patch=$(git rev-list --count --first-parent "${last}..HEAD" 2>/dev/null || echo 0)
else
    patch=$(git rev-list --count --first-parent HEAD 2>/dev/null || echo 0)
fi

if [ "$release" -eq 1 ]; then
    minor=$((minor + 1))
    patch=0
fi

sed -i -E \
    -e "s/#define[[:space:]]+MINOR[[:space:]]+[0-9]+/#define MINOR ${minor}/" \
    -e "s/#define[[:space:]]+PATCH[[:space:]]+[0-9]+/#define PATCH ${patch}/" \
    "$VH"

echo "${major}.${minor}.${patch}"
