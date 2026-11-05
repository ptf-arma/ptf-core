"""Paths and helpers shared by run_server.py and run_client.py."""
import os
import re
import shutil
from pathlib import Path

HERE = Path(__file__).resolve().parent
REPO = HERE.parent.parent
RPT_DIR = Path.home() / "AppData" / "Local" / "Arma 3"
STEAM = Path(os.environ.get("PTF_STEAM_DIR", r"C:\Program Files (x86)\Steam")) / "steamapps"


def game_dir():
    return STEAM / "common" / "Arma 3"


def server_dir():
    return STEAM / "common" / "Arma 3 Server"


def mod_argument(mod):
    """-mod= for the workshop mods in .hemtt/launch.toml, plus the build under test."""
    if not (Path(mod) / "addons").is_dir():
        raise SystemExit(f"No addons folder in {mod}. Pass the built mod folder.")
    ids = re.findall(r'"(\d{6,})"', (REPO / ".hemtt" / "launch.toml").read_text(encoding="utf-8"))
    workshop = STEAM / "workshop" / "content" / "107410"
    mods = [workshop / i for i in ids]
    missing = [m.name for m in mods if not m.is_dir()]
    if missing:
        print("Not subscribed, so left out:", ", ".join(missing), flush=True)
    return "-mod=" + ";".join([str(m) for m in mods if m.is_dir()] + [str(mod)])


def output_dir(label, clean=True):
    out = REPO / ".hemttout" / "mp-test" / label
    if clean:
        shutil.rmtree(out, ignore_errors=True)
    out.mkdir(parents=True, exist_ok=True)
    return out


def newest_rpt(profile):
    rpts = sorted(profile.glob("*.rpt"), key=lambda f: f.stat().st_mtime)
    return rpts[-1] if rpts else None


def keep_rpt(profile, target):
    rpt = newest_rpt(profile)
    if rpt:
        shutil.copy2(rpt, target)
