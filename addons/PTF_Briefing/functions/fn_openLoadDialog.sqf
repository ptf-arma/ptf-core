/*
	Client: ask for a Google Slides link and send it to the server.
*/
params ["_ship"];
if (isNil "zen_dialog_fnc_create") exitWith {["Loading slides needs Zeus Enhanced (ZEN)."] call PTF_Briefing_fnc_notify};
[
	"Load Google Slides",
	[
		["EDIT", ["Google Slides link", "Either: Share, set General access to 'Anyone with the link' and copy the link. Or: File > Share > Publish to web, and copy that link. Paste it here with Ctrl+V."], [_ship getVariable ["PTF_Briefing_url", ""]], true]
	],
	{
		params ["_values", "_ship"];
		[_ship, _values select 0, false, player, clientOwner] remoteExecCall ["PTF_Briefing_fnc_requestLoad", 2];
	},
	{},
	_ship
] call zen_dialog_fnc_create;
