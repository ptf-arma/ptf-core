/*
	Client: in or out of spectating while out of lives.

	ACE's spectator, forced so it can't be closed. ACE also puts TFAR in its
	spectator mode (TFAR_fnc_forceSpectator): the player hears the people
	around the camera but living players can't hear them. Without ACE, the
	vanilla spectator, which TFAR switches the same way.

	Params: [on]
*/
params ["_on"];
PTF_Lives_spectating = _on;
if (_on) then {["out", 0] call PTF_Lives_fnc_notify};
if (!isNil "ace_spectator_fnc_setSpectator") exitWith {
	[_on, _on, false] call ace_spectator_fnc_setSpectator;
};
if (_on) then {
	["Initialize", [player, [], true]] call BIS_fnc_EGSpectator;
} else {
	["Terminate"] call BIS_fnc_EGSpectator;
};
