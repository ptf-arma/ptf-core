#!/usr/bin/env python3
"""Turn the --icons screenshots into Arsenal icons for PTF_Dress.

Keys out the magenta wall, crops each uniform to the coat and writes 128 px PAAs to
addons/PTF_Dress/ui. Cap icons are a tight crop of the head, from one rank per cap.

Usage:  python tools/review-dress-uniforms.py --icons --cap --ranks <all ranks>
        python tools/dress-review/make_icons.py
"""
import subprocess
import tempfile
from pathlib import Path

import numpy as np
from PIL import Image, ImageFilter

REPO = Path(__file__).resolve().parents[2]
SHOTS = REPO / ".hemttout" / "dress-review" / "shots"
UI = REPO / "addons" / "PTF_Dress" / "ui"
TOOL = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\ImageToPAA\ImageToPAA.exe")
SIZE = 128
# Which rank's shot supplies each cap's icon.
CAPS = {"cover": "GySgt", "cover_officer": "Capt", "cover_field": "Maj"}


def cut_out(shot: Path):
    """Return the figure as RGBA, and its bounding box."""
    a = np.asarray(Image.open(shot).convert("RGB"), float)
    r, g, b = a[..., 0], a[..., 1], a[..., 2]
    wall = (g < np.minimum(r, b) * 0.62) & (np.minimum(r, b) > 60) & (np.abs(r - b) < 70)
    # The figure is whatever connects to the frame's centre column and is not the wall
    # or the ground: the ground below the wall's edge is cropped away later anyway.
    alpha = np.asarray(Image.fromarray(~wall).filter(ImageFilter.MinFilter(3)), float) * 255
    alpha = np.asarray(Image.fromarray(alpha.astype("uint8")).filter(ImageFilter.GaussianBlur(0.8)), float)
    rgba = np.dstack([a, alpha])
    h, w = wall.shape
    # Search only where the wall surrounds the figure: above the wall's lower edge.
    probe = wall[:, w // 2 - 500:w // 2 + 500]
    rows = np.where(probe.mean(axis=1) > 0.25)[0]
    top_wall, bottom_wall = rows[0], rows[-1]
    figure = ~wall[top_wall:bottom_wall, :]
    cols = np.where(figure[:, w // 2 - 500:w // 2 + 500].any(axis=0))[0] + w // 2 - 500
    fig_rows = np.where(figure[:, cols[0]:cols[-1]].any(axis=1))[0] + top_wall
    return rgba, (cols[0], fig_rows[0], cols[-1], bottom_wall)


def save(rgba: np.ndarray, box, name: str, tmp: Path):
    x0, y0, x1, y1 = box
    side = max(x1 - x0, y1 - y0)
    cx, cy = (x0 + x1) // 2, (y0 + y1) // 2
    crop = Image.fromarray(np.clip(rgba, 0, 255).astype("uint8"), "RGBA").crop(
        (cx - side // 2, cy - side // 2, cx - side // 2 + side, cy - side // 2 + side))
    icon = crop.resize((SIZE, SIZE), Image.LANCZOS)
    png = tmp / f"ptf_dress_icon_{name}_ca.png"
    icon.save(png)
    subprocess.run([str(TOOL), str(png), str(UI / png.with_suffix(".paa").name)], check=True, capture_output=True)
    return icon


def main():
    UI.mkdir(exist_ok=True)
    sheet = []
    with tempfile.TemporaryDirectory() as t:
        tmp = Path(t)
        for shot in sorted(SHOTS.glob("icon_*.png")):
            rank = shot.stem.removeprefix("icon_")
            rgba, (x0, y0, x1, y1) = cut_out(shot)
            height = int((y1 - y0) / 0.62)  # the wall's edge cuts the figure at about the thighs
            # Collar to mid-thigh.
            top = y0 + int(height * 0.14)
            sheet.append(save(rgba, (x0, top, x1, min(top + int(height * 0.42), y1)), rank.lower(), tmp))
            for cap, source in CAPS.items():
                if source == rank:
                    head = int(height * 0.17)
                    mid = (x0 + x1) // 2 + int(np.where(rgba[y0 + head // 2, x0:x1, 3] > 128)[0].mean()) - (x1 - x0) // 2
                    sheet.append(save(rgba, (mid - head // 2, y0 - 8, mid + head // 2, y0 + head), cap, tmp))
    out = Image.new("RGB", (SIZE * 10, SIZE * (len(sheet) // 10 + 1)), (60, 60, 60))
    for i, icon in enumerate(sheet):
        out.paste(icon, ((i % 10) * SIZE, (i // 10) * SIZE), icon)
    out.save(SHOTS.parent / "icons_sheet.png")
    print(len(sheet), "icons")


if __name__ == "__main__":
    main()
