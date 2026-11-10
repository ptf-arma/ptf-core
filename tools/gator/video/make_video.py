#!/usr/bin/env python3
"""Film the G/ATOR hype video: a PTF MRZR and a PTF ACV towing it on Malden, then it sets up.

Builds the repo, loads the full PTF modset (.hemtt/launch.toml workshop mods, this repo's PBOs,
the PBOs kept outside git and the G/ATOR data PBO), and plays tools/gator/video/mission with
the game kept in the background. The mission films frame by frame (see its init.sqf); this
script turns each screenshot into a JPEG as it lands, then lays the G/ATOR's own sounds on
the frames where the mission logged them, adds PTF title and end cards, and writes an MP4.

Usage:  python tools/gator/video/make_video.py [--no-build] [--external <folder>] [--data <pbo>]
                                               [--reuse-frames] [--out <file.mp4>]
--reuse-frames  skip the game and rebuild the MP4 from the last run's frames and log.
Needs ffmpeg, Pillow and numpy. About 20 minutes, most of it the game filming.
"""
import argparse
import os
import re
import shutil
import subprocess
import sys
import tempfile
import time
import wave
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFilter, ImageFont

REPO = Path(__file__).resolve().parents[3]
sys.path.insert(0, str(REPO / "tools" / "mp-test"))
sys.path.insert(0, str(REPO / "tools" / "gator"))
import common  # noqa: E402
from import_sounds import ffmpeg  # noqa: E402

WORK = REPO / ".hemttout" / "gator-video"
DOCS = Path.home() / "Documents"
SOUNDS = REPO / "addons" / "PTF_GATOR" / "sounds"
# the PTF website checkout beside this one, for the emblem on the title card (skipped without it)
BRAND = Path(os.environ.get("PTF_BRAND_DIR", REPO.parent / "ptf-website" / "public" / "brand"))
FPS = 30
RATE = 44100
SIZE = (1920, 1080)
GOLD = (196, 164, 102)
WHITE = (236, 232, 222)
OVERLAP = 0.5

try:
    from common import launch_in_background
except ImportError:
    import importlib.util
    _path = REPO.parent / "immersive-cigs-addon-feasibility-d65301" / "tools" / "mp-test" / "common.py"
    _spec = importlib.util.spec_from_file_location("cigs_common", _path)
    _mod = importlib.util.module_from_spec(_spec)
    _spec.loader.exec_module(_mod)
    launch_in_background = _mod.launch_in_background

# What each logged sound plays: (file, gain, playback speed).
ONE_SHOTS = {
    "PTF_GATOR_gen_start": ("gen_start", 0.9, 1.0),
    "PTF_GATOR_gen_stop": ("gen_stop", 0.9, 1.0),
    "PTF_GATOR_motor_start": ("motor_start", 0.8, 1.0),
    "PTF_GATOR_leg_down": ("leg_down", 1.0, 1.0),
}
LOOPS = {
    "gen": ("gen_loop", 0.55, 1.0),
    "motor": ("motor_loop", 0.8, 1.0),
    "hum": ("radar_hum", 0.7, 1.0),
    "leg_fl": ("motor_loop", 0.45, 1.35),
    "leg_fr": ("motor_loop", 0.45, 1.35),
    "leg_rl": ("motor_loop", 0.45, 1.35),
    "leg_rr": ("motor_loop", 0.45, 1.35),
}


def screenshot_files():
    roots = [DOCS / "Arma 3" / "Screenshots"] + list((DOCS / "Arma 3 - Other Profiles").glob("*/Screenshots"))
    return [f for r in roots if r.exists() for f in r.glob("gatorvid_*")]


def film(args):
    if "arma3_x64.exe" in subprocess.run(["tasklist"], capture_output=True, text=True).stdout.lower():
        sys.exit("Arma 3 is running. Close it first.")
    if not args.no_build:
        subprocess.run(["hemtt", "build"], cwd=REPO, check=True, capture_output=True)
        subprocess.run(["git", "checkout", "--", "addons/PTF_Main/script_version.hpp"], cwd=REPO, check=False)
    shutil.rmtree(WORK, ignore_errors=True)
    addons = WORK / "@ptf_gator_video" / "addons"
    addons.mkdir(parents=True)
    built = {p.name.lower() for p in (REPO / ".hemttout" / "build" / "addons").glob("*.pbo")}
    for pbo in (REPO / ".hemttout" / "build" / "addons").glob("*.pbo"):
        shutil.copy2(pbo, addons)
    for pbo in Path(args.external).glob("*.pbo"):
        if pbo.name.lower() not in built:
            shutil.copy2(pbo, addons)
    shutil.copy2(args.data, addons)
    mission = WORK / "gator_video.Malden"
    shutil.copytree(Path(__file__).parent / "mission", mission)
    cfg = WORK / "autotest.cfg"
    cfg.write_text(f'class TestMissions\n{{\n\tclass GatorVideo\n\t{{\n\t\tcampaign = "";\n'
                   f'\t\tmission = "{mission}";\n\t}};\n}};\n')
    frames = WORK / "frames"
    frames.mkdir()
    for old in screenshot_files():
        old.unlink()

    started = time.time()
    game_dir = common.game_dir()
    proc = launch_in_background(
        [str(game_dir / "arma3_x64.exe"), common.mod_argument(str(addons.parent)), f"-autotest={cfg}",
         "-skipIntro", "-noSplash", "-world=empty", "-noPause", "-noPauseAudio",
         "-window", "-posX=0", "-posY=0", f"-x={SIZE[0]}", f"-y={SIZE[1]}"],
        cwd=game_dir)
    rpt = None
    done = False
    while proc.poll() is None and time.time() - started < args.timeout:
        for f in screenshot_files():
            m = re.search(r"gatorvid_(\d+)", f.name)
            try:
                with Image.open(f) as im:
                    im.convert("RGB").resize(SIZE, Image.LANCZOS).save(frames / f"{int(m.group(1)):05d}.jpg", quality=93)
                f.unlink()
            except OSError:
                pass  # still being written
        if rpt is None:
            new = [p for p in common.RPT_DIR.glob("*.rpt") if p.stat().st_mtime > started]
            rpt = new[0] if new else None
        text = rpt.read_text(errors="replace") if rpt else ""
        if "GATORVID DONE" in text:
            time.sleep(5)
            done = True
            break
        time.sleep(0.5)
    for f in screenshot_files():
        m = re.search(r"gatorvid_(\d+)", f.name)
        with Image.open(f) as im:
            im.convert("RGB").resize(SIZE, Image.LANCZOS).save(frames / f"{int(m.group(1)):05d}.jpg", quality=93)
        f.unlink()
    if proc.poll() is None:
        subprocess.run(["taskkill", "/PID", str(proc.pid), "/F"], capture_output=True)
    if rpt:
        shutil.copy2(rpt, WORK / "game.rpt")
    print(f"Filmed for {(time.time() - started) / 60:.0f} min: {len(list(frames.glob('*.jpg')))} frames, "
          f"{'finished' if done else 'DID NOT FINISH'}")
    for line in (WORK / "game.rpt").read_text(errors="replace").splitlines() if rpt else []:
        if "GATORVID route" in line or "rror in expression" in line:
            print("  " + line[:300])
    if not done:
        sys.exit("The mission did not finish; see .hemttout/gator-video/game.rpt")


def decode(name, speed, tmp):
    wav = Path(tmp) / f"{name}_{speed}.wav"
    if not wav.exists():
        filt = [] if speed == 1.0 else ["-af", f"asetrate={int(RATE * speed)},aresample={RATE}"]
        subprocess.run([ffmpeg(), "-v", "error", "-y", "-i", str(SOUNDS / f"{name}.ogg"), *filt, "-ac", "1",
                        "-ar", str(RATE), str(wav)], check=True)
    with wave.open(str(wav)) as w:
        return np.frombuffer(w.readframes(w.getnframes()), np.int16).astype(np.float32) / 32768


def soundtrack(rpt_text, frames, tmp):
    """The G/ATOR's sounds, each placed on the frame the mission logged it."""
    total = int(frames / FPS * RATE) + RATE
    mix = np.zeros(total, np.float32)

    def add(audio, at, gain):
        start = int(at / FPS * RATE)
        end = min(total, start + len(audio))
        if end > start:
            mix[start:end] += audio[:end - start] * gain

    open_loops = {}
    for kind, name, frame in re.findall(r'"GATORVID (SOUND|LOOP|STOP) (\S+) (\d+)"', rpt_text):
        frame = int(frame)
        if kind == "SOUND" and name in ONE_SHOTS:
            file, gain, speed = ONE_SHOTS[name]
            add(decode(file, speed, tmp), frame, gain)
        elif kind == "LOOP" and name in LOOPS:
            open_loops[name] = frame
        elif kind == "STOP" and name in open_loops:
            start = open_loops.pop(name)
            lay_loop(add, name, start, frame, tmp)
    for name, start in open_loops.items():
        lay_loop(add, name, start, frames, tmp)
    peak = np.abs(mix).max() or 1
    return mix * (0.9 / peak)


def lay_loop(add, name, start, stop, tmp):
    file, gain, speed = LOOPS[name]
    clip = decode(file, speed, tmp)
    period = len(clip) / RATE - OVERLAP / speed
    t = start / FPS
    while t < stop / FPS:
        add(clip[:int((stop / FPS - t + 0.5) * RATE)], t * FPS, gain)
        t += period


def card(lines, emblem=True):
    """A title or end card: dark field, PTF emblem, gold and white type."""
    im = Image.new("RGB", SIZE, (14, 16, 13))
    d = ImageDraw.Draw(im)
    y = 260
    if emblem and (BRAND / "ptf-emblem-326w.png").exists():
        e = Image.open(BRAND / "ptf-emblem-326w.png").convert("RGBA")
        e = e.resize((220, int(220 * e.height / e.width)), Image.LANCZOS)
        im.paste(e, ((SIZE[0] - e.width) // 2, 140), e)
        y = 140 + e.height + 60
    for text, size, colour, font in lines:
        f = ImageFont.truetype(font, size)
        x0, y0, x1, y1 = d.textbbox((0, 0), text, font=f)
        d.text(((SIZE[0] - (x1 - x0)) / 2 - x0, y), text, fill=colour, font=f)
        y += (y1 - y0) + 28
    return im


def make(args):
    shot = {int(f.stem): f for f in (WORK / "frames").glob("*.jpg")}
    if not shot:
        sys.exit("No frames: run without --reuse-frames first.")
    # The game occasionally drops a screenshot: repeat the frame before it.
    frames, last = [], None
    for i in range(max(shot) + 1):
        last = shot.get(i, last)
        if last is not None:
            frames.append(last)
    print(f"{len(shot)} frames shot, {len(frames) - len(shot)} repeated to fill gaps")
    rpt = (WORK / "game.rpt").read_text(errors="replace")
    out = Path(args.out)
    out.parent.mkdir(parents=True, exist_ok=True)
    agency, bahn = r"C:\Windows\Fonts\AGENCYB.TTF", r"C:\Windows\Fonts\bahnschrift.ttf"
    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        seq = tmp / "seq"
        seq.mkdir()
        title = card([("AN/TPS-80 G/ATOR", 120, WHITE, agency), ("GROUND/AIR TASK-ORIENTED RADAR", 44, GOLD, bahn),
                      ("PTF CORE", 40, GOLD, agency)])
        end = card([("TOWED BY ANYTHING WE DRIVE.", 70, WHITE, agency), ("UP AND TURNING IN UNDER A MINUTE.", 70, WHITE, agency),
                    ("PARAMARINE TASK FORCE", 46, GOLD, agency)])
        n = 0
        lead = int(2.5 * FPS)

        def put(im):
            nonlocal n
            im.save(seq / f"{n:05d}.jpg", quality=93)
            n += 1

        black = Image.new("RGB", SIZE, (0, 0, 0))
        for i in range(lead):
            put(Image.blend(black, title, min(1, i / 15, (lead - i) / 15)))
        for i, f in enumerate(frames):
            im = Image.open(f).convert("RGB")
            if i < 12:
                im = Image.blend(black, im, i / 12)
            put(im)
        for i in range(int(3.5 * FPS)):
            put(Image.blend(black, end, min(1, i / 15, (int(3.5 * FPS) - i) / 15)))

        audio = soundtrack(rpt, len(frames), tmp)
        full = np.zeros(int(n / FPS * RATE) + RATE, np.float32)
        start = int(lead / FPS * RATE)
        full[start:start + len(audio)] += audio[:len(full) - start]
        fade = int(0.8 * RATE)
        tail = int(n / FPS * RATE)
        full[tail - fade:tail] *= np.linspace(1, 0, fade)
        full[tail:] = 0
        wav = tmp / "audio.wav"
        with wave.open(str(wav), "wb") as w:
            w.setnchannels(1)
            w.setsampwidth(2)
            w.setframerate(RATE)
            w.writeframes((np.clip(full[:tail], -1, 1) * 32767).astype(np.int16).tobytes())
        subprocess.run([ffmpeg(), "-v", "error", "-y", "-framerate", str(FPS), "-i", str(seq / "%05d.jpg"), "-i", str(wav),
                        "-c:v", "libx264", "-preset", "slow", "-crf", "21", "-pix_fmt", "yuv420p", "-c:a", "aac",
                        "-b:a", "192k", "-shortest", "-movflags", "+faststart", str(out)], check=True)
    print(f"Wrote {out} ({out.stat().st_size / 1e6:.1f} MB, {n / FPS:.0f} s)")


def main():
    ap = argparse.ArgumentParser()
    ap.add_argument("--no-build", action="store_true")
    ap.add_argument("--external", default=os.environ.get("PTF_EXTERNAL_ADDONS"))
    source = os.environ.get("PTF_GATOR_SOURCE", "")
    ap.add_argument("--data", default=str(Path(source) / "arma" / "ptf_gator_data.pbo") if source else None)
    ap.add_argument("--reuse-frames", action="store_true")
    ap.add_argument("--timeout", type=int, default=3600)
    ap.add_argument("--out", default=str(REPO / "releases" / "gator_hype.mp4"))
    args = ap.parse_args()
    if not args.reuse_frames:
        if not args.external or not Path(args.external).is_dir():
            sys.exit("Set PTF_EXTERNAL_ADDONS or pass --external.")
        if not args.data or not Path(args.data).is_file():
            sys.exit("Build the data PBO first (tools/gator/build_data.py).")
        film(args)
    make(args)


if __name__ == "__main__":
    main()
