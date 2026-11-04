#!/usr/bin/env python3
"""Generate the PTF_Dress USMC Service "A" textures, materials and rank config.

Starts from Bohemia's Art of War parade uniform sheets in the local Arma 3 install
but keeps little of them: the fabric is rebuilt at 4096 with the baked folds
filtered out of both colour and normal map, keeping only seams and pocket edges,
and the belt, buckle and insignia are drawn from scratch to MCO 1020.34H.

Sheet positions were read off the model using a labelled grid
(tools/dress-review/probe_sheets.py). Check changes in game with
tools/review-dress-uniforms.py.

Usage:  python tools/generate-dress-uniforms.py [--ranks Sgt Capt]
Needs:  Pillow + numpy, Arma 3 (Art of War data), Arma 3 Tools (ImageToPAA).
"""
import argparse
import json
import struct
import subprocess
import sys
import tempfile
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFilter, ImageFont

REPO = Path(__file__).resolve().parent.parent
ADDON = REPO / "addons" / "PTF_Dress"
DATA = ADDON / "data"
PREFIX = r"z\PTF\addons\PTF_Dress"
STEAM = Path(r"C:\Program Files (x86)\Steam\steamapps\common")
# Insignia artwork cut from MCO 1020.34H by tools/dress-assets/extract.py.
ASSETS = REPO / "tools" / "dress-assets"
RIBBON_ART = ASSETS / "ribbons"

# Rank sheets are drawn at twice the final size and reduced, so small insignia come
# out crisp. ImageToPAA writes 4096 at most and silently shrinks anything larger, with
# a softer filter than this, so they are reduced here. The cloth is built at BASE.
SHEET = 8192
PAA_MAX = 4096
K = SHEET // 2048  # layout constants below are in vanilla 2048-space pixels
PX_PER_IN = 23.7 * K  # sleeve scale: seam to cuff is ~565 px at 2048 for ~24 in
BASE = 4096
BASE_K = BASE // 2048
BASE_PX_PER_IN = 23.7 * BASE_K
SS = 4  # insignia supersampling

# Texture brightness to on-screen brightness, measured in game in daylight on a
# real map: 71 in the texture rendered as 195, so about 2.75x. Exposure swings a
# lot by map and time of day, so judge colour only in daylight on real terrain.
GAIN_COAT = 2.75
# Direct sun washes cloth out at full strength, far more than the shaded side, so
# the cloth materials respond less to it. Lower means flatter light and shade.
CLOTH_DIFFUSE = 0.6


def daylight(*rgb, gain=GAIN_COAT):
    """Texture value that renders as this colour in daylight."""
    return np.array(rgb, float) / gain


# Darkened from the shade first picked by eye (80, 78, 58): the coats in the order's
# photographs measure 60 to 75, against 100 to 130 in game.
GREEN = daylight(60, 58.5, 43.5)
KHAKI = daylight(190, 165, 135)
# Metal and saturated cloth did not follow the fabric's gain, so these were set
# from what earlier builds rendered as rather than from the formula.
BRASS = (78, 66, 38)
SCARLET = (48, 10, 12)
INSIGNIA_GREEN = (18, 19, 12)
SILVER = (50, 51, 52)
GOLD = (88, 72, 36)
PIN_BLACK = (9, 9, 9)
# Navy grade insignia on the Marine service coat is blue on green (para 8000). Very
# low and barely saturated, since the game brightens saturated colours a long way.
NAVY_BLUE = (5, 7, 18)

# Grey level of the vanilla pieces each target colour is anchored to.
GREEN_REF = 43.0
SHIRT_REF = 126.0
TIE_REF = 62.0

# Sleeves. `cx` is the outer centreline of the arm seen side-on, read from the
# grid; the island's top edge is the shoulder seam. The rear of the sleeve is on
# opposite sides on the two islands.
SLEEVES = [
    {"cx": 1925, "seam_y": 30, "cuff_y": 605, "rear": +1, "buttons": (1990, 520, 2030, 590)},
    {"cx": 1675, "seam_y": 650, "cuff_y": 1222, "rear": -1, "buttons": (1595, 1130, 1635, 1205)},
]
# The peaked cuff seam's height above the hem, and how fast it falls away from the
# peak, read from the order's Service "A" photographs.
CUFF_PEAK_IN = 3.8
CUFF_SLOPE = 0.32
# About half the visible arm, which is ~210 px wide at 2048.
CHEVRON_W = 108 * K
# Navy rate is worn on this sleeve only, midway between shoulder seam and elbow.
LEFT_SLEEVE = SLEEVES[0]
RATE_W = int(CHEVRON_W * 0.85)
RATE_CENTRE_IN = 6.5
SHOULDER_STRAP = {"x1": 1807, "cy": 1669}
# Centres of the collar leaves, and the sheet's rotation there as seen on the model.
# Centred on the collar leaf between the gorge seam and the fold, as the order says
# ("centered on the collar"), measured with tools/dress-review/probe_fine.py. The
# rotation keeps the wing tips parallel to the bottom of the coat.
COAT_COLLAR = [(684, 68, 60), (343, 74, -60)]
SHIRT_COLLAR = [(1634, 63, 35), (1180, 69, -35)]
TROUSERS = (0, 1040, 1225, 2048)
# The front centre of each leg, read off the model.
TROUSER_CREASES = [512, 768]
# The tie stops at its tip. The same column below that is trouser hem.
TIE = [(1225, 1590, 1320, 1880), (1280, 1530, 1412, 1616)]
# Shoes, soles and laces. Kept clear of the sleeve and pocket pieces next to them.
SHOE_ZONES = [(1205, 1040, 1590, 1550), (1590, 1245, 1645, 1550), (1205, 1550, 1645, 2048), (1645, 1490, 1760, 1640)]
# Where shirt pieces live. Coat fold highlights are also bright and near-neutral,
# so colour alone would paint khaki streaks across the coat.
# The strip at 1445-1592, 640-1078 is the shirt sleeve poking out past the coat cuff,
# which the photographs never show, so it is left as coat cloth.
SHIRT_ZONES = [(1150, 0, 1680, 112), (1262, 1335, 1445, 1545),
               (1650, 1240, 2048, 1715)]
ARMHOLE = (1915, 680, 62)
# Parts of the sheet the model never shows, standing or saluting, checked in game by
# painting them in strong colours and searching every review camera for those colours.
WATERMARK_BLOCK = (1000, 1000, 1200, 1040)
WATERMARK_STRIP = (1210, 1320, 1224, 1590)
WATERMARK = ("PTF CORE - PARAMARINE TASK FORCE", "paramarines.com - APL-ND - DO NOT REUSE")
# The shoulder strap sits inside the last shirt zone, and its pale seam specks would
# otherwise turn khaki.
STRAP_ZONE = (1645, 1630, 1815, 1740)

# Belt and buckle sheet, in vanilla 1024x512 pixels. The belt wraps the waist along
# x. Both halves meet the plate and share x 704-768 mirrored, so anything drawn on
# only one side has to go on the plate itself.
# It is heavily squeezed in x: about 25 px per inch, against 85 px per inch in y.
DECOR_K = 2
BELT_Y = (0, 196)
PLATE = (0, 208, 324, 446)
COAT_BUTTON = (927, 300, 90, 88)
# The smaller black disc on the sheet.
SMALL_BUTTON = (782, 415, 90, 90)

# Cap sheet, in vanilla 1024x1024 pixels, read off the model.
CAP_CROWN = (256, 265, 248)  # centre and radius of the crown's top
# The crown's front-to-back axis is this far from the sheet's vertical, in degrees.
CAP_CROWN_ROTATION = -12
CAP_VISOR = (505, 340, 890, 535)

def _enlisted(name, chevrons=0, rifles=True, rockers=0, stripes=0):
    return {"name": name, "chevrons": chevrons, "rifles": rifles, "rockers": rockers, "stripes": stripes}


def _navy(name, kind, count, rocker=False, striker=False, stripes=0):
    return {"name": name, "navy": (kind, count, rocker, striker), "stripes": stripes}


# A rack drawn as a UI texture on a plate renders brighter than a PAA of the same value.
RACK_UI_LEVEL = 0.74


def _officer(name, kind, colour, count=1):
    return {"name": name, "metal": (kind, colour, count)}


# The ranks PTF actually uses. Service stripe counts are typical time in grade at
# one stripe per four years, not a rule from the order.
RANKS = {
    "Pvt": _enlisted("Private (E-1)"),
    "PFC": _enlisted("Private First Class (E-2)", 1, rifles=False),
    "LCpl": _enlisted("Lance Corporal (E-3)", 1),
    "Cpl": _enlisted("Corporal (E-4)", 2),
    "Sgt": _enlisted("Sergeant (E-5)", 3, stripes=1),
    "SSgt": _enlisted("Staff Sergeant (E-6)", 3, rockers=1, stripes=2),
    "GySgt": _enlisted("Gunnery Sergeant (E-7)", 3, rockers=2, stripes=3),
    # NAVPERS 15665: paygrade E-1 wears no group rate mark.
    "HR": _navy("Hospitalman Recruit (HR)", "group", 0),
    "HA": _navy("Hospitalman Apprentice (HA)", "group", 2, striker=True),
    "HN": _navy("Hospitalman (HN)", "group", 3, striker=True),
    "HM3": _navy("Hospital Corpsman 3rd Class (HM3)", "crow", 1),
    "HM2": _navy("Hospital Corpsman 2nd Class (HM2)", "crow", 2, stripes=1),
    "HM1": _navy("Hospital Corpsman 1st Class (HM1)", "crow", 3, stripes=2),
    "HMC": _navy("Chief Hospital Corpsman (HMC)", "crow", 3, rocker=True, stripes=3),
    "WO1": _officer("Warrant Officer (W-1)", "warrant", GOLD, "two"),
    "CWO2": _officer("Chief Warrant Officer 2 (W-2)", "warrant", GOLD, "three"),
    "CWO3": _officer("Chief Warrant Officer 3 (W-3)", "warrant", SILVER, "two"),
    "CWO4": _officer("Chief Warrant Officer 4 (W-4)", "warrant", SILVER, "three"),
    "CWO5": _officer("Chief Warrant Officer 5 (W-5)", "warrant", SILVER, "stripe"),
    "2ndLt": _officer("Second Lieutenant (O-1)", "bars", GOLD),
    "1stLt": _officer("First Lieutenant (O-2)", "bars", SILVER),
    "Capt": _officer("Captain (O-3)", "bars", SILVER, 2),
    "Maj": _officer("Major (O-4)", "oak", GOLD),
    "LtCol": _officer("Lieutenant Colonel (O-5)", "oak", SILVER),
    "Col": _officer("Colonel (O-6)", "eagle", SILVER),
}


# --- Game data -------------------------------------------------------------

def read_pbo_file(pbo: Path, name: str) -> bytes:
    def z(f):
        out = bytearray()
        while (c := f.read(1)) not in (b"", b"\0"):
            out += c
        return out.decode("latin1")

    with open(pbo, "rb") as f:
        entries, first = [], True
        while True:
            n = z(f)
            mime, _orig, _res, _ts, size = struct.unpack("<5I", f.read(20))
            if first and mime == 0x56657273:
                while z(f):
                    z(f)
                first = False
                continue
            first = False
            if not n:
                break
            entries.append((n, size))
        off = f.tell()
        for n, size in entries:
            if n.lower() == name.lower():
                f.seek(off)
                return f.read(size)
            off += size
    raise FileNotFoundError(f"{name} not in {pbo}")


class Tools:
    def __init__(self, tmp: Path):
        self.tmp = tmp
        self.exe = STEAM / "Arma 3 Tools" / "ImageToPAA" / "ImageToPAA.exe"
        self.pbo = STEAM / "Arma 3" / "AoW" / "Addons" / "characters_f_aow.pbo"
        for p in (self.exe, self.pbo):
            if not p.exists():
                sys.exit(f"Missing {p}")

    def load(self, name: str) -> np.ndarray:
        src = self.tmp / Path(name.replace("\\", "/")).name
        src.write_bytes(read_pbo_file(self.pbo, name))
        png = src.with_suffix(".png")
        subprocess.run([str(self.exe), str(src), str(png)], check=True, capture_output=True)
        return np.asarray(Image.open(png).convert("RGBA"), float).copy()

    def save(self, arr: np.ndarray, name: str):
        channels = arr.shape[2]
        img = Image.fromarray(np.clip(arr, 0, 255).astype("uint8"), "RGBA" if channels == 4 else "RGB")
        if max(img.size) > PAA_MAX:
            img = img.resize((PAA_MAX, PAA_MAX), Image.LANCZOS)
        png = self.tmp / (name + ".png")
        img.save(png)
        dst = DATA / (name + ".paa")
        subprocess.run([str(self.exe), str(png), str(dst)], check=True, capture_output=True)
        print(f"  {dst.name}  {dst.stat().st_size / 1e6:.2f} MB")


# --- Helpers ---------------------------------------------------------------

def grey(a):
    return a[..., 0] * 0.30 + a[..., 1] * 0.59 + a[..., 2] * 0.11


def box_mask(shape, boxes):
    m = np.zeros(shape[:2], bool)
    for x0, y0, x1, y1 in boxes:
        m[y0:y1, x0:x1] = True
    return m


def blur(a, sigma):
    """Gaussian blur of a 2D array, by FFT since the radii here are large."""
    h, w = a.shape
    fy = np.fft.fftfreq(h)[:, None]
    fx = np.fft.rfftfreq(w)[None, :]
    kernel = np.exp(-2 * (np.pi * sigma) ** 2 * (fx ** 2 + fy ** 2))
    return np.fft.irfft2(np.fft.rfft2(a) * kernel, s=a.shape)


def upscale(a, size):
    """Resize a float array, per channel, to (height, width)."""
    def one(c):
        return np.asarray(Image.fromarray(c.astype("float32"), "F").resize((size[1], size[0]), Image.BICUBIC), float)
    if a.ndim == 2:
        return one(a)
    return np.stack([one(a[..., i]) for i in range(a.shape[2])], axis=2)


def soft_threshold(a, t):
    return np.sign(a) * np.maximum(np.abs(a) - t, 0)


def noise(shape, sigma, seed):
    n = blur(np.random.default_rng(seed).normal(0, 1, shape), sigma)
    return n / n.std()


def cloth_grain(shape, seed):
    """Fine heathered wool: per-channel flecks over a soft mottle. Multiplies to ~1."""
    fine = noise(shape, 0.7, seed) * 0.022 + noise(shape, 22, seed + 1) * 0.01
    flecks = np.stack([noise(shape, 0.8, seed + 2 + i) * 0.012 for i in range(3)], axis=2)
    return 1 + fine[..., None] + flecks


def flatten_normals(n, folds=0.0):
    """Filter folds out of a tangent-space normal map, keeping seams and edges.

    Folds sit in the middle frequencies. Seams and pocket edges are much finer, and
    vanilla's fine weave is low amplitude, so a soft threshold removes it as well.
    """
    xy = n[..., :2] - 128.0
    out = np.empty_like(xy)
    for i in range(2):
        low = blur(xy[..., i], 3)
        very_low = blur(xy[..., i], 70)
        out[..., i] = (low - very_low) * folds + soft_threshold(xy[..., i] - low, 6) * 1.1
    return out


def normals_from(xy):
    """Assemble an RGBA normal map from x/y slopes in -127..127."""
    x, y = xy[..., 0] / 127.0, xy[..., 1] / 127.0
    z = np.sqrt(np.clip(1 - x ** 2 - y ** 2, 0.04, 1))
    out = np.full(xy.shape[:2] + (4,), 255.0)
    out[..., 0], out[..., 1], out[..., 2] = x * 127 + 128, y * 127 + 128, z * 127 + 128
    return out


def relief(rgba: Image.Image, strength=1.0, shadow=True) -> Image.Image:
    """Light an insignia from its own outline, so it reads as raised metal or cloth."""
    arr = np.asarray(rgba, float).copy()
    alpha = arr[..., 3] / 255
    height = blur(alpha, max(arr.shape[1] / 90, 0.9))
    gy, gx = np.gradient(height)
    # Lit from the upper left. Sheet orientation differs by island but it still reads.
    light = (-gx - gy) * arr.shape[1] / 90 * strength
    arr[..., :3] = np.clip(arr[..., :3] * (1 + np.clip(light, -0.7, 1.6))[..., None], 0, 255)
    if shadow:
        under = np.roll(np.roll(blur(alpha, 0.5 * K), K // 2, axis=0), K // 2, axis=1) * 0.7
        total = alpha + under * (1 - alpha)
        rgb = arr[..., :3] * (alpha / np.maximum(total, 1e-3))[..., None]
        arr[..., :3], arr[..., 3] = rgb, total * 255
    return Image.fromarray(np.clip(arr, 0, 255).astype("uint8"), "RGBA")


# Stage6 is close to no reflection, unlike vanilla's fresnel(1,0.7), which lays a pale
# veil of sky over the whole sun-facing side, right over black insignia. Reflectance
# is ((n-1)^2+k^2)/((n+1)^2+k^2), so it is n=1, k=0 that gives none, not low values.
def rvmat(ti, nohq, dt, smdi, dt_tile=1, power=300, env=r"a3\data_f\env_co.paa", diffuse=CLOTH_DIFFUSE):
    def stage(i, tex, tile=1):
        return (f'class Stage{i}\n{{\n\ttexture="{tex}";\n\tuvSource="tex";\n\tclass uvTransform\n\t{{\n'
                f'\t\taside[]={{{tile},0,0}};\n\t\tup[]={{0,{tile},0}};\n\t\tdir[]={{0,0,0}};\n\t\tpos[]={{0,0,0}};\n\t}};\n}};\n')
    return (f'class StageTI\n{{\n\ttexture="{ti}";\n}};\nambient[]={{1,1,1,1}};\ndiffuse[]={{{diffuse},{diffuse},{diffuse},1}};\n'
            f'forcedDiffuse[]={{0,0,0,0}};\nemmisive[]={{0,0,0,1}};\nspecular[]={{0.8,0.8,0.8,0.8}};\n'
            f'specularPower={power};\nPixelShaderID="Super";\nVertexShaderID="Super";\n'
            + stage(1, nohq) + stage(2, dt, dt_tile)
            + stage(3, "#(argb,8,8,3)color(0,0,0,0,MC)") + stage(4, "#(argb,8,8,3)color(1,1,1,1,AS)")
            + stage(5, smdi)
            + 'class Stage6\n{\n\ttexture="#(ai,64,64,1)fresnel(1,0.01)";\n\tuvSource="none";\n};\n'
            + stage(7, env))


def data_path(name):
    return f"{PREFIX}\\data\\{name}"


# --- Base sheet ------------------------------------------------------------

def remove_trouser_stripes(a):
    """Mirror the fabric on the outer side of each stripe across it.

    The stripes run beside the pockets, whose shadow would smear if used as a source.
    """
    r, g, b = a[..., 0], a[..., 1], a[..., 2]
    gold = (r - b > 50) & (r > g)
    stripe = np.zeros(a.shape[:2], bool)
    stripe[1060:2048, 255:320] = True
    stripe[1060:2048, 915:985] = True
    stripe &= gold & box_mask(a.shape, [TROUSERS])
    stripe = np.asarray(Image.fromarray(stripe).filter(ImageFilter.MaxFilter(7)))
    for y in np.where(stripe.any(axis=1))[0]:
        xs = np.where(stripe[y])[0]
        for run in np.split(xs, np.where(np.diff(xs) > 1)[0] + 1):
            x0, x1 = run[0], run[-1]
            w = x1 - x0 + 1
            src = a[y, max(x0 - w - 1, 0):x0 - 1] if (x0 + x1) / 2 < 612 else a[y, x1 + 2:x1 + 2 + w]
            if len(src) == w:
                a[y, x0:x1 + 1] = src[::-1]


def tailoring_height(size):
    """Height map, 0 to about 1, for the cuff seams and trouser creases."""
    h = np.zeros(size)
    for s in SLEEVES:
        hem = s["cuff_y"] * BASE_K
        peak_x = (s["cx"] + 30 * s["rear"]) * BASE_K
        x0, x1 = peak_x - 240 * BASE_K, peak_x + 240 * BASE_K
        xs = np.arange(max(x0, 0), min(x1, BASE))
        ys = hem - CUFF_PEAK_IN * BASE_PX_PER_IN + np.abs(xs - peak_x) * CUFF_SLOPE
        for x, y in zip(xs, ys):
            # A folded seam: raised above the line, a step down below it.
            yi = int(y)
            h[max(yi - 3, 0):yi + 1, x] = 1
    for x in TROUSER_CREASES:
        h[1120 * BASE_K:2010 * BASE_K, x * BASE_K - 1:x * BASE_K + 1] = 1
    return blur(h, 1.3)


def collar_emblem(index, px_per_k=24, k=K, shadow=True) -> Image.Image:
    """The coat collar's emblem, turned for its leaf. Eagles face inboard: the drawn
    eagle looks right, so the other leaf is flipped."""
    e = ega(px_per_k * k, shadow=shadow)
    if index:
        e = e.transpose(Image.FLIP_LEFT_RIGHT)
    return e.rotate(COAT_COLLAR[index][2], expand=True, resample=Image.BICUBIC)


def emboss_collar_emblems(xy):
    """Every rank wears these, so they can be raised in the shared normal map."""
    for i, (x, y, _) in enumerate(COAT_COLLAR):
        e = np.asarray(collar_emblem(i, k=BASE_K, shadow=False), float)
        alpha = e[..., 3] / 255
        # The silhouette stands proud, and the modelling inside it catches the light.
        height = blur(alpha, 0.8) + alpha * grey(e) / max(grey(e).max(), 1) * 0.8
        gy, gx = np.gradient(height)
        h, w = height.shape
        x0, y0 = x * BASE_K - w // 2, y * BASE_K - h // 2
        xy[y0:y0 + h, x0:x0 + w, 0] -= gx * 110
        xy[y0:y0 + h, x0:x0 + w, 1] -= gy * 110


def build_base(tools: Tools):
    """Return the shared 4096 colour and normal sheets and the 2048 specular base."""
    co = tools.load(r"Uniforms\Data\ParadeUniform_01_US_CO.paa")[..., :3]
    nohq = tools.load(r"Uniforms\Data\ParadeUniform_01_US_NOHQ.paa")
    smdi = tools.load(r"Uniforms\Data\ParadeUniform_01_US_SMDI.paa")
    remove_trouser_stripes(co)

    # The vanilla cuff buttons do not belong on a USMC service coat.
    for s in SLEEVES:
        x0, y0, x1, y1 = s["buttons"]
        dx = -(x1 - x0 + 6) * s["rear"]
        co[y0:y1, x0:x1] = co[y0:y1, x0 + dx:x1 + dx]

    shape = co.shape
    r, b = co[..., 0], co[..., 2]
    lum, sat = grey(co), co.max(axis=2) - co.min(axis=2)
    yy, xx = np.ogrid[:shape[0], :shape[1]]
    armhole = (xx - ARMHOLE[0]) ** 2 + (yy - ARMHOLE[1]) ** 2 < ARMHOLE[2] ** 2
    shirt = (sat < 14) & (lum > 62) & (box_mask(shape, SHIRT_ZONES) | armhole) & ~box_mask(shape, [STRAP_ZONE])
    tie = box_mask(shape, TIE)
    # Whole zones rather than by colour, which left holes in the toecaps. The one
    # scrap of cloth inside them is left out.
    shoes = box_mask(shape, SHOE_ZONES) & (lum < 110) & ~tie & ~shirt & ~box_mask(shape, [(1225, 1880, 1320, 2048), (1450, 1850, 1500, 2010)])
    fabric = ~(shirt | tie | shoes)

    # Fabric: broad form plus crisp seams and pocket edges, without the folds.
    # A low power: vanilla's broad light and dark reads as stains on clean cloth.
    broad = (np.maximum(blur(lum, 90), 8) / GREEN_REF) ** 0.12
    # A high threshold: vanilla's scattered specks would otherwise come through.
    # Seams only darken: vanilla's bright flecks along them read as pale scratches.
    seams = np.clip(soft_threshold(lum - blur(lum, 4), 7) / GREEN_REF * 0.9, -0.5, 0.02)
    tone = np.clip(broad + seams, 0.5, 1.25)
    out = co.copy()
    out[fabric] = GREEN * tone[fabric][..., None]
    out[shirt] = KHAKI * ((lum[shirt] / SHIRT_REF) ** 0.5)[..., None]
    # Smoothed, since vanilla's coarse tie weave stands out against a clean shirt.
    tie_tone = (np.maximum(blur(lum, 6), 8) / TIE_REF) ** 0.35
    out[tie] = KHAKI * tie_tone[tie][..., None]

    size = (BASE, BASE)
    colour = upscale(out, size)
    fabric_hi = upscale(fabric.astype(float), size)[..., None]
    grain = cloth_grain(size, 1020)
    colour *= 1 + (grain - 1) * fabric_hi

    # Tailoring the vanilla sheet lacks: the peaked cuff seam and a pressed crease.
    tailoring = tailoring_height(size)
    gy, gx = np.gradient(tailoring)
    colour *= 1 - np.clip(np.abs(gx) + np.abs(gy), 0, 1)[..., None] * 0.5 * fabric_hi

    # Normals: flattened fabric, plus a fine weave for light to catch up close.
    flat = flatten_normals(nohq)
    original = nohq[..., :2] - 128.0
    xy = np.where(fabric[..., None], flat, original)
    xy = upscale(xy, size)
    xy[..., 0] -= gx * 60
    xy[..., 1] -= gy * 60
    xy[..., 0] += fabric_hi[..., 0] * noise(size, 0.9, 77) * 1.5
    xy[..., 1] += fabric_hi[..., 0] * noise(size, 0.9, 78) * 1.5
    emboss_collar_emblems(xy)
    normals = normals_from(xy)

    # Specular: matte cloth, leather keeps a restrained shine.
    # Polished black. A warm sun turns anything brighter than this brown.
    shoes_hi = upscale(shoes.astype(float), size)[..., None]
    # Smoothed, since vanilla's leather grain reads as suede rather than a shine.
    # Never brighter than the source, or the blur pulls light in from around the sole.
    shoe_tone = np.minimum(blur(grey(colour), 5), grey(colour))
    colour = colour * (1 - shoes_hi) + shoe_tone[..., None] * 0.26 * shoes_hi
    # The smooth surface comes from the normal map too, keeping only the broad shape.
    for i in range(2):
        xy[..., i] = xy[..., i] * (1 - shoes_hi[..., 0]) + blur(xy[..., i], 6) * shoes_hi[..., 0]
    normals = normals_from(xy)
    spec = smdi.copy()
    spec[fabric, 1], spec[fabric, 2] = 2, 8
    spec[shirt | tie, 1], spec[shirt | tie, 2] = 2, 8
    # Any stronger and the shoe mirrors the blotchy reflection map like camouflage.
    spec[shoes, 1] = 90
    spec[shoes, 2] = 170
    spec[..., 0] = 255
    return colour, normals, spec[..., :3]


# --- Insignia --------------------------------------------------------------

def stamp(sheet, spec, rgba: Image.Image, cx, cy, metal=False):
    """Composite insignia centred at (cx, cy) in 4096 space, and mark metal as shiny."""
    arr = np.asarray(rgba, float)
    h, w = arr.shape[:2]
    x0, y0 = int(cx - w / 2), int(cy - h / 2)
    region = sheet[y0:y0 + h, x0:x0 + w]
    alpha = arr[..., 3:] / 255
    region[:] = region * (1 - alpha) + arr[..., :3] * alpha
    if metal:
        small = np.asarray(Image.fromarray(arr[..., 3].astype("uint8")).resize((max(w // K, 1), max(h // K, 1)), Image.BILINEAR), float) / 255
        sx, sy = x0 // K, y0 // K
        target = spec[sy:sy + small.shape[0], sx:sx + small.shape[1]]
        target[..., 1] = target[..., 1] * (1 - small) + 110 * small
        target[..., 2] = target[..., 2] * (1 - small) + 170 * small


def chevron_insignia(chevrons, rifles, rockers=0) -> Image.Image:
    """Green on scarlet cloth chevrons, point up (MCO 1020.34H fig. 4-6)."""
    # Rockered grades pack their stripes tighter, as the figure shows.
    stripe, gap = (0.105, 0.028) if rockers else (0.135, 0.035)
    fall = 0.40  # how far a wing drops across half the insignia width
    bowl = (0.40 if rockers else 0.46) if rifles else 0.0
    side_y = fall + chevrons * (stripe + gap) + (bowl * 0.15 if rifles else 0)
    depth = bowl * 0.85
    # Includes a scarlet edge below the last rocker.
    rocker_h = rockers * (stripe + gap) + (0.03 if rockers else 0)
    W = CHEVRON_W * SS
    H = int((side_y + depth + rocker_h + 0.04) * W)
    img = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    d = ImageDraw.Draw(img)
    u = W - 2 * SS
    green = INSIGNIA_GREEN + (255,)

    def pt(x, y):
        return (SS + x * u, SS + y * u)

    def curve(y, x0=1.0, x1=0.0):
        return [pt(x0 + (x1 - x0) * s, y + depth * np.sin(np.pi * s)) for s in np.linspace(0, 1, 60)]

    # Scarlet backing with a bowl-shaped lower edge.
    outline = [pt(0.5, 0), pt(1, fall), pt(1, side_y + rocker_h)]
    if rifles:
        outline += curve(side_y + rocker_h)
    else:
        outline.append(pt(0.5, side_y - fall))
    outline += [pt(0, side_y + rocker_h), pt(0, fall)]
    d.polygon(outline, fill=SCARLET + (255,))

    margin = 0.03
    wing = fall * (1 - 2 * margin)
    for i in range(chevrons):
        y = 0.05 + i * (stripe + gap)
        d.polygon([pt(0.5, y), pt(1 - margin, y + wing), pt(1 - margin, y + wing + stripe),
                   pt(0.5, y + stripe), pt(margin, y + wing + stripe), pt(margin, y + wing)], fill=green)

    for i in range(rockers):
        top = side_y + gap + i * (stripe + gap)
        d.polygon(curve(top, 1 - margin, margin) + curve(top + stripe, margin, 1 - margin), fill=green)

    if rifles:
        v_tip = 0.05 + chevrons * (stripe + gap)
        cx, cy = 0.5, (v_tip + side_y + depth) / 2 + 0.05
        for sgn in (-1, 1):
            # stock end thick, barrel thin, crossing at the centre
            a, b = pt(cx + sgn * 0.33, cy + 0.10), pt(cx - sgn * 0.33, cy - 0.10)
            mid = pt(cx + sgn * 0.08, cy + 0.024)
            d.line([a, mid], fill=green, width=int(0.07 * u))
            d.line([mid, b], fill=green, width=int(0.035 * u))

    out = img.resize((W // SS, H // SS), Image.LANCZOS)
    arr = np.asarray(out, float).copy()
    # Thread texture, so it reads as embroidery rather than flat paint.
    arr[..., :3] *= (1 + noise(arr.shape[:2], 0.7, 5) * 0.06)[..., None]
    return relief(Image.fromarray(np.clip(arr, 0, 255).astype("uint8"), "RGBA"), 0.5)


def service_stripes(count: int, rear: int, back=SCARLET, fill=INSIGNIA_GREEN, degrees=30, scale=1.0) -> Image.Image:
    """Green on scarlet, 30 degrees, front end low. Proportions from fig. 4-6.

    Navy stripes on the same coat are blue on green at 45 degrees (para 8000).
    """
    length, width, gap = (CHEVRON_W * v * scale for v in (1.1, 0.17, 0.05))
    ang = np.radians(degrees)
    W = int((length * np.cos(ang) + width + 12) * SS)
    H = int((length * np.sin(ang) + (count + 0.3) * (width + gap) / np.cos(ang) + 12) * SS)
    img = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    d = ImageDraw.Draw(img)
    ux, uy = np.cos(ang), -np.sin(ang)  # along the stripe, rising to the rear
    nx, ny = -uy, ux  # across it
    half, wd, pad = length / 2 * SS, width * SS, 0.012 * CHEVRON_W * SS
    cx, cy = W / 2, H - (length / 2 * np.sin(ang) + width) * SS

    for i in range(count):
        o = -i * (width + gap) * SS
        c = (cx + nx * o, cy + ny * o)

        def quad(along, across):
            return [(c[0] + sa * along * ux + sb * across * nx, c[1] + sa * along * uy + sb * across * ny)
                    for sa, sb in ((-1, -1), (1, -1), (1, 1), (-1, 1))]
        d.polygon(quad(half, wd / 2), fill=back + (255,))
        d.polygon(quad(half - pad * 2, wd / 2 - pad * 2), fill=fill + (255,))

    out = img.resize((W // SS, H // SS), Image.LANCZOS)
    if rear < 0:
        out = out.transpose(Image.FLIP_LEFT_RIGHT)
    return relief(out, 0.4)


def on_khaki(colour):
    """Metal against the shirt: bright silver has the same value as sunlit khaki, so
    only its dark lines would survive at a distance. Darker reads as one solid shape."""
    return tuple(int(c * 0.68) for c in colour)


def warrant_enamel(pattern, collar):
    """Scarlet blocks as (centre, width) along the bar, in inches, from para 4005."""
    if pattern == "three":
        centre, outer, gap = (5 / 32, 3 / 32, 5 / 32) if collar else (1 / 4, 1 / 8, 1 / 4)
        offset = centre / 2 + gap + outer / 2
        return [(-offset, outer), (0, centre), (offset, outer)]
    width, apart = (1 / 4, 5 / 32) if collar else (3 / 8, 1 / 4)
    offset = (width + apart) / 2
    return [(-offset, width), (offset, width)]


def warrant_bar(colour, pattern, scale=1.0) -> Image.Image:
    """One bar with scarlet enamel. Long axis across the strap, which is image-vertical."""
    collar = scale < 1
    length, width = (v * scale * PX_PER_IN * SS for v in (1.125, 0.375))
    inch = PX_PER_IN * SS
    pad = 3 * SS
    W, H = int(width + pad * 2), int(length + pad * 2)
    img = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    d = ImageDraw.Draw(img)
    d.rectangle([pad, pad, pad + width, pad + length], fill=colour + (255,))
    mid_x, mid_y = W / 2, H / 2
    if pattern == "stripe":
        # 1/8 inch wide, lengthwise along the bar.
        half = (0.75 if collar else 1.125) * inch / 2
        half = min(half, length / 2)
        d.rectangle([mid_x - inch / 16, mid_y - half, mid_x + inch / 16, mid_y + half], fill=SCARLET + (255,))
    else:
        inset = 0.035 * inch
        for centre, wide in warrant_enamel(pattern, collar):
            y = mid_y + centre * inch
            d.rectangle([pad + inset, y - wide * inch / 2, pad + width - inset, y + wide * inch / 2], fill=SCARLET + (255,))
    return polished(relief(img.resize((W // SS, H // SS), Image.LANCZOS), 1.6))


def caduceus(height) -> Image.Image:
    """The Hospital Corps mark: staff, two serpents and spread wings, in one colour."""
    h = int(height) * SS
    w = int(h * 0.8)
    img = Image.new("RGBA", (w, h), (0, 0, 0, 0))
    d = ImageDraw.Draw(img)
    blue = NAVY_BLUE + (255,)
    cx = w / 2
    # Staff and knob.
    d.rectangle([cx - h * 0.018, h * 0.1, cx + h * 0.018, h], fill=blue)
    d.ellipse([cx - h * 0.05, h * 0.03, cx + h * 0.05, h * 0.13], fill=blue)
    # Wings: feathers swept up and out from the staff's head.
    for sign in (-1, 1):
        for i in range(5):
            root = h * (0.16 + i * 0.025)
            tip_x = cx + sign * w * (0.48 - i * 0.075)
            tip_y = h * (0.06 + i * 0.075)
            d.polygon([(cx, root), (tip_x, tip_y), (tip_x - sign * w * 0.05, tip_y + h * 0.05), (cx, root + h * 0.05)], fill=blue)
    # Two serpents winding round the staff.
    ys = np.linspace(h * 0.3, h * 0.92, 90)
    for phase in (0, np.pi):
        pts = [(cx + np.sin((y / h - 0.3) * 3 * 2 * np.pi + phase) * w * 0.17 * (1 - (y / h - 0.3) * 0.7), y) for y in ys]
        d.line(pts, fill=blue, width=int(h * 0.035), joint="curve")
    return img.resize((w // SS, h // SS), Image.LANCZOS)


def navy_eagle(width) -> Image.Image:
    """The order's eagle, cut above the arrows it holds as a colonel's, with a tail added."""
    src = Image.open(ASSETS / "eagle.png").convert("RGBA")
    src = src.resize((int(width), int(src.height * width / src.width)), Image.LANCZOS)
    a = np.asarray(src, float).copy()
    h, w = a.shape[:2]
    cut = int(h * 0.68)
    a[cut:, ..., 3] = 0
    level = grey(a[a[..., 3] > 128, :3]).mean()
    tone = np.clip(grey(a) / max(level, 1), 0.3, 1.6)
    a[..., :3] = np.array(NAVY_BLUE, float) * (0.55 + tone * 0.6)[..., None]
    img = Image.fromarray(crisp(np.clip(a, 0, 255)).astype("uint8"), "RGBA")
    d = ImageDraw.Draw(img)
    d.polygon([(w * 0.43, cut - h * 0.03), (w * 0.57, cut - h * 0.03), (w * 0.62, h * 0.94), (w * 0.38, h * 0.94)], fill=NAVY_BLUE + (255,))
    # Faces the front of the coat on the left sleeve.
    return img.transpose(Image.FLIP_LEFT_RIGHT)


def rate_badge(chevrons, rocker) -> Image.Image:
    """Navy rating badge: eagle, Hospital Corps mark and chevrons point down."""
    W = RATE_W
    eagle = navy_eagle(W * 0.72)
    mark = caduceus(W * 0.36)
    stripe, gap, fall = 0.065, 0.04, 0.3
    cad_top = eagle.height / W + (0.1 if rocker else -0.02)
    cad_bottom = cad_top + mark.height / W
    wing_y = cad_bottom - 0.2
    H = int((wing_y + fall + chevrons * (stripe + gap) + 0.04) * W)
    layer = Image.new("RGBA", (W * SS, H * SS), (0, 0, 0, 0))
    d = ImageDraw.Draw(layer)
    u = (W - 2) * SS
    blue = NAVY_BLUE + (255,)

    def pt(x, y):
        return (SS + x * u, SS + y * u)

    for i in range(chevrons):
        y = wing_y + i * (stripe + gap)
        d.polygon([pt(0, y), pt(0.5, y + fall), pt(1, y), pt(1, y + stripe), pt(0.5, y + fall + stripe), pt(0, y + stripe)], fill=blue)
    if rocker:
        # A chief's arc over the mark, its ends meeting the top chevron's.
        top, thick = cad_top - 0.09, 0.065
        def arc(offset, reverse=False):
            ss = np.linspace(0, 1, 60)
            pts = [pt(s, wing_y - 0.02 + offset - (wing_y - 0.02 - top) * np.sin(np.pi * s)) for s in ss]
            return pts[::-1] if reverse else pts
        d.polygon(arc(0) + arc(thick, True), fill=blue)
    img = layer.resize((W, H), Image.LANCZOS)
    img.alpha_composite(mark, (W // 2 - mark.width // 2, int(cad_top * W)))
    img.alpha_composite(eagle, (W // 2 - eagle.width // 2, 0))
    arr = np.asarray(img, float).copy()
    # Thread texture, so it reads as embroidery rather than flat paint.
    arr[..., :3] *= (1 + noise(arr.shape[:2], 0.7, 6) * 0.06)[..., None]
    return relief(Image.fromarray(np.clip(arr, 0, 255).astype("uint8"), "RGBA"), 0.5)


def apply_navy(a, sm, spec):
    """Everything goes on the left sleeve: rate midway to the elbow, stripes at the cuff."""
    kind, count, rocker, striker = spec["navy"]
    s = LEFT_SLEEVE
    centre = s["seam_y"] * K + int(RATE_CENTRE_IN * PX_PER_IN)
    if kind == "crow":
        stamp(a, sm, rate_badge(count, rocker), s["cx"] * K, centre)
    elif count:
        # NAVPERS 15665: 3 inch stripes at 30 degrees, lower end forward, with any
        # striker mark centred immediately above.
        marks = service_stripes(count, s["rear"], NAVY_BLUE, NAVY_BLUE, 30, 0.6)
        stamp(a, sm, marks, s["cx"] * K, centre)
        if striker:
            mark = relief(caduceus(1.3 * PX_PER_IN), 0.5)
            stamp(a, sm, mark, s["cx"] * K, centre - int(marks.height * 0.32) - mark.height // 2)
    if spec["stripes"]:
        st = service_stripes(spec["stripes"], s["rear"], NAVY_BLUE, NAVY_BLUE, 45, 0.8)
        bottom = s["cuff_y"] * K - int((CUFF_PEAK_IN + 0.5) * PX_PER_IN)
        stamp(a, sm, st, s["cx"] * K, bottom - st.height // 2)


def watermark(sheet):
    """Mark the sheet as ours where no player can see it, so a ripped copy can be proved."""
    ink = np.array((150, 145, 120), float)

    def text_mask(w, h, lines):
        mask = Image.new("L", (w, h), 0)
        d = ImageDraw.Draw(mask)
        size = h // (len(lines) + 1)
        font = ImageFont.truetype("arialbd.ttf", size)
        while max(d.textlength(line, font=font) for line in lines) > w - 12:
            size -= 1
            font = ImageFont.truetype("arialbd.ttf", size)
        for i, line in enumerate(lines):
            d.text((6, 4 + i * (h - 8) // len(lines)), line, fill=255, font=font)
        return mask

    x0, y0, x1, y1 = (v * K for v in WATERMARK_BLOCK)
    mask = np.asarray(text_mask(x1 - x0, y1 - y0, WATERMARK), float)[..., None] / 255
    sheet[y0:y1, x0:x1] = sheet[y0:y1, x0:x1] * (1 - mask) + ink * mask

    x0, y0, x1, y1 = (v * K for v in WATERMARK_STRIP)
    strip = text_mask(y1 - y0, x1 - x0, WATERMARK[:1]).rotate(90, expand=True)
    mask = np.asarray(strip, float)[..., None] / 255
    sheet[y0:y1, x0:x1] = sheet[y0:y1, x0:x1] * (1 - mask) + ink * mask


def bars(count, colour, scale=1.0) -> Image.Image:
    """Bars with their long axis across the strap, which is image-vertical.

    Captain's pair is joined by a holding bar at each end. Dimensions are from
    para 4005: 1 1/8 by 3/8 inch and 3/8 inch apart.
    """
    length, width, apart = (v * scale * PX_PER_IN * SS for v in (1.125, 0.375, 0.375))
    pad = 3 * SS
    W, H = int(count * width + (count - 1) * apart + pad * 2), int(length + pad * 2)
    img = Image.new("RGBA", (W, H), (0, 0, 0, 0))
    d = ImageDraw.Draw(img)
    y0, y1 = pad, pad + length
    if count > 1:
        for ya, yb in ((y0, y0 + width * 0.17), (y1 - width * 0.17, y1)):
            d.rectangle([pad, ya, W - pad, yb], fill=colour + (255,))
    for i in range(count):
        x0 = pad + i * (width + apart)
        d.rectangle([x0, y0, x0 + width, y1], fill=colour + (255,))
    return polished(relief(img.resize((W // SS, H // SS), Image.LANCZOS), 1.6))


def polished(rgba: Image.Image) -> Image.Image:
    """A soft band of light across flat metal, so it stops reading as plastic."""
    arr = np.asarray(rgba, float).copy()
    h, w = arr.shape[:2]
    yy, xx = np.mgrid[:h, :w]
    arr[..., :3] *= (0.82 + 0.34 * np.exp(-(((xx / max(w, 1) + yy / max(h, 1)) - 0.8) / 0.45) ** 2))[..., None]
    return Image.fromarray(np.clip(arr, 0, 255).astype("uint8"), "RGBA")


def load_asset(name, width) -> Image.Image:
    img = Image.open(ASSETS / f"{name}.png").convert("RGBA")
    return img.resize((int(width), int(img.height * width / img.width)), Image.LANCZOS)


def crisp(arr):
    """Harden the silhouette and sharpen the modelling, which resizing softens."""
    out = arr.copy()
    out[..., 3] = np.clip((out[..., 3] - 90) * 255 / 75, 0, 255)
    rgb = Image.fromarray(np.clip(out[..., :3], 0, 255).astype("uint8"), "RGB").filter(
        ImageFilter.UnsharpMask(radius=2, percent=160, threshold=0))
    out[..., :3] = np.asarray(rgb, float)
    return out


def metal_asset(name, colour, width, stretch=1.5) -> Image.Image:
    """A photographed insignia, brought to the sheet's brightness for this metal."""
    arr = np.asarray(load_asset(name, width), float).copy()
    alpha = arr[..., 3] > 128
    arr[..., :3] *= grey(np.array(colour, float)) / max(grey(arr[alpha, :3]).mean(), 1)
    # Stretch the modelling around the mean, so feathers and veins read from a distance.
    level = grey(arr[alpha, :3]).mean()
    arr[..., :3] = level + (arr[..., :3] - level) * stretch
    arr = crisp(np.clip(arr, 0, 255))
    return relief(Image.fromarray(arr.astype("uint8"), "RGBA"), 0)


def ega(size_px: int, shade=PIN_BLACK[0], shadow=True) -> Image.Image:
    """The Eagle, Globe and Anchor in non-glossy black, keeping its modelling."""
    arr = np.asarray(load_asset("ega", size_px), float).copy()
    tone = grey(arr)
    tone = tone / np.percentile(tone[arr[..., 3] > 128], 90)
    # Wide range for a dark colour, so the globe and wings stay legible in sun or shade.
    arr[..., :3] = (shade * (0.3 + tone * 2.2))[..., None]
    img = Image.fromarray(crisp(np.clip(arr, 0, 255)).astype("uint8"), "RGBA")
    return relief(img, 0, shadow)


def officer_insignia(metal, scale=1.0) -> Image.Image:
    """Laid out as on the strap: eagle's head and oak stem end up along the strap."""
    kind, colour, count = metal
    if kind == "warrant":
        return warrant_bar(on_khaki(colour) if scale < 1 else colour, count, scale)
    if kind == "bars":
        return bars(count, on_khaki(colour) if scale < 1 else colour, scale)
    # Flipped so the eagle faces the front of the coat (para 4005). Both straps share
    # this sheet, mirrored, so that holds on both shoulders.
    return upright_insignia(metal, scale).transpose(Image.FLIP_LEFT_RIGHT).rotate(90, expand=True, resample=Image.BICUBIC)


def upright_insignia(metal, scale) -> Image.Image:
    kind, colour, _ = metal
    shirt = scale < 1
    tone, stretch = (on_khaki(colour), 1.1) if shirt else (colour, 1.5)
    if kind == "oak":
        name = "oak_gold" if colour == GOLD else "oak_silver"
        return metal_asset(name, tone, 0.92 * scale * PX_PER_IN, stretch)
    return metal_asset("eagle", tone, 1.5 * scale * PX_PER_IN, stretch)


def apply_rank(base, base_spec, spec):
    a, sm = upscale(base, (SHEET, SHEET)), base_spec.copy()

    # Coat collar emblems: non-glossy black (para 4001). The collar's scale is finer
    # than the sleeve's, so this renders a little over the regulation 9/16 inch.
    for i, (x, y, _) in enumerate(COAT_COLLAR):
        stamp(a, sm, collar_emblem(i), x * K, y * K)

    if "metal" in spec:
        strap = SHOULDER_STRAP
        insignia = officer_insignia(spec["metal"])
        # Outer edge's midpoint 3/4 inch from the armhole seam, which is the strap's
        # right-hand end on the sheet (para 4005).
        x = strap["x1"] * K - int(0.75 * PX_PER_IN) - insignia.width // 2
        stamp(a, sm, insignia, x, strap["cy"] * K, metal=True)
        # Required on the shirt collar under the coat as well.
        for i, (x, y, rot) in enumerate(SHIRT_COLLAR):
            if spec["metal"][0] in ("bars", "warrant"):
                small = officer_insignia(spec["metal"], 0.75)
            else:
                # Upright on the collar: head or stem toward its top or bottom.
                # Facing the front of the collar on both sides (para 4005).
                upright = upright_insignia(spec["metal"], 0.72)
                if i == 0:
                    upright = upright.transpose(Image.FLIP_LEFT_RIGHT)
                small = upright.rotate(rot, expand=True, resample=Image.BICUBIC)
            stamp(a, sm, small, x * K, y * K, metal=True)
    elif "navy" in spec:
        apply_navy(a, sm, spec)
    else:
        if spec["chevrons"]:
            insignia = chevron_insignia(spec["chevrons"], spec["rifles"], spec["rockers"])
            for s in SLEEVES:
                # 4 inches below the shoulder seam (para 4004).
                top = s["seam_y"] * K + int(4 * PX_PER_IN)
                stamp(a, sm, insignia, s["cx"] * K, top + insignia.height // 2)
        if spec["stripes"]:
            for s in SLEEVES:
                st = service_stripes(spec["stripes"], s["rear"])
                # Lower edge 1/2 inch above the point of the cuff (para 4008).
                bottom = s["cuff_y"] * K - int((CUFF_PEAK_IN + 0.5) * PX_PER_IN)
                stamp(a, sm, st, s["cx"] * K, bottom - st.height // 2)
    watermark(a)
    return a, sm


# --- Shared sheets ---------------------------------------------------------

def build_decor(tools: Tools):
    """Coat belt, buckle and buttons: colour, normal map and specular."""
    co = tools.load(r"Uniforms\Data\ParadeUniform_Decorated_01_US_CO.paa")[..., :3]
    nohq = tools.load(r"Uniforms\Data\ParadeUniform_Decorated_01_US_NOHQ.paa")
    smdi = tools.load(r"Uniforms\Data\ParadeUniform_Decorated_01_US_SMDI.paa")[..., :3]

    # 40-line coat button: black plastic. Keep the relief, drop the gold.
    lum = grey(co)
    bx, by, brx, bry = COAT_BUTTON
    yy, xx = np.ogrid[:co.shape[0], :co.shape[1]]
    disc = ((xx - bx) / brx) ** 2 + ((yy - by) / bry) ** 2 < 1
    co[disc] = PIN_BLACK
    # The cuff buttons are geometry using this disc. Real service coats have none,
    # so they take the cloth's colour and shrink to a slight bump.
    sx, sy, srx, sry = SMALL_BUTTON
    small = ((xx - sx) / srx) ** 2 + ((yy - sy) / sry) ** 2 < 1
    co[small] = GREEN

    # The plate's thin side faces map to the pale pieces beside it, which show as a
    # bright sliver under the buckle unless they match the belt.
    sat = co.max(axis=2) - co.min(axis=2)
    sides = box_mask(co.shape, [(0, 440, 840, 512), (324, 204, 840, 440)]) & (lum > 60) & (sat < 30)
    co[sides] = GREEN

    k = DECOR_K
    size = (co.shape[0] * k, co.shape[1] * k)
    colour = upscale(co, size)
    xy = upscale(nohq[..., :2] - 128.0, size)
    spec = upscale(smdi, size)

    # Measured beside the buckle in game: the same value renders darker and greener here
    # than on the coat.
    cloth = GREEN * np.array((1.2, 1.1, 1.08))
    grain = cloth_grain(size, 2040)
    height = np.zeros(size)
    h, w = size

    # Belt: the same cloth as the coat, with lines of stitching near each edge.
    y0, y1 = BELT_Y[0] * k, BELT_Y[1] * k
    belt_tone = np.ones((y1 - y0, w))
    stitch = np.zeros((y1 - y0, w))
    for yy_s in (14 * k, (BELT_Y[1] - 14) * k):
        stitch[yy_s - 2:yy_s + 2, :] = 1
    # The belt is squeezed in x, so stitches are short in sheet space.
    dashes = (np.arange(w) // 6) % 2 == 0
    stitch *= dashes[None, :]

    belt_tone *= 1 - stitch * 0.32
    colour[y0:y1] = cloth * belt_tone[..., None] * grain[y0:y1]

    # Plate: geometry far wider than a real buckle, so the belt runs across it and
    # the buckle is painted smaller. Same for every rank: para 3002 sets one belt
    # for all male service coats. Thin open frame, no centre bar, a little taller
    # than the belt, with its inner edge on the coat front.
    px0, py0, px1, py1 = (v * k for v in PLATE)
    pw, ph = px1 - px0, py1 - py0
    colour[py0:py1, px0:px1] = cloth * grain[py0:py1, px0:px1]

    fh = ph
    fw = int(fh * 0.56)
    bx0, by0 = px0 + int(pw * 0.24), py0
    tail = np.zeros((ph, pw))
    # Free end, passed through toward the wearer's left, tapering to a point. Cut off
    # by the plate's edge, as the belt either side of it is shared between both sides
    # of the waist, so this is shorter than the order's 2 3/4 inches.
    tail_top, tail_bottom = int(ph * 0.16), int(ph * 0.84)
    tail_x0, tail_x1 = bx0 - px0 + fw - 4 * k, pw - 8 * k
    point = int((tail_bottom - tail_top) * 0.42)
    for x in range(tail_x0, tail_x1):
        inset = max(0, x - (tail_x1 - point)) * (tail_bottom - tail_top) / 2 / point
        tail[tail_top + int(inset):tail_bottom - int(inset), x] = 1
    # Cloth keeper, midway between the buckle and the tip, proud of the tail.
    keeper = np.zeros((ph, pw))
    kx = (bx0 - px0 + fw + tail_x1) // 2 - 16 * k
    keeper[:, kx:kx + 15 * k] = 1
    layer = blur(tail, 1.6) * 0.8 + blur(keeper, 1.4) * 1.3
    gy, gx = np.gradient(layer)
    # Edges in shadow, and the doubled-over end a touch darker than the belt beneath.
    edge = blur(np.abs(gx) + np.abs(gy), 1.2)
    shade = np.clip(1 - edge * 1.6, 0.55, 1) * (1 - np.clip(blur(tail, 1.6), 0, 1) * 0.07)
    colour[py0:py1, px0:px1] *= shade[..., None]
    height[py0:py1, px0:px1] = layer

    canvas = Image.new("RGBA", (fw * SS, fh * SS), (0, 0, 0, 0))
    d = ImageDraw.Draw(canvas)
    rim = int(fw * SS * 0.13)
    d.rounded_rectangle([0, 0, fw * SS - 1, fh * SS - 1], radius=rim // 2, fill=BRASS + (255,))
    d.rounded_rectangle([rim, rim, fw * SS - rim - 1, fh * SS - rim - 1], radius=rim // 3, fill=(0, 0, 0, 0))
    buckle = canvas.resize((fw, fh), Image.LANCZOS)
    alpha = np.asarray(buckle, float)[..., 3] / 255
    lit = np.asarray(relief(buckle, 2.2, shadow=False), float)[..., :3]
    sheen = 1 + 0.14 * np.sin(np.linspace(0, np.pi, fh))[:, None, None]
    target = colour[by0:by0 + fh, bx0:bx0 + fw]
    # The frame's soft shadow on the cloth behind it.
    target *= 1 - (blur(alpha, 4) * 0.45)[..., None] * (1 - alpha[..., None])
    target[:] = target * (1 - alpha[..., None]) + lit * sheen * alpha[..., None]
    height[by0:by0 + fh, bx0:bx0 + fw] += blur(alpha, 1.6) * 2.0

    # Normals: belt and plate come from the drawn height, not vanilla's eagle.
    gy, gx = np.gradient(height)
    drawn = np.stack([-gx * 90, -gy * 90], axis=2)
    weave = noise(size, 0.9, 79) * 3.0
    for yr0, yr1, xr0, xr1 in ((y0, y1, 0, w), (py0, py1, px0, px1)):
        xy[yr0:yr1, xr0:xr1, 0] = drawn[yr0:yr1, xr0:xr1, 0] + weave[yr0:yr1, xr0:xr1]
        xy[yr0:yr1, xr0:xr1, 1] = drawn[yr0:yr1, xr0:xr1, 1] + weave[yr0:yr1, xr0:xr1]

    # Specular: matte cloth, polished buckle.
    spec[y0:y1, :, 1], spec[y0:y1, :, 2] = 2, 8
    spec[py0:py1, px0:px1, 1], spec[py0:py1, px0:px1, 2] = 2, 8
    tgt = spec[by0:by0 + fh, bx0:bx0 + fw]
    tgt[..., 1] = tgt[..., 1] * (1 - alpha) + 200 * alpha
    tgt[..., 2] = tgt[..., 2] * (1 - alpha) + 190 * alpha
    # Black plastic buttons, near matte. Vanilla's relief is the Army's Great Seal, so
    # it is replaced with a domed face, a rim and the emblem.
    bdisc = upscale(disc.astype(float), size) > 0.5
    spec[bdisc, 1] = 5
    spec[bdisc, 2] = 30
    cx, cy, rx, ry = (v * k for v in COAT_BUTTON)
    gy_b, gx_b = np.mgrid[cy - ry:cy + ry, cx - rx:cx + rx]
    d2 = ((gx_b - cx) / rx) ** 2 + ((gy_b - cy) / ry) ** 2
    button = np.clip(1 - d2, 0, 1) ** 0.5 * 0.9 + np.clip((d2 - 0.78) / 0.06, 0, 1) * np.clip((1.0 - d2) / 0.06, 0, 1) * 0.35
    mark = np.asarray(load_asset("ega", int(rx * 1.35)), float)[..., 3] / 255
    mh, mw = mark.shape
    my, mx = ry - mh // 2, rx - mw // 2
    button[my:my + mh, mx:mx + mw] += blur(mark, 1.0) * 0.5
    bgy, bgx = np.gradient(button * 14)
    inside = d2 < 1
    region = xy[cy - ry:cy + ry, cx - rx:cx + rx]
    region[..., 0][inside] = np.clip(-bgx[inside] * 45, -110, 110)
    region[..., 1][inside] = np.clip(-bgy[inside] * 45, -110, 110)
    spec[..., 0] = 255
    return colour, normals_from(xy), spec


def build_caps(tools: Tools):
    """Service frame caps: colour per grade group, normals with or without quatrefoil.

    Enlisted are plain. Officers add the quatrefoil on the crown, and field grade add
    oak sprays on the visor (para 3004 and figure 3-2).
    """
    src = tools.load(r"Headgear\Data\ParadeDressCap_01_US_F_CO.paa")
    nohq = tools.load(r"Headgear\Data\ParadeDressCap_01_US_F_NOHQ.paa")
    smdi = tools.load(r"Headgear\Data\ParadeDressCap_01_US_F_SMDI.paa")[..., :3]
    a = src[..., :3]
    lum = grey(a)
    r, g, b = a[..., 0], a[..., 1], a[..., 2]

    # Crown top, crown wall and band. Read off the model: the top disc is the big
    # circle, the wall the strips beneath it, and the band the row at y 805-890.
    fabric = box_mask(a.shape, [(0, 0, 512, 540), (0, 540, 640, 800), (0, 800, 1024, 895)])
    tone = np.clip((np.maximum(blur(lum, 40), 8) / GREEN_REF) ** 0.25
                   + soft_threshold(lum - blur(lum, 3), 3) / GREEN_REF, 0.5, 1.2)
    a[fabric] = GREEN * tone[fabric][..., None]
    # All gold on the vanilla cap (buttons, chinstrap, braid) is black here.
    gold = (r - b > 50) & (g > r * 0.45) & ~fabric
    a[gold] = lum[gold][..., None] * 0.15
    a[895:1024, :] = grey(a[895:1024, :])[..., None] * 0.15
    # Lining: dark rather than Army-parade scarlet.
    red = (r > g * 2) & (r > b * 2)
    a[red] = lum[red][..., None] * np.array([0.55, 0.52, 0.42])

    # Visor: darker, or sky light turns its dark grey blue in game.
    visor = box_mask(a.shape, [(505, 330, 900, 540), (800, 0, 1024, 340)]) & (lum < 70)
    a[visor] *= 0.5

    k = 2
    size = (a.shape[0] * k, a.shape[1] * k)
    colour = upscale(a, size)
    fabric_hi = upscale(fabric.astype(float), size)[..., None]
    colour *= 1 + (cloth_grain(size, 3060) - 1) * fabric_hi
    alpha = upscale(src[..., 3], size)

    # The cap badge is an alpha-cut plate: redraw it to the EGA's outline.
    x0, y0, x1, y1 = 666 * k, 580 * k, 1017 * k, 801 * k
    colour[y0:y1, x0:x1] = PIN_BLACK
    alpha[y0:y1, x0:x1] = 0
    badge = np.asarray(ega(200 * k, shadow=False), float)
    bh, bw = badge.shape[:2]
    bx, by = 845 * k - bw // 2, 690 * k - bh // 2
    colour[by:by + bh, bx:bx + bw] = badge[..., :3]
    alpha[by:by + bh, bx:bx + bw] = badge[..., 3]

    xy = np.where(fabric[..., None], flatten_normals(nohq, folds=0.25), nohq[..., :2] - 128.0)
    xy = upscale(xy, size)
    xy[y0:y1, x0:x1] = 0

    # Gloss visor and strap, but less of it: at full strength the visor mirrors the
    # sky and reads grey instead of black.
    spec = upscale(smdi, size) * np.array([1, 0.35, 0.7])
    spec[..., 1][fabric_hi[..., 0] > 0.5] = 2
    spec[..., 2][fabric_hi[..., 0] > 0.5] = 8
    spec[..., 0] = 255

    # Quatrefoil: green braid on a green crown, so mostly raised rather than coloured.
    # The figure's braid spans 270 px of a crown 397 px across.
    cx, cy, radius = CAP_CROWN
    q = load_asset("quatrefoil", 270 * 2 * radius * k / 397).rotate(CAP_CROWN_ROTATION, expand=True, resample=Image.BICUBIC)
    q_arr = np.asarray(q, float)
    qh, qw = q_arr.shape[:2]
    qx, qy = cx * k - qw // 2, cy * k - qh // 2
    braid = q_arr[..., 3] / 255
    officer = colour.copy()
    officer[qy:qy + qh, qx:qx + qw] *= (1 + (q_arr[..., 0] / 255 - 0.5) * 0.8 * braid)[..., None]
    height = np.zeros(size)
    height[qy:qy + qh, qx:qx + qw] = blur(braid, 1.4)
    gy, gx = np.gradient(height)
    officer_xy = xy + np.dstack([-gx * 110, -gy * 110])

    # Field grade: the figure's oak sprays, fitted to the visor.
    vx0, vy0, vx1, vy1 = (v * k for v in CAP_VISOR)
    spray = Image.open(ASSETS / "visor_field.png").convert("RGBA").resize((vx1 - vx0, vy1 - vy0), Image.LANCZOS)
    s_arr = np.asarray(spray, float)
    field = officer.copy()
    s_alpha = s_arr[..., 3:] / 255
    field[vy0:vy1, vx0:vx1] = field[vy0:vy1, vx0:vx1] * (1 - s_alpha) + s_arr[..., :3] * 0.36 * s_alpha

    colours = {"": np.dstack([colour, alpha]), "_officer": np.dstack([officer, alpha]), "_field": np.dstack([field, alpha])}
    return colours, {"": normals_from(xy), "_officer": normals_from(officer_xy)}, spec


def build_suitpack(tools: Tools) -> np.ndarray:
    """The folded uniform seen on the ground: the same coat, with green trousers."""
    src = tools.load(r"Uniforms\Suitpacks\data\suitpack_ParadeUniform_01_US_decorated_co.paa")[..., :3]
    lum = grey(src)
    r, b = src[..., 0], src[..., 2]
    out = np.empty_like(src)
    # Coat and trousers are different vanilla cloths, so each is measured separately.
    trousers = box_mask(src.shape, [(30, 325, 445, 512)])
    stripe = (r - b > 40) & trousers
    braid = box_mask(src.shape, [(405, 30, 512, 62)]) & (b - r > 15)
    gold = (r - b > 45) & ~trousers
    shirt = (lum > 95) & (src.max(axis=2) - src.min(axis=2) < 30) & box_mask(src.shape, [(400, 90, 512, 180)])
    tie = box_mask(src.shape, [(470, 120, 512, 170)]) & ~shirt & (lum < 70)
    for part, ref in ((trousers, np.median(lum[trousers & ~stripe])), (~trousers, np.median(lum[~trousers & ~gold & ~shirt]))):
        out[part] = GREEN * np.clip(lum[part] / ref, 0.45, 1.5)[..., None] ** 0.6 * 0.72  # the model's own material lights it far brighter than the coat
    # Stripe and braid take the cloth either side of them.
    soft = np.stack([blur(out[..., i] * ~(stripe | braid), 7) / np.maximum(blur((~(stripe | braid)).astype(float), 7), 0.05) for i in range(3)], axis=2)
    grown = np.asarray(Image.fromarray(stripe | braid).filter(ImageFilter.MaxFilter(5)))
    out[grown] = soft[grown]
    out[gold] = PIN_BLACK
    out[shirt] = KHAKI * (lum[shirt] / max(np.percentile(lum[shirt], 80), 1))[..., None]
    out[tie] = KHAKI * 0.8
    return out


def build_award_ribbons(tools: Tools):
    """Tiles for drawing a wearer's rack at runtime, from tools/fetch-dress-ribbons.py."""
    catalogue = json.loads((RIBBON_ART / "ribbons.json").read_text())
    entries = []
    for i, award in enumerate(catalogue):
        art = RIBBON_ART / f"{award['id']}.png"
        if not art.exists():
            continue
        # Texture sides must be powers of two. The stretch cancels out when drawn.
        tile = np.asarray(Image.open(art).convert("RGB").resize((256, 64), Image.LANCZOS), float) * RACK_UI_LEVEL
        name = f"ptf_dress_ribbon_{i:02d}_co"
        tools.save(tile, name)
        cls = "r_" + award["id"].replace("-", "_")
        entries.append(f"""   class {cls}
   {{
      name = "{award['name']}";
      picture = "\\{data_path(name + '.paa')}";
   }};
""")
    for metal, colour in (("gold", (205, 165, 60)), ("silver", (175, 178, 182))):
        size = 64 * SS
        img = Image.new("RGBA", (size, size), (0, 0, 0, 0))
        points = []
        for j in range(10):
            r = size * (0.48 if j % 2 == 0 else 0.19)
            a = -np.pi / 2 + j * np.pi / 5
            points.append((size / 2 + r * np.cos(a), size / 2 + r * np.sin(a)))
        ImageDraw.Draw(img).polygon(points, fill=colour + (255,))
        tools.save(np.asarray(img.resize((64, 64), Image.LANCZOS), float), f"ptf_dress_device_{metal}_ca")
    header = "// GENERATED by tools/generate-dress-uniforms.py - do not edit by hand.\n"
    (ADDON / "cfgRibbons.hpp").write_text(header + f"""class CfgPTFDressRibbons
{{
   device_gold = "\\{data_path('ptf_dress_device_gold_ca.paa')}";
   device_silver = "\\{data_path('ptf_dress_device_silver_ca.paa')}";
""" + "".join(entries) + "};\n", newline="\n")


def build_detail() -> np.ndarray:
    """Tiling fine grain for close-up cloth. Averages 0.5, so brightness is untouched."""
    v = 128 + noise((1024, 1024), 0.8, 1020) * 3 + noise((1024, 1024), 6, 1021) * 1
    return np.dstack([v, v, v])


# --- Config ----------------------------------------------------------------

def write_config(ranks):
    veh, wep = [], []
    for ab in ranks:
        s = RANKS[ab]
        low = ab.lower()
        veh.append(f"""class PTF_Dress_USMC_A_{ab}_Unit : PTF_Dress_USMC_A_Base
{{
   scope = 1;
   uniformClass = "PTF_Uniform_Dress_USMC_A_{ab}";
   hiddenSelectionsTextures[] =
   {{
      "\\{data_path(f'ptf_dress_usmc_a_{low}_co.paa')}",
      "",
      "\\{data_path('ptf_dress_usmc_decor_co.paa')}",
      "",
      ""
   }};
   hiddenSelectionsMaterials[] =
   {{
      "\\{data_path(f'ptf_dress_usmc_a_{low}.rvmat')}",
      "",
      "\\{data_path('ptf_dress_usmc_decor.rvmat')}",
      // No rack: a rack is only ever shown when it is the wearer's own. Both of these
      // must stay empty to hide it, as a material alone brings back vanilla's ribbons.
      ""
   }};
}};
""")
        wep.append(f"""class PTF_Uniform_Dress_USMC_A_{ab} : PTF_Uniform_Dress_USMC_A_Base
{{
   scope = 2;
   displayName = "[Dress] Service A - {s['name']} [PTF]";
   picture = "\\z\\PTF\\addons\\PTF_Dress\\ui\\ptf_dress_icon_{low}_ca.paa";
   class ItemInfo : ItemInfo
   {{
      uniformClass = "PTF_Dress_USMC_A_{ab}_Unit";
   }};
}};
""")
    header = "// GENERATED by tools/generate-dress-uniforms.py - do not edit by hand.\n"
    (ADDON / "cfgRankVehicles.hpp").write_text(header + "\n".join(veh), newline="\n")
    (ADDON / "cfgRankUniforms.hpp").write_text(header + "\n".join(wep), newline="\n")


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--ranks", nargs="*", default=list(RANKS), choices=list(RANKS))
    args = ap.parse_args()

    DATA.mkdir(parents=True, exist_ok=True)
    # Everything in data/ is generated, so a full run clears it and a removed rank
    # can't leave an orphan. A partial run is for iterating and keeps the rest.
    if set(args.ranks) == set(RANKS):
        for old in DATA.glob("ptf_dress_*"):
            old.unlink()

    dt = data_path("ptf_dress_wool_dt.paa")
    with tempfile.TemporaryDirectory() as t:
        tools = Tools(Path(t))
        print("Base sheet...")
        base, base_normals, base_spec = build_base(tools)
        print("Shared textures:")
        tools.save(base_normals, "ptf_dress_usmc_nohq")
        tools.save(build_detail(), "ptf_dress_wool_dt")

        decor, decor_n, decor_s = build_decor(tools)
        tools.save(decor, "ptf_dress_usmc_decor_co")
        tools.save(decor_n, "ptf_dress_usmc_decor_nohq")
        tools.save(decor_s, "ptf_dress_usmc_decor_smdi")
        (DATA / "ptf_dress_usmc_decor.rvmat").write_text(rvmat(
            "#(argb,8,8,3)color(1,0.1,0.1,0.12,TI)", data_path("ptf_dress_usmc_decor_nohq.paa"), dt,
            data_path("ptf_dress_usmc_decor_smdi.paa"), dt_tile=4, power=120), newline="\n")

        cap_colours, cap_normals, cap_spec = build_caps(tools)
        for suffix, img in cap_colours.items():
            tools.save(img, f"ptf_dress_usmc_cover{suffix}_co")
        tools.save(cap_spec, "ptf_dress_usmc_cover_smdi")
        for suffix, img in cap_normals.items():
            tools.save(img, f"ptf_dress_usmc_cover{suffix}_nohq")
            (DATA / f"ptf_dress_usmc_cover{suffix}.rvmat").write_text(rvmat(
                r"a3\characters_f_aow\headgear\data\paradedresscap_01_ti_ca.paa", data_path(f"ptf_dress_usmc_cover{suffix}_nohq.paa"), dt,
                data_path("ptf_dress_usmc_cover_smdi.paa"), dt_tile=4, power=120, env=r"a3\data_f\env_land_co.paa"), newline="\n")

        tools.save(build_suitpack(tools), "ptf_dress_usmc_suitpack_co")
        print("Award ribbons:")
        build_award_ribbons(tools)

        print("Ranks:")
        for ab in args.ranks:
            low = ab.lower()
            sheet, spec = apply_rank(base, base_spec, RANKS[ab])
            tools.save(sheet, f"ptf_dress_usmc_a_{low}_co")
            tools.save(spec, f"ptf_dress_usmc_a_{low}_smdi")
            (DATA / f"ptf_dress_usmc_a_{low}.rvmat").write_text(rvmat(
                r"a3\characters_f_aow\uniforms\data\paradeuniform_01_ti_ca.paa", data_path("ptf_dress_usmc_nohq.paa"), dt,
                data_path(f"ptf_dress_usmc_a_{low}_smdi.paa"), dt_tile=8), newline="\n")
    write_config(list(RANKS))


if __name__ == "__main__":
    main()
