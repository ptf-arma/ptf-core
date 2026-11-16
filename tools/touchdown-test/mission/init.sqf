// In-game test of the touchdown guard (PTF_Scripts, PTF_fnc_touchdownGuardDamage).
// Run with: python tools/lha-test/run.py --mission tools/touchdown-test/mission
// Logs one "LHATEST PASS|FAIL <check> <detail>" line per check, and "LHATEST INFO"
// lines with what the engine actually passes to HandleDamage on a collision.
//
// The advanced flight model's random touchdown explosions can't be made to happen
// on demand, so this checks the guard's rules: gentle touchdowns are protected,
// and everything that should still do damage does.

private _check = {
	params ["_name", "_ok", ["_detail", ""]];
	diag_log format ["LHATEST %1 %2 %3", ["FAIL", "PASS"] select _ok, _name, _detail];
};

diag_log "LHATEST start";
waitUntil {time > 0};
disableUserInput true;
sleep 2;

["settings", (missionNamespace getVariable ["PTF_TouchdownGuardEnabled", false])
	&& {PTF_TouchdownGuardMaxSpeed == 30} && {PTF_TouchdownGuardMaxDescent == 4},
	format ["%1 %2 %3", missionNamespace getVariable "PTF_TouchdownGuardEnabled",
		missionNamespace getVariable "PTF_TouchdownGuardMaxSpeed", missionNamespace getVariable "PTF_TouchdownGuardMaxDescent"]] call _check;

// Open ground on Stratis airbase, away from the player.
private _ground = {
	params ["_offset"];
	private _p = (getPosATL player) vectorAdd _offset;
	[_p select 0, _p select 1, 0]
};
private _spawn = {
	params ["_offset", ["_height", 0]];
	private _pos = [_offset] call _ground;
	private _heli = createVehicle ["PTF_UH1Y", _pos vectorAdd [0, 0, _height], [], 0, "CAN_COLLIDE"];
	_heli setPosATL (_pos vectorAdd [0, 0, _height]);
	_heli setDir 0;
	// Record what the engine passes on every hit. Added before the guard's own
	// handler (that one comes a frame later), returns nothing, so it changes nothing.
	_heli setVariable ["TEST_hits", []];
	_heli addEventHandler ["HandleDamage", {
		params ["_v", "_sel", "_dmg", "_src", "_proj", "_idx", "_inst", "_hp"];
		(_v getVariable "TEST_hits") pushBack [_hp, _dmg, _proj, typeOf _src, isNull _inst, velocity _v select 2];
		nil
	}];
	_heli
};
private _worst = {
	params ["_heli"];
	selectMax ([damage _heli] + ((getAllHitPointsDamage _heli) param [2, []]))
};

// ---------- the handler is on aircraft, not parachutes ----------
private _heli = [[60, 0, 0]] call _spawn;
private _chute = createVehicle ["Steerable_Parachute_F", ([[60, 40, 0]] call _ground) vectorAdd [0, 0, 300], [], 0, "CAN_COLLIDE"];
sleep 1;
["handler added", (_heli getVariable ["PTF_touchdownGuard_eh", -1]) >= 0 && {_heli in PTF_touchdownGuard_aircraft},
	str (_heli getVariable "PTF_touchdownGuard_eh")] call _check;
["not on parachutes", isNil {_chute getVariable "PTF_touchdownGuard_eh"}, str (_chute getVariable "PTF_touchdownGuard_eh")] call _check;
deleteVehicle _chute;
["sampler running", count (_heli getVariable ["PTF_touchdownGuard_samples", []]) == 2,
	str (_heli getVariable "PTF_touchdownGuard_samples")] call _check;

// ---------- the rules, called directly ----------
private _quad = createVehicle ["B_Quadbike_01_F", [[60, 30, 0]] call _ground, [], 0, "CAN_COLLIDE"];
createVehicleCrew _quad;
private _hull = ((getAllHitPointsDamage _heli) select 0) find "HitHull";
private _rotor = ((getAllHitPointsDamage _heli) select 0) findIf {"rotor" in toLower _x};
private _gentle = [[0, [1, 0.5, -1], 1], [-0.1, [1, 0.5, -1.2], 1.2]];
// Samples: [age, velocity, height]. Args: source, projectile, hit index, instigator, hit point.
{
	_x params ["_name", "_samples", "_args", "_protect"];
	_args params [["_src", objNull], ["_proj", ""], ["_idx", -1], ["_inst", objNull], ["_hp", ""]];
	private _result = [];
	isNil {
		_heli setVariable ["PTF_touchdownGuard_samples", _samples apply {[time + (_x select 0), _x select 1, _x select 2]}];
		private _r = [_heli, "", 0.95, _src, _proj, _idx, _inst, _hp] call PTF_fnc_touchdownGuardDamage;
		_result = [isNil "_r", if (isNil "_r") then {-1} else {_r}];
	};
	_result params ["_untouched", "_value"];
	private _kept = if (_idx < 0) then {damage _heli} else {_heli getHitIndex _idx};
	private _ok = [_untouched, !_untouched && {_value == _kept}] select _protect;
	[format ["rule: %1", _name], _ok, format ["%1, returned %2", ["passes damage on", "protected"] select _protect, [_value, "nothing"] select _untouched]] call _check;
} forEach [
	["gentle touchdown", _gentle, [], true],
	["gentle touchdown, hull", _gentle, [objNull, "", _hull, objNull, "HitHull"], true],
	["own collision source", _gentle, [_heli], true],
	["hard landing", [[0, [0, 0, -6], 1], [-0.1, [0, 0, -5], 1.5]], [], false],
	["fast", [[0, [15, 0, -1], 1], [-0.1, [15, 0, -1], 1.2]], [], false],
	["high up", [[0, [0, 0, -1], 8], [-0.1, [0, 0, -1], 8.1]], [], false],
	["stale samples", [[-1, [0, 0, -1], 1], [-1.1, [0, 0, -1], 1.2]], [], false],
	["one sample", [[0, [0, 0, -1], 1]], [], false],
	["bullet", _gentle, [objNull, "B_762x51_Ball"], false],
	["someone fired it", _gentle, [objNull, "", -1, player], false],
	["rammed by a crewed vehicle", _gentle, [_quad], false],
	["rotor strike", _gentle, [objNull, "", _rotor, objNull, "HitHRotor"], false]
];
PTF_TouchdownGuardEnabled = false;
private _off = [];
isNil {
	_heli setVariable ["PTF_touchdownGuard_samples", _gentle apply {[time + (_x select 0), _x select 1, _x select 2]}];
	private _r = [_heli, "", 0.95, objNull, "", -1, objNull, ""] call PTF_fnc_touchdownGuardDamage;
	_off = [isNil "_r"];
};
PTF_TouchdownGuardEnabled = true;
["switched off", _off select 0] call _check;
{deleteVehicle _x} forEach crew _quad;
deleteVehicle _quad;

// ---------- the real engine ----------
// Gunfire on a parked helicopter: low and still, so the samples say "gentle", and
// it must take damage anyway.
private _target = (getPosASL _heli) vectorAdd [0, 0, 1.2];
private _from = _target vectorAdd [-8, 0, 0];
for "_i" from 1 to 5 do {
	private _bullet = createVehicle ["B_127x99_Ball", [0, 0, 0], [], 0, "CAN_COLLIDE"];
	_bullet setPosASL _from;
	_bullet setVelocity ((_from vectorFromTo _target) vectorMultiply 900);
	sleep 0.2;
};
sleep 1;
["gunfire still damages", ([_heli] call _worst) > 0, format ["worst %1", [_heli] call _worst]] call _check;
diag_log format ["LHATEST INFO gunfire hits %1", (_heli getVariable "TEST_hits") select [0, 6]];
deleteVehicle _heli;

// A hard drop from 20 m: must be damaged. Its hits show what a collision looks like
// to HandleDamage (no projectile, nobody behind it), which the guard relies on.
private _drop = [[60, -40, 0], 20] call _spawn;
sleep 6;
private _hits = _drop getVariable "TEST_hits";
["hard drop damages", !alive _drop || {([_drop] call _worst) > 0.3}, format ["alive %1, worst %2", alive _drop, [_drop] call _worst]] call _check;
diag_log format ["LHATEST INFO hard drop hits %1", _hits select [0, 8]];
["collisions have no projectile", _hits isNotEqualTo [] && {(_hits findIf {(_x select 2) != "" || {!(_x select 4)}}) < 0},
	format ["%1 hits, first %2", count _hits, _hits param [0, []]]] call _check;
deleteVehicle _drop;

// Gentle set-downs, guard on: undamaged.
private _soft = [];
for "_i" from 0 to 3 do {
	private _h = [[-60, 15 * _i, 0], 1.5] call _spawn;
	_h setVelocity [0, 0, -1];
	_soft pushBack _h;
};
sleep 6;
["gentle set-down undamaged", (_soft findIf {!alive _x || {([_x] call _worst) > 0.05}}) < 0,
	str (_soft apply {[alive _x, ([_x] call _worst) toFixed 2]})] call _check;
{deleteVehicle _x} forEach _soft;

diag_log "LHATEST DONE";
sleep 1;
endMission "END1";
