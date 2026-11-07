#!/usr/bin/env python3
"""Grades the staged formation shots to a serious, period look and adds PTF branding, for sharing.

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
# Marine scarlet and gold, kept dull so they sit in the picture rather than on it.
GOLD = (196, 164, 102)
WHITE = (232, 228, 216)
SCARLET = (150, 30, 34)


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


def grade(img, fill_top=False, horizon=0.72):
    """A serious, period look: overcast slate sky, muted film colour and restrained highlights."""
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

    # The evening light's orange out, and the blown-out building brought down.
    b = np.clip(a * np.array([0.95, 0.98, 1.02]), 0, 1) ** 1.08
    b = b / (1 + 0.55 * b) * 1.3
    # Muted, with insignia reds holding on a little longer than everything else.
    lum = b.mean(axis=2, keepdims=True)
    redness = np.clip((b[..., 0:1] - b[..., 1:2]) / 0.25, 0, 1)
    b = lum + (b - lum) * (0.58 + redness * 0.3)
    # A gentle S-curve for weight, a little warmth in the lights and cold in the shadows.
    b = (b * b * (3 - 2 * b)) * 0.4 + b * 0.6
    lum = b.mean(axis=2, keepdims=True)
    b = b + (lum - 0.4) * np.array([0.035, 0.008, -0.04])
    # A touch of old print's sepia over everything.
    b = b * 0.86 + lum * np.array([1.04, 0.97, 0.84]) * 0.14

    # An overcast sky, heavy and slate overhead, lighter toward the horizon.
    stops = [(0.0, (42, 43, 46)), (0.45, (82, 81, 80)), (0.8, (134, 129, 118)), (1.0, (168, 158, 138))]
    pos = np.clip(yy / (h * horizon), 0, 1)
    sky = np.stack([np.interp(pos, [s[0] for s in stops], [s[1][c] for s in stops]) for c in range(3)], axis=2) / 255
    sky = np.clip(sky * (1 + (clouds((h, w))[..., None] - 1) * 1.6), 0, 1)
    out = b * (1 - mask) + sky * mask

    # A heavy vignette, as an old lens would give.
    v = np.hypot((xx - w / 2) / (w / 2), (yy - h / 2) / (h / 2))
    out *= (1 - 0.55 * np.clip(v - 0.45, 0, 1) ** 1.4)[..., None]

    result = Image.fromarray((np.clip(out, 0, 1) * 255).astype("uint8"))
    result = result.filter(ImageFilter.UnsharpMask(radius=2.0, percent=45, threshold=2))
    # Film grain, finer in the lights than the shadows.
    g = np.random.default_rng(7).normal(0, 1, (h, w, 1))
    level = np.asarray(result, float).mean(axis=2, keepdims=True) / 255
    return Image.fromarray(np.clip(np.asarray(result, float) + g * (4.2 - level * 2), 0, 255).astype("uint8")).convert("RGBA")


def spaced(draw, xy, text, font, fill, spacing, anchor_right=False):
    width = sum(draw.textlength(c, font=font) + spacing for c in text) - spacing
    x, y = xy
    if anchor_right:
        x -= width
    for c in text:
        draw.text((x, y), c, font=font, fill=fill)
        x += draw.textlength(c, font=font) + spacing
    return width


def shadowed(base, painter, blur=9, opacity=120):
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


def rule(draw, x0, x1, y, thick=5):
    draw.rectangle([x0, y, x1, y + thick], fill=SCARLET + (255,))


HEAD = FONTS / "COPRGTB.TTF"
SUB = FONTS / "COPRGTL.TTF"
MOTTO = "IMPROVISE. ADAPT. OVERCOME."


def formation(img):
    def paint(l):
        d = ImageDraw.Draw(l)
        m = logo("ptf-logo-horizontal-reversed-800w.png", 800)
        l.alpha_composite(m, (80, 70))
        d.text((84, 292), "SERVICE ALPHA", font=ImageFont.truetype(str(HEAD), 93), fill=WHITE + (255,))
        rule(d, 84, 940, 402)
        spaced(d, (84, 420), MOTTO, ImageFont.truetype(str(SUB), 40), GOLD + (255,), 3.5)
    shadowed(img, paint)


def formation_eye(img):
    """Smaller, to stay on the sky above the building in the eye-level shot."""
    def paint(l):
        d = ImageDraw.Draw(l)
        l.alpha_composite(logo("ptf-logo-horizontal-reversed-800w.png", 600), (70, 50))
        d.text((70, 215), "SERVICE ALPHA", font=ImageFont.truetype(str(HEAD), 68), fill=WHITE + (255,))
        rule(d, 74, 694, 298)
        spaced(d, (74, 314), MOTTO, ImageFont.truetype(str(SUB), 29), GOLD + (255,), 2.5)
    shadowed(img, paint)


def commander(img):
    def paint(l):
        d = ImageDraw.Draw(l)
        l.alpha_composite(logo("ptf-emblem-652w.png", 215), (90, 75))
        d.text((335, 70), "EARN", font=ImageFont.truetype(str(HEAD), 77), fill=WHITE + (255,))
        d.text((335, 160), "THE ALPHAS", font=ImageFont.truetype(str(HEAD), 77), fill=GOLD + (255,))
        spaced(d, (338, 262), "PARAMARINE TASK FORCE", ImageFont.truetype(str(SUB), 34), WHITE + (255,), 6)
    shadowed(img, paint)


def hills(img):
    w = img.width

    def paint(l):
        d = ImageDraw.Draw(l)
        d.text((w - 85, 85), "25 RANKS.", font=ImageFont.truetype(str(HEAD), 84), fill=WHITE + (255,), anchor="ra")
        d.text((w - 85, 180), "ONE STANDARD.", font=ImageFont.truetype(str(HEAD), 84), fill=GOLD + (255,), anchor="ra")
        rule(d, w - 876, w - 85, 282)
        m = logo("ptf-logo-horizontal-reversed-800w.png", 470)
        l.alpha_composite(m, (w - 85 - m.width, 305))
    shadowed(img, paint)


def ranks(img):
    w, h = img.size

    def paint(l):
        d = ImageDraw.Draw(l)
        m = logo("ptf-logo-horizontal-reversed-800w.png", 620)
        l.alpha_composite(m, (800, 40))
        spaced(d, (805, 212), MOTTO, ImageFont.truetype(str(SUB), 34), GOLD + (255,), 3)
    shadowed(img, paint)


def drill_left(img):
    """The drill instructor out in front, with the sky clear to his right."""
    def paint(l):
        d = ImageDraw.Draw(l)
        l.alpha_composite(logo("ptf-emblem-652w.png", 190), (70, 60))
        d.text((285, 50), "IT STARTS", font=ImageFont.truetype(str(HEAD), 73), fill=WHITE + (255,))
        d.text((285, 132), "HERE.", font=ImageFont.truetype(str(HEAD), 73), fill=GOLD + (255,))
        spaced(d, (287, 228), "PARAMARINE TASK FORCE", ImageFont.truetype(str(SUB), 32), WHITE + (255,), 5)
    shadowed(img, paint)


def drill_right(img):
    """Nose to nose, with the sky clear at the top right."""
    w = img.width

    def paint(l):
        d = ImageDraw.Draw(l)
        d.text((w - 70, 50), "IT STARTS", font=ImageFont.truetype(str(HEAD), 73), fill=WHITE + (255,), anchor="ra")
        d.text((w - 70, 132), "HERE.", font=ImageFont.truetype(str(HEAD), 73), fill=GOLD + (255,), anchor="ra")
        m = logo("ptf-logo-horizontal-reversed-800w.png", 400)
        l.alpha_composite(m, (w - 70 - m.width, 225))
    shadowed(img, paint)


# Name, output, overlay, and whether real sky shows above the walls.
SHOTS = [
    ("hype_c_low", "PTF_Dress_hype_1_formation", formation, False),
    ("hype_c_lower", "PTF_Dress_hype_2_earn_the_alphas", commander, True),
    ("hype_c_left", "PTF_Dress_hype_3_one_standard", hills, False),
    ("hype_c_rank", "PTF_Dress_hype_4_ranks", ranks, False),
    ("hype_di_portrait", "PTF_Dress_hype_5_it_starts_here", drill_left, False),
    ("hype_di_nose", "PTF_Dress_hype_6_nose_to_nose", drill_right, False),
    ("hype_c_eye", "PTF_Dress_hype_7_eye_level", formation_eye, False),
]


def main():
    for src, dst, overlay, fill_top in SHOTS:
        img = grade(Image.open(SRC / f"{src}.png"), fill_top)
        overlay(img)
        img.convert("RGB").save(OUT / f"{dst}.jpg", quality=95)
        print(dst, img.size)


if __name__ == "__main__":
    main()
