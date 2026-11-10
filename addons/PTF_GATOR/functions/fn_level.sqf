/*
 * Author: Paramarine Task Force
 * Levels a G/ATOR on its four legs, or settles it back onto its wheels. Server only.
 *
 * Leveling: the trailer turns upright (keeping its heading) and rises just clear of its wheels
 * while every leg runs down to the ground under it, over LEVEL_TIME seconds. PhysX would drop a
 * car back onto its wheels, so the trailer hangs from an anchor (attachTo) while it is
 * leveled; attached, it still animates, takes damage and runs its scripts. The anchor is a
 * hidden soda can: an attached object animates only as often as its parent is simulated,
 * which for a static object (a helipad) is a couple of times a second, so the array and
 * legs jerked. A hidden PhysX object is simulated every frame and still stays where put. If the ground
 * is too steep for the legs' reach it stays as it is, each leg down where it met the ground,
 * and players nearby are told.
 *
 * Settling: the reverse, back to where it stood on its wheels before, then the anchor goes.
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 * 1: Level (true) or settle back (false) <BOOL>
 * 2: Instantly <BOOL> (default: false)
 * 3: Run once done, with the G/ATOR as _this <CODE> (default: {})
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar, true] call PTF_GATOR_fnc_level
 */
#include "..\script_gator.hpp"
params [["_radar", objNull, [objNull]], ["_level", true, [true]], ["_instant", false, [false]], ["_done", {}, [{}]]];

if (!isServer) exitWith {[_radar, _level, _instant, _done] remoteExecCall ["PTF_GATOR_fnc_level", 2]};
if (isNull _radar || {_radar getVariable ["PTF_GATOR_levelling", false]}) exitWith {};
private _leveled = _radar getVariable ["PTF_GATOR_leveled", false];
if (_leveled isEqualTo _level) exitWith {_radar call _done};

// Move the anchor (and the trailer with it) and the legs from one pose to another.
// A pose is [model origin ASL, vectorDir, vectorUp].
private _move = {
	params ["_radar", "_from", "_to", "_phases", "_instant", "_finish"];
	private _anchor = _radar getVariable ["PTF_GATOR_anchor", objNull];
	private _offset = _radar getVariable ["PTF_GATOR_anchorOffset", [0, 0, 0]];
	if (isNull _anchor) then {_instant = true};
	private _place = {
		params ["_anchor", "_offset", "_origin", "_dir", "_up"];
		private _right = _dir vectorCrossProduct _up;
		_anchor setVectorDirAndUp [_dir, _up];
		_anchor setPosWorld (_origin vectorDiff ((_right vectorMultiply (_offset select 0)) vectorAdd (_dir vectorMultiply (_offset select 1))
			vectorAdd (_up vectorMultiply (_offset select 2))));
	};
	{
		private _source = "ptf_gator_leg_" + _x;
		private _phase = _phases select _forEachIndex;
		_radar setVariable ["PTF_GATOR_legTarget_" + _x, _phase, true];
		if (_instant) then {
			_radar animateSource [_source, _phase, true];
		} else {
			_radar animateSource [_source, _phase, (abs (_phase - (_radar animationSourcePhase _source)) * LEG_PERIOD / LEVEL_TIME) max 0.01];
		};
	} forEach LEGS;
	if (_instant) exitWith {
		if (!isNull _anchor) then {([_anchor, _offset] + _to) call _place};
		_radar call _finish;
	};
	private _start = CBA_missionTime;
	[{
		params ["_args", "_handle"];
		_args params ["_radar", "_anchor", "_offset", "_from", "_to", "_start", "_place", "_finish"];
		if (isNull _radar || {isNull _anchor}) exitWith {[_handle] call CBA_fnc_removePerFrameHandler};
		private _t = ((CBA_missionTime - _start) / LEVEL_TIME) min 1;
		private _s = _t * _t * (3 - 2 * _t);
		private _lerp = {params ["_a", "_b"]; _a vectorAdd ((_b vectorDiff _a) vectorMultiply _s)};
		private _dir = vectorNormalized ([_from select 1, _to select 1] call _lerp);
		private _up = vectorNormalized ([_from select 2, _to select 2] call _lerp);
		// Keep dir and up square to each other.
		_dir = vectorNormalized (_up vectorCrossProduct (_dir vectorCrossProduct _up));
		[_anchor, _offset, [_from select 0, _to select 0] call _lerp, _dir, _up] call _place;
		if (_t >= 1) then {
			[_handle] call CBA_fnc_removePerFrameHandler;
			_radar call _finish;
		};
	}, 0, [_radar, _anchor, _offset, _from, _to, _start, _place, _finish]] call CBA_fnc_addPerFrameHandler;
};

private _now = [_radar modelToWorldWorld [0, 0, 0], vectorDir _radar, vectorUp _radar];

if (_level) then {
	// Upright on the same heading, with the wheels and the tongue stand just clear of the
	// ground and every leg reaching at least half way, so they all bear.
	private _dir = vectorNormalized [(_now select 1) select 0, (_now select 1) select 1, 0];
	private _up = [0, 0, 1];
	private _right = _dir vectorCrossProduct _up;
	private _origin = +(_now select 0);
	private _ground = {
		params ["_point"];
		[_radar, _origin vectorAdd (_right vectorMultiply (_point select 0)) vectorAdd (_dir vectorMultiply (_point select 1))] call PTF_GATOR_fnc_groundUnder
	};
	private _feet = LEGS apply {[LEG_FOOT get _x] call _ground};
	private _height = 0.02 max (selectMax (REST_POINTS apply {[_x] call _ground}) - (_origin select 2) + 0.02);
	_height = _height max (selectMax _feet - (_origin select 2) - LEG_TRAVEL * 0.5 + 0.0);
	_origin set [2, (_origin select 2) + _height];
	private _phases = _feet apply {((_origin select 2) + LEG_TRAVEL - _x) / LEG_TRAVEL};
	if (selectMax _phases > LEG_MAX_PHASE) exitWith {
		private _near = allPlayers select {_x distance _radar < 15};
		if (_near isNotEqualTo []) then {
			["The ground is too steep to level the G/ATOR. It stands on its wheels and legs as it is.", 1.5] remoteExecCall ["ace_common_fnc_displayTextStructured", _near];
		};
		_radar call _done;
	};

	// Hang it from an anchor where it stands, then lift.
	private _anchor = createVehicle ["Land_Can_V3_F", [0, 0, 0], [], 0, "CAN_COLLIDE"];
	_anchor hideObjectGlobal true;
	_anchor allowDamage false;
	_anchor setVectorDirAndUp [_now select 1, _now select 2];
	_anchor setPosWorld (_now select 0);
	_radar attachTo [_anchor];
	_radar setVectorDirAndUp [[0, 1, 0], [0, 0, 1]];
	// Where the trailer's origin sits on the anchor (in the anchor's own axes).
	private _rel = (_radar modelToWorldWorld [0, 0, 0]) vectorDiff getPosWorld _anchor;
	private _r0 = (_now select 1) vectorCrossProduct (_now select 2);
	_radar setVariable ["PTF_GATOR_anchor", _anchor, true];
	_radar setVariable ["PTF_GATOR_anchorOffset", [_rel vectorDotProduct _r0, _rel vectorDotProduct (_now select 1), _rel vectorDotProduct (_now select 2)]];
	_radar setVariable ["PTF_GATOR_restPose", [_now, LEGS apply {_radar animationSourcePhase ("ptf_gator_leg_" + _x)}]];
	// where each leg comes back to, for how long raising one takes (PTF_GATOR_fnc_task)
	_radar setVariable ["PTF_GATOR_restPhases", LEGS apply {_radar animationSourcePhase ("ptf_gator_leg_" + _x)}, true];
	_radar setVariable ["PTF_GATOR_levelling", true, true];
	[_radar, _now, [_origin, _dir, _up], _phases, _instant, compile format ["
		_this setVariable ['PTF_GATOR_levelling', false, true];
		_this setVariable ['PTF_GATOR_leveled', true, true];
		_this call %1;
	", _done]] call _move;
} else {
	(_radar getVariable ["PTF_GATOR_restPose", [_now, LEGS apply {_radar getVariable ["PTF_GATOR_legTarget_" + _x, 0]}]]) params ["_rest", "_phases"];
	_radar setVariable ["PTF_GATOR_levelling", true, true];
	[_radar, _now, _rest, _phases, _instant, compile format ["
		private _anchor = _this getVariable ['PTF_GATOR_anchor', objNull];
		detach _this;
		deleteVehicle _anchor;
		_this setVariable ['PTF_GATOR_anchor', objNull, true];
		_this setVelocity [0, 0, 0];
		_this setVariable ['PTF_GATOR_levelling', false, true];
		_this setVariable ['PTF_GATOR_leveled', false, true];
		_this call %1;
	", _done]] call _move;
};
