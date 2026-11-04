#!/usr/bin/env python3
"""Tile review screenshots into one image per rank, for reading at a glance.

Usage:  python tools/dress-review/contact_sheet.py Sgt Capt
Writes .hemttout/dress-review/shots/sheet_<rank>.jpg
"""
import sys
from pathlib import Path

from PIL import Image, ImageDraw

SHOTS = Path(__file__).resolve().parents[2] / ".hemttout" / "dress-review" / "shots"
TILE = (560, 630)
COLS = 4

for rank in sys.argv[1:]:
    files = sorted(SHOTS.glob(f"{rank}_*.png"))
    if not files:
        print(f"no shots for {rank}")
        continue
    rows = (len(files) + COLS - 1) // COLS
    sheet = Image.new("RGB", (COLS * TILE[0], rows * TILE[1]), (15, 15, 15))
    draw = ImageDraw.Draw(sheet)
    for i, f in enumerate(files):
        im = Image.open(f).convert("RGB")
        w, h = im.size
        # Crop the centre to the tile's shape, which is where the subject is.
        cw = int(h * TILE[0] / TILE[1])
        im = im.crop(((w - cw) // 2, 0, (w + cw) // 2, h)).resize(TILE, Image.LANCZOS)
        x, y = (i % COLS) * TILE[0], (i // COLS) * TILE[1]
        sheet.paste(im, (x, y))
        draw.text((x + 6, y + 4), f.stem, fill=(255, 255, 0))
    out = SHOTS / f"sheet_{rank}.jpg"
    sheet.save(out, quality=90)
    print(out)
