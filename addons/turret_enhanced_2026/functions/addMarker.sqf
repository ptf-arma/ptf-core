/*
	GLT_fnc_addMarker  (Turret Enhanced 2026 Version)
	Entry point for the "Mark Target" controls (SHIFT+1/2/3/4 by default, Options > Controls) and scroll-menu actions.
	Captures the position under the crosshair immediately, then either opens the marker text
	dialog or places the marker straight away (CBA setting "Prompt for marker text").

	Params: _slot <NUMBER> 1 to 4
	Returns: <BOOL> true if handled (lets CBA consume the key press)
*/

params [["_slot", 1, [0]]];

if (!hasInterface) exitWith {false};
if (!(missionNamespace getVariable ["Fat_Lurch_Markers", true])) exitWith {false};
if (dialog) exitWith {false};

private _veh = call GLT_fnc_getISRVehicle;
if (isNull _veh) exitWith {false};

// Capture where the turret is looking NOW, before the dialog opens
private _pos = screenToWorld [0.5, 0.5];
private _channel = currentChannel;

if (missionNamespace getVariable ["GLT_MarkerPromptText", true]) then
{
	GLT_pendingMarker = [_slot, _pos, _channel];
	createDialog "GLT_MarkerText";
}
else
{
	[_slot, _pos, _channel, ""] call GLT_fnc_placeMarker;
};

true
