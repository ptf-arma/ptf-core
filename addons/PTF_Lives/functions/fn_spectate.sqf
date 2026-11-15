/*
	Client: in or out of spectating while out of lives.

	ACE's spectator, forced so it can't be closed. ACE also puts TFAR in its
	spectator mode (TFAR_fnc_forceSpectator): the player hears the people
	around the camera but living players can't hear them. Without ACE, the
	vanilla spectator, which TFAR switches the same way.

	The mission's respawn menu (the MenuPosition template) is a forced full-screen
	map drawn over everything, so it hid the spectator (tested 2026-11-10: the
	player saw only the menu, its own Spectate button greyed out). It is put away
	while spectating and opened again when the player may respawn.

	Params: [mode]
	  true    start spectating
	  false   stop, and give the respawn menu back if it was put away
	  "keep"  while spectating (fn_clientInit, twice a second): keep the respawn
	          menu away and ACE's screen up
*/
params ["_mode"];
private _ace = !isNil "ace_spectator_fnc_setSpectator";
private _menuUp = {missionNamespace getVariable ["BIS_RscRespawnControlsMap_shown", false]};

if (_mode isEqualTo "keep") exitWith {
	if (call _menuUp) then {
		PTF_Lives_menuAway = true;
		["close"] call BIS_fnc_showRespawnMenu;
	};
	// ACE never notices its screen being closed by something else, and then
	// can't tidy up after itself (its unit icons stay on): open it again
	if (_ace && {isNull (findDisplay 60000)} && {!isNull (findDisplay 46)} && {!(call _menuUp)}) then {
		[true] call ace_spectator_fnc_ui;
	};
};

PTF_Lives_spectating = _mode;
if (_mode) then {
	PTF_Lives_menuAway = false;
	["out", 0] call PTF_Lives_fnc_notify;
	if (call _menuUp) then {
		PTF_Lives_menuAway = true;
		["close"] call BIS_fnc_showRespawnMenu;
	};
	if (_ace) then {
		[true, true, false] call ace_spectator_fnc_setSpectator;
	} else {
		["Initialize", [player, [], true]] call BIS_fnc_EGSpectator;
	};
} else {
	if (_ace) then {
		// ACE removes its icons only if its own screen is still up, so make sure it is
		if (isNull (findDisplay 60000) && {!isNull (findDisplay 46)}) then {[true] call ace_spectator_fnc_ui};
		[false, false, false] call ace_spectator_fnc_setSpectator;
	} else {
		["Terminate"] call BIS_fnc_EGSpectator;
	};
	if (missionNamespace getVariable ["PTF_Lives_menuAway", false]) then {
		PTF_Lives_menuAway = false;
		// once ACE's screen is gone: closing it closes the map too
		[] spawn {
			private _t = time + 5;
			waitUntil {sleep 0.1; isNull (findDisplay 60000) || {time > _t}};
			sleep 0.5;
			if (!alive player) then {["open"] call BIS_fnc_showRespawnMenu};
		};
	};
};
