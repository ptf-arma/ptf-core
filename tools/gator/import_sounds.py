#!/usr/bin/env python3
"""Cut the G/ATOR's sounds out of four Pixabay recordings and the owner's incoming alarm into
addons/PTF_GATOR/sounds.

The recordings are under the Pixabay Content License (see credits_and_license.txt) and aren't
committed. They sit in <PTF_GATOR_SOURCE>/sounds under their Pixabay download names. Every cut
is only trimmed, faded and levelled (the alarm also goes through a loudspeaker, SPEAKER). A loop clip fades in and out over OVERLAP seconds at
each end: the game starts each repeat that much before the last one ends, on a second
emitter, so the two crossfade and a frame of timing error can't be heard (fn_soundLoop.sqf,
whose loop periods are the lengths this prints minus OVERLAP). Output is mono 44.1 kHz OGG,
so the game can place it in 3D.

    python tools/gator/import_sounds.py [--source <folder with the mp3s>]

Needs ffmpeg and numpy.
"""
import argparse
import os
import shutil
import subprocess
import sys
import tempfile
import wave
from pathlib import Path

import numpy as np

REPO = Path(__file__).resolve().parents[2]
OUT = REPO / "addons" / "PTF_GATOR" / "sounds"
RATE = 44100
OVERLAP = 0.5

DIESEL = "freesound_community-diesel-engine-startup-and-stutdown-69303.mp3"
HUM = "freesoundfx-electric-generators-loopable-388827.mp3"
MECH = "audiopapkin-mechanical-sfx-018-314780.mp3"
CLUNK = "freesound_community-heater-vent-hit-lower-part-83044.mp3"
# The incoming alarm, supplied by the owner (made with Voicemod): a tone pulsing every 0.68 s
# for 5.6 s, then the voice, the whole cycle repeating every 7.183 s.
ALARM = "c-ram-incoming-alarm-(alarm-red-iraq)-made-with-Voicemod.mp3"

# name: (source, start s, end s, peak, kind, fade s). The diesel recording cranks from 0.3 s,
# settles to idle by 5 s, idles steadily to 20 s and stops by 22.8 s. The mechanical one is a
# little louder for its first 2.5 s, then steady. One-shots that hand over to a loop (or take
# over from one) fade over the same OVERLAP, so the two crossfade.
CUTS = {
    "gen_start": (DIESEL, 0.25, 5.50, 0.85, "oneshot", OVERLAP),
    "gen_loop": (DIESEL, 6.00, 19.50, 0.70, "loop", OVERLAP),
    "gen_stop": (DIESEL, 19.60, 22.75, 0.70, "oneshot", OVERLAP),
    "radar_hum": (HUM, 0.30, 17.50, 0.60, "loop", OVERLAP),
    "motor_start": (MECH, 0.00, 2.80, 0.90, "oneshot", OVERLAP),
    "motor_loop": (MECH, 2.40, 10.50, 0.90, "loop", OVERLAP),
    "leg_down": (CLUNK, 0.00, 0.80, 0.85, "oneshot", 0.02),
    # One whole cycle plus the overlap, from 0.6 s, so each repeat overlaps the next across the
    # near-silent gap between two pulses at 0.85 s. The repeats are the same sound in step, so
    # they crossfade in straight lines ("cycle"): equal-power fades would swell over the seam.
    "alarm": (ALARM, 0.60, 0.60 + 7.183 + OVERLAP, 0.98, "cycle", OVERLAP),
}

# The alarm comes out of a loudspeaker on the trailer, so its recording goes through one: the
# band a horn speaker carries (no deep bass, no fizz above 4 kHz), a little of its cone's
# break-up, and compression, as a PA's amplifier squeezes it, which also makes it louder for
# the same peak. Applied to the whole recording before it is cut.
SPEAKER = {
    ALARM: "highpass=f=380:poles=2,highpass=f=380:poles=2,lowpass=f=3800:poles=2,lowpass=f=3800:poles=2,"
           "equalizer=f=1800:t=q:w=1.2:g=5,acompressor=threshold=-30dB:ratio=10:attack=2:release=60:makeup=14dB,"
           "asoftclip=type=tanh:threshold=0.6",
}


def ffmpeg():
    exe = shutil.which("ffmpeg")
    if exe:
        return exe
    winget = Path(os.environ.get("LOCALAPPDATA", "")) / "Microsoft" / "WinGet" / "Packages"
    found = sorted(winget.glob("Gyan.FFmpeg*/**/bin/ffmpeg.exe"))
    if not found:
        sys.exit("ffmpeg not found")
    return str(found[-1])


def decode(path, tmp, speaker=""):
    wav = Path(tmp) / (path.stem + ".wav")
    subprocess.run([ffmpeg(), "-v", "error", "-y", "-i", str(path), "-ac", "1", "-ar", str(RATE)] + (["-af", speaker] if speaker else []) + [str(wav)], check=True)
    with wave.open(str(wav)) as w:
        return np.frombuffer(w.readframes(w.getnframes()), np.int16).astype(np.float32) / 32768


def cut(audio, start, end, peak, kind, fade):
    a = audio[int(start * RATE):int(end * RATE)].copy()
    n = int(fade * RATE)
    if kind == "cycle":
        ramp = np.linspace(0, 1, n)
        a[:n] *= ramp
        a[-n:] *= ramp[::-1]
    elif kind == "loop" or fade >= OVERLAP:
        # Equal-power fades, so two copies overlapping by `fade` keep the level steady.
        t = np.linspace(0, np.pi / 2, n)
        a[:n] *= np.sin(t)
        a[-n:] *= np.cos(t)
    else:
        a[:n] *= np.linspace(0, 1, n)
        a[-n:] *= np.linspace(1, 0, n)
    return a * (peak / max(1e-6, np.abs(a).max()))


def write_ogg(audio, target, tmp):
    wav = Path(tmp) / (target.stem + "_out.wav")
    with wave.open(str(wav), "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(RATE)
        w.writeframes((np.clip(audio, -1, 1) * 32767).astype(np.int16).tobytes())
    subprocess.run([ffmpeg(), "-v", "error", "-y", "-i", str(wav), "-c:a", "libvorbis", "-q:a", "5", str(target)], check=True)


def main():
    ap = argparse.ArgumentParser()
    default = Path(os.environ.get("PTF_GATOR_SOURCE", "")) / "sounds" if os.environ.get("PTF_GATOR_SOURCE") else None
    ap.add_argument("--source", default=default)
    args = ap.parse_args()
    if not args.source or not Path(args.source).is_dir():
        sys.exit("Pass --source or set PTF_GATOR_SOURCE (the recordings go in its sounds folder).")
    src = Path(args.source)
    OUT.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory() as tmp:
        decoded = {}
        for name, (file, start, end, peak, kind, fade) in CUTS.items():
            if file not in decoded:
                decoded[file] = decode(src / file, tmp, SPEAKER.get(file, ""))
            audio = cut(decoded[file], start, end, peak, kind, fade)
            write_ogg(audio, OUT / f"{name}.ogg", tmp)
            period = f", repeat every {len(audio) / RATE - OVERLAP:.3f} s" if kind in ("loop", "cycle") else ""
            print(f"  {name}.ogg  {len(audio) / RATE:.2f} s  ({kind}{period})")


if __name__ == "__main__":
    main()
