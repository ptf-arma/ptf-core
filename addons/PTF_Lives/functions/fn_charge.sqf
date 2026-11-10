/*
	Server: a player used a life (died, or left while unconscious).

	Once per body per player: the unit remembers whose life it already cost, so
	a body that dies after its player left unconscious, or one retired by
	fn_retire, isn't charged twice. A different player who later takes the same
	slot is charged for their own deaths.

	Params: [unit, SteamID, reason for the log]
*/
params ["_unit", "_uid", "_why"];
if ((_unit getVariable ["PTF_Lives_charged", ""]) isEqualTo _uid) exitWith {};
_unit setVariable ["PTF_Lives_charged", _uid];
// off: dying is free
if (!PTF_Lives_on) exitWith {};

private _entry = PTF_Lives_book getOrDefault [_uid, []];
if (_entry isEqualTo []) then {
	_entry = [name _unit, PTF_Lives_start, 0];
	PTF_Lives_book set [_uid, _entry];
};
_entry set [1, ((_entry select 1) - 1) max 0];
_entry set [2, (_entry select 2) + 1];
diag_log format ["[PTF_Lives] %1 %2: %3 lives left", _entry select 0, _why, _entry select 1];
call PTF_Lives_fnc_publish;
