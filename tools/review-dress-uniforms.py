#!/usr/bin/env python3
"""Screenshot the PTF_Dress uniforms in game, with no manual steps.

Builds the addon, loads only PTF_Dress and PTF_Main so the game starts quickly,
runs tools/dress-review/mission through Arma's -autotest, and collects the
screenshots into .hemttout/dress-review/shots. Refuses to run while Arma is open.
The game window opens and takes focus for the duration.

Usage:  python tools/review-dress-uniforms.py --ranks Sgt Capt --views front belt
        (omit --views for every camera position, --cap to add the frame cap)
"""
import argparse
import shutil
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent
WORK = REPO / ".hemttout" / "dress-review"
GAME = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Arma 3")
DOCS = Path.home() / "Documents"
RPT_DIR = Path.home() / "AppData" / "Local" / "Arma 3"
MISSION_NAME = "dress_review.Stratis"
# Lighting conditions the review can run in: hour, overcast, and a building to stand in.
LIGHTS = {
    "noon": '["noon",11,0]',
    "morning": '["morning",8,0.15]',
    "midmorning": '["midmorning",10,0.15]',
    "overcast": '["overcast",12,1]',
    "dusk": '["dusk",19,0.2]',
    "night": '["night",23,0]',
    "nightlit": '["nightlit",23,0,"",true]',
    "hangar": '["hangar",11,0,"Land_Hangar_F"]',
}


def screenshot_files():
    """Screenshots land in the active profile's folder, whichever that is."""
    roots = [DOCS / "Arma 3" / "Screenshots"] + list((DOCS / "Arma 3 - Other Profiles").glob("*/Screenshots"))
    return [f for r in roots if r.exists() for f in r.glob("dressreview_*")]


def arma_running() -> bool:
    out = subprocess.run(["tasklist"], capture_output=True, text=True).stdout.lower()
    return "arma3_x64.exe" in out


def prepare(args) -> Path:
    if not args.no_build:
        subprocess.run(["hemtt", "build"], cwd=REPO, check=True, capture_output=True)
        # hemtt rewrites this on every build; it is not part of the change.
        subprocess.run(["git", "checkout", "--", "addons/PTF_Main/script_version.hpp"], cwd=REPO, check=False)
    shutil.rmtree(WORK, ignore_errors=True)
    addons = WORK / "@ptf_dress_review" / "addons"
    addons.mkdir(parents=True)
    for pbo in ("PTF_Dress.pbo", "PTF_Main.pbo", "PTF_DICoverUSMC.pbo"):
        shutil.copy2(REPO / ".hemttout" / "build" / "addons" / pbo, addons / pbo)

    mission = WORK / MISSION_NAME
    shutil.copytree(REPO / "tools" / "dress-review" / "mission", mission)
    def cap(rank):
        if not args.cap:
            return '""'
        suffix = {"WO1": "_Officer", "CWO2": "_Officer", "CWO3": "_Officer", "CWO4": "_Officer", "CWO5": "_Officer",
                  "2ndLt": "_Officer", "1stLt": "_Officer", "Capt": "_Officer",
                  "Maj": "_Field", "LtCol": "_Field", "Col": "_Field"}.get(rank, "")
        return f'"PTF_Headgear_Dress_USMC_Cover{suffix}"'
    subjects = ",".join(f'["{r}","PTF_Uniform_Dress_USMC_A_{r}",{cap(r)}]' for r in args.ranks)
    views = ",".join(f'"{v}"' for v in args.views)
    if args.script:
        shutil.copy2(REPO / "tools" / "dress-review" / args.script / "init.sqf", mission / "init.sqf")
    if args.icons:
        shutil.copy2(REPO / "tools" / "dress-review" / "icons" / "init.sqf", mission / "init.sqf")
    if args.demo:
        # The demo shares the review mission's empty scene, with its own script.
        shutil.copy2(REPO / "tools" / "dress-review" / "demo" / "init.sqf", mission / "init.sqf")
    (mission / "review_list.sqf").write_text(
        f"dress_subjects = [{subjects}];\ndress_views = [{views}];\ndress_settle = {args.settle};\n"
        f"dress_lights = [{','.join(LIGHTS[l] for l in args.lights)}];\n"
        f'dress_ease = "{args.ease}";\ndress_salute = "{args.salute}";\ndress_anim = "{args.anim}";\n')

    cfg = WORK / "autotest.cfg"
    cfg.write_text(f'class TestMissions\n{{\n\tclass DressReview\n\t{{\n\t\tcampaign = "";\n'
                   f'\t\tmission = "{mission}";\n\t}};\n}};\n')
    return cfg


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--ranks", nargs="+", default=["Sgt", "Capt"])
    ap.add_argument("--views", nargs="*", default=[])
    ap.add_argument("--cap", action="store_true")
    ap.add_argument("--anim", default="AmovPercMstpSnonWnonDnon", help="pose for the rank review")
    ap.add_argument("--lights", nargs="+", default=["noon"], choices=list(LIGHTS))
    ap.add_argument("--settle", type=float, default=1.5)
    ap.add_argument("--no-build", action="store_true", help="reuse the last hemtt build")
    ap.add_argument("--timeout", type=int, default=420)
    ap.add_argument("--extra-mod", help="another mod folder to load, such as billet-link")
    ap.add_argument("--script", help="run tools/dress-review/<name>/init.sqf as the mission")
    ap.add_argument("--icons", action="store_true", help="shoot the Arsenal icon source images, needs --cap")
    ap.add_argument("--demo", action="store_true", help="run the posed lineup mission instead of the rank review")
    ap.add_argument("--ease", default="AmovPercMstpSnonWnonDnon_Ease", help="at-ease animation for --demo")
    ap.add_argument("--salute", default="AmovPercMstpSnonWnonDnon_Salute", help="salute animation for --demo")
    args = ap.parse_args()

    if arma_running():
        sys.exit("Arma 3 is running. Close it first: the review needs its own session.")

    cfg = prepare(args)
    for old in screenshot_files():
        old.unlink()

    started = time.time()
    proc = subprocess.Popen(
        [str(GAME / "arma3_x64.exe"), f"-mod={WORK / '@ptf_dress_review'}" + (f";{args.extra_mod}" if args.extra_mod else ""), f"-autotest={cfg}",
         "-skipIntro", "-noSplash", "-world=empty", "-noPause", "-showScriptErrors",
         "-window", "-posX=0", "-posY=0"],
        cwd=GAME)
    # The game refuses to write once its screenshot folder passes 250 MB, which a
    # full review reaches quickly, so move each shot out as it appears.
    shots = WORK / "shots"
    shots.mkdir(exist_ok=True)

    def collect():
        moved = 0
        for f in screenshot_files():
            try:
                shutil.move(str(f), shots / f.name.replace("dressreview_", ""))
                moved += 1
            except OSError:
                pass  # still being written; the next pass gets it
        return moved

    found = 0
    while proc.poll() is None:
        found += collect()
        if time.time() - started > args.timeout:
            print(f"Timed out after {args.timeout}s, closing the review game.")
            proc.kill()
            break
        time.sleep(0.5)
    time.sleep(1)
    found += collect()
    print(f"Game exited after {time.time() - started:.0f}s")
    print(f"{found} screenshots in {shots}")

    rpts = sorted(RPT_DIR.glob("*.rpt"), key=lambda p: p.stat().st_mtime)
    if rpts:
        rpt = rpts[-1]
        print(f"Log: {rpt}")
        for line in rpt.read_text(errors="replace").splitlines():
            if any(k in line for k in ("DRESSREVIEW", "ErrorMessage", "Exception code", "Error in expression", "ptf_dress")):
                print("  " + line[:170])
    sys.exit(0 if found else 1)


if __name__ == "__main__":
    main()
