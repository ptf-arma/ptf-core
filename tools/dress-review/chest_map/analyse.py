#!/usr/bin/env python3
"""Turns the chest_map mission's shots into a height map of the chest.

Each pixel's surface is the deepest sheet position at which it still shows the sheet's colour.
The sheet's visible edges in the shallowest shot give the scale from pixels to metres. Writes
tools/dress-assets/chest_map.npz and a picture of the result for checking by eye.

Usage:  python tools/dress-review/chest_map/analyse.py <sheet size m> <centre x> <centre z>
"""
import sys
from pathlib import Path

import numpy as np
from PIL import Image

REPO = Path(__file__).resolve().parents[3]
SHOTS = REPO / ".hemttout" / "dress-review" / "shots"
OUT = REPO / "tools" / "dress-assets" / "chest_map.npz"

size, cx, cz = (float(v) for v in sys.argv[1:4])
files = sorted(SHOTS.glob("map_*.png"), key=lambda f: -int(f.stem.split("_")[1]))
print(len(files), "shots")
surface = None
for f in files:
    y = int(f.stem.split("_")[1]) / 10000
    a = np.asarray(Image.open(f).convert("RGB"), int)
    sheet = (a[..., 0] > a[..., 1] + 60) & (a[..., 2] > a[..., 1] + 60)
    if surface is None:
        surface = np.full(sheet.shape, np.nan)
        ys, xs = np.where(sheet)
        x0, x1, y0, y1 = xs.min(), xs.max(), ys.min(), ys.max()
        print("first shot", f.stem, "sheet px", x0, x1, y0, y1, "share", round(float(sheet.mean()), 3))
    surface[sheet] = y

# Pixel to the unit's coordinates. The wearer's left is -x, on the image's right side.
scale = size / (x1 - x0)
print("mm per pixel", round(scale * 1000, 3))
crop = surface[y0:y1, x0:x1]
xs = cx + (np.arange(crop.shape[1]) - crop.shape[1] / 2) * scale * -1
zs = cz - (np.arange(crop.shape[0]) - crop.shape[0] / 2) * scale
np.savez_compressed(OUT, surface=crop.astype("float32"), xs=xs.astype("float32"), zs=zs.astype("float32"))

lo, hi = np.nanmin(crop), np.nanmax(crop)
print("surface y from", round(float(lo), 4), "to", round(float(hi), 4), "unset share", round(float(np.isnan(crop).mean()), 3))
view = np.nan_to_num((crop - lo) / (hi - lo)) * 255
Image.fromarray(view.astype("uint8")).save(SHOTS.parent / "chest_map.png")

# Samples over where a rack would go, for a sanity check.
for z in (1.43, 1.41, 1.39, 1.37):
    row = np.abs(zs - z).argmin()
    print(f"z {z}: " + " ".join(f"{x:.2f}:{crop[row, np.abs(xs - x).argmin()]:.3f}" for x in (-0.17, -0.15, -0.13, -0.11, -0.09, -0.07, -0.05)))
