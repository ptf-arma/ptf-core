/*
	Client: put the briefing controls on a ship's podium laptop. The laptop is
	part of the ship's model, so the actions hang on an invisible local helper
	placed on it.
*/
params ["_ship"];
([_ship] call PTF_Briefing_fnc_laptopPos) params ["_part", "_local"];
if (isNull _part) exitWith {false};

private _helper = "Land_HelipadEmpty_F" createVehicleLocal [0, 0, 0];
_helper attachTo [_part, _local];
_helper setVariable ["PTF_Briefing_ship", _ship];
_ship setVariable ["PTF_Briefing_helper", _helper];

// ACE runs these later on their own, so they only use _target and globals.
private _ready = {missionNamespace getVariable ["PTF_Briefing_ready", false]};
private _hasDeck = {
	params ["_target"];
	(missionNamespace getVariable ["PTF_Briefing_ready", false])
	&& {(((_target getVariable ["PTF_Briefing_ship", objNull]) getVariable ["PTF_Briefing_deck", []])) isNotEqualTo []}
};
private _set = {
	params ["_target", "", "_args"];
	[_target getVariable "PTF_Briefing_ship", _args select 0, player, clientOwner] remoteExecCall ["PTF_Briefing_fnc_setSlide", 2];
};

private _root = [
	"PTF_Briefing", "Briefing screens", "\a3\ui_f\data\igui\cfg\simpletasks\types\documents_ca.paa",
	{
		if !(missionNamespace getVariable ["PTF_Briefing_ready", false]) then {
			["Briefing screens need billet-link on the server."] call PTF_Briefing_fnc_notify;
		};
	},
	{true}, {}, [], [0, 0, 0.1], 3
] call ace_interact_menu_fnc_createAction;
[_helper, 0, [], _root] call ace_interact_menu_fnc_addActionToObject;

{
	_x params ["_id", "_label", "_statement", "_condition", ["_args", []]];
	private _action = [
		"PTF_Briefing_" + _id, _label, "", _statement, _condition, {}, _args, [0, 0, 0], 3
	] call ace_interact_menu_fnc_createAction;
	[_helper, 0, ["PTF_Briefing"], _action] call ace_interact_menu_fnc_addActionToObject;
} forEach [
	["next", "Next slide", _set, _hasDeck, ["next"]],
	["prev", "Previous slide", _set, _hasDeck, ["prev"]],
	["first", "First slide", _set, _hasDeck, ["first"]],
	["blank", "Blank screens", _set, _hasDeck, ["blank"]],
	["load", "Load slides...", {
		params ["_target"];
		[_target getVariable "PTF_Briefing_ship"] call PTF_Briefing_fnc_openLoadDialog;
	}, _ready],
	["reload", "Reload slides (show edits)", {
		params ["_target"];
		private _ship = _target getVariable "PTF_Briefing_ship";
		[_ship, _ship getVariable ["PTF_Briefing_url", ""], true, player, clientOwner] remoteExecCall ["PTF_Briefing_fnc_requestLoad", 2];
	}, _hasDeck],
	["clear", "Clear slides", _set, _hasDeck, ["clear"]]
];
true
