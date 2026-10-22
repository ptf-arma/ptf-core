/*
	GLT_fnc_slewTo  (Turret Enhanced 2026 Version)
	Slews the camera the local player is looking through to a position. Used by Map Slew, Slew to
	Grid and the Marker List.

	Methods (the monitor, GLT_fnc_slewMonitor, switches to the fallback if the first one doesn't take):
		Turret camera (helicopter / UAV gunner, vehicle commander...):
			lockCameraTo position  ->  fallback: lockCameraTo an invisible local helper object
			(the engine only accepts positions on stabilized optics)
		Pilot camera (targeting pod, turret path [-1]):
			setPilotCameraTarget   ->  fallback: steer with setPilotCameraDirection
			(some mod pods don't accept a target, e.g. without suitable sensors)

	The lock is released by the monitor when the camera is on target, when it stops moving (target
	unreachable / not exactly matched), after a timeout, or when the player leaves the view. The camera is
	never left locked on the point.

	Params:
		_veh    <OBJECT> the vehicle / UAV
		_posAGL <ARRAY>  target position (AGL, e.g. marker position or map click)
	Returns: <BOOL> true if a slew was started
*/

params [["_veh", objNull, [objNull]], ["_posAGL", [], [[]]]];

if (isNull _veh || {count _posAGL < 2}) exitWith {false};

private _pos = [_posAGL select 0, _posAGL select 1, 0];
private _posASL = AGLToASL _pos;

// Finish (and release) a slew that is still running
if (!isNil "GLT_slewState") then {["new slew"] call GLT_fnc_slewMonitor};

private _path = if (unitIsUAV _veh) then
{
	private _gunner = gunner _veh;
	if (isNull _gunner) then {[0]} else {_veh unitTurret _gunner}
}
else
{
	_veh unitTurret player
};

private _usePilot = _path isEqualTo [] || {_path isEqualTo [-1]};

if (_usePilot && {!hasPilotCamera _veh}) exitWith {false};

private _method = if (_usePilot) then
{
	_veh setPilotCameraTarget _posASL;
	"pilotTarget"
}
else
{
	_veh lockCameraTo [_posASL, _path];
	"turretPos"
};


// [vehicle, path, method, targetASL, targetAGL, startTime, lastCameraDir, stableTicks, helperObject, fallbackChecked]
GLT_slewState = [_veh, _path, _method, _posASL, _pos, diag_tickTime, [0, 0, 0], 0, objNull, false];
// Called with [] on purpose: a per-frame handler passes [args, handle] as _this, which the monitor
// must not receive (its parameters are a finish reason and a release flag).
GLT_slewPFH = [{[] call GLT_fnc_slewMonitor}, 0.1] call CBA_fnc_addPerFrameHandler;

true
