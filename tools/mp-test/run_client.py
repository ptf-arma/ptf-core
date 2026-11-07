#!/usr/bin/env python3
"""Run the interface mission once under -autotest and keep its RPT.

Headless clients have no interface, so ACE actions and arsenal screens need this. It opens a
game window for about a minute, and the game exits by itself. It does not join a server:
connecting a real client this way hung for 20 minutes when it was tried.

Usage:  run_client.py <label> "<path to the built mod folder>" [--timeout 420]
"""
import argparse
import shutil
import subprocess
import sys
import time

import common

ap = argparse.ArgumentParser(description=__doc__, formatter_class=argparse.RawDescriptionHelpFormatter)
ap.add_argument("label", help="name for this run, e.g. baseline or fixed")
ap.add_argument("mod", help="the built mod folder, with an addons folder inside it")
ap.add_argument("--timeout", type=int, default=420)
args = ap.parse_args()

running = subprocess.run(["tasklist"], capture_output=True, text=True).stdout.lower()
if "arma3_x64.exe" in running:
    sys.exit("Arma is already running. Close it first.")

game_dir = common.game_dir()
out = common.output_dir(args.label, clean=False)
config = out / "autotest.cfg"
config.write_text('class TestMissions\n{\n\tclass T\n\t{\n\t\tcampaign = "";\n\t\tmission = "%s";\n\t};\n};\n'
                  % (common.HERE / "ptf_ui.Stratis"))

# -autotest ignores -profiles for its RPT, so watch the normal RPT folder for a new file.
before = set(common.RPT_DIR.glob("*.rpt"))
game = subprocess.Popen(
    [str(game_dir / "arma3_x64.exe"), common.mod_argument(args.mod), f"-autotest={config}", "-skipIntro", "-noSplash",
     "-world=empty", "-noPause", "-noPauseAudio", "-showScriptErrors", "-window", "-posX=0", "-posY=0"], cwd=game_dir)
print("client pid", game.pid, flush=True)

started = time.time()
rpt = None
finished = False
try:
    while time.time() - started < args.timeout:
        time.sleep(4)
        new = sorted(set(common.RPT_DIR.glob("*.rpt")) - before, key=lambda f: f.stat().st_mtime)
        rpt = new[-1] if new else rpt
        if rpt and "PTFUI DONE" in rpt.read_text(encoding="utf-8", errors="replace"):
            finished = True
            print(f"done after {int(time.time() - started)} s", flush=True)
            time.sleep(3)
            break
        if game.poll() is not None:
            print("client exited with", game.returncode, flush=True)
            break
    else:
        print("TIMEOUT", flush=True)
finally:
    if game.poll() is None:
        subprocess.run(["taskkill", "/PID", str(game.pid), "/F"], capture_output=True)
    time.sleep(3)
    if rpt:
        shutil.copy2(rpt, out / "client.rpt")

print("results in", out, flush=True)
sys.exit(0 if finished else 1)
