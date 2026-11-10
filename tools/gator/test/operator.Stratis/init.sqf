// Short test of the operator role: the operator computer and manual control, its console (with
// a Billet build: --extra <billet>/mod/.hemttout/build/addons), staring at a sector (and pointing the array), a closer look
// and jamming's ghosts, CROWS jamming and strobes, the enemy's fix and hunt (a shoot-and-scoot
// mortar team) with splash prediction, take cover, the tablet panel, the server tick's cost, and
// anti-radiation missiles (silent defeats one, transmitting takes the hit).
//   python tools/gator/test/run.py --mission tools/gator/test/operator.Stratis
private _check = {
	params ["_name", "_ok", ["_detail", ""]];
	diag_log format ["GATORTEST %1 %2 %3", ["FAIL", "PASS"] select _ok, _name, _detail];
};
diag_log "GATORTEST start";
waitUntil {time > 0};
private _spot = [[1950, 5750, 0], 0, 600, 15, 0, 0.06, 0] call BIS_fnc_findSafePos;
_spot set [2, 0];
private _radar = createVehicle ["PTF_GATOR", _spot, [], 0, "CAN_COLLIDE"];
_radar setDir 0;
_radar setPosATL _spot;
_radar allowDamage false;
player allowDamage false;
player setPosATL (_radar modelToWorld [-3, 0, 0]);
sleep 4;
{[_radar, _x, true, true] call PTF_GATOR_fnc_setLeg} forEach ["fl", "fr", "rl", "rr"];
[_radar, true, true] call PTF_GATOR_fnc_setPower;
sleep 1;
[_radar, true, true] call PTF_GATOR_fnc_setDeployed;
sleep 1;
[_radar, true] call PTF_GATOR_fnc_setSpinning;
sleep 2.5;
private _facing = {
	(_radar modelToWorldVisual (_radar selectionPosition ["turntable_axis", "Memory"])) getDir (_radar modelToWorldVisual (_radar selectionPosition ["hum_source", "Memory"]))
};
private _off = {params ["_a", "_b"]; abs (((_a - _b) + 540) % 360 - 180)};
private _sensor = {typeOf (_radar getVariable ["PTF_GATOR_sensor", objNull])};

// --- The operator computer: carried out on its cable, set down; manual control ------------------------
[_radar, "sector"] call PTF_GATOR_fnc_operator;
sleep 0.5;
private _refused = _radar getVariable ["PTF_GATOR_mode", "full"] == "full";
[_radar, "out", player] call PTF_GATOR_fnc_computer;
sleep 2;
private _computer = _radar getVariable ["PTF_GATOR_computer", objNull];
private _carried = !isNull _computer && {attachedTo _computer isEqualTo player};
[player, _computer] call ace_dragging_fnc_dropObject_carry;
sleep 2;
[_radar, "manual"] call PTF_GATOR_fnc_operator;
sleep 0.5;
["the computer: carried out, set down and cabled; manual control (refused before)", _refused && {_carried} && {isNull attachedTo _computer}
	&& {(_radar getVariable ["PTF_GATOR_console", objNull]) isEqualTo _computer} && {_radar getVariable ["PTF_GATOR_manual", false]},
	format ["refused %1, %2 carried %3, linked %4, manual %5, %6 m off", _refused, typeOf _computer, _carried,
		_radar getVariable ["PTF_GATOR_console", objNull], _radar getVariable ["PTF_GATOR_manual", false], round (_computer distance _radar)]] call _check;

// --- Sector: the array sweeps back and forth between two edges, 30 and 120 degrees -----------------------
[_radar, "sector"] call PTF_GATOR_fnc_operator;
[_radar, "sectorFrom", "30"] call PTF_GATOR_fnc_operator;
[_radar, "sectorTo", "120"] call PTF_GATOR_fnc_operator;
[_radar, "sectorTo", "45"] call PTF_GATOR_fnc_operator;   // too narrow: refused
sleep 3;
private _faced = [];
for "_i" from 1 to 80 do {sleep 0.1; _faced pushBack (call _facing)};
private _inside = _faced findIf {((_x - 30 + 360) % 360) > 94 && {((_x - 30 + 360) % 360) < 356}} < 0;
private _dir = 75;
private _entry = (missionNamespace getVariable ["PTF_GATOR_cbRadars", []]) param [0, []];
["sector: it sweeps between its edges, edge to edge", (_radar getVariable ["PTF_GATOR_sector", []]) isEqualTo [30, 120] && {_inside}
	&& {_faced findIf {([_x, 30] call _off) < 6} >= 0} && {_faced findIf {([_x, 120] call _off) < 6} >= 0}
	&& {(_entry param [3, []]) isEqualTo [30, 120]} && {(_radar getVariable ["PTF_GATOR_errScale", 1]) == 0.5},
	format ["sector %1, faced %2 to %3, listed %4", _radar getVariable ["PTF_GATOR_sector", []], round selectMin _faced, round selectMax _faced, _entry param [3, []]]] call _check;

// Rounds 1.2 km out, in the sector and behind it: only the one in it is traced.
private _round = {
	params ["_bearing", "_key"];
	private _p = _radar getPos [1200, _bearing];
	private _asl = [_p select 0, _p select 1, (getTerrainHeightASL _p) + 400];
	private _can = "Land_Can_V3_F" createVehicleLocal [0, 0, 0];
	_can setPosASL _asl;
	_can enableSimulation false;
	private _from = _radar getPos [3000, _bearing];
	[_can, AGLToASL _from, CBA_missionTime, "Sh_82mm_AMOS", [], _asl, _key, "mortar"]
};
private _flights = [[_dir, "t.in"] call _round, [_dir + 180, "t.out"] call _round];
missionNamespace setVariable ["PTF_GATOR_cbFlights", _flights];
call PTF_GATOR_fnc_cbWatch;
sleep 1;
private _tracks = _radar getVariable ["PTF_GATOR_cbTracks", []];
["sector: rounds outside it go unseen", count _tracks == 1 && {([_radar getDir ((_tracks select 0) get "point"), _dir] call _off) < 20},
	format ["%1 tracks", count _tracks]] call _check;
{deleteVehicle (_x select 0)} forEach _flights;
call PTF_GATOR_fnc_cbWatch;

// --- A closer look: the miss halves; a ghost goes -------------------------------------------------
private _track = _tracks select 0;
private _was = _track get "error";
[_radar, "dwell", str (_track get "id")] call PTF_GATOR_fnc_operator;
sleep 1.5;
private _staring = ((missionNamespace getVariable ["PTF_GATOR_cbRadars", []]) param [0, []]) param [4, false];
sleep 5;
["a closer look halves the miss, then back to the sweep", _staring && {_track getOrDefault ["dwelt", false]} && {abs ((_track get "error") - _was * 0.5) < 1}
	&& {_radar getVariable ["PTF_GATOR_mode", ""] == "sector"} && {isNil {_radar getVariable "PTF_GATOR_dwell"}},
	format ["miss %1 to %2 m, staring while it looked %3", round _was, round (_track get "error"), _staring]] call _check;
private _ghostAt = _radar getPos [4000, _dir];
private _id = (missionNamespace getVariable ["PTF_GATOR_cbNext", 0]) + 1;
missionNamespace setVariable ["PTF_GATOR_cbNext", _id];
_tracks pushBack createHashMapFromArray [["id", _id], ["kind", "point"], ["sum", [_ghostAt select 0, _ghostAt select 1]], ["point", [_ghostAt select 0, _ghostAt select 1]],
	["rounds", 1], ["error", 300], ["first", CBA_missionTime], ["last", CBA_missionTime], ["impacts", []], ["ammo", ""], ["weapon", "mortar"], ["false", true]];
[_radar, "dwell", str _id] call PTF_GATOR_fnc_operator;
sleep 6;
["a closer look finds jamming's ghost out", (_radar getVariable ["PTF_GATOR_cbTracks", []]) findIf {(_x get "id") == _id} < 0] call _check;
[-1] call PTF_GATOR_fnc_cbErase;

// --- Full turn again --------------------------------------------------------------------------------
[_radar, "full"] call PTF_GATOR_fnc_operator;
sleep 2;
["full turn again", _radar getVariable ["PTF_GATOR_spinning", false] && {call _sensor == "PTF_GATOR_Sensor"}, call _sensor] call _check;

// --- CROWS jamming: a jammer 1 km east, as CROWS lists it (its jam map) ---------------------------------
private _jammer = createVehicle ["Land_Can_V3_F", _radar getPos [1000, 90], [], 0, "CAN_COLLIDE"];
private _crows = missionNamespace getVariable ["crowsEW_main_jamMap", createHashMap];
missionNamespace setVariable ["crowsEW_main_jamMap", createHashMapFromArray [[netId _jammer, [_jammer, 500, 1500, true, ["DroneJammer"]]]]];
sleep 2.5;
private _strobes = _radar getVariable ["PTF_GATOR_strobes", []];
["jammed: shorter reach, rougher tracks, a strobe on the jammer", (_radar getVariable ["PTF_GATOR_jam", 0]) == 1 && {call _sensor == "PTF_GATOR_SensorJammed"}
	&& {abs ((_radar getVariable ["PTF_GATOR_reach", 0]) - 800) < 1} && {count _strobes == 1} && {([(_strobes select 0) select 1, 90] call _off) < 3},
	format ["jam %1, sensor %2, reach %3, strobes %4", _radar getVariable ["PTF_GATOR_jam", 0], call _sensor, _radar getVariable ["PTF_GATOR_reach", 0], _strobes]] call _check;
missionNamespace setVariable ["crowsEW_main_jamMap", _crows];
deleteVehicle _jammer;
sleep 2;

// --- The enemy's fix and hunt: a mortar team sent for it; where its rounds come down ----------------------
player setPosATL (_radar modelToWorld [-40, 0, 0]);
missionNamespace setVariable ["PTF_GATOR_enemyHunt", true];
_radar setVariable ["PTF_GATOR_fixRaw", 0.62];
sleep 2;
private _guns = missionNamespace getVariable ["PTF_GATOR_batteryGuns", []];
["a good fix: a mortar team is sent", (_radar getVariable ["PTF_GATOR_fix", 0]) == 2 && {count _guns == 1},
	format ["fix %1, %2 at %3 m", _radar getVariable ["PTF_GATOR_fix", 0], _guns apply {typeOf _x}, _guns apply {round (_x distance2D _radar)}]] call _check;
_radar setVariable ["PTF_GATOR_fixRaw", 0];
private _t0 = time;
waitUntil {sleep 1; time - _t0 > 75 || {(_radar getVariable ["PTF_GATOR_cbTracks", []]) findIf {count (_x get "impacts") >= 2} >= 0}};
sleep 6;
private _impacts = [];
{_impacts append (_x get "impacts")} forEach (_radar getVariable ["PTF_GATOR_cbTracks", []]);
private _splashes = _radar getVariable ["PTF_GATOR_splashes", []];
private _misses = _impacts apply {private _i = _x; selectMin (_splashes apply {(_x select 0) distance2D _i})};
["its rounds are traced and their splash predicted", _impacts isNotEqualTo [] && {selectMax _misses < 60},
	format ["%1 rounds down, predictions off by %2 m", count _impacts, _misses apply {round _x}]] call _check;
diag_log "GATORTEST SNAP warn";
["stop"] call PTF_GATOR_fnc_enemyBattery;
sleep 1;
["the battery packs up when told", (missionNamespace getVariable ["PTF_GATOR_batteryGuns", []]) isEqualTo []] call _check;
missionNamespace setVariable ["PTF_GATOR_enemyHunt", false];

// --- Take cover goes out over SATCOM only; the tablet reads, the console works -----------------------------
player setPosATL (_computer modelToWorld [0, -1.2, 0]);
player setDir (player getDir _computer);
private _section = ["tracks"] call PTF_GATOR_fnc_gatorLayer;
private _rows = _section getOrDefault ["rows", []];
private _shapes = ["draw"] call PTF_GATOR_fnc_gatorLayer;
["the tablet's G/ATOR section only reads", count _rows >= 2 && {_rows findIf {(_x getOrDefault ["actions", []]) isNotEqualTo []} < 0} && {count _shapes >= 5},
	format ["%1 rows (%2), %3 shapes", count _rows, _rows apply {_x get "label"}, count _shapes]] call _check;
private _panel = ["panel", _computer] call PTF_GATOR_fnc_console;
private _blocks = _panel getOrDefault ["blocks", []];
private _names = _blocks apply {_x getOrDefault ["id", _x getOrDefault ["title", ""]]};
["the console panel: control, emissions, scan, alarm, tracks, air",
	{_x in _names} count ["control", "emit", "scan", "alarm", "Counter-battery", "Air"] == 6 && {count _names == 6},
	format ["%1 · %2", _panel getOrDefault ["status", ""], _names]] call _check;
if (!isNil "blk_fnc_tabletConsole") then {
	["ptf_gator", _computer] call blk_fnc_tabletConsole;
	sleep 5;
	["the console opens on the Billet tablet", !isNull findDisplay 8890] call _check;
	diag_log "GATORTEST SNAP console";
	sleep 1;
	// its Sector button, as the page sends a click
	["con:sector:scan:"] call blk_fnc_tabletMessage;
	// and its right edge one click on, as the stepper sends it
	["con:sectorTo::135"] call blk_fnc_tabletMessage;
	sleep 3;
	diag_log "GATORTEST SNAP console_sector";
	sleep 4;
	private _clicked = _radar getVariable ["PTF_GATOR_mode", ""] == "sector" && {(_radar getVariable ["PTF_GATOR_sector", []]) isEqualTo [30, 135]};
	["con:full:scan:"] call blk_fnc_tabletMessage;
	sleep 1;
	["the console's buttons and steppers work the radar", _clicked && {_radar getVariable ["PTF_GATOR_mode", ""] == "full"},
		str (_radar getVariable ["PTF_GATOR_sector", []])] call _check;
	// walking away closes it
	player setPosATL (_computer modelToWorld [0, -6, 0]);
	sleep 1.5;
	["walking away closes it", isNull findDisplay 8890] call _check;
};

// --- What the server's tick costs, per G/ATOR, once a second ------------------------------------------------
private _cost = (diag_codePerformance [{[_this, true] call PTF_GATOR_fnc_operatorTick}, _radar, 500]) select 0;
["the operator tick costs little", _cost < 0.1, format ["%1 ms a second", _cost toFixed 4]] call _check;

// --- Anti-radiation missiles: silent defeats one; transmitting takes the hit -----------------------------------
player setPosATL (_radar modelToWorld [-300, 0, 0]);
_radar allowDamage true;
_radar setVariable ["PTF_GATOR_fixRaw", 0];
private _m = [_radar, 90, 9000] call PTF_GATOR_fnc_armLaunch;
sleep 2;
private _arm = _radar getVariable ["PTF_GATOR_arm", []];
[_radar, "silent"] call PTF_GATOR_fnc_operator;
sleep 1.6;
private _armLost = _radar getVariable ["PTF_GATOR_arm", []];
_t0 = time;
waitUntil {sleep 0.5; isNull _m || {time - _t0 > 30}};
sleep 2;
["missile warning; silent, it loses the G/ATOR", _arm isNotEqualTo [] && {(_radar getVariable ["PTF_GATOR_armLast", ""]) == "defeated"} && {alive _radar},
	format ["warned %1, then %4, %2, radar damage %3", _arm, _radar getVariable ["PTF_GATOR_armLast", ""], damage _radar, _armLost]] call _check;
[_radar, "transmit"] call PTF_GATOR_fnc_operator;
sleep 3;
_m = [_radar, 200, 6000] call PTF_GATOR_fnc_armLaunch;
_t0 = time;
waitUntil {sleep 0.5; isNull _m || {time - _t0 > 30}};
sleep 2;
["transmitting, it takes the hit", (_radar getVariable ["PTF_GATOR_armLast", ""]) == "hit",
	format ["%1, radar alive %2, damage %3", _radar getVariable ["PTF_GATOR_armLast", ""], alive _radar, damage _radar]] call _check;
diag_log "GATORTEST DONE";
