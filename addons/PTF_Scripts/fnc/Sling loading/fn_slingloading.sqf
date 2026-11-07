// Sling-load mass override for the PTF CH-53s and MV-22s. Called from those
// aircraft's config init, so it runs on every machine.
//
// Sling Load Rigging hangs loads on plain physics ropes, so the airframe has to
// out-lift the real weight - slingLoadMaxCargoMass only governs vanilla sling
// loading - and at full weight these aircraft cannot lift the vehicles that opt
// in. A cargo class opts in with
//     SlingloadingWeight = "[<mass under a CH-53>, <mass under an MV-22>]";
// and weighs that much for as long as it hangs from one of these aircraft.
//
// Locality is the whole difficulty. setMass only takes effect on the machine
// that owns the cargo, and a slung load changes owner mid-lift: Sling Load
// Rigging hands it to the pilot after the ropes go on. So the rope handlers here
// only decide what the mass should be (PTF_fnc_slingMassUpdate); the cargo's
// owner applies it (PTF_fnc_slingMassApply), and applies it again whenever the
// cargo moves to another machine (the Local handler in XEH_postInit.sqf).
params ["_heli"];

// Register once per machine, however many times this is called.
if (_heli getVariable ["PTF_slingMassHandlers", false]) exitWith {};
_heli setVariable ["PTF_slingMassHandlers", true];

_heli addEventHandler ["RopeAttach", {
    params ["_heli", "_rope", "_cargo"];
    [_heli, _rope, _cargo, true] call PTF_fnc_slingMassUpdate;
}];

_heli addEventHandler ["RopeBreak", {
    params ["_heli", "_rope", "_cargo"];
    [_heli, _rope, _cargo, false] call PTF_fnc_slingMassUpdate;
}];
