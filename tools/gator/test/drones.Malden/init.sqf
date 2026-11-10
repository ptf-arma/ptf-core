// Drones and CROWS jammers against the G/ATOR: how far it sees each drone in the modset, and
// what drones, strobes and jamming look like on its operator console.
//   python tools/gator/test/run.py --mission tools/gator/test/drones.Malden --full --extra <billet>/mod/.hemttout/build/addons
// (measures, takes screenshots, closes); with --keep the game stays open to look round (Zeus: Y).
//
// CROWS only runs its jammers in multiplayer (its main postInit exits in single player), so
// this registers its jammers in CROWS's own jammer list (crowsEW_main_jamMap), as CROWS's
// addJammer event does: the G/ATOR's side is the real thing, the radios aren't jammed.
private _check = {
	params ["_name", "_ok", ["_detail", ""]];
	diag_log format ["GATORTEST %1 %2 %3", ["FAIL", "PASS"] select _ok, _name, _detail];
};
diag_log "GATORTEST start";
waitUntil {time > 0};
setDate [2035, 7, 18, 11, 0];
0 setOvercast 0.15;
0 setFog 0;
forceWeatherChange;
player allowDamage false;
private _zeus = (createGroup sideLogic) createUnit ["ModuleCurator_F", [0, 0, 0], [], 0, "NONE"];
_zeus setVariable ["Addons", 3, true];
player assignCurator _zeus;

// --- Two G/ATORs, a few km apart, set up, transmitting and on the network --------------------------------
private _setUp = {
	params ["_near"];
	private _spot = [_near, 0, 900, 12, 0, 0.05, 0] call BIS_fnc_findSafePos;
	_spot = [_spot select 0, _spot select 1, 0];
	private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
	_radar allowDamage false;
	_radar setPosATL _spot;
	player setPosATL ((_radar modelToWorld [-4, 0, 0]) vectorMultiply [1, 1, 0]);
	sleep 3;
	{[_radar, _x, true, true] call PTF_GATOR_fnc_setLeg} forEach ["fl", "fr", "rl", "rr"];
	[_radar, true, true] call PTF_GATOR_fnc_setPower;
	sleep 1;
	[_radar, true, true] call PTF_GATOR_fnc_setDeployed;
	sleep 1;
	[_radar, true] call PTF_GATOR_fnc_setSpinning;
	// its SATCOM antenna, set down 8 m off
	[_radar, "out", player] call PTF_GATOR_fnc_satcom;
	sleep 2;
	private _antenna = _radar getVariable ["PTF_GATOR_antenna", objNull];
	[player, _antenna] call ace_dragging_fnc_dropObject;
	sleep 0.5;
	_antenna setPosATL ((_radar modelToWorld [-9, 4, 0]) vectorMultiply [1, 1, 0]);
	_zeus addCuratorEditableObjects [[_radar], true];
	_radar
};
private _radar2 = [[5400, 9600, 0]] call _setUp;
private _radar = [[8100, 10000, 0]] call _setUp;
// the first one's operator computer, set down, in manual
[_radar, "out", player] call PTF_GATOR_fnc_computer;
sleep 2;
private _computer = _radar getVariable ["PTF_GATOR_computer", objNull];
[player, _computer] call ace_dragging_fnc_dropObject_carry;
sleep 3;
[_radar, "manual"] call PTF_GATOR_fnc_operator;
["both G/ATORs up and on the network", {!isNull (_x getVariable ["PTF_GATOR_satcom", objNull]) && {!isNull (_x getVariable ["PTF_GATOR_sensor", objNull])}} count [_radar, _radar2] == 2,
	format ["%1 m apart", round (_radar distance2D _radar2)]] call _check;

// --- How far it sees each drone in the modset ---------------------------------------------------------
// Every drone type (one per model), flown at 150 m over the ground on its own bearing, brought
// in step by step from 9 km over the open sea east of the airfield (so no hill hides it); the
// first step its own radar has it (not the data link) is how far it sees it.
private _classes = [];
private _models = [];
{
	if (getNumber (_x >> "isUav") == 1 && {getNumber (_x >> "scope") == 2} && {configName _x isKindOf "Air"}) then {
		private _m = toLowerANSI getText (_x >> "model");
		if !(_m in _models) then {_models pushBack _m; _classes pushBack configName _x};
	};
} forEach ("true" configClasses (configFile >> "CfgVehicles"));
_classes = _classes select [0, 14];
private _drones = [];
{
	private _d = createVehicle [_x, _radar getPos [9000, 40 + 10 * _forEachIndex], [], 0, "FLY"];
	createVehicleCrew _d;
	_d allowDamage false;
	_d flyInHeight 150;
	(group driver _d) setBehaviourStrong "CARELESS";
	{_x disableAI "TARGET"; _x disableAI "AUTOTARGET"} forEach crew _d;
	_zeus addCuratorEditableObjects [[_d], true];
	_drones pushBack _d;
} forEach _classes;
private _seenAt = _drones apply {-1};
private _place = {
	params ["_d", "_dist", "_bearing"];
	private _p = _radar getPos [_dist, _bearing];
	_d setPosASL [_p select 0, _p select 1, ((getTerrainHeightASL _p) max 0) + 150];
	_d setDir ((_bearing + 180) % 360);
	_d setVelocityModelSpace [0, [20, 60] select (_d isKindOf "Plane"), 0];
};
{
	private _dist = _x;
	{[_x, _dist, 40 + 10 * _forEachIndex] call _place} forEach _drones;
	sleep 4.5;
	private _found = (getSensorTargets (_radar getVariable ["PTF_GATOR_sensor", objNull])) select {"activeradar" in (_x param [3, []])} apply {_x select 0};
	{
		if ((_seenAt select _forEachIndex) < 0 && {_x in _found}) then {_seenAt set [_forEachIndex, _dist]};
	} forEach _drones;
} forEach [9000, 7000, 5000, 4000, 3000, 2000, 1500, 1000, 600, 300];
{
	private _cfg = configOf _x;
	diag_log format ["GATORTEST INFO drone %1 (%2, radar size %3): %4", typeOf _x, getText (_cfg >> "displayName"),
		[1, getNumber (_cfg >> "radarTargetSize")] select (isNumber (_cfg >> "radarTargetSize")),
		[format ["first seen at %1 m", _seenAt select _forEachIndex], "never seen, down to 300 m"] select ((_seenAt select _forEachIndex) < 0)];
} forEach _drones;
["drones show on the radar", _seenAt findIf {_x > 0} >= 0, format ["%1 of %2 types seen", {_x > 0} count _seenAt, count _drones]] call _check;

// --- The picture: drones loitering 1 to 4 km out, on the operator console ------------------------------
{
	private _p = _radar getPos [1000 + 3000 * _forEachIndex / (count _drones max 1), _forEachIndex * 360 / count _drones + 15];
	[_x, _p distance2D _radar, _radar getDir _p] call _place;
	private _wp = (group driver _x) addWaypoint [_p, 0];
	_wp setWaypointType "LOITER";
	_wp setWaypointLoiterRadius 250;
} forEach _drones;
player setPosATL ((_computer modelToWorld [0, -1.2, 0]) vectorMultiply [1, 1, 0]);
player setDir (player getDir _computer);
sleep 6;
["ptf_gator", _computer] call blk_fnc_tabletConsole;
sleep 5;
// The console's map fitted to a place and a width (metres), as its own map moves.
private _fit = {
	params ["_centre", "_across"];
	private _map = (findDisplay 8890) displayCtrl 200;
	if (isNull _map) exitWith {};
	private _s = ctrlMapScale _map;
	for "_i" from 1 to 3 do {
		[_map, _centre, _s, 0] call (uiNamespace getVariable "BLK_tabCentre");
		sleep 0.4;
		(ctrlPosition _map) params ["_x0", "_y0", "_w", "_h"];
		private _now = ((_map ctrlMapScreenToWorld [_x0 + _w, _y0 + _h / 2]) select 0) - ((_map ctrlMapScreenToWorld [_x0, _y0 + _h / 2]) select 0);
		_s = (_s * _across / (_now max 1)) min 1;
	};
	[_map, _centre, _s, 0] call (uiNamespace getVariable "BLK_tabCentre");
	sleep 1.5;
};
[getPosASL _radar, 9000] call _fit;
["the console opens with drones on its air list", !isNull findDisplay 8890 && {(_radar getVariable ["PTF_GATOR_air", []]) isNotEqualTo []},
	format ["%1 aircraft listed", count (_radar getVariable ["PTF_GATOR_air", []])]] call _check;
diag_log "GATORTEST SNAP drones";
sleep 4;

// --- A CROWS jammer 5 km off: both G/ATORs hear it; their strobes cross on it -------------------------
private _jamAt = [];
for "_b" from 20 to 340 step 20 do {
	private _p = _radar getPos [5000, _b];
	if (!surfaceIsWater _p && {(_p distance2D _radar2) > 3000} && {abs ((((_radar getDir _p) - (_radar2 getDir _p)) + 540) % 360 - 180) > 30} && {_jamAt isEqualTo []}) then {_jamAt = _p};
};
if (_jamAt isEqualTo []) then {_jamAt = _radar getPos [5000, 210]};
private _jammer = createVehicle ["O_Truck_03_device_F", _jamAt, [], 0, "NONE"];
_jammer allowDamage false;
_zeus addCuratorEditableObjects [[_jammer], true];
private _jamMap = missionNamespace getVariable ["crowsEW_main_jamMap", createHashMap];
_jamMap set [netId _jammer, [_jammer, 1000, 1500, true, ["VoiceCommsJammer", "DroneJammer"]]];
missionNamespace setVariable ["crowsEW_main_jamMap", _jamMap];
sleep 4;
private _s1 = (_radar getVariable ["PTF_GATOR_strobes", []]) param [0, []];
private _s2 = (_radar2 getVariable ["PTF_GATOR_strobes", []]) param [0, []];
// where the two strobes cross (what a jammer fix would compute)
private _cross = [];
if (_s1 isNotEqualTo [] && {_s2 isNotEqualTo []}) then {
	_s1 params ["_p1", "_b1"];
	_s2 params ["_p2", "_b2"];
	private _den = (sin _b1) * (cos _b2) - (cos _b1) * (sin _b2);
	if (abs _den > 0.01) then {
		private _t = (((_p2 select 0) - (_p1 select 0)) * (cos _b2) - ((_p2 select 1) - (_p1 select 1)) * (sin _b2)) / _den;
		_cross = [(_p1 select 0) + _t * sin _b1, (_p1 select 1) + _t * cos _b1];
	};
};
["both G/ATORs strobe the far jammer, and the strobes cross on it", _cross isNotEqualTo [] && {(_cross distance2D _jammer) < 700} && {(_radar getVariable ["PTF_GATOR_jam", 0]) == 0},
	format ["strobes %1° and %2°, crossing %3 m from the jammer, %4 m off", round (_s1 param [1, -1]), round (_s2 param [1, -1]),
		[round (_cross distance2D _jammer), "-"] select (_cross isEqualTo []), round (_jammer distance2D _radar)]] call _check;
private _mid = ((getPosASL _radar) vectorAdd (getPosASL _radar2) vectorAdd (getPosASL _jammer)) vectorMultiply (1 / 3);
[_mid, 9000] call _fit;
diag_log "GATORTEST SNAP strobes";
sleep 4;

// --- A second jammer 1 km off: the first G/ATOR is jammed ----------------------------------------------
private _close = createVehicle ["O_Truck_03_device_F", _radar getPos [1000, (_radar getDir _jammer) + 40], [], 0, "NONE"];
_close allowDamage false;
_zeus addCuratorEditableObjects [[_close], true];
_jamMap set [netId _close, [_close, 1000, 1500, true, ["VoiceCommsJammer", "DroneJammer"]]];
sleep 4;
private _panel = ["panel", _computer] call PTF_GATOR_fnc_console;
["jammed: its reach shrinks, and the console says so", (_radar getVariable ["PTF_GATOR_jam", 0]) == 1 && {"JAMMED" in (_panel getOrDefault ["status", ""])},
	format ["jam %1, reach %2 m, status %3, %4 aircraft still seen", _radar getVariable ["PTF_GATOR_jam", 0], round (_radar getVariable ["PTF_GATOR_reach", 0]),
		_panel getOrDefault ["status", ""], count (_radar getVariable ["PTF_GATOR_air", []])]] call _check;
[getPosASL _radar, 9000] call _fit;
diag_log "GATORTEST SNAP jammed";
sleep 4;
diag_log "GATORTEST DONE";
