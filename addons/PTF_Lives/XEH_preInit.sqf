// Server settings (Addon Options > Paramarine Task Force > Lives). These are
// only where a mission starts: admins change both live from the Billet tablet,
// and those changes last until the mission ends.
[
    "PTF_Lives_onSetting", "CHECKBOX",
    ["Lives on at mission start", "Each player gets a set number of lives. Admins can switch this on or off during the mission from the Billet tablet."],
    ["Paramarine Task Force", "Lives"],
    false,
    1, // global: the server's value is everyone's
    {},
    false
] call CBA_fnc_addSetting;
[
    "PTF_Lives_startSetting", "SLIDER",
    ["Starting lives", "Lives each player gets the first time they join the mission."],
    ["Paramarine Task Force", "Lives"],
    [1, 50, 3, 0],
    1,
    {},
    false
] call CBA_fnc_addSetting;
