[
    "PTF_LzNames", "EDITBOX",
    ["LZ marker name list", "Set possibel names for the lz markers"],
    ["Paramarine Task Force", "Markers"],
    "['Alpha', 'Bravo', 'Charlie', 'Delta', 'Echo', 'Foxtrot', 'Golf', 'Hotel', 'India', 'Juliett', 'Kilo', 'Lima', 'Mike', 'November', 'Oscar', 'Papa', 'Quebec', 'Romeo', 'Sierra', 'Tango', 'Uniform', 'Victor', 'Whiskey', 'X-ray', 'Yankee', 'Zulu']",
    true, // isGlobal - the marker index (IDLZ) is shared, so the name list has to be too
    {},
    false // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_ReNames", "EDITBOX",
    ["Resupply marker name list", "Set possibel names for the Resupply markers"],
    ["Paramarine Task Force", "Markers"],
    "['Alpha', 'Bravo', 'Charlie', 'Delta', 'Echo', 'Foxtrot', 'Golf', 'Hotel', 'India', 'Juliett', 'Kilo', 'Lima', 'Mike', 'November', 'Oscar', 'Papa', 'Quebec', 'Romeo', 'Sierra', 'Tango', 'Uniform', 'Victor', 'Whiskey', 'X-ray', 'Yankee', 'Zulu']",
    true, // isGlobal - the marker index (IDRE) is shared, so the name list has to be too
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
[
    "PTF_ArsenelExit", "CHECKBOX",
    ["Auto Set Radios When exiting Arsenal", "Auto the your radioes when you exit the arsenal"],
    ["Paramarine Task Force", "TFAR Setting"],
    true,
    true, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
