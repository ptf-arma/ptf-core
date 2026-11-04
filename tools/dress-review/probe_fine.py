#!/usr/bin/env python3
"""Overwrite the Sgt sheet with a fine labelled grid over chosen zones, in 2048 coordinates.

For reading exact positions of small parts off the model. Rerun
tools/generate-dress-uniforms.py afterwards to restore the real texture.

Usage:  python tools/dress-review/probe_fine.py x0 y0 x1 y1 [x0 y0 x1 y1 ...]
"""
import subprocess
import sys
import tempfile
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont

DATA = Path(__file__).resolve().parents[2] / "addons" / "PTF_Dress" / "data"
TOOL = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\ImageToPAA\ImageToPAA.exe")
STEP, K = 20, 2

nums = [int(v) for v in sys.argv[1:]]
img = Image.new("RGB", (4096, 4096), (70, 70, 70))
d = ImageDraw.Draw(img)
font = ImageFont.truetype("arial.ttf", 11)
for z in range(0, len(nums), 4):
    x0, y0, x1, y1 = nums[z:z + 4]
    for y in range(y0, y1, STEP):
        for x in range(x0, x1, STEP):
            col = (235, 235, 90) if ((x // STEP) + (y // STEP)) % 2 else (90, 170, 235)
            d.rectangle([x * K, y * K, (x + STEP) * K, (y + STEP) * K], fill=col, outline=(0, 0, 0))
            d.text((x * K + 2, y * K + 1), f"{x}", fill=(0, 0, 0), font=font)
            d.text((x * K + 2, y * K + 14), f"{y}", fill=(180, 0, 0), font=font)
with tempfile.TemporaryDirectory() as t:
    png = Path(t) / "probe.png"
    img.save(png)
    subprocess.run([str(TOOL), str(png), str(DATA / "ptf_dress_usmc_a_sgt_co.paa")], check=True, capture_output=True)
