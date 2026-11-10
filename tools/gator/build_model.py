"""Turn the purchased AN/TPS-80 G/ATOR model into the Arma model: gator.p3d and model.cfg.

Runs inside Blender (5.x), on the artist's .blend:

    blender -b <...Deployed_blender_base.blend> --python tools/gator/build_model.py -- <out dir> [--renders <dir>]

The model ships deployed, as six merged meshes. This script splits them into the parts that
move by their loose pieces, builds four resolution LODs plus collision, shadow and memory
LODs, and writes model.cfg for the stow/deploy sequence. Everything about this particular
model (hinge positions, which pieces are braces) is in the constants below, measured from the
artist's mesh; see tools/gator/README.md for how they were found.

Blender space here: x towards the trailer's left, y towards its back, z up, metres, ground at
z = 0. The P3D gets (x, z, y). Checked in game: written as (-x, z, -y) the trailer came out
facing backwards, with selectionPosition reading (-x, -z, y) of the P3D's coordinates.
"""
import json
import math
import os
import sys

import bmesh
import bpy
import numpy as np
from mathutils import Matrix, Vector
from mathutils.bvhtree import BVHTree

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
import p3d  # noqa: E402

PREFIX = r"z\ptf_gator\addons\data"
MODEL_NAME = "gator"

# The artist's materials, our short names for them, and the hidden selection each one is.
MATERIALS = {"AN_TPS_80_Support_MAT": "support", "AN_TPS_80_Generator_MAT": "generator", "AN_TPS_80_Radar_MAT": "radar"}
# The artist's "Glass" object is the light lenses: same texture as the trailer, but their own
# material (and hidden selection) so they read as off and can be lit later.
MAT_ORDER = ["support", "generator", "radar", "lights"]
CAMO = {"support": "camo1", "generator": "camo2", "radar": "camo3", "lights": "lights"}
TEXTURE_OF = {"lights": "support"}

# --- Measured from the artist's mesh -----------------------------------------------------
# The array tilts on a hinge bolt at the back of the equipment box.
HINGE = Vector((0.0, 2.53, 1.78))
# Folding the array forward by this much lays it on the folded braces (a full 64 degrees
# touches the box; 63 clears it and leaves the far end 6 degrees up).
RADAR_STOW_DEG = 63.0
# The struts are hydraulic cylinders and stay pinned to the bracket on the array's edge
# while it moves: each turns about its pivot and its rod slides in or out to match.
# Vertical struts: pivot on the box side. 1.67 m long deployed, 0.99 m stowed.
BRACE_V_PIVOT = Vector((1.13, 1.696, 1.760))
BRACE_V_TOP = Vector((1.135, 1.758, 3.433))
BRACE_V_SPLIT = 0.55       # metres along the strut: lower part below, sliding rod above
# Diagonal struts: pivot at the front of the box. They can only shorten by BRACE_D_RETRACT,
# which the array reaches about a third of the way down (folded flat, their two pins would
# be 33 cm apart). There they unpin and fold back onto the box, swinging in to lie straight,
# while the array carries on down. Deploying, they swing up and pin on at that point.
BRACE_D_PIVOT = Vector((0.565, 0.150, 1.720))
BRACE_D_TOP = Vector((1.12, 1.68, 3.70))
BRACE_D_SPLIT = 1.33       # metres along the strut: lower tube below, sliding rod above
BRACE_D_RETRACT = 1.20     # how far the rod can slide in
BRACE_D_FOLD_ELEV = 4.0    # degrees above the box top once folded
BRACE_D_FOLD_SPAN = 0.08   # share of the deploy sequence the fold takes
# Arma animations move linearly, so the struts follow the array in this many straight pieces.
STRUT_KEYS = 12
# Leveling jacks: rod and foot slide up into the cylinder. The rod is modelled running up
# inside the cylinder, so whatever would come out of the top is cut off.
JACKS = {"fl": (1.4965, 0.3095), "fr": (-1.4965, 0.3095), "rl": (1.4965, 2.2355), "rr": (-1.4965, 2.2355)}
JACK_TRAVEL = 0.30
# A leg runs on past phase 1 (foot on flat ground) to JACK_MAX_PHASE, to reach down a slope
# and lift its corner when the trailer levels itself; the rod stays inside its cylinder.
JACK_MAX_PHASE = 2.0
JACK_MOVING_TOP = 0.40     # pieces of a jack entirely below this move (rod end, foot)
JACK_ROD_TOP = 1.081       # top of the rod inside the cylinder
# Arma wheel_1_x is the left side (Blender +x). PhysX cars need two axles, so the real wheels
# are the rear pair and the tongue stand's caster stands in for the front pair (no mesh).
WHEEL = {"1_2": 1.426, "2_2": -1.426}
STAND_WHEEL_R = 0.075
WHEEL_Y, WHEEL_Z, WHEEL_R = 1.285, 0.4375, 0.4375
# The tongue stand (jockey caster): its collar, fork and wheel slide up into the outer tube
# when the trailer is hitched (source ptf_gator_stand, 0 down to 1 up).
STAND_XY = (0.0, -2.37)
STAND_TRAVEL = 0.22
# The equipment box sits on a turntable: deployed, the box, array and struts spin about a
# vertical axis through its centre (source ptf_gator_spin, one turn per unit of phase).
SPIN_CENTRE = Vector((0.0, 1.5465, 0.0))
TURNTABLE_PARTS = ("turntable", "radar", "pedestal", "brace_")
BONE_OF = {"pedestal": "turntable"}  # parts whose bone has another name
# Turning, the array's foot (level with the hinge) sweeps out to 1.85 m from the turntable
# centre, and the artist put the generator's back wall 1.69 m away: a 16 cm clash whenever
# the array faces forward. The generator and its guard frame move forward along the rails.
GENERATOR_SHIFT = 0.20


def generator_unit(obj, mn, mx):
    """The generator housing and the guard frame round it (not the platform behind it).
    The guard posts' foot collars start at 0.871 m, so the cut is just below them."""
    if obj == "Generator":
        return mx.y < 0.25
    return obj in ("Base", "Glass") and mn.z > 0.86 and mn.y > -1.9 and mx.y < -0.05


def inside_static(mn, mx, statics):
    """Whether a piece sits inside a bigger piece that stays put (a clamp in a frame bracket):
    it stays with it."""
    return any(smn.x - 0.01 <= mn.x and mx.x <= smx.x + 0.01 and smn.y - 0.01 <= mn.y and mx.y <= smx.y + 0.01
               and smn.z - 0.01 <= mn.z and mx.z <= smx.z + 0.01 and (smx - smn).length > (mx - mn).length
               for smn, smx in statics)

# The array's animation source, ptf_gator_deploy, runs 0 (stowed) to 1 (raised); the struts
# follow the array. Each leg has its own source, ptf_gator_leg_<fl|fr|rl|rr>, 0 up to 1 down.
PHASES = {
    "radar": (0.00, 1.00),
}
# Arma turns a rotation the other way to Blender's right-hand rule about the same axis
# points. Checked in game by tools/gator/test (probe positions).
ARMA_ROTATION_SIGN = -1.0

TOTAL_MASS = 5500.0
COM_TARGET_Y = 1.0   # centre of mass a little ahead of the axle, so the tongue stand carries weight
# Mass per cubic metre of collision hull, relative to the trailer body: the array and the box
# are mostly hollow, and a low centre of mass keeps the trailer steady.
DENSITY = {"body": 1.0, "pedestal": 0.5, "radar": 0.25}

# Shadow buffer LODs (close-up shadows), as the vanilla Offroad has them: the reduced mesh.
SHADOW_BUFFER_LODS = [(11000.0, 20000, 0.05), (11010.0, 6000, 0.25)]
# How far the shadow buffer meshes sit inside the visible surface.
SHADOW_BUFFER_INSET = 0.02
WHEEL_PARTS = ("wheel_1_2", "wheel_2_2")

# Resolution LODs: (resolution, triangle budget, drop loose pieces smaller than this, metres).
# LOD 1 is only the lossless flat-face merge (about 175k triangles); the rest are cut further.
RES_LODS = [(1.0, 1000000, 0.0), (2.0, 60000, 0.03), (3.0, 18000, 0.08), (4.0, 6000, 0.25)]


def to_arma(v):
    return (v[0], v[2], v[1])


def to_arma_np(a):
    a = np.asarray(a, np.float64).reshape(-1, 3)
    return np.stack([a[:, 0], a[:, 2], a[:, 1]], 1)


def side_of(x):
    return "l" if x > 0 else "r"


# --- Parts ------------------------------------------------------------------------------

def brace_d(side):
    s = 1 if side == "l" else -1
    b = Vector((s * BRACE_D_PIVOT.x, BRACE_D_PIVOT.y, BRACE_D_PIVOT.z))
    a = Vector((s * BRACE_D_TOP.x, BRACE_D_TOP.y, BRACE_D_TOP.z))
    return b, (a - b).normalized(), (a - b).length


def brace_v(side):
    s = 1 if side == "l" else -1
    return (Vector((s * BRACE_V_PIVOT.x, BRACE_V_PIVOT.y, BRACE_V_PIVOT.z)),
            Vector((s * BRACE_V_TOP.x, BRACE_V_TOP.y, BRACE_V_TOP.z)))


def seg_dist(p, a, b):
    ab = b - a
    t = max(0.0, min(1.0, (p - a).dot(ab) / ab.length_squared))
    return (p - (a + ab * t)).length


def classify(obj, mn, mx):
    """Which part a loose piece of the artist's mesh belongs to."""
    c = (mn + mx) / 2
    if obj == "Radar":
        return "radar"
    if obj == "Control_Panel":
        side = side_of(c.x)
        # Cables and fittings that run from the box back into the array's foot move with it.
        if mx.y > 2.6:
            return "radar"
        b, u, length = brace_d(side)
        t = (c - b).dot(u)
        if c.z > 1.70 and t > 0.03 and seg_dist(c, b, b + u * length) < 0.12:
            return f"brace_d_{side}" if t < BRACE_D_SPLIT else f"brace_d_{side}_rod"
        v0, v1 = brace_v(side)
        if 1.07 <= abs(c.x) <= 1.19 and c.z > 1.70 and mx.z < 3.5 and seg_dist(c, v0, v1) < 0.10:
            t = (c - v0).dot((v1 - v0).normalized())
            return f"brace_v_{side}" if t < BRACE_V_SPLIT else f"brace_v_{side}_rod"
        return "pedestal"
    if obj == "Base" and abs(c.x - STAND_XY[0]) < 0.1 and abs(c.y - STAND_XY[1]) < 0.12 and mx.z <= 0.36:
        return "stand"
    if obj == "Support":
        for name, (jx, jy) in JACKS.items():
            d = math.hypot(c.x - jx, c.y - jy)
            if d < 0.4 and mx.z <= JACK_MOVING_TOP:
                return f"jack_{name}"
            if d < 0.02 and 0.37 < mn.z < 0.40 and mx.z > 1.0:
                return f"jack_{name}"  # the rod, cut down below
        for wname, wx in WHEEL.items():
            inside = (min(abs(mn.x), abs(mx.x)) >= abs(wx) - 0.16 and max(abs(mn.x), abs(mx.x)) <= abs(wx) + 0.16
                      and (mn.x > 0) == (wx > 0))
            corners = [(y, z) for y in (mn.y, mx.y) for z in (mn.z, mx.z)]
            if inside and all(math.hypot(y - WHEEL_Y, z - WHEEL_Z) <= WHEEL_R * 1.45 for y, z in corners) \
                    and mn.y >= WHEEL_Y - WHEEL_R - 0.01 and mx.y <= WHEEL_Y + WHEEL_R + 0.01 and mx.z <= 2 * WHEEL_R + 0.01:
                return f"wheel_{wname}"
    return "body"


def islands(bm):
    """Loose pieces of a bmesh, as lists of face indices."""
    bm.faces.ensure_lookup_table()
    seen = set()
    out = []
    for f in bm.faces:
        if f.index in seen:
            continue
        stack = [f]
        seen.add(f.index)
        group = []
        while stack:
            g = stack.pop()
            group.append(g.index)
            for v in g.verts:
                for h in v.link_faces:
                    if h.index not in seen:
                        seen.add(h.index)
                        stack.append(h)
        out.append(group)
    return out


def load_parts():
    """Split the artist's meshes into one bmesh per part, in Blender world space, with each
    face's material set to our MAT_ORDER index and its loose piece's size stored on it."""
    parts = {}
    counts = {}
    moved = {}
    for o in list(bpy.data.objects):
        if o.type != "MESH":
            continue
        mat = "lights" if o.name == "Glass" else MATERIALS[o.data.materials[0].name]
        bm = bmesh.new()
        bm.from_mesh(o.data)
        bm.transform(o.matrix_world)
        bm.faces.ensure_lookup_table()
        size_layer = bm.faces.layers.float.new("piece")
        by_part = {}
        groups = []
        for group in islands(bm):
            co = np.array([v.co for i in group for v in bm.faces[i].verts])
            groups.append((group, Vector(co.min(0)), Vector(co.max(0))))
        statics = [(mn, mx) for _, mn, mx in groups if not generator_unit(o.name, mn, mx)]
        for group, mn, mx in groups:
            part = classify(o.name, mn, mx)
            if generator_unit(o.name, mn, mx) and not inside_static(mn, mx, statics):
                for v in {v for i in group for v in bm.faces[i].verts}:
                    v.co.y -= GENERATOR_SHIFT
                moved[part] = moved.get(part, 0) + 1
            diag = (mx - mn).length
            for i in group:
                bm.faces[i][size_layer] = diag
                bm.faces[i].material_index = MAT_ORDER.index(mat)
            by_part.setdefault(part, set()).update(group)
            counts[part] = counts.get(part, 0) + 1
        for part, faces in by_part.items():
            sub = bm.copy()
            sub.faces.ensure_lookup_table()
            bmesh.ops.delete(sub, geom=[f for f in sub.faces if f.index not in faces], context="FACES")
            target = parts.get(part)
            if target is None:
                parts[part] = sub
            else:
                me = bpy.data.meshes.new("tmp")
                sub.to_mesh(me)
                target.from_mesh(me)
                bpy.data.meshes.remove(me)
                sub.free()
        bm.free()
    for name, bm in parts.items():
        if name.startswith("jack_"):
            cut = JACK_ROD_TOP - JACK_TRAVEL
            res = bmesh.ops.bisect_plane(bm, geom=list(bm.verts) + list(bm.edges) + list(bm.faces),
                                         plane_co=(0, 0, cut), plane_no=(0, 0, 1), clear_outer=True)
            del res
    print("PIECES", json.dumps(counts, sort_keys=True), "generator pieces moved", moved)
    return parts


# --- Pose: where each part is at a deploy phase --------------------------------------------

def phase_k(name, s):
    a, b = PHASES[name]
    return max(0.0, min(1.0, (s - a) / (b - a)))


def rot_about(point, deg):
    return Matrix.Translation(point) @ Matrix.Rotation(math.radians(deg), 4, "X") @ Matrix.Translation(-point)


def radar_deg(s):
    """How far the array is folded at deploy phase s."""
    return RADAR_STOW_DEG * (1 - phase_k("radar", s))


def s_at_radar_deg(deg):
    a, b = PHASES["radar"]
    return b - deg / RADAR_STOW_DEG * (b - a)


def strut_ends(kind, side):
    """A strut's pivot on the box and its pin on the array, deployed."""
    if kind == "v":
        return brace_v(side)
    b, u, length = brace_d(side)
    return b, b + u * length


def strut_frame(kind, side):
    """Pivot, unit direction, length, and the two rotation axes: pitch turns about x, skew
    tilts the strut sideways (about the axis across it that lies flat)."""
    p, a = strut_ends(kind, side)
    rest = a - p
    e0 = Vector((0, rest.y, rest.z)).normalized()
    return p, rest.normalized(), rest.length, Vector((1, 0, 0)), e0.cross(Vector((1, 0, 0)))


def strut_pose(kind, side, deg):
    """(pitch, skew, slide) that keep a strut pinned when the array has folded deg degrees."""
    p, u, length, _, _ = strut_frame(kind, side)
    a = p + u * length
    d = (rot_about(HINGE, deg) @ a) - p
    rest = a - p
    pitch = math.degrees(math.atan2(d.z, d.y) - math.atan2(rest.z, rest.y))
    skew = math.degrees(math.asin(d.x / d.length) - math.asin(rest.x / length))
    return pitch, skew, d.length - length


_KEYS = {}


def strut_keys(kind, side):
    """Keyframes [(s, pitch, skew, slide)], ascending in s, all zero deployed (s = 1)."""
    if (kind, side) in _KEYS:
        return _KEYS[(kind, side)]
    if kind == "v":
        degs = np.linspace(RADAR_STOW_DEG, 0, STRUT_KEYS + 1)
        keys = [(s_at_radar_deg(d), *strut_pose(kind, side, d)) for d in degs]
    else:
        lo, hi = 0.0, RADAR_STOW_DEG  # how far the array folds before the rod is all the way in
        for _ in range(40):
            mid = (lo + hi) / 2
            lo, hi = (mid, hi) if strut_pose(kind, side, mid)[2] > -BRACE_D_RETRACT else (lo, mid)
        degs = np.linspace(lo, 0, STRUT_KEYS + 1)
        keys = [(s_at_radar_deg(d), *strut_pose(kind, side, d)) for d in degs]
        p, u, length, _, _ = strut_frame(kind, side)
        rest = u * length
        fold_pitch = BRACE_D_FOLD_ELEV - math.degrees(math.atan2(rest.z, rest.y))
        fold_skew = -math.degrees(math.asin(rest.x / length))
        keys.insert(0, (keys[0][0] - BRACE_D_FOLD_SPAN, fold_pitch, fold_skew, keys[0][3]))
        print(f"STRUT diagonal {side} unpins {lo:.1f} degrees into the fold, at phase {keys[1][0]:.3f}")
    _KEYS[(kind, side)] = keys
    return keys


def strut_at(keys, s):
    """Linear between keyframes, as Arma's animations will move it."""
    if s <= keys[0][0]:
        return keys[0][1:]
    if s >= keys[-1][0]:
        return keys[-1][1:]
    for k0, k1 in zip(keys, keys[1:]):
        if k0[0] <= s <= k1[0]:
            f = (s - k0[0]) / (k1[0] - k0[0])
            return tuple(x0 + (x1 - x0) * f for x0, x1 in zip(k0[1:], k1[1:]))


def part_matrix(part, s, yaw=0.0, legs=None):
    """World transform of a part at deploy phase s (1 = deployed = the artist's pose), with
    the turntable turned yaw degrees and the legs at phase `legs` (default: down unless
    the array is fully stowed)."""
    if part == "stand":
        return Matrix.Identity(4)
    if part.startswith("jack_"):
        leg = (1.0 if s > 0 else 0.0) if legs is None else legs
        return Matrix.Translation((0, 0, JACK_TRAVEL * (1 - leg)))
    m = local_matrix(part, s)
    if yaw and part.startswith(TURNTABLE_PARTS):
        m = Matrix.Translation(SPIN_CENTRE) @ Matrix.Rotation(math.radians(yaw), 4, "Z") @ Matrix.Translation(-SPIN_CENTRE) @ m
    return m


def local_matrix(part, s):
    if part == "radar":
        return rot_about(HINGE, radar_deg(s))
    if part.startswith("brace_"):
        _, kind, side = part.split("_")[:3]
        p, u, _, _, w = strut_frame(kind, side)
        pitch, skew, slide = strut_at(strut_keys(kind, side), s)
        m = rot_about(p, pitch) @ Matrix.Translation(p) @ Matrix.Rotation(math.radians(skew), 4, w) @ Matrix.Translation(-p)
        if part.endswith("_rod"):
            m = m @ Matrix.Translation(u * slide)
        return m
    return Matrix.Identity(4)


BONES = {  # bone -> parent
    "turntable": "",
    "radar": "turntable",
    "brace_v_l": "turntable", "brace_v_r": "turntable",
    "brace_v_l_rod": "brace_v_l", "brace_v_r_rod": "brace_v_r",
    "brace_d_l": "turntable", "brace_d_r": "turntable",
    "brace_d_l_rod": "brace_d_l", "brace_d_r_rod": "brace_d_r",
    "jack_fl": "", "jack_fr": "", "jack_rl": "", "jack_rr": "",
    "stand": "",
    "wheel_1_2_damper": "", "wheel_2_2_damper": "",
    "wheel_1_2": "wheel_1_2_damper", "wheel_2_2": "wheel_2_2_damper",
    # The stencil and the patches ride the box and the array, and are hidden on a wreck.
    "markings_text": "turntable", "markings_patch": "radar",
}


# --- Meshes for each LOD --------------------------------------------------------------------

def mark_uv_seams(bm):
    """Mark every edge where the texture coordinates break as a seam, so neither reduction
    step merges faces across it. Merging across a seam is what tears the texture: the
    surviving triangles sample the wrong part of the sheet."""
    uv = bm.loops.layers.uv.active
    if uv is None:
        return
    for e in bm.edges:
        if len(e.link_loops) != 2:
            e.seam = True
            continue
        a, b = e.link_loops
        # The two faces' loops run opposite ways along the shared edge.
        a0, a1 = a[uv].uv, a.link_loop_next[uv].uv
        b0, b1 = b.link_loop_next[uv].uv, b[uv].uv
        e.seam = (a0 - b0).length > 1e-4 or (a1 - b1).length > 1e-4 or a.face.material_index != b.face.material_index


def decimated(bm_src, ratio, min_piece):
    """A Blender mesh of the part, cut to about `ratio` of its triangles, smoothed by angle.

    First tiny pieces go, then flat neighbouring faces within one texture island merge
    (lossless on this mostly flat-panelled model, about 2.6x fewer triangles). Only if that
    isn't enough does an edge-collapse pass run, kept off the texture seams."""
    bm = bm_src.copy()
    original = tri_count(bm)
    layer = bm.faces.layers.float.get("piece")
    if min_piece > 0:
        bmesh.ops.delete(bm, geom=[f for f in bm.faces if f[layer] < min_piece], context="FACES")
    mark_uv_seams(bm)
    bmesh.ops.dissolve_limit(bm, angle_limit=math.radians(1.0), use_dissolve_boundaries=False,
                             verts=list(bm.verts), edges=list(bm.edges), delimit={"UV", "MATERIAL", "SHARP", "SEAM"})
    bmesh.ops.triangulate(bm, faces=list(bm.faces))
    ratio = ratio * original / max(1, len(bm.faces))
    me = bpy.data.meshes.new("part")
    bm.to_mesh(me)
    bm.free()
    for m in MAT_ORDER:  # material slots, so material indices survive evaluation
        me.materials.append(bpy.data.materials.get("gator_" + m) or bpy.data.materials.new("gator_" + m))
    obj = bpy.data.objects.new("part", me)
    bpy.context.scene.collection.objects.link(obj)
    if ratio < 0.999 and len(me.polygons):
        mod = obj.modifiers.new("dec", "DECIMATE")
        mod.ratio = ratio
        mod.use_collapse_triangulate = True
    dg = bpy.context.evaluated_depsgraph_get()
    ev = obj.evaluated_get(dg)
    m2 = bpy.data.meshes.new_from_object(ev)
    bpy.data.objects.remove(obj)
    bpy.data.meshes.remove(me)
    bm = bmesh.new()
    bm.from_mesh(m2)
    # Smooth by angle: hard-surface edges over 35 degrees stay sharp.
    for f in bm.faces:
        f.smooth = True
    for e in bm.edges:
        if len(e.link_faces) == 2:
            e.smooth = e.calc_face_angle(0.0) < math.radians(35)
        else:
            e.smooth = False
    bmesh.ops.triangulate(bm, faces=[f for f in bm.faces if len(f.verts) > 4])
    bm.to_mesh(m2)
    bm.free()
    return m2


# Markings: quads 5 mm proud of flat surfaces, textured from markings_ca.paa (made by
# build_textures.py: stencil text in the top 2048 x 480, the faded PTF patch at 8,520 to
# 472,1016). Surfaces measured by raycasting the mesh:
# - the recessed panel on each side of the equipment box (x 1.086, y 0.45 to 1.55,
#   z 1.27 to 1.53), for the text;
# - the array's side edge (x 1.128), flat from 0.2 to 1.4 m along the array from the hinge
#   and 0.10 to 0.40 m across it, for the patch, which stands upright with the array raised.
MARKINGS_TEXTURE = PREFIX + r"\data\markings_ca.paa"
_ALONG = Vector((0, -0.85, 2.1)).normalized()     # up the raised array
_ACROSS = Vector((0, 0.9, 0.44)).normalized()     # through it, towards its face
MARKINGS = [
    # (bone, centre on the left side, up, width, height, (u0, v0, u1, v1)); mirrored for the right
    # 7 cm above the panel's middle, clear of the latches along its bottom edge.
    ("markings_text", Vector((1.086, 1.00, 1.47)), Vector((0, 0, 1)), 1.08, 0.253, (0.0, 0.0, 1.0, 480 / 1024)),
    ("markings_patch", Vector((1.128, 0, 0)) + HINGE + _ALONG * 0.85 + _ACROSS * 0.25, _ALONG,
     0.234, 0.25, (8 / 2048, 520 / 1024, 472 / 2048, 1016 / 1024)),
]


def add_markings(lod):
    """Put the markings on both sides, reading as they would painted on (so the text runs
    front to back on the left side and back to front on the right)."""
    for sx in (1, -1):
        out = Vector((sx, 0, 0))
        for bone, centre, up, w, h, (u0, v0, u1, v1) in MARKINGS:
            right = up.cross(out)
            c = Vector((sx * (abs(centre.x) + 0.005), centre.y, centre.z))
            quad = [(c - right * w / 2 + up * h / 2, (u0, v0)), (c + right * w / 2 + up * h / 2, (u1, v0)),
                    (c + right * w / 2 - up * h / 2, (u1, v1)), (c - right * w / 2 - up * h / 2, (u0, v1))]
            base = lod.add_points(to_arma_np([p for p, _ in quad]))
            corners = [base + i for i in range(4)]
            uvs = [uv for _, uv in quad]
            normal = np.array(to_arma(out))
            if p3d.orient_face(lod.points, corners, normal):
                corners, uvs = corners[::-1], uvs[::-1]
            lod.faces.append((corners, [normal] * 4, uvs, MARKINGS_TEXTURE, ""))
            if bone:
                lod.select(bone, corners, [len(lod.faces) - 1])


def tri_count(bm):
    return sum(len(f.verts) - 2 for f in bm.faces)


def build_res_lod(parts, res, budget, min_piece, shadow=False):
    """A resolution LOD, or with shadow=True a shadow buffer LOD: the same reduced mesh with no
    textures, so close-up shadows follow the real surface (the shadow volume is convex hulls,
    which bridge the hollows of the array's ribbed face and shade it in blotches)."""
    total = 0
    for bm in parts.values():
        layer = bm.faces.layers.float.get("piece")
        total += sum(len(f.verts) - 2 for f in bm.faces if f[layer] >= min_piece)
    ratio = min(1.0, budget / max(1, total))
    lod = p3d.Lod(res)
    tex = {m: f"{PREFIX}\\data\\{TEXTURE_OF.get(m, m)}_co.paa" for m in MAT_ORDER}
    rvmat = {m: f"{PREFIX}\\data\\{m}.rvmat" for m in MAT_ORDER}
    n_tris = 0
    for part, bm in sorted(parts.items()):
        me = decimated(bm, ratio, min_piece)
        if not len(me.polygons):
            bpy.data.meshes.remove(me)
            continue
        co = np.array([v.co for v in me.vertices])
        if shadow:
            # Pulled in under the surface it stands for: reduced, it would otherwise poke a few
            # millimetres through the visible mesh in places and shade it in sharp spots. Never
            # more than a third of the way through the piece, or a thin plate turns inside out
            # and its underside stands proud of the surface, which casts the same spots.
            normals = np.array([v.normal for v in me.vertices])
            tree = BVHTree.FromPolygons(co.tolist(), [list(poly.vertices) for poly in me.polygons])
            depth = np.full(len(co), SHADOW_BUFFER_INSET)
            for i, (c, n) in enumerate(zip(co, normals)):
                hit = tree.ray_cast(Vector(c - n * 0.0005), Vector(-n), 3 * SHADOW_BUFFER_INSET)
                if hit[0] is not None:
                    depth[i] = min(SHADOW_BUFFER_INSET, hit[3] / 3)
            co = co - normals * depth[:, None]
        base = lod.add_points(to_arma_np(co))
        cn = me.corner_normals
        uv = me.uv_layers[0].data if me.uv_layers else None
        face0 = len(lod.faces)
        for poly in me.polygons:
            loops = list(poly.loop_indices)
            corners = [base + me.loops[li].vertex_index for li in loops]
            normals = [to_arma(cn[li].vector) for li in loops]
            uvs = [(uv[li].uv[0], 1.0 - uv[li].uv[1]) if uv else (0.0, 0.0) for li in loops]
            if p3d.orient_face(lod.points, corners, np.array(to_arma(poly.normal))):
                corners, normals, uvs = corners[::-1], normals[::-1], uvs[::-1]
            m = MAT_ORDER[poly.material_index]
            if shadow:
                lod.faces.append((corners, normals, uvs, "", ""))
            else:
                lod.faces.append((corners, normals, uvs, tex[m], rvmat[m]))
                lod.select(CAMO[m], corners, [len(lod.faces) - 1])
                if part in WHEEL_PARTS:
                    lod.select(part + "_hide", corners, [len(lod.faces) - 1])
            n_tris += len(loops) - 2
        bone = BONE_OF.get(part, part)
        if bone in BONES:
            lod.select(bone, range(base, base + len(co)), range(face0, len(lod.faces)))
        bpy.data.meshes.remove(me)
    if res <= 3.0 and not shadow:
        add_markings(lod)
    print(f"LOD {res}: {n_tris} triangles, {len(lod.points)} points (ratio {ratio:.3f})")
    return lod


# --- Collision: convex pieces ----------------------------------------------------------------

def sample_surface(me, spacing):
    """Points on a mesh's surface roughly every `spacing` metres, plus its vertices."""
    co = np.array([v.co for v in me.vertices])
    tris = []
    for p in me.polygons:
        vs = list(p.vertices)
        for i in range(1, len(vs) - 1):
            tris.append((vs[0], vs[i], vs[i + 1]))
    if not tris:
        return co
    t = co[np.array(tris)]
    area = 0.5 * np.linalg.norm(np.cross(t[:, 1] - t[:, 0], t[:, 2] - t[:, 0]), axis=1)
    n = np.clip(np.ceil(area / (spacing * spacing)).astype(int), 1, 400)
    rng = np.random.default_rng(1)
    idx = np.repeat(np.arange(len(t)), n)
    r1, r2 = rng.random(len(idx)), rng.random(len(idx))
    flip = r1 + r2 > 1
    r1[flip], r2[flip] = 1 - r1[flip], 1 - r2[flip]
    pts = t[idx, 0] + (t[idx, 1] - t[idx, 0]) * r1[:, None] + (t[idx, 2] - t[idx, 0]) * r2[:, None]
    return np.vstack([co, pts])


def hull(points, max_verts=60):
    """Convex hull of points as (verts, tris), thickened if flat, capped at max_verts."""
    pts = np.asarray(points, np.float64)
    if len(pts) < 4:
        return None
    centre = pts.mean(0)
    _, sv, vt = np.linalg.svd(pts - centre, full_matrices=False)
    extents = np.ptp((pts - centre) @ vt.T, axis=0)
    if extents.min() < 0.04:
        n = vt[-1]
        pts = np.vstack([pts + n * 0.02, pts - n * 0.02])
    q = 0.03
    while True:
        snapped = np.unique(np.round(pts / q) * q, axis=0)
        bm = bmesh.new()
        verts = [bm.verts.new(p) for p in snapped]
        res = bmesh.ops.convex_hull(bm, input=verts)
        loose = {g for g in res["geom_interior"] + res["geom_unused"] if isinstance(g, bmesh.types.BMVert)}
        bmesh.ops.delete(bm, geom=list(loose), context="VERTS")
        bmesh.ops.dissolve_degenerate(bm, dist=0.005, edges=list(bm.edges))
        bmesh.ops.triangulate(bm, faces=list(bm.faces))
        if len(bm.verts) <= max_verts or q > 0.5:
            break
        bm.free()
        q *= 1.5
    # A shadow volume must be closed, or Arma stretches a streak of shadow off it.
    if not all(len(e.link_faces) == 2 for e in bm.edges) or             any(f.calc_area() < 1e-6 for f in bm.faces):
        bm.free()
        return None
    bm.verts.ensure_lookup_table()
    vs = np.array([v.co for v in bm.verts])
    index = {v: i for i, v in enumerate(bm.verts)}
    tris = [[index[v] for v in f.verts] for f in bm.faces]
    bm.free()
    if len(vs) < 4 or len(tris) < 4:
        return None
    return vs, tris


CELL = {"body": 1.0, "pedestal": 0.8, "radar": 1.0}


def collision_pieces(parts):
    """Convex pieces per part, in Blender space: a grid of cells for the big parts, one hull
    for the small ones. Returns [(part, verts, tris)]."""
    out = []
    for part, bm in sorted(parts.items()):
        me = decimated(bm, min(1.0, 3000 / max(1, tri_count(bm))), 0.05)
        pts = sample_surface(me, 0.08)
        bpy.data.meshes.remove(me)
        if len(pts) < 4:
            continue
        cell = CELL.get(part)
        if cell is None:
            h = hull(pts)
            if h:
                out.append((part, *h))
            continue
        keys = np.floor(pts / cell).astype(int)
        for key in {tuple(k) for k in keys}:
            lo = np.array(key) * cell - 0.05
            hi = lo + cell + 0.10
            sel = pts[np.all((pts >= lo) & (pts <= hi), axis=1)]
            if len(sel) < 12:
                continue
            h = hull(sel)
            if h:
                out.append((part, *h))
    print("COLLISION pieces", len(out))
    return out


def inset(vs, by):
    """Shrink a convex piece by `by` metres each side along its own axes (never below half)."""
    centre = vs.mean(0)
    _, _, axes = np.linalg.svd(vs - centre, full_matrices=False)
    local = (vs - centre) @ axes.T
    extent = np.ptp(local, axis=0)
    scale = np.maximum(0.5, (extent - 2 * by) / np.maximum(extent, 1e-6))
    return centre + (local * scale) @ axes


# Hit points: (config class, selection, parts it covers, extra filter on a piece's centre).
# The generator and its fuel tank are the front unit of the trailer body.
HIT_POINTS = [
    ("HitBody", "hit_hull", ("body", "pedestal"), None),
    ("HitEngine", "hit_engine", ("body",), lambda c: c.y < -0.3 and c.z > 0.9),
    ("HitFuel", "hit_fuel", ("body",), lambda c: c.y < -0.6 and 0.9 < c.z < 1.3),
    ("HitRadar", "hit_radar", ("radar",), None),
    ("HitLF2Wheel", "wheel_1_2_steering", ("wheel_1_2",), None),
    ("HitRF2Wheel", "wheel_2_2_steering", ("wheel_2_2",), None),
]


def hitpoints_lod(pieces):
    """Points spread over what each hit point covers. They go in the moving parts' bone
    selections too, so the radar's hit point follows the array."""
    lod = p3d.Lod(p3d.RES_HITPOINTS)
    for _, name, parts, keep in HIT_POINTS:
        for part, vs, _ in pieces:
            if part not in parts:
                continue
            centre = Vector(np.asarray(vs).mean(0))
            if keep and not keep(centre):
                continue
            pts = [centre] + [Vector(v) for v in vs[:: max(1, len(vs) // 6)]]
            pts = [centre + (p - centre) * 0.7 for p in pts]
            base = lod.add_points(to_arma_np(pts))
            ids = range(base, base + len(pts))
            lod.select(name, ids)
            bone = BONE_OF.get(part, part)
            # Not the wheels: hiding a removed wheel's bone would pull its hit point to the
            # model's centre, and ACE puts "Replace wheel" at that point.
            if bone in BONES and not bone.startswith("wheel_"):
                lod.select(bone, ids)
    print("HITPOINTS", {n: len(lod.selections.get(n, ((), ()))[0]) for _, n, _, _ in HIT_POINTS})
    return lod


def comp_lod(res, pieces, parts_filter=None, mass=False, shrink=0.0):
    lod = p3d.Lod(res)
    vols = []
    n = 0
    for part, vs, tris in pieces:
        if parts_filter and part not in parts_filter:
            continue
        n += 1
        a = to_arma_np(inset(np.asarray(vs), shrink) if shrink else vs)
        base = lod.add_points(a)
        f0 = len(lod.faces)
        centre = a.mean(0)
        for t in tris:
            corners = [base + i for i in t]
            pts = lod.points[corners]
            outward = np.cross(pts[1] - pts[0], pts[2] - pts[0])
            if np.dot(outward, pts.mean(0) - centre) < 0:
                outward = -outward
            if p3d.orient_face(lod.points, corners, outward):
                corners = corners[::-1]
            nrm = outward / (np.linalg.norm(outward) or 1)
            lod.faces.append((corners, [nrm] * 3, [(0, 0)] * 3, "", ""))
        ids = range(base, base + len(a))
        lod.select(f"Component{n:02d}", ids, range(f0, len(lod.faces)))
        bone = BONE_OF.get(part, part)
        if bone in BONES:
            lod.select(bone, ids, range(f0, len(lod.faces)))
        vol = abs(sum(np.dot(a[t[0]] - centre, np.cross(a[t[1]] - centre, a[t[2]] - centre)) for t in tris)) / 6
        vols.append((ids, vol * DENSITY.get(part, 0.5), a))
    if mass:
        m = np.zeros(len(lod.points))
        for ids, vol, a in vols:
            m[list(ids)] = max(vol, 1e-3) / len(a)
        # P3D z is Blender y: put the centre of mass at COM_TARGET_Y.
        target = COM_TARGET_Y
        z = lod.points[:, 2]
        front, rear = z < target, z >= target
        f = np.sum(m[front] * (z[front] - target))
        r = np.sum(m[rear] * (z[rear] - target))
        if f < 0 and r > 0:
            m[front] *= -r / f
        m *= TOTAL_MASS / m.sum()
        lod.mass = m
        com = (m[:, None] * lod.points).sum(0) / m.sum()
        print("MASS", round(m.sum()), "centre of mass (Arma)", np.round(com, 3).tolist())
        lod.properties["autocenter"] = "0"
    print(f"LOD {res:g}: {n} components")
    return lod


# --- Memory points ----------------------------------------------------------------------------

def memory_points(parts):
    pts = {}  # name -> [(blender point), ...]
    pts["radar_axis"] = [HINGE + Vector((-1.25, 0, 0)), HINGE + Vector((1.25, 0, 0))]
    for side in "lr":
        for kind in "vd":
            p, u, _, x, w = strut_frame(kind, side)
            name = f"brace_{kind}_{side}"
            pts[f"{name}_axis"] = [p - x * 0.1, p + x * 0.1]
            pts[f"{name}_skew"] = [p, p + w]
            pts[f"{name}_slide"] = [p, p + u]
    pts["jack_axis"] = [Vector((0, 0, 0)), Vector((0, 0, 1))]
    pts["turntable_axis"] = [SPIN_CENTRE, SPIN_CENTRE + Vector((0, 0, 1))]
    for w, x in WHEEL.items():
        c = Vector((x, WHEEL_Y, WHEEL_Z))
        pts[f"wheel_{w}_axis"] = [c + Vector((-0.12, 0, 0)), c + Vector((0.12, 0, 0))]
        pts[f"wheel_{w}_bound"] = [c + Vector((0, 0, -WHEEL_R))]
    # Tongue stand foot: the bottom of the stand's caster.
    body = parts["body"]
    foot = [v.co for v in parts["stand"].verts if v.co.z < 0.03]
    stand = sum(foot, Vector()) / len(foot)
    pts["stand_foot"] = [Vector((stand.x, stand.y, 0.0))]
    for w, dx in (("1_1", 0.12), ("2_1", -0.12)):
        c = Vector((stand.x + dx, stand.y, STAND_WHEEL_R))
        pts[f"wheel_{w}_axis"] = [c + Vector((-0.04, 0, 0)), c + Vector((0.04, 0, 0))]
        pts[f"wheel_{w}_bound"] = [c + Vector((0, 0, -STAND_WHEEL_R))]
    lunette = max((v.co for v in body.verts if v.co.y < -2.9), key=lambda c: -c.y)
    pts["hitch"] = [Vector((0.0, lunette.y + 0.05, lunette.z))]
    # Where the ACE actions sit: the left side of the equipment box, in reach from the ground,
    # the generator's left side, and each leg's cylinder.
    pts["interact"] = [Vector((1.35, 1.0, 1.3))]
    pts["generator"] = [Vector((1.35, -0.8 - GENERATOR_SHIFT, 1.25))]
    for name, (x, y) in JACKS.items():
        pts[f"leg_{name}"] = [Vector((x + math.copysign(0.12, x), y, 0.75))]
    # Sound sources. The hum comes from in front of the array's face, which looks aft and
    # 26 degrees up, so it goes round with the antenna; the motor from the hinge.
    pts["hum_source"] = [HINGE + Vector((0, -0.85, 2.1)) + Vector((0, 0.9, 0.44)) * 2.0]
    pts["motor_source"] = [HINGE.copy()]
    # Where the tail lights glow from at night, while towed with the vehicle's lights on.
    pts["taillight"] = [Vector((0.0, 2.30, 0.95))]
    # Where a wreck burns (the inherited destruction effects): the generator and its tank, and
    # the middle of the trailer.
    pts["destructionEffect1"] = [Vector((0.0, -0.8 - GENERATOR_SHIFT, 1.2))]
    pts["destructionEffect2"] = [Vector((0.0, 1.2, 1.4))]
    # Sling lift points: the shackles at the front corners of the frame, the eyes at the back.
    for i, (x, y, z) in enumerate(((1.228, -1.14, 0.97), (-1.228, -1.14, 0.97), (1.256, 2.465, 1.02), (-1.256, 2.465, 1.02)), 1):
        pts[f"SlingLoadCargo{i}"] = [Vector((x, y, z))]
    # Probes: a point on each moving part, so the test can check where Arma put it.
    probes = {"radar": HINGE + (Vector((0, 0.821 - 2.53, 6.0 - 1.78))), "turntable": Vector((1.2, 0.05, 1.68))}
    for side in "lr":
        for kind in "vd":
            p, u, length, _, _ = strut_frame(kind, side)
            probes[f"brace_{kind}_{side}"] = p + u * 0.3
            probes[f"brace_{kind}_{side}_rod"] = p + u * (length - 0.03)
    for name, (x, y) in JACKS.items():
        probes[f"jack_{name}"] = Vector((x, y, 0.03))
    for bone, p in probes.items():
        pts[f"probe_{bone}"] = [p]
    return pts, probes


ON_TURNTABLE = ("hum_source", "motor_source")


def memory_lod(pts):
    lod = p3d.Lod(p3d.RES_MEMORY)
    for name, plist in pts.items():
        base = lod.add_points(to_arma_np(plist))
        lod.select(name, range(base, base + len(plist)))
        if name.startswith("probe_"):
            lod.select(name[len("probe_"):], range(base, base + len(plist)))
        if name in ON_TURNTABLE:
            lod.select("turntable", range(base, base + len(plist)))
    return lod


def landcontact_lod(pts):
    lod = p3d.Lod(p3d.RES_LANDCONTACT)
    for name in ("wheel_1_2_bound", "wheel_2_2_bound", "stand_foot"):
        lod.add_points(to_arma_np(pts[name]))
    return lod


# --- model.cfg ---------------------------------------------------------------------------------

def model_cfg():
    def rot(name, axis, phase, deg):
        a, b = PHASES[phase]
        ang = ARMA_ROTATION_SIGN * math.radians(deg)
        return (f"            class {name} {{ type = \"rotation\"; source = \"ptf_gator_deploy\"; selection = \"{name}\"; "
                f"axis = \"{axis}\"; memory = 1; minValue = {a}; maxValue = {b}; angle0 = {ang:.6f}; angle1 = 0; }};")

    def move(name, axis, phase, offset):
        a, b = PHASES[phase]
        return (f"            class {name} {{ type = \"translation\"; source = \"ptf_gator_deploy\"; selection = \"{name}\"; "
                f"axis = \"{axis}\"; memory = 1; minValue = {a}; maxValue = {b}; offset0 = {offset}; offset1 = 0; }};")

    def strut(kind, side):
        # One animation per keyframe gap: each adds its step below its range and nothing
        # above it, so together they move linearly from key to key. Skew is listed before
        # pitch: Arma applies a bone's animations in order, and the strut tilts sideways in
        # its rest frame before it turns.
        bone = f"brace_{kind}_{side}"
        keys = strut_keys(kind, side)
        out = []
        for label, i, kind_, axis, sel in (("skew", 2, "rotation", f"{bone}_skew", bone),
                                           ("pitch", 1, "rotation", f"{bone}_axis", bone),
                                           ("slide", 3, "translation", f"{bone}_slide", f"{bone}_rod")):
            for j, (k0, k1) in enumerate(zip(keys, keys[1:])):
                step = k0[i] - k1[i]
                if abs(step) < 1e-5:
                    continue
                value = (f"angle0 = {ARMA_ROTATION_SIGN * math.radians(step):.6f}; angle1 = 0;" if kind_ == "rotation"
                         else f"offset0 = {step:.5f}; offset1 = 0;")
                out.append(f"            class {bone}_{label}{j} {{ type = \"{kind_}\"; source = \"ptf_gator_deploy\"; "
                           f"selection = \"{sel}\"; axis = \"{axis}\"; memory = 1; minValue = {k0[0]:.5f}; "
                           f"maxValue = {k1[0]:.5f}; {value} }};")
        return out

    anims = [rot("radar", "radar_axis", "radar", RADAR_STOW_DEG)]
    for side in "lr":
        anims += strut("v", side) + strut("d", side)
    for j in JACKS:
        anims.append(f"            class jack_{j} {{ type = \"translation\"; source = \"ptf_gator_leg_{j}\"; selection = \"jack_{j}\"; "
                     f"axis = \"jack_axis\"; memory = 1; minValue = 0; maxValue = {JACK_MAX_PHASE}; offset0 = {JACK_TRAVEL}; "
                     f"offset1 = {JACK_TRAVEL * (1 - JACK_MAX_PHASE)}; }};")
    anims.append(f"            class stand {{ type = \"translation\"; source = \"ptf_gator_stand\"; selection = \"stand\"; "
                 f"axis = \"jack_axis\"; memory = 1; minValue = 0; maxValue = 1; offset0 = 0; offset1 = {STAND_TRAVEL}; }};")
    anims.append(f"            class turntable {{ type = \"rotation\"; source = \"ptf_gator_spin\"; selection = \"turntable\"; "
                 f"axis = \"turntable_axis\"; memory = 1; sourceAddress = \"loop\"; minValue = 0; maxValue = 1; "
                 f"angle0 = 0; angle1 = {ARMA_ROTATION_SIGN * 2 * math.pi:.6f}; }};")
    for w, hit in (("1_2", "HitLF2Wheel"), ("2_2", "HitRF2Wheel")):
        # Towed, the trailer is placed rather than driven, so PhysX doesn't turn the wheels:
        # ptf_gator_wheels does (one turn per unit, PTF_GATOR_fnc_towLoop runs it).
        anims.append(f"            class wheel_{w}_towed {{ type = \"rotation\"; source = \"ptf_gator_wheels\"; selection = \"wheel_{w}\"; "
                     f"axis = \"wheel_{w}_axis\"; memory = 1; sourceAddress = \"loop\"; minValue = 0; maxValue = 1; "
                     f"angle0 = 0; angle1 = \"rad -360\"; }};")
        # Gone once shot off or taken off with ACE (a hide on the wheel's own bone).
        anims.append(f"            class wheel_{w}_destruct {{ type = \"hide\"; source = \"ptf_gator_{hit}\"; selection = \"wheel_{w}\"; "
                     f"minValue = 0; maxValue = 1; hideValue = 0.99; }};")
    for bone in ("markings_text", "markings_patch"):
        anims.append(f"            class {bone}_wreck {{ type = \"hide\"; source = \"damage\"; selection = \"{bone}\"; "
                     f"minValue = 0; maxValue = 1; hideValue = 0.99; }};")
    for w in WHEEL:
        anims.append(f"            class wheel_{w} {{ type = \"rotation\"; source = \"wheel\"; selection = \"wheel_{w}\"; "
                     f"axis = \"wheel_{w}_axis\"; memory = 1; sourceAddress = \"loop\"; minValue = 0; maxValue = 1; "
                     f"angle0 = 0; angle1 = \"rad -360\"; }};")
    bones = ",\n".join(f'            "{b}", "{p}"' for b, p in BONES.items())
    return f"""// Generated by tools/gator/build_model.py - do not hand-edit.
class CfgSkeletons
{{
    class Default
    {{
        isDiscrete = 1;
        skeletonInherit = "";
        skeletonBones[] = {{}};
    }};
    class PTF_GATOR_Skeleton: Default
    {{
        skeletonBones[] =
        {{
{bones}
        }};
    }};
}};
class CfgModels
{{
    class Default
    {{
        sectionsInherit = "";
        sections[] = {{}};
        skeletonName = "";
    }};
    class {MODEL_NAME}: Default
    {{
        skeletonName = "PTF_GATOR_Skeleton";
        sections[] = {{"camo1", "camo2", "camo3", "lights"}};
        class Animations
        {{
{chr(10).join(anims)}
        }};
    }};
}};
"""


# --- Checks ---------------------------------------------------------------------------------------

def overlap_report(parts):
    """Count touching triangles between each moving part and everything else, at several
    phases of the sequence, against the deployed pose as a baseline."""
    meshes = {}
    for part, bm in parts.items():
        me = decimated(bm, min(1.0, 8000 / max(1, tri_count(bm))), 0.02)
        meshes[part] = np.array([v.co for v in me.vertices]), [list(p.vertices) for p in me.polygons]
        bpy.data.meshes.remove(me)

    def tree(part, s):
        co, polys = meshes[part]
        m = np.array(part_matrix(part, s))
        moved = co @ m[:3, :3].T + m[:3, 3]
        return BVHTree.FromPolygons(moved.tolist(), polys)

    moving = [p for p in parts if p in BONES and not p.startswith("wheel")]
    report = {}
    for s in (1.0, 0.95, 0.85, 0.75, 0.6, 0.4, 0.2, 0.1, 0.0):
        trees = {p: tree(p, s) for p in parts}
        for p in moving:
            for q in parts:
                if q == p or (q in moving and q < p):
                    continue
                n = len(trees[p].overlap(trees[q]))
                if n:
                    report.setdefault(f"{p}~{q}", {})[s] = n
    bad = {}
    for pair, by_phase in sorted(report.items()):
        base = by_phase.get(1.0, 0)
        worse = {s: n for s, n in by_phase.items() if n > base + 2}
        print("OVERLAP", pair, by_phase)
        if worse:
            bad[pair] = worse
    print("OVERLAP_NEW", json.dumps(bad, default=str))

    # Spinning: everything on the turntable against everything that isn't.
    on = [p for p in parts if p.startswith(TURNTABLE_PARTS)]
    off = [p for p in parts if p not in on]

    def spun(part, yaw):
        co, polys = meshes[part]
        m = np.array(part_matrix(part, 1.0, yaw))
        return BVHTree.FromPolygons((co @ m[:3, :3].T + m[:3, 3]).tolist(), polys)

    fixed = {q: spun(q, 0) for q in off}
    base = {}
    for yaw in range(0, 360, 15):
        for p in on:
            t = spun(p, yaw)
            for q in off:
                n = len(t.overlap(fixed[q]))
                if yaw == 0:
                    base[(p, q)] = n
                elif n > base.get((p, q), 0) + 2:
                    bad.setdefault(f"spin {p}~{q}", {})[yaw] = n
    print("SPIN_OVERLAP", json.dumps({k: v for k, v in bad.items() if k.startswith("spin")}))
    return bad


def expected_probes(probes):
    """Where each probe should be when stowed and deployed, in Arma model space."""
    out = {}
    for bone, p in probes.items():
        out[bone] = {f"{s:g}": list(np.round(to_arma(part_matrix(bone, s) @ p), 4)) for s in (0.0, 0.5, 1.0)}
        # Deployed with the turntable a quarter turn round (spin phase 0.25).
        out[bone]["spin0.25"] = list(np.round(to_arma(part_matrix(bone, 1.0, 90.0) @ p), 4))
    return out


def render_review(parts, out_dir):
    """Workbench renders of the sequence, for a quick look without the game."""
    os.makedirs(out_dir, exist_ok=True)
    sc = bpy.context.scene
    for o in list(sc.objects):
        o.hide_render = True
    sc.render.engine = "BLENDER_WORKBENCH"
    sc.display.shading.light = "STUDIO"
    sc.display.shading.color_type = "OBJECT"
    sc.display.shading.show_cavity = True
    sc.render.resolution_x, sc.render.resolution_y = 1100, 800
    objs = {}
    palette = [(0.8, 0.3, 0.3, 1), (0.3, 0.7, 0.3, 1), (0.3, 0.4, 0.9, 1), (0.9, 0.8, 0.2, 1), (0.7, 0.3, 0.8, 1), (0.2, 0.8, 0.8, 1), (0.9, 0.5, 0.1, 1)]
    for i, (part, bm) in enumerate(sorted(parts.items())):
        me = decimated(bm, min(1.0, 30000 / max(1, tri_count(bm))), 0.0)
        o = bpy.data.objects.new("rev_" + part, me)
        o.color = (0.75, 0.75, 0.7, 1) if part in ("body", "pedestal") else palette[i % len(palette)]
        sc.collection.objects.link(o)
        objs[part] = o
    cd = bpy.data.cameras.new("revcam")
    cam = bpy.data.objects.new("revcam", cd)
    sc.collection.objects.link(cam)
    sc.camera = cam
    views = {"left": ((11, 0.3, 2.6), 30), "q": ((8.5, -8.5, 6.0), 35), "rear": ((-6, 10, 4.5), 35)}
    target = Vector((0, 0.3, 1.8))
    for s in (1.0, 0.85, 0.7, 0.5, 0.3, 0.1, 0.0):
        for part, o in objs.items():
            o.matrix_world = part_matrix(part, s)
        for vname, (pos, lens) in views.items():
            cam.location = pos
            cam.rotation_euler = (target - Vector(pos)).to_track_quat("-Z", "Y").to_euler()
            cd.lens = lens
            sc.render.filepath = os.path.join(out_dir, f"phase{s:.2f}_{vname}.png")
            bpy.ops.render.render(write_still=True)


def main():
    argv = sys.argv[sys.argv.index("--") + 1:]
    out_dir = argv[0]
    renders = argv[argv.index("--renders") + 1] if "--renders" in argv else None
    os.makedirs(out_dir, exist_ok=True)
    parts = load_parts()
    for name, bm in sorted(parts.items()):
        print(f"PART {name}: {tri_count(bm)} triangles")
    lods = [build_res_lod(parts, res, budget, piece) for res, budget, piece in RES_LODS]
    pieces = collision_pieces(parts)
    static = {"body", "pedestal"}
    # No shadow volume LOD: Arma cast it as well as the shadow buffer, and its convex hulls
    # (one bridging the array's top panel and a fitting beside it) stood proud of the flat
    # panel and shaded it in sharp polygons. The shadow buffer LODs alone cast true shadows.
    for res, budget, piece in SHADOW_BUFFER_LODS:
        lods.append(build_res_lod(parts, res, budget, piece, shadow=True))
    lods.append(comp_lod(p3d.RES_GEOMETRY, pieces, mass=True))
    lods.append(comp_lod(p3d.RES_PHYSX, pieces, parts_filter=static))
    mem, probes = memory_points(parts)
    lods.append(memory_lod(mem))
    lods.append(landcontact_lod(mem))
    lods.append(hitpoints_lod(pieces))
    lods.append(comp_lod(p3d.RES_VIEW_GEOMETRY, pieces))
    lods.append(comp_lod(p3d.RES_FIRE_GEOMETRY, pieces))
    p3d.write_mlod(os.path.join(out_dir, f"{MODEL_NAME}.p3d"), lods)
    with open(os.path.join(out_dir, "model.cfg"), "w", newline="\n") as f:
        f.write(model_cfg())
    bad = overlap_report(parts)
    info = {"probes": expected_probes(probes), "phases": PHASES, "overlaps": bad,
            "memory": {k: [list(np.round(to_arma(p), 4)) for p in v] for k, v in mem.items()}}
    with open(os.path.join(out_dir, "gator_model.json"), "w") as f:
        json.dump(info, f, indent=1, default=str)
    if renders:
        render_review(parts, renders)
    print("DONE")


if __name__ == "__main__":
    main()
