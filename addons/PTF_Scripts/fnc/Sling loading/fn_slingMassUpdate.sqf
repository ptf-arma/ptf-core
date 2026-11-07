// RopeAttach / RopeBreak handler registered by PTF_fnc_slingloading. Works out
// what the cargo's mass should be and sends it to the machine that owns the
// cargo, the only place setMass takes effect.
//
// _heli     - the PTF CH-53 / MV-22 the rope hangs from
// _rope     - the rope that was attached or broke
// _cargo    - the object on the other end
// _attached - true for RopeAttach, false for RopeBreak
params ["_heli", "_rope", "_cargo", "_attached"];

// Cargo that opts in has its own tuned weight. Anything else is only touched
// under an aircraft with an AFM lift factor (see PTF_fnc_slingMassApply).
private _heliType = typeOf _heli;
private _optedIn = ([_cargo, _heliType] call PTF_fnc_slingWeightFor) >= 0;
private _afmFactor = getNumber (configOf _heli >> "PTF_slingMassFactorAFM");
if (!_optedIn && {_afmFactor <= 0}) exitWith {};
if (_optedIn) then {_afmFactor = 1};

private _slingMass = [_cargo, _heliType] call PTF_fnc_slingMassFor;

// Which machines raise rope events is not something to depend on, so only a
// machine that owns one of the three parties speaks. That is at most three
// identical messages, and applying the same mass twice is harmless.
if !(local _heli || {local _rope} || {local _cargo}) exitWith {};

if (_attached) exitWith {
    ["PTF_slingMass_apply", [_cargo, _slingMass, objNull, _afmFactor], _cargo] call CBA_fnc_targetEvent;
};

// One rope breaking is not a release: Sling Load Rigging hangs a load on several
// ropes, one can snap while the rest hold, and it swaps ropes for new ones when
// the aircraft changes pilot. Passing the aircraft along has the cargo's owner
// (which also owns the ropes) check whether any rope still holds it.
["PTF_slingMass_apply", [_cargo, _slingMass, _heli], _cargo] call CBA_fnc_targetEvent;
