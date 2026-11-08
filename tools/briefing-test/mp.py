#!/usr/bin/env python3
"""Test PTF_Briefing's multiplayer path with a dedicated server and a headless client.

The server loads a public Google deck through billet-link, the headless client asks
for every slide over the network, and the server checks each arrived intact
(BRIEFMP ... MATCH in the server RPT). No game window opens.

billet-link is linked to a stand-in Billet run here (a billet_link.toml in the test mod's
folder, which wins over any in the server's folder), so the load also goes through the
"Load briefing slides" permission check: the stand-in grants it to TEST_UID only, and the
run fails unless billet-link asked about exactly that player.

Usage:  python tools/briefing-test/mp.py --billet-dll <path to billet_link.dll> [--no-build] [--port 2412]
"""
import argparse
import http.server
import json
import shutil
import threading
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
TEST_UID = "76561198000000001"  # mp/init.sqf passes this SteamID

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

# Stand-in for Billet's tablet endpoint: grants slides_load to TEST_UID only.
asked = []


class FakeBillet(http.server.BaseHTTPRequestHandler):
    def do_POST(self):
        body = json.loads(self.rfile.read(int(self.headers.get("content-length", 0))) or b"{}")
        asked.append(body)
        reply = {"ok": True, "kind": "slides_role", "allowed": body.get("uid") == TEST_UID}
        if body.get("kind") != "slides_role":
            reply = {"ok": False, "reason": "unknown_kind"}
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
(mod / "billet_link.toml").write_text(
    f'endpoint = "http://127.0.0.1:{billet.server_port}/api/ingest/heartbeat"\nkey = "blk_briefing_test"\n')
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
print("billet asked:", asked)
if [a.get("uid") for a in asked] != [TEST_UID]:
    print("FAIL: billet-link should have asked the stand-in Billet once, about", TEST_UID)
    ok = False
print("results in", out)
sys.exit(0 if ok else 1)
