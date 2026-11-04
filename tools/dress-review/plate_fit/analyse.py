#!/usr/bin/env python3
"""Reports how much of the rack plate stays visible at each angle and depth.

Reads the plate_fit mission's screenshots. For each angle, 100% is the count at the shallowest
depth, where the plate is clear of the chest. The best fit is the angle reaching the greatest
depth with the rack still whole.

Moving the plate away from the camera shrinks it, so counts are corrected for that distance.
"""
import re
from collections import defaultdict
from pathlib import Path

import numpy as np
from PIL import Image

SHOTS = Path(__file__).resolve().parents[3] / ".hemttout" / "dress-review" / "shots"
WHOLE = 0.98
CAMERA_M = 0.9


def ribbon_pixels(path: Path) -> int:
    a = np.asarray(Image.open(path).convert("RGB"), int)
    high, low = a.max(axis=2), a.min(axis=2)
    return int(((high - low > 90) & (high > 70)).sum())


grid = defaultdict(dict)
for f in SHOTS.glob("fit_*.png"):
    m = re.fullmatch(r"fit_(-?\d+)_(-?\d+)_(\d+)", f.stem)
    if m:
        grid[(int(m[1]), int(m[2]))][int(m[3]) - 100] = ribbon_pixels(f)

results = []
for (yaw, tilt), counts in sorted(grid.items()):
    depths = sorted(counts)
    base = max(counts[depths[0]], 1)
    row = {d: counts[d] / base * ((CAMERA_M + d / 1000) / (CAMERA_M + depths[0] / 1000)) ** 2 for d in depths}
    # Deepest depth reached before the rack first starts to bury.
    best = None
    for d in depths:
        if row[d] < WHOLE:
            break
        best = d
    results.append((best if best is not None else -999, yaw, tilt))
    print(f"yaw {yaw:4d} tilt {tilt:3d} whole to {best!s:>5} mm | "
          + " ".join(f"{d}:{row[d] * 100:3.0f}" for d in depths))
results.sort(reverse=True)
print("best:", results[:3])
