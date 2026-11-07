/*
	Server, from the laptop: change what the ship's screens show.

	[_ship, _action, player, clientOwner] remoteExecCall ["PTF_Briefing_fnc_setSlide", 2];

	_action: "next", "prev", "first", "blank" (screens off, slides kept) or "clear"
	(screens off, deck forgotten).
*/
params [["_ship", objNull, [objNull]], ["_action", "", [""]], ["_caller", objNull, [objNull]], ["_sentOwner", 0, [0]]];
if (!isServer || {isNull _ship}) exitWith {};
private _owner = [_sentOwner] call PTF_Briefing_fnc_callerOwner;
if !([_ship, _caller] call PTF_Briefing_fnc_canControl) exitWith {};

if (_action == "clear") exitWith {
	_ship setVariable ["PTF_Briefing_deck", [], true];
	_ship setVariable ["PTF_Briefing_blank", false, true];
	_ship setVariable ["PTF_Briefing_loading", -1e9];
};
private _deck = _ship getVariable ["PTF_Briefing_deck", []];
if (_deck isEqualTo []) exitWith {["No slides loaded. Use Load slides first."] remoteExecCall ["PTF_Briefing_fnc_notify", _owner]};
if (_action == "blank") exitWith {_ship setVariable ["PTF_Briefing_blank", true, true]};

private _count = (_deck select 1) max 1;
private _slide = _ship getVariable ["PTF_Briefing_slide", 0];
// Any move brings the screens back if they were blanked; the first press only does that.
private _wasBlank = _ship getVariable ["PTF_Briefing_blank", false];
_ship setVariable ["PTF_Briefing_blank", false, true];
if (_wasBlank && {_action != "first"}) exitWith {};
_slide = switch (_action) do {
	case "next": {(_slide + 1) min (_count - 1)};
	case "prev": {(_slide - 1) max 0};
	case "first": {0};
	default {_slide};
};
_ship setVariable ["PTF_Briefing_slide", _slide, true];
