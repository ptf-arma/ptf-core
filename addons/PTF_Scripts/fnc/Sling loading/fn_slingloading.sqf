params ["_Heli"];

_Heli addEventHandler ["RopeAttach", { 
 params ["_object1", "_rope", "_object2"];
_RopesAttached = missionNamespace getVariable ["PTF_RopesAttached", 0];
if (_RopesAttached > 1) exitwith {};
if (getmass _object2 > 6800) exitwith {};
if (getmass _object2 > 2900) then {
missionNamespace setVariable ["PTF_ObjectMass", getmass _object2];
_object2 setMass [2900];
missionNamespace setVariable ["PTF_RopesAttached", 1];
}
}];

_Helit addEventHandler ["RopeBreak", {
	params ["_object1", "_rope", "_object2"];
_RopesAttached = missionNamespace getVariable ["PTF_RopesAttached", 0];
_Defultmass = missionNamespace getVariable ["PTF_ObjectMass", 0];
if (_RopesAttached == 0) exitwith {};
_object2 setmass [_Defultmass];
missionNamespace setVariable ["PTF_RopesAttached", 0];
}];