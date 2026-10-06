/*
	GLT_fnc_markerList  (Turret Enhanced 2026 Version)
	"Marker List" window (dialogs\markerList.h): the player's own Turret Enhanced markers, with
	slew-to, delete and hide / unhide.

	Hidden markers (GLT_hiddenMarkers) stay on the map and in this list, greyed out at the bottom, but are
	not drawn in the camera overlay. Selecting one turns the Hide button into Unhide.

	Modes:
		"open"      []            - keybind / scroll action entry point
		"onLoad"    [_display]
		"fill"      [_display]    - (re)build the list, keeping the selected marker selected
		"selChanged"[]            - update the Hide / Unhide button text
		"slew"      []            - slew camera to selected marker and close  (Slew / double-click / Enter)
		"delete"    []            - delete selected marker from the map        (Delete button / Del key)
		"hide"      []            - toggle hidden state of the selected marker (Hide / Unhide button)
		"onUnload"  []

	Returns: <BOOL> for "open" (true if handled, lets CBA consume the key press)
*/

#define IDD_MARKERLIST 589
#define IDC_LIST       1500
#define IDC_EMPTY      1001
#define IDC_HIDE       1602

params ["_mode", ["_args", []]];

if (isNil "GLT_myMarkers") then {GLT_myMarkers = []};
if (isNil "GLT_hiddenMarkers") then {GLT_hiddenMarkers = []};

private _getSelected = {
	private _display = findDisplay IDD_MARKERLIST;
	if (isNull _display) exitWith {""};
	private _list = _display displayCtrl IDC_LIST;
	private _row = lbCurSel _list;
	if (_row < 0) exitWith {""};
	_list lbData _row
};

switch (_mode) do
{
	case "open":
	{
		if (dialog) exitWith {false};
		private _veh = call GLT_fnc_getISRVehicle;
		if (isNull _veh) exitWith {false};
		GLT_listVehicle = _veh;
		createDialog "GLT_MarkerList";
		true
	};

	case "onLoad":
	{
		_args params ["_display"];

		_display displayAddEventHandler ["KeyDown", {
			params ["_display", "_key"];
			switch (true) do
			{
				case (_key in [28, 156]): {["slew"] call GLT_fnc_markerList; true};	// Enter / Numpad Enter
				case (_key == 211):       {["delete"] call GLT_fnc_markerList; true};	// Delete
				default {false};
			};
		}];

		private _list = _display displayCtrl IDC_LIST;
		_list ctrlAddEventHandler ["LBDblClick", {["slew"] call GLT_fnc_markerList}];
		_list ctrlAddEventHandler ["LBSelChanged", {["selChanged"] call GLT_fnc_markerList}];

		// Pass the display: findDisplay does not return a dialog while its onLoad is still running
		["fill", [_display]] call GLT_fnc_markerList;
		ctrlSetFocus _list;
	};

	case "fill":
	{
		_args params [["_display", findDisplay IDD_MARKERLIST, [displayNull]]];
		if (isNull _display) exitWith {};
		private _list = _display displayCtrl IDC_LIST;

		// Keep the same marker selected after a rebuild (fall back to the same row)
		private _prevRow = lbCurSel _list;
		private _prevMarker = if (_prevRow >= 0) then {_list lbData _prevRow} else {""};

		// Drop markers that no longer exist (deleted from the map by anyone)
		GLT_myMarkers = GLT_myMarkers select {markerType _x != ""};
		GLT_hiddenMarkers = GLT_hiddenMarkers select {_x in GLT_myMarkers};

		// Visible markers first, hidden ones greyed out at the bottom (each group in placement order)
		private _visible = GLT_myMarkers select {!(_x in GLT_hiddenMarkers)};
		private _hidden  = GLT_myMarkers select {_x in GLT_hiddenMarkers};

		lbClear _list;
		{
			private _isHidden = _x in GLT_hiddenMarkers;
			private _pos = markerPos _x;
			private _text = markerText _x;
			if (_text == "") then {_text = "(no text)"};
			if (_isHidden) then {_text = _text + "  [hidden]"};

			private _row = _list lbAdd format ["%1     %2", _text, mapGridPosition _pos];
			_list lbSetData [_row, _x];

			([markerType _x, markerColor _x] call GLT_fnc_markerStyle) params ["_icon", "_rgba"];
			_list lbSetPicture [_row, _icon];

			if (_isHidden) then
			{
				private _grey = [0.5, 0.5, 0.5, 0.6];
				_list lbSetColor [_row, _grey];
				_list lbSetPictureColor [_row, _grey];
				_list lbSetPictureColorSelected [_row, _grey];
			}
			else
			{
				_list lbSetPictureColor [_row, _rgba];
				_list lbSetPictureColorSelected [_row, _rgba];
			};
		} forEach (_visible + _hidden);

		private _count = lbSize _list;
		private _empty = _display displayCtrl IDC_EMPTY;
		_empty ctrlShow (_count == 0);
		if (_count == 0) then
		{
			// Show the keys / buttons the player actually bound (Options > Controls)
			_empty ctrlSetText format ["No markers placed yet (%1)",
				(["GLT_markSlot1", "GLT_markSlot2", "GLT_markSlot3", "GLT_markSlot4"] apply {[_x] call GLT_fnc_keyName}) joinString " / "];
		};

		if (_count > 0) then
		{
			private _sel = -1;
			if (_prevMarker != "") then
			{
				for "_i" from 0 to (_count - 1) do
				{
					if ((_list lbData _i) == _prevMarker) exitWith {_sel = _i};
				};
			};
			if (_sel < 0) then {_sel = (_prevRow max 0) min (_count - 1)};
			_list lbSetCurSel _sel;
		};

		["selChanged"] call GLT_fnc_markerList;
	};

	case "selChanged":
	{
		private _display = findDisplay IDD_MARKERLIST;
		if (isNull _display) exitWith {};
		private _marker = call _getSelected;
		private _button = _display displayCtrl IDC_HIDE;
		if (_marker != "" && {_marker in GLT_hiddenMarkers}) then
		{
			_button ctrlSetText "Unhide";
			_button ctrlSetTooltip "Show this marker in the camera overlay again";
		}
		else
		{
			_button ctrlSetText "Hide";
			_button ctrlSetTooltip "Hide from the camera overlay and grey out here. The marker stays on the map";
		};
	};

	case "slew":
	{
		private _marker = call _getSelected;
		if (_marker == "") exitWith {};
		private _veh = missionNamespace getVariable ["GLT_listVehicle", objNull];
		closeDialog 1;
		if ([_veh, markerPos _marker] call GLT_fnc_slewTo) then
		{
			systemChat format ["Turret Slewed to %1 (%2)", markerText _marker, mapGridPosition markerPos _marker];
		};
	};

	case "delete":
	{
		private _marker = call _getSelected;
		if (_marker == "") exitWith {};
		GLT_myMarkers = GLT_myMarkers - [_marker];
		GLT_hiddenMarkers = GLT_hiddenMarkers - [_marker];
		deleteMarker _marker;
		call GLT_fnc_buildOverlayList;
		["fill", [findDisplay IDD_MARKERLIST]] call GLT_fnc_markerList;
	};

	case "hide":
	{
		private _marker = call _getSelected;
		if (_marker == "") exitWith {};
		if (_marker in GLT_hiddenMarkers) then
		{
			GLT_hiddenMarkers = GLT_hiddenMarkers - [_marker];
		}
		else
		{
			GLT_hiddenMarkers pushBack _marker;
		};
		call GLT_fnc_buildOverlayList;
		["fill", [findDisplay IDD_MARKERLIST]] call GLT_fnc_markerList;
	};

	case "onUnload":
	{
		GLT_listVehicle = nil;
	};
};
