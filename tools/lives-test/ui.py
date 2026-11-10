#!/usr/bin/env python3
"""Check PTF_Lives on the Billet tablet and Rugged Phone, in single player, in the background.

Plays tools/lives-test/mission alone: the Home panel, the admin's Lives tab with clicks made
through the page (give and take a life, starting lives, search, off and on), then the phone.
You are the host, so you are an admin. No Billet answers, so Home shows its "no answer" page
with the Lives panel beside it. Lines starting LIVESTEST and LIVESPROBE are printed, and pictures of the
game window (only that window) land in .hemttout/mp-test/lives-ui.

Usage:  python tools/lives-test/ui.py [--billet PATH] [--no-build]
"""
import argparse
import ctypes
from ctypes import wintypes
import re
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

def capture(pid, target):
    """The game's own window, and nothing else on screen, drawn by PrintWindow into a PNG."""
    from PIL import Image
    user32, gdi32 = ctypes.windll.user32, ctypes.windll.gdi32
    found = []
    enum_type = ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)

    def collect(window, _):
        owner = wintypes.DWORD()
        user32.GetWindowThreadProcessId(window, ctypes.byref(owner))
        if owner.value == pid and user32.IsWindowVisible(window):
            found.append(window)
        return True

    user32.EnumWindows(enum_type(collect), 0)
    if not found:
        return False
    window = found[0]
    rect = wintypes.RECT()
    user32.GetClientRect(window, ctypes.byref(rect))
    width, height = rect.right, rect.bottom
    if width <= 0 or height <= 0:
        return False
    screen = user32.GetDC(window)
    dc = gdi32.CreateCompatibleDC(screen)
    bitmap = gdi32.CreateCompatibleBitmap(screen, width, height)
    gdi32.SelectObject(dc, bitmap)
    user32.PrintWindow(window, dc, 3)  # client area, full content (DirectX too)
    header = (ctypes.c_uint32 * 10)(40, width, (-height) & 0xFFFFFFFF, 1 | (32 << 16), 0, 0, 0, 0, 0, 0)
    pixels = ctypes.create_string_buffer(width * height * 4)
    gdi32.GetDIBits(dc, bitmap, 0, height, pixels, header, 0)
    gdi32.DeleteObject(bitmap)
    gdi32.DeleteDC(dc)
    user32.ReleaseDC(window, screen)
    Image.frombuffer("RGB", (width, height), pixels, "raw", "BGRX", 0, 1).save(target)
    return True


WORKSHOP = common.STEAM / "workshop" / "content" / "107410"
MODS = ["450814997", "463939057", "894678801"]  # CBA_A3, ACE3, TFAR
PROFILE = "ptflivesui"

ap = argparse.ArgumentParser()
ap.add_argument("--billet", default=str(REPO.parent.parent / "billet"), help="the Billet repo (or a worktree of it)")
ap.add_argument("--no-build", action="store_true")
ap.add_argument("--timeout", type=int, default=300)
args = ap.parse_args()
billet_repo = Path(args.billet)

if "arma3_x64.exe" in subprocess.run(["tasklist"], capture_output=True, text=True).stdout.lower():
    sys.exit("Arma 3 is running (maybe another test). Wait for it to close.")
if not args.no_build:
    subprocess.run(["hemtt", "build"], cwd=REPO, check=True, capture_output=True)
    subprocess.run(["git", "checkout", "--", "addons/PTF_Main/script_version.hpp"], cwd=REPO, check=False)
    subprocess.run(["hemtt", "build"], cwd=billet_repo / "mod", check=True, capture_output=True)

out = common.output_dir("lives-ui")
mod = out / "@ptf_lives_ui"
(mod / "addons").mkdir(parents=True)
shutil.copy2(REPO / ".hemttout" / "build" / "addons" / "PTF_Lives.pbo", mod / "addons")
shutil.copy2(billet_repo / "mod" / ".hemttout" / "build" / "addons" / "blk_tablet.pbo", mod / "addons")
mission = out / "ptf_lives_test.VR"
shutil.copytree(HERE / "mission", mission)
cfg = out / "autotest.cfg"
cfg.write_text(f'class TestMissions\n{{\n\tclass LivesUi\n\t{{\n\t\tcampaign = "";\n\t\tmission = "{mission}";\n\t}};\n}};\n')
profile = out / "profile"
profile.mkdir()

game = launch_in_background(
    [str(common.game_dir() / "arma3_x64.exe"), "-mod=" + ";".join([str(WORKSHOP / m) for m in MODS] + [str(mod)]),
     f"-autotest={cfg}", f"-profiles={profile}", f"-name={PROFILE}", "-skipIntro", "-noSplash", "-world=empty",
     "-window", "-noPause", "-noPauseAudio"], cwd=common.game_dir())
started = time.time()
ok = False
snapped = set()
try:
    while time.time() - started < args.timeout and game.poll() is None:
        time.sleep(0.5)
        rpt = common.newest_rpt(profile)
        text = rpt.read_text(encoding="utf-8", errors="replace") if rpt else ""
        # "LIVESTEST snap <name>": the mission holds still while the window is captured
        for name in re.findall(r"LIVESTEST snap (\w+)", text):
            if name not in snapped:
                snapped.add(name)
                print("captured" if capture(game.pid, out / f"{name}.png") else "could not capture", name, flush=True)
        if "LIVESTEST UI DONE" in text:
            ok = True
            break
finally:
    time.sleep(2)
    if game.poll() is None:
        subprocess.run(["taskkill", "/PID", str(game.pid), "/F"], capture_output=True)
    time.sleep(2)
    common.keep_rpt(profile, out / "client.rpt")

path = out / "client.rpt"
if path.exists():
    for line in path.read_text(encoding="utf-8", errors="replace").splitlines():
        if any(k in line for k in ("LIVESTEST", "LIVESPROBE", "PTF_Lives", "rror in expression", "rror position", "rror Undefined")):
            print(f"  {line[:600]}")
print("OK" if ok else "did not finish")
print("results in", out)
sys.exit(0 if ok else 1)
