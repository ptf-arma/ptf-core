/*
 * Author: Paramarine Task Force
 * The air tracks layer on the Billet tablet's map (class blk_tabletLayers in config.cpp): the
 * aircraft the networked G/ATORs' radars see out to 10 km (PTF_GATOR_picture, refreshed every
 * two seconds). Billet asks once a second while the tablet is open; see Billet's
 * fn_tabletLayers for the format.
 *
 * ["draw"]: each aircraft as its MIL-STD symbol (but not one the tablet already draws as one
 *  of its own side's groups or their vehicles, Billet's blue force tracking) (Arma's NATO markers, as the tablet's groups
 *  use): hostile, friendly, or unknown by what the radar makes of it, rotary wing, fixed wing or
 *  drone, coloured hostile red, friendly blue, unknown yellow, neutral green; a leader line to
 *  where it will be in 30 seconds; and a label: type, height, speed.
 * ["tracks"]: its section of the map's Tracks list, hostile first, nearest the top within each;
 *  a click centres the map on the aircraft.
 * Besides the network's picture, a G/ATOR within OP_RANGE (its crew, at its operator console)
 * shows what its own radar sees, on the network or not. An aircraft its operator identified
 * (IFF, PTF_GATOR_fnc_console) shows as what it answered.
 *
 * Arguments:
 * 0: "draw" or "tracks" <STRING>
 *
 * Return Value:
 * Shapes <ARRAY>, or the Tracks section <HASHMAP>
 */
#include "..\script_gator.hpp"
params [["_cmd", "", [""]]];

(missionNamespace getVariable ["PTF_GATOR_picture", [0, [], [], []]]) params ["", "_radars", "", "_air"];
// and the G/ATORs here, what their own radars see
_air = +_air;
_radars = +_radars;
{
	private _radar = _x;
	if (alive _radar && {(_radars findIf {(_x select 1) isEqualTo _radar}) < 0}) then {
		private _iff = _radar getVariable ["PTF_GATOR_iff", createHashMap];
		{
			private _id = _x select 0;
			if (_air findIf {(_x select 0) isEqualTo _id} < 0) then {
				private _track = +_x;
				if (_id in _iff) then {_track set [2, _iff get _id]};
				_air pushBack _track;
			};
		} forEach (_radar getVariable ["PTF_GATOR_air", []]);
		_radars pushBack [getPosASL _radar, _radar];
	};
} forEach (nearestObjects [player, ["PTF_GATOR"], OP_RANGE]);
private _colour = createHashMapFromArray [["enemy", [1, 0.353, 0.282]], ["unknown", [1, 0.86, 0.2]], ["friendly", [0.345, 0.651, 1]], ["neutral", [0.298, 0.761, 0.431]]];
private _word = createHashMapFromArray [["enemy", "HOSTILE"], ["unknown", "UNKNOWN"], ["friendly", "FRIEND"], ["neutral", "NEUTRAL"]];
// MIL-STD frames as Arma's markers have them: hostile (diamond), friendly (rectangle), and
// neutral (square) also for unknown, which has no marker of its own
private _frame = createHashMapFromArray [["enemy", "o"], ["friendly", "b"], ["neutral", "n"], ["unknown", "n"]];

if (_cmd == "tracks") exitWith {
	if (isNil {missionNamespace getVariable "PTF_GATOR_picture"}) exitWith {nil};
	private _rank = createHashMapFromArray [["enemy", 0], ["unknown", 1], ["neutral", 2], ["friendly", 3]];
	private _home = (_radars param [0, [[0, 0]]]) select 0;
	private _sorted = [_air, [], {(_rank getOrDefault [_x select 2, 1]) * 100000 + ((_x select 3) distance2D _home)}] call BIS_fnc_sortBy;
	private _rows = _sorted apply {
		_x params ["", "_name", "_rel", "_at", "_height", "_speed", "_heading"];
		createHashMapFromArray [["label", format ["%1 · grid %2", _name, mapGridPosition _at]],
			["note", format ["%1 m · %2 km/h · heading %3", _height, _speed, _heading]],
			["value", _word getOrDefault [_rel, "UNKNOWN"]], ["tone", createHashMapFromArray [["enemy", "bad"], ["unknown", "acc"], ["friendly", "ok"]] getOrDefault [_rel, ""]],
			["at", _at]]
	};
	createHashMapFromArray [["title", "Air"], ["rows", _rows],
		["empty", ["No aircraft within 10 km", "Offline: no G/ATOR cabled to SATCOM"] select (_radars isEqualTo [])]]
};

if (_cmd != "draw") exitWith {[]};
private _shapes = [];
// Aircraft the tablet already draws as one of its own side's groups or their vehicles (Billet's
// blue force tracking) aren't drawn twice; they stay in the lists.
private _tracked = uiNamespace getVariable ["BLK_tabVehs", []];
private _groups = uiNamespace getVariable ["BLK_tabGroups", []];
{
	_x params ["_id", "_name", "_rel", "_at", "_height", "_speed", "_heading", ["_kind", "air"]];
	private _plane = objectFromNetId _id;
	if (_plane in _tracked || {!isNull _plane && {(group effectiveCommander _plane) in _groups}}) then {continue};
	private _c = _colour getOrDefault [_rel, [1, 0.86, 0.2]];
	private _lead = _speed * 30 / 3.6;   // metres in 30 s: km/h is m/s times 3.6
	_shapes pushBack ["line", _at, _at vectorAdd [sin _heading * _lead, cos _heading * _lead], _c + [0.8], 2];
	_shapes pushBack ["icon", _at, format ["\A3\ui_f\data\map\markers\nato\%1_%2.paa", _frame getOrDefault [_rel, "n"], _kind], 28, _c + [1], 0];
	_shapes pushBack ["text", _at, format ["%1  %2 M  %3 KM/H", toUpper _name, _height, _speed], _c + [1], 0.04, "sans"];
} forEach _air;
_shapes
