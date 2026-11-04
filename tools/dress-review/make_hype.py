#!/usr/bin/env python3
"""Grades the staged formation shots and adds PTF branding, for sharing with the unit.

Needs the hype mission's screenshots, and the ptf-website checkout beside this repo for the logos.

Usage:  python tools/dress-review/make_hype.py [source folder] [output folder]
"""
import sys
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFilter, ImageFont

REPO = Path(__file__).resolve().parents[2]
SRC = Path(sys.argv[1]) if len(sys.argv) > 1 else REPO / ".hemttout" / "dress-review" / "shots"
OUT = Path(sys.argv[2]) if len(sys.argv) > 2 else REPO / "releases"
BRAND = Path(r"C:\Users\mpadd\Documents\GitHub\ptf-website\public\brand")
FONTS = Path(r"C:\Windows\Fonts")
GOLD = (232, 190, 110)
WHITE = (250, 247, 240)


def sky_mask(a):
    """The sky, keyed from the magenta walls the hype mission puts behind the base."""
    # Distance haze washes the walls out to pale pink, so this goes by the ratio of green to
    # red and blue, and only among bright pixels, which keeps dark tinted cloth out of it.
    low = np.minimum(a[..., 0], a[..., 2])
    ratio = (low - a[..., 1]) / np.maximum(low, 0.01)
    return (np.clip((ratio - 0.14) / 0.12, 0, 1) * np.clip((low - 0.42) / 0.14, 0, 1))[..., None]


def clouds(shape):
    """Long, soft streaks of cloud for the painted sky, averaging 1."""
    h, w = shape
    rng = np.random.default_rng(11)
    out = np.zeros((h, w))
    # More rows than columns, stretched to the frame: long horizontal bands.
    for size, weight in (((9, 3), 1.0), ((22, 6), 0.5), ((60, 14), 0.25)):
        n = Image.fromarray(((rng.random(size) * 255)).astype("uint8")).resize((w, h), Image.BICUBIC)
        out += (np.asarray(n, float) / 255 - 0.5) * weight
    return 1 + np.clip(out, -0.8, 0.8) * 0.16


def grade(img, sun_xy, fill_top=False, horizon=0.72):
    """Dusk sky behind the figures, deeper contrast and richer colour on everything else."""
    a = np.asarray(img.convert("RGB"), float) / 255
    h, w = a.shape[:2]
    yy, xx = np.mgrid[:h, :w]
    mask = sky_mask(a)
    # Takes the walls' magenta cast back out of the figures, whatever is still pinker than it
    # is green. Reds and blues have no cast to remove: one of the two is below the green.
    cast = np.clip(np.minimum(a[..., 0], a[..., 2]) - a[..., 1], 0, 1)[..., None]
    a = a - cast * np.array([1, 0, 1])
    # The walls also redden the dark cloth facing them. It is olive, so red comes back down to
    # the green. Bright or strongly red things, like skin, insignia and flags, are left alone.
    lum = a.mean(axis=2, keepdims=True)
    red = np.clip(a[..., 0:1] - a[..., 1:2], 0, 1)
    dark = np.clip((0.42 - lum) / 0.12, 0, 1) * np.clip(1 - red / np.maximum(lum, 0.02) / 0.9, 0, 1)
    a = a - red * dark * np.array([0.82, 0, 0])
    # Fills the sliver of real sky above the walls, at the very top of a tilted-up frame.
    if fill_top:
        top = np.zeros(mask.shape)
        top[:70] = 1
        mask = np.maximum(mask, top * (a.mean(axis=2, keepdims=True) > 0.55))

    # Figures and ground: S-curve and saturation, keeping the cloth green.
    b = a * a * (3 - 2 * a) * 0.65 + a * 0.35
    lum = b.mean(axis=2, keepdims=True)
    b = lum + (b - lum) * 1.3
    b *= 1 + np.array([0.035, 0.015, -0.04]) * np.clip(lum * 1.5, 0, 1)
    b *= 1 - 0.1 * np.clip(0.5 - lum, 0, 0.5)

    # Sky: deep blue overhead, through violet, to burning orange at the horizon.
    stops = [(0.0, (16, 26, 58)), (0.3, (42, 44, 92)), (0.55, (128, 66, 96)), (0.8, (232, 122, 62)), (1.0, (255, 190, 104))]
    pos = np.clip(yy / (h * horizon), 0, 1)
    sky = np.stack([np.interp(pos, [s[0] for s in stops], [s[1][c] for s in stops]) for c in range(3)], axis=2) / 255
    sky = np.clip(sky * clouds((h, w))[..., None], 0, 1)
    out = b * (1 - mask) + sky * mask

    # Sun glow, screened in low near the horizon.
    d = np.hypot((xx - sun_xy[0]) / w, (yy - sun_xy[1]) / w)
    glow = np.exp(-(d / 0.3) ** 2)[..., None] * np.array([0.34, 0.17, 0.05])
    out = 1 - (1 - np.clip(out, 0, 1)) * (1 - glow)
    # Rim light on the figures against the sky, by brightening what borders it.
    edge = np.asarray(Image.fromarray((mask[..., 0] * 255).astype("uint8")).filter(ImageFilter.GaussianBlur(5)), float)[..., None] / 255
    rim = np.clip(edge * (1 - mask) * 1.8, 0, 1) * np.array([0.34, 0.2, 0.08])
    out = 1 - (1 - np.clip(out, 0, 1)) * (1 - rim)
    # Vignette.
    v = np.hypot((xx - w / 2) / (w / 2), (yy - h / 2) / (h / 2))
    out *= (1 - 0.4 * np.clip(v - 0.6, 0, 1) ** 1.5)[..., None]

    result = Image.fromarray((np.clip(out, 0, 1) * 255).astype("uint8"))
    result = result.filter(ImageFilter.UnsharpMask(radius=2.2, percent=70, threshold=2))
    g = np.random.default_rng(7).normal(0, 2.6, (h, w, 1))
    return Image.fromarray(np.clip(np.asarray(result, float) + g, 0, 255).astype("uint8")).convert("RGBA")


def spaced(draw, xy, text, font, fill, spacing, anchor_right=False):
    width = sum(draw.textlength(c, font=font) + spacing for c in text) - spacing
    x, y = xy
    if anchor_right:
        x -= width
    for c in text:
        draw.text((x, y), c, font=font, fill=fill)
        x += draw.textlength(c, font=font) + spacing
    return width


def shadowed(base, painter, blur=14, opacity=190):
    """Paint onto a layer, then composite it over its own soft dark shadow."""
    layer = Image.new("RGBA", base.size, (0, 0, 0, 0))
    painter(layer)
    alpha = layer.getchannel("A").filter(ImageFilter.GaussianBlur(blur)).point(lambda v: min(255, v * opacity // 100))
    shadow = Image.new("RGBA", base.size, (0, 0, 0, 0))
    shadow.putalpha(alpha)
    base.alpha_composite(shadow)
    base.alpha_composite(layer)


def logo(name, width):
    im = Image.open(BRAND / name).convert("RGBA")
    return im.resize((width, int(im.height * width / im.width)), Image.LANCZOS)


def rule(draw, x0, x1, y, thick=7):
    draw.rectangle([x0, y, x1, y + thick], fill=GOLD + (255,))


HEAD = FONTS / "impact.ttf"
SUB = FONTS / "bahnschrift.ttf"
MOTTO = "IMPROVISE. ADAPT. OVERCOME."


def formation(img):
    def paint(l):
        d = ImageDraw.Draw(l)
        m = logo("ptf-logo-horizontal-reversed-800w.png", 800)
        l.alpha_composite(m, (80, 70))
        d.text((80, 300), "SERVICE ALPHA", font=ImageFont.truetype(str(HEAD), 142), fill=WHITE + (255,))
        rule(d, 84, 790, 475)
        spaced(d, (84, 500), MOTTO, ImageFont.truetype(str(SUB), 40), GOLD + (255,), 3.5)
    shadowed(img, paint)


def commander(img):
    def paint(l):
        d = ImageDraw.Draw(l)
        l.alpha_composite(logo("ptf-emblem-652w.png", 215), (90, 75))
        d.text((335, 70), "EARN", font=ImageFont.truetype(str(HEAD), 118), fill=WHITE + (255,))
        d.text((335, 190), "THE ALPHAS", font=ImageFont.truetype(str(HEAD), 118), fill=GOLD + (255,))
        spaced(d, (340, 325), "PARAMARINE TASK FORCE", ImageFont.truetype(str(SUB), 34), WHITE + (255,), 6)
    shadowed(img, paint)


def hills(img):
    w = img.width

    def paint(l):
        d = ImageDraw.Draw(l)
        d.text((w - 85, 85), "25 RANKS.", font=ImageFont.truetype(str(HEAD), 128), fill=WHITE + (255,), anchor="ra")
        d.text((w - 85, 215), "ONE STANDARD.", font=ImageFont.truetype(str(HEAD), 128), fill=GOLD + (255,), anchor="ra")
        rule(d, w - 745, w - 90, 368)
        m = logo("ptf-logo-horizontal-reversed-800w.png", 470)
        l.alpha_composite(m, (w - 85 - m.width, 395))
    shadowed(img, paint)


def ranks(img):
    w, h = img.size

    def paint(l):
        d = ImageDraw.Draw(l)
        m = logo("ptf-logo-horizontal-reversed-800w.png", 620)
        l.alpha_composite(m, (800, 40))
        spaced(d, (805, 212), MOTTO, ImageFont.truetype(str(SUB), 34), GOLD + (255,), 3)
    shadowed(img, paint)


# Name, output, overlay, sun position in pixels, and whether real sky shows above the walls.
SHOTS = [
    ("hype_c_low", "PTF_Dress_hype_1_formation", formation, (1500, 900), False),
    ("hype_c_lower", "PTF_Dress_hype_2_earn_the_alphas", commander, (500, 1000), True),
    ("hype_c_left", "PTF_Dress_hype_3_one_standard", hills, (2100, 1000), False),
    ("hype_c_rank", "PTF_Dress_hype_4_ranks", ranks, (1400, 900), False),
]


def main():
    for src, dst, overlay, sun, fill_top in SHOTS:
        img = grade(Image.open(SRC / f"{src}.png"), sun, fill_top)
        overlay(img)
        img.convert("RGB").save(OUT / f"{dst}.jpg", quality=95)
        print(dst, img.size)


if __name__ == "__main__":
    main()
