"""Write unbinarized Arma models (MLOD .p3d) with several LODs, from plain Python data.

Coordinates here are Arma model space: x right, y up, z forward. Each LOD is a list of
points, a list of faces and named selections; Binarize (run by HEMTT) turns the result into
the ODOL the game loads.

Conventions this writer handles, found the hard way in tools/generate-cigs-models.py:
- MLOD wants the opposite winding to how a face reads from outside, or it renders invisible.
- MLOD normals point into the surface.
- Texture v runs down the image (Blender's runs up).
"""
import struct

import numpy as np

# LOD resolutions, as the vanilla Offroad and Quadbike use them.
RES_SHADOW = 10000.0
RES_GEOMETRY = 1e13
RES_PHYSX = 4e13
RES_MEMORY = 1e15
RES_LANDCONTACT = 2e15
RES_HITPOINTS = 5e15
RES_VIEW_GEOMETRY = 6e15
RES_FIRE_GEOMETRY = 7e15


class Lod:
    """One LOD. points: (n,3) float array. faces: list of (corner point ids, corner normals,
    corner uvs, texture, material). selections: name -> (point ids, face ids). For a point
    selection with weights, pass a dict point id -> weight in 0..1 instead of a set."""

    def __init__(self, resolution):
        self.resolution = resolution
        self.points = np.zeros((0, 3), np.float32)
        self.faces = []
        self.selections = {}
        self.mass = None          # per-point masses, geometry LOD only
        self.properties = {}      # named properties, e.g. autocenter = 0

    def add_points(self, pts):
        base = len(self.points)
        self.points = np.vstack([self.points, np.asarray(pts, np.float32).reshape(-1, 3)])
        return base

    def select(self, name, point_ids=(), face_ids=()):
        pts, fcs = self.selections.setdefault(name, (set(), set()))
        pts.update(int(i) for i in point_ids)
        fcs.update(int(i) for i in face_ids)

    def to_bytes(self):
        n_pts = len(self.points)
        # Normals are stored once per distinct value.
        normal_index = {}
        normals = []
        face_blobs = []
        for corners, cnormals, cuvs, texture, material in self.faces:
            ids = []
            for p, nrm, uv in zip(corners, cnormals, cuvs):
                key = (round(float(nrm[0]), 4), round(float(nrm[1]), 4), round(float(nrm[2]), 4))
                ni = normal_index.get(key)
                if ni is None:
                    ni = normal_index[key] = len(normals)
                    normals.append(key)
                ids.append((int(p), ni, float(uv[0]), float(uv[1])))
            blob = bytearray(struct.pack("<I", len(ids)))
            for p, ni, u, v in ids + [(0, 0, 0.0, 0.0)] * (4 - len(ids)):
                blob += struct.pack("<IIff", p, ni, u, v)
            blob += struct.pack("<I", 0) + texture.encode("latin1") + b"\0" + material.encode("latin1") + b"\0"
            face_blobs.append(bytes(blob))
        if not normals:
            normals.append((0.0, 1.0, 0.0))

        out = bytearray(b"P3DM" + struct.pack("<6I", 28, 256, n_pts, len(normals), len(self.faces), 0))
        pts = np.zeros(n_pts, dtype=[("x", "<f4"), ("y", "<f4"), ("z", "<f4"), ("f", "<u4")])
        pts["x"], pts["y"], pts["z"] = self.points[:, 0], self.points[:, 1], self.points[:, 2]
        out += pts.tobytes()
        # MLOD normals point into the surface.
        out += np.asarray(normals, "<f4").__neg__().tobytes()
        for b in face_blobs:
            out += b
        out += b"TAGG"

        def tag(name, data):
            return struct.pack("<B", 1) + name.encode("latin1") + b"\0" + struct.pack("<I", len(data)) + data

        for name in sorted(self.selections):
            pts_sel, faces_sel = self.selections[name]
            data = bytearray(n_pts + len(self.faces))
            for i in pts_sel:
                data[i] = 1
            for f in faces_sel:
                data[n_pts + f] = 1
            out += tag(name, bytes(data))
        if self.mass is not None:
            out += tag("#Mass#", np.asarray(self.mass, "<f4").tobytes())
        for k, v in self.properties.items():
            out += tag("#Property#", k.encode("latin1").ljust(64, b"\0") + str(v).encode("latin1").ljust(64, b"\0"))
        out += tag("#EndOfFile#", b"")
        out += struct.pack("<f", self.resolution)
        return bytes(out)


def write_mlod(path, lods):
    out = bytearray(b"MLOD" + struct.pack("<II", 257, len(lods)))
    for lod in lods:
        out += lod.to_bytes()
    with open(path, "wb") as f:
        f.write(out)


def orient_face(points, corners, outward):
    """Order a face's corners the way MLOD wants them: wound so the face reads from outside
    with cross(b - a, c - b) pointing inwards. Returns True if the order was reversed."""
    a, b, c = (points[corners[i]] for i in range(3))
    return float(np.dot(np.cross(b - a, c - b), outward)) > 0
