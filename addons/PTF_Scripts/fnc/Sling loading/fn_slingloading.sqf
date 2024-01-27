params ["_Heli"];



_Heli addEventHandler ["RopeAttach", { 
 params ["_object1", "_rope", "_object2"];
_RopesAttached = _object2 getVariable ["PTF_RopesAttached", 0];
if (_RopesAttached > 1) exitwith {};
if (getmass _object2 > 6800) exitwith {};
if (getmass _object2 > 2900) then {
_object2 setVariable ["PTF_ObjectMass", getmass _object2, true];
_object2 setMass [2900];
_object2 setVariable ["PTF_RopesAttached", 1, true];
}
}];

_Heli addEventHandler ["RopeBreak", {
params ["_object1", "_rope", "_object2"];
_RopesAttached = _object2 getVariable "PTF_RopesAttached";
_Defultmass = _object2 getVariable "PTF_ObjectMass";
if (_RopesAttached == 0) exitwith {};
_object2 setmass [_Defultmass];
_object2 setVariable ["PTF_RopesAttached", 0, true];
}];