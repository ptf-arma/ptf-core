/*
	XEH_postInit.sqf (Turret Enhanced 2026 Version)
	Runs once per machine with a player. Attaches the Controls actions (config.cpp (CfgUserActions)) and
	initialises the LOCAL marker counter. The original registered CBA keybinds and reset the counter in
	MPaddaction.sqf, which runs every time any aircraft initialises on any machine.
*/

#include "script_name.hpp"

if (!hasInterface) exitWith {};

// Local, per-player marker counter. Never broadcast, never reset by other players' vehicles.
if (isNil "GLT_markerCounter") then {GLT_markerCounter = 0};
if (isNil "GLT_myMarkers") then {GLT_myMarkers = []};
if (isNil "GLT_hiddenMarkers") then {GLT_hiddenMarkers = []};	// hidden from the camera overlay via Marker List

// Laser spots announced by the machine that created them (GLT_fnc_laserCreated): [[laserObject, owner], ...]
if (isNil "GLT_laserRegistry") then {GLT_laserRegistry = []};
["GLT_laserOn", {
	params ["_laser", "_owner"];
	if (!isNull _laser && {!isNull _owner}) then {GLT_laserRegistry pushBack [_laser, _owner]};
}] call CBA_fnc_addEventHandler;

// Camera marker overlay and laser map drawing
call GLT_fnc_overlayInit;

// Controls (Options > Controls > GLT_MOD_NAME): actions are declared in config.cpp (CfgUserActions) and
// can be bound to keyboard, mouse or joystick / HOTAS. These handlers are mission-scoped, so they are
// re-added here at every mission start. The called functions ignore presses outside a camera view.
{
	_x params ["_action", "_code"];
	addUserActionEventHandler [_action, "Activate", _code];
} forEach [
	["GLT_markSlot1",  {[1] call GLT_fnc_addMarker}],
	["GLT_markSlot2",  {[2] call GLT_fnc_addMarker}],
	["GLT_markSlot3",  {[3] call GLT_fnc_addMarker}],
	["GLT_markSlot4",  {[4] call GLT_fnc_addMarker}],
	["GLT_markerList", {["open"] call GLT_fnc_markerList}],
	["GLT_measure",    {[] call fatlurch_fnc_measDistance}],
	["GLT_cycleMarkerOverlay", {[] call GLT_fnc_cycleMarkerOverlay}],
	["GLT_resetMarkerCounter", {
		GLT_markerCounter = 0;
		systemChat format ["%1: marker counter reset to 0", GLT_MOD_NAME];
	}]
];
