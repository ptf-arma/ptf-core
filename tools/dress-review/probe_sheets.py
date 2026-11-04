#!/usr/bin/env python3
"""Overwrite the Sgt, decor and cap textures with labelled UV grids.

Run the review afterwards to read sheet coordinates straight off the model, then
rerun tools/generate-dress-uniforms.py to restore the real textures.
"""
import subprocess
from pathlib import Path

from PIL import Image, ImageDraw, ImageFont

REPO = Path(__file__).resolve().parents[2]
DATA = REPO / "addons" / "PTF_Dress" / "data"
TOOL = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\ImageToPAA\ImageToPAA.exe")


def grid(w, h, step, font_size, alpha=False):
    img = Image.new("RGBA", (w, h), (200, 200, 200, 255))
    d = ImageDraw.Draw(img)
    font = ImageFont.truetype("arial.ttf", font_size)
    for y in range(0, h, step):
        for x in range(0, w, step):
            col = (235, 235, 90, 255) if ((x // step) + (y // step)) % 2 else (90, 170, 235, 255)
            d.rectangle([x, y, x + step, y + step], fill=col, outline=(0, 0, 0, 255), width=2)
            d.text((x + 4, y + 2), f"{x},{y}", fill=(0, 0, 0, 255), font=font)
    return img


def save(img, name):
    png = DATA / (name + ".png")
    img.save(png)
    subprocess.run([str(TOOL), str(png), str(DATA / (name + ".paa"))], check=True, capture_output=True)
    png.unlink()


save(grid(2048, 2048, 64, 15), "ptf_dress_usmc_a_sgt_co")
save(grid(1024, 512, 64, 15), "ptf_dress_usmc_decor_co")
save(grid(1024, 1024, 64, 15), "ptf_dress_usmc_cover_co")
