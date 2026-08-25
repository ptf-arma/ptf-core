/*
	ZEN custom module: browse every loudspeaker sound (and playlist) in one
	list and place the chosen module pre-configured at the clicked position.
	Placement itself happens server-side (PTF_Sound_fnc_placeSpeaker), which
	sidesteps client-object races and keeps the module Zeus-editable on
	dedicated servers.

	Called by ZEN custom modules with [position ASL, attached object].
*/
params ["_posASL", "_attached"];

private _entries = [];
{
	if (getNumber (_x >> "scope") == 2) then {
		private _catName = getText (configFile >> "CfgFactionClasses" >> getText (_x >> "category") >> "displayName");
		_entries pushBack [_catName, getText (_x >> "displayName"), configName _x];
	};
} forEach ("inheritsFrom _x isEqualTo (configFile >> 'CfgVehicles' >> 'PTF_Sound_Module_base')" configClasses (configFile >> "CfgVehicles"));
_entries sort true;

[
	"Place Loudspeaker",
	[
		["LIST", ["Sound", "Broadcast to place. Preview it after placing via the right-click Loudspeaker menu."], [_entries apply {_x select 2}, _entries apply {format ["%1  -  %2", _x select 1, _x select 0]}, 0, 10], true],
		["SLIDER", ["Broadcast Range", "Metres. 0 = the sound's default range."], [0, 3000, 0, 0], true],
		["SLIDER", ["Pause Between Repeats", "Seconds. -1 = the sound's default pause."], [-1, 300, -1, 0], true],
		["CHECKBOX", ["Spawn Speaker Prop", "Create a visible loudspeaker prop and bind the broadcast to it - players can find, shoot, or ACE-cut it."], true, true],
		["CHECKBOX", ["Muted", "Place silent - position and preview it, then Resume from the right-click Loudspeaker menu."], false, true]
	],
	{
		params ["_values", "_args"];
		_args params ["_posASL"];
		_values params ["_class", "_distance", "_pause", "_spawnProp", "_muted"];
		[_class, _posASL, _distance, _pause, _muted, _spawnProp, getAssignedCuratorLogic player] remoteExec ["PTF_Sound_fnc_placeSpeaker", 2];
	},
	{},
	[_posASL, _attached]
] call zen_dialog_fnc_create;
