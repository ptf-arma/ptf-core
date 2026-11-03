/*
	GLT_fnc_updateMarkerActions  (Turret Enhanced 2026 Version)
	Refreshes the titles of the "Mark Target" scroll-menu actions on every vehicle after a
	marker type/colour CBA setting changes. Called from the CBA settings callbacks.
*/

if (!hasInterface) exitWith {};

{
	private _ids = _x getVariable ["GLT_markerActionIds", []];
	private _veh = _x;
	{
		_veh setUserActionText [_x, [_forEachIndex + 1] call GLT_fnc_markerActionTitle];
	} forEach _ids;
} forEach (vehicles select {(_x getVariable ["GLT_markerActionIds", []]) isNotEqualTo []});
