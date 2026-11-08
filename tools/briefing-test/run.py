#!/usr/bin/env python3
"""Test PTF_Briefing in game, with no manual steps.

Builds PTF_Briefing, loads it with the Peral LHA, CBA and ACE plus a billet-link
DLL (the server half, from the Billet repo), runs tools/briefing-test/mission
through -autotest, keeps the game in the background, and collects screenshots
plus Arma-window captures into .hemttout/briefing-test.

Usage:  python tools/briefing-test/run.py --billet-dll <path to billet_link.dll> [--no-build] [--url URL]
                                          [--billet-endpoint http://127.0.0.1:<port>/api/ingest/heartbeat]
"""
import argparse
import ctypes
import shutil
import subprocess
import sys
import time
from ctypes import wintypes
from pathlib import Path

REPO = Path(__file__).resolve().parent.parent.parent
sys.path.insert(0, str(REPO / "tools" / "mp-test"))
WORK = REPO / ".hemttout" / "briefing-test"
GAME = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Arma 3")
LHA = Path(r"C:\Program Files (x86)\Steam\steamapps\workshop\content\107410\3596653038")
DOCS = Path.home() / "Documents"
RPT_DIR = Path.home() / "AppData" / "Local" / "Arma 3"
WORKSHOP = Path(r"C:\Program Files (x86)\Steam\steamapps\workshop\content\107410")
MODS = ["450814997", "463939057"]  # CBA_A3, ACE3
# Google's public Slides API sample deck.
DEFAULT_URL = "https://docs.google.com/presentation/d/1EAYk18WDjIG-zp_0vLm3CsfQh_i8eXc67Jo2O9C6Vuc/edit"

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


def screenshot_files():
    roots = [DOCS / "Arma 3" / "Screenshots"] + list((DOCS / "Arma 3 - Other Profiles").glob("*/Screenshots"))
    return [f for r in roots if r.exists() for f in r.glob("brieftest_*")]


def capture_window(pid, target):
    """Capture only the Arma window (PrintWindow), never the desktop."""
    from PIL import Image
    user32, gdi32 = ctypes.windll.user32, ctypes.windll.gdi32
    found = []

    @ctypes.WINFUNCTYPE(wintypes.BOOL, wintypes.HWND, wintypes.LPARAM)
    def each(hwnd, _):
        p = wintypes.DWORD()
        user32.GetWindowThreadProcessId(hwnd, ctypes.byref(p))
        if p.value == pid and user32.IsWindowVisible(hwnd):
            found.append(hwnd)
        return True

    user32.EnumWindows(each, 0)
    if not found:
        return False
    hwnd = found[0]
    rect = wintypes.RECT()
    user32.GetClientRect(hwnd, ctypes.byref(rect))
    w, h = rect.right, rect.bottom
    hdc = user32.GetDC(hwnd)
    mem = gdi32.CreateCompatibleDC(hdc)
    bmp = gdi32.CreateCompatibleBitmap(hdc, w, h)
    gdi32.SelectObject(mem, bmp)
    user32.PrintWindow(hwnd, mem, 3)  # PW_CLIENTONLY | PW_RENDERFULLCONTENT
    buf = ctypes.create_string_buffer(w * h * 4)
    gdi32.GetBitmapBits(bmp, len(buf), buf)
    Image.frombuffer("RGBA", (w, h), buf, "raw", "BGRA", 0, 1).convert("RGB").save(target)
    gdi32.DeleteObject(bmp)
    gdi32.DeleteDC(mem)
    user32.ReleaseDC(hwnd, hdc)
    return True


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--no-build", action="store_true")
    ap.add_argument("--url", default=DEFAULT_URL)
    ap.add_argument("--billet-dll", required=True, help="billet_link.dll built from the Billet repo")
    ap.add_argument("--timeout", type=int, default=420)
    ap.add_argument("--billet-endpoint", help="link billet-link to this Billet (its heartbeat URL) so loading asks it for the "
                    "slides_load permission; without it nobody is asked and the load goes ahead")
    args = ap.parse_args()

    if "arma3_x64.exe" in subprocess.run(["tasklist"], capture_output=True, text=True).stdout.lower():
        sys.exit("Arma 3 is running. Close it first.")
    if not args.no_build:
        subprocess.run(["hemtt", "build"], cwd=REPO, check=True, capture_output=True)
        subprocess.run(["git", "checkout", "--", "addons/PTF_Main/script_version.hpp"], cwd=REPO, check=False)

    shutil.rmtree(WORK, ignore_errors=True)
    addons = WORK / "@ptf_briefing_test" / "addons"
    addons.mkdir(parents=True)
    shutil.copy2(REPO / ".hemttout" / "build" / "addons" / "PTF_Briefing.pbo", addons)
    # Arma looks for extensions in each loaded mod's root folder.
    shutil.copy2(args.billet_dll, WORK / "@ptf_briefing_test" / "billet_link_x64.dll")
    if args.billet_endpoint:
        (WORK / "@ptf_briefing_test" / "billet_link.toml").write_text(
            f'endpoint = "{args.billet_endpoint}"\nkey = "blk_briefing_test"\n')
    mission = WORK / "brief_test.Stratis"
    shutil.copytree(Path(__file__).parent / "mission", mission)
    (mission / "test_settings.sqf").write_text(f'brief_url = "{args.url}";\n')
    cfg = WORK / "autotest.cfg"
    cfg.write_text(f'class TestMissions\n{{\n\tclass BriefTest\n\t{{\n\t\tcampaign = "";\n'
                   f'\t\tmission = "{mission}";\n\t}};\n}};\n')
    shots = WORK / "shots"
    shots.mkdir()
    for old in screenshot_files():
        old.unlink()

    started = time.time()
    proc = launch_in_background(
        [str(GAME / "arma3_x64.exe"), "-mod=" + ";".join([str(WORKSHOP / m) for m in MODS] + [str(LHA), str(WORK / "@ptf_briefing_test")]), f"-autotest={cfg}",
         "-skipIntro", "-noSplash", "-world=empty", "-noPause", "-noPauseAudio", "-showScriptErrors",
         "-window", "-posX=0", "-posY=0", "-x=1600", "-y=900"],
        cwd=GAME)

    rpt, seen = None, 0
    while proc.poll() is None:
        for f in screenshot_files():
            try:
                shutil.move(str(f), shots / f.name.replace("brieftest_", "shot_"))
            except OSError:
                pass
        if rpt is None:
            new = [p for p in RPT_DIR.glob("*.rpt") if p.stat().st_mtime > started]
            rpt = new[0] if new else None
        if rpt:
            lines = rpt.read_text(errors="replace").splitlines()
            for line in lines[seen:]:
                if "BRIEFTEST CAPTURE" in line:
                    name = line.split("BRIEFTEST CAPTURE", 1)[1].strip().strip('"')
                    ok = capture_window(proc.pid, shots / f"window_{name}.png")
                    print(f"window capture {name}: {ok}", flush=True)
            seen = len(lines)
        if time.time() - started > args.timeout:
            print("Timed out, closing the game.")
            proc.kill()
            break
        time.sleep(0.3)
    time.sleep(1)
    for f in screenshot_files():
        shutil.move(str(f), shots / f.name.replace("brieftest_", "shot_"))
    print(f"Game exited after {time.time() - started:.0f}s; files in {shots}")
    if rpt:
        shutil.copy2(rpt, WORK / "game.rpt")
        for line in rpt.read_text(errors="replace").splitlines():
            if any(k in line for k in ("BRIEFTEST", "rror in expression", "Exception code", "PTF_Briefing", "billet")):
                print("  " + line[:300])


if __name__ == "__main__":
    main()
