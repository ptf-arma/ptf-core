params ["_Heli"];

_Heli addEventHandler ["RopeAttach", { 
 params ["_Heli", "_rope", "_Object"];
private _RopesAttached = _Object getVariable ["PTF_RopesAttached", 0];
if (_RopesAttached >= 1) exitwith {};
if(isNil{[configFile >> 'CfgVehicles' >> typeof _Object ,"SlingloadingWeight"] call BIS_fnc_returnConfigEntry;}) exitwith {false};

private  _HeliCheck = (typeOf _heli splitString "_");
_HeliCheck resize 2;
_HeliCheck = _HeliCheck joinString "";

if (_HeliCheck == "PTFCH53" || _HeliCheck == "PTFMV22") then {
_Object setVariable ["PTF_ObjectMass", getmass _Object, true];
Private _selectHash = createHashMapFromArray [
["PTFCH53",0],
["PTFMV22",1]
];
if(isNil{parseSimpleArray ([configFile >> 'CfgVehicles' >> typeof _Object ,"SlingloadingWeight"] call BIS_fnc_returnConfigEntry)}) exitwith {};
Private _setmass = parseSimpleArray ([configFile >> 'CfgVehicles' >> typeof _Object ,"SlingloadingWeight"] call BIS_fnc_returnConfigEntry);
_Object setMass (_setmass select (_selectHash get _HeliCheck));
_Object setVariable ["PTF_RopesAttached", 1, true];
}
}];

_Heli addEventHandler ["RopeBreak", {
params ["_object1", "_rope", "_object2"];
private _RopesAttached = _object2 getVariable ["PTF_RopesAttached", 0];
private _Defultmass = _object2 getVariable ["PTF_ObjectMass", -1];
if (_RopesAttached == 0) exitwith {};
_object2 setmass _Defultmass;
_object2 setVariable ["PTF_RopesAttached", 0, true];
}];
