#!/usr/bin/env python3
"""Colours each mip level of the GySgt sheet differently, to show which one the game draws.

Each level is converted on its own and its top level spliced into one PAA. Run
tools/review-dress-uniforms.py afterwards, then rerun tools/generate-dress-uniforms.py to restore
the real texture. 4096 red, 2048 green, 1024 blue, 512 yellow, 256 magenta, 128 cyan, 64 white,
and black below that.
"""
import struct
import subprocess
import tempfile
from pathlib import Path

from PIL import Image

DATA = Path(__file__).resolve().parents[2] / "addons" / "PTF_Dress" / "data"
TOOL = r"C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\ImageToPAA\ImageToPAA.exe"
COLOURS = {4096: (200, 0, 0), 2048: (0, 200, 0), 1024: (0, 0, 200), 512: (200, 200, 0),
           256: (200, 0, 200), 128: (0, 200, 200), 64: (200, 200, 200)}
NAME = "ptf_dress_usmc_a_gysgt_co"


def split(data: bytes):
    """A PAA's header, the offsets table's position, its mip entries, and whatever follows."""
    i, offsets_at = 2, None
    while data[i:i + 4] == b"GGAT":
        size = int.from_bytes(data[i + 8:i + 12], "little")
        if data[i + 4:i + 8] == b"SFFO":
            offsets_at = i + 12
        i += 12 + size
    i += 2 + 3 * int.from_bytes(data[i:i + 2], "little")
    header, mips = data[:i], []
    while (w := int.from_bytes(data[i:i + 2], "little")) != 0:
        size = int.from_bytes(data[i + 4:i + 7], "little")
        mips.append((w & 0x7FFF, data[i:i + 7 + size]))
        i += 7 + size
    return header, offsets_at, mips, data[i:]


with tempfile.TemporaryDirectory() as t:
    def convert(colour, size):
        png, paa = Path(t) / (NAME + ".png"), Path(t) / (NAME + ".paa")
        Image.new("RGB", (size, size), colour).save(png)
        subprocess.run([TOOL, str(png), str(paa)], check=True, capture_output=True)
        return paa.read_bytes()

    header, offsets_at, mips, tail = split(convert(COLOURS[4096], 4096))
    out = bytearray(header)
    entries = [mips[0][1]]
    for w, entry in mips[1:]:
        entries.append(split(convert(COLOURS.get(w, (0, 0, 0)), w))[2][0][1] if w >= 4 else entry)
    at = len(out)
    for k, entry in enumerate(entries):
        struct.pack_into("<I", out, offsets_at + 4 * k, at)
        at += len(entry)
    (DATA / (NAME + ".paa")).write_bytes(bytes(out) + b"".join(entries) + tail)
print("levels", [m[0] for m in mips])
