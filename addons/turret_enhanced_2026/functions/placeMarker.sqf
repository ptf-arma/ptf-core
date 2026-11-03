/*
	GLT_fnc_placeMarker  (Turret Enhanced 2026 Version)
	Creates the map marker for a marker slot using the configured type/colour/size and the
	player's LOCAL marker counter (GLT_markerCounter, never broadcast or reset by other
	players' vehicles).

	Params:
		_slot    <NUMBER> 1 to 4
		_pos     <ARRAY>  world position
		_channel <NUMBER> chat channel the marker is placed in (currentChannel at capture time)
		_text    <STRING> optional text typed by the player
*/

params [["_slot", 1, [0]], ["_pos", [0, 0, 0], [[]]], ["_channel", 0, [0]], ["_text", "", [""]]];

([_slot] call GLT_fnc_markerSlotInfo) params ["_type", "_color", "_typeName", "_colorName"];

if (isNil "GLT_markerCounter") then {GLT_markerCounter = 0};
private _num = GLT_markerCounter;
GLT_markerCounter = _num + 1;

// Prefix setting with {Counter} tag + optional typed text (see GLT_fnc_markerLabel)
private _label = [_slot, _num, _text] call GLT_fnc_markerLabel;

private _size = missionNamespace getVariable ["GLT_MarkerSize", 0.5];
private _grid = mapGridPosition _pos;

private _channelArray = ["Global", "Side", "Command", "Group", "Vehicle", "Direct"];
private _channelName = if (_channel >= 0 && {_channel < count _channelArray}) then {_channelArray select _channel} else {"Custom channel"};

// "_USER_DEFINED" prefix keeps the marker deletable by players like a normal map marker
private _name = format ["_USER_DEFINED_GLT_%1_%2_%3", clientOwner, _num, round (random 1e6)];

private _marker = createMarker [_name, _pos, _channel, player];
// Local setters, then one global setter at the end: the final global call syncs the whole marker once
_marker setMarkerShapeLocal "ICON";
_marker setMarkerTypeLocal _type;
_marker setMarkerTextLocal _label;
_marker setMarkerColorLocal _color;
_marker setMarkerSize [_size, _size];

// Local registry of this player's markers (camera overlay + Marker List / slew)
if (isNil "GLT_myMarkers") then {GLT_myMarkers = []};
GLT_myMarkers pushBack _marker;
call GLT_fnc_buildOverlayList;	// show it in the camera overlay straight away

systemChat format ["%1 %2 marker %3 created at %4 in %5", _colorName, _typeName, [_label, str _num] select (_label == ""), _grid, _channelName];

_marker
