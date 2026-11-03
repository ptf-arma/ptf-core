/*
Written by Erik Kofahl (Fat_Lurch) for TSOG
2026 Version: rewritten as a start/finish toggle (was a two-step scroll action with a global waitUntil).

Measure tool - toggle.
	1st call: stores the point under the crosshair as the start of the measurement.
	2nd call: measures from the stored start to the point under the crosshair and reports it.

Used by both the "Measure Distance" / "Measure" scroll-menu actions and the
"Measure Distance (start / finish)" control (SHIFT+6 by default, Options > Controls). The start point is local to the
player (GLT_measureStart).

Params: _veh <OBJECT> (optional) vehicle the action was used from
Returns: <BOOL> true if handled
*/

params [["_veh", objNull, [objNull]]];

if (!(missionNamespace getVariable ["Fat_Lurch_Measure", true])) exitWith {false};
if (isNull (call GLT_fnc_getISRVehicle)) exitWith {false};

private _here = screenToWorld [0.5, 0.5];

if (isNil "GLT_measureStart") then
{
	GLT_measureStart = _here;
	systemChat format ["Measure start set at %1. Slew to the new position and press %2 again (or select Measure)", mapGridPosition _here, ["GLT_measure"] call GLT_fnc_keyName];
}
else
{
	private _p1 = GLT_measureStart;
	GLT_measureStart = nil;

	private _dist = round (_p1 distance2D _here);
	private _dir = round (_p1 getDir _here);

	systemChat format ["Distance: %1 meters (2D) - Heading: %2°", _dist, _dir];
};

true
