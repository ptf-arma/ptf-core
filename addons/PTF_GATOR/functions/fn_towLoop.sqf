/*
 * Author: Paramarine Task Force
 * Moves a hitched G/ATOR behind its towing vehicle, every frame, on the machine that owns the
 * trailer (the server hands it to whoever owns the vehicle, so the two never lag each other).
 * Started on every machine by the PTF_GATOR XEH init.
 *
 * It is a kinematic trailer, not a roped one: the axle trails the hitch at the tongue's length
 * (each frame the axle moves straight toward where the hitch now is), the body pitches up to
 * the hitch and rolls with the ground under the axle, and it can't jackknife past 85 degrees.
 *
 * Every other player sees a copy. The real trailer reaches their machines only at network
 * rate, as a run of jumps (placed each frame, not driven), so it stuttered behind the vehicle
 * the whole way. On each of their machines the real trailer is hidden while it's towed, and a
 * local copy of it (a simple object of the same class, no physics) is placed every frame by the
 * same reckoning from the towing vehicle as that machine sees it: on the hitch, smooth, its
 * wheels rolling and its tail lights lit with the vehicle's. The real one still carries the
 * physics, the ACE actions and the state.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar] call PTF_GATOR_fnc_towLoop
 */
params [["_radar", objNull, [objNull]]];

if (isNull _radar) exitWith {};

// From the model: the axle's middle and the lunette, in model space (x right, y forward, z up).
#define AXLE [0, -1.285, 0.4375]
#define LUNETTE [0, 3.10, 0.868]
#define TONGUE 4.385
#define MAX_ANGLE 85
// metres a wheel turn
#define WHEEL_ROLL 2.749

// Where the trailer goes behind the vehicle this frame: its axle (kept in <axle var>, this
// machine's own reckoning) follows the hitch. Returns [model origin (world ASL), dir, up].
// <copy>: the local copy being placed, which the ground probe must not find under itself.
private _pose = {
	params ["_radar", "_tower", "_axleVar", ["_copy", objNull]];
	private _hitch = _tower modelToWorldVisualWorld (_radar getVariable ["PTF_GATOR_towHitch", [0, 0, 0]]);
	private _axle = _radar getVariable [_axleVar, _radar modelToWorldVisualWorld AXLE];

	// The axle follows the hitch.
	private _heading = [(_hitch select 0) - (_axle select 0), (_hitch select 1) - (_axle select 1), 0];
	if (vectorMagnitude _heading < 0.01) then {_heading = vectorDir _radar};
	_heading = vectorNormalized [_heading select 0, _heading select 1, 0];
	// No jackknifing: keep within MAX_ANGLE of the towing vehicle's heading.
	private _towDir = vectorNormalized [(vectorDir _tower) select 0, (vectorDir _tower) select 1, 0];
	private _angle = acos ((_heading vectorDotProduct _towDir) max -1 min 1);
	if (_angle > MAX_ANGLE) then {
		private _side = [-1, 1] select (((_towDir select 0) * (_heading select 1) - (_towDir select 1) * (_heading select 0)) > 0);
		private _a = (_towDir select 0) atan2 (_towDir select 1);
		_a = _a - _side * MAX_ANGLE;
		_heading = [sin _a, cos _a, 0];
	};
	private _ax = (_hitch select 0) - (_heading select 0) * TONGUE;
	private _ay = (_hitch select 1) - (_heading select 1) * TONGUE;
	// The ground under the axle: terrain, or a bridge or road object under it.
	private _ground = getTerrainHeightASL [_ax, _ay];
	// (not the trailer itself, nor its copy: the copy found its own roof and rode up and down on it)
	private _hits = (lineIntersectsSurfaces [[_ax, _ay, (_hitch select 2) + 3], [_ax, _ay, _ground - 0.5], _radar, _tower, true, 3, "ROADWAY", "GEOM"])
		select {(_x select 2) isNotEqualTo _copy && {(_x select 3) isNotEqualTo _copy}};
	if (_hits isNotEqualTo []) then {_ground = ((_hits select 0) select 0) select 2};
	_axle = [_ax, _ay, _ground + (AXLE select 2)];
	_radar setVariable [_axleVar, _axle];

	// Orientation: forward along axle-to-hitch less the tongue's own rise, up from the ground.
	private _forward = vectorNormalized (_hitch vectorDiff _axle);
	private _normal = surfaceNormal [_ax, _ay];
	private _right = vectorNormalized (_forward vectorCrossProduct _normal);
	private _upF = _right vectorCrossProduct _forward;
	private _rise = (LUNETTE select 2) - (AXLE select 2);
	private _tilt = _rise atan2 TONGUE;
	private _dir = (_forward vectorMultiply cos _tilt) vectorDiff (_upF vectorMultiply sin _tilt);
	private _up = (_upF vectorMultiply cos _tilt) vectorAdd (_forward vectorMultiply sin _tilt);
	[_axle vectorDiff ((_dir vectorMultiply (AXLE select 1)) vectorAdd (_up vectorMultiply (AXLE select 2))), _dir, _up]
};

[{
	params ["_args", "_handle"];
	_args params ["_radar", "_pose", "_copyHolder"];
	private _copy = _copyHolder select 0;
	// The copy goes with the tow, the trailer, or this machine taking over the driving.
	private _dropCopy = {
		if (!isNull _copy) then {
			{deleteVehicle _x} forEach ([_copy] + (_copyHolder select 1));
			_copyHolder set [0, objNull];
			_copyHolder set [1, []];
			if (!isNull _radar) then {
				_radar hideObject false;
				_radar setVariable ["PTF_GATOR_towCopy", nil];
				_radar setVariable ["PTF_GATOR_copyAxle", nil];
			};
		};
	};
	if (isNull _radar) exitWith {
		call _dropCopy;
		[_handle] call CBA_fnc_removePerFrameHandler;
	};

	private _tower = _radar getVariable ["PTF_GATOR_tower", objNull];
	if (isNull _tower) exitWith {
		call _dropCopy;
		if (!isNil {_radar getVariable "PTF_GATOR_towAxle"}) then {
			_radar setVariable ["PTF_GATOR_towAxle", nil];
			if (local _radar) then {
				_radar setVelocity [0, 0, 0];
				_radar animateSource ["ptf_gator_wheels", _radar animationSourcePhase "ptf_gator_wheels"];
				_radar setVariable ["PTF_GATOR_wheelRate", 0];
			};
		};
	};
	if (!alive _tower || {!alive _radar}) exitWith {
		call _dropCopy;
		if (isServer) then {[_radar, objNull] call PTF_GATOR_fnc_towHitch};
	};
	// A wheel shot off or taken off: it drops off the hitch onto its axle.
	if (selectMax (["HitLF2Wheel", "HitRF2Wheel"] apply {_radar getHitPointDamage _x}) >= 1) exitWith {
		call _dropCopy;
		if (isServer) then {
			[_radar, objNull] call PTF_GATOR_fnc_towHitch;
			if (!isNull driver _tower && {isPlayer driver _tower}) then {
				["The G/ATOR lost a wheel and came off the hitch.", 1.5] remoteExecCall ["ace_common_fnc_displayTextStructured", driver _tower];
			};
		};
	};
	// The server keeps the trailer with whoever drives the vehicle.
	if (isServer && {isMultiplayer} && {owner _radar != owner _tower}) then {_radar setOwner owner _tower};

	// Another player's machine: show the copy, placed from the vehicle as this machine sees it.
	if (!local _radar) exitWith {
		if (!hasInterface && {!(missionNamespace getVariable ["PTF_GATOR_towCopyTest", false])}) exitWith {};
		if (isNull _copy) then {
			_copy = createSimpleObject [typeOf _radar, getPosWorldVisual _radar, true];
			_copy animate ["stand", 1, true];
			_copyHolder set [0, _copy];
			_radar setVariable ["PTF_GATOR_towCopy", _copy];
			_radar setVariable ["PTF_GATOR_copyAxle", _radar modelToWorldVisualWorld AXLE];
			_radar setVariable ["PTF_GATOR_copyRoll", 0];
			_radar setVariable ["PTF_GATOR_copyLit", false];
			_radar hideObject true;
		};
		([_radar, _tower, "PTF_GATOR_copyAxle", _copy] call _pose) params ["_origin", "_dir", "_up"];
		_copy setPosWorld _origin;
		_copy setVectorDirAndUp [_dir, _up];
		// its wheels roll at the vehicle's ground speed
		private _roll = (_radar getVariable ["PTF_GATOR_copyRoll", 0]) + ((velocity _tower) vectorDotProduct _dir) * diag_deltaTime / WHEEL_ROLL;
		_roll = _roll - floor _roll;
		_radar setVariable ["PTF_GATOR_copyRoll", _roll];
		{_copy animate [_x, _roll, true]} forEach ["wheel_1_2_towed", "wheel_2_2_towed"];
		// its tail lights with the vehicle's
		private _lit = isLightOn _tower;
		if (_lit isNotEqualTo (_radar getVariable ["PTF_GATOR_copyLit", false])) then {
			_radar setVariable ["PTF_GATOR_copyLit", _lit];
			_copy setObjectMaterial [3, ["\z\ptf_gator\addons\data\data\lights.rvmat", "\z\ptf_gator\addons\data\data\lights_on.rvmat"] select _lit];
			{deleteVehicle _x} forEach (_copyHolder select 1);
			_copyHolder set [1, []];
			if (_lit) then {
				private _light = "#lightpoint" createVehicleLocal [0, 0, 0];
				_light setLightColor [1, 0.08, 0.03];
				_light setLightAmbient [0.25, 0.02, 0.01];
				_light setLightBrightness 0.2;
				_light lightAttachObject [_copy, _copy selectionPosition ["taillight", "Memory"]];
				_copyHolder set [1, [_light]];
			};
		};
	};
	// This machine drives it: the real trailer, no copy.
	call _dropCopy;

	if (isNil {_radar getVariable "PTF_GATOR_towAxle"}) then {_radar disableCollisionWith _tower};
	([_radar, _tower, "PTF_GATOR_towAxle"] call _pose) params ["_origin", "_dir", "_up"];
	_radar setVectorDirAndUp [_dir, _up];
	// Place it so the model's axle point lands on the axle.
	private _offset = (getPosASL _radar) vectorDiff (_radar modelToWorldWorld [0, 0, 0]);
	_radar setPosASL (_origin vectorAdd _offset);
	_radar setVelocity velocity _tower;

	// Roll the wheels at the ground speed, set twice a second. Placing the trailer each frame
	// means PhysX never turns them itself.
	private _now = diag_tickTime;
	if (_now > (_radar getVariable ["PTF_GATOR_wheelsAt", 0])) then {
		_radar setVariable ["PTF_GATOR_wheelsAt", _now + 0.5];
		private _rate = ((velocity _tower) vectorDotProduct _dir) / WHEEL_ROLL;
		private _last = _radar getVariable ["PTF_GATOR_wheelRate", 0];
		if (abs (_rate - _last) > 0.05 + 0.1 * abs _last) then {
			_radar setVariable ["PTF_GATOR_wheelRate", _rate];
			private _phase = _radar animationSourcePhase "ptf_gator_wheels";
			if (abs _rate < 0.05) then {
				_radar animateSource ["ptf_gator_wheels", _phase];
			} else {
				_radar animateSource ["ptf_gator_wheels", _phase + ([-100000, 100000] select (_rate > 0)), abs _rate];
			};
		};
	};
}, 0, [_radar, _pose, [objNull, []]]] call CBA_fnc_addPerFrameHandler;
