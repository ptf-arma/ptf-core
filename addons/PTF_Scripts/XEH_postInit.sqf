// Remove the PTF aircraft that use custom PTF loadout functions from ACE's
// pylon-editor list, so ACE doesn't also offer its generic pylon UI for them.
// Runs at postInit, after ace_pylons (a required addon) has populated the
// array. Guarded in case the array isn't present.
if (!isNil "ace_pylons_aircraftWithPylons") then {
    ace_pylons_aircraftWithPylons = ace_pylons_aircraftWithPylons - [
        "PTF_MQ9",
        "PTF_MQ9_SCARFACE",
        "PTF_MQ9_HQ",
        "PTF_AH1Z",
        "PTF_AH1Z_HQ",
        "PTF_AH1Z_GUNFIGHTERS"
    ];
};

// ---------------------------------------------------------------------------
// Forced respawn loadout (PTF_RespawnLoadoutEnabled, off by default).
//
// EntityRespawned is the right hook: it fires only on an actual respawn, never
// on initial spawn or JIP, so whatever a mission maker put in the Eden slot is
// left alone and only the vanilla-kit-on-death case is touched.
//
// Applied a frame late. ACE's own respawn gear handling and any mission-side
// onPlayerRespawn.sqf run on the respawn frame, and the last write to the
// unit's loadout wins -- going next frame means PTF Core is that last write.
// A mission that wants to own respawn gear opts out with
// PTF_RespawnLoadoutDisabled instead of racing us.
// ---------------------------------------------------------------------------
if (hasInterface) then {
    addMissionEventHandler ["EntityRespawned", {
        params ["_newUnit"];
        // Fires for every respawning entity this machine knows about, vehicles
        // included. Only the local player's own respawn is ours to re-kit.
        if (_newUnit != player) exitWith {};
        [PTF_fnc_respawnLoadout, [_newUnit]] call CBA_fnc_execNextFrame;
    }];
};

// Sling-load mass (PTF_fnc_slingloading). setMass only takes effect where the
// cargo is local, so the decision travels to the cargo's owner as an event, and
// is applied again whenever a lightened cargo changes owner - which a slung load
// does mid-lift, when Sling Load Rigging hands it to the pilot. Locality changes
// are infrequent and the check is two variable reads, so it is attached to every
// class rather than to a list that has to be kept in step with the configs.
["PTF_slingMass_apply", {_this call PTF_fnc_slingMassApply}] call CBA_fnc_addEventHandler;

["All", "Local", {
    params ["_object", "_isLocal"];
    if (!_isLocal) exitWith {};
    if (
        (_object getVariable ["PTF_SlingMass", -1]) > 0
        || {!isNil {_object getVariable "PTF_ObjectMass"}}
    ) then {
        [_object] call PTF_fnc_slingMassApply;
    };
}] call CBA_fnc_addClassEventHandler;

// "Sling info" (PTF_fnc_slingInfo): on anything slingable, its mass and which
// fleet aircraft can lift it; on aircraft, rated capacity and current load. The
// cargo test mirrors Sling Load Rigging's canRigCargo, sling item included.
if (hasInterface) then {
    private _icon = "\a3\ui_f\data\igui\cfg\vehicletoggles\slingloadropeiconon2_ca.paa";
    private _action = ["PTF_slingInfo", "Sling info", _icon, {[_target] call PTF_fnc_slingInfo}, {
        "slr_slingload_CargoSling" in (_player call ace_common_fnc_uniqueItems)
        && {!(_target isKindOf "CAManBase")}
        && {!(_target isKindOf "slr_slingload_apexFitting")}
        && {
            _target isKindOf "LandVehicle" || {_target isKindOf "Air"} || {_target isKindOf "Ship"}
            || {_target getVariable ["slr_slingload_isRiggingEnabled", false]}
            || {getArray (configOf _target >> "slingLoadCargoMemoryPoints") isNotEqualTo []}
        }
    }] call ace_interact_menu_fnc_createAction;
    ["All", 0, ["ACE_MainActions"], _action, true] call ace_interact_menu_fnc_addActionToClass;

    // Aircrew can't interact with their own aircraft from outside
    private _selfAction = ["PTF_slingInfoSelf", "Sling info", _icon, {[_target] call PTF_fnc_slingInfo}, {
        getNumber (configOf _target >> "slingLoadMaxCargoMass") > 0
        && {"slr_slingload_CargoSling" in (_player call ace_common_fnc_uniqueItems)}
    }] call ace_interact_menu_fnc_createAction;
    ["Air", 1, ["ACE_SelfActions"], _selfAction, true] call ace_interact_menu_fnc_addActionToClass;
};
