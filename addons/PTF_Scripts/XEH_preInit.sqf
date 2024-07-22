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
    "PTF_WeaponWList", "EDITBOX",
    ["WhiteList Shoulderable Weapons", "Set what weapons you want to be able to shoulder"],
    ["Paramarine Task Force", "Weapon Swaping"],
    "['rhs_weap_m32','rhs_weap_M590_5RD','rhs_weap_M590_8RD']",
    true, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_WeaponW", "CHECKBOX",
    ["Enable Shoulderable Whitelist", "Only allowe the weapons defined under Whitelist to be place on your shoulder"],
    ["Paramarine Task Force", "Weapon Swaping"],
    true,
    true, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_TFARSR", "EDITBOX",
    ["Set SR Radio Channel", "Set what channel you would like to set when you exit the arsenal"],
    ["Paramarine Task Force", "TFAR Setting"],
    "0",
    false, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_TFARSRALT", "EDITBOX",
    ["Set SR ALT Radio Channel", "Set what channel you would like to set when you exit the arsenal"],
    ["Paramarine Task Force", "TFAR Setting"],
    "0",
    false, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_TFARLR", "EDITBOX",
    ["Set LR Radio Channel", "Set what channel you would like to set when you exit the arsenal"],
    ["Paramarine Task Force", "TFAR Setting"],
    "0",
    false, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
[
    "PTF_TFARLRALT", "EDITBOX",
    ["Set LR ALT Radio Channel", "Set what channel you would like to set when you exit the arsenal"],
    ["Paramarine Task Force", "TFAR Setting"],
    "0",
    false, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;