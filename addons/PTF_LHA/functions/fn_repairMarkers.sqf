/*
 * Player's machine: make the LHA's hangar an ACE repair facility.
 *
 * ACE counts a player as in a repair facility when an object marked
 * ACE_isRepairFacility is within 7.5 m, or overhead. Its overhead test starts at the
 * player's height plus their eye height above sea level, which on a ship at sea is
 * already above the flight deck, so marking the ship's parts does nothing. Instead,
 * small invisible markers go on the hangar floors, one under each of Peral's hangar
 * ceiling lights, set a metre into the floor so players on the flight deck above are
 * out of reach. ACE runs this check on the repairing player's machine, so the
 * markers are local: no network traffic.
 *
 * Arguments:
 * 0: The ship <OBJECT>
 */
params ["_ship"];

private _t = time;
waitUntil {count (_ship getVariable ["bis_carrierparts", []]) >= 8 || {time - _t > 60} || {isNull _ship}};
if (isNull _ship) exitWith {};

private _cfg = configFile >> "PTF_LHA_Deck";
private _drop = getNumber (_cfg >> "repairMarkerDepth");
private _markers = [];
{
	private _part = _x select 0;
	{
		{
			_x params ["_class", "_prefix", "_first", "_last"];
			if (typeOf _part == _class) then {
				for "_i" from _first to _last do {
					private _light = _part selectionPosition format ["%1%2", _prefix, [str _i, "0" + str _i] select (_i < 10)];
					if (_light isNotEqualTo [0, 0, 0]) then {
						private _from = _part modelToWorldWorld _light;
						private _hit = (lineIntersectsSurfaces [_from vectorAdd [0, 0, -0.3], _from vectorAdd [0, 0, -12], objNull, objNull, true, 1]) param [0, []];
						if (_hit isNotEqualTo []) then {
							private _marker = "Land_ClutterCutter_small_F" createVehicleLocal [0, 0, 0];
							_marker attachTo [_part, (_part worldToModel ASLToAGL (_hit select 0)) vectorAdd [0, 0, _drop * -1]];
							_marker setVariable ["ACE_isRepairFacility", true];
							_markers pushBack _marker;
						};
					};
				};
			};
		} forEach getArray (configFile >> "CfgVehicles" >> "Peral_LHA" >> _x);
	} forEach getArray (_cfg >> "repairLights");
} forEach (_ship getVariable ["bis_carrierparts", []]);

_ship setVariable ["PTF_LHA_repairMarkers", _markers];
_ship addEventHandler ["Deleted", {
	params ["_ship"];
	{deleteVehicle _x} forEach (_ship getVariable ["PTF_LHA_repairMarkers", []]);
}];
