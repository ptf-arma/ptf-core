#!/usr/bin/env python3
"""Download PTF's award catalogue and ribbon art from Billet's public API.

Writes tools/dress-assets/ribbons/<award id>.png and ribbons.json, which
tools/generate-dress-uniforms.py turns into the tiles a rack is drawn from. Rerun
when an award is added or its art changes, then rerun the generator.

Usage:  python tools/fetch-dress-ribbons.py
"""
import json
import urllib.request
from io import BytesIO
from pathlib import Path

from PIL import Image

API = "https://billet.paramarines.net/api/v1/units/ptf/awards"
OUT = Path(__file__).resolve().parent / "dress-assets" / "ribbons"
AGENT = {"User-Agent": "PTFDressUniformTool/1.0"}


def fetch(url: str) -> bytes:
    with urllib.request.urlopen(urllib.request.Request(url, headers=AGENT), timeout=30) as r:
        return r.read()


def main():
    OUT.mkdir(parents=True, exist_ok=True)
    for old in OUT.glob("*.png"):
        old.unlink()
    awards = json.loads(fetch(API))["awards"]
    catalogue = []
    for award in awards:
        entry = {"id": award["id"], "name": award["name"]}
        if award.get("imageUrl"):
            img = Image.open(BytesIO(fetch(award["imageUrl"]))).convert("RGB")
            img.save(OUT / f"{award['id']}.png")
            entry["size"] = img.size
        catalogue.append(entry)
    (OUT / "ribbons.json").write_text(json.dumps(catalogue, indent=2) + "\n", newline="\n")
    for entry in catalogue:
        print(entry.get("size"), entry["name"])


if __name__ == "__main__":
    main()
