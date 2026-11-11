/*
 * Author: Paramarine Task Force
 * External fuel pods for the PTF MQ-9s. Replaces the USAF mod's USAF_EXT_FUEL
 * scripts, which the PTF MQ-9 classes no longer start (see cfgMQ9.hpp).
 *
 * Why the USAF version is replaced: it drains the pods on a fixed timer (0.001
 * a second, whatever the engine burns), so two pods last ~7.5 minutes; and its
 * init runs on every machine, each of which hands the aircraft's owner another
 * drain loop, so in multiplayer the pods empty N times faster. It also adds
 * nothing if the drone spawns below 90% fuel and never refills the pods.
 *
 * This version: once a second, on the machine where the aircraft is local, it
 * tops the internal tank back up from the pods by exactly what the engine
 * burned. The pods are a pool measured in internal tanks: each pod holds
 * PTF_MQ9PodFuel of a full internal tank (CBA setting). Any pylon magazine with
 * USAF_EXT_FUEL_COUNT > 0 counts as a pod.
 *  - A pod fitted (or the drone spawning) brings its fuel with it, full.
 *  - A pod removed takes its share away.
 *  - Refuelling refills the pods too: an ACE refuel nozzle connected to the
 *    drone, or internal fuel rising by anything other than this script.
 * Started on every machine by the MQ-9 init; only the owner acts, so it follows
 * the aircraft when control of the UAV moves. PTF_extFuel (global) is the pool.
 *
 * Arguments:
 * 0: MQ-9 <OBJECT>
 *
 * Return Value:
 * None
 *
 * Example:
 * [_plane] call PTF_fnc_mq9ExtFuel
 */

params [["_plane", objNull, [objNull]]];

if (isNull _plane || {is3DEN}) exitWith {};

// [was local last tick, internal fuel after last tick, last broadcast pool]
[{
	params ["_args", "_handle"];
	_args params ["_plane", "_state"];
	if (!alive _plane) exitWith {[_handle] call CBA_fnc_removePerFrameHandler};
	if (!local _plane) exitWith {_state set [0, false]};

	// Pods currently on the pylons, with ammo (i.e. not jettisoned).
	private _pods = 0;
	{
		if (
			getNumber (configFile >> "CfgMagazines" >> _x >> "USAF_EXT_FUEL_COUNT") > 0
			&& {_plane ammoOnPylon (_forEachIndex + 1) > 0}
		) then {_pods = _pods + 1};
	} forEach getPylonMagazines _plane;
	private _cap = _pods * (missionNamespace getVariable ["PTF_MQ9PodFuel", 0.5]);

	private _pool = _plane getVariable ["PTF_extFuel", _cap];
	private _oldCap = _plane getVariable ["PTF_extFuelCap", _cap];
	if (_cap > _oldCap) then {_pool = _pool + (_cap - _oldCap)};

	private _fuel = fuel _plane;
	if !(_state select 0) then {
		// Just became (or started as) the owner: nothing to compare against yet.
		_state set [0, true];
		_state set [1, _fuel];
	};

	// Refuelling refills the pods too. While the pods hold the internal tank
	// full a fuel truck has nothing to add, so an ACE nozzle connected to the
	// drone counts as well as the fuel going up by something other than us.
	if (
		!isNull (_plane getVariable ["ace_refuel_nozzle", objNull])
		|| {_fuel > (_state select 1) + 0.001}
	) then {_pool = _cap};
	_pool = (_pool min _cap) max 0;

	// Replace what the engine burned since last tick.
	if (_pool > 0 && {_fuel < 1}) then {
		private _transfer = (1 - _fuel) min _pool;
		_fuel = _fuel + _transfer;
		_pool = _pool - _transfer;
		_plane setFuel _fuel;
	};
	_state set [1, _fuel];

	// The pool only matters to whoever owns the drone next, so a coarse
	// broadcast is enough: on a 1% change, on running dry, or on a refit.
	if (_cap != _oldCap || {isNil {_plane getVariable "PTF_extFuelCap"}}) then {
		_plane setVariable ["PTF_extFuelCap", _cap, true];
	};
	if (abs (_pool - (_state select 2)) >= 0.01 || {_pool == 0 && {(_state select 2) != 0}} || {_cap != _oldCap}) then {
		_plane setVariable ["PTF_extFuel", _pool, true];
		_state set [2, _pool];
	} else {
		_plane setVariable ["PTF_extFuel", _pool];
	};
}, 1, [_plane, [false, fuel _plane, -1]]] call CBA_fnc_addPerFrameHandler;
