/*
	GLT_fnc_drawLaserOverlay  [GLT] Goltred update - not part of the original Turret Enhanced by Fat_Lurch.
	(Draw3D, every frame) Draws the laser spots of other friendly players / units / vehicles in the camera
	view, labelled with the lasing group's name (+ ACE laser code when ACE is loaded).
	Icon: the mod's own images\LaserSpot.paa, drawn in its own colours. Player settings: icon size
	(GLT_LaserOverlayIconSize) and label colour (GLT_LaserOverlayTextColor). Icon and label are two draws so
	the label colour doesn't tint the icon.
	Only spots the camera can actually see are drawn:
		- inside the camera's field of view (no edge arrows)
		- in line of sight: not hidden by terrain, buildings or other objects. Anything within TARGET_RADIUS of
		  the spot doesn't count: that is the lased target itself (e.g. a vehicle lased from its far side),
		  which should still show its laser
		  The line-of-sight rays are the costly part, so their result is kept on the laser object (local
		  variable GLT_los) and re-checked LOS_INTERVAL times per second, not every frame.
	The list comes from GLT_fnc_friendlyLasers (rebuilt twice a second).
*/

#include "..\script_name.hpp"	// GLT_QPATH: file paths from the PBO prefix

#define TARGET_RADIUS 8	// m
#define LOS_INTERVAL 0.2	// s between line-of-sight checks per laser

private _lasers = missionNamespace getVariable ["GLT_friendlyLasers", []];
if (_lasers isEqualTo []) exitWith {};
private _veh = call GLT_fnc_getISRVehicle;
if (isNull _veh) exitWith {};

#define ICON GLT_QPATH(images\LaserSpot.paa)
#define CLEAR_TEX "#(argb,8,8,3)color(0,0,0,0)"	// invisible icon: places the label as if under the real one

private _camPos = AGLToASL (positionCameraToWorld [0, 0, 0]);
private _size = missionNamespace getVariable ["GLT_LaserOverlayIconSize", 0.6];
private _textColor = +(missionNamespace getVariable ["GLT_LaserOverlayTextColor", [1, 0.15, 0.15, 1]]);
if (count _textColor < 4) then {_textColor pushBack 1};

{
	_x params ["_laser", "_label"];
	// The laser object is deleted when the designator is switched off
	if (!isNull _laser) then
	{
		private _spot = getPosASLVisual _laser;
		if ((worldToScreen (ASLToAGL _spot)) isEqualTo []) then {continue};	// outside the camera view

		// Line of sight (cached): the first terrain / object hit between camera and spot must be near the spot
		(_laser getVariable ["GLT_los", [false, -1]]) params ["_visible", "_nextCheck"];
		if (diag_tickTime >= _nextCheck) then
		{
			private _terrainHit = terrainIntersectAtASL [_camPos, _spot];
			_visible = _terrainHit isEqualTo [0, 0, 0] || {(_terrainHit distance _spot) <= TARGET_RADIUS};
			if (_visible) then
			{
				private _hits = lineIntersectsSurfaces [_camPos, _spot, _veh, _laser, true, 1, "VIEW", "FIRE"];
				_visible = _hits isEqualTo [] || {((_hits select 0 select 0) distance _spot) <= TARGET_RADIUS};
			};
			_laser setVariable ["GLT_los", [_visible, diag_tickTime + LOS_INTERVAL]];
		};
		if (!_visible) then {continue};

		private _pos = ASLToAGL _spot;
		drawIcon3D [ICON, [1, 1, 1, 1], _pos, _size, _size, 0, "", 0, 0.032, "PuristaBold", "center", false];
		drawIcon3D [CLEAR_TEX, _textColor, _pos, _size, _size, 0, _label, 2, 0.032, "PuristaBold", "center", false];
	};
} forEach _lasers;
