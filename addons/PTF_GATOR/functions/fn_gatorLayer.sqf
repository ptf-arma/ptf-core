/*
 * Author: Paramarine Task Force
 * The G/ATOR layer on the Billet tablet's map (class blk_tabletLayers in config.cpp), and on
 * its operator console (PTF_GATOR_fnc_console). The G/ATORs it shows are those on the network
 * (PTF_GATOR_picture) and any within OP_RANGE of this player (its crew, at the trailer).
 *
 * ["draw"]: in the tablet's own MIL-STD style:
 *  - its symbol: a friendly radar (data\gator_nato_ca.paa, made by tools/gator/make_icons.py
 *    to match Arma's NATO markers that the tablet draws groups with), in the tablet's blue
 *  - while it transmits, its sensor arc: an outline wedge out to where it hears rounds (2 km,
 *    less while jammed), pointing the way its array faces and turning with it (Billet's "beam"
 *    shape, in metres, so it is that size at any zoom). Billet asks once a second, so the arc
 *    is handed over with how fast it turns and Billet turns it every frame in between.
 *    Sweeping a sector, the sector is drawn too, and the arc pans back and forth across it.
 *  - its 2 km ring (where it hears rounds) and its 10 km ring (its reach)
 *  - CROWS jammers it hears: a strobe, a red line on the jammer's bearing; strobes from two
 *    places cross on the jammer
 *  - an anti-radiation missile inbound: a red line on its bearing, and its time to impact
 * ["tracks"]: the G/ATOR section of the map's Tracks list, to read: each one's state
 *  (automatic or manual, transmitting or silent, full turn or a sector), jamming and missiles
 *  inbound. It is worked from its operator console.
 *
 * Arguments:
 * 0: "draw" or "tracks" <STRING>
 *
 * Return Value:
 * Shapes <ARRAY>, the Tracks section <HASHMAP>, or nil
 */
#include "..\script_gator.hpp"
#define BLUE [0.345, 0.651, 1]
#define RED [1, 0.353, 0.282]
#define ARC_WIDTH 60
// a sweeping sector's beam, degrees
#define BEAM_WIDTH 20
// one turn in ptf_gator_spin's animPeriod (6 s); the array turns anticlockwise seen from above
#define TURN_RATE -60

params [["_cmd", "", [""]]];

private _near = (nearestObjects [player, ["PTF_GATOR"], OP_RANGE]) select {alive _x};

(missionNamespace getVariable ["PTF_GATOR_picture", [0, [], [], []]]) params ["", "_networked"];
private _radars = _networked apply {_x select 1};
{_radars pushBackUnique _x} forEach _near;
_radars = _radars select {!isNull _x};
private _ago = {
	params ["_t"];
	private _m = floor ((CBA_missionTime - _t) / 60);
	["just now", format ["%1 min ago", _m]] select (_m >= 1)
};

if (_cmd == "tracks") exitWith {
	if (_radars isEqualTo []) exitWith {nil};
	private _rows = [];
	{
		private _radar = _x;
		private _key = netId _radar regexReplace [":", "-"];
		private _at = getPosASL _radar;
		private _home = [_at select 0, _at select 1];
		private _deployed = alive _radar && {_radar animationSourcePhase "ptf_gator_deploy" > 0.999} && {[_radar] call PTF_GATOR_fnc_powerState == "on"};
		private _tx = !isNull (_radar getVariable ["PTF_GATOR_sensor", objNull]);
		private _sector = _radar getVariable ["PTF_GATOR_mode", "full"] == "sector";
		private _silent = _radar getVariable ["PTF_GATOR_emcon", false];
		private _jam = _radar getVariable ["PTF_GATOR_jam", 0];
		private _dwell = _radar getVariable ["PTF_GATOR_dwell", []];
		private _name = format ["G/ATOR · grid %1%2", mapGridPosition _radar, ["", " · offline"] select (isNull (_radar getVariable ["PTF_GATOR_satcom", objNull]))];

		// Its state.
		private _what = call {
			if (!alive _radar) exitWith {"Destroyed"};
			if (!_deployed) exitWith {"Not set up: array down or no power"};
			if (_silent) exitWith {"Silent (EMCON): sees nothing, gives nothing away"};
			if (_dwell isNotEqualTo []) exitWith {format ["Staring at %1 for a closer look", ["a track", "an aircraft (IFF)"] select ((_dwell select 0) == "iff")]};
			if (_sector) exitWith {format ["Sweeping %1° to %2°", (_radar getVariable ["PTF_GATOR_sector", [0, 0]]) select 0, (_radar getVariable ["PTF_GATOR_sector", [0, 0]]) select 1]};
			if (_tx) exitWith {"Transmitting, full turn"};
			"Array not turning"
		};
		_rows pushBack createHashMapFromArray [["key", _key], ["label", _name], ["at", _home],
			["note", format ["%1 · %2", ["Automatic", "Manual"] select (_radar getVariable ["PTF_GATOR_manual", false]), _what]],
			["value", ["OFF", ["SILENT", "TX"] select _tx] select (_deployed)], ["tone", ["", ["acc", "ok"] select _tx] select _deployed]];

		// CROWS jamming, and the jammers it hears.
		private _strobes = _radar getVariable ["PTF_GATOR_strobes", []];
		if (_jam > 0 || {_strobes isNotEqualTo []}) then {
			private _last = _strobes param [count _strobes - 1, []];
			_rows pushBack createHashMapFromArray [["key", _key + ".j"],
				["label", format ["Jamming%1", ["", format [" · strobe %1°", round (_last select 1)]] select (_last isNotEqualTo [])]],
				["note", [format ["Strobes: %1. Strobes from two places cross on the jammer.", count _strobes],
					format ["%1%% jammed: reach %2 km, tracks %3x rougher, false tracks likely",
						round (_jam * 100), (CB_DETECT * (1 - (1 - JAM_REACH) * _jam) / 1000) toFixed 1, (1 + (JAM_ERROR - 1) * _jam) toFixed 1]] select (_jam > 0)],
				["value", [format ["%1 STB", count _strobes], format ["%1%%", round (_jam * 100)]] select (_jam > 0)], ["tone", ["acc", "bad"] select (_jam > 0)], ["at", _home]];
		};

		// Anti-radiation missiles inbound.
		{
			_x params ["", "_eta", "_bearing", "_lost"];
			_rows pushBack createHashMapFromArray [["key", format ["%1.a%2", _key, _forEachIndex]],
				["label", format ["MISSILE INBOUND · bearing %1°", _bearing]],
				["note", ["Anti-radiation: homing on its emissions. Go silent to break its lock.", "Lost its lock: flying blind"] select _lost],
				["value", format ["%1 s", _eta]], ["tone", "bad"], ["at", _home]];
		} forEach (_radar getVariable ["PTF_GATOR_arm", []]);
	} forEach _radars;
	createHashMapFromArray [["title", "G/ATOR"], ["rows", _rows], ["empty", "No G/ATOR on the network"]]
};

if (_cmd != "draw") exitWith {[]};
private _seen = uiNamespace getVariable ["PTF_GATOR_faceSeen", createHashMap];
uiNamespace setVariable ["PTF_GATOR_faceSeen", _seen];
private _shapes = [];
{
	private _radar = _x;
	private _asl = getPosASL _radar;
	private _at = [_asl select 0, _asl select 1];
	_shapes pushBack ["ring", _at, CB_TRACE, BLUE + [0.3], 2];
	_shapes pushBack ["ring", _at, _radar getVariable ["PTF_GATOR_reach", CB_DETECT], BLUE + [0.55], 2];
	// strobes on the jammers it hears
	{
		_x params ["_from", "_bearing"];
		_shapes pushBack ["line", _from, _from vectorAdd [sin _bearing * JAM_HEAR, cos _bearing * JAM_HEAR], RED + [0.55], 2];
		if (_forEachIndex == count (_radar getVariable ["PTF_GATOR_strobes", []]) - 1) then {
			_shapes pushBack ["text", _from vectorAdd [sin _bearing * 3000, cos _bearing * 3000], format ["JAM %1°", round _bearing], RED + [0.9], 0.035, "sans"];
		};
	} forEach (_radar getVariable ["PTF_GATOR_strobes", []]);
	// missiles inbound
	{
		_x params ["", "_eta", "_bearing"];
		_shapes pushBack ["line", _at, _at vectorAdd [sin _bearing * 8000, cos _bearing * 8000], RED + [1], 3];
		_shapes pushBack ["text", _at vectorAdd [sin _bearing * 2500, cos _bearing * 2500], format ["ARM %1 S", _eta], RED + [1], 0.045, "sans"];
	} forEach (_radar getVariable ["PTF_GATOR_arm", []]);
	private _sweep = _radar getVariable ["PTF_GATOR_mode", "full"] == "sector";
	(_radar getVariable ["PTF_GATOR_sector", [0, 90]]) params ["_from", "_to"];
	private _span = ((_to - _from) + 360) % 360;
	private _reach = _radar getVariable ["PTF_GATOR_reach", CB_DETECT];
	if (_sweep) then {
		// the sector, out to where it hears rounds: its two edges and the arc between
		private _edge = {_at vectorAdd [sin _this * _reach, cos _this * _reach]};
		_shapes pushBack ["line", _at, _from call _edge, BLUE + [0.85], 2];
		_shapes pushBack ["line", _at, _to call _edge, BLUE + [0.85], 2];
		private _n = 2 max ceil (_span / 5);
		for "_i" from 1 to _n do {
			_shapes pushBack ["line", (_from + _span * (_i - 1) / _n) call _edge, (_from + _span * _i / _n) call _edge, BLUE + [0.85], 2];
		};
	};
	if (!isNull (_radar getVariable ["PTF_GATOR_sensor", objNull])) then {
		// Which way the array faces.
		private _heading = [_radar] call PTF_GATOR_fnc_facing;
		// How fast, from the last look a second ago (which way the spin runs, whatever the model
		// does), or the animation's own rate the first time.
		private _now = diag_tickTime;
		private _turn = 0;
		if (_radar getVariable ["PTF_GATOR_spinning", false]) then {
			_turn = TURN_RATE;
			(_seen getOrDefault [netId _radar, [0, -1]]) params ["_was", "_wasAt"];
			if (_now - _wasAt > 0.3 && {_now - _wasAt < 2.5}) then {
				_turn = (((_heading - _was) + 540) % 360 - 180) / (_now - _wasAt);
			};
		};
		_seen set [netId _radar, [_heading, _now]];
		if (_sweep && {isNil {_radar getVariable "PTF_GATOR_dwell"}}) then {
			// its beam, out to its reach, panning back and forth across the whole sector at the
			// antenna's turning speed (its middle runs from one edge to the other, less half its width)
			private _w = BEAM_WIDTH min _span;
			_shapes pushBack ["beam", _at, _reach, _heading, _w, BLUE + [0.95], 2, -TURN_RATE * (_radar getVariable ["PTF_GATOR_sweepDir", 1]), _now,
				_from + _w / 2, _span - _w];
		} else {
			_shapes pushBack ["beam", _at, _reach, _heading, ARC_WIDTH, BLUE + [0.95], 2, _turn, _now];
		};
	};
	_shapes pushBack ["icon", _at, "\z\PTF\addons\PTF_GATOR\data\gator_nato_ca.paa", 28, BLUE + [1], 0];
	_shapes pushBack ["text", _at, "G/ATOR", BLUE + [1], 0.04, "sans"];
} forEach _radars;
_shapes
