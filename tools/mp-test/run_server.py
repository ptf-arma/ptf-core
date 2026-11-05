#!/usr/bin/env python3
"""Run the smoke mission on a dedicated server, with two headless clients joining in turn.

No game window opens. The mission (ptf_smoke.Stratis) reports crate contents, arsenals and
a hash of every PTF config class to the RPTs, which land in .hemttout/mp-test/<label>/.
See README.md.

Usage:  run_server.py <label> "<path to the built mod folder>" [--port 2402] [--timeout 1200]
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
# 2302 is left alone because other local servers tend to be using it.
ap.add_argument("--port", type=int, default=2402)
ap.add_argument("--timeout", type=int, default=1200, help="seconds allowed for each stage")
args = ap.parse_args()

server_dir = common.server_dir()
exe = str(server_dir / "arma3server_x64.exe")
mod_arg = common.mod_argument(args.mod)
out = common.output_dir(args.label)
mission = server_dir / "mpmissions" / "ptf_smoke.Stratis"

config = out / "server.cfg"
config.write_text("""hostname = "ptf smoke";
password = "";
passwordAdmin = "ptfsmoke";
maxPlayers = 4;
persistent = 1;
verifySignatures = 0;
BattlEye = 0;
headlessClients[] = {"127.0.0.1"};
localClient[] = {"127.0.0.1"};
allowedFilePatching = 0;
class Missions { class M1 { template = "ptf_smoke.Stratis"; difficulty = "Regular"; }; };
""")

shutil.rmtree(mission, ignore_errors=True)
shutil.copytree(common.HERE / "ptf_smoke.Stratis", mission)
server_profile = out / "profile_server"
server_profile.mkdir()
server = subprocess.Popen(
    [exe, f"-port={args.port}", f"-config={config}", f"-profiles={server_profile}", "-name=ptfsmoke",
     "-autoInit", mod_arg, "-noSound"], cwd=server_dir)
procs = [server]
print("server pid", server.pid, flush=True)
started = time.time()


def join_headless(number):
    profile = out / f"profile_hc{number}"
    profile.mkdir()
    proc = subprocess.Popen(
        [exe, "-client", "-connect=127.0.0.1", f"-port={args.port}", "-password=", f"-profiles={profile}",
         f"-name=hc{number}", mod_arg, "-noSound"], cwd=server_dir)
    procs.append(proc)
    print("headless client", number, "pid", proc.pid, flush=True)
    return profile


def wait_for(text):
    begun = time.time()
    while time.time() - begun < args.timeout:
        time.sleep(4)
        if server.poll() is not None:
            print("server exited with", server.returncode, flush=True)
            return False
        rpt = common.newest_rpt(server_profile)
        if rpt and text in rpt.read_text(encoding="utf-8", errors="replace"):
            print(f"saw {text} after {int(time.time() - started)} s", flush=True)
            return True
    print("TIMEOUT waiting for", text, flush=True)
    return False


finished = False
headless = []
try:
    if wait_for("PTFSMOKE SERVER READY"):
        headless.append(join_headless(1))
        if wait_for("PTFSMOKE SERVER HC2GO"):
            headless.append(join_headless(2))
            finished = wait_for("PTFSMOKE SERVER DONE")
finally:
    time.sleep(8)
    for proc in reversed(procs):
        if proc.poll() is None:
            subprocess.run(["taskkill", "/PID", str(proc.pid), "/F"], capture_output=True)
    time.sleep(3)
    common.keep_rpt(server_profile, out / "server.rpt")
    for number, profile in enumerate(headless, 1):
        common.keep_rpt(profile, out / f"hc{number}.rpt")
    shutil.rmtree(mission, ignore_errors=True)

print("results in", out, flush=True)
sys.exit(0 if finished else 1)
