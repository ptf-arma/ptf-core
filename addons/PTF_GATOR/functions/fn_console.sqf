/*
 * Author: Paramarine Task Force
 * The G/ATOR operator console: what its operator computer shows on the Billet tablet's console
 * slot (class blk_tabletConsoles in config.cpp; see Billet's fn_tabletConsole for the format).
 * The map is the tablet's, with the G/ATOR, counter-battery and air layers, this G/ATOR's own
 * picture on them whether it's on the network or not. Beside it, the panel: its controls, which
 * stay in view, and its lists, which scroll beneath them.
 *  - Control: automatic (it turns and transmits by itself) or manual (the operator has it)
 *  - in manual: Emissions (Transmit / Silent) and Scan (Full turn / Sector), and a sector's two
 *    edges, 15 degrees a click; the array sweeps back and forth between them
 *  - the incoming alarm
 *  - on its status bar, a missile inbound (bearing and seconds), rounds it traced coming down
 *    (how many, and seconds to the first; where, on the map) and how jammed it is
 *  - Counter-battery tracks (Look closer in manual, Erase, Clear all) and Air (Identify in
 *    manual); a click on a row centres the map on it
 * Each control is a command for PTF_GATOR_fnc_operator, which checks it again on the server.
 *
 * Arguments:
 * 0: "panel" or "action" <STRING>
 * 1: The operator computer <OBJECT>
 * 2: Action <STRING>
 * 3: Key <STRING>
 * 4: Value <STRING>
 *
 * Return Value:
 * The panel <HASHMAP>, or nil (the console closes)
 */
#include "..\script_gator.hpp"
params [["_cmd", "", [""]], ["_computer", objNull, [objNull]], ["_action", "", [""]], ["_key", "", [""]], ["_value", "", [""]]];

private _radar = _computer getVariable ["PTF_GATOR_radar", objNull];
if (isNull _radar) exitWith {nil};

if (_cmd == "action") exitWith {
	private _do = {params ["_c", ["_k", ""]]; [_radar, _c, _k, player] call PTF_GATOR_fnc_operator};
	switch (_action) do {
		case "alarm": {[["alarmOff", "alarmOn"] select (_value == "1")] call _do};
		case "iff": {["iff", _key regexReplace ["-", ":"]] call _do};
		case "dwell";
		case "erase": {[_action, _key] call _do};
		case "sectorFrom";
		case "sectorTo": {[_action, _value] call _do};
		default {[_action] call _do};
	};
	nil
};
if (_cmd != "panel") exitWith {nil};

private _block = {
	params ["_type", "_pairs"];
	private _b = createHashMapFromArray _pairs;
	_b set ["type", _type];
	_b
};
private _button = {
	params ["_id", "_label", ["_on", false], ["_tone", ""]];
	createHashMapFromArray [["id", _id], ["label", _label], ["on", _on], ["tone", _tone]]
};
private _act = {params ["_id", "_label"]; createHashMapFromArray [["id", _id], ["label", _label]]};

private _linked = (_radar getVariable ["PTF_GATOR_console", objNull]) isEqualTo _computer;
private _manual = _radar getVariable ["PTF_GATOR_manual", false];
private _deployed = alive _radar && {_radar animationSourcePhase "ptf_gator_deploy" > 0.999} && {[_radar] call PTF_GATOR_fnc_powerState == "on"};
private _tx = !isNull (_radar getVariable ["PTF_GATOR_sensor", objNull]);
private _silent = _radar getVariable ["PTF_GATOR_emcon", false];
private _sector = _radar getVariable ["PTF_GATOR_mode", "full"] == "sector";
(_radar getVariable ["PTF_GATOR_sector", [0, 90]]) params ["_from", "_to"];
private _dwell = _radar getVariable ["PTF_GATOR_dwell", []];
private _asl = getPosASL _radar;
private _home = [_asl select 0, _asl select 1];

// The status bar: a missile inbound first, then its state, and how jammed it is.
private _jam = _radar getVariable ["PTF_GATOR_jam", 0];
private _arm = (_radar getVariable ["PTF_GATOR_arm", []]) select {!(_x select 3)};
private _incoming = ((_radar getVariable ["PTF_GATOR_splashes", []]) apply {(_x select 1) - CBA_missionTime}) select {_x > 0};
private _state = call {
	if (!alive _radar) exitWith {["DESTROYED", "bad"]};
	if (_arm isNotEqualTo []) exitWith {[format ["MISSILE INBOUND · %1° · %2 S", (_arm select 0) select 2, (_arm select 0) select 1], "bad"]};
	if (_incoming isNotEqualTo []) exitWith {[format ["INCOMING · %1 RD%2 · FIRST IN %3 S", count _incoming, ["S", ""] select (count _incoming == 1), ceil selectMin _incoming], "bad"]};
	if (!_linked) exitWith {["NO CONNECTION: CABLE OUT", "bad"]};
	if (!_deployed) exitWith {["NOT SET UP", "acc"]};
	if (_silent) exitWith {["SILENT", "acc"]};
	if (_dwell isNotEqualTo []) exitWith {["LOOKING CLOSER", "ok"]};
	if (_tx) exitWith {[["TRANSMITTING · FULL TURN", format ["TRANSMITTING · SWEEPING %1°-%2°", _from, _to]] select _sector, "ok"]};
	["ARRAY NOT TURNING", "acc"]
};
if (_jam > 0 && {_arm isEqualTo []} && {_incoming isEqualTo []}) then {_state = [format ["JAMMED %1%% · %2", round (_jam * 100), _state select 0], "bad"]};
private _blocks = [];

// The controls.
_blocks pushBack (["buttons", [["id", "control"], ["label", "Control"],
	["note", "Automatic turns and transmits by itself and won't defend itself. Manual gives you emissions, scan, look closer and identify."],
	["buttons", [["auto", "Auto", !_manual] call _button, ["manual", "Manual", _manual] call _button]]]] call _block);
if (!_linked) then {
	_blocks pushBack (["note", [["text", "Cable out: plug the computer back in near the trailer."], ["tone", "bad"]]] call _block);
};
if (_manual && {_linked}) then {
	_blocks pushBack (["buttons", [["id", "emit"], ["label", "Emissions"],
		["note", "Silent, it sees nothing, missiles homing on it lose it, and the enemy's fix on it fades."],
		["buttons", [["transmit", "Transmit", !_silent] call _button, ["silent", "Silent", _silent, "bad"] call _button]]]] call _block);
	_blocks pushBack (["buttons", [["id", "scan"], ["label", "Scan"],
		["note", "A sector halves each round's miss and slows the enemy's fix; rounds and aircraft outside it go unseen."],
		["buttons", [["full", "Full turn", !_sector] call _button, ["sector", "Sector", _sector] call _button]]]] call _block);
	if (_sector) then {
		_blocks pushBack (["stepper", [["id", "sectorFrom"], ["label", "Sweep from"], ["value", _from], ["step", 15], ["wrap", 360], ["unit", "°"],
			["note", format ["The sector's left edge. It sweeps clockwise from here to the right edge, %1° across at least.", SECTOR_MIN]]]] call _block);
		_blocks pushBack (["stepper", [["id", "sectorTo"], ["label", "Sweep to"], ["value", _to], ["step", 15], ["wrap", 360], ["unit", "°"],
			["note", "The sector's right edge."]]] call _block);
	};
};
_blocks pushBack (["toggle", [["id", "alarm"], ["label", "Alarm"], ["on", _radar getVariable ["PTF_GATOR_alarm", false]],
	["note", "The incoming alarm: sounds at the trailer while traced rounds are in the air."]]] call _block);

// Counter-battery tracks: its own.
private _name = {params ["_id"]; format ["CB%1", [str _id, "0" + str _id] select (_id < 10)]};
private _tracks = ([_radar getVariable ["PTF_GATOR_cbOwn", []], [], {_x select 5}, "DESCEND"] call BIS_fnc_sortBy) apply {
	_x params ["_id", "_kind", "_at", "_error", "_rounds", "_last", "", "_bearing", "_ammo", "", ["_weapon", "artillery"], ["_dwelt", false]];
	private _age = (CBA_missionTime - _last) max 0;
	private _ago = ["just now", format ["%1 min ago", floor (_age / 60)]] select (_age >= 60);
	private _acts = [];
	if (_manual && {_kind == "point"} && {!_dwelt}) then {_acts pushBack (["dwell", "Look closer"] call _act)};
	_acts pushBack (["erase", "Erase"] call _act);
	if (_kind == "bearing") then {
		createHashMapFromArray [["key", str _id], ["label", format ["%1 · bearing %2°", [_id] call _name, round _bearing]], ["at", _home],
			["note", format ["Beyond 10 km · %1 rds · %2", _rounds, _ago]], ["value", "BRG"], ["tone", ["", "acc"] select (_age < 120)], ["actions", _acts]]
	} else {
		createHashMapFromArray [["key", str _id], ["label", format ["%1 · %2 · %3", [_id] call _name, _weapon, mapGridPosition _at]], ["at", _at],
			["note", format ["%1 rds · %2%3", _rounds, _ago, ["", " · looked at closer"] select _dwelt]],
			["value", format ["±%1 M", round _error]], ["tone", ["", "bad"] select (_age < 120)], ["actions", _acts]]
	};
};
_blocks pushBack (["list", [["title", "Counter-battery"], ["rows", _tracks], ["empty", "No enemy fire traced"],
	["actions", [[], [["clear", "Clear all"] call _act]] select (_tracks isNotEqualTo [])]]] call _block);

// Air: what its radar sees, as it identified them.
private _iff = _radar getVariable ["PTF_GATOR_iff", createHashMap];
private _word = createHashMapFromArray [["enemy", "HOSTILE"], ["unknown", "UNKNOWN"], ["friendly", "FRIEND"], ["neutral", "NEUTRAL"]];
private _air = (_radar getVariable ["PTF_GATOR_air", []]) apply {
	_x params ["_id", "_label", "_rel", "_at", "_height", "_speed", "_heading"];
	_rel = _iff getOrDefault [_id, _rel];
	createHashMapFromArray [["key", _id regexReplace [":", "-"]], ["label", format ["%1 · %2", _label, mapGridPosition _at]], ["at", _at],
		["note", format ["%1 m · %2 km/h · heading %3°", _height, _speed, _heading]],
		["value", _word getOrDefault [_rel, "UNKNOWN"]], ["tone", createHashMapFromArray [["enemy", "bad"], ["unknown", "acc"], ["friendly", "ok"]] getOrDefault [_rel, ""]],
		["actions", [[], [["iff", "Identify"] call _act]] select (_manual && {_rel == "unknown"})]]
};
_blocks pushBack (["list", [["title", "Air"], ["rows", _air], ["empty", ["Not transmitting", "No aircraft within 10 km"] select _tx]]] call _block);

createHashMapFromArray [["title", format ["G/ATOR · %1", mapGridPosition _radar]], ["status", _state select 0], ["tone", _state select 1], ["blocks", _blocks]]
