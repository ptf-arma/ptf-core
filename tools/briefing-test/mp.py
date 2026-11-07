#!/usr/bin/env python3
"""Test PTF_Briefing's multiplayer path with a dedicated server and a headless client.

The server loads a public Google deck through billet-link, the headless client asks
for every slide over the network, and the server checks each arrived intact
(BRIEFMP ... MATCH in the server RPT). No game window opens.

Usage:  python tools/briefing-test/mp.py --billet-dll <path to billet_link.dll> [--no-build] [--port 2412]
"""
import argparse
import shutil
import subprocess
import sys
import time
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent
sys.path.insert(0, str(REPO / "tools" / "mp-test"))
import common  # noqa: E402

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

WORKSHOP = common.STEAM / "workshop" / "content" / "107410"
MODS = ["450814997", "463939057", "3596653038"]  # CBA_A3, ACE3, Peral LHA
DEFAULT_URL = "https://docs.google.com/presentation/d/1EAYk18WDjIG-zp_0vLm3CsfQh_i8eXc67Jo2O9C6Vuc/edit"

ap = argparse.ArgumentParser()
ap.add_argument("--billet-dll", required=True)
ap.add_argument("--no-build", action="store_true")
ap.add_argument("--url", default=DEFAULT_URL)
ap.add_argument("--port", type=int, default=2412)
ap.add_argument("--timeout", type=int, default=300)
args = ap.parse_args()

if not args.no_build:
    subprocess.run(["hemtt", "build"], cwd=REPO, check=True, capture_output=True)
    subprocess.run(["git", "checkout", "--", "addons/PTF_Main/script_version.hpp"], cwd=REPO, check=False)

out = common.output_dir("briefing")
mod = out / "@ptf_briefing_test"
(mod / "addons").mkdir(parents=True)
shutil.copy2(REPO / ".hemttout" / "build" / "addons" / "PTF_Briefing.pbo", mod / "addons")
shutil.copy2(args.billet_dll, mod / "billet_link_x64.dll")
mod_arg = "-mod=" + ";".join([str(WORKSHOP / m) for m in MODS] + [str(mod)])

server_dir = common.server_dir()
exe = str(server_dir / "arma3server_x64.exe")
mission = server_dir / "mpmissions" / "ptf_briefing_mp.Stratis"
shutil.rmtree(mission, ignore_errors=True)
shutil.copytree(HERE / "mp", mission)
(mission / "test_settings.sqf").write_text(f'brief_url = "{args.url}";\n')

config = out / "server.cfg"
config.write_text("""hostname = "ptf briefing test";
password = "";
passwordAdmin = "ptfbrief";
maxPlayers = 2;
persistent = 1;
verifySignatures = 0;
BattlEye = 0;
headlessClients[] = {"127.0.0.1"};
localClient[] = {"127.0.0.1"};
class Missions { class M1 { template = "ptf_briefing_mp.Stratis"; difficulty = "Regular"; }; };
""")
server_profile = out / "profile_server"
server_profile.mkdir()
hc_profile = out / "profile_hc"
hc_profile.mkdir()

procs = [launch_in_background(
    [exe, f"-port={args.port}", f"-config={config}", f"-profiles={server_profile}", "-name=ptfbrief",
     "-autoInit", mod_arg, "-noSound"], cwd=server_dir)]
started = time.time()


def wait_for(text):
    while time.time() - started < args.timeout:
        time.sleep(3)
        if procs[0].poll() is not None:
            print("server exited with", procs[0].returncode, flush=True)
            return False
        rpt = common.newest_rpt(server_profile)
        if rpt and text in rpt.read_text(encoding="utf-8", errors="replace"):
            print(f"saw {text} after {int(time.time() - started)} s", flush=True)
            return True
    print("TIMEOUT waiting for", text, flush=True)
    return False


ok = False
try:
    if wait_for("BRIEFMP SERVER READY"):
        procs.append(launch_in_background(
            [exe, "-client", "-connect=127.0.0.1", f"-port={args.port}", "-password=", f"-profiles={hc_profile}",
             "-name=hc", mod_arg, "-noSound"], cwd=server_dir))
        ok = wait_for("BRIEFMP SERVER DONE")
finally:
    time.sleep(3)
    for proc in reversed(procs):
        if proc.poll() is None:
            subprocess.run(["taskkill", "/PID", str(proc.pid), "/F"], capture_output=True)
    time.sleep(3)
    common.keep_rpt(server_profile, out / "server.rpt")
    common.keep_rpt(hc_profile, out / "hc.rpt")
    shutil.rmtree(mission, ignore_errors=True)

for name in ("server.rpt", "hc.rpt"):
    path = out / name
    if path.exists():
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            if any(k in line for k in ("BRIEFMP", "PTF_Briefing", "billet", "rror in expression")):
                print(f"  {name}: {line[:260]}")
print("results in", out)
sys.exit(0 if ok else 1)
