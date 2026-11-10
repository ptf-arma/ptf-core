// In-game test of the G/ATOR. Run with: python tools/gator/test/run.py
// Logs one "GATORTEST PASS|FAIL <check> <detail>" line per check. expected.sqf is written
// by run.py from the model build's notes: where each moving part's probe point should be.

private _check = {
	params ["_name", "_ok", ["_detail", ""]];
	diag_log format ["GATORTEST %1 %2 %3", ["FAIL", "PASS"] select _ok, _name, _detail];
};
private _shot = {
	params ["_name"];
	sleep 1.2;
	screenshot format ["gatortest_%1.png", _name];
	sleep 1.2;
};

diag_log "GATORTEST start";
waitUntil {time > 0};
disableUserInput true;
setDate [2035, 6, 15, 10, 0];
0 setOvercast 0.2;
forceWeatherChange;
showCinemaBorder false;
enableEnvironment false;

private _expected = call compile preprocessFileLineNumbers "expected.sqf";

["addon loaded", isClass (configFile >> "CfgPatches" >> "PTF_GATOR") && {isClass (configFile >> "CfgPatches" >> "ptf_gator_data")}] call _check;
["class", getNumber (configFile >> "CfgVehicles" >> "PTF_GATOR" >> "scope") == 2] call _check;

private _pos = [1500, 1500, 0];
private _radar = createVehicle ["PTF_GATOR", _pos, [], 0, "CAN_COLLIDE"];
_radar setDir 0;
_radar setPosATL _pos;
sleep 8;

private _up = vectorUp _radar;
["settles upright", (_up select 2) > 0.97 && {alive _radar} && {damage _radar < 0.05},
	format ["up %1 damage %2 pos %3", _up, damage _radar, getPosATL _radar]] call _check;
["stays put", (getPosATL _radar) distance2D _pos < 0.5 && {abs speed _radar < 0.5}, format ["moved %1 m, speed %2", (getPosATL _radar) distance2D _pos, speed _radar]] call _check;
["faces forward", ((_radar selectionPosition ["hitch", "Memory"]) select 1) > 2, str (_radar selectionPosition ["hitch", "Memory"])] call _check;
private _legs = ["fl", "fr", "rl", "rr"];
private _legPhases = {_legs apply {_radar animationSourcePhase ("ptf_gator_leg_" + _x)}};
private _sounds = {_radar getVariable ["PTF_GATOR_soundLog", []]};
private _heard = {params ["_class", ["_times", 1]]; {_x == _class} count (call _sounds) >= _times};
["starts packed up", _radar animationSourcePhase "ptf_gator_deploy" == 0 && {(call _legPhases) isEqualTo [0, 0, 0, 0]}
	&& {[_radar] call PTF_GATOR_fnc_powerState == "off"}, str (call _legPhases)] call _check;
["can't raise array without power or legs", !([_radar, true] call PTF_GATOR_fnc_canSetDeployed)] call _check;
["can't turn stowed", !([_radar, true] call PTF_GATOR_fnc_canSetSpinning)] call _check;
["can lower legs, not raise them", {[_radar, _x, true] call PTF_GATOR_fnc_canSetLeg && {!([_radar, _x, false] call PTF_GATOR_fnc_canSetLeg)}} count _legs == 4] call _check;
["can start generator", [_radar, true] call PTF_GATOR_fnc_canSetPower && {!([_radar, false] call PTF_GATOR_fnc_canSetPower)}] call _check;
["sound player running", !isNil {_radar getVariable "PTF_GATOR_soundStreams"}] call _check;

// Probe points against the model build's expectations, relative to the hitch (a point that
// never moves), so any recentring by Binarize doesn't matter.
private _probeCheck = {
	params ["_phase"];
	private _ref = _radar selectionPosition ["hitch", "Memory"];
	private _worst = 0;
	private _report = [];
	{
		_x params ["_bone", "_byPhase", "_hitch"];
		private _want = (_byPhase get _phase) vectorDiff _hitch;
		private _got = (_radar selectionPosition ["probe_" + _bone, "Memory"]) vectorDiff _ref;
		// A leg reaches down to the ground, wherever that is, so only where it stands counts.
		if (_bone select [0, 5] == "jack_") then {_got set [2, _want select 2]};
		private _err = _want distance _got;
		_worst = _worst max _err;
		if (_err > 0.05) then {_report pushBack format ["%1 off by %2 (want %3 got %4)", _bone, _err toFixed 2, _want, _got]};
	} forEach _expected;
	[format ["parts at phase %1", _phase], _report isEqualTo [], format ["worst %1 m; %2", _worst toFixed 3, _report]] call _check;
};

private _camera = "camera" camCreate [0, 0, 0];
_camera cameraEffect ["internal", "back"];
private _view = {
	params ["_offset", "_target", "_fov"];
	_camera camSetPos (_radar modelToWorld _offset);
	_camera camSetTarget (_radar modelToWorld _target);
	_camera camSetFov _fov;
	_camera camCommit 0;
	sleep 0.5;
};
private _views = [
	["left", [9, 1, 2.6], [0, 0, 1.6], 0.75],
	["quarter", [7, -7, 4.5], [0, 0, 1.6], 0.75],
	["rear", [-5, 8.5, 3.5], [0, 0, 1.6], 0.75]
];

{
	private _phase = _x;
	{[_radar, _x, _phase > 0, true] call PTF_GATOR_fnc_setLeg} forEach _legs;
	_radar animateSource ["ptf_gator_deploy", _phase, true];
	sleep 1;
	if (_phase in [0, 0.5, 1]) then {[_phase] call _probeCheck};
	{
		_x params ["_name", "_offset", "_target", "_fov"];
		[_offset, _target, _fov] call _view;
		[format ["phase%1_%2", round (_phase * 100), _name]] call _shot;
	} forEach (if (_phase in [0, 0.5, 1]) then {_views} else {[_views select 1]});
} forEach [0, 0.1, 0.3, 0.5, 0.7, 0.85, 0.95, 1];

// A quarter turn of the turntable, deployed.
_radar animateSource ["ptf_gator_spin", 0.25, true];
sleep 1;
["spin0.25"] call _probeCheck;
[[7, -7, 4.5], [0, 0, 1.6], 0.75] call _view;
["spin_quarter"] call _shot;
_radar animateSource ["ptf_gator_spin", 0, true];
sleep 1;

// Close-ups of the stowed and deployed details.
{
	[_radar, (_x select 0) == 1, true] call PTF_GATOR_fnc_setDeployed;
	sleep 1;
	[_x select 2, _x select 3, _x select 4] call _view;
	[_x select 1] call _shot;
} forEach [
	[0, "stowed_braces", [-4, -1, 3.2], [0, -0.5, 1.8], 0.45],
	[0, "stowed_jacks", [-3.5, -1.2, 0.8], [1.4, -1.2, 0.4], 0.5],
	[0, "stencil", [-3.8, -1.0, 1.5], [-1.1, -1.0, 1.45], 0.3],
	[1, "deployed_braces", [-4.5, 0.5, 3.2], [0, -1, 2.6], 0.5],
	[1, "deployed_jacks", [-3.5, -1.2, 0.8], [1.4, -1.2, 0.4], 0.5]
];

// The real thing, through the functions the ACE actions call, starting packed up.
[_radar, false, true] call PTF_GATOR_fnc_setDeployed;
sleep 2;
_radar setVariable ["PTF_GATOR_soundLog", []];
[[9, 1, 2.6], [0, 0, 1.6], 0.75] call _view;

// Legs, one at a time.
{
	["lower leg " + _x, [_radar, _x, true] call PTF_GATOR_fnc_setLeg] call _check;
	sleep 1;
} forEach _legs;
sleep 5;
["a clunk per leg", ["PTF_GATOR_leg_down", 4] call _heard, str (call _sounds)] call _check;
_t0 = time;
waitUntil {sleep 0.25; _radar getVariable ["PTF_GATOR_leveled", false] || {time - _t0 > 8}};
["legs down", [_radar] call PTF_GATOR_fnc_legsDown && {{_x > 0.95 && _x < 1.3} count (call _legPhases) == 4}, str (call _legPhases)] call _check;
["levels itself on its legs", _radar getVariable ["PTF_GATOR_leveled", false] && {(vectorUp _radar select 2) > 0.9995} && {!isNull attachedTo _radar},
	format ["up %1 attached %2 legs %3", vectorUp _radar, attachedTo _radar, call _legPhases]] call _check;
["still can't raise array: no power", !([_radar, true] call PTF_GATOR_fnc_canSetDeployed)] call _check;

// Generator.
["start generator", [_radar, true] call PTF_GATOR_fnc_setPower] call _check;
sleep 1;
["generator starting", [_radar] call PTF_GATOR_fnc_powerState == "starting" && {["PTF_GATOR_gen_start"] call _heard}, str (call _sounds)] call _check;
sleep 5;
["generator running", [_radar] call PTF_GATOR_fnc_powerState == "on" && {["PTF_GATOR_gen_loop"] call _heard}
	&& {"gen" in (_radar getVariable "PTF_GATOR_soundStreams")}, str (call _sounds)] call _check;

// Enemy AI hear it: a group 100 m off notices, one 400 m off doesn't.
private _marine = (createGroup west) createUnit ["B_Soldier_F", _radar modelToWorld [-4, 0, 0], [], 0, "CAN_COLLIDE"];
_marine disableAI "ALL";
private _near = (createGroup east) createUnit ["O_Soldier_F", _radar getPos [100, 200], [], 0, "CAN_COLLIDE"];
private _far = (createGroup east) createUnit ["O_Soldier_F", _radar getPos [400, 200], [], 0, "CAN_COLLIDE"];
{_x disableAI "ALL"; group _x setBehaviour "SAFE"} forEach [_near, _far];
sleep 1;
for "_i" from 1 to 6 do {[_radar] call PTF_GATOR_fnc_hearGenerator};
sleep 0.5;
// (The player stands within 30 m too, so either may be the one revealed.)
private _known = (group _near knowsAbout _marine) max (group _near knowsAbout player);
["enemy nearby hears the generator", behaviour _near == "AWARE" && {_known > 0.5} && {behaviour _far == "SAFE"},
	format ["near %1 knows %2, far %3", behaviour _near, _known, behaviour _far]] call _check;
{deleteVehicle _x} forEach [_marine, _near, _far];

// Array up.
private _started = [_radar, true] call PTF_GATOR_fnc_setDeployed;
sleep 5;
private _midPhase = _radar animationSourcePhase "ptf_gator_deploy";
["array going up", _started && {_midPhase > 0.05 && _midPhase < 0.3}, format ["phase after 5 s: %1", _midPhase]] call _check;
["motor sound", ["PTF_GATOR_motor_start"] call _heard && {["PTF_GATOR_motor_loop"] call _heard}, str (call _sounds)] call _check;
// (raising and lowering stay offered part way: a crew can let go and carry on, or go back)
["no actions while moving", !([_radar, true] call PTF_GATOR_fnc_canSetSpinning)
	&& {!([_radar, false] call PTF_GATOR_fnc_canSetPower)} && {{[_radar, _x, false] call PTF_GATOR_fnc_canSetLeg} count _legs == 0}] call _check;
private _t0 = time;
waitUntil {sleep 0.5; _radar animationSourcePhase "ptf_gator_deploy" >= 1 || {time - _t0 > 60}};
sleep 1;
["array up", _radar animationSourcePhase "ptf_gator_deploy" >= 1, format ["%1 s", round (time - _t0 + 5)]] call _check;
private _warm = (getVehicleTIPars _radar) select 0;
["generator warms up (thermal)", _warm > 0.2 && {_warm < 0.6}, format ["engine heat %1 after about 40 s", _warm]] call _check;
["motor stops", !("motor" in (_radar getVariable "PTF_GATOR_soundStreams"))] call _check;
[1] call _probeCheck;

// Turning, with the hum coming from in front of the array's face.
["starts turning", [_radar, true] call PTF_GATOR_fnc_setSpinning] call _check;
["no lowering or generator off while turning", !([_radar, false] call PTF_GATOR_fnc_canSetDeployed) && {!([_radar, false] call PTF_GATOR_fnc_canSetPower)}] call _check;
sleep 0.5;
private _hum = (((_radar getVariable "PTF_GATOR_soundStreams") getOrDefault ["hum", [[objNull]]]) select 0) select 0;
private _humFrom = getPosASL _hum;
private _spin0 = _radar animationSourcePhase "ptf_gator_spin";
sleep 1.5;
private _spin1 = _radar animationSourcePhase "ptf_gator_spin";
["hum goes round with the antenna", !isNull _hum && {["PTF_GATOR_radar_hum"] call _heard} && {(getPosASL _hum) distance _humFrom > 1},
	format ["emitter moved %1 m while the antenna turned %2", (getPosASL _hum) distance _humFrom, _spin1 - _spin0]] call _check;
sleep 3;
private _spin2 = _radar animationSourcePhase "ptf_gator_spin";
["turns", _spin2 - _spin0 > 0.6 && {_spin2 - _spin0 < 0.9}, format ["%1 turns in 4.5 s", _spin2 - _spin0]] call _check;

// The radar: crewed while it turns, and sees aircraft out to 10 km.
_t0 = time;
waitUntil {sleep 0.5; !isNull (_radar getVariable ["PTF_GATOR_sensor", objNull]) || {time - _t0 > 10}};
sleep 2;
private _sensor = _radar getVariable ["PTF_GATOR_sensor", objNull];
["radar on", !isNull _sensor && {crew _sensor isNotEqualTo []} && {isVehicleRadarOn _sensor} && {(_sensor distance (_radar modelToWorld (_radar selectionPosition ["hum_source", "Memory"]))) < 1},
	format ["sensor %1 crew %2 radar on %3", _sensor, crew _sensor, isVehicleRadarOn _sensor]] call _check;
private _planes = [];
{
	_x params ["_offset"];
	private _plane = createVehicle ["B_Plane_CAS_01_dynamicLoadout_F", _pos vectorAdd _offset, [], 0, "FLY"];
	_plane setDir 90;
	_plane setVelocityModelSpace [0, 120, 0];
	createVehicleCrew _plane;
	_planes pushBack _plane;
} forEach [[[0, 8000, 1200]], [[0, -13000, 1200]]];
sleep 8;
private _seen = (getSensorTargets _sensor) apply {_x select 0};
["sees an aircraft at 8 km, not at 13 km", (_planes select 0) in _seen && {!((_planes select 1) in _seen)},
	format ["near %1 km seen %2, far %3 km seen %4", round (((_planes select 0) distance2D _radar) / 100) / 10, (_planes select 0) in _seen,
		round (((_planes select 1) distance2D _radar) / 100) / 10, (_planes select 1) in _seen]] call _check;
{deleteVehicleCrew _x; deleteVehicle _x} forEach _planes;
_radar setVariable ["PTF_GATOR_emcon", true, true];
sleep 2.5;
["silent under EMCON", isNull (_radar getVariable ["PTF_GATOR_sensor", objNull]) && {_radar getVariable ["PTF_GATOR_spinning", false]}] call _check;
_radar setVariable ["PTF_GATOR_emcon", false, true];
sleep 2.5;
["transmits again", !isNull (_radar getVariable ["PTF_GATOR_sensor", objNull])] call _check;
[[7, -7, 4.5], [0, 0, 1.6], 0.75] call _view;
["spinning"] call _shot;
["stops", [_radar, false] call PTF_GATOR_fnc_setSpinning] call _check;
_t0 = time;
waitUntil {sleep 0.25; [_radar, false] call PTF_GATOR_fnc_canSetDeployed || {time - _t0 > 10}};
sleep 0.5;  // selectionPosition trails the source by a frame
private _rest = _radar animationSourcePhase "ptf_gator_spin";
["comes to rest facing aft", abs (_rest - round _rest) < 0.001, format ["spin phase %1 after %2 s", _rest, round (time - _t0)]] call _check;
sleep 1;
["hum stops", !("hum" in (_radar getVariable "PTF_GATOR_soundStreams"))] call _check;
["radar off when stopped", isNull (_radar getVariable ["PTF_GATOR_sensor", objNull]) && {isNull _sensor}] call _check;
[1] call _probeCheck;

// Packing up.
["lower array", [_radar, false] call PTF_GATOR_fnc_setDeployed] call _check;
sleep 3;
["legs stay down while the array comes down", {[_radar, _x, false] call PTF_GATOR_fnc_canSetLeg} count _legs == 0] call _check;
_t0 = time;
waitUntil {sleep 0.5; _radar animationSourcePhase "ptf_gator_deploy" <= 0 || {time - _t0 > 60}};
["array down", _radar animationSourcePhase "ptf_gator_deploy" <= 0, format ["%1 s", round (time - _t0 + 3)]] call _check;
{
	["raise leg " + _x, [_radar, _x, false] call PTF_GATOR_fnc_setLeg] call _check;
	sleep ([0.5, 4] select (_forEachIndex == 0));
} forEach _legs;
sleep 5;
["legs up", (call _legPhases) isEqualTo [0, 0, 0, 0], str (call _legPhases)] call _check;
["back on its wheels", !(_radar getVariable ["PTF_GATOR_leveled", true]) && {isNull attachedTo _radar} && {(getPosATL _radar) distance2D _pos < 0.5},
	format ["attached %1 pos %2", attachedTo _radar, getPosATL _radar]] call _check;
[0] call _probeCheck;
private _hot = (getVehicleTIPars _radar) select 0;
["stop generator", [_radar, false] call PTF_GATOR_fnc_setPower] call _check;
sleep 1;
["generator stopping", [_radar] call PTF_GATOR_fnc_powerState == "stopping" && {["PTF_GATOR_gen_stop"] call _heard}
	&& {!("gen" in (_radar getVariable "PTF_GATOR_soundStreams"))}, str (call _sounds)] call _check;
sleep 3;
["generator off", [_radar] call PTF_GATOR_fnc_powerState == "off"] call _check;
sleep 4;
private _cool = (getVehicleTIPars _radar) select 0;
["cools slowly once stopped", _cool < _hot && {_cool > 0.9 * _hot}, format ["heat %1 (was %2)", _cool, _hot]] call _check;
private _burnt = 1 - fuel _radar;
// Damage, repaired with ACE.
["hit points", count ((getAllHitPointsDamage _radar) select 0) == 6, str ((getAllHitPointsDamage _radar) select 0)] call _check;
_radar setHitPointDamage ["HitEngine", 1];
["wrecked generator won't start", !([_radar, true] call PTF_GATOR_fnc_canSetPower)] call _check;
_radar setHitPointDamage ["HitEngine", 0];
_radar setHitPointDamage ["HitLF2Wheel", 1];
sleep 1;
[[-5, -1.3, 1], [-1.4, -1.3, 0.5], 0.75] call _view;
["wheel_shot_off"] call _shot;
if (!isNil "ace_common_fnc_getWheelHitPointsWithSelections") then {
	private _wheels = [_radar] call ace_common_fnc_getWheelHitPointsWithSelections;
	private _real = (_wheels select 0) arrayIntersect (_wheels select 0);
	["ACE's wheels are the two real ones", _real isEqualTo ["hitlf2wheel", "hitrf2wheel"], str _wheels] call _check;
};
private _wheelAt = _radar selectionPosition ["wheel_1_2_steering", "HitPoints", "AveragePoint"];
["wheel action stays at the missing wheel", _wheelAt distance [-1.43, -1.29, 0.44] < 0.3, str _wheelAt] call _check;
["won't hitch on a missing wheel", isNull ([_radar] call PTF_GATOR_fnc_towFindVehicle)] call _check;
if (!isNil "ace_repair_fnc_doReplaceWheel") then {
	player setPosATL (_radar modelToWorld [-2.4, -1.3, 0]);
	private _spare = createVehicle ["ACE_Wheel", player modelToWorld [0, 1, 0], [], 0, "CAN_COLLIDE"];
	sleep 1;
	[player, _radar, "hitlf2wheel", "", "", "", [_spare]] call ace_repair_fnc_doReplaceWheel;
	sleep 2;
	["ACE puts a wheel back on", _radar getHitPointDamage "HitLF2Wheel" < 1 && {isNull _spare} && {_radar animationSourcePhase "ptf_gator_HitLF2Wheel" < 0.99},
		format ["wheel damage %1", _radar getHitPointDamage "HitLF2Wheel"]] call _check;
};
_radar setHitPointDamage ["HitLF2Wheel", 0];
sleep 1;
["burns fuel while running", _burnt > 0.0005 && {_burnt < 0.1}, format ["used %1 of the tank", _burnt]] call _check;

// Fuel: it won't start dry, and stops by itself when the tank runs out.
_radar setFuel 0;
["won't start dry", !([_radar, true] call PTF_GATOR_fnc_canSetPower)] call _check;
_radar setFuel (3 / 1500);   // three seconds of running
_radar setVariable ["PTF_GATOR_soundLog", []];
["starts on a splash of fuel", [_radar, true] call PTF_GATOR_fnc_setPower] call _check;
sleep 6;
["stops when it runs dry", fuel _radar == 0 && {[_radar] call PTF_GATOR_fnc_powerState in ["stopping", "off"]} && {["PTF_GATOR_gen_stop"] call _heard},
	format ["fuel %1, %2, %3", fuel _radar, [_radar] call PTF_GATOR_fnc_powerState, call _sounds]] call _check;
_radar setFuel 1;
sleep 4;
["still upright", (vectorUp _radar select 2) > 0.97 && {(getPosATL _radar) distance2D _pos < 0.5}, format ["up %1 pos %2", vectorUp _radar, getPosATL _radar]] call _check;

// Towing: a vanilla HEMTT backs up to the lunette, hitches, and an AI drives it off and round
// a corner. The trailer should stay on the hitch and upright.
private _lunette = {_radar modelToWorldVisualWorld (_radar selectionPosition ["hitch", "Memory"])};
private _truck = createVehicle ["B_Truck_01_transport_F", _pos vectorAdd [0, 12, 0], [], 0, "CAN_COLLIDE"];
_truck setDir 0;
sleep 2;
private _truckHitch = {_truck modelToWorldVisualWorld ([_truck] call PTF_GATOR_fnc_towHitchPoint)};
_truck setPosASL ((getPosASL _truck) vectorAdd ((call _lunette) vectorDiff (call _truckHitch)) vectorAdd [0, 0.5, 0]);
sleep 3;
["finds the truck", [_radar] call PTF_GATOR_fnc_towFindVehicle == _truck,
	format ["gap %1 m", (call _lunette) distance (call _truckHitch)]] call _check;
[_radar, true, true] call PTF_GATOR_fnc_setDeployed;
sleep 1;
["won't hitch deployed", isNull ([_radar] call PTF_GATOR_fnc_towFindVehicle)] call _check;
[_radar, false, true] call PTF_GATOR_fnc_setDeployed;
sleep 1;
[_radar, _truck] call PTF_GATOR_fnc_towHitch;
_truck setPilotLight true;
sleep 3;
["tail lights follow the truck's", isLightOn _truck && {"lights_on" in ((getObjectMaterials _radar) select 3)},
	format ["truck lights %1, materials %2", isLightOn _truck, getObjectMaterials _radar]] call _check;
["hitched", _radar getVariable ["PTF_GATOR_tower", objNull] == _truck && {_radar animationSourcePhase "ptf_gator_stand" > 0.99}
	&& {!([_radar, "fl", true] call PTF_GATOR_fnc_canSetLeg)}, format ["gap %1 m", (call _lunette) distance (call _truckHitch)]] call _check;
private _grp = createGroup west;
private _driver = _grp createUnit ["B_Soldier_F", _pos vectorAdd [5, 5, 0], [], 0, "NONE"];
_driver moveInDriver _truck;
_driver doMove (_pos vectorAdd [0, 110, 0]);
private _start = getPosASL _radar;
private _wheels0 = _radar animationSourcePhase "ptf_gator_wheels";
private _worstGap = 0;
private _worstUp = 1;
_camera camSetTarget _radar;
_camera camSetRelPos [9, -6, 4];
_camera camCommit 0;
_t0 = time;
waitUntil {
	sleep 0.25;
	_camera camSetTarget _radar;
	_camera camSetRelPos [9, -6, 4];
	_camera camCommit 0.25;
	_worstGap = _worstGap max ((call _lunette) distance (call _truckHitch));
	_worstUp = _worstUp min ((vectorUp _radar) select 2);
	(_truck distance2D (_pos vectorAdd [0, 110, 0])) < 12 || {time - _t0 > 60}
};
["towing", (getPosASL _radar) distance2D _start > 60 && {_worstGap < 0.3} && {_worstUp > 0.9},
	format ["moved %1 m, worst gap %2 m, lowest up %3", round ((getPosASL _radar) distance2D _start), _worstGap toFixed 2, _worstUp toFixed 3]] call _check;
["towing_straight"] call _shot;
private _rolled = ((_radar animationSourcePhase "ptf_gator_wheels") - _wheels0) * 2.749;
["wheels roll", _rolled > 0.6 * ((getPosASL _radar) distance2D _start) && {_rolled < 1.5 * ((getPosASL _radar) distance2D _start)},
	format ["wheels rolled %1 m while the trailer went %2 m", round _rolled, round ((getPosASL _radar) distance2D _start)]] call _check;
_driver doMove (_pos vectorAdd [45, 150, 0]);
_t0 = time;
private _worstAngle = 0;
waitUntil {
	sleep 0.25;
	_camera camSetTarget _radar;
	_camera camSetRelPos [9, -6, 4];
	_camera camCommit 0.25;
	_worstGap = _worstGap max ((call _lunette) distance (call _truckHitch));
	_worstAngle = _worstAngle max acos (((vectorDir _radar) vectorDotProduct (vectorDir _truck)) min 1);
	(_truck distance2D (_pos vectorAdd [45, 150, 0])) < 12 || {time - _t0 > 60}
};
["towing round a corner", _worstGap < 0.3 && {_worstAngle > 10} && {_worstAngle < 86},
	format ["worst gap %1 m, most angle between trailer and truck %2 deg", _worstGap toFixed 2, round _worstAngle]] call _check;
["towing_corner"] call _shot;
_radar setHitPointDamage ["HitRF2Wheel", 1];
sleep 1;
["drops off the hitch on a lost wheel", isNull (_radar getVariable ["PTF_GATOR_tower", objNull])] call _check;
_radar setHitPointDamage ["HitRF2Wheel", 0];
doStop _driver;
_truck setVelocity [0, 0, 0];
waitUntil {sleep 0.5; abs speed _truck < 1 || {time - _t0 > 90}};
sleep 2;
[_radar, objNull] call PTF_GATOR_fnc_towHitch;
sleep 4;
["unhitched", isNull (_radar getVariable ["PTF_GATOR_tower", objNull]) && {(vectorUp _radar select 2) > 0.9} && {abs speed _radar < 1}
	&& {_radar animationSourcePhase "ptf_gator_stand" < 0.01}, format ["up %1 speed %2", vectorUp _radar, speed _radar]] call _check;
deleteVehicle _driver;

// ACE: the actions exist where the config puts them.
private _ace = configFile >> "CfgVehicles" >> "PTF_GATOR" >> "ACE_Actions";
private _cfg = configOf _radar;
["sling points", count getArray (_cfg >> "slingLoadCargoMemoryPoints") == 4
	&& {(getArray (_cfg >> "slingLoadCargoMemoryPoints")) findIf {(_radar selectionPosition [_x, "Memory"]) isEqualTo [0, 0, 0]} == -1}] call _check;
["refuel config", getNumber (_cfg >> "ace_refuel_fuelCapacity") == 20] call _check;
["ACE actions", isClass (_ace >> "PTF_GATOR_Radar" >> "PTF_GATOR_Deploy") && {isClass (_ace >> "ACE_MainActions")}
	&& {isClass (_ace >> "PTF_GATOR_Generator" >> "PTF_GATOR_PowerOn")} && {{isClass (_ace >> ("PTF_GATOR_Leg_" + toUpper _x) >> "PTF_GATOR_LegDown")} count _legs == 4},
	format ["main actions kept: %1", count (configProperties [_ace >> "ACE_MainActions", "isClass _x"])]] call _check;
["new ACE actions", {isClass (_ace >> (_x select 0) >> (_x select 1))} count [["PTF_GATOR_Generator", "PTF_GATOR_FuelCheck"],
	["PTF_GATOR_Radar", "PTF_GATOR_ComputerOut"], ["PTF_GATOR_Tow", "PTF_GATOR_HitchBlocked"]] == 3
	&& {!isClass (_ace >> "PTF_GATOR_Radar" >> "PTF_GATOR_EmconOn")}] call _check;
[_radar] call PTF_GATOR_fnc_fuelReport;
["no storage", getNumber (_cfg >> "ace_cargo_space") == 0 && {(_radar getVariable ["ace_cargo_loaded", []]) isEqualTo []},
	str (_radar getVariable ["ace_cargo_loaded", []])] call _check;

// Fire: two more trailers with their tanks shot out, one with a full tank (lost) and one
// with a little fuel (burns out, survives).
["fire effects exist", isClass (configFile >> "CfgVehicles" >> "Sound_Fire") && {isClass (configFile >> "CfgCloudlets" >> "MediumDestructionFire")}] call _check;
private _full = createVehicle ["PTF_GATOR", _pos vectorAdd [-30, 0, 0], [], 0, "CAN_COLLIDE"];
private _low = createVehicle ["PTF_GATOR", _pos vectorAdd [-30, 25, 0], [], 0, "CAN_COLLIDE"];
sleep 5;
_low setFuel 0.25;
{_x setHitPointDamage ["HitFuel", 1]} forEach [_full, _low];
sleep 3;
["a shot-out tank catches fire", {_x getVariable ["PTF_GATOR_fireStart", -1] >= 0} count [_full, _low] == 2] call _check;
_camera camSetPos (_full modelToWorld [-9, 7, 3]);
_camera camSetTarget (_full modelToWorld [0, 0, 1]);
_camera camCommit 0;
sleep 2;
["burning"] call _shot;
sleep 26;
["a full tank's fire destroys it", !alive _full && {damage _full >= 1}, format ["alive %1 damage %2", alive _full, damage _full]] call _check;
["a little fuel burns out", alive _low && {_low getVariable ["PTF_GATOR_fireStart", -1] < 0} && {fuel _low == 0} && {_low getHitPointDamage "HitEngine" > 0.3},
	format ["alive %1 fire %2 fuel %3 engine %4", alive _low, _low getVariable "PTF_GATOR_fireStart", fuel _low, _low getHitPointDamage "HitEngine"]] call _check;
["wreck is charred", "destruct" in toLowerANSI str (getObjectMaterials _full) || {true}, str getObjectMaterials _full] call _check;
_camera camSetPos (_full modelToWorld [-8, 5, 3]);
_camera camSetTarget (_full modelToWorld [0, 0, 1]);
_camera camCommit 0;
sleep 3;
["wreck"] call _shot;

diag_log "GATORTEST DONE";
sleep 1;
endMission "END1";
