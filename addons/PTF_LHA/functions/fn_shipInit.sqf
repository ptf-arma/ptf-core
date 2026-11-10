/*
 * Init handler on Peral_LHA, run beside Peral's own (CfgVehicles.hpp), on every
 * machine the ship exists on.
 *
 * Server: paints PTF's hull number, then sets up the deck services. Peral's init
 * picks a random digit unless a number is already set, and it is spawned, so it
 * checks after this has run. A "Ship Number" set in Eden is applied after init and
 * replaces this one.
 * Players: put the 1MC controls and the logistics console on the ship, and make the
 * hangar a repair facility.
 *
 * Arguments:
 * 0: The ship <OBJECT>
 */
params ["_ship"];

if (isServer) then {
	private _number = getText (configOf _ship >> "PTF_LHA_hullNumber");
	if (_number isNotEqualTo "") then {
		[_ship, _number] call LHA_fnc_lha_number;
	};
};

// Nothing else belongs in an Eden scene.
if (is3DEN) exitWith {};

if (isServer) then {
	[_ship] spawn PTF_LHA_fnc_deckServices;
};
if (hasInterface) then {
	[_ship] spawn PTF_LHA_fnc_addActions;
	[_ship] spawn PTF_LHA_fnc_repairMarkers;
	[_ship] spawn PTF_LHA_fnc_logisticsActions;
};
