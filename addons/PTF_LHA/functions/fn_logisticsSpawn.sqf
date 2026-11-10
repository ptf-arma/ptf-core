/*
 * Server: spawn a crate or support vehicle from the ship's logistics menu
 * (PTF_LHA_Logistics, config.cpp) on the first free spot of its area.
 *
 * Only classes listed in a menu can be spawned, and only while the ship's spawners
 * are allowed: Peral's "Disable Spawners" attribute and spawner whitelist module
 * apply here as they do to his own spawners. A spot is free when nothing loose is
 * on it: vehicles, crates, props or people. The ship's own fixtures are attached
 * to it and don't count.
 *
 * Arguments:
 * 0: The ship <OBJECT>
 * 1: Class to spawn <STRING>
 *
 * Return Value:
 * The new object, or objNull <OBJECT>
 */
params [["_ship", objNull, [objNull]], ["_class", "", [""]]];

if (!isServer || {isNull _ship}) exitWith {objNull};

private _caller = [remoteExecutedOwner, clientOwner] select (remoteExecutedOwner == 0);
private _tell = {
	params ["_text"];
	if (_caller == clientOwner) then {systemChat _text} else {[_text] remoteExecCall ["systemChat", _caller]};
};

private _cfg = configFile >> "PTF_LHA_Logistics";
private _menu = ("_class in getArray (_x >> 'classes')" configClasses (_cfg >> "Menus")) param [0, configNull];
if (isNull _menu || {!isClass (configFile >> "CfgVehicles" >> _class)}) exitWith {objNull};

private _parts = (_ship getVariable ["bis_carrierparts", []]) apply {_x select 0};
private _area = _cfg >> "Areas" >> getText (_menu >> "area");
private _onPart = (_parts select {typeOf _x == getText (_area >> "part")}) param [0, objNull];
if (isNull _onPart) exitWith {objNull};

// Peral's spawner switches, kept on every part of the ship.
if (_onPart getVariable ["LHA_DisableSpawners", false]) exitWith {
	["The ship's spawners are switched off."] call _tell;
	objNull
};
private _allowed = _onPart getVariable ["LHA_SpawnerWhiteList", nil];
private _who = if (_caller == clientOwner) then {player} else {(allPlayers select {owner _x == _caller}) param [0, objNull]};
if (!isNil "_allowed" && {!(_who in _allowed)}) exitWith {
	["You are not on this ship's spawner list."] call _tell;
	objNull
};

// Two requests for the same area in the same moment would both find it free.
private _busyVar = "PTF_LHA_logisticsBusy_" + configName _area;
if (_ship getVariable [_busyVar, false]) exitWith {objNull};
_ship setVariable [_busyVar, true];

private _clear = getNumber (_area >> "clear");
private _fixed = _parts + [_ship];
// Free: nothing loose reaching within _clear metres across (a big neighbour like the
// 15 m deck crane counts by its size, not its centre) and reaching into the 4 m above
// the floor, so a spot in the hangar isn't blocked by an aircraft on the flight deck
// above it. Heights come from each object's own box: a tall object's centre can be
// metres above the floor it stands on.
private _spot = getArray (_area >> "spots") findIf {
	private _at = _onPart modelToWorldWorld (_x select [0, 3]);
	(nearestObjects [ASLToAGL _at, [], _clear + 10]) findIf {
		private _box = boundingBoxReal _x;
		isNull attachedTo _x && {!(_x in _fixed)} && {typeOf _x != ""} && {!(_x isKindOf "Logic")} && {!isObjectHidden _x}
			&& {((_x modelToWorldWorld [0, 0, (_box select 0) select 2]) select 2) < (_at select 2) + 4}
			&& {((_x modelToWorldWorld [0, 0, (_box select 1) select 2]) select 2) > (_at select 2) - 0.5}
			&& {(getPosASL _x) distance2D _at < _clear + ((_box select 2) / 2)}
	} < 0
};
if (_spot < 0) exitWith {
	_ship setVariable [_busyVar, false];
	[format ["No free spot %1. Move something out of the way first.", getText (_area >> "displayName")]] call _tell;
	objNull
};
(getArray (_area >> "spots") select _spot) params ["_x0", "_y0", "_z0", "_dir"];

private _object = createVehicle [_class, [0, 0, 1000], [], 0, "CAN_COLLIDE"];
_object allowDamage false;
// On the floor below the spot: rays find the hangar decks. Where they find nothing
// the spot's own height is the floor.
private _top = _onPart modelToWorldWorld [_x0, _y0, _z0 + 1.5];
private _hit = (lineIntersectsSurfaces [_top, _top vectorAdd [0, 0, -3], _object, objNull, true, 1, "GEOM", "VIEW"]) param [0, []];
private _floor = if (_hit isEqualTo []) then {_onPart modelToWorldWorld [_x0, _y0, _z0]} else {_hit select 0};
// setPosASL places a vehicle by its bottom but a crate by its centre, so put it at the
// floor, see where its bottom ended up, and lift it by the difference.
_object setDir ((getDir _onPart) + _dir);
_object setPosASL _floor;
private _bottom = (_object modelToWorldWorld [0, 0, ((boundingBoxReal _object) select 0) select 2]) select 2;
_object setPosASL (_floor vectorAdd [0, 0, (_floor select 2) - _bottom + 0.1]);
_object setVelocity [0, 0, 0];

{_x addCuratorEditableObjects [[_object], true]} forEach allCurators;
_ship setVariable [_busyVar, false];
private _label = getText (_cfg >> "Labels" >> _class);
if (_label == "") then {_label = getText (configOf _object >> "displayName")};
[format ["%1 is ready %2.", _label, getText (_area >> "displayName")]] call _tell;

// Let it settle before it can take damage.
[_object] spawn {
	params ["_object"];
	sleep 5;
	if (!isNull _object) then {_object allowDamage true};
};
_object
