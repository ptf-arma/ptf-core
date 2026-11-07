// The mass a cargo is lightened to while slung under an aircraft type, or -1 if
// it doesn't opt in for that aircraft. Cargo classes opt in with
// SlingloadingWeight = "[<under a CH-53>, <under an MV-22>]"; the aircraft is
// matched by its PTF class prefix.
//
// _cargo    - the object that would hang from the ropes
// _heliType - aircraft class name
params ["_cargo", "_heliType"];

private _weights = getText (configOf _cargo >> "SlingloadingWeight");
if (_weights isEqualTo "") exitWith {-1};

private _index = ["PTF_CH53", "PTF_MV22"] find (_heliType select [0, 8]);
if (_index < 0) exitWith {-1};

private _masses = parseSimpleArray _weights;
if (isNil "_masses") exitWith {-1};
_masses param [_index, -1, [0]]
