/*
 * Server: flight deck and hangar services on one LHA (positions in PTF_LHA_Deck,
 * config.cpp).
 *
 * - Invisible helipads on Peral's six deck spots, for AI helicopters to land on.
 * - At each of Peral's three deck refuel points (the modelled hose reels): an ACE
 *   fuel hose with unlimited fuel, and a vehicle ammo box that ACE rearms from.
 *
 * Everything is removed again if the ship is deleted.
 *
 * Arguments:
 * 0: The ship <OBJECT>
 */
params ["_ship"];

private _t = time;
waitUntil {count (_ship getVariable ["bis_carrierparts", []]) >= 8 || {time - _t > 60} || {isNull _ship}};
if (isNull _ship) exitWith {};
// Peral's turrets and the carrier code are still placing things on the first frames.
sleep 1;

private _parts = (_ship getVariable ["bis_carrierparts", []]) apply {_x select 0};
private _part = {
	params ["_class"];
	(_parts select {typeOf _x == _class}) param [0, objNull]
};
private _cfg = configFile >> "PTF_LHA_Deck";
private _made = [];

// Put _object on the deck of _onPart at _local (that part's model space): on the
// surface below that point, or at flight deck height where a ray finds none (near
// the deck edge some of the deck is walkable surface only, which rays don't see).
private _deckZ = getNumber (_cfg >> "deckHeight");
private _place = {
	params ["_object", "_onPart", "_local"];
	private _top = _onPart modelToWorldWorld (_local vectorAdd [0, 0, 2]);
	private _hit = (lineIntersectsSurfaces [_top, _top vectorAdd [0, 0, -5], _object, objNull, true, 1]) param [0, []];
	private _deck = if (_hit isEqualTo []) then {[_local select 0, _local select 1, _deckZ]} else {_onPart worldToModel ASLToAGL (_hit select 0)};
	private _lift = (((boundingBoxReal _object) select 0) select 2) * -1;
	_object attachTo [_onPart, _deck vectorAdd [0, 0, _lift]];
	_object setDir 0;
};

// Fixed props: attached, so no physics; no damage; nobody drags them off or loads them.
private _fixProp = {
	params ["_object"];
	_object allowDamage false;
	if (!isNil "ace_dragging_fnc_setDraggable") then {
		[_object, false, [0, 0, 0], 0, false, true] call ace_dragging_fnc_setDraggable;
		[_object, false, [0, 0, 0], 0, false, true] call ace_dragging_fnc_setCarryable;
	};
	if (!isNil "ace_cargo_fnc_setSize") then {[_object, -1] call ace_cargo_fnc_setSize};
};

{
	_x params ["_class", "_local"];
	private _onPart = [_class] call _part;
	if (!isNull _onPart) then {
		private _pad = createVehicle ["Land_HelipadEmpty_F", [0, 0, 0], [], 0, "CAN_COLLIDE"];
		_pad attachTo [_onPart, _local];
		_made pushBack _pad;
	};
} forEach getArray (_cfg >> "helipads");

getArray (_cfg >> "fuelOffset") params ["_fuelIn", "_fuelAft"];
getArray (_cfg >> "ammoOffset") params ["_ammoIn", "_ammoAft"];
{
	_x params ["_class", "_point"];
	private _onPart = [_class] call _part;
	private _reel = _onPart selectionPosition _point;
	if (!isNull _onPart && {_reel isNotEqualTo [0, 0, 0]}) then {
		// Inboard is towards the centre line, whichever side the reel is on.
		private _inboard = [1, -1] select ((_reel select 0) > 0);

		private _hose = createVehicle [getText (_cfg >> "fuelProp"), [0, 0, 0], [], 0, "CAN_COLLIDE"];
		[_hose, _onPart, _reel vectorAdd [_inboard * _fuelIn, _fuelAft, 0]] call _place;
		[_hose] call _fixProp;
		if (!isNil "ace_refuel_fnc_makeSource") then {
			// -10: unlimited (ACE's REFUEL_INFINITE_FUEL).
			[_hose, -10] call ace_refuel_fnc_makeSource;
		};
		_made pushBack _hose;

		private _ammo = createVehicle [getText (_cfg >> "ammoProp"), [0, 0, 0], [], 0, "CAN_COLLIDE"];
		[_ammo, _onPart, _reel vectorAdd [_inboard * _ammoIn, _ammoAft, 0]] call _place;
		[_ammo] call _fixProp;
		clearItemCargoGlobal _ammo;
		clearMagazineCargoGlobal _ammo;
		clearWeaponCargoGlobal _ammo;
		clearBackpackCargoGlobal _ammo;
		if (!isNil "ace_rearm_fnc_makeSource") then {
			// Effectively unlimited when the server limits rearm supply.
			[_ammo, 1e6] call ace_rearm_fnc_makeSource;
		};
		_made pushBack _ammo;
	};
} forEach getArray (_cfg >> "fuelPoints");

_ship setVariable ["PTF_LHA_deckObjects", _made];
_ship addEventHandler ["Deleted", {
	params ["_ship"];
	{deleteVehicle _x} forEach (_ship getVariable ["PTF_LHA_deckObjects", []]);
}];
