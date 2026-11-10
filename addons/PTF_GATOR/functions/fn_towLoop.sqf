/*
 * Author: Paramarine Task Force
 * Moves a hitched G/ATOR behind its towing vehicle, every frame, on the machine that owns the
 * trailer (the server hands it to whoever owns the vehicle, so the two never lag each other).
 * Started on every machine by the PTF_GATOR XEH init.
 *
 * It is a kinematic trailer, not a roped one: the axle trails the hitch at the tongue's length
 * (each frame the axle moves straight toward where the hitch now is), the body pitches up to
 * the hitch and rolls with the ground under the axle, and it can't jackknife past 85 degrees.
 * It moves through the trailer's own PhysX simulation, so other machines see it the way they
 * see any vehicle.
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

[{
	params ["_radar", "_handle"];
	if (isNull _radar) exitWith {[_handle] call CBA_fnc_removePerFrameHandler};

	private _tower = _radar getVariable ["PTF_GATOR_tower", objNull];
	if (isNull _tower) exitWith {
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
		if (isServer) then {[_radar, objNull] call PTF_GATOR_fnc_towHitch};
	};
	// A wheel shot off or taken off: it drops off the hitch onto its axle.
	if (selectMax (["HitLF2Wheel", "HitRF2Wheel"] apply {_radar getHitPointDamage _x}) >= 1) exitWith {
		if (isServer) then {
			[_radar, objNull] call PTF_GATOR_fnc_towHitch;
			if (!isNull driver _tower && {isPlayer driver _tower}) then {
				["The G/ATOR lost a wheel and came off the hitch.", 1.5] remoteExecCall ["ace_common_fnc_displayTextStructured", driver _tower];
			};
		};
	};
	// The server keeps the trailer with whoever drives the vehicle.
	if (isServer && {isMultiplayer} && {owner _radar != owner _tower}) then {_radar setOwner owner _tower};
	if (!local _radar) exitWith {};

	private _hitch = _tower modelToWorldVisualWorld (_radar getVariable ["PTF_GATOR_towHitch", [0, 0, 0]]);
	private _axle = _radar getVariable "PTF_GATOR_towAxle";
	if (isNil "_axle") then {
		_radar disableCollisionWith _tower;
		_axle = _radar modelToWorldVisualWorld AXLE;
	};

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
	private _hits = lineIntersectsSurfaces [[_ax, _ay, (_hitch select 2) + 3], [_ax, _ay, _ground - 0.5], _radar, _tower, true, 1, "ROADWAY", "GEOM"];
	if (_hits isNotEqualTo []) then {_ground = ((_hits select 0) select 0) select 2};
	_axle = [_ax, _ay, _ground + (AXLE select 2)];
	_radar setVariable ["PTF_GATOR_towAxle", _axle];

	// Orientation: forward along axle-to-hitch less the tongue's own rise, up from the ground.
	private _forward = vectorNormalized (_hitch vectorDiff _axle);
	private _normal = surfaceNormal [_ax, _ay];
	private _right = vectorNormalized (_forward vectorCrossProduct _normal);
	private _upF = _right vectorCrossProduct _forward;
	private _rise = (LUNETTE select 2) - (AXLE select 2);
	private _tilt = _rise atan2 TONGUE;
	private _dir = (_forward vectorMultiply cos _tilt) vectorDiff (_upF vectorMultiply sin _tilt);
	private _up = (_upF vectorMultiply cos _tilt) vectorAdd (_forward vectorMultiply sin _tilt);
	_radar setVectorDirAndUp [_dir, _up];

	// Place it so the model's axle point lands on the axle.
	private _origin = _axle vectorDiff ((_dir vectorMultiply (AXLE select 1)) vectorAdd (_up vectorMultiply (AXLE select 2)));
	private _offset = (getPosASL _radar) vectorDiff (_radar modelToWorldWorld [0, 0, 0]);
	_radar setPosASL (_origin vectorAdd _offset);
	_radar setVelocity velocity _tower;

	// Roll the wheels at the ground speed (2.749 m a turn), set twice a second. Placing the
	// trailer each frame means PhysX never turns them itself.
	private _now = diag_tickTime;
	if (_now > (_radar getVariable ["PTF_GATOR_wheelsAt", 0])) then {
		_radar setVariable ["PTF_GATOR_wheelsAt", _now + 0.5];
		private _rate = ((velocity _tower) vectorDotProduct _dir) / 2.749;
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
}, 0, _radar] call CBA_fnc_addPerFrameHandler;
