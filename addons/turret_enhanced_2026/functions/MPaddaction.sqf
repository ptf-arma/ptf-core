/*
Written by Erik Kofahl (Fat_Lurch) for TSOG
*/

_unit = _this;

_pri = -1000;

// GLT: the CBA keybinds that were registered here (again every time any aircraft initialised on any
// machine) were replaced by native Options > Controls actions: config.cpp (CfgUserActions) + XEH_postInit.sqf.

// GLT: marker actions replaced - 4 slots, titles coloured from the GLT marker settings (refreshed by
// GLT_fnc_updateMarkerActions), placing through GLT_fnc_addMarker.
private _markerActionIds = [];
{
	_x params ["_slot", "_offset"];
	_markerActionIds pushBack (_unit addAction [[_slot] call GLT_fnc_markerActionTitle, format ["[%1] call GLT_fnc_addMarker", _slot], nil, _pri - _offset, false, true, "", "(([_this, _target] call fatlurch_fnc_isViewISR)&&(Fat_Lurch_Markers))"]);
} forEach [[1, 0], [2, 1], [3, 2], [4, 2.2]];
_unit setVariable ["GLT_markerActionIds", _markerActionIds];
_unit addAction ["Marker List", {["open"] call GLT_fnc_markerList;}, nil, _pri - 2.5, false, true, "", "(([_this, _target] call fatlurch_fnc_isViewISR)&&(Fat_Lurch_Markers))"];	// GLT: new
// GLT: new - same as the "Cycle Camera Overlay" key; title shows the current mode (GLT_fnc_buildOverlayList keeps
// it current). The menu stays open so it can be used repeatedly.
_unit setVariable ["GLT_overlayActionId", _unit addAction [format ["Camera Overlay: %1", GLT_overlayModeNames select ((call GLT_fnc_overlayModes) select 0)], {[] call GLT_fnc_cycleMarkerOverlay}, nil, _pri - 2.6, false, false, "", "([_this, _target] call fatlurch_fnc_isViewISR)"]];

_unit addAction ["Change Altitude", "_this call fatlurch_fnc_changeAltitude",nil, _pri - 3,false, true, "","(([_this, _target] call fatlurch_fnc_isViewISR) && (_target isKindOf 'uav'))"];	//2020_08_24
_unit addAction ["Change Loiter", "_this call fatlurch_fnc_changeLoiter",nil, _pri - 4,false, true, "","(([_this, _target] call fatlurch_fnc_isViewISR) && (_target isKindOf 'uav') && (waypointType [group _target, currentWaypoint group _target] == 'LOITER'))"];	//2020_08_24
_unit addAction ["Map Slew", {params ["_target", "_caller", "_actionId", "_arguments"]; [_target, _caller] call fatlurch_fnc_mapSlew;},nil, _pri - 5,false, true, "","(([_this, _target] call fatlurch_fnc_isViewISR)&&(Fat_Lurch_MapSlew))"];
_unit addAction ["Slew to Grid", {params ["_target", "_caller", "_actionId", "_arguments"]; [_target, _caller] call fatlurch_fnc_inputGrid;},nil, _pri - 6, false, true, "","(([_this, _target] call fatlurch_fnc_isViewISR)&&(Fat_Lurch_Grid))"];
_unit addAction ["Measure Distance", {params ["_target", "_caller", "_actionId", "_arguments"]; [_target] call fatlurch_fnc_measDistance;},nil, _pri - 7,false, true, "","(([_this, _target] call fatlurch_fnc_isViewISR)&&(Fat_Lurch_Measure)&&(isNil 'GLT_measureStart'))"];	// GLT: hidden while a measurement is running
_unit addAction ["Measure", {params ["_target", "_caller", "_actionId", "_arguments"]; [_target] call fatlurch_fnc_measDistance;},nil, _pri - 8,false, true, "","(([_this, _target] call fatlurch_fnc_isViewISR)&&(Fat_Lurch_Measure)&&(!isNil 'GLT_measureStart'))"];	// GLT: finishes a measurement (was "Placeholder for Measure")
_unit addAction ["Weapon Status", {params ["_target", "_caller", "_actionId", "_arguments"]; [_target] call fatlurch_fnc_weaponReport;},nil, _pri - 9,false, true, "","(([_this, _target] call fatlurch_fnc_isViewISR)&&(_target isKindOf 'uav'))"];
_unit addAction ["Reset VMS", {params ["_target", "_caller", "_actionId", "_arguments"]; [_target] call fatlurch_fnc_resetUAV;},nil, _pri - 10,false, true, "","(([_this, _target] call fatlurch_fnc_isViewISR)&&(_target isKindOf 'uav'))"];



/* TODO

-Change Loiter Radius if UAV and current waypoint type is loiter

*/


_this spawn fatLurch_fnc_North_Ind;

// GLT: "mkrNum=0;" removed - it reset every player's marker counter whenever any aircraft initialised.
// The counter is now GLT_markerCounter, local to each player (XEH_postInit.sqf).

