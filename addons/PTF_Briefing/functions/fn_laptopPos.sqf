/*
	Where a ship's podium laptop is: [part, position in the part's model space].
	The part is objNull if the ship's parts don't exist (yet).
*/
params ["_ship"];
private _cfg = configFile >> "PTF_Briefing_Ships" >> typeOf _ship;
private _partClass = getText (_cfg >> "part");
private _part = (((_ship getVariable ["bis_carrierparts", []]) select {typeOf (_x select 0) == _partClass}) param [0, [objNull]]) select 0;
if (isNull _part) then {
	_part = (nearestObjects [_ship, [_partClass], 300]) param [0, objNull];
};
if (isNull _part) exitWith {[objNull, [0, 0, 0]]};

// selectionPosition returns [0,0,0] for the laptop proxy in every LOD (checked in
// game), so the measured offset from config is what's used.
[_part, getArray (_cfg >> "laptopOffset")]
