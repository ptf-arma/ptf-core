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
