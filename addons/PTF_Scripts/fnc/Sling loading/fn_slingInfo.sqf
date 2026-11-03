// "Sling info" readout (ACE interaction, registered in XEH_postInit.sqf).
//
// On an aircraft that can sling: its rated capacity and what it is carrying.
// On anything else: its mass, and which aircraft in CfgPTFSlingFleet
// (PTF_Aircraft) can lift it, using the weight it would have on their ropes.
//
// Capacities are the aircraft's slingLoadMaxCargoMass. Sling Load Rigging's
// ropes are plain physics and don't enforce it, so this is the rating to fly
// by, not a hard limit.
//
// _target - the object interacted with (or the player's aircraft, from inside)
params ["_target"];

private _fnc_mass = {
    params ["_kg"];
    if (_kg >= 1000) then {format ["%1 t", (_kg / 1000) toFixed 1]} else {format ["%1 kg", round _kg]}
};
private _green = "#8FD16A";
private _red = "#E06C5F";

private _lines = [format ["<t size='1.2'>%1</t>", getText (configOf _target >> "displayName")]];
private _capacity = getNumber (configOf _target >> "slingLoadMaxCargoMass");

if (_capacity > 0 && {alive _target}) then {
    // Aircraft: rating and current load
    _lines pushBack format ["Rated sling capacity: %1", [_capacity] call _fnc_mass];

    // SLR records each rope's load on the rope; vanilla sling loading has one.
    private _slung = [];
    {
        private _load = _x getVariable ["slr_slingload_target4Rope", objNull];
        if (!isNull _load) then {_slung pushBackUnique _load};
    } forEach ropes _target;
    private _vanillaLoad = getSlingLoad _target;
    if (!isNull _vanillaLoad) then {_slung pushBackUnique _vanillaLoad};

    if (_slung isEqualTo []) then {
        _lines pushBack "Slung now: nothing";
    } else {
        private _heliType = typeOf _target;
        private _load = 0;
        {_load = _load + ([_x, _heliType] call PTF_fnc_slingMassFor)} forEach _slung;
        _lines pushBack format [
            "Slung now: <t color='%1'>%2</t> (%3 spare)",
            [_red, _green] select (_load <= _capacity),
            [_load] call _fnc_mass,
            [(_capacity - _load) max 0] call _fnc_mass
        ];
    };
} else {
    // Cargo: mass, and a verdict per fleet aircraft. A rigged wreck hangs from
    // its dummy, so that is what the ropes actually carry.
    private _cargo = _target;
    private _wreckDummy = _target getVariable ["slr_slingload_wreckDummy", objNull];
    if (!isNull _wreckDummy) then {_cargo = _wreckDummy};

    _lines pushBack format ["Mass: %1", [_cargo getVariable ["PTF_ObjectMass", getMass _cargo]] call _fnc_mass];
    _lines pushBack "<t size='0.9'>Sling lift (on the ropes / rated):</t>";
    {
        private _heliType = getText (_x >> "vehicle");
        private _rated = getNumber (configFile >> "CfgVehicles" >> _heliType >> "slingLoadMaxCargoMass");
        if (_rated > 0) then {
            private _onRopes = [_cargo, _heliType] call PTF_fnc_slingMassFor;
            private _canLift = _onRopes <= _rated;
            _lines pushBack format [
                "<t color='%1'>%2 %3</t>  %4 / %5",
                [_red, _green] select _canLift,
                ["NO", "OK"] select _canLift,
                getText (_x >> "displayName"),
                [_onRopes] call _fnc_mass,
                [_rated] call _fnc_mass
            ];
        };
    } forEach ("true" configClasses (configFile >> "CfgPTFSlingFleet"));
};

hintSilent parseText (_lines joinString "<br/>");
