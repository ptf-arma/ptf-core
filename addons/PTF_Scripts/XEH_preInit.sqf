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
"PTF_SRChannels", "LIST",	 
["Select # of Short Range Channels",	 "Select how many SR channels you want to set"], 
["Paramarine Task Force", "TFAR Setting SR"], 
[[0,1,2,3,4,5,6,7,8,9], ["0","1","2","3","4","5","6","7","8","9"], 0],
false, // isGlobal
{
params ["_value"];
[_value,"SR"] call PTF_fnc_ChangeSettings;
},
false // needRestart
] call CBA_fnc_addSetting;

[
"PTF_LRChannels", "LIST",	 
["Select # of Long Range Channels",	 "Select how many LR channels you want to set"], 
["Paramarine Task Force", "TFAR Setting LR"], 
[[0,1,2,3,4,5,6,7,8,9], ["0","1","2","3","4","5","6","7","8","9"], 0],
false, // isGlobal
{
params ["_value"];
[_value,"LR"] call PTF_fnc_ChangeSettings;
},
false // needRestart
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