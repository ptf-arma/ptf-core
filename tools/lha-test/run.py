#!/usr/bin/env python3
"""Test PTF_LHA in game, with no manual steps.

Builds the repo, adds the PBOs that ship with the mod but live outside git
(PTF_EXTERNAL_ADDONS), loads it with the workshop mods in .hemtt/launch.toml, and
plays tools/lha-test/mission through -autotest with the game kept in the background.
The mission checks every PTF_LHA change and logs one LHATEST line per check;
screenshots of the hangar land in .hemttout/lha-test/shots.

Usage:  python tools/lha-test/run.py [--no-build] [--external <folder of PBOs>] [--timeout 600] [--mission <folder>]
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(REPO / "tools" / "mp-test"))
import common  # noqa: E402

WORK = REPO / ".hemttout" / "lha-test"
DOCS = Path.home() / "Documents"

try:
    from common import launch_in_background
except ImportError:
    # Lives on the cigs branch until that merges.
    import importlib.util
    _path = REPO.parent / "immersive-cigs-addon-feasibility-d65301" / "tools" / "mp-test" / "common.py"
    _spec = importlib.util.spec_from_file_location("cigs_common", _path)
    _mod = importlib.util.module_from_spec(_spec)
    _spec.loader.exec_module(_mod)
    launch_in_background = _mod.launch_in_background


def capture_window(pid, target):
    """Capture only the Arma window (shared with tools/briefing-test)."""
    import importlib.util
    spec = importlib.util.spec_from_file_location("brief_run", REPO / "tools" / "briefing-test" / "run.py")
    mod = importlib.util.module_from_spec(spec)
    spec.loader.exec_module(mod)
    return mod.capture_window(pid, target)


def screenshot_files():
    roots = [DOCS / "Arma 3" / "Screenshots"] + list((DOCS / "Arma 3 - Other Profiles").glob("*/Screenshots"))
    return [f for r in roots if r.exists() for f in r.glob("lhatest_*")]


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--no-build", action="store_true")
    ap.add_argument("--external", default=os.environ.get("PTF_EXTERNAL_ADDONS"),
                    help="folder with the PBOs kept outside git (default: PTF_EXTERNAL_ADDONS)")
    ap.add_argument("--timeout", type=int, default=600)
    ap.add_argument("--mission", default=str(Path(__file__).parent / "mission"),
                    help="mission folder to play instead of the test (for probes)")
    args = ap.parse_args()

    if "arma3_x64.exe" in subprocess.run(["tasklist"], capture_output=True, text=True).stdout.lower():
        sys.exit("Arma 3 is running. Close it first.")
    if not args.external or not Path(args.external).is_dir():
        sys.exit("Pass --external or set PTF_EXTERNAL_ADDONS: PTF's aircraft need the PBOs kept outside git.")
    if not args.no_build:
        subprocess.run(["hemtt", "build"], cwd=REPO, check=True, capture_output=True)
        subprocess.run(["git", "checkout", "--", "addons/PTF_Main/script_version.hpp"], cwd=REPO, check=False)

    shutil.rmtree(WORK, ignore_errors=True)
    mod = WORK / "@ptf_lha_test"
    addons = mod / "addons"
    addons.mkdir(parents=True)
    built = {p.name.lower() for p in (REPO / ".hemttout" / "build" / "addons").glob("*.pbo")}
    for pbo in (REPO / ".hemttout" / "build" / "addons").glob("*.pbo"):
        shutil.copy2(pbo, addons)
    for pbo in Path(args.external).glob("*.pbo"):
        if pbo.name.lower() not in built:
            shutil.copy2(pbo, addons)

    mission = WORK / "lha_test.Stratis"
    shutil.copytree(args.mission, mission)
    cfg = WORK / "autotest.cfg"
    cfg.write_text(f'class TestMissions\n{{\n\tclass LhaTest\n\t{{\n\t\tcampaign = "";\n'
                   f'\t\tmission = "{mission}";\n\t}};\n}};\n')
    shots = WORK / "shots"
    shots.mkdir()
    for old in screenshot_files():
        old.unlink()

    started = time.time()
    game_dir = common.game_dir()
    proc = launch_in_background(
        [str(game_dir / "arma3_x64.exe"), common.mod_argument(str(mod)), f"-autotest={cfg}",
         "-skipIntro", "-noSplash", "-world=empty", "-noPause", "-noPauseAudio", "-showScriptErrors",
         "-window", "-posX=0", "-posY=0", "-x=1600", "-y=900"],
        cwd=game_dir)

    rpt = None
    quiet_since = None
    captured = set()
    while proc.poll() is None:
        for f in screenshot_files():
            try:
                shutil.move(str(f), shots / f.name.replace("lhatest_", ""))
            except OSError:
                pass
        if rpt is None:
            new = [p for p in common.RPT_DIR.glob("*.rpt") if p.stat().st_mtime > started]
            rpt = new[0] if new else None
        text = rpt.read_text(errors="replace") if rpt else ""
        for name in re.findall(r"LHATEST CAPTURE (\w+)", text):
            if name not in captured:
                captured.add(name)
                print(f"window capture {name}:", capture_window(proc.pid, shots / f"window_{name}.png"), flush=True)
        if "LHATEST DONE" in text:
            time.sleep(3)
            break
        # A script error in the mission usually stops it for good. Give it a
        # minute to log anything else, then stop instead of waiting out the timeout.
        last_check = text.rfind("LHATEST ")
        if last_check >= 0 and "rror in expression" in text[last_check:]:
            quiet_since = quiet_since or time.time()
            if time.time() - quiet_since > 60:
                print("Script error in the mission, stopping.")
                break
        else:
            quiet_since = None
        if time.time() - started > args.timeout:
            print("Timed out.")
            break
        time.sleep(1)
    if proc.poll() is None and not (rpt and "LHATEST DONE" in rpt.read_text(errors="replace")):
        # Stopped early: keep a picture of the game window to show why.
        try:
            print("window capture:", capture_window(proc.pid, shots / "stalled_window.png"))
        except Exception as e:  # noqa: BLE001 - diagnostics only
            print("window capture failed:", e)
    if proc.poll() is None:
        subprocess.run(["taskkill", "/PID", str(proc.pid), "/F"], capture_output=True)
    time.sleep(2)
    for f in screenshot_files():
        shutil.move(str(f), shots / f.name.replace("lhatest_", ""))
    print(f"Game ran {time.time() - started:.0f}s; screenshots in {shots}")

    # Script errors are listed but don't fail the run: PTF's other addons have known
    # ones (the MV-22's MFD conditions, logged when the test crews a helicopter).
    # A check that breaks because of one still logs FAIL.
    failed = 0
    done = False
    if rpt:
        shutil.copy2(rpt, WORK / "game.rpt")
        for line in rpt.read_text(errors="replace").splitlines():
            if "LHATEST" in line or "rror in expression" in line or "PTF_LHA" in line:
                print("  " + line[:300])
                failed += " FAIL " in line
                done |= "LHATEST DONE" in line
    ok = done and not failed
    print("PASSED" if ok else "FAILED", f"({failed} failed checks{'' if done else ', mission did not finish'})")
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
