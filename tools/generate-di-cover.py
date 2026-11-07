#!/usr/bin/env python3
"""Paint the campaign cover's colour and specular sheets from the model's own UV layout.

Reads addons/PTF_DICoverUSMC/DICover.p3d (an MLOD), works out which part of the sheet belongs to
which part of the hat, and writes the colour, specular and normal sheets. The ambient sheet is the
original bake and is left alone. The emblem's detail is tools/dress-assets/ega.png projected onto
the model's emblem from the front.

    python tools/generate-di-cover.py            # sheets into the addon
    python tools/generate-di-cover.py --png DIR  # also keep the PNGs, for inspection

Needs: Pillow + numpy, Arma 3 Tools (ImageToPAA).
"""
import argparse
import math
import shutil
import struct
import subprocess
import tempfile
from pathlib import Path

import numpy as np
from PIL import Image, ImageDraw, ImageFilter

REPO = Path(__file__).resolve().parent.parent
ADDON = REPO / "addons" / "PTF_DICoverUSMC"
IMAGE_TO_PAA = Path(r"C:\Program Files (x86)\Steam\steamapps\common\Arma 3 Tools\ImageToPAA\ImageToPAA.exe")
SIZE = 2048

# sRGB, before the shader's daylight gain. Real covers are an olive felt with a darker strap.
FELT = (58, 54, 38)
LEATHER = (36, 33, 24)
SWEATBAND = (58, 42, 28)
# Para 7003: the hat is trimmed with a grosgrain ribbon and bow, and has four eyelets in the crown.
RIBBON = (32, 31, 22)
EYELET = (14, 14, 12)
# The bow's side of the hat, as the sign of model x, and its size along the band in metres.
BOW_SIDE = 1
BOW_WIDTH = 0.05
BOW_KNOT = 0.011
# Eyelets sit around the crown at this height. The front one holds the emblem, so isn't drawn.
EYELET_HEIGHT = 0.822
EYELET_RADIUS = 0.0048
HAT_CENTRE = (0.0, -0.02)
EMBLEM = (24, 24, 23)
EMBLEM_LIGHT = (92, 90, 85)
BUCKLE = (58, 48, 30)
THREAD = (74, 70, 46)

# Specular (green) and gloss (blue) for the SMDI sheet.
SMDI = {"felt": (16, 14), "leather": (58, 90), "ribbon": (18, 30), "sweatband": (40, 60), "emblem": (32, 50), "buckle": (110, 120)}

# Where ega.png's globe sits, and where the model's globe sits, to line the two up.
ART_GLOBE = (160.0, 180.0)
ART_SCALE = 7800.0  # art pixels per metre
MODEL_GLOBE = (0.0025, 0.8085)
# The globe's sheet area. Its faces overlap and aren't a flat map, so it stays plain matte black.
GLOBE_UV = ((0.581, 0.562), (0.632, 0.613))


def read_first_lod(path):
    """Points, normals and faces of the MLOD's first resolution LOD."""
    b = path.read_bytes()
    assert b[:4] == b"MLOD", path
    o = 12 + 12
    npt, nnm, nfc, _ = struct.unpack_from("<IIII", b, o)
    o += 16
    pts = np.frombuffer(b, "<f4", npt * 4, o).reshape(-1, 4)[:, :3].copy()
    o += npt * 16
    nms = np.frombuffer(b, "<f4", nnm * 3, o).reshape(-1, 3).copy()
    o += nnm * 12
    faces = []
    for _ in range(nfc):
        nv = struct.unpack_from("<I", b, o)[0]
        o += 4
        vs = [struct.unpack_from("<IIff", b, o + 16 * i) for i in range(nv)]
        o += 16 * 4 + 4
        for _ in range(2):  # texture and material names
            o = b.index(0, o) + 1
        faces.append(vs)
    return pts, nms, faces


def classify(pts, nms, faces):
    """Name each face from where it sits on the sheet, and on the hat."""
    centre = np.array([0.0, 0.8, -0.02])
    names = []
    for vs in faces:
        uv = np.array([(v[2], v[3]) for v in vs]).mean(0)
        p = pts[[v[0] for v in vs]]
        n = nms[[v[1] for v in vs]].mean(0)
        radial = (p.mean(0) - centre) * (1, 0, 1)
        radial /= max(np.linalg.norm(radial), 1e-6)
        if uv[0] < 0.037 or (0.88 < uv[0] and uv[1] > 0.6):
            names.append("strap")
        elif uv[0] < 0.533:
            names.append("under" if uv[1] < 0.498 else "brim")
        elif uv[1] < 0.5:
            names.append("crown")
        elif uv[1] < 0.613:
            names.append("buckle" if uv[0] < 0.554 and uv[1] < 0.528 else "emblem")
        else:
            # A folded strip. Normals here point inwards, so the outward side is the negative one.
            names.append("band" if float(n @ radial) < 0 else "sweatband")
    return names


def masks(faces, names):
    out = {}
    for key in set(names):
        out[key] = Image.new("L", (SIZE, SIZE), 0)
    draws = {k: ImageDraw.Draw(v) for k, v in out.items()}
    for vs, name in zip(faces, names):
        draws[name].polygon([(v[2] * SIZE, v[3] * SIZE) for v in vs], fill=255, outline=255)
    return {k: np.asarray(v) > 0 for k, v in out.items()}


def surface_position(pts, faces, names, key):
    """x, y and z on the model behind each sheet pixel of one part, NaN elsewhere."""
    out = np.full((SIZE, SIZE, 3), np.nan, np.float32)
    for vs, name in zip(faces, names):
        if name != key:
            continue
        for i in range(1, len(vs) - 1):
            tri = [vs[0], vs[i], vs[i + 1]]
            uv = np.array([(v[2] * SIZE, v[3] * SIZE) for v in tri])
            xyz = pts[[v[0] for v in tri]]
            x0, y0 = np.floor(uv.min(0)).astype(int) - 1
            x1, y1 = np.ceil(uv.max(0)).astype(int) + 2
            yy, xx = np.mgrid[max(y0, 0):min(y1, SIZE), max(x0, 0):min(x1, SIZE)]
            d = (uv[1, 1] - uv[2, 1]) * (uv[0, 0] - uv[2, 0]) + (uv[2, 0] - uv[1, 0]) * (uv[0, 1] - uv[2, 1])
            if abs(d) < 1e-9:
                continue
            a = ((uv[1, 1] - uv[2, 1]) * (xx - uv[2, 0]) + (uv[2, 0] - uv[1, 0]) * (yy - uv[2, 1])) / d
            b = ((uv[2, 1] - uv[0, 1]) * (xx - uv[2, 0]) + (uv[0, 0] - uv[2, 0]) * (yy - uv[2, 1])) / d
            c = 1 - a - b
            inside = (a >= -0.03) & (b >= -0.03) & (c >= -0.03)
            value = a[..., None] * xyz[0] + b[..., None] * xyz[1] + c[..., None] * xyz[2]
            out[yy[inside], xx[inside]] = value[inside]
    return out


def emblem_relief(pos):
    """Brightness of the emblem art behind each sheet pixel, 0 to 1."""
    art = Image.open(REPO / "tools" / "dress-assets" / "ega.png").convert("RGBA")
    art = np.asarray(art, np.float32)
    lum = art[..., :3].mean(2) * (art[..., 3] / 255)
    lum = (lum - np.percentile(lum[art[..., 3] > 128], 2)) / max(np.ptp(lum), 1)
    h, w = lum.shape
    ax = ART_GLOBE[0] + (pos[..., 0] - MODEL_GLOBE[0]) * ART_SCALE
    ay = ART_GLOBE[1] - (pos[..., 1] - MODEL_GLOBE[1]) * ART_SCALE
    known = np.isfinite(ax)
    ax = np.clip(np.nan_to_num(ax), 0, w - 1.001)
    ay = np.clip(np.nan_to_num(ay), 0, h - 1.001)
    ix, iy = ax.astype(int), ay.astype(int)
    fx, fy = ax - ix, ay - iy
    val = (lum[iy, ix] * (1 - fx) * (1 - fy) + lum[iy, ix + 1] * fx * (1 - fy)
           + lum[iy + 1, ix] * (1 - fx) * fy + lum[iy + 1, ix + 1] * fx * fy)
    val = np.clip(val, 0, 1) * known
    (u0, v0), (u1, v1) = GLOBE_UV
    val[int(v0 * SIZE) - 2:int(v1 * SIZE) + 3, int(u0 * SIZE) - 2:int(u1 * SIZE) + 3] = 0
    return val


def normals_from_height(height):
    """A tangent-space normal sheet from a height field in pixels."""
    dx = (np.roll(height, -1, 1) - np.roll(height, 1, 1)) / 2
    dy = (np.roll(height, -1, 0) - np.roll(height, 1, 0)) / 2
    n = np.dstack((-dx, dy, np.ones_like(height)))
    n /= np.linalg.norm(n, axis=2, keepdims=True)
    return Image.fromarray(((n * 0.5 + 0.5) * 255 + 0.5).astype(np.uint8), "RGB")


def grow(mask, px):
    img = Image.fromarray((mask * 255).astype(np.uint8))
    for _ in range(px):
        img = img.filter(ImageFilter.MaxFilter(3))
    return np.asarray(img) > 0


def edge_distance(mask, limit):
    """Pixels from the edge of the mask, up to limit."""
    dist = np.zeros(mask.shape, np.float32)
    cur = mask.copy()
    for i in range(limit):
        dist[cur] = i + 1
        cur = cur & np.roll(cur, 1, 0) & np.roll(cur, -1, 0) & np.roll(cur, 1, 1) & np.roll(cur, -1, 1)
    return dist


def noise(rng, scale, size=SIZE):
    """Smooth noise around zero, with features about scale pixels across."""
    n = max(2, int(size / scale))
    small = rng.normal(0, 1, (n, n)).astype(np.float32)
    big = Image.fromarray(small).resize((size, size), Image.BICUBIC)
    return np.asarray(big)


def stitches(mask, distance, at, width, angle, length_rad, thread_ratio=0.6):
    """Rows of stitches following the edge of a mask, dashed by angle around the part's middle."""
    row = (np.abs(distance - at) <= width / 2) & mask
    return row & ((angle / length_rad) % 1.0 < thread_ratio)


def polar(mask):
    ys, xs = np.nonzero(mask)
    cx, cy = (xs.min() + xs.max()) / 2, (ys.min() + ys.max()) / 2
    yy, xx = np.mgrid[0:SIZE, 0:SIZE]
    return np.arctan2(yy - cy, xx - cx)


def around_hat(pos):
    """Angle round the hat from its front, in radians, for each sheet pixel."""
    return np.arctan2(pos[..., 0] - HAT_CENTRE[0], -(pos[..., 2] - HAT_CENTRE[1]))


def eyelets(pos):
    """Distance on the crown to the nearest eyelet at the sides and back, in metres."""
    known = np.isfinite(pos[..., 0])
    angle = around_hat(pos)
    best = np.full((SIZE, SIZE), np.inf, np.float32)
    for target in (math.pi / 2, -math.pi / 2, math.pi):
        off = np.abs((angle - target + math.pi) % (2 * math.pi) - math.pi)
        score = np.where(known, off * 0.09 + np.abs(pos[..., 1] - EYELET_HEIGHT), np.inf)
        centre = pos[np.unravel_index(np.argmin(score), score.shape)]
        dist = np.linalg.norm(np.nan_to_num(pos) - centre, axis=2)
        best = np.minimum(best, np.where(known, dist, np.inf))
    return best


def bow_shape(pos, band):
    """The bow's loops and knot on the band, each a mask, from where each pixel sits on the hat.

    The band is a ring on the sheet, so its distance from the ring's middle runs across its width.
    """
    known = np.isfinite(pos[..., 0]) & band
    along = np.nan_to_num(((around_hat(pos) - BOW_SIDE * math.pi / 2 + math.pi) % (2 * math.pi) - math.pi) * 0.09)
    ys, xs = np.nonzero(band)
    yy, xx = np.mgrid[0:SIZE, 0:SIZE]
    ring = np.hypot(xx - (xs.min() + xs.max()) / 2, yy - (ys.min() + ys.max()) / 2)
    near = known & (np.abs(along) < BOW_WIDTH)
    mid, half = np.median(ring[near]), (ring[near].max() - ring[near].min()) / 2
    up = np.abs(ring - mid) / max(half, 1)
    across = np.abs(along) / (BOW_WIDTH / 2)
    # Each loop is narrow at the knot, and widens to almost the band's full width at its end.
    loop = known & (across < 1) & (up < 0.3 + 0.55 * np.minimum(across * 1.6, 1))
    knot = known & (np.abs(along) < BOW_KNOT / 2) & (up < 0.72)
    return loop, knot


def paint(m, relief, pos_band, pos_crown):
    rng = np.random.default_rng(1775)
    colour = np.empty((SIZE, SIZE, 3), np.float32)
    colour[:] = FELT  # bleed colour for everything outside a part
    spec = np.zeros((SIZE, SIZE), np.float32) + SMDI["felt"][0]
    gloss = np.zeros((SIZE, SIZE), np.float32) + SMDI["felt"][1]
    height = np.zeros((SIZE, SIZE), np.float32)

    # Felt: broad unevenness from pressing, then fibre. Light on purpose; the bakes do the shaping.
    fibre = noise(rng, 2.5) * 0.030 + noise(rng, 7) * 0.022 + noise(rng, 60) * 0.018 + noise(rng, 220) * 0.03
    colour *= 1 + fibre[..., None]

    height += noise(rng, 2.2) * 0.10 + noise(rng, 5) * 0.08
    colour[m["under"]] *= 0.90

    # Brim: rows of stitching near the edge, and a darker pressed edge.
    for part, rows in (("brim", (15, 23)), ("under", (15, 23))):
        d = edge_distance(m[part], 40)
        a = polar(m[part])
        edge = np.clip(1 - (d - 1) / 9, 0, 1) * m[part]
        colour *= 1 - edge[..., None] * 0.28
        for at in rows:
            hit = stitches(m[part], d, at, 2.2, a, 2 * math.pi / 420)
            groove = (np.abs(d - at) <= 3) & m[part]
            colour[groove] *= 0.86
            colour[hit] = THREAD
            height[groove] -= 0.6
            height[hit] += 0.5

    # Hatband: grosgrain ribbon, with fine ribs across its width, and its bow.
    grow_band = grow(m["band"], 4)
    grain = noise(rng, 2.5) * 0.08 + noise(rng, 12) * 0.025
    along = np.nan_to_num(around_hat(pos_band)) * 0.09
    ribs = np.sin(along / 0.003 * 2 * math.pi)
    colour[grow_band] = np.array(RIBBON, np.float32) * (1 + (grain + ribs * 0.05)[grow_band])[..., None]
    spec[grow_band], gloss[grow_band] = SMDI["ribbon"]
    height[grow_band] = (ribs * 0.35)[grow_band]
    loop, knot = bow_shape(pos_band, m["band"])
    # Stands proud of the ribbon, with a shadow on it round the edge.
    shadow = grow(loop | knot, 3) & m["band"] & ~(loop | knot)
    colour[shadow] *= 0.45
    colour[loop] = np.array(RIBBON, np.float32) * (1.2 + (ribs * 0.06)[loop])[..., None]
    height[loop] += 1.5
    colour[knot] = np.array(RIBBON, np.float32) * 1.4
    height[knot] += 2.5

    # Ventilation eyelets, dark metal round a hole.
    dist = eyelets(pos_crown)
    colour[dist < EYELET_RADIUS] = EYELET
    spec[dist < EYELET_RADIUS], gloss[dist < EYELET_RADIUS] = SMDI["buckle"]
    height[dist < EYELET_RADIUS] += 2.0
    height[dist < EYELET_RADIUS * 0.55] -= 4.0

    grow_sweat = grow(m["sweatband"], 4) & ~m["band"]
    colour[grow_sweat] = np.array(SWEATBAND, np.float32) * (1 + grain[grow_sweat])[..., None]
    spec[grow_sweat], gloss[grow_sweat] = SMDI["sweatband"]

    # Chin strap: the same leather, edges worn slightly lighter.
    grow_strap = grow(m["strap"], 4)
    colour[grow_strap] = np.array(LEATHER, np.float32) * (1 + grain[grow_strap])[..., None]
    spec[grow_strap], gloss[grow_strap] = SMDI["leather"]
    d = edge_distance(m["strap"], 6)
    wear = np.clip(1 - (d - 1) / 3, 0, 1) * m["strap"]
    colour *= 1 + wear[..., None] * 0.25
    height[grow_strap] = (noise(rng, 2.5) * 0.08)[grow_strap] + (np.clip(d / 6, 0, 1) * 1.2)[grow_strap]

    grow_buckle = grow(m["buckle"], 3)
    colour[grow_buckle] = BUCKLE
    spec[grow_buckle], gloss[grow_buckle] = SMDI["buckle"]
    height[grow_buckle] = 0

    # Emblem: matte black, per the cover's enlisted device. Only the raised detail catches light.
    grow_ega = grow(m["emblem"], 3)
    base, light = np.array(EMBLEM, np.float32), np.array(EMBLEM_LIGHT, np.float32)
    colour[grow_ega] = base
    colour[m["emblem"]] = (base + (light - base) * relief[..., None] ** 1.3)[m["emblem"]]
    spec[grow_ega], gloss[grow_ega] = SMDI["emblem"]
    height[grow_ega] = (relief * 3.0)[grow_ega]

    colour = np.clip(colour, 0, 255).astype(np.uint8)
    smdi = np.zeros((SIZE, SIZE, 3), np.uint8)
    smdi[..., 0] = 255
    smdi[..., 1] = np.clip(spec, 0, 255)
    smdi[..., 2] = np.clip(gloss, 0, 255)
    return Image.fromarray(colour, "RGB"), Image.fromarray(smdi, "RGB"), normals_from_height(height)


def main():
    ap = argparse.ArgumentParser(description=__doc__.split("\n")[0])
    ap.add_argument("--png", type=Path, help="keep the PNG sheets in this folder")
    args = ap.parse_args()

    pts, nms, faces = read_first_lod(ADDON / "DICover.p3d")
    names = classify(pts, nms, faces)
    print({k: names.count(k) for k in sorted(set(names))})
    relief = emblem_relief(surface_position(pts, faces, names, "emblem")[..., :2])
    co, smdi, nohq = paint(masks(faces, names), relief, surface_position(pts, faces, names, "band"), surface_position(pts, faces, names, "crown"))

    with tempfile.TemporaryDirectory() as tmp:
        tmp = Path(tmp)
        for name, img in (("dihat_co", co), ("dihat_smdi", smdi), ("dihat_nohq", nohq)):
            png = tmp / f"{name}.png"
            img.save(png)
            if args.png:
                args.png.mkdir(parents=True, exist_ok=True)
                shutil.copy2(png, args.png / png.name)
            subprocess.run([str(IMAGE_TO_PAA), str(png), str(ADDON / "data" / f"{name}.paa")],
                           check=True, stdout=subprocess.DEVNULL)


if __name__ == "__main__":
    main()
