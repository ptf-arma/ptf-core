/*
 * Author: Paramarine Task Force
 * Keeps a G/ATOR's radar running exactly while it should be: array up, antenna turning,
 * generator running, antenna not wrecked (HitRadar). Vehicle sensors only work with crew, and
 * this model has no crew seats, so the radar is a hidden PTF_GATOR_Sensor (the vanilla
 * AN/MPQ-105, retuned to 10 km) attached to the turntable and crewed with its UAV AI while
 * the radar is on, and deleted when it stops. Its contacts go out on the data link. A wrecked
 * antenna also stops the turning. While it transmits, enemy passive radar and anti-radiation
 * missiles can find it (the vanilla sensor is a real emitter); the crew can go silent
 * (PTF_GATOR_emcon). Also lets enemy AI hear the generator (PTF_GATOR_fnc_hearGenerator), lists
 * it for counter-battery while it transmits (PTF_GATOR_cbRadars, PTF_GATOR_fnc_cbFired) and
 * keeps it on the network or off it by its SATCOM antenna (PTF_GATOR_fnc_satcom); jammed, it is
 * off the network and the data link. Its air picture adds what the vanilla radar can't see:
 * small drones within UAS_RANGE and missiles in flight within MISSILE_RANGE.
 * Runs on the server once a second (from the XEH init).
 *
 * Arguments:
 * 0: G/ATOR <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_radar] call PTF_GATOR_fnc_radarLoop
 */
#include "..\script_gator.hpp"
#define HEAR_INTERVAL 10

params [["_radar", objNull, [objNull]]];

if (!isServer || {isNull _radar}) exitWith {};

private _all = (missionNamespace getVariable ["PTF_GATOR_all", []]) select {!isNull _x};
_all pushBackUnique _radar;
missionNamespace setVariable ["PTF_GATOR_all", _all];

[{
	params ["_args", "_handle"];
	_args params ["_radar", "_holder"];
	private _sensor = _holder select 0;
	private _remove = {
		if (!isNull _sensor) then {
			deleteVehicleCrew _sensor;
			deleteVehicle _sensor;
		};
		_holder set [0, objNull];
		if (!isNull _radar) then {_radar setVariable ["PTF_GATOR_sensor", objNull, true]};
	};
	// Counter-battery: the transmitting G/ATORs every gun checks its rounds against
	// (PTF_GATOR_fnc_cbFired, cbWatch), sent out only when it changes:
	// [G/ATOR, where (ASL), reach m, its sector [from, to] or [] all round, staring at one track]
	private _listen = {
		params ["_on"];
		private _list = missionNamespace getVariable ["PTF_GATOR_cbRadars", []];
		private _i = _list findIf {(_x select 0) isEqualTo _radar};
		if (!_on && {_i < 0}) exitWith {};
		private _entry = [_radar, getPosASL _radar, round (_radar getVariable ["PTF_GATOR_reach", CB_DETECT]),
			[[], _radar getVariable ["PTF_GATOR_sector", []]] select (_radar getVariable ["PTF_GATOR_mode", "full"] == "sector"),
			!isNil {_radar getVariable "PTF_GATOR_dwell"}];
		if (_on && {_i >= 0} && {(_list select _i) isEqualTo _entry}) exitWith {};
		_list = +_list;
		if (_on) then {
			if (_i >= 0) then {_list set [_i, _entry]} else {_list pushBack _entry};
		} else {
			_list deleteAt _i;
		};
		missionNamespace setVariable ["PTF_GATOR_cbRadars", _list select {!isNull (_x select 0)}, true];
	};
	if (isNull _radar) exitWith {
		call _remove;
		missionNamespace setVariable ["PTF_GATOR_cbRadars", (missionNamespace getVariable ["PTF_GATOR_cbRadars", []]) select {!isNull (_x select 0)}, true];
		call PTF_GATOR_fnc_cbPublish;
		[_handle] call CBA_fnc_removePerFrameHandler;
	};

	// Standing on its own it belongs to the server, whoever last had it (a Zeus who moved it,
	// say): the server moves its legs and array and levels it. Towed, slung under a
	// helicopter, carried as cargo or attached to anything but its own leveling anchor, it goes
	// with whatever has it.
	if (isMultiplayer && {!local _radar} && {isNull (_radar getVariable ["PTF_GATOR_tower", objNull])}
		&& {isNull ropeAttachedTo _radar} && {isNull isVehicleCargo _radar}
		&& {isNull attachedTo _radar || {(attachedTo _radar) isEqualTo (_radar getVariable ["PTF_GATOR_anchor", objNull])}}) then {
		_radar setOwner 2;
	};

	// On the network or not: its SATCOM antenna, set down clear of it, cable in.
	[_radar, "update"] call PTF_GATOR_fnc_satcom;
	// Its operator computer: cabled in, or it goes back to automatic control.
	[_radar, "update"] call PTF_GATOR_fnc_computer;

	if (_radar getHitPointDamage "HitRadar" >= 0.9 && {_radar getVariable ["PTF_GATOR_spinning", false]}) then {
		_radar setVariable ["PTF_GATOR_spinning", false, true];
		_radar animateSource ["ptf_gator_spin", ceil (_radar animationSourcePhase "ptf_gator_spin")];
	};

	// Enemy AI near enough may hear the generator, every HEAR_INTERVAL seconds.
	if (alive _radar && {[_radar] call PTF_GATOR_fnc_powerState != "off"} && {CBA_missionTime >= _radar getVariable ["PTF_GATOR_heardAt", 0]}) then {
		_radar setVariable ["PTF_GATOR_heardAt", CBA_missionTime + HEAR_INTERVAL];
		[_radar] call PTF_GATOR_fnc_hearGenerator;
	};

	// It transmits while the antenna turns (or sweeps a sector, or stares at one track) on power with the array up,
	// unless its crew has it silent (emissions control): then it detects nothing and gives
	// nothing away.
	private _sector = _radar getVariable ["PTF_GATOR_mode", "full"] == "sector";
	private _active = alive _radar && {_sector || {_radar getVariable ["PTF_GATOR_spinning", false]} || {!isNil {_radar getVariable "PTF_GATOR_dwell"}}} && {!(_radar getVariable ["PTF_GATOR_emcon", false])}
		&& {[_radar] call PTF_GATOR_fnc_powerState == "on"} && {_radar animationSourcePhase "ptf_gator_deploy" > 0.999} && {_radar getHitPointDamage "HitRadar" < 0.9};
	// A sweep stops itself when the power goes or the array comes down; back up, it carries on.
	if (_active && {_sector} && {!(_radar getVariable ["PTF_GATOR_sweeping", false])}) then {[_radar] call PTF_GATOR_fnc_sweep};
	// The operator's world: the enemy's fix on it, CROWS jamming.
	private _jam = [_radar, _active] call PTF_GATOR_fnc_operatorTick;
	// Its sensor: shorter while heavily jammed.
	private _class = ["PTF_GATOR_Sensor", "PTF_GATOR_SensorJammed"] select (_jam >= 0.5);
	if (!isNull _sensor && {typeOf _sensor != _class}) then {
		call _remove;
		_sensor = objNull;
	};
	if (_active && {isNull _sensor}) then {
		_sensor = createVehicle [_class, getPosATL _radar, [], 0, "CAN_COLLIDE"];
		_sensor allowDamage false;
		[_sensor, true] remoteExec ["hideObjectGlobal", 2];
		_sensor attachTo [_radar, [0, 0, 0], "hum_source", true];
		createVehicleCrew _sensor;
		_sensor lock 2;
		[_sensor, 1] remoteExec ["setVehicleRadar", _sensor];
		_holder set [0, _sensor];
		_radar setVariable ["PTF_GATOR_sensor", _sensor, true];
	};
	if (!_active && {!isNull _sensor}) then _remove;
	// Jammed, it can't put what it sees on the network: not on the data link either.
	if (!isNull _sensor && {(_jam == 0) isNotEqualTo (vehicleReportRemoteTargets _sensor)}) then {_sensor setVehicleReportRemoteTargets (_jam == 0)};
	[_active] call _listen;

	// Air tracks: what its radar sees, every other second, for the network's picture
	// (PTF_GATOR_fnc_cbPublish sends it on while it is cabled to a SATCOM antenna). Sweeping a
	// sector, only those in it.
	(_radar getVariable ["PTF_GATOR_sector", [0, 360]]) params ["_from", "_to"];
	private _span = [360, ((_to - _from) + 360) % 360] select _sector;
	private _air = [];
	// missiles that have hit or gone, off the list
	private _missiles = missionNamespace getVariable ["PTF_GATOR_missiles", []];
	if (_missiles findIf {isNull (_x select 0)} >= 0) then {missionNamespace setVariable ["PTF_GATOR_missiles", _missiles select {!isNull (_x select 0)}]};
	if (_active && {!isNull _sensor}) then {
		private _radarAt = getPosASL _radar;
		{
			_x params ["_target", "_type", "_relationship", ["_sources", []]];
			// what its own radar sees, not what the data link reports (friendly aircraft broadcast
			// their own positions on it; a radar's picture is what it finds)
			if (_type == "air" && {"activeradar" in _sources} && {alive _target} && {(((_radar getDir _target) - _from + 360) % 360) <= _span}) then {
				private _at = getPosASL _target;
				// for its MIL-STD symbol: a drone, a helicopter (rotary wing) or a plane
				private _kind = ["plane", "air"] select (_target isKindOf "Helicopter");
				if (unitIsUAV _target) then {_kind = "uav"};
				_air pushBack [netId _target, getText (configOf _target >> "displayName"), _relationship, [_at select 0, _at select 1],
					round ((getPosATL _target) select 2), round abs speed _target, round getDir _target, _kind];
			};
		} forEach getSensorTargets _sensor;

		// What the game's radar can't see. Each must be in its sector and above the ridge line
		// (terrain only, from the array).
		private _eye = _radarAt vectorAdd [0, 0, CB_EYE];
		private _inView = {
			params ["_pos"];
			(((_radar getDir _pos) - _from + 360) % 360) <= _span && {!terrainIntersectASL [_eye, _pos]}
		};
		// Small drones (an FPV, a quadcopter): too small for it, so looked for here, closer in.
		// An unidentified small track until its operator identifies it.
		{
			private _id = netId _x;
			if (alive _x && {unitIsUAV _x} && {((getPosATL _x) select 2) > 1} && {_air findIf {(_x select 0) isEqualTo _id} < 0}
				&& {[getPosASL _x] call _inView}) then {
				private _at = getPosASL _x;
				_air pushBack [_id, "Small UAS", "unknown", [_at select 0, _at select 1], round ((getPosATL _x) select 2), round abs speed _x, round getDir _x, "uav"];
			};
		} forEach (_radar nearEntities [["Air"], UAS_RANGE]);
		// Missiles in flight (PTF_GATOR_fnc_cbFired lists them).
		{
			_x params ["_missile", "_id"];
			private _at = getPosASL _missile;
			if (_at distance _radarAt < MISSILE_RANGE && {((getPosATL _missile) select 2) > 3} && {[_at] call _inView}) then {
				_air pushBack [_id, "Missile", "unknown", [_at select 0, _at select 1], round ((getPosATL _missile) select 2),
					round (vectorMagnitude velocity _missile * 3.6), round getDir _missile, "missile"];
			};
		} forEach (missionNamespace getVariable ["PTF_GATOR_missiles", []]);
	};
	if (_air isNotEqualTo (_radar getVariable ["PTF_GATOR_air", []]) && {_air isEqualTo [] || {diag_tickTime >= _radar getVariable ["PTF_GATOR_airAt", 0]}}) then {
		// public: the operator console reads its own G/ATOR's, on the network or not
		_radar setVariable ["PTF_GATOR_air", _air, true];
		_radar setVariable ["PTF_GATOR_airAt", diag_tickTime + 1.9];
		call PTF_GATOR_fnc_cbPublish;
	};
}, 1, [_radar, [objNull]]] call CBA_fnc_addPerFrameHandler;
