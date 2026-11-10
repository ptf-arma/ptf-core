/*
 * Author: Paramarine Task Force
 * Plays a G/ATOR's sounds on this machine, every frame, from its synced state, lights its
 * tail lights while it is towed by a vehicle with its lights on, and blows black exhaust from
 * under the generator while it runs (thick as it starts, thin once settled). Sounds: the generator
 * (start, running, stop), the array motor while the array moves, a smaller motor on each leg
 * while it moves and a clunk as it touches down, and the radar hum while it transmits. Started
 * on every client by the PTF_GATOR XEH init (with the incoming alarm while rounds it traced are in
 * the air, PTF_GATOR_alarmUntil), so nothing about sound goes over the network
 * and players joining late hear the right thing (but not starts or clunks from before they
 * arrived).
 *
 * Sounds play with say3D from invisible emitters attached to the radar at memory points;
 * deleting an emitter cuts its sound. A loop has two emitters and starts each repeat
 * OVERLAP seconds before the last one ends, on the other emitter: the clips fade in and out
 * over that time (tools/gator/import_sounds.py), so the repeats crossfade and a frame of
 * timing error can't be heard. The hum's emitters sit in front of the array's face and ride
 * the turntable, so the hum goes round with the antenna.
 *
 * For the in-game test, the radar's local variable PTF_GATOR_soundLog lists every sound
 * started here, and PTF_GATOR_soundStreams holds the running loops.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar] spawn PTF_GATOR_fnc_soundLoop
 */
#include "..\script_gator.hpp"
params [["_radar", objNull, [objNull]]];

if (!hasInterface || {isNull _radar}) exitWith {};

// From tools/gator/import_sounds.py: each loop's repeat period (its length less the overlap)
// and the overlap. The leg motor is the array motor's clip played 1.35 times faster.
#define OVERLAP 0.5
#define GEN_LOOP_PERIOD 13.0
#define HUM_PERIOD 16.7
#define MOTOR_START_HANDOVER 2.3
#define MOTOR_LOOP_PERIOD 7.6
#define LEG_MOTOR_PERIOD (MOTOR_LOOP_PERIOD / 1.35)
// Exhaust: the running strength (0..1, 1 being the start-up smoke), how long after start-up it
// takes to settle there, and where it comes from: the right-hand edge under the generator
// housing, from the "generator" memory point on the housing's left side.
#define EXHAUST_IDLE 0.15
#define EXHAUST_SETTLE 8
#define EXHAUST_OFFSET [2.5, -0.18, -0.45]
// Heat: seconds for the generator to get (most of the way) hot, and to cool again.
// Beyond this (just past the incoming alarm's reach) a player hears none of it.
#define FAR 2100
#define HEAT_RISE 90
#define HEAT_FALL 300

private _legs = ["fl", "fr", "rl", "rr"];
private _state = createHashMapFromArray [
	["powerTime", _radar getVariable ["PTF_GATOR_powerTime", -1e6]],
	["array", _radar animationSourcePhase "ptf_gator_deploy"],
	["arrayMoving", -1],
	["legs", _legs apply {_radar animationSourcePhase ("ptf_gator_leg_" + _x)}],
	["legsMoving", _legs apply {-1}],
	["legsLanding", _legs apply {false}],
	["lit", false],
	["light", objNull],
	["exhaust", objNull],
	["exhaustStrength", -1],
	["heat", -1],
	["heatSet", -1],
	["fire", []]
];
_radar setVariable ["PTF_GATOR_soundStreams", createHashMap];
_radar setVariable ["PTF_GATOR_soundLog", []];

[{
	params ["_args", "_handle"];
	_args params ["_radar", "_state", "_legs"];
	private _streams = _radar getVariable ["PTF_GATOR_soundStreams", createHashMap];

	if (isNull _radar || {!alive _radar}) exitWith {
		{{deleteVehicle _x} forEach (_y select 0)} forEach _streams;
		deleteVehicle (_state get "light");
		deleteVehicle (_state get "exhaust");
		{deleteVehicle _x} forEach (_state get "fire");
		[_handle] call CBA_fnc_removePerFrameHandler;
	};

	private _now = diag_tickTime;
	// Out of earshot (beyond the alarm's reach, from wherever this player's camera is): no
	// sounds or exhaust, and the rest (heat, fire, tail lights, all slow or seen from afar)
	// once a second rather than every frame.
	private _far = (positionCameraToWorld [0, 0, 0]) distance _radar > FAR;
	if (_far && {_now < _state getOrDefault ["farAt", 0]}) exitWith {};
	_state set ["farAt", _now + 1];
	if (_far) then {
		{{deleteVehicle _x} forEach (_y select 0)} forEach _streams;
		_streams = createHashMap;
		_radar setVariable ["PTF_GATOR_soundStreams", _streams];
	};
	private _log = {_radar setVariable ["PTF_GATOR_soundLog", (_radar getVariable ["PTF_GATOR_soundLog", []]) + [_this]]};
	private _emitter = {
		params ["_point", ["_follow", false]];
		private _e = "Land_HelipadEmpty_F" createVehicleLocal [0, 0, 0];
		_e attachTo [_radar, [0, 0, 0], _point, _follow];
		_e
	};
	private _oneShot = {
		params ["_class", "_point", "_range"];
		if (_far) exitWith {};
		private _e = [_point] call _emitter;
		_e say3D [_class, _range];
		[{deleteVehicle _this}, _e, 10] call CBA_fnc_waitAndExecute;
		_class call _log;
	};
	// Keep a loop going: [name, class, period, point, range, follow bone, opening class, opening handover]
	private _loop = {
		params ["_name", "_class", "_period", "_point", "_range", ["_follow", false], ["_opening", ""], ["_handover", 0]];
		if (_far) exitWith {};
		if !(_name in _streams) then {
			private _pair = [[_point, _follow] call _emitter, [_point, _follow] call _emitter];
			if (_opening != "") then {
				(_pair select 1) say3D [_opening, _range];
				_opening call _log;
			};
			_streams set [_name, [_pair, _now + _handover, 0, true]];
		};
		(_streams get _name) params ["_pair", "_next", "_which", "_first"];
		if (_now >= _next) then {
			(_pair select _which) say3D [_class, _range];
			if (_first) then {_class call _log};
			// From the planned time, so frame-length errors don't add up; but don't race to
			// catch up after a long stall.
			_streams set [_name, [_pair, (_next + _period) max (_now + _period - 0.1), 1 - _which, false]];
		};
	};
	// Stop a loop, optionally a little later so whatever takes over can fade in under it.
	private _stop = {
		params ["_name", ["_after", 0]];
		if (_name in _streams) then {
			private _pair = (_streams get _name) select 0;
			_streams deleteAt _name;
			if (_after > 0) then {
				[{{deleteVehicle _x} forEach _this}, _pair, _after] call CBA_fnc_waitAndExecute;
			} else {
				{deleteVehicle _x} forEach _pair;
			};
		};
	};

	// Generator.
	private _power = [_radar] call PTF_GATOR_fnc_powerState;
	private _powerTime = _radar getVariable ["PTF_GATOR_powerTime", -1e6];
	if (_powerTime != _state get "powerTime") then {
		_state set ["powerTime", _powerTime];
		if (_power == "starting") then {["PTF_GATOR_gen_start", "generator", 250] call _oneShot};
		if (_power == "stopping") then {
			// The stop clip opens on the same idle and fades in, so let the loop run under it.
			["PTF_GATOR_gen_stop", "generator", 200] call _oneShot;
			["gen", OVERLAP] call _stop;
		};
	};
	// The running loop takes over as the start clip settles to idle.
	private _startTime = getNumber (configOf _radar >> "ptf_gator_powerStartTime");
	if (_power == "on" || {_power == "starting" && {CBA_missionTime - _powerTime > _startTime - OVERLAP}}) then {
		["gen", "PTF_GATOR_gen_loop", GEN_LOOP_PERIOD, "generator", 200] call _loop;
	} else {
		["gen"] call _stop;
	};

	// Exhaust: thin black smoke from under the generator while it runs, thick as it starts and
	// thinning over the first EXHAUST_SETTLE seconds of running. Re-tuned only when the
	// strength moves on by a step, not every frame.
	private _exhaust = _state get "exhaust";
	private _strength = switch (_power) do {
		case "starting": {1};
		case "on": {EXHAUST_IDLE max (1 - (CBA_missionTime - _powerTime - _startTime) / EXHAUST_SETTLE)};
		case "stopping": {EXHAUST_IDLE};
		default {0};
	};
	if (_strength == 0 || _far) then {
		if (!isNull _exhaust) then {
			deleteVehicle _exhaust;
			_state set ["exhaust", objNull];
		};
	} else {
		if (isNull _exhaust) then {
			_exhaust = "#particlesource" createVehicleLocal (_radar modelToWorld [0, 0, 0]);
			_state set ["exhaust", _exhaust];
			_state set ["exhaustStrength", -1];
		};
		if (abs (_strength - (_state get "exhaustStrength")) >= 0.05 || {_strength == EXHAUST_IDLE && {(_state get "exhaustStrength") != EXHAUST_IDLE}}) then {
			_state set ["exhaustStrength", _strength];
			private _at = (_radar selectionPosition ["generator", "Memory"]) vectorAdd EXHAUST_OFFSET;
			// Blown out sideways, so it shows from under the housing instead of rising
			// unseen through the deck. The trailer can't turn while the generator runs (its legs
			// are down), so the direction worked out here holds.
			private _alpha = 0.26 + 0.18 * _strength;
			private _size = 0.7 + 0.55 * _strength;
			_exhaust setParticleParams [
				["\A3\data_f\ParticleEffects\Universal\Universal", 16, 7, 48, 1], "", "Billboard",
				1, 2.4 + 1.6 * _strength,                   // timer period, life
				_at, _radar vectorModelToWorld [0.5 + 0.5 * _strength, 0, 0.1 + 0.2 * _strength],
				0, 1.24, 1, 0.08,                           // rotation, weight, volume, rubbing
				[_size * 0.5, _size, _size * 1.8],
				[[0.03, 0.03, 0.03, _alpha], [0.07, 0.07, 0.07, _alpha * 0.6], [0.12, 0.12, 0.12, 0]],
				[0.8, 0.3, 0.25], 0.4, 0.15, "", "", _radar
			];
			_exhaust setParticleRandom [0.8, [0.1, 0.35, 0.05], [0.2, 0.2, 0.1], 1, 0.25 * _size, [0.02, 0.02, 0.02, 0.03], 0, 0, 360];
			_exhaust setDropInterval linearConversion [EXHAUST_IDLE, 1, _strength, 0.1, 0.035, true];
		};
	};

	// Array motor: while the array is moving.
	private _array = _radar animationSourcePhase "ptf_gator_deploy";
	if (_array != _state get "array") then {
		_state set ["array", _array];
		_state set ["arrayMoving", _now + 0.3];
	};
	// Moving: between its ends, or changed just now (an instant move to an end).
	if (_array > 0.0005 && {_array < 0.9995} || {_now < _state get "arrayMoving"}) then {
		["motor", "PTF_GATOR_motor_loop", MOTOR_LOOP_PERIOD, "motor_source", 100, true, "PTF_GATOR_motor_start", MOTOR_START_HANDOVER] call _loop;
	} else {
		["motor", OVERLAP] call _stop;
	};

	// Radar hum: while it transmits (its sensor is up; silent, turning or not, it's quiet), from
	// in front of the array's face.
	if (!isNull (_radar getVariable ["PTF_GATOR_sensor", objNull])) then {
		["hum", "PTF_GATOR_radar_hum", HUM_PERIOD, "hum_source", 120, true] call _loop;
	} else {
		["hum", OVERLAP] call _stop;
	};

	// Legs: a motor while each one moves, and a clunk as one that was up meets the ground.
	private _was = _state get "legs";
	private _moving = _state get "legsMoving";
	private _landing = _state get "legsLanding";
	private _phases = _legs apply {_radar animationSourcePhase ("ptf_gator_leg_" + _x)};
	{
		private _leg = _legs select _forEachIndex;
		private _then = _was select _forEachIndex;
		if (_x != _then) then {_moving set [_forEachIndex, _now + 0.15]};
		// A leg leaving the up position is on its way to the ground; it clunks once it rests
		// there. (Leveling moves legs that are already down: no clunk.)
		if (_then < 0.001 && {_x > _then}) then {_landing set [_forEachIndex, true]};
		private _legState = [_radar, _leg] call PTF_GATOR_fnc_legState;
		if (_now < _moving select _forEachIndex || {_legState == "moving"}) then {
			["leg_" + _leg, "PTF_GATOR_leg_motor", LEG_MOTOR_PERIOD, "leg_" + _leg, 50] call _loop;
		} else {
			["leg_" + _leg, 0.3] call _stop;
		};
		if (_landing select _forEachIndex && {_legState != "moving"}) then {
			_landing set [_forEachIndex, false];
			if (_legState == "down") then {["PTF_GATOR_leg_down", "leg_" + _leg, 60] call _oneShot};
		};
	} forEach _phases;
	_state set ["legs", _phases];

	// Heat, for thermal sights: the generator warms over a few minutes of running and cools
	// slowly once stopped. A fire is hot.
	private _dt = _now - (_state getOrDefault ["heatAt", _now]);
	_state set ["heatAt", _now];
	private _heat = _state get "heat";
	private _running = _power in ["starting", "on"];
	if (_heat < 0) then {
		// Joining late: as warm as the generator would be by now.
		_heat = [0, 1 - exp (-(CBA_missionTime - _powerTime) / HEAT_RISE)] select _running;
	};
	_heat = if (_running) then {_heat + (1 - _heat) * (1 - exp (-_dt / HEAT_RISE))} else {_heat * exp (-_dt / HEAT_FALL)};
	_state set ["heat", _heat];
	private _burning = _radar getVariable ["PTF_GATOR_fireStart", -1] >= 0;
	private _shown = [_heat, 1] select _burning;
	if (abs (_shown - (_state get "heatSet")) > 0.01 || {_now > _state getOrDefault ["heatSetAt", 0]}) then {
		_state set ["heatSet", _shown];
		_state set ["heatSetAt", _now + 2];
		(getVehicleTIPars _radar) params ["", ["_wheels", 0], ["_weapon", 0]];
		_radar setVehicleTIPars [_shown, _wheels, _weapon];
	};

	// Fire: a burning fuel tank (PTF_GATOR_fnc_fuelLoop starts it).
	private _fire = _state get "fire";
	if (_burning isNotEqualTo (_fire isNotEqualTo [])) then {
		{deleteVehicle _x} forEach _fire;
		_fire = [];
		if (_burning) then {
			private _at = _radar selectionPosition ["destructionEffect1", "Memory"];
			{
				private _source = "#particlesource" createVehicleLocal (_radar modelToWorld _at);
				_source setParticleClass _x;
				_source attachTo [_radar, _at];
				_fire pushBack _source;
			} forEach ["MediumDestructionFire", "MediumDestructionSmoke"];
			private _light = "#lightpoint" createVehicleLocal (_radar modelToWorld _at);
			_light setLightColor [1, 0.45, 0.15];
			_light setLightAmbient [1, 0.35, 0.1];
			_light setLightBrightness 2;
			_light setLightAttenuation [2, 0, 0, 0.5];
			_light lightAttachObject [_radar, _at vectorAdd [0, 0, 0.6]];
			_fire pushBack _light;
		};
		_state set ["fire", _fire];
	};

	// The incoming alarm, while rounds it traced are in the air (PTF_GATOR_fnc_cbReport): loud,
	// heard faint 2 km off, from the trailer, so its direction carries.
	if (CBA_missionTime < _radar getVariable ["PTF_GATOR_alarmUntil", -1]) then {
		["alarm", "PTF_GATOR_alarm", ALARM_PERIOD, "interact", ALARM_RANGE] call _loop;
	} else {
		["alarm", OVERLAP] call _stop;
	};

	// An anti-radiation missile homing on it (PTF_GATOR_fnc_armReport): the missile warning,
	// heard at the trailer.
	if ((_radar getVariable ["PTF_GATOR_arm", []]) isNotEqualTo []) then {
		["arm", "PTF_GATOR_armAlarm", 1, "interact", 300] call _loop;
	} else {
		["arm"] call _stop;
	};

	// Tail lights: lit while towed by a vehicle with its lights on.
	private _tower = _radar getVariable ["PTF_GATOR_tower", objNull];
	private _lit = !isNull _tower && {isLightOn _tower};
	if (_lit isNotEqualTo (_state get "lit")) then {
		_state set ["lit", _lit];
		_radar setObjectMaterial [3, ["\z\ptf_gator\addons\data\data\lights.rvmat", "\z\ptf_gator\addons\data\data\lights_on.rvmat"] select _lit];
		deleteVehicle (_state get "light");
		if (_lit) then {
			private _light = "#lightpoint" createVehicleLocal [0, 0, 0];
			_light setLightColor [1, 0.08, 0.03];
			_light setLightAmbient [0.25, 0.02, 0.01];
			_light setLightBrightness 0.2;
			_light lightAttachObject [_radar, _radar selectionPosition ["taillight", "Memory"]];
			_state set ["light", _light];
		};
	};
}, 0, [_radar, _state, _legs]] call CBA_fnc_addPerFrameHandler;
