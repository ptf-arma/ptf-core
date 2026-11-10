// Shared numbers for the G/ATOR's scripts, from the model (tools/gator/build_model.py).
// Model space: x right, y forward, z up, origin on the ground under the middle of the trailer.

// The legs: how far phase 1 moves a foot, the furthest a leg runs, and seconds per unit of phase.
#define LEG_TRAVEL 0.30
#define LEG_MAX_PHASE 2
#define LEG_PERIOD 4
// Each leg's foot sole with the leg up (phase 0).
#define LEG_FOOT (createHashMapFromArray [["fl", [-1.4965, -0.3095, 0.30]], ["fr", [1.4965, -0.3095, 0.30]], ["rl", [-1.4965, -2.2355, 0.30]], ["rr", [1.4965, -2.2355, 0.30]]])
// Where the trailer otherwise touches the ground: under each wheel and the tongue stand.
#define REST_POINTS [[-1.426, -1.285, 0], [1.426, -1.285, 0], [0, 2.37, 0]]
// How long the trailer takes to level itself (and to settle back onto its wheels).
#define LEVEL_TIME 3
#define LEGS ["fl", "fr", "rl", "rr"]

// Counter-battery: a round is detected while within CB_DETECT metres of a transmitting
// G/ATOR; its firing point is traced back if within CB_TRACE metres; each traced point is off
// by CB_ERROR of its distance on average (the server's Addon Options setting, 4% by default,
// so 40 m at 1 km), and a track of n rounds by that over the square root of n.
#define CB_DETECT 2000
#define CB_TRACE 10000
// The array's height above the ground, where its sight line starts; how often a round in range
// but behind a hill is looked for again, in seconds.
#define CB_EYE 4.5
#define CB_LOOK 0.3
#define CB_ERROR ((missionNamespace getVariable ["PTF_GATOR_cbError", 4]) / 100)
// The incoming alarm: seconds it sounds after a round is traced, at most, and after the last
// traced round lands; its clip's repeat (tools/gator/import_sounds.py) and reach.
#define ALARM_HOLD 30
#define ALARM_TAIL 4
#define ALARM_PERIOD 7.183
#define ALARM_RANGE 2000

// The operator's radar: how close (m) a player must be to work it from a tablet; a sector's
// width (deg) and its accuracy (the share of the usual error); a dwell's length (s) and how
// much it tightens a track; the enemy's fix on a transmitting G/ATOR, per second, in full turn
// and sector mode, and how fast it fades when silent; the fix's levels, and their miss (m).
#define OP_RANGE 60
#define SECTOR_MIN 30
// The array's bearing at rest, round from the trailer's heading (PTF_GATOR_fnc_facing)
#define ARRAY_REST 180
#define SECTOR_GAIN 0.5
#define DWELL_TIME 5
#define DWELL_GAIN 0.5
#define FIX_RATE_FULL (1 / 240)
#define FIX_RATE_SECTOR (1 / 600)
#define FIX_FADE (1 / 300)
#define FIX_ROUGH 0.3
#define FIX_GOOD 0.6
#define FIX_LOCKED 0.85
#define FIX_MISS [500, 100, 25]
// Splash warnings: players this close (m) to where a traced round will land are warned.
#define SPLASH_WARN 200
// CROWS jammers: a G/ATOR hears one this far off (m), its strobe lasts (s), and at full
// jamming its reach shrinks to JAM_REACH of usual and its error grows by JAM_ERROR times.
#define JAM_HEAR 15000
#define JAM_STROBE_LIFE 600
#define JAM_REACH 0.4
#define JAM_ERROR 2.5
