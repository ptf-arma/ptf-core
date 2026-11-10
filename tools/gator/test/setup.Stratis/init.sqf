// Short test: terrain masking (and its cost), setup jobs timed to their animations, letting go.
//   python tools/gator/test/run.py --mission tools/gator/test/setup.Stratis
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
player setPosATL (_radar modelToWorld [-3, 0, 0]);
sleep 6;

// --- Jobs timed to the animations ------------------------------------------------------------
// When does a source stop moving, after a job starts?
private _doneAfter = {
	params ["_source", ["_limit", 60]];
	private _t0 = time;
	private _was = -1;
	private _still = 0;
	waitUntil {
		sleep 0.05;
		private _p = _radar animationSourcePhase _source;
		if (_p == _was) then {_still = _still + 0.05} else {_still = 0};
		_was = _p;
		_still >= 0.3 || {time - _t0 > _limit}
	};
	time - _t0 - 0.3
};
private _expect = ((([_radar, "fl"] call PTF_GATOR_fnc_legReach) max 0.05 min 2) * 4);
[_radar, "legDown", "fl"] call PTF_GATOR_fnc_task;
private _took = ["ptf_gator_leg_fl"] call _doneAfter;
["leg's job lasts as long as it moves", abs (_took - _expect) < 0.35, format ["job %1 s, leg moved %2 s", _expect toFixed 2, _took toFixed 2]] call _check;
// Let go part way: it stops there.
[_radar, "legDown", "fr"] call PTF_GATOR_fnc_task;
sleep 1.5;
[_radar, "leg", "fr"] call PTF_GATOR_fnc_halt;
sleep 0.3;
private _held = _radar animationSourcePhase "ptf_gator_leg_fr";
sleep 1.5;
["let go: the leg stops where it is", _held > 0.2 && {_held < 0.6} && {(_radar animationSourcePhase "ptf_gator_leg_fr") == _held}
	&& {[_radar, "fr"] call PTF_GATOR_fnc_legState == "down"},
	format ["stopped at %1, now %2, %3", _held toFixed 2, (_radar animationSourcePhase "ptf_gator_leg_fr") toFixed 2, [_radar, "fr"] call PTF_GATOR_fnc_legState]] call _check;
// The rest by hand; the halted one comes up and goes down again.
[_radar, "legUp", "fr"] call PTF_GATOR_fnc_task;
sleep 3;
{[_radar, _x, true, true] call PTF_GATOR_fnc_setLeg} forEach ["fr", "rl", "rr"];
sleep 4;
["levels on the legs", _radar getVariable ["PTF_GATOR_leveled", false]] call _check;
// The generator: its job is its start.
[_radar, "power"] call PTF_GATOR_fnc_task;
private _t0 = time;
waitUntil {sleep 0.05; [_radar] call PTF_GATOR_fnc_powerState == "on" || {time - _t0 > 10}};
["generator's job lasts as long as its start", abs ((time - _t0) - 5) < 0.3, format ["on after %1 s", (time - _t0) toFixed 2]] call _check;
// The array: up 4 s, let go, then down from there: the job is what's left to travel.
[_radar, "raise"] call PTF_GATOR_fnc_task;
sleep 4;
[_radar, "array"] call PTF_GATOR_fnc_halt;
sleep 0.5;
private _part = _radar animationSourcePhase "ptf_gator_deploy";
sleep 1;
["let go: the array stops where it is", _part > 0.08 && {_part < 0.16} && {(_radar animationSourcePhase "ptf_gator_deploy") == _part}
	&& {[_radar, true] call PTF_GATOR_fnc_canSetDeployed} && {[_radar, false] call PTF_GATOR_fnc_canSetDeployed},
	format ["stopped at %1", _part toFixed 3]] call _check;
_expect = _part * 32;
[_radar, "lower"] call PTF_GATOR_fnc_task;
_took = ["ptf_gator_deploy"] call _doneAfter;
["array's job lasts as long as it moves", abs (_took - _expect) < 0.35 && {_radar animationSourcePhase "ptf_gator_deploy" < 0.001},
	format ["job %1 s, array moved %2 s", _expect toFixed 2, _took toFixed 2]] call _check;

// --- Terrain masking -----------------------------------------------------------------------------
[_radar, true, true] call PTF_GATOR_fnc_setDeployed;
sleep 1;
[_radar, true] call PTF_GATOR_fnc_setSpinning;
sleep 3;
private _eye = (getPosASL _radar) vectorAdd [0, 0, 4.5];
// a point 1.6 km off, 3 m over the ground, behind a hill from the array
private _hidden = [];
for "_b" from 0 to 355 step 5 do {
	private _p = _radar getPos [1600, _b];
	private _asl = [_p select 0, _p select 1, (getTerrainHeightASL _p) + 3];
	if (!surfaceIsWater _p && {terrainIntersectASL [_eye, _asl]}) exitWith {_hidden = _asl};
};
["found a spot behind a hill", _hidden isNotEqualTo [], str _hidden] call _check;
private _round = "Land_Can_V3_F" createVehicleLocal [0, 0, 0];
_round setPosASL _hidden;
_round enableSimulation false;
missionNamespace setVariable ["PTF_GATOR_cbFlights", [[_round, _hidden vectorAdd [800, 0, 0], CBA_missionTime, "Sh_82mm_AMOS", [], _hidden, "test.1", "mortar"]]];
call PTF_GATOR_fnc_cbWatch;
sleep 1;
["behind the hill: not traced", (_radar getVariable ["PTF_GATOR_cbTracks", []]) isEqualTo []] call _check;
_round setPosASL (_hidden vectorAdd [0, 0, 900]);
sleep 0.4;
call PTF_GATOR_fnc_cbWatch;
sleep 1;
["climbed into view: traced", count (_radar getVariable ["PTF_GATOR_cbTracks", []]) == 1] call _check;
deleteVehicle _round;
call PTF_GATOR_fnc_cbWatch;

// --- What it costs ---------------------------------------------------------------------------
// Worst case: 40 rounds in the air, all in range, all behind the hill, all looked at this tick.
private _many = [];
for "_i" from 1 to 40 do {
	private _r = "Land_Can_V3_F" createVehicleLocal [0, 0, 0];
	_r setPosASL (_hidden vectorAdd [_i, 0, 0]);
	_r enableSimulation false;
	_many pushBack _r;
};
private _flights = _many apply {[_x, _hidden, CBA_missionTime, "Sh_82mm_AMOS", [], _hidden, "x", "mortar", 0]};
private _watch = (diag_codePerformance [{
	missionNamespace setVariable ["PTF_GATOR_cbFlights", _this apply {+_x}];
	call PTF_GATOR_fnc_cbWatch
}, _flights, 200]) select 0;
private _idle = (diag_codePerformance [{
	missionNamespace setVariable ["PTF_GATOR_cbFlights", _this apply {private _f = +_x; _f set [8, 1e9]; _f}];
	call PTF_GATOR_fnc_cbWatch
}, _flights, 200]) select 0;
// a rifle shot while a G/ATOR transmits: the per-shot cost every gun pays
private _shot = (diag_codePerformance [{
	[player, "arifle_MX_F", "arifle_MX_F", "Single", "B_65x39_Caseless", "30Rnd_65x39_caseless_mag", objNull, player] call PTF_GATOR_fnc_cbFired
}, [], 2000]) select 0;
["it costs little", _watch < 0.5 && {_shot < 0.02}, format ["40 rounds all looked at %1 ms a tick (ten ticks a second, on the gun's machine), between looks %2 ms; a rifle shot %3 ms",
	_watch toFixed 3, _idle toFixed 3, _shot toFixed 4]] call _check;
{deleteVehicle _x} forEach _many;
missionNamespace setVariable ["PTF_GATOR_cbFlights", []];
diag_log "GATORTEST DONE";
