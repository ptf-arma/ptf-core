#!/usr/bin/env python3
"""Start a playable PTF_Briefing demo: the LHA at sea, you in its briefing room.

Loads CBA, ACE, ZEN, the Peral LHA and a test mod holding PTF_Briefing.pbo plus the
billet-link DLL, and starts straight into tools/briefing-test/demo. The game opens
normally (this one is for playing, not a background test). Esc, Abort closes it.

Usage:  python tools/briefing-test/demo.py --billet-dll <path to billet_link.dll> [--no-build] [--url URL]
"""
import argparse
import shutil
import subprocess
import sys
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
WORK = REPO / ".hemttout" / "briefing-demo"
GAME = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Arma 3")
WORKSHOP = Path(r"C:\Program Files (x86)\Steam\steamapps\workshop\content\107410")
MODS = ["450814997", "463939057", "1779063631", "3596653038"]  # CBA_A3, ACE3, ZEN, Peral LHA
DEFAULT_URL = "https://docs.google.com/presentation/d/1EAYk18WDjIG-zp_0vLm3CsfQh_i8eXc67Jo2O9C6Vuc/edit"

ap = argparse.ArgumentParser()
ap.add_argument("--billet-dll", required=True)
ap.add_argument("--no-build", action="store_true")
ap.add_argument("--url", default=DEFAULT_URL, help="link put on the clipboard at the start")
args = ap.parse_args()

if "arma3_x64.exe" in subprocess.run(["tasklist"], capture_output=True, text=True).stdout.lower():
    sys.exit("Arma 3 is running. Close it first.")
if not args.no_build:
    subprocess.run(["hemtt", "build"], cwd=REPO, check=True, capture_output=True)
    subprocess.run(["git", "checkout", "--", "addons/PTF_Main/script_version.hpp"], cwd=REPO, check=False)

shutil.rmtree(WORK, ignore_errors=True)
mod = WORK / "@ptf_briefing_demo"
(mod / "addons").mkdir(parents=True)
shutil.copy2(REPO / ".hemttout" / "build" / "addons" / "PTF_Briefing.pbo", mod / "addons")
shutil.copy2(args.billet_dll, mod / "billet_link_x64.dll")
mission = WORK / "ptf_briefing_demo.Stratis"
shutil.copytree(Path(__file__).parent / "demo", mission)
(mission / "test_settings.sqf").write_text(f'brief_url = "{args.url}";\n')
cfg = WORK / "autotest.cfg"
cfg.write_text(f'class TestMissions\n{{\n\tclass BriefDemo\n\t{{\n\t\tcampaign = "";\n'
               f'\t\tmission = "{mission}";\n\t}};\n}};\n')

subprocess.Popen(
    [str(GAME / "arma3_x64.exe"), "-mod=" + ";".join([str(WORKSHOP / m) for m in MODS] + [str(mod)]),
     f"-autotest={cfg}", "-skipIntro", "-noSplash", "-world=empty"],
    cwd=GAME)
print("Arma is starting with the demo.")
