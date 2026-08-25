"""Render the original Valmeran music for PTF_Sound.

Synthesizes every piece with a small additive-synthesis engine (no samples,
no external audio) and writes WAVs into the PTF_Sound raw cache, where
tools/generate-sounds.py applies the PA chain:

  anthem_valmera.wav      "Himno de la Republica" - anthem
  march_guardia.wav       "Marcha de la Guardia"  - military march
  son_valmera.wav         son cubano groove (clave, tumbao, montuno)
  merengue_bocachico.wav  merengue (guira, tambora, accordion runs)
  bolero_valmera.wav      slow bolero (guitar arpeggio, muted trumpet)
  bells_church.wav        church bells (generic)
  radio_jingle.wav        Radio Nacional fanfare (voice tag appended later)

The Caribbean pieces are rhythm-forward on purpose: percussion grooves,
syncopated bass, and short brass stabs synthesize far more convincingly
than long lyrical melodies, and through the loudspeaker chain they read as
real PA music. All original composition - no recording rights - so the
music belongs to Valmera alone. To use real (properly licensed) recordings
instead, drop them over these WAVs in the cache and regenerate.

Requires:  python -m pip install numpy
Usage:     python tools/compose-music.py   (generate-sounds.py runs it
                                            automatically when needed)
"""

import wave
from pathlib import Path

import numpy as np

SR = 44100
RAW_CACHE = Path(__file__).resolve().parent / ".sound_cache"
RNG = np.random.default_rng(1936)

NOTES = {"C": 0, "D": 2, "E": 4, "F": 5, "G": 7, "A": 9, "B": 11}


def freq(name):
    # "C4", "Bb3", "G#4" -> Hz
    letter, rest = name[0], name[1:]
    semi = NOTES[letter]
    if rest.startswith("b"):
        semi, rest = semi - 1, rest[1:]
    elif rest.startswith("#"):
        semi, rest = semi + 1, rest[1:]
    return 440.0 * 2 ** ((semi - 9) / 12 + int(rest) - 4)


BRASS = [(1, 1.0), (2, 0.6), (3, 0.75), (4, 0.5), (5, 0.4), (6, 0.3), (7, 0.2), (8, 0.15), (9, 0.1), (10, 0.08)]
HORNS = [(1, 1.0), (2, 0.35), (3, 0.2), (4, 0.1), (5, 0.06)]
MUTED = [(1, 1.0), (2, 0.25), (3, 0.35), (4, 0.12), (5, 0.08)]
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


def brass_note(f, dur, vib=0.35):
    # Detuned double gives the section a chorus instead of an organ.
    return tone(f, dur, BRASS, vib=vib) + 0.5 * tone(f * 1.006, dur, BRASS, vib=vib)


def pluck(f, dur, bright=1.0):
    # Percussive string/key hit (piano montuno, tres, accordion-ish runs).
    n = int(dur * SR)
    t = np.arange(n) / SR
    out = np.zeros(n)
    for h, amp in [(1, 1.0), (2, 0.6 * bright), (3, 0.4 * bright), (4, 0.25 * bright), (5, 0.15 * bright), (6, 0.1 * bright)]:
        fh = f * h
        if fh > SR * 0.45:
            break
        out += amp * np.sin(2 * np.pi * fh * t) * np.exp(-t * (3 + 2 * h))
    return out * np.exp(-t * 3.5) * np.minimum(t / 0.004, 1)


def drum(f, dur, drop=1.35, decay=16, noise=0.0):
    # Membrane hit with a pitch drop; noise adds slap.
    n = int(dur * SR)
    t = np.arange(n) / SR
    tau = 0.03
    phase = 2 * np.pi * f * (t + (drop - 1) * tau * (1 - np.exp(-t / tau)))
    out = np.sin(phase) * np.exp(-t * decay)
    if noise:
        out = out + noise * RNG.standard_normal(n) * np.exp(-t * 45)
    return out * np.minimum(t / 0.002, 1)


def tick(dur=0.04, decay=110, gain=1.0):
    # Guira/shaker tick: a burst of noise.
    n = int(dur * SR)
    t = np.arange(n) / SR
    return gain * RNG.standard_normal(n) * np.exp(-t * decay)


def clave_hit():
    n = int(0.07 * SR)
    t = np.arange(n) / SR
    return np.sin(2 * np.pi * 2400 * t) * np.exp(-t * 70)


def bell_strike(f, dur=3.5):
    # Inharmonic partials, long decay - a church bell.
    n = int(dur * SR)
    t = np.arange(n) / SR
    out = np.zeros(n)
    for p, amp, dk in [(1.0, 1.0, 1.1), (2.76, 0.55, 1.7), (5.40, 0.30, 2.6), (8.93, 0.18, 4.0)]:
        out += amp * np.sin(2 * np.pi * f * p * t) * np.exp(-t * dk)
    return out * np.minimum(t / 0.002, 1)


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


def melody_track(length, beat, notes, synth):
    track = np.zeros(int(length * SR))
    pos = 0.0
    for name, beats in notes:
        dur = beats * beat
        if name != "R":
            place(track, pos, synth(freq(name), dur * 0.98))
        pos += dur
    return track


def chord_tracks(length, beat, chords, beats_per_bar):
    pad = np.zeros(int(length * SR))
    bass = np.zeros(int(length * SR))
    for bar, (root, minor) in enumerate(chords):
        start = bar * beats_per_bar * beat
        semis = [0, 3 if minor else 4, 7]
        base = freq(root + "3")
        for s in semis:
            place(pad, start, tone(base * 2 ** (s / 12), beats_per_bar * beat * 0.98, HORNS, attack=0.1))
        for b in range(0, beats_per_bar, 2):
            place(bass, start + b * beat, tone(freq(root + "2"), beat * 1.6, TUBA, attack=0.02))
    return pad, bass


def chord_semis(minor):
    return [0, 3 if minor else 4, 7, 12]


# ---------------------------------------------------------------- pieces --

def anthem():
    beat = 60 / 84
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
    lead = melody_track(length, beat, melody, brass_note)
    octave = melody_track(length, beat, melody, lambda f, d: tone(f * 2, d, HORNS))
    pad, bass = chord_tracks(length, beat, chords, 4)
    perc = np.zeros(int(length * SR))
    # Timpani roll into the B section and under the final chord, cymbals on
    # both arrival points.
    for anchor in [7 * 4 * beat, (total_beats - 6) * beat]:
        for i in range(12):
            place(perc, anchor - 1.4 + i * 0.12, noise_hit(0.25, 0.05, body_f=65), gain=0.4 + 0.04 * i)
        place(perc, anchor, noise_hit(2.5, 0.7), gain=0.35)
    render(RAW_CACHE / "anthem_valmera.wav", length,
           [(lead, 1.0), (octave, 0.22), (pad, 0.4), (bass, 0.8), (perc, 0.8)])


def march():
    beat = 60 / 116
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
    lead = melody_track(length, beat, melody, lambda f, d: brass_note(f, d, vib=0.25))
    pad, _ = chord_tracks(length, beat, chords, 4)
    bass = np.zeros(int(length * SR))
    perc = np.zeros(int(length * SR))
    for bar, (root, _minor) in enumerate(chords):
        start = bar * 4 * beat
        for b in range(4):
            f = freq(root + "2") * (1.0 if b % 2 == 0 else 1.5)
            place(bass, start + b * beat, tone(f, beat * 0.9, TUBA, attack=0.015))
        # Paso-doble flavoured snare plus castanet-ish clave ticks.
        for b, gain in [(0, 1.0), (1, 0.4), (1.5, 0.3), (2, 0.8), (3, 0.4), (3.5, 0.3)]:
            place(perc, start + b * beat, noise_hit(0.1, 0.03, body_f=185), gain=0.5 * gain)
        for b in (0.5, 2.5):
            place(perc, start + b * beat, clave_hit(), gain=0.25)
        if bar % 8 == 7:
            for i in range(4):
                place(perc, start + (3 + i * 0.25) * beat, noise_hit(0.08, 0.025, body_f=185), gain=0.45)
        for b in (0, 2):
            place(perc, start + b * beat, noise_hit(0.15, 0.06, body_f=60), gain=0.9)
    render(RAW_CACHE / "march_guardia.wav", length,
           [(lead, 1.0), (pad, 0.35), (bass, 0.85), (perc, 1.0)])


def son():
    # Son cubano: 3-2 clave, conga tumbao, syncopated bass, montuno piano,
    # brass stabs. Am | Dm | E7 | Am.
    beat = 60 / 96
    bars = 28
    length = bars * 4 * beat + 2
    chords = [("A", 1), ("D", 1), ("E", 0), ("A", 1)] * (bars // 4)

    clave = np.zeros(int(length * SR))
    congas = np.zeros(int(length * SR))
    bass = np.zeros(int(length * SR))
    piano = np.zeros(int(length * SR))
    brass = np.zeros(int(length * SR))

    for bar in range(bars):
        start = bar * 4 * beat
        root, minor = chords[bar]
        # 3-2 son clave over a two-bar cycle.
        hits = [0, 1.5, 3] if bar % 2 == 0 else [1, 2]
        for b in hits:
            place(clave, start + b * beat, clave_hit(), gain=0.5)
        # Conga tumbao: palm, slap, two open tones.
        place(congas, start + 1.5 * beat, drum(180, 0.2, decay=24), gain=0.35)
        place(congas, start + 2 * beat, drum(240, 0.15, decay=30, noise=0.6), gain=0.55)
        place(congas, start + 3.5 * beat, drum(190, 0.3, drop=1.4, decay=13), gain=0.7)
        place(congas, start + 4 * beat - 0.5 * beat + 0.5 * beat, drum(175, 0.3, drop=1.4, decay=13), gain=0.0)
        place(congas, start + 3.0 * beat, drum(175, 0.3, drop=1.4, decay=13), gain=0.5)
        # Bass tumbao: fifth on the and-of-two, root on four (anticipating).
        fifth = freq(root + "2") * 1.5
        place(bass, start + 1.5 * beat, tone(fifth, beat * 0.9, TUBA, attack=0.01), gain=0.9)
        place(bass, start + 3 * beat, tone(freq(root + "2"), beat * 1.2, TUBA, attack=0.01), gain=1.0)
        if bar >= 4:
            # Montuno: syncopated eighth-note vamp in octaves.
            base = freq(root + "3")
            semis = chord_semis(minor)
            pattern = [0, 2, 1, 2, 3, 2, 1, 2]
            for i, s in enumerate(pattern):
                f = base * 2 ** (semis[s] / 12)
                g = 0.5 if i % 2 == 0 else 0.35
                place(piano, start + i * 0.5 * beat, pluck(f, 0.4), gain=g)
                place(piano, start + i * 0.5 * beat, pluck(f * 2, 0.4), gain=g * 0.6)
        if bar >= 12 and bar % 4 == 0 and bar < bars - 2:
            # Brass stab riff at the top of each cycle.
            for b, note, dur in [(0, "A4", 0.5), (0.5, "C5", 0.5), (1, "E5", 1.2)]:
                place(brass, start + b * beat, brass_note(freq(note), dur * beat, vib=0.2), gain=0.8)

    render(RAW_CACHE / "son_valmera.wav", length,
           [(clave, 0.9), (congas, 1.0), (bass, 0.95), (piano, 0.8), (brass, 0.7)])


def merengue():
    # Merengue: driving guira sixteenths, tambora, four-on-the-floor bass,
    # accordion-style runs, catchy horn riff. C | F | G | C.
    beat = 60 / 138
    bars = 32
    length = bars * 4 * beat + 1.5
    chords = [("C", 0), ("F", 0), ("G", 0), ("C", 0)] * (bars // 4)

    guira = np.zeros(int(length * SR))
    tambora = np.zeros(int(length * SR))
    bass = np.zeros(int(length * SR))
    keys = np.zeros(int(length * SR))
    horns = np.zeros(int(length * SR))

    scale = ["C4", "D4", "E4", "F4", "G4", "A4", "B4", "C5"]
    run = [0, 2, 4, 7, 4, 2, 4, 7, 0, 2, 4, 7, 4, 2, 4, 2]

    for bar in range(bars):
        start = bar * 4 * beat
        root, minor = chords[bar]
        for i in range(16):
            accent = 1.0 if i % 4 == 0 else 0.45
            place(guira, start + i * 0.25 * beat, tick(gain=accent), gain=0.3)
        place(guira, start + 3.5 * beat, tick(dur=0.12, decay=25), gain=0.35)  # scrape
        for b in (0, 2):
            place(tambora, start + b * beat, drum(85, 0.3, drop=1.5, decay=12), gain=1.0)
        for b in (1.5, 3):
            place(tambora, start + b * beat, drum(330, 0.1, decay=35, noise=0.7), gain=0.5)
        if bar % 4 == 3:
            for i in range(4):
                place(tambora, start + (3 + i * 0.25) * beat, drum(330, 0.08, decay=40, noise=0.7), gain=0.45)
        for b in range(4):
            f = freq(root + "2") * (1.0 if b % 2 == 0 else 1.5)
            place(bass, start + b * beat, tone(f, beat * 0.8, TUBA, attack=0.01), gain=1.0)
        if bar >= 4:
            # Accordion-ish sixteenth runs - the merengue signature.
            base = freq(root + "4") / freq("C4")
            for i, s in enumerate(run):
                place(keys, start + i * 0.25 * beat, pluck(freq(scale[s % 8]) * base, 0.22, bright=1.4), gain=0.4)
        if bar >= 16:
            riff = [
                (0, "E5", 0.5), (0.5, "D5", 0.5), (1, "C5", 0.5), (1.5, "D5", 0.5), (2, "E5", 1.0), (3, "G4", 1.0),
            ] if bar % 2 == 0 else [
                (0, "F5", 0.5), (0.5, "E5", 0.5), (1, "D5", 1.0), (2, "C5", 2.0),
            ]
            for b, note, dur in riff:
                place(horns, start + b * beat, brass_note(freq(note), dur * beat * 0.9, vib=0.2), gain=0.55)

    render(RAW_CACHE / "merengue_bocachico.wav", length,
           [(guira, 1.0), (tambora, 1.0), (bass, 0.95), (keys, 0.85), (horns, 0.8)])


def bolero():
    # Slow bolero: nylon-guitar arpeggio, light bongo, muted trumpet.
    # Am | Dm | E7 | Am.
    beat = 60 / 66
    bars = 16
    length = bars * 4 * beat + 2.5
    chords = [("A", 1), ("D", 1), ("E", 0), ("A", 1)] * (bars // 4)

    guitar = np.zeros(int(length * SR))
    bongo = np.zeros(int(length * SR))
    bass = np.zeros(int(length * SR))

    for bar in range(bars):
        start = bar * 4 * beat
        root, minor = chords[bar]
        semis = chord_semis(minor)
        arp = [0, 2, 3, 2, 1, 2, 3, 2]
        base = freq(root + "3")
        for i, s in enumerate(arp):
            place(guitar, start + i * 0.5 * beat, pluck(base * 2 ** (semis[s] / 12), 0.7, bright=0.5), gain=0.5)
        place(bass, start, tone(freq(root + "2"), beat * 1.8, TUBA, attack=0.02), gain=0.7)
        place(bass, start + 2.5 * beat, tone(freq(root + "2") * 1.5, beat * 0.9, TUBA, attack=0.02), gain=0.45)
        for b, g in [(1.5, 0.3), (2, 0.2), (3.5, 0.35)]:
            place(bongo, start + b * beat, drum(420, 0.1, decay=35), gain=g)

    melody = [
        ("E4", 1), ("A4", 2), ("B4", 1),
        ("C5", 2), ("A4", 2),
        ("B4", 1.5), ("A4", 0.5), ("G#4", 2),
        ("A4", 4),
        ("C5", 1), ("B4", 1), ("A4", 2),
        ("F4", 2), ("A4", 2),
        ("E4", 1.5), ("F4", 0.5), ("G#4", 2),
        ("A4", 4),
    ] * 2
    trumpet = melody_track(length, beat, melody, lambda f, d: tone(f, d, MUTED, vib=0.55, attack=0.06))

    render(RAW_CACHE / "bolero_valmera.wav", length,
           [(guitar, 0.9), (bongo, 0.8), (bass, 0.85), (trumpet, 0.75)])


def bells():
    length = 22.0
    track = np.zeros(int(length * SR))
    strikes = [(0, "E4"), (2.8, "C4"), (5.6, "E4"), (8.4, "C4"), (11.2, "E4"), (14.0, "C4"), (16.8, "C4")]
    for at, note in strikes:
        place(track, at, bell_strike(freq(note)), gain=1.0)
    render(RAW_CACHE / "bells_church.wav", length, [(track, 1.0)])


def jingle():
    beat = 60 / 100
    melody = [
        ("C4", 0.5), ("E4", 0.5), ("G4", 0.5), ("C5", 1.5),
        ("G4", 0.5), ("C5", 2.5),
    ]
    total_beats = sum(b for _, b in melody)
    length = total_beats * beat + 1.5
    lead = melody_track(length, beat, melody, lambda f, d: brass_note(f, d, vib=0.4))
    third = melody_track(length, beat, [("E4", 0.5), ("G4", 0.5), ("C5", 0.5), ("E5", 1.5), ("C5", 0.5), ("E5", 2.5)],
                         lambda f, d: tone(f, d, HORNS))
    perc = np.zeros(int(length * SR))
    place(perc, 0, noise_hit(0.2, 0.07, body_f=60), gain=0.9)
    place(perc, (total_beats - 2.5) * beat, noise_hit(2.0, 0.6), gain=0.4)
    place(perc, (total_beats - 2.5) * beat, noise_hit(0.3, 0.1, body_f=60), gain=0.9)
    render(RAW_CACHE / "radio_jingle.wav", length, [(lead, 1.0), (third, 0.4), (perc, 0.8)])


RAW_CACHE.mkdir(parents=True, exist_ok=True)
anthem()
march()
son()
merengue()
bolero()
bells()
jingle()
