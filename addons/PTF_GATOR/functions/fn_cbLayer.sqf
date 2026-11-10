/*
 * Author: Paramarine Task Force
 * The counter-battery layer on the Billet tablet's map (class blk_tabletLayers in config.cpp),
 * from the network's picture (PTF_GATOR_picture). Billet asks once a second while the tablet
 * is open; see Billet's fn_tabletLayers for the format.
 *
 * ["draw"]: in the tablet's MIL-STD style and hostile red:
 *  - each firing point: the hostile mortar or artillery symbol (Arma's NATO markers, as the
 *    tablet's groups use) in a ring as wide as its likely miss, where its rounds landed
 *    (crosses, lines back to it), and a label: track, rounds, miss, how long ago
 *  - each bearing (fired from beyond 10 km): a dashed line out from its G/ATOR, and a label
 *  Tracks not heard from for ten minutes fade.
 * ["tracks"]: its section of the map's Tracks list, newest first: each firing point's grid,
 *  likely miss and rounds (a click centres the map on it), hot (red) for two minutes, with an
 *  Erase button on each and Clear all on the section. Rounds coming down: where, and in how
 *  many seconds (the G/ATOR's prediction).
 *  Besides the network's picture, a G/ATOR within OP_RANGE (its crew, at its operator console)
 *  shows its own tracks, on the network or not.
 * ["action", action, key]: those buttons ("erase" a track by its number, "clear" them all),
 *  done on the server (PTF_GATOR_fnc_cbErase).
 *
 * Arguments:
 * 0: "draw", "tracks" or "action" <STRING>
 * 1: Action ("erase" or "clear") <STRING>
 * 2: Track number, as text <STRING>
 *
 * Return Value:
 * Shapes <ARRAY>, the Tracks section <HASHMAP>, or nil
 */
#include "..\script_gator.hpp"
#define RED [1, 0.353, 0.282]

params [["_cmd", "", [""]], ["_action", "", [""]], ["_key", "", [""]]];

if (_cmd == "action") exitWith {
	if (_action == "erase") then {[parseNumber _key] call PTF_GATOR_fnc_cbErase};
	if (_action == "clear") then {[-1] call PTF_GATOR_fnc_cbErase};
	nil
};

(missionNamespace getVariable ["PTF_GATOR_picture", [0, [], [], [], []]]) params ["", "_radars", "_tracks", "", ["_splashes", []]];
// and the G/ATORs here, their own
_tracks = +_tracks;
_splashes = +_splashes;
_radars = +_radars;
{
	private _radar = _x;
	if (alive _radar && {(_radars findIf {(_x select 1) isEqualTo _radar}) < 0}) then {
		{
			private _id = _x select 0;
			if (_tracks findIf {(_x select 0) isEqualTo _id} < 0) then {_tracks pushBack _x};
		} forEach (_radar getVariable ["PTF_GATOR_cbOwn", []]);
		_splashes append (_radar getVariable ["PTF_GATOR_splashes", []]);
		_radars pushBack [[0, 0], _radar];
	};
} forEach (nearestObjects [player, ["PTF_GATOR"], OP_RANGE]);
private _name = {params ["_id"]; format ["CB%1", [str _id, "0" + str _id] select (_id < 10)]};

if (_cmd == "tracks") exitWith {
	// Nobody's G/ATOR has ever been on the network: no section.
	if (isNil {missionNamespace getVariable "PTF_GATOR_picture"}) exitWith {nil};
	private _rows = ([_tracks, [], {_x select 5}, "DESCEND"] call BIS_fnc_sortBy) apply {
		_x params ["_id", "_kind", "_at", "_error", "_rounds", "_last", "", "_bearing", "_ammo", "_home", ["_weapon", "artillery"], ["_dwelt", false]];
		private _age = (CBA_missionTime - _last) max 0;
		private _ago = ["just now", format ["%1 min ago", floor (_age / 60)]] select (_age >= 60);
		private _hot = _age < 120;
		private _row = if (_kind == "bearing") then {
			createHashMapFromArray [["label", format ["%1 · bearing %2", [_id] call _name, round _bearing]],
				["note", format ["beyond 10 km · %1 rds · %2", _rounds, _ago]], ["value", "BRG"], ["tone", ["", "acc"] select _hot], ["at", _home]]
		} else {
			createHashMapFromArray [["label", format ["%1 · %2 · grid %3", [_id] call _name, _weapon, mapGridPosition _at]],
				["note", format ["%1 rds · %2%3%4", _rounds, _ago, ["", " · looked at closer"] select _dwelt, [format [" · %1", _ammo], ""] select (_ammo == "")]],
				["value", format ["±%1 m", round _error]], ["tone", ["", "bad"] select _hot], ["at", _at]]
		};
		_row set ["key", str _id];
		_row set ["actions", [createHashMapFromArray [["id", "erase"], ["label", "Erase"]]]];
		_row
	};
	createHashMapFromArray [["title", "Counter-battery"], ["rows", _rows],
		["actions", [[], [createHashMapFromArray [["id", "clear"], ["label", "Clear all"]]]] select (_rows isNotEqualTo [])],
		["empty", ["No enemy fire traced", "Offline: no G/ATOR cabled to SATCOM"] select (_radars isEqualTo [])]]
};

if (_cmd != "draw") exitWith {[]};
private _shapes = [];
{
	_x params ["_id", "_kind", "_at", "_error", "_rounds", "_last", "_impacts", "_bearing", "", "_home", ["_weapon", "artillery"]];
	private _age = (CBA_missionTime - _last) max 0;
	private _fade = [1, 0.45] select (_age > 600);
	private _ago = [format ["%1 MIN", floor (_age / 60)], "NOW"] select (_age < 60);
	if (_kind == "bearing") then {
		private _far = _home vectorAdd [sin _bearing * 1.3 * CB_TRACE, cos _bearing * 1.3 * CB_TRACE];
		// dashed: a dash every 600 m
		for "_d" from 0 to 1.3 * CB_TRACE - 300 step 600 do {
			private _a = _home vectorAdd [sin _bearing * _d, cos _bearing * _d];
			private _b = _home vectorAdd [sin _bearing * (_d + 300), cos _bearing * (_d + 300)];
			_shapes pushBack ["line", _a, _b, RED + [0.75 * _fade], 2];
		};
		_shapes pushBack ["text", _far, format ["%1  BRG %2  >10 KM  %3 RDS  %4", [_id] call _name, round _bearing, _rounds, _ago], RED + [_fade], 0.04, "sans"];
	} else {
		{
			_shapes pushBack ["line", _at, _x, RED + [0.4 * _fade], 2];
			_shapes pushBack ["icon", _x, "\A3\ui_f\data\map\markers\military\destroy_CA.paa", 16, [1, 0.6, 0.3, 0.9 * _fade], 0];
		} forEach _impacts;
		_shapes pushBack ["disc", _at, _error max 5, RED + [0.14 * _fade]];
		_shapes pushBack ["ring", _at, _error max 5, RED + [0.9 * _fade], 2];
		_shapes pushBack ["icon", _at, format ["\A3\ui_f\data\map\markers\nato\o_%1.paa", ["art", "mortar"] select (_weapon == "mortar")], 28, RED + [_fade], 0];
		_shapes pushBack ["text", _at, format ["%1  %2 RDS  ±%3 M  %4", [_id] call _name, _rounds, round _error, _ago], RED + [_fade], 0.04, "sans"];
	};
} forEach _tracks;
// Rounds coming down: where, and the seconds left.
{
	_x params ["_at", "_lands"];
	private _left = _lands - CBA_missionTime;
	if (_left > -2) then {
		_shapes pushBack ["ring", _at, SPLASH_WARN, [1, 0.6, 0.3, 0.5], 2];
		_shapes pushBack ["mark", _at, "x", 14, [1, 0.6, 0.3, 1]];
		_shapes pushBack ["text", _at, ["IMPACT", format ["SPLASH %1 S", ceil _left]] select (_left > 0), [1, 0.6, 0.3, 1], 0.04, "sans"];
	};
} forEach _splashes;
_shapes
