// What a cargo weighs on the ropes under an aircraft type: its real mass, or
// its SlingloadingWeight for that aircraft if that is lighter (the same rule
// PTF_fnc_slingMassApply uses when it lightens the cargo).
//
// _cargo    - the object that would hang from the ropes
// _heliType - aircraft class name
params ["_cargo", "_heliType"];

// While slung, getMass is the lightened mass; the real one is kept here.
private _realMass = _cargo getVariable ["PTF_ObjectMass", getMass _cargo];
private _weight = [_cargo, _heliType] call PTF_fnc_slingWeightFor;

[_realMass, _realMass min _weight] select (_weight > 0)
