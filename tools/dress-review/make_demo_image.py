#!/usr/bin/env python3
"""Turn the --demo screenshot into the shareable image: crop and label only.

Nothing is painted over the render, so it shows what players will see in game.

Usage:  python tools/dress-review/make_demo_image.py <output.png>
"""
import sys
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont

SHOTS = Path(__file__).resolve().parents[2] / ".hemttout" / "dress-review" / "shots"

# Left to right, and each figure's centre as a fraction of the screenshot's width.
LINEUP = [
    (0.090, "LCpl", "Attention"),
    (0.192, "Sgt", "Parade rest"),
    (0.285, "GySgt", "Saluting"),
    (0.397, "HM2 (Corpsman)", "Attention"),
    (0.497, "CWO3", "Parade rest"),
    (0.605, "2ndLt", "Uncovered"),
    (0.705, "Capt", "Saluting"),
    (0.815, "Maj", "Parade rest"),
    (0.922, "Col", "Attention"),
]

img = Image.open(SHOTS / "demo_wide.png").convert("RGB")
w, h = img.size
img = img.crop((0, int(h * 0.27), w, int(h * 0.72)))
w, h = img.size

band = int(w * 0.075)
out = Image.new("RGB", (w, h + band), (24, 27, 20))
out.paste(img, (0, 0))
d = ImageDraw.Draw(out)
name_font = ImageFont.truetype("arialbd.ttf", int(band * 0.20))
note_font = ImageFont.truetype("arial.ttf", int(band * 0.16))
title_font = ImageFont.truetype("arialbd.ttf", int(band * 0.19))
for x, name, note in LINEUP:
    d.text((x * w, h + band * 0.30), name, font=name_font, fill=(235, 228, 205), anchor="mm")
    d.text((x * w, h + band * 0.52), note, font=note_font, fill=(170, 166, 145), anchor="mm")
d.text((w / 2, h + band * 0.82), 'PTF Core: USMC Service "A" uniforms. In-game screenshot.',
       font=title_font, fill=(210, 204, 180), anchor="mm")
out.save(sys.argv[1])
print(out.size, sys.argv[1])
