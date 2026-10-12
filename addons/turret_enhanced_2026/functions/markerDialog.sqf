/*
	GLT_fnc_markerDialog  (Turret Enhanced 2026 Version)
	Event handling for the "GLT_MarkerText" dialog (dialogs\markerText.h).

	Modes:
		"onLoad"   [_display]            - fill header, hook Enter keys, focus the edit box
		"commit"   []                    - store typed text and close with exit code 1
		"onUnload" [_display, _exitCode] - place marker (exit code 1) or cancel (Esc / Cancel)

	Enter / Numpad Enter / OK  -> place marker with the typed text (empty text = number only)
	Escape / Cancel            -> no marker, counter is not advanced
*/

#define IDD_MARKERTEXT 588
#define IDC_HEADER     100
#define IDC_EDIT       1400

params ["_mode", ["_args", []]];

switch (_mode) do
{
	case "onLoad":
	{
		_args params ["_display"];

		private _pending = missionNamespace getVariable ["GLT_pendingMarker", []];
		if (_pending isEqualTo []) exitWith {_display closeDisplay 2};
		_pending params ["_slot", "_pos"];

		([_slot] call GLT_fnc_markerSlotInfo) params ["_type", "_color", "_typeName", "_colorName", "_hex"];
		private _num = missionNamespace getVariable ["GLT_markerCounter", 0];
		private _prefix = [_slot, _num, ""] call GLT_fnc_markerLabel;
		if (_prefix == "") then {_prefix = format ["Marker %1", _slot]};

		(_display displayCtrl IDC_HEADER) ctrlSetStructuredText parseText format [
			"<t align='center'>%1 <t color='%2'>(%3 %4)</t> @ %5</t>",
			_prefix, _hex, _colorName, _typeName, mapGridPosition _pos
		];

		_display displayAddEventHandler ["KeyDown", {
			params ["_display", "_key"];
			if (_key in [28, 156]) then	// DIK_RETURN, DIK_NUMPADENTER
			{
				["commit"] call GLT_fnc_markerDialog;
				true
			}
			else
			{
				false
			};
		}];

		uiNamespace setVariable ["GLT_markerTextValue", ""];

		// Focus next frame so the character from the SHIFT+<n> key press doesn't land in the box
		[{
			params ["_display"];
			if (isNull _display) exitWith {};
			private _edit = _display displayCtrl IDC_EDIT;
			_edit ctrlSetText "";
			ctrlSetFocus _edit;
		}, [_display]] call CBA_fnc_execNextFrame;
	};

	case "commit":
	{
		private _display = findDisplay IDD_MARKERTEXT;
		if (isNull _display) exitWith {};
		uiNamespace setVariable ["GLT_markerTextValue", ctrlText (_display displayCtrl IDC_EDIT)];
		_display closeDisplay 1;
	};

	case "onUnload":
	{
		_args params ["_display", "_exitCode"];

		private _pending = missionNamespace getVariable ["GLT_pendingMarker", []];
		GLT_pendingMarker = nil;
		if (_pending isEqualTo []) exitWith {};

		if (_exitCode == 1) then
		{
			_pending params ["_slot", "_pos", "_channel"];
			private _text = uiNamespace getVariable ["GLT_markerTextValue", ""];
			[_slot, _pos, _channel, _text] call GLT_fnc_placeMarker;
		}
		else
		{
			systemChat "Marker cancelled";
		};
	};
};
