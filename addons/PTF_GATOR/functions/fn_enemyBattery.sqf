/*
 * Author: Paramarine Task Force
 * An enemy mortar team that shoots and scoots: it sets up somewhere 1.5 to 3.5 km from where it
 * aims, fires its rounds, packs up and is gone a quarter of a minute after its last round, before
 * counter-fire can reach it. Harassing, it comes back every few minutes from somewhere else.
 * For the G/ATOR's crew to trace (its tracks show where it was, not where it is). Used by the
 * enemy's hunt for a G/ATOR they have a fix on (PTF_GATOR_fnc_operatorTick) and by Zeus
 * (PTF_GATOR_fnc_initZeus). Runs on the server (called anywhere). Its men and mortar are Zeus's to
 * edit, and to kill.
 *
 * Arguments:
 * 0: Where it aims (positionAGL), or "stop": every battery packs up and goes <ARRAY, STRING>
 * 1: Rounds a volley (default: 4) <NUMBER>
 * 2: Minutes between volleys, harassing (default: 0: one volley) <NUMBER>
 * 3: The side it fires on: the battery is an enemy of theirs (default: west) <SIDE>
 *
 * Return Value:
 * None
 *
 * Example:
 * [getPos player, 6, 4] call PTF_GATOR_fnc_enemyBattery
 */
params [["_aim", [], [[], ""]], ["_rounds", 4, [0]], ["_every", 0, [0]], ["_target", west, [west]]];
if (!isServer) exitWith {_this remoteExecCall ["PTF_GATOR_fnc_enemyBattery", 2]};

if (_aim isEqualTo "stop") exitWith {
	missionNamespace setVariable ["PTF_GATOR_batteryGen", (missionNamespace getVariable ["PTF_GATOR_batteryGen", 0]) + 1];
	{
		{deleteVehicle _x} forEach crew _x;
		deleteVehicle _x;
	} forEach (missionNamespace getVariable ["PTF_GATOR_batteryGuns", []]);
	missionNamespace setVariable ["PTF_GATOR_batteryGuns", []];
};
if (count _aim < 2) exitWith {};

// Whose: the first side hostile to the one it fires on.
private _side = [east, independent, west] select {_x != _target && {_x getFriend _target < 0.6}} param [0, east];
private _class = createHashMapFromArray [[east, "O_Mortar_01_F"], [independent, "I_Mortar_01_F"], [west, "B_Mortar_01_F"]] get _side;

[_aim, _rounds max 1, _every, _side, _class, missionNamespace getVariable ["PTF_GATOR_batteryGen", 0]] spawn {
	params ["_aim", "_rounds", "_every", "_side", "_class", "_gen"];
	private _stopped = {_gen != (missionNamespace getVariable ["PTF_GATOR_batteryGen", 0])};
	while {true} do {
		private _started = time;
		// somewhere flat on land, out of the way
		private _spot = [_aim, 1500, 3500, 4, 0, 0.25, 0, [], [[], []]] call BIS_fnc_findSafePos;
		if (_spot isEqualTo [] || {_spot distance2D _aim < 1400}) exitWith {
			diag_log format ["[PTF_GATOR] enemy battery: no place to set up near %1", _aim];
		};
		private _gun = createVehicle [_class, _spot, [], 0, "NONE"];
		_gun setDir (_spot getDir _aim);
		private _group = createGroup [_side, true];
		createVehicleCrew _gun;
		(crew _gun) joinSilent _group;
		_group setBehaviourStrong "COMBAT";
		private _guns = missionNamespace getVariable ["PTF_GATOR_batteryGuns", []];
		_guns pushBack _gun;
		missionNamespace setVariable ["PTF_GATOR_batteryGuns", _guns];
		{_x addCuratorEditableObjects [[_gun] + crew _gun, true]} forEach allCurators;
		diag_log format ["[PTF_GATOR] enemy battery: %1 set up at %2, %3 m from %4", _class, mapGridPosition _spot, round (_spot distance2D _aim), mapGridPosition _aim];

		sleep 8;
		if (call _stopped) exitWith {};
		private _magazine = (getArtilleryAmmo [_gun]) param [0, ""];
		private _scatter = _aim getPos [random 40, random 360];
		if (alive gunner _gun && {_magazine != ""} && {_scatter inRangeOfArtillery [[_gun], _magazine]}) then {
			gunner _gun doArtilleryFire [_scatter, _magazine, _rounds];
			// until its rounds are gone (or a minute and a half)
			private _t0 = time;
			waitUntil {
				sleep 1;
				!alive gunner _gun || {time - _t0 > 90} || {call _stopped}
					|| {unitReady gunner _gun && {time - _t0 > 6 + 3 * _rounds}}
			};
		};
		// scoot: packed up and gone before counter-fire lands
		sleep 15;
		{deleteVehicle _x} forEach crew _gun;
		deleteVehicle _gun;
		missionNamespace setVariable ["PTF_GATOR_batteryGuns", (missionNamespace getVariable ["PTF_GATOR_batteryGuns", []]) - [_gun, objNull]];
		if (_every <= 0 || {call _stopped}) exitWith {};
		sleep ((_every * 60 - (time - _started)) max 20);
		if (call _stopped) exitWith {};
	};
};
