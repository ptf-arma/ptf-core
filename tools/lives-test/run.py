#!/usr/bin/env python3
"""Test PTF_Lives in multiplayer: a dedicated server and a real player, in the background.

The player (your own Arma, joining the local server) runs tools/lives-test/mission/init.sqf:
the Billet tablet's Home panel and the admin's Lives tab (clicked through the page), two
deaths (the second leaves them spectating), an admin giving a life back, then going
unconscious. The runner kills the game there, which is leaving while unconscious, starts it
again, and the player must come back still out of lives until an admin switches Lives off.

Billet is a stand-in run here: it says "not linked" to the tablet's own screens and grants
"Manage lives" (lives_role) to everyone. Screenshots land in the output folder.

Needs: the Billet repo next to this one (or --billet), with its mod built by this script and
billet-link's DLL built (cargo build --release in mod/extension), CBA, ACE and TFAR from Steam.

Not yet seen working: on the dev PC (2026-11-09) the server refused the game's Steam ticket
("Client kicked due to failed Steam checks: Invalid ticket") on 127.0.0.1 and on the LAN
address, with and without loopback and SteamAppId set. ui.py covers the tablet in single
player; the deaths, spectating and rejoin still need a real multiplayer session.

Usage:  python tools/lives-test/run.py [--billet PATH] [--no-build] [--port 2302] [--host ADDRESS]
"""
import argparse
import http.server
import json
import os
import shutil
import subprocess
import sys
import threading
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
MODS = ["450814997", "463939057", "894678801"]  # CBA_A3, ACE3, TFAR
PROFILE = "ptflivestest"

ap = argparse.ArgumentParser()
ap.add_argument("--billet", default=str(REPO.parent.parent / "billet"), help="the Billet repo (or a worktree of it)")
ap.add_argument("--no-build", action="store_true")
ap.add_argument("--port", type=int, default=2302)
ap.add_argument("--host", default="127.0.0.1", help="the address the game joins (try this PC's LAN address if Steam rejects the ticket)")
ap.add_argument("--timeout", type=int, default=420)
args = ap.parse_args()
billet_repo = Path(args.billet)

if "arma3_x64.exe" in subprocess.run(["tasklist"], capture_output=True, text=True).stdout.lower():
    sys.exit("Arma 3 is running (maybe another test). Wait for it to close.")
if not args.no_build:
    subprocess.run(["hemtt", "build"], cwd=REPO, check=True, capture_output=True)
    subprocess.run(["git", "checkout", "--", "addons/PTF_Main/script_version.hpp"], cwd=REPO, check=False)
    subprocess.run(["hemtt", "build"], cwd=billet_repo / "mod", check=True, capture_output=True)
dll = billet_repo / "mod" / "extension" / "target" / "release" / "billet_link.dll"
if not dll.exists():
    sys.exit(f"No billet-link DLL at {dll}: cargo build --release in mod/extension first.")

out = common.output_dir("lives")
client_mod = out / "@ptf_lives_test"
(client_mod / "addons").mkdir(parents=True)
shutil.copy2(REPO / ".hemttout" / "build" / "addons" / "PTF_Lives.pbo", client_mod / "addons")
shutil.copy2(billet_repo / "mod" / ".hemttout" / "build" / "addons" / "blk_tablet.pbo", client_mod / "addons")
server_mod = out / "@ptf_lives_server"
(server_mod / "addons").mkdir(parents=True)
shutil.copy2(billet_repo / "mod" / ".hemttout" / "build" / "addons" / "blk_main.pbo", server_mod / "addons")
shutil.copy2(dll, server_mod / "billet_link_x64.dll")

# Stand-in for billet.gg: heartbeats are fine, the tablet's own screens say "not linked",
# and anyone may manage lives.
asked = []


class FakeBillet(http.server.BaseHTTPRequestHandler):
    def do_POST(self):
        body = json.loads(self.rfile.read(int(self.headers.get("content-length", 0))) or b"{}")
        reply = {"ok": True}
        if self.path.endswith("/tablet"):
            asked.append(body.get("kind"))
            if body.get("kind") == "lives_role":
                reply = {"ok": True, "kind": "lives_role", "allowed": True}
            else:
                reply = {"ok": False, "reason": "not_linked"}
        data = json.dumps(reply, separators=(",", ":")).encode()
        self.send_response(200)
        self.send_header("Content-Type", "application/json")
        self.send_header("Content-Length", str(len(data)))
        self.end_headers()
        self.wfile.write(data)

    def log_message(self, *_):
        pass


billet = http.server.HTTPServer(("127.0.0.1", 0), FakeBillet)
threading.Thread(target=billet.serve_forever, daemon=True).start()
(server_mod / "billet_link.toml").write_text(
    f'endpoint = "http://127.0.0.1:{billet.server_port}/api/ingest/heartbeat"\nkey = "blk_lives_test"\n')

mods = [str(WORKSHOP / m) for m in MODS] + [str(client_mod)]
mod_arg = "-mod=" + ";".join(mods)
server_dir = common.server_dir()
mission = server_dir / "mpmissions" / "ptf_lives_test.VR"
shutil.rmtree(mission, ignore_errors=True)
shutil.copytree(HERE / "mission", mission)

config = out / "server.cfg"
config.write_text("""hostname = "ptf lives test";
password = "";
passwordAdmin = "ptflives";
maxPlayers = 2;
persistent = 1;
verifySignatures = 0;
BattlEye = 0;
disconnectTimeout = 5;
localClient[] = {"127.0.0.1", "%s"};
class Missions { class M1 { template = "ptf_lives_test.VR"; difficulty = "Regular"; }; };
""" % args.host)
server_profile = out / "profile_server"
server_profile.mkdir()
client_profile = out / "profile_client"
client_profile.mkdir()

procs = []
started = time.time()


def rpt_text(profile):
    rpt = common.newest_rpt(profile)
    return rpt.read_text(encoding="utf-8", errors="replace") if rpt else ""


def wait_for(profile, text, after=0):
    """Wait until `text` appears in the profile's newest RPT, past character `after`."""
    while time.time() - started < args.timeout:
        time.sleep(2)
        if procs[0].poll() is not None:
            print("server exited with", procs[0].returncode, flush=True)
            return False
        if text in rpt_text(profile)[after:]:
            print(f"saw {text} after {int(time.time() - started)} s", flush=True)
            return True
    print("TIMEOUT waiting for", text, flush=True)
    return False


def start_client():
    return launch_in_background(
        [str(common.game_dir() / "arma3_x64.exe"), "-client", f"-connect={args.host}", f"-port={args.port}", "-password=",
         f"-profiles={client_profile}", f"-name={PROFILE}", mod_arg, "-skipIntro", "-noSplash", "-world=empty",
         "-window", "-noPause", "-noPauseAudio"], cwd=common.game_dir(),
        # as if Steam had started it, so its Steam ticket is valid for the server
        env={**os.environ, "SteamAppId": "107410", "SteamGameId": "107410"})


def stop(proc):
    if proc.poll() is None:
        subprocess.run(["taskkill", "/PID", str(proc.pid), "/F"], capture_output=True)


ok = False
try:
    procs.append(launch_in_background(
        [str(server_dir / "arma3server_x64.exe"), f"-port={args.port}", f"-config={config}", f"-profiles={server_profile}",
         "-name=ptflives", "-autoInit", mod_arg, f"-serverMod={server_mod}", "-noSound"], cwd=server_dir))
    if wait_for(server_profile, "LIVESTEST SERVER READY"):
        client = start_client()
        procs.append(client)
        if wait_for(client_profile, "LIVESTEST C1 DROP"):
            # the game goes away while the player is unconscious
            stop(client)
            if wait_for(server_profile, "left while unconscious", 0):
                time.sleep(5)
                client = start_client()
                procs.append(client)
                ok = wait_for(client_profile, "LIVESTEST C2 DONE")
finally:
    time.sleep(3)
    for proc in reversed(procs):
        stop(proc)
    time.sleep(3)
    common.keep_rpt(server_profile, out / "server.rpt")
    rpts = sorted(client_profile.glob("*.rpt"), key=lambda f: f.stat().st_mtime)
    for i, rpt in enumerate(rpts, 1):
        shutil.copy2(rpt, out / f"client{i}.rpt")
    shots = list(client_profile.rglob("*.png")) + list((Path.home() / "Documents" / "Arma 3 - Other Profiles" / PROFILE).rglob("*.png"))
    for shot in shots:
        shutil.copy2(shot, out / shot.name)
    shutil.rmtree(mission, ignore_errors=True)

for name in ["server.rpt"] + [f"client{i}.rpt" for i in range(1, 4)]:
    path = out / name
    if path.exists():
        for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
            if any(k in line for k in ("LIVESTEST", "LIVESPROBE", "PTF_Lives", "rror in expression", "rror position")):
                print(f"  {name}: {line[:400]}")
print("billet asked:", asked)
print("results in", out)
sys.exit(0 if ok else 1)
