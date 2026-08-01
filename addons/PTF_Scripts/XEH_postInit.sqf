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
