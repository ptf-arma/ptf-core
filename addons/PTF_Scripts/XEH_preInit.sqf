[
    "PTF_LzNames", "EDITBOX",
    ["LZ marker name list", "Set possibel names for the lz markers"],
    ["Paramarine Task Force", "Markers"],
    "['Alpha', 'Bravo', 'Charlie', 'Delta', 'Echo', 'Foxtrot', 'Golf', 'Hotel', 'India', 'Juliett', 'Kilo', 'Lima', 'Mike', 'November', 'Oscar', 'Papa', 'Quebec', 'Romeo', 'Sierra', 'Tango', 'Uniform', 'Victor', 'Whiskey', 'X-ray', 'Yankee', 'Zulu']",
    true,  // isGlobal - the SERVER reads this list to allocate callsigns from one
           // canonical pool, so every client must agree on it. Per-player lists
           // and unique unit-wide callsigns are mutually exclusive.
    {},
    false // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_ReNames", "EDITBOX",
    ["Resupply marker name list", "Set possibel names for the Resupply markers"],
    ["Paramarine Task Force", "Markers"],
    "['Alpha', 'Bravo', 'Charlie', 'Delta', 'Echo', 'Foxtrot', 'Golf', 'Hotel', 'India', 'Juliett', 'Kilo', 'Lima', 'Mike', 'November', 'Oscar', 'Papa', 'Quebec', 'Romeo', 'Sierra', 'Tango', 'Uniform', 'Victor', 'Whiskey', 'X-ray', 'Yankee', 'Zulu']",
    true,  // isGlobal - the SERVER reads this list to allocate callsigns from one
           // canonical pool, so every client must agree on it. Per-player lists
           // and unique unit-wide callsigns are mutually exclusive.
    {},
    false // needRestart
] call CBA_fnc_addSetting;
// The ticket sliders below are the configured maximum only - CBA resets a
// setting to its configured value on any settings refresh, so the live count is
// kept in a matching <setting>Current missionNamespace variable instead.
// Do not write these from script.
[
    "PTF_Uh1yTickets", "SLIDER",
    ["Armed Uh1y Tickets", "Set Ticket Pool for Helicopters"],
    ["Paramarine Task Force", "Tickets"],
    [0, 100, 5, 0],
    true, // isGlobal
    {},
    true // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_Ah1zTickets", "SLIDER",
    ["Ah1z Tickets", "Set Ticket Pool for Helicopters"],
    ["Paramarine Task Force", "Tickets"],
    [0, 100, 2, 0],
    true, // isGlobal
    {},
    true // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_PlaneTickets", "SLIDER",
    ["f18 Tickets", "Set Ticket Pool for Helicopters"],
    ["Paramarine Task Force", "Tickets"],
    [0, 100, 2, 0],
    true, // isGlobal
    {},
    true // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_MQ9Tickets", "SLIDER",
    ["MQ9 Tickets", "Set Ticket Pool for Helicopters"],
    ["Paramarine Task Force", "Tickets"],
    [0, 100, 2, 0],
    true, // isGlobal
    {},
    true // needRestart
] call CBA_fnc_addSetting;

// ---------------------------------------------------------------------------
// Respawn loadout
//
// Arma rebuilds a respawning player from the config of whatever class the
// mission's playable slot uses, so any gear applied in Eden or out of an
// arsenal is gone and the player gets that class's kit -- a vanilla one, since
// this mod defines no BLUFOR man classes. These two settings let a server hand
// every respawning player one of the PTF role kits instead.
//
// The kit list is built here, not lazily on first use, because the LIST setting
// below needs the names now. It is an #include rather than a call to keep the
// build free of any assumption about when CfgFunctions finished compiling
// relative to CBA's preInit.
// ---------------------------------------------------------------------------
PTF_defaultLoadouts =
#include "\z\PTF\addons\PTF_Scripts\fnc\arsenal\defaultloadouts.hpp"
;
PTF_defaultLoadoutsMap = createHashMapFromArray PTF_defaultLoadouts;

private _loadoutNames = PTF_defaultLoadouts apply {_x select 0};
private _defaultLoadout = _loadoutNames find "Rifleman D";
if (_defaultLoadout < 0) then {_defaultLoadout = 0};

[
    "PTF_RespawnLoadoutEnabled", "CHECKBOX",
    [
        "Force respawn loadout",
        "Give every respawning player the kit selected below, instead of the config kit of their slot's unit class. Off leaves respawn exactly as it is now."
    ],
    ["Paramarine Task Force", "Respawn"],
    false,
    true,  // isGlobal - one server-wide rule, and a client must not be able to
           // opt itself into a better kit than everyone else.
    {},
    false // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_RespawnLoadoutName", "LIST",
    [
        "Respawn loadout",
        "Which PTF role kit respawning players are given. Ignored unless 'Force respawn loadout' is on."
    ],
    ["Paramarine Task Force", "Respawn"],
    [_loadoutNames, _loadoutNames, _defaultLoadout],
    true,  // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
