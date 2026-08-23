"""Generate PTF_Sound audio and configs from tools/sound_lines.json.

Renders every voice line with Microsoft neural TTS (edge-tts), synthesizes the
siren/tone entries with ffmpeg, runs everything through a loudspeaker effect
chain, and writes into addons/PTF_Sound:

  sounds/<category>/<name>.ogg   the audio, foldered generic vs campaign
  cfgSounds.hpp                  CfgSounds classes (Eden trigger effects, say3D)
  cfgModules.hpp                 one Zeus/Eden loudspeaker module per sound
  cfgPatchesUnits.hpp            CfgPatches units[] - needed for Zeus visibility

Requires:  python -m pip install edge-tts imageio-ffmpeg
Usage:     python tools/generate-sounds.py

Voice audio is Microsoft neural TTS fetched via the unofficial edge-tts
endpoint. Fine for prototyping; before a Workshop release either regenerate
through the Azure Speech API (same voices, redistribution-clean license) or
replace individual lines with member VA recordings dropped into the raw cache
directory as <name>.mp3 - the effect chain applies either way.
"""

import asyncio
import json
import re
import subprocess
import sys
import tempfile
from pathlib import Path

import edge_tts
import imageio_ffmpeg

REPO = Path(__file__).resolve().parent.parent
ADDON = REPO / "addons" / "PTF_Sound"
SOUNDS = ADDON / "sounds"
RAW_CACHE = Path(tempfile.gettempdir()) / "ptf_sound_raw"
FFMPEG = imageio_ffmpeg.get_ffmpeg_exe()
PBO_PREFIX = "z\\PTF\\addons\\PTF_Sound\\sounds"

# Arma will not play sample rates above 48 kHz - it fails silently. ffmpeg's
# loudnorm (first link in SPEAKER_FILTER/MUSIC_FILTER) resamples to 192 kHz,
# so the output rate is pinned explicitly on every encode.
SAMPLE_RATE = 44100

# Horn-speaker simulation: steep bandpass into the horn's telephone-band
# range, a honky mid resonance, hard clipping for the overdriven PA crunch
# (then a low-pass to tame the clip harmonics), and a double outdoor
# slapback off distant buildings. Mono.
SPEAKER_FILTER = (
    "loudnorm=I=-16:TP=-1.5,"
    "highpass=f=500,highpass=f=500,"
    "lowpass=f=2700,lowpass=f=2700,"
    "equalizer=f=1100:t=q:w=1.5:g=7,"
    "aeval='min(max(val(0)*4,-0.75),0.75)',"
    "lowpass=f=3000,"
    "aecho=0.8:0.45:110|230:0.3|0.14,"
    "volume=-2dB,"
    "pan=mono|c0=c0"
)
# Music keeps a wider band and a lighter clip than speech so the bass line
# and percussion survive, but still reads as an overdriven PA.
MUSIC_FILTER = (
    "loudnorm=I=-16:TP=-1.5,"
    "highpass=f=250,lowpass=f=4200,"
    "equalizer=f=1000:t=q:w=1.5:g=4,"
    "aeval='min(max(val(0)*2.5,-0.8),0.8)',"
    "lowpass=f=4500,"
    "aecho=0.8:0.45:110|230:0.25|0.12,"
    "volume=-2dB,"
    "pan=mono|c0=c0"
)
SIREN_FILTER = (
    "highpass=f=300,lowpass=f=4000,"
    "volume=-3dB,"
    "aecho=0.6:0.35:70:0.2,"
    "afade=t=in:d=0.5,areverse,afade=t=in:d=0.5,areverse,"
    "pan=mono|c0=c0"
)

# aevalsrc expressions; the air raid phase term is the integral of a
# 500 +/- 300 Hz sweep at 0.12 Hz.
SYNTH_EXPR = {
    "airraid": "0.8*sin(2*PI*500*t - 2500*cos(2*PI*0.12*t))",
    "twotone": "0.8*sin(2*PI*(600 + 200*gt(mod(t,1),0.5))*t)",
    "chime": "exp(-2.5*mod(t,2))*sin(2*PI*if(lt(mod(t,2),1),660,528)*t)",
}


def run_ffmpeg(args):
    proc = subprocess.run([FFMPEG, "-y", *args], capture_output=True, text=True)
    if proc.returncode != 0:
        sys.exit(f"ffmpeg failed:\n{proc.stderr[-2000:]}")
    return proc


def ogg_duration(path):
    proc = subprocess.run([FFMPEG, "-i", str(path)], capture_output=True, text=True)
    m = re.search(r"Duration: (\d+):(\d+):(\d+\.\d+)", proc.stderr)
    if not m:
        sys.exit(f"could not read duration of {path}")
    return round(int(m[1]) * 3600 + int(m[2]) * 60 + float(m[3]), 1)


def sound_entry(item, defaults, duration):
    name, cat = item["name"], item["category"]
    vol = item.get("volume", defaults["volume"])
    pitch = item.get("pitch", defaults["pitch"])
    dist = item.get("distance", defaults["distance"])
    pause = item.get("pause", defaults["pause"])
    path = f"{PBO_PREFIX}\\{cat}\\{name}.ogg"
    sound = (
        f"class PTF_Sound_{name}\n"
        "{\n"
        f'\tname = "PTF PA - {item["display"]}";\n'
        f'\tsound[] = {{"\\{path}", {vol}, {pitch}, {dist}}};\n'
        "\ttitles[] = {};\n"
        "};\n"
    )
    module = (
        f"class PTF_Sound_Module_{name}: PTF_Sound_Module_base\n"
        "{\n"
        "\tscope = 2;\n"
        "\tscopeCurator = 2;\n"
        f'\tdisplayName = "{item["display"]}";\n'
        f'\tcategory = "PTF_Sound_{cat}";\n'
        f'\tPTF_sound = "{path}";\n'
        f"\tPTF_volume = {vol};\n"
        f"\tPTF_distance = {dist};\n"
        f"\tPTF_duration = {duration};\n"
        f"\tPTF_pause = {pause};\n"
        "};\n"
    )
    return sound, module


async def main():
    data = json.loads((REPO / "tools" / "sound_lines.json").read_text(encoding="utf-8"))
    defaults = data["defaults"]
    RAW_CACHE.mkdir(parents=True, exist_ok=True)
    items = []

    for line in data["lines"]:
        raw = RAW_CACHE / f"{line['name']}.mp3"
        # A member VA recording dropped in the cache under the same name wins
        # over TTS; delete the file to fall back.
        if not raw.exists():
            await edge_tts.Communicate(
                line["text"], line["voice"], rate=line.get("rate", "+0%")
            ).save(str(raw))
        out = SOUNDS / line["category"] / f"{line['name']}.ogg"
        out.parent.mkdir(parents=True, exist_ok=True)
        run_ffmpeg(["-i", str(raw), "-af", SPEAKER_FILTER, "-c:a", "libvorbis", "-q:a", "4", "-ar", str(SAMPLE_RATE), str(out)])
        items.append((line, out))
        print(f"  {line['category']}/{out.name}  ({out.stat().st_size // 1024} KB)")

    music = data.get("music", [])
    if any(not (RAW_CACHE / f"{m['name']}.wav").exists() for m in music):
        print("Rendering music with tools/compose-music.py ...")
        subprocess.run([sys.executable, str(REPO / "tools" / "compose-music.py")], check=True)
    for piece in music:
        wav = RAW_CACHE / f"{piece['name']}.wav"
        out = SOUNDS / piece["category"] / f"{piece['name']}.ogg"
        out.parent.mkdir(parents=True, exist_ok=True)
        if "text" in piece:
            # Voice tag (e.g. a station ident) appended after the music.
            tag = RAW_CACHE / f"{piece['name']}_tag.mp3"
            if not tag.exists():
                await edge_tts.Communicate(
                    piece["text"], piece["voice"], rate=piece.get("rate", "+0%")
                ).save(str(tag))
            graph = (
                "[0:a]aformat=sample_rates=44100:channel_layouts=mono[a0];"
                "[1:a]aformat=sample_rates=44100:channel_layouts=mono[a1];"
                f"[a0][a1]concat=n=2:v=0:a=1,{MUSIC_FILTER}[out]"
            )
            run_ffmpeg(["-i", str(wav), "-i", str(tag), "-filter_complex", graph,
                        "-map", "[out]", "-c:a", "libvorbis", "-q:a", "4", "-ar", str(SAMPLE_RATE), str(out)])
        else:
            run_ffmpeg(["-i", str(wav), "-af", MUSIC_FILTER, "-c:a", "libvorbis", "-q:a", "4", "-ar", str(SAMPLE_RATE), str(out)])
        items.append((piece, out))
        print(f"  {piece['category']}/{out.name}  ({out.stat().st_size // 1024} KB)")

    for tone in data["synth"]:
        out = SOUNDS / tone["category"] / f"{tone['name']}.ogg"
        out.parent.mkdir(parents=True, exist_ok=True)
        src = f"aevalsrc='{SYNTH_EXPR[tone['type']]}':s=44100:d={tone['duration']}"
        run_ffmpeg(["-f", "lavfi", "-i", src, "-af", SIREN_FILTER, "-c:a", "libvorbis", "-q:a", "4", "-ar", str(SAMPLE_RATE), str(out)])
        items.append((tone, out))
        print(f"  {tone['category']}/{out.name}  ({out.stat().st_size // 1024} KB)")

    expected = {out for _, out in items}
    for stale in SOUNDS.rglob("*.ogg"):
        if stale not in expected:
            stale.unlink()
            print(f"  removed stale {stale.relative_to(SOUNDS)}")

    header = "// Generated by tools/generate-sounds.py from tools/sound_lines.json - do not hand-edit.\n"
    sounds_hpp, modules_hpp = header, header
    for item, out in items:
        sound, module = sound_entry(item, defaults, ogg_duration(out))
        sounds_hpp += sound
        modules_hpp += module
    (ADDON / "cfgSounds.hpp").write_text(sounds_hpp, encoding="utf-8", newline="\n")
    (ADDON / "cfgModules.hpp").write_text(modules_hpp, encoding="utf-8", newline="\n")

    # Zeus builds its asset list from CfgPatches units[], not from CfgVehicles:
    # a module missing here has working classes but never shows up in the Zeus
    # Modules tab. Generated alongside cfgModules.hpp so the two cannot drift.
    units = "".join(f'\t\t"PTF_Sound_Module_{i["name"]}",\n' for i, _ in items)
    (ADDON / "cfgPatchesUnits.hpp").write_text(
        header + "units[] =\n\t{\n" + units.rstrip(",\n") + "\n\t};\n",
        encoding="utf-8", newline="\n")

    categories = sorted({i["category"] for i, _ in items})
    print(f"Wrote {len(items)} sounds ({', '.join(categories)}), cfgSounds.hpp, cfgModules.hpp, cfgPatchesUnits.hpp")
    print("Module categories referenced: "
          + ", ".join(f"PTF_Sound_{c}" for c in categories)
          + " - each needs a CfgFactionClasses entry in config.cpp.")


asyncio.run(main())
