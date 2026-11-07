/*
	Server: may this player run this ship's briefing controls? They must be at
	the podium laptop, or be a Zeus.
*/
params ["_ship", "_caller"];
if (!isMultiplayer) exitWith {true};
if (isNull _caller) exitWith {false};
if (!isNull getAssignedCuratorLogic _caller) exitWith {true};
([_ship] call PTF_Briefing_fnc_laptopPos) params ["_part", "_local"];
if (isNull _part) exitWith {false};
private _range = getNumber (configFile >> "PTF_Briefing_Ships" >> typeOf _ship >> "controlRange");
// ASL on both sides: at sea, AGL heights follow the waves.
((getPosASL _caller) distance (_part modelToWorldWorld _local)) <= _range + 2
