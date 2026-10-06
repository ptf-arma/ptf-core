/*
Written by Erik Kofahl (Fat_Lurch) for TSOG
2026 Version: uses a stackable MapSingleClick mission event handler instead of onMapSingleClick (a single
global slot that other mods such as ACE also use), and GLT_fnc_slewTo, which always releases the lock.
*/

params ["_veh", "_gunner"];

// Clean up a previous map slew that was never completed
if (!isNil "GLT_mapSlewEH") then
{
	removeMissionEventHandler ["MapSingleClick", GLT_mapSlewEH];
	GLT_mapSlewEH = nil;
};

GLT_mapSlewEH = addMissionEventHandler ["MapSingleClick", {
	params ["_units", "_pos", "_alt", "_shift"];
	_thisArgs params ["_veh"];

	removeMissionEventHandler [_thisEvent, _thisEventHandler];
	GLT_mapSlewEH = nil;

	openMap false;
	if ([_veh, _pos] call GLT_fnc_slewTo) then
	{
		systemChat format ["Turret Slewed to %1", mapGridPosition _pos];
	};
}, [_veh]];

openMap true;
systemChat "Click on the map to slew the turret";

// If the map is closed without a click, drop the handler
[{visibleMap}, {
	[{!visibleMap}, {
		if (!isNil "GLT_mapSlewEH") then
		{
			removeMissionEventHandler ["MapSingleClick", GLT_mapSlewEH];
			GLT_mapSlewEH = nil;
			systemChat "Map slew cancelled";
		};
	}] call CBA_fnc_waitUntilAndExecute;
}, [], 5] call CBA_fnc_waitUntilAndExecute;
