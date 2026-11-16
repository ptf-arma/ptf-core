// Short test of the operator role: the operator computer and manual control, its console (with
// a Billet build: --extra <billet>/mod/.hemttout/build/addons), staring at a sector (and pointing the array), a closer look
// and jamming's ghosts, lobbed rounds, small drones and missiles, CROWS jamming and taking a jammer's bearing, the enemy's fix and hunt (a shoot-and-scoot
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

// --- What else it sees: lobbed rounds, a small drone, a missile in flight -----------------------------------
// Lobbed: a tank's HE shell fired steeply by a man is traced; flat, or a 40 mm grenade, isn't.
private _lob = {
	params ["_ammo", "_pitch"];
	private _p = _radar getPos [5000, 270];
	private _shell = createVehicle [_ammo, [_p select 0, _p select 1, 800], [], 0, "CAN_COLLIDE"];
	_shell setVectorDirAndUp [[0, cos _pitch, sin _pitch], [0, -sin _pitch, cos _pitch]];
	private _before = count (missionNamespace getVariable ["PTF_GATOR_cbFlights", []]);
	[player, "", "", "", _ammo, "", _shell, objNull] call PTF_GATOR_fnc_cbFired;
	private _listed = count (missionNamespace getVariable ["PTF_GATOR_cbFlights", []]) > _before;
	deleteVehicle _shell;
	[_listed, getNumber (configFile >> "CfgAmmo" >> _ammo >> "indirectHit")]
};
private _lobs = [["Sh_120mm_HE", 45], ["Sh_120mm_HE", 3], ["G_40mm_HE", 45]] apply {_x call _lob};
call PTF_GATOR_fnc_cbWatch;
["lobbed: a big shell fired steeply is traced; flat, or a 40 mm grenade, isn't", (_lobs apply {_x select 0}) isEqualTo [true, false, false],
	format ["120 mm at 45°, 120 mm at 3°, 40 mm at 45°: %1", _lobs]] call _check;
// An RPG fired flat by a man 400 m off, where the radar can see along the ground to him: traced back to him.
private _rpgAt = [];
{
	private _p = _radar getPos [400, _x];
	if (_rpgAt isEqualTo [] && {!surfaceIsWater _p} && {!terrainIntersectASL [(getPosASL _radar) vectorAdd [0, 0, 4.5], (AGLToASL _p) vectorAdd [0, 0, 2]]}) then {_rpgAt = _p};
} forEach [0, 45, 90, 135, 180, 225, 270, 315];
private _rpgMan = (createGroup east) createUnit ["O_Soldier_LAT_F", _rpgAt, [], 0, "CAN_COLLIDE"];
_rpgMan disableAI "ALL";
private _rpgDir = _rpgAt getDir _radar;
private _rocket = createVehicle ["R_PG32V_F", (AGLToASL _rpgAt) vectorAdd [0, 0, 1.6], [], 0, "CAN_COLLIDE"];
_rocket setPosASL ((AGLToASL _rpgAt) vectorAdd [sin _rpgDir * 2, cos _rpgDir * 2, 1.6]);
_rocket setVectorDirAndUp [[sin (_rpgDir + 30), cos (_rpgDir + 30), 0], [0, 0, 1]];
_rocket setVelocity [sin (_rpgDir + 30) * 140, cos (_rpgDir + 30) * 140, 0];
[_rpgMan, "launch_RPG32_F", "", "", "R_PG32V_F", "", _rocket, objNull] call PTF_GATOR_fnc_cbFired;
sleep 2.5;
private _rpgTrack = (_radar getVariable ["PTF_GATOR_cbTracks", []]) select {(_x getOrDefault ["weapon", ""]) == "launcher"};
["an RPG fired flat by a man is traced back to him", _rpgAt isNotEqualTo [] && {_rpgTrack isNotEqualTo []}
	&& {((_rpgTrack select 0) getOrDefault ["point", [0, 0]]) distance2D _rpgAt < 80},
	format ["from %1, tracks %2", _rpgAt, _rpgTrack apply {[_x get "weapon", (_x getOrDefault ["point", [0, 0]]) distance2D _rpgAt]}]] call _check;
deleteVehicle _rpgMan;
{[_radar, "erase", str (_x get "id")] call PTF_GATOR_fnc_operator} forEach _rpgTrack;
// A small drone 900 m off, 80 m up.
private _uavAt = _radar getPos [900, 300];
private _uav = createVehicle ["B_UAV_01_F", [_uavAt select 0, _uavAt select 1, 80], [], 0, "FLY"];
createVehicleCrew _uav;
_uav flyInHeight 80;
_uav setVelocityModelSpace [0, 8, 0];
// A missile in flight: a Titan AA fired up and away to the north-east.
private _aa = createVehicle ["B_static_AA_F", _radar getPos [150, 45], [], 0, "NONE"];
createVehicleCrew _aa;
_aa allowDamage false;
sleep 1;
(gunner _aa) doWatch ((_aa getPos [2000, 45]) vectorAdd [0, 0, 1500]);
sleep 4;
[_aa, (_aa weaponsTurret [0]) param [0, ""]] call BIS_fnc_fire;
private _sawMissile = false;
private _sawUav = false;
for "_i" from 1 to 12 do {
	sleep 0.5;
	private _air = _radar getVariable ["PTF_GATOR_air", []];
	if (_air findIf {(_x param [7, ""]) == "missile"} >= 0) then {_sawMissile = true};
	if (_air findIf {(_x select 0) == netId _uav} >= 0) then {_sawUav = true};
};
["the small drone and the missile on the Air list", _sawUav && {_sawMissile},
	format ["drone %1, missile %2 (listed %3), air %4", _sawUav, _sawMissile, count (missionNamespace getVariable ["PTF_GATOR_missiles", []]),
		(_radar getVariable ["PTF_GATOR_air", []]) apply {[_x select 1, _x param [7, ""]]}]] call _check;
diag_log "GATORTEST SNAP air";
deleteVehicleCrew _uav;
deleteVehicle _uav;
deleteVehicleCrew _aa;
deleteVehicle _aa;

// --- CROWS jamming: a jammer 1 km east, as CROWS lists it (its jam map) ---------------------------------
private _jammer = createVehicle ["Land_Can_V3_F", _radar getPos [1000, 90], [], 0, "CAN_COLLIDE"];
private _crows = missionNamespace getVariable ["crowsEW_main_jamMap", createHashMap];
missionNamespace setVariable ["crowsEW_main_jamMap", createHashMapFromArray [[netId _jammer, [_jammer, 500, 1500, true, ["DroneJammer"]]]]];
sleep 2.5;
private _strobes = _radar getVariable ["PTF_GATOR_strobes", []];
private _status = (["panel", _computer] call PTF_GATOR_fnc_console) getOrDefault ["status", ""];
["jammed: shorter reach, rougher tracks, off the network; heard, no bearing yet", (_radar getVariable ["PTF_GATOR_jam", 0]) == 1 && {call _sensor == "PTF_GATOR_SensorJammed"}
	&& {abs ((_radar getVariable ["PTF_GATOR_reach", 0]) - 800) < 1} && {_strobes isEqualTo []} && {(_radar getVariable ["PTF_GATOR_dfShow", []]) isEqualTo [1, -1, -3]}
	&& {"OFF NET" in _status} && {!vehicleReportRemoteTargets (_radar getVariable ["PTF_GATOR_sensor", objNull])},
	format ["jam %1, sensor %2, reach %3, strobes %4, df %5, status %6", _radar getVariable ["PTF_GATOR_jam", 0], call _sensor, _radar getVariable ["PTF_GATOR_reach", 0],
		_strobes, _radar getVariable ["PTF_GATOR_dfShow", []], _status]] call _check;
// Its bearing, by hand: a sector away from it reads no signal; a wide one over it a weak one and no
// bearing; narrowed but off centre, no bearing; turned onto it, a stronger signal and a strobe
// along the sector's centre line after 8 s.
[_radar, "sector"] call PTF_GATOR_fnc_operator;
[_radar, "sectorFrom", "180"] call PTF_GATOR_fnc_operator;
[_radar, "sectorTo", "270"] call PTF_GATOR_fnc_operator;
sleep 2.5;
private _away = _radar getVariable ["PTF_GATOR_dfShow", []];
[_radar, "sectorFrom", "0"] call PTF_GATOR_fnc_operator;
[_radar, "sectorTo", "300"] call PTF_GATOR_fnc_operator;
sleep 2.5;
private _wide = _radar getVariable ["PTF_GATOR_dfShow", []];
[_radar, "sectorFrom", "85"] call PTF_GATOR_fnc_operator;
[_radar, "sectorTo", "175"] call PTF_GATOR_fnc_operator;
sleep 2.5;
private _offCentre = _radar getVariable ["PTF_GATOR_dfShow", []];
// the console's turn button, as the operator would: 5 degrees left, eight times
for "_i" from 1 to 8 do {["action", _computer, "panL", "", ""] call PTF_GATOR_fnc_console};
sleep 3;
private _counting = _radar getVariable ["PTF_GATOR_dfShow", []];
private _sector = _radar getVariable ["PTF_GATOR_sector", []];
diag_log "GATORTEST SNAP df";
sleep 7;
_strobes = _radar getVariable ["PTF_GATOR_strobes", []];
["a jammer's bearing takes the signal found and centred, then held", (_away select 1) <= 3 && {(_away select 2) == -3}
	&& {(_wide select 1) > 10} && {(_wide select 1) < 45} && {(_wide select 2) == -1}
	&& {(_offCentre select 2) == -2} && {_sector isEqualTo [45, 135]}
	&& {(_counting select 1) > (_wide select 1) + 25} && {(_counting select 2) > 0}
	&& {count _strobes == 1} && {((_strobes select 0) select 1) == 90} && {((_strobes select 0) param [4, 99]) <= 10}
	&& {((_radar getVariable ["PTF_GATOR_dfShow", []]) select 2) == 0},
	format ["away %1, wide %2, off centre %3, turned to %4: %5, then %6, strobes %7", _away, _wide, _offCentre, _sector, _counting,
		_radar getVariable ["PTF_GATOR_dfShow", []], _strobes]] call _check;
// back to the sector the console checks start from
[_radar, "sectorFrom", "60"] call PTF_GATOR_fnc_operator;
[_radar, "sectorTo", "120"] call PTF_GATOR_fnc_operator;
[_radar, "full"] call PTF_GATOR_fnc_operator;
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
	private _clicked = _radar getVariable ["PTF_GATOR_mode", ""] == "sector" && {(_radar getVariable ["PTF_GATOR_sector", []]) isEqualTo [60, 135]};
	// a bearing typed into the right edge's box, then Enter, on the page itself
	["(function () { const i = document.querySelector('[data-appset=sectorTo]'); if (!i) return; i.focus(); i.value = '200'; i.dispatchEvent(new KeyboardEvent('keydown', { key: 'Enter', bubbles: true })); })()"] call blk_fnc_tabletExec;
	sleep 3;
	private _typed = (_radar getVariable ["PTF_GATOR_sector", []]) isEqualTo [60, 200];
	// and one typed with no Enter at all: it goes in a moment after the last key
	["(function () { const i = document.querySelector('[data-appset=sectorFrom]'); if (!i) return; i.focus(); i.value = '75'; i.dispatchEvent(new Event('input', { bubbles: true })); })()"] call blk_fnc_tabletExec;
	sleep 3.5;
	_typed = _typed && {(_radar getVariable ["PTF_GATOR_sector", []]) isEqualTo [75, 200]};
	diag_log "GATORTEST SNAP console_typed";
	["con:full:scan:"] call blk_fnc_tabletMessage;
	sleep 1;
	["the console's buttons, steppers and typed bearings (Enter, or none) work the radar", _clicked && {_typed} && {_radar getVariable ["PTF_GATOR_mode", ""] == "full"},
		format ["clicked %1, typed %2, now %3", _clicked, _typed, _radar getVariable ["PTF_GATOR_sector", []]]] call _check;
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
