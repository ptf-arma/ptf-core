/*
	GLT_fnc_buildOverlayList  [GLT] Goltred update - not part of the original Turret Enhanced by Fat_Lurch.
	Rebuilds GLT_overlayMarkers, the markers the camera overlay draws (GLT_fnc_drawMarkerOverlay), and
	refreshes the title of the "Camera Overlay" scroll-menu action.
	Runs twice a second from GLT_fnc_overlayInit, and straight away when an overlay setting changes, the
	cycle key is used, a marker is placed, or one is hidden / deleted in the Marker List, so those changes
	show at once. Drawing then only walks this short list every frame instead of every map marker.
*/

if (!hasInterface) exitWith {};

if (isNil "GLT_myMarkers") then {GLT_myMarkers = []};
if (isNil "GLT_hiddenMarkers") then {GLT_hiddenMarkers = []};

(call GLT_fnc_overlayModes) params ["_effective", "", "_mode"];

// Keep the "Camera Overlay: <mode>" scroll-menu action title current (only touched when it changes)
private _title = format ["Camera Overlay: %1", GLT_overlayModeNames select _effective];
if (_title isNotEqualTo (missionNamespace getVariable ["GLT_overlayActionTitle", ""])) then
{
	GLT_overlayActionTitle = _title;
	{
		_x setUserActionText [_x getVariable "GLT_overlayActionId", _title];
	} forEach (vehicles select {!isNil {_x getVariable "GLT_overlayActionId"}});
};

private _source = switch (_mode) do
{
	case 1: {GLT_myMarkers};
	case 2: {allMapMarkers};
	default {[]};
};

// Icon markers that exist, are visible and aren't hidden in the Marker List
GLT_overlayMarkers = _source select {
	markerShape _x == "ICON"
	&& {markerType _x != ""}
	&& {markerAlpha _x > 0}
	&& {!(_x in GLT_hiddenMarkers)}
};
