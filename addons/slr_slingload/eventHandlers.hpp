// PTF fork: ropes are simulated by the machine that creates them, so hook
// ropes are now created on the machine that owns the aircraft, after the
// cargo has been moved there. Upstream created them on the rigger's machine
// and tried to setOwner the ropes afterwards, leaving rope, aircraft and cargo
// on different machines in multiplayer.

// Server: move the cargo to the aircraft's owner, then have that machine
// create the hook ropes.
[QGVAR(hookCargo), {
    params ["_heli", "_cargo", "", "", "", "", ["_requester", objNull]];
    if (isNull _heli || {isNull _cargo}) exitWith {};
    // The engine won't move a vehicle with anyone inside to another machine.
    // attachCargo checks this too; this catches someone getting in meanwhile.
    if ((crew _cargo) findIf {alive _x} > -1) exitWith {
        [_requester, LSTRING(CargoOccupied)] call FUNC(hookRefused);
    };
    private _heliOwner = owner _heli;
    if (isMultiplayer && {owner _cargo != _heliOwner}) then {
        _cargo setOwner _heliOwner;
    };
    [QGVAR(createHookRopes), _this, _heli] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

// Aircraft owner: give the cargo up to 3 s to arrive, then create the ropes.
// If it never arrives, createHookRopes refuses rather than hang a load from
// ropes simulated on another machine.
[QGVAR(createHookRopes), {
    [{
        params ["_heli", "_cargo"];
        isNull _cargo || {local _cargo} || {!local _heli}
    }, FUNC(createHookRopes), _this, 3, FUNC(createHookRopes)] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

// Server: the aircraft changed owner mid-lift. Move its slung cargo along,
// then have the new owner recreate the ropes.
[QGVAR(claimCargo), {
    params ["_heli"];
    if (isNull _heli) exitWith {};
    private _heliOwner = owner _heli;
    {
        private _target = _x getVariable [QGVAR(target4Rope), objNull];
        if (isMultiplayer && {!isNull _target} && {owner _target != _heliOwner}) then {
            _target setOwner _heliOwner;
        };
    } forEach ropes _heli;
    [QGVAR(takeOverRopes), [_heli], _heli] call CBA_fnc_targetEvent;
}] call CBA_fnc_addEventHandler;

[QGVAR(takeOverRopes), {
    [{
        params ["_heli"];
        (ropes _heli) findIf {
            private _target = _x getVariable [QGVAR(target4Rope), objNull];
            !isNull _target && {!local _target}
        } == -1
    }, FUNC(takeOverRopes), _this, 3, FUNC(takeOverRopes)] call CBA_fnc_waitUntilAndExecute;
}] call CBA_fnc_addEventHandler;

// Server: move a picked-up apex fitting to the picker's machine. Only
// fittings: this is a client request, so don't let it move anything else.
[QGVAR(claimObject), {
    params ["_object", "_clientOwner"];
    if (isNull _object || {!isMultiplayer} || {!(_object isKindOf "slr_slingload_apexFitting")}) exitWith {};
    if (owner _object != _clientOwner) then {
        _object setOwner _clientOwner;
    };
}] call CBA_fnc_addEventHandler;

// The player whose hook-up was refused (see hookRefused): say why.
[QGVAR(hookRefused), {
    params ["_stringName"];
    if (hasInterface) then {
        // The fitting is gone by now, so the load has to be rigged again
        hint format ["%1 %2", localize _stringName, localize LSTRING(RigAgain)];
    };
}] call CBA_fnc_addEventHandler;

[QGVAR(destroyRope), {
    params ["_rope"];
    if (!isNull _rope) then {
        ropeDestroy _rope;
    };
}] call CBA_fnc_addEventHandler;

["slr_slingload_adjustRope", {
    params ["_rope", "_speed", "_length", "_relative"];
    ropeUnwind [_rope, _speed, _length, _relative];
}] call CBA_fnc_addEventHandler;

{
    [_x, "InitPost", {
        params ["_heli"];
        if (local _heli) then {
            _heli addItemCargoGlobal ["slr_slingload_CargoSling", 4];
        };
    }, true, [], true] call CBA_fnc_addClassEventHandler;

    [_x, "Local", {
        params ["_heli", "_isLocal"];
        if (_isLocal && {(ropes _heli) findIf {!isNil {_x getVariable QGVAR(target4Rope)}} > -1}) then {
            [QGVAR(claimCargo), [_heli]] call CBA_fnc_serverEvent;
        };
    }, true] call CBA_fnc_addClassEventHandler;
} forEach ["Helicopter", "VTOL_Base_F"];

["slr_slingload_apexFitting", "Deleted", {
    params ["_apexFitting"];
    private _cargo = _apexFitting getVariable ["slr_slingload_cargo4Fitting", objNull];
    if !(isNull _cargo) then {
        _cargo setVariable ["slr_slingload_ropes4Cargo", [], true];
    };
}, true] call CBA_fnc_addClassEventHandler;

["slr_slingload_apexFitting", "Killed", {
    params ["_apexFitting"];
    deleteVehicle _apexFitting;
}, true] call CBA_fnc_addClassEventHandler;

// A fitting picked up by another player is moved to their machine (see
// pickUpFitting); recreate its ropes there so they follow the new holder.
["slr_slingload_apexFitting", "Local", {
    params ["_apexFitting", "_isLocal"];
    if (_isLocal) then {
        [_apexFitting] call FUNC(takeOverRopes);
    };
}, true] call CBA_fnc_addClassEventHandler;

["slr_slingload_apexFitting", "Init", {
    (_this # 0) addEventHandler ["RopeBreak", {
        params ["_apexFitting"];
        // Only the owner decides, so a remote machine with a stale view of
        // the ropes can't delete a fitting whose rope is being recreated.
        if (!local _apexFitting) exitWith {};
        if (
            (ropeAttachedObjects _apexFitting isEqualTo [])
            ||
            {ropes _apexFitting isEqualTo []}
        ) then {
            deleteVehicle _apexFitting;
        };
    }];
}, true, [], true] call CBA_fnc_addClassEventHandler;
