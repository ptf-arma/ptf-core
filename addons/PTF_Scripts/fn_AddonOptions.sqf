[
    "PTF_LzNames", "EDITBOX",
    ["LZ marker name list", "Set possibel names for the lz markers"],
    ["Paramarine Task Force", "Markers"],
    "['Alpha', 'Bravo', 'Charlie', 'Delta', 'Echo', 'Foxtrot', 'Golf', 'Hotel', 'India', 'Juliett', 'Kilo', 'Lima', 'Mike', 'November', 'Oscar', 'Papa', 'Quebec', 'Romeo', 'Sierra', 'Tango', 'Uniform', 'Victor', 'Whiskey', 'X-ray', 'Yankee', 'Zulu']",
    false, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_ReNames", "EDITBOX",
    ["Resupply marker name list", "Set possibel names for the Resupply markers"],
    ["Paramarine Task Force", "Markers"],
    "['Alpha', 'Bravo', 'Charlie', 'Delta', 'Echo', 'Foxtrot', 'Golf', 'Hotel', 'India', 'Juliett', 'Kilo', 'Lima', 'Mike', 'November', 'Oscar', 'Papa', 'Quebec', 'Romeo', 'Sierra', 'Tango', 'Uniform', 'Victor', 'Whiskey', 'X-ray', 'Yankee', 'Zulu']",
    false, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
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
    [0, 100, 5, 0],
    true, // isGlobal
    {},
    true // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_PlaneTickets", "SLIDER",
    ["f18 Tickets", "Set Ticket Pool for Helicopters"],
    ["Paramarine Task Force", "Tickets"],
    [0, 100, 5, 0],
    true, // isGlobal
    {},
    true // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_MQ9Tickets", "SLIDER",
    ["MQ9 Tickets", "Set Ticket Pool for Helicopters"],
    ["Paramarine Task Force", "Tickets"],
    [0, 100, 5, 0],
    true, // isGlobal
    {},
    true // needRestart
] call CBA_fnc_addSetting;