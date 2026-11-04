#!/usr/bin/env python3
"""Cut the insignia artwork for PTF_Dress out of MCO 1020.34H.

Run once against the order's PDF. The PNGs it writes are committed, so the texture
generator does not need the PDF.

Usage:  uv run --no-project --with pymupdf --with pillow --with numpy \\
            python tools/dress-assets/extract.py "path/to/MCO 1020.34H v2.pdf"
"""
import io
import sys
from pathlib import Path

import numpy as np
import pymupdf
from PIL import Image, ImageFilter

OUT = Path(__file__).resolve().parent

# PDF image ids, read from the order: the title page seal, figure 4-12's colonel
# and lieutenant colonel/major insignia, and figure 3-2's cap components.
SEAL, EAGLE, OAK_SILVER, OAK_GOLD, CAP_FIGURE = 14720, 312, 314, 315, 139


def load(doc, xref):
    return Image.open(io.BytesIO(doc.extract_image(xref)["image"])).convert("RGB")


def key_white(img, soft=(18, 60)):
    """Alpha from distance to a white background, trimmed to its bounding box."""
    a = np.asarray(img, float)
    dist = 255 - a.min(axis=2)
    alpha = np.clip((dist - soft[0]) / (soft[1] - soft[0]), 0, 1) * 255
    out = Image.fromarray(np.dstack([a, alpha]).astype("uint8"), "RGBA")
    return out.crop(out.getchannel("A").getbbox())


def ega(doc):
    """The emblem from the seal, minus the red field and the motto ribbon.

    Service insignia has no ribbon (para 4001).
    """
    a = np.asarray(load(doc, SEAL), float)[150:492, 178:486]
    r, g, b = a[..., 0], a[..., 1], a[..., 2]
    red = (r - g > 70) & (r - b > 40) & (g < 90)
    alpha = (~red).astype(float) * 255
    # The ribbon and its tail sit above and left of the eagle's head.
    alpha[:31, :] = 0
    alpha[:44, :130] = 0
    alpha[:37, 175:] = 0
    # Stray corners of the seal's inner ring.
    alpha[:60, :24] = 0
    alpha[:60, -24:] = 0
    alpha[-60:, :40] = 0
    alpha[-60:, -60:] = 0
    out = Image.fromarray(np.dstack([a, alpha]).astype("uint8"), "RGBA")
    # Clean the fringe left by the red field.
    arr = np.asarray(out).copy()
    arr[..., 3] = np.asarray(out.getchannel("A").filter(ImageFilter.MinFilter(3)))
    out = Image.fromarray(arr, "RGBA")
    return out.crop(out.getchannel("A").getbbox())


def visor_ornament(doc):
    """Gold oak sprays from the field grade visor, on transparency."""
    a = np.asarray(load(doc, CAP_FIGURE).crop((495, 50, 815, 222)), float)
    r, b = a[..., 0], a[..., 2]
    alpha = np.clip((r - b - 25) / 50, 0, 1) * np.clip((r - 50) / 40, 0, 1) * 255
    # The figure's mount shows at the top corners.
    alpha[:26, :44] = 0
    alpha[:26, -44:] = 0
    return Image.fromarray(np.dstack([a, alpha]).astype("uint8"), "RGBA")


def quatrefoil(doc):
    """The crown's braid as a greyscale cord pattern on transparency."""
    a = np.asarray(load(doc, CAP_FIGURE).crop((1015, 215, 1285, 470)).convert("L"), float)
    bg = np.median(a)
    alpha = np.clip((a - bg - 3) / 12, 0, 1) * 255
    tone = np.clip((a - bg) / max(a.max() - bg, 1), 0, 1) * 255
    return Image.fromarray(np.dstack([tone, tone, tone, alpha]).astype("uint8"), "RGBA")


doc = pymupdf.open(sys.argv[1])
ega(doc).save(OUT / "ega.png")
key_white(load(doc, EAGLE)).save(OUT / "eagle.png")
key_white(load(doc, OAK_SILVER)).save(OUT / "oak_silver.png")
key_white(load(doc, OAK_GOLD)).save(OUT / "oak_gold.png")
visor_ornament(doc).save(OUT / "visor_field.png")
quatrefoil(doc).save(OUT / "quatrefoil.png")
