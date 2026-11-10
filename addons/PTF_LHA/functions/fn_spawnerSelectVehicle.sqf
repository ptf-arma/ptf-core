/*
 * Replaces LHA_fnc_lha_spawner_selectVehicle (see CfgFunctions in config.cpp). The
 * LHA's aircraft and amphibious spawner dialogs call it when a vehicle is picked.
 *
 * Peral's script makes room by deleting a listed vehicle already on the chosen spot,
 * but:
 * - it doesn't look inside it, so a pilot running up a helicopter could lose it to
 *   someone at the spawner. This refuses while anyone alive is aboard.
 * - it counts everything within reach, including objects attached to that vehicle.
 *   ACE hangs a fast-rope anchor bar on every UH-1Y, so a parked UH-1Y was never
 *   replaced ("Something is in the way."). This removes the empty vehicle and what
 *   is attached to it, then lets Peral's script spawn on the clear spot.
 *
 * Arguments (Peral's):
 * 0: onLBSelChanged parameters <ARRAY>
 * 1: Spawn point prefix, "ac" or "av" <STRING>
 * 2: Name of the vehicle list in Peral_LHA's config <STRING>
 * 3: Radius that must be clear <NUMBER>
 */
params [["_eventParams", []], ["_spawnPointName", ""], ["_vehVarClasses", ""], ["_spawnRadius", 10]];
_eventParams params ["_control", "_lbCurSel"];

// Peral's way of finding the spot.
private _ship = player getVariable ["Peral_LHA_Obj", objNull];
private _point = format ["%1_spawnpoint_%2", _spawnPointName, _control lbValue _lbCurSel];
private _local = _ship selectionPosition _point;

private _near = [];
if (!isNull _ship && {_local isNotEqualTo [0, 0, 0]}) then {
	_near = ((_ship modelToWorld _local) nearObjects ["AllVehicles", _spawnRadius]) select {
		alive _x && {isNull attachedTo _x}
	};
};

private _manned = _near select {!(_x isKindOf "CAManBase") && {(crew _x) findIf {alive _x} >= 0}};
if (_manned isNotEqualTo []) exitWith {
	systemChat format ["Someone is aboard the %1 on that spot. They need to get out first.",
		getText (configOf (_manned select 0) >> "displayName")];
};

// One empty vehicle from the spawner's own list: clear it, attachments included,
// the way Peral's script would have.
if (count _near == 1) then {
	private _old = _near select 0;
	private _listed = getArray (configFile >> "CfgVehicles" >> "Peral_LHA" >> _vehVarClasses);
	if (typeOf _old in _listed) then {
		{deleteVehicle _x} forEach attachedObjects _old;
		deleteVehicle _old;
		private _t = diag_tickTime;
		waitUntil {isNull _old || {diag_tickTime - _t > 5}};
	};
};

_this call PTF_LHA_fnc_peralSpawnerSelectVehicle;
