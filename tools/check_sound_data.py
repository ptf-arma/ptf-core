"""Check PTF_Sound generated data is in sync with tools/sound_lines.json.

Catches "edited the JSON, forgot to run tools/generate-sounds.py" without
needing network or TTS: every entry must have its OGG in the right category
folder plus its classes in cfgSounds.hpp, cfgModules.hpp and
cfgPatchesUnits.hpp; playlists must reference existing sounds; and no stray
OGGs may linger in the addon.

Usage: python tools/check_sound_data.py [--strict]
  --strict  exit 1 on problems (CI gating); default reports only.
"""

import json
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
ADDON = REPO / "addons" / "PTF_Sound"
SOUNDS = ADDON / "sounds"

data = json.loads((REPO / "tools" / "sound_lines.json").read_text(encoding="utf-8"))
entries = data["lines"] + data.get("music", []) + data.get("synth", [])
playlists = data.get("playlists", [])
names = [e["name"] for e in entries]

sounds_hpp = (ADDON / "cfgSounds.hpp").read_text(encoding="utf-8")
modules_hpp = (ADDON / "cfgModules.hpp").read_text(encoding="utf-8")
units_hpp = (ADDON / "cfgPatchesUnits.hpp").read_text(encoding="utf-8")

problems = []

dupes = {n for n in names if names.count(n) > 1}
for n in sorted(dupes):
    problems.append(f"duplicate name: {n}")

expected_oggs = set()
for e in entries:
    ogg = SOUNDS / e["category"] / f"{e['name']}.ogg"
    expected_oggs.add(ogg)
    if not ogg.exists():
        problems.append(f"missing OGG: {ogg.relative_to(REPO)} (regenerate)")
    if f"class PTF_Sound_{e['name']}\n" not in sounds_hpp:
        problems.append(f"cfgSounds.hpp missing class PTF_Sound_{e['name']} (regenerate)")
    if f"class PTF_Sound_Module_{e['name']}:" not in modules_hpp:
        problems.append(f"cfgModules.hpp missing class PTF_Sound_Module_{e['name']} (regenerate)")
    if f'"PTF_Sound_Module_{e["name"]}"' not in units_hpp:
        problems.append(f"cfgPatchesUnits.hpp missing PTF_Sound_Module_{e['name']} (regenerate)")

for pl in playlists:
    for item in pl["items"]:
        if item not in names:
            problems.append(f"playlist {pl['name']}: unknown item {item}")
    if f"class PTF_Sound_Module_playlist_{pl['name']}:" not in modules_hpp:
        problems.append(f"cfgModules.hpp missing playlist module {pl['name']} (regenerate)")
    if f'"PTF_Sound_Module_playlist_{pl["name"]}"' not in units_hpp:
        problems.append(f"cfgPatchesUnits.hpp missing playlist module {pl['name']} (regenerate)")

for stray in sorted(SOUNDS.rglob("*.ogg")):
    if stray not in expected_oggs:
        problems.append(f"stray OGG not in sound_lines.json: {stray.relative_to(REPO)}")

print("== PTF_Sound data consistency ==")
if problems:
    for p in problems:
        print(f"  {p}")
else:
    print("  none")
print(f"\ncheck_sound_data: {len(problems)} problem(s) "
      f"across {len(entries)} sounds and {len(playlists)} playlists.")

if problems and "--strict" in sys.argv:
    sys.exit(1)
