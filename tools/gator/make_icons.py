"""Draw the G/ATOR's map symbol for the Billet tablet: addons/PTF_GATOR/data/gator_nato_ca.paa.

A MIL-STD-2525 friendly equipment symbol for a radar, in the same style and proportions as
Arma's own NATO map markers (\\A3\\ui_f\\data\\map\\markers\\nato\\b_*.paa) that the tablet draws
groups with: 64 x 64, a 3 px black frame around a half-alpha white fill (the map tints the
fill with the side's colour), and the radar's dish in black. Drawn from scratch at four times
the size and scaled down, so its curves are smooth. Run after changing it:

    python tools/gator/make_icons.py
"""
import subprocess
import tempfile
from pathlib import Path

from PIL import Image, ImageDraw

REPO = Path(__file__).resolve().parents[2]
IMAGE_TO_PAA = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\ImageToPAA\ImageToPAA.exe")
OUT = REPO / "addons" / "PTF_GATOR" / "data" / "gator_nato_ca.paa"
S = 4  # supersampling


def symbol():
    size = 64 * S
    im = Image.new("RGBA", (size, size), (0, 0, 0, 0))
    d = ImageDraw.Draw(im)
    # The frame: the friendly rectangle, as Arma's own markers draw it.
    left, top, right, bottom = 3 * S, 14 * S, 61 * S - 1, 50 * S - 1
    d.rectangle([left, top, right, bottom], fill=(0, 0, 0, 255))
    d.rectangle([left + 3 * S, top + 3 * S, right - 3 * S, bottom - 3 * S], fill=(255, 255, 255, 128))
    # The radar: a dish opening up and to the right, its feed arm, and its mount.
    w = int(2.6 * S)
    ink = (0, 0, 0, 255)
    cx, cy, r = 33 * S, 29 * S, 9 * S
    # the bowl: the lower-left half of a circle (PIL angles run clockwise from 3 o'clock)
    d.arc([cx - r, cy - r, cx + r, cy + r], start=45, end=225, fill=ink, width=w)
    # the feed: from the bowl's centre out to the upper right, with its horn
    d.line([(cx, cy), (cx + 7 * S, cy - 7 * S)], fill=ink, width=w)
    d.ellipse([cx + 5 * S, cy - 9 * S, cx + 9 * S, cy - 5 * S], fill=ink)
    # the mount: from the bowl's lowest point down to a short base
    foot = (cx - 0.7071 * r, cy + 0.7071 * r)
    d.line([foot, (foot[0] - 2 * S, 43 * S)], fill=ink, width=w)
    d.line([(foot[0] - 7 * S, 43 * S), (foot[0] + 3 * S, 43 * S)], fill=ink, width=w)
    return im.resize((64, 64), Image.LANCZOS)


def main():
    OUT.parent.mkdir(parents=True, exist_ok=True)
    with tempfile.TemporaryDirectory() as tmp:
        png = Path(tmp) / "gator_nato_ca.png"
        symbol().save(png)
        subprocess.run([str(IMAGE_TO_PAA), str(png), str(OUT)], check=True, capture_output=True)
        symbol().resize((256, 256), Image.NEAREST).save(REPO / ".hemttout" / "gator_nato_preview.png")
    print(f"wrote {OUT}")


if __name__ == "__main__":
    main()
