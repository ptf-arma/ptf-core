/*
	Client: hold this player dead, spectating, while Lives is on and they have
	none left, and let them respawn the moment they have one again (an admin
	gave one, or switched Lives off).

	The hold is the engine's own respawn timer, set out of reach, as the
	vanilla Tickets respawn template does it, so the mission's respawn (its
	positions, menu and loadouts) runs normally once it is released.

	The server counts the death, which takes a moment to arrive. A player on
	their last life (1 or fewer) is held the instant they die, so a short
	respawn delay can't slip past; once the server's count arrives (their
	charges go up), or after 3 s, the count decides.
*/
PTF_Lives_holding = false;     // respawn timer held
PTF_Lives_spectating = false;
PTF_Lives_death = [-1, 0, false]; // [time of death, charges then, held at once]
PTF_Lives_delay = getMissionConfigValue ["respawnDelay", 0];

addMissionEventHandler ["EntityKilled", {
	params ["_unit"];
	if (_unit isNotEqualTo player) exitWith {};
	private _mine = call PTF_Lives_fnc_mine;
	private _hold = (missionNamespace getVariable ["PTF_Lives_on", false]) && {(_mine param [2, 99]) <= 1};
	PTF_Lives_death = [time, _mine param [4, 0], _hold];
	if (_hold) then {
		setPlayerRespawnTime 1e10;
		PTF_Lives_holding = true;
	};
}];

// A fresh body: the server checks it has a life behind it (fn_hello).
addMissionEventHandler ["EntityRespawned", {
	params ["_new"];
	if (_new isEqualTo player) then {[] remoteExecCall ["PTF_Lives_fnc_hello", 2]};
}];

[] spawn {
	waitUntil {sleep 0.5; !isNull player};
	[] remoteExecCall ["PTF_Lives_fnc_hello", 2];
	private _lastCharges = -1;
	while {true} do {
		sleep 0.5;
		private _on = missionNamespace getVariable ["PTF_Lives_on", false];
		private _mine = call PTF_Lives_fnc_mine;
		private _lives = _mine param [2, 1];
		private _charges = _mine param [4, 0];

		// a life used: say how many are left (none left: fn_spectate says so)
		if (_mine isNotEqualTo []) then {
			if (_lastCharges >= 0 && {_charges > _lastCharges} && {_on} && {_lives > 0}) then {["left", _lives] call PTF_Lives_fnc_notify};
			_lastCharges = _charges;
		};

		if (alive player) then {
			PTF_Lives_holding = false;
			if (PTF_Lives_spectating) then {[false] call PTF_Lives_fnc_spectate};
		} else {
			PTF_Lives_death params ["_at", "_chargesThen", "_heldAtOnce"];
			private _settled = !_on || {_lives <= 0} || {_charges > _chargesThen} || {time - _at > 3};
			private _hold = _on && {[_heldAtOnce, _lives <= 0] select _settled};
			if (_hold) then {
				if (!PTF_Lives_holding) then {
					setPlayerRespawnTime 1e10;
					PTF_Lives_holding = true;
				};
				if (_settled && {!PTF_Lives_spectating}) then {[true] call PTF_Lives_fnc_spectate};
			} else {
				if (PTF_Lives_spectating) then {[false] call PTF_Lives_fnc_spectate};
				if (PTF_Lives_holding) then {
					PTF_Lives_holding = false;
					// what is left of the mission's delay, at least a second
					setPlayerRespawnTime ((PTF_Lives_delay - (time - _at)) max 1);
				};
			};
		};
	};
};
