"""Render the original Valmeran propaganda music for PTF_Sound.

Synthesizes three pieces with a small additive-synthesis brass band (no
samples, no external audio) and writes them as WAVs into the PTF_Sound raw
cache, where tools/generate-sounds.py picks them up and applies the
loudspeaker chain:

  anthem_valmera.wav   "Himno de la Republica" - stately anthem, ~50 s
  march_guardia.wav    "Marcha de la Guardia"  - military march, ~50 s
  radio_jingle.wav     Radio Nacional fanfare  - ~8 s (voice tag appended
                       by generate-sounds.py)

The music is original composition - through the horn-speaker effect chain the
synth brass reads as an overdriven PA band, and being original it carries no
recording rights and belongs to Valmera alone. To use real (properly
licensed) recordings instead, drop them over these WAVs in the cache and
regenerate.

Requires:  python -m pip install numpy
Usage:     python tools/compose-music.py   (generate-sounds.py runs it
                                            automatically when needed)
"""

import tempfile
import wave
from pathlib import Path

import numpy as np

SR = 44100
RAW_CACHE = Path(tempfile.gettempdir()) / "ptf_sound_raw"
RNG = np.random.default_rng(1936)

NOTES = {"C": 0, "D": 2, "E": 4, "F": 5, "G": 7, "A": 9, "B": 11}


def freq(name):
    # "C4", "Bb3", "F#4" -> Hz
    letter, rest = name[0], name[1:]
    semi = NOTES[letter]
    if rest.startswith("b"):
        semi, rest = semi - 1, rest[1:]
    elif rest.startswith("#"):
        semi, rest = semi + 1, rest[1:]
    return 440.0 * 2 ** ((semi - 9) / 12 + int(rest) - 4)


BRASS = [(1, 1.0), (2, 0.6), (3, 0.75), (4, 0.5), (5, 0.4), (6, 0.3), (7, 0.2), (8, 0.15), (9, 0.1), (10, 0.08)]
HORNS = [(1, 1.0), (2, 0.35), (3, 0.2), (4, 0.1), (5, 0.06)]
TUBA = [(1, 1.0), (2, 0.5), (3, 0.2)]


def tone(f, dur, harmonics, vib=0.0, attack=0.03, release=0.08):
    n = int(dur * SR)
    t = np.arange(n) / SR
    out = np.zeros(n)
    for h, amp in harmonics:
        fh = f * h
        if fh > SR * 0.45:
            break
        phase = 2 * np.pi * fh * t
        if vib:
            phase = phase + vib * np.sin(2 * np.pi * 5.5 * t) * np.minimum(t / 0.25, 1)
        out += amp * np.sin(phase)
    env = np.interp(t, [0, attack, max(dur - release, attack), dur], [0, 1, 0.85, 0])
    return out * env


def noise_hit(dur, decay, body_f=0.0):
    n = int(dur * SR)
    t = np.arange(n) / SR
    out = RNG.standard_normal(n) * np.exp(-t / decay)
    if body_f:
        out = 0.6 * out + 0.8 * np.sin(2 * np.pi * body_f * t) * np.exp(-t / (decay * 1.5))
    return out


def place(track, start, samples, gain=1.0):
    i = int(start * SR)
    end = min(i + len(samples), len(track))
    track[i:end] += samples[: end - i] * gain


def render(path, length, parts):
    mix = np.zeros(int(length * SR))
    for track, gain in parts:
        mix += track * gain
    mix *= 0.9 / max(np.max(np.abs(mix)), 1e-9)
    data = (mix * 32767).astype(np.int16)
    with wave.open(str(path), "wb") as w:
        w.setnchannels(1)
        w.setsampwidth(2)
        w.setframerate(SR)
        w.writeframes(data.tobytes())
    print(f"  {path.name}  ({len(data) / SR:.1f} s)")


def melody_track(length, beat, notes, harmonics, vib=0.0, octave=0):
    track = np.zeros(int(length * SR))
    pos = 0.0
    for name, beats in notes:
        dur = beats * beat
        if name != "R":
            f = freq(name) * 2 ** octave
            place(track, pos, tone(f, dur * 0.98, harmonics, vib=vib))
        pos += dur
    return track


def chord_tracks(length, beat, chords, beats_per_bar):
    # chords: list of (root, quality) per bar; pad sustains, tuba plays roots
    pad = np.zeros(int(length * SR))
    bass = np.zeros(int(length * SR))
    for bar, (root, minor) in enumerate(chords):
        start = bar * beats_per_bar * beat
        third = 3 if minor else 4
        semis = [0, third, 7]
        base = freq(root + "3")
        for s in semis:
            place(pad, start, tone(base * 2 ** (s / 12), beats_per_bar * beat * 0.98, HORNS, attack=0.1))
        for b in range(0, beats_per_bar, 2):
            place(bass, start + b * beat, tone(freq(root + "2"), beat * 1.6, TUBA, attack=0.02))
    return pad, bass


def anthem():
    beat = 60 / 84
    bpb = 4
    melody = [
        ("C4", 1), ("E4", 1), ("G4", 2),
        ("C5", 2), ("G4", 2),
        ("A4", 1.5), ("F4", 0.5), ("A4", 2),
        ("G4", 4),
        ("F4", 1), ("A4", 1), ("G4", 1), ("F4", 1),
        ("E4", 2), ("G4", 2),
        ("D4", 1), ("E4", 1), ("F4", 1), ("D4", 1),
        ("C4", 4),
        ("E4", 1), ("G4", 1), ("C5", 2),
        ("B4", 1), ("A4", 1), ("G4", 2),
        ("A4", 1), ("B4", 1), ("C5", 1), ("D5", 1),
        ("G4", 4),
        ("C5", 2), ("B4", 1), ("A4", 1),
        ("A4", 2), ("F4", 2),
        ("F4", 1.5), ("E4", 0.5), ("D4", 1), ("D4", 1),
        ("C4", 6),
    ]
    chords = [("C", 0), ("C", 0), ("F", 0), ("C", 0), ("F", 0), ("C", 0), ("G", 0), ("C", 0),
              ("C", 0), ("G", 0), ("F", 0), ("G", 0), ("A", 1), ("F", 0), ("G", 0), ("C", 0)]
    total_beats = sum(b for _, b in melody)
    length = total_beats * beat + 2
    lead = melody_track(length, beat, melody, BRASS, vib=0.35)
    octave = melody_track(length, beat, melody, HORNS, octave=1)
    pad, bass = chord_tracks(length, beat, chords, bpb)
    perc = np.zeros(int(length * SR))
    # timpani roll under the final chord, cymbal on the downbeat of it
    final = (total_beats - 6) * beat
    for i in range(12):
        place(perc, final + i * 0.12, noise_hit(0.25, 0.05, body_f=65), gain=0.5 + 0.04 * i)
    place(perc, final, noise_hit(2.5, 0.7), gain=0.35)
    render(RAW_CACHE / "anthem_valmera.wav", length,
           [(lead, 1.0), (octave, 0.25), (pad, 0.4), (bass, 0.8), (perc, 0.8)])


def march():
    beat = 60 / 116
    bpb = 4
    phrase_a = [
        ("C4", 0.75), ("C4", 0.25), ("C4", 1), ("E4", 1), ("G4", 1),
        ("C5", 2), ("G4", 2),
        ("A4", 0.75), ("A4", 0.25), ("A4", 1), ("C5", 1), ("A4", 1),
        ("G4", 3), ("E4", 1),
        ("F4", 0.75), ("F4", 0.25), ("F4", 1), ("A4", 1), ("F4", 1),
        ("E4", 0.75), ("E4", 0.25), ("E4", 1), ("G4", 1), ("E4", 1),
        ("D4", 1), ("G4", 1), ("F4", 0.5), ("E4", 0.5), ("D4", 1),
        ("C4", 2), ("G4", 2),
    ]
    phrase_b = [
        ("E4", 1), ("E4", 1), ("E4", 1.5), ("F4", 0.5),
        ("G4", 2), ("E4", 2),
        ("F4", 1), ("F4", 1), ("F4", 1.5), ("G4", 0.5),
        ("A4", 2), ("F4", 2),
        ("G4", 0.75), ("G4", 0.25), ("A4", 1), ("B4", 1), ("C5", 1),
        ("D5", 2), ("B4", 2),
        ("C5", 1), ("G4", 1), ("E4", 1), ("D4", 1),
        ("C4", 4),
    ]
    melody = phrase_a + phrase_a + phrase_b
    chords_a = [("C", 0), ("C", 0), ("F", 0), ("C", 0), ("F", 0), ("C", 0), ("G", 0), ("C", 0)]
    chords_b = [("C", 0), ("C", 0), ("F", 0), ("F", 0), ("C", 0), ("G", 0), ("C", 0), ("C", 0)]
    chords = chords_a + chords_a + chords_b
    total_beats = sum(b for _, b in melody)
    length = total_beats * beat + 1.5
    lead = melody_track(length, beat, melody, BRASS, vib=0.25)
    pad, _ = chord_tracks(length, beat, chords, bpb)
    # oom-pah bass: root on 1 and 3, fifth on 2 and 4
    bass = np.zeros(int(length * SR))
    for bar, (root, _minor) in enumerate(chords):
        start = bar * bpb * beat
        for b in range(bpb):
            f = freq(root + "2") * (1.0 if b % 2 == 0 else 1.5)
            place(bass, start + b * beat, tone(f, beat * 0.9, TUBA, attack=0.015))
    perc = np.zeros(int(length * SR))
    n_bars = len(chords)
    for bar in range(n_bars):
        start = bar * bpb * beat
        for b, gain in [(0, 1.0), (1, 0.4), (1.5, 0.3), (2, 0.8), (3, 0.4), (3.5, 0.3)]:
            place(perc, start + b * beat, noise_hit(0.1, 0.03, body_f=185), gain=0.5 * gain)
        if bar % 8 == 7:  # snare fill into the next phrase
            for i in range(4):
                place(perc, start + (3 + i * 0.25) * beat, noise_hit(0.08, 0.025, body_f=185), gain=0.45)
        for b in (0, 2):
            place(perc, start + b * beat, noise_hit(0.15, 0.06, body_f=60), gain=0.9)
    render(RAW_CACHE / "march_guardia.wav", length,
           [(lead, 1.0), (pad, 0.35), (bass, 0.85), (perc, 1.0)])


def jingle():
    beat = 60 / 100
    melody = [
        ("C4", 0.5), ("E4", 0.5), ("G4", 0.5), ("C5", 1.5),
        ("G4", 0.5), ("C5", 2.5),
    ]
    total_beats = sum(b for _, b in melody)
    length = total_beats * beat + 1.5
    lead = melody_track(length, beat, melody, BRASS, vib=0.4)
    third = melody_track(length, beat, [("E4", 0.5), ("G4", 0.5), ("C5", 0.5), ("E5", 1.5), ("C5", 0.5), ("E5", 2.5)], HORNS)
    perc = np.zeros(int(length * SR))
    place(perc, 0, noise_hit(0.2, 0.07, body_f=60), gain=0.9)
    place(perc, (total_beats - 2.5) * beat, noise_hit(2.0, 0.6), gain=0.4)
    place(perc, (total_beats - 2.5) * beat, noise_hit(0.3, 0.1, body_f=60), gain=0.9)
    render(RAW_CACHE / "radio_jingle.wav", length, [(lead, 1.0), (third, 0.4), (perc, 0.8)])


RAW_CACHE.mkdir(parents=True, exist_ok=True)
anthem()
march()
jingle()
