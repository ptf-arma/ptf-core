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
