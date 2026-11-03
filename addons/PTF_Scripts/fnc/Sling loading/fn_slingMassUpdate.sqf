// RopeAttach / RopeBreak handler registered by PTF_fnc_slingloading. Works out
// what the cargo's mass should be and sends it to the machine that owns the
// cargo, the only place setMass takes effect.
//
// _heli     - the PTF CH-53 / MV-22 the rope hangs from
// _rope     - the rope that was attached or broke
// _cargo    - the object on the other end
// _attached - true for RopeAttach, false for RopeBreak
params ["_heli", "_rope", "_cargo", "_attached"];

private _weights = getText (configOf _cargo >> "SlingloadingWeight");
if (_weights isEqualTo "") exitWith {};

private _index = ["PTF_CH53", "PTF_MV22"] find ((typeOf _heli) select [0, 8]);
if (_index < 0) exitWith {};

// Which machines raise rope events is not something to depend on, so only a
// machine that owns one of the three parties speaks. That is at most three
// identical messages, and applying the same mass twice is harmless.
if !(local _heli || {local _rope} || {local _cargo}) exitWith {};

private _masses = parseSimpleArray _weights;
if (isNil "_masses") exitWith {};
private _slingMass = _masses param [_index, -1, [0]];

if (_attached) exitWith {
    ["PTF_slingMass_apply", [_cargo, _slingMass], _cargo] call CBA_fnc_targetEvent;
};

// One rope breaking is not a release: Sling Load Rigging hangs a load on several
// ropes, one can snap while the rest hold, and it swaps ropes for new ones when
// the aircraft changes pilot. Passing the aircraft along has the cargo's owner
// (which also owns the ropes) check whether any rope still holds it.
["PTF_slingMass_apply", [_cargo, _slingMass, _heli], _cargo] call CBA_fnc_targetEvent;
