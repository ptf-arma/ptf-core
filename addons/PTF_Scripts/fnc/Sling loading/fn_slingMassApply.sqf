// Sets the sling-load mass decided by PTF_fnc_slingMassUpdate. Has to run where
// the cargo is local: setMass is ignored anywhere else.
//
// _cargo     - the slung object
// _slingMass - mass to hold while slung, or -1 to restore the real mass. Omit it
//              to apply whatever was last decided, which is what the Local
//              handler in XEH_postInit.sqf does when the cargo changes owner.
// _heli      - set when a rope broke: keep _slingMass if the cargo still hangs
//              from this aircraft a frame later, else restore the real mass.
//
// The decision is stored on the cargo (PTF_SlingMass) so a new owner can pick it
// up. The real mass (PTF_ObjectMass) is recorded once, by the cargo's owner,
// before the first change - recording it only once keeps a mass that was never
// restored from being taken as the real one on the next lift.
params ["_cargo", "_slingMass", ["_heli", objNull]];

if (isNull _cargo) exitWith {};

if (!local _cargo) exitWith {
    // The cargo changed owner while this was on its way - pass it on.
    if (!isNil "_slingMass") then {
        ["PTF_slingMass_apply", _this, _cargo] call CBA_fnc_targetEvent;
    };
};

if (!isNull _heli) exitWith {
    // Wait a frame for the broken rope to be gone (and any replacement to exist).
    [{
        params ["_cargo", "_slingMass", "_heli"];
        private _stillSlung = _cargo in ropeAttachedObjects _heli;
        [_cargo, [-1, _slingMass] select _stillSlung] call PTF_fnc_slingMassApply;
    }, [_cargo, _slingMass, _heli]] call CBA_fnc_execNextFrame;
};

if (isNil "_slingMass") then {
    _slingMass = _cargo getVariable ["PTF_SlingMass", -1];
    // Re-applying a stored decision: if no rope holds the cargo any more (the
    // aircraft was deleted mid-lift, so no RopeBreak came), restore instead of
    // keeping it light for good.
    if (_slingMass > 0 && {isNull ropeAttachedTo _cargo}) then {
        _slingMass = -1;
        _cargo setVariable ["PTF_SlingMass", -1, true];
    };
} else {
    _cargo setVariable ["PTF_SlingMass", _slingMass, true];
};

if (_slingMass > 0) exitWith {
    if (isNil {_cargo getVariable "PTF_ObjectMass"}) then {
        _cargo setVariable ["PTF_ObjectMass", getMass _cargo, true];
    };
    // Only ever lighten: SlingloadingWeight is an absolute mass, and a load
    // already lighter than it (a small wreck on the wreck dummy) must not
    // get heavier.
    _cargo setMass (_slingMass min (_cargo getVariable ["PTF_ObjectMass", _slingMass]));
};

private _objectMass = _cargo getVariable ["PTF_ObjectMass", -1];
if (_objectMass > 0) then {
    _cargo setMass _objectMass;
    _cargo setVariable ["PTF_ObjectMass", nil, true];
};
