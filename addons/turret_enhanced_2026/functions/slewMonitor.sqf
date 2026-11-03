/*
	GLT_fnc_slewMonitor  (Turret Enhanced 2026 Version)
	Runs every 0.1 s while a slew started by GLT_fnc_slewTo is in progress (state in GLT_slewState).

		- after 0.3 s: if the first method did not take, switch to the fallback
		- pilot camera direction mode: keeps steering the pod at the target
		- finishes when the camera is within 0.5 deg of the target, when it has stopped moving for
		  0.5 s (target not exactly reachable), after 10 s, or when the player leaves the view
		- on finish the lock is always released (never left stuck), so the player can move the camera freely

	Can also be called as ["reason"] call GLT_fnc_slewMonitor to force-finish (with release).
*/

#define ON_TARGET_DEG   0.5
#define STILL_DEG       0.03
#define STILL_TICKS     5
#define TIMEOUT_S       10

params [["_forceReason", "", [""]]];

if (isNil "GLT_slewState") exitWith
{
	if (!isNil "GLT_slewPFH") then {[GLT_slewPFH] call CBA_fnc_removePerFrameHandler; GLT_slewPFH = nil};
};

GLT_slewState params ["_veh", "_path", "_method", "_posASL", "_posAGL", "_start", "_lastDir", "_still", "_helper", "_fallbackChecked"];

private _finish = {
	params ["_reason"];
	switch (_method) do
	{
		case "turretPos";
		case "turretObj":   {_veh lockCameraTo [objNull, _path]};
		case "pilotTarget": {_veh setPilotCameraTarget objNull};
		default {};	// pilotDir: nothing is locked
	};
	if (!isNull _helper) then {deleteVehicle _helper};
	GLT_slewState = nil;
	if (!isNil "GLT_slewPFH") then {[GLT_slewPFH] call CBA_fnc_removePerFrameHandler; GLT_slewPFH = nil};
};

if (_forceReason != "") exitWith {[_forceReason] call _finish};

if ((call GLT_fnc_getISRVehicle) != _veh) exitWith {["left the camera view"] call _finish};

private _elapsed = diag_tickTime - _start;

// --- Fallback if the first method did not take
if (!_fallbackChecked && {_elapsed > 0.3}) then
{
	_fallbackChecked = true;
	switch (_method) do
	{
		case "pilotTarget":
		{
			if (!((getPilotCameraTarget _veh) select 0)) then
			{
				_veh setPilotCameraTarget objNull;
				_method = "pilotDir";
			};
		};
		case "turretPos":
		{
			if (isNil {_veh lockedCameraTo _path}) then
			{
				_helper = createVehicleLocal ["Land_HelipadEmpty_F", _posAGL, [], 0, "CAN_COLLIDE"];
				_veh lockCameraTo [_helper, _path];
				_method = "turretObj";
			};
		};
	};
};

// --- Pilot camera direction mode: keep steering (the aircraft moves)
if (_method == "pilotDir") then
{
	private _camPos = _veh modelToWorldVisualWorld (getPilotCameraPosition _veh);
	_veh setPilotCameraDirection (_veh vectorWorldToModelVisual (_camPos vectorFromTo _posASL));
};

// --- Where is the camera looking?
private _c0 = AGLToASL (positionCameraToWorld [0, 0, 0]);
private _c1 = AGLToASL (positionCameraToWorld [0, 0, 1]);
private _dir = _c0 vectorFromTo _c1;
private _error = acos ((((_dir vectorDotProduct (_c0 vectorFromTo _posASL)) max -1) min 1));
private _moved = if (_lastDir isEqualTo [0, 0, 0]) then {180} else {acos ((((_dir vectorDotProduct _lastDir) max -1) min 1))};
_still = if (_moved < STILL_DEG) then {_still + 1} else {0};

if (_error < ON_TARGET_DEG && {_elapsed > 0.2}) exitWith
{
	[format ["on target (%1 deg)", _error toFixed 2]] call _finish;
};
if (_still >= STILL_TICKS && {_elapsed > 1}) exitWith
{
	[format ["camera stopped %1 deg from the target", _error toFixed 2]] call _finish;
};
if (_elapsed > TIMEOUT_S) exitWith
{
	[format ["timeout, %1 deg from the target", _error toFixed 2]] call _finish;
};

GLT_slewState = [_veh, _path, _method, _posASL, _posAGL, _start, _dir, _still, _helper, _fallbackChecked];
