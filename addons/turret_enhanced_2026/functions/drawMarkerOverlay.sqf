/*
	GLT_fnc_drawMarkerOverlay  (Turret Enhanced 2026 Version) (Draw3D, every frame)
	Draws map markers as icons (with their text, no distance) in the camera view while the player is in an ISR (gunner) view.
	Which markers: GLT_overlayMarkers, rebuilt twice a second by GLT_fnc_buildOverlayList from the Camera Overlay
	settings (see GLT_fnc_overlayModes), so this per-frame code never walks every map marker.
	GLT_MarkerOverlayEdgeArrows - arrows at the screen edge for drawn markers outside the camera's view
*/

private _markers = missionNamespace getVariable ["GLT_overlayMarkers", []];
if (_markers isEqualTo []) exitWith {};

private _veh = call GLT_fnc_getISRVehicle;
if (isNull _veh) exitWith {};

private _edgeArrows = missionNamespace getVariable ["GLT_MarkerOverlayEdgeArrows", true];

{
	private _type = markerType _x;
	// Filtered when the list is built; only re-check that it wasn't deleted since
	if (_type != "") then
	{
		([_type, markerColor _x] call GLT_fnc_markerStyle) params ["_icon", "_rgba"];

		// GLT: markers placed by hand on the map are black by default and usually have no text. The icon and
		// its edge arrow are drawn in the marker colour, so a black one is invisible on the camera feed:
		// draw very dark colours in light grey (camera view only - the map and Marker List keep the real colour).
		if (((_rgba select 0) max (_rgba select 1) max (_rgba select 2)) < 0.35) then
		{
			_rgba = [0.8, 0.8, 0.8, _rgba select 3];
		};

		// GLT: never pass empty text - keeps the edge arrow for markers without a label
		private _text = markerText _x;
		if (_text == "") then {_text = " "};

		private _pos = markerPos _x;
		_pos set [2, 0];

		drawIcon3D [_icon, _rgba, _pos, 0.8, 0.8, markerDir _x, _text, 2, 0.032, "PuristaMedium", "center", _edgeArrows];
	};
} forEach _markers;
