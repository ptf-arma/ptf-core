/*
	GLT_fnc_drawUnitOverlay  [GLT] Goltred update - not part of the original Turret Enhanced by Fat_Lurch.
	(Draw3D, every frame) Draws the NATO symbol of friendly vehicles / infantry groups in the camera view, just
	above each one, with the group name under it (setting). Only inside the camera's view (no edge arrows).
	The list comes from GLT_fnc_friendlyUnits (rebuilt twice a second); positions are read every frame so the
	icons stay on moving vehicles.
*/

#define HEIGHT 2.5	// m above the object

private _units = missionNamespace getVariable ["GLT_friendlyUnits", []];
if (_units isEqualTo []) exitWith {};
if (isNull (call GLT_fnc_getISRVehicle)) exitWith {};

private _size = missionNamespace getVariable ["GLT_UnitOverlayIconSize", 0.7];

{
	_x params ["_obj", "_icon", "_rgba", "_label"];
	if (alive _obj) then
	{
		private _pos = (ASLToAGL (getPosASLVisual _obj)) vectorAdd [0, 0, HEIGHT];
		drawIcon3D [_icon, _rgba, _pos, _size, _size, 0, _label, 2, 0.028, "PuristaMedium", "center", false];
	};
} forEach _units;
