#!/usr/bin/env python3
"""Test the G/ATOR in game, with no manual steps.

Loads a lean modset (CBA, ACE, and this repo's PTF_Main + PTF_GATOR with the data PBO built
by tools/gator/build_data.py), plays tools/gator/test/mission through -autotest with the
game kept in the background, and reports the mission's GATORTEST lines. The mission
spawns the radar on the VR map, checks it settles, steps the deploy sequence and compares
each moving part's probe point with where the model build says it should be, runs a real
deploy and stow, and takes screenshots (in .hemttout/gator-test/shots). About 2 minutes.

Usage:  python tools/gator/test/run.py [--no-build] [--data <ptf_gator_data.pbo>] [--timeout 400]
        python tools/gator/test/run.py --play     same modset, but a mission to walk round the
                                                  radar and use its ACE actions yourself; the
                                                  game stays open until you quit it
"""
import argparse
import json
import os
import re
import shutil
import subprocess
import sys
import time
from pathlib import Path

REPO = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(REPO / "tools" / "mp-test"))
sys.path.insert(0, str(Path(__file__).resolve().parent))
import common  # noqa: E402
from capture import capture_arma  # noqa: E402

WORK = REPO / ".hemttout" / "gator-test"
DOCS = Path.home() / "Documents"
WORKSHOP = common.STEAM / "workshop" / "content" / "107410"
MODS = {"CBA_A3": "450814997", "ACE3": "463939057"}
REPO_PBOS = ("ptf_main.pbo", "ptf_gator.pbo")

try:
    from common import launch_in_background
except ImportError:
    # Lives on the cigs branch until that merges.
    import importlib.util
    _path = REPO.parent / "immersive-cigs-addon-feasibility-d65301" / "tools" / "mp-test" / "common.py"
    if not _path.exists():
        _path = REPO.parents[2] / ".claude" / "worktrees" / "immersive-cigs-addon-feasibility-d65301" / "tools" / "mp-test" / "common.py"
    _spec = importlib.util.spec_from_file_location("cigs_common", _path)
    _mod = importlib.util.module_from_spec(_spec)
    _spec.loader.exec_module(_mod)
    launch_in_background = _mod.launch_in_background


def screenshot_files():
    roots = [DOCS / "Arma 3" / "Screenshots"] + list((DOCS / "Arma 3 - Other Profiles").glob("*/Screenshots"))
    return [f for r in roots if r.exists() for f in r.glob("gatortest_*")]


def write_expected(model_json, target):
    """The model build's probe positions, as SQF, in selectionPosition's axes: (-x, -z, y) of
    the P3D's (found in game, see build_model.py)."""
    info = json.loads(Path(model_json).read_text())
    hx, hy, hz = info["memory"]["hitch"][0]
    hitch = f"[{-hx}, {-hz}, {hy}]"
    rows = []
    for bone, by_phase in info["probes"].items():
        def key(p):
            return f"{float(p):g}" if p.replace(".", "").isdigit() else f'"{p}"'
        pairs = ", ".join(f"[{key(p)}, [{-x}, {-z}, {y}]]" for p, (x, y, z) in by_phase.items())
        rows.append(f'\t["{bone}", createHashMapFromArray [{pairs}], {hitch}]')
    target.write_text("// Written by tools/gator/test/run.py\n[\n" + ",\n".join(rows) + "\n]\n", newline="\n")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--no-build", action="store_true")
    source = os.environ.get("PTF_GATOR_SOURCE", "")
    ap.add_argument("--data", default=str(Path(source) / "arma" / "ptf_gator_data.pbo") if source else None,
                    help="the data PBO (default: $PTF_GATOR_SOURCE/arma/ptf_gator_data.pbo)")
    ap.add_argument("--timeout", type=int, default=400)
    ap.add_argument("--play", action="store_true", help="open the walk-around mission and leave the game running")
    ap.add_argument("--keep", action="store_true", help="with --mission: start it and leave the game running (a demo to look round)")
    ap.add_argument("--full", action="store_true",
                    help="the full PTF modset (.hemtt/launch.toml, this repo's PBOs and $PTF_EXTERNAL_ADDONS) instead of CBA + ACE")
    ap.add_argument("--extra", default="", help="a folder of PBOs to load as well, over any of the same name (e.g. a Billet build)")
    ap.add_argument("--world", default="", help="the map to play on (default: VR, or a --mission folder's suffix)")
    ap.add_argument("--mission", help="play this mission folder instead (for probes); it ends the run by logging GATORTEST DONE. "
                                      "A folder named <name>.<world> plays on that map")
    args = ap.parse_args()
    data = Path(args.data) if args.data else None
    if not data or not data.is_file():
        sys.exit("Build the data PBO first (tools/gator/build_data.py) and pass --data or set PTF_GATOR_SOURCE.")
    model_json = data.parent / "gator_model.json"

    if "arma3_x64.exe" in subprocess.run(["tasklist"], capture_output=True, text=True).stdout.lower():
        sys.exit("Arma 3 is running. Close it first.")
    if not args.no_build:
        subprocess.run(["hemtt", "build"], cwd=REPO, check=True, capture_output=True)
        subprocess.run(["git", "checkout", "--", "addons/PTF_Main/script_version.hpp"], cwd=REPO, check=False)

    shutil.rmtree(WORK, ignore_errors=True)
    addons = WORK / "@ptf_gator_test" / "addons"
    addons.mkdir(parents=True)
    built = list((REPO / ".hemttout" / "build" / "addons").glob("*.pbo"))
    for pbo in built:
        if args.full or pbo.name.lower() in REPO_PBOS:
            shutil.copy2(pbo, addons)
    if args.full:
        external = Path(os.environ.get("PTF_EXTERNAL_ADDONS", ""))
        if not external.is_dir():
            sys.exit("--full needs PTF_EXTERNAL_ADDONS set to the folder of PBOs kept outside git.")
        names = {p.name.lower() for p in built}
        for pbo in external.glob("*.pbo"):
            if pbo.name.lower() not in names and "gator" not in pbo.name.lower():
                shutil.copy2(pbo, addons)
    shutil.copy2(data, addons)
    if args.extra:
        for pbo in Path(args.extra).glob("*.pbo"):
            # never a build's dev-only test addons: they drive the game on their own
            if "devtest" not in pbo.name.lower():
                shutil.copy2(pbo, addons)

    # A probe mission folder named like "slope.Stratis" plays on that map; the rest on VR.
    world = args.world or (Path(args.mission).suffix[1:] if args.mission and Path(args.mission).suffix else "VR")
    mission = WORK / f"gator_test.{world}"
    shutil.copytree(Path(args.mission) if args.mission else Path(__file__).parent / ("play" if args.play else "mission"), mission)
    if not args.play:
        write_expected(model_json, mission / "expected.sqf")
    cfg = WORK / "autotest.cfg"
    cfg.write_text(f'class TestMissions\n{{\n\tclass GatorTest\n\t{{\n\t\tcampaign = "";\n'
                   f'\t\tmission = "{mission}";\n\t}};\n}};\n')
    shots = WORK / "shots"
    shots.mkdir()
    for old in screenshot_files():
        old.unlink()

    mods = [WORKSHOP / i for i in MODS.values()] + [addons.parent]
    if args.full:
        mods = [m for m in common.mod_argument(str(addons.parent))[len("-mod="):].split(";") if m]
    started = time.time()
    game_dir = common.game_dir()
    proc = launch_in_background(
        [str(game_dir / "arma3_x64.exe"), "-mod=" + ";".join(str(m) for m in mods), f"-autotest={cfg}",
         "-skipIntro", "-noSplash", "-world=empty", "-noPause", "-noPauseAudio", "-showScriptErrors",
         "-window", "-posX=0", "-posY=0", "-x=1600", "-y=900"],
        cwd=game_dir)
    if args.play or args.keep:
        print(f"Arma is starting in the background with the {'walk-around' if args.play else Path(args.mission).name} mission; bring it forward when you want it.")
        return

    rpt = None
    snapped = set()
    while proc.poll() is None:
        for f in screenshot_files():
            try:
                shutil.move(str(f), shots / f.name.replace("gatortest_", ""))
            except OSError:
                pass
        if rpt is None:
            new = [p for p in common.RPT_DIR.glob("*.rpt") if p.stat().st_mtime > started]
            rpt = new[0] if new else None
        text = rpt.read_text(errors="replace") if rpt else ""
        # "GATORTEST SNAP <name>": capture the Arma window itself (UI and all), which the
        # game's screenshot command can't; the mission holds still a few seconds after.
        for name in re.findall(r'GATORTEST SNAP (\w+)', text):
            if name not in snapped:
                snapped.add(name)
                time.sleep(0.5)
                print(f"  snap {name}: {'captured' if capture_arma(shots / (name + '.png')) else 'window capture failed'}")
        if "GATORTEST DONE" in text:
            time.sleep(3)
            break
        if time.time() - started > args.timeout:
            print("Timed out.")
            break
        time.sleep(1)
    if proc.poll() is None:
        subprocess.run(["taskkill", "/PID", str(proc.pid), "/F"], capture_output=True)
    time.sleep(2)
    for f in screenshot_files():
        shutil.move(str(f), shots / f.name.replace("gatortest_", ""))
    print(f"Game ran {time.time() - started:.0f}s; screenshots in {shots}")

    failed, done = 0, False
    if rpt:
        shutil.copy2(rpt, WORK / "game.rpt")
        for line in rpt.read_text(errors="replace").splitlines():
            low = line.lower()
            if "GATORTEST" in line or "rror in expression" in line or "gator" in low and ("warning" in low or "error" in low or "no entry" in low or "cannot" in low):
                print("  " + line[:400])
                failed += " FAIL " in line
                done |= "GATORTEST DONE" in line
    ok = done and not failed
    print("PASSED" if ok else "FAILED", f"({failed} failed checks{'' if done else ', mission did not finish'})")
    sys.exit(0 if ok else 1)


if __name__ == "__main__":
    main()
