params ["_value", ["_TYPE","SR"]];

if (_value == 0) exitWith {}; 

for "_i" from 1 to _value do {
[
    "PTF_TFAR" + _TYPE + str _i, "EDITBOX",
    ["Set " + _TYPE + " Radio Channel # " +str _i , "Set The Frequancy for this channel"],
    ["Paramarine Task Force", "TFAR Setting " + _TYPE],
    "0",
    false, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;

};

[
    "PTF_TFAR" + _TYPE +"ALT", "LIST",
    ["SET ALT CHANNEL", "Set What Channel to be Alternate"],
    ["Paramarine Task Force", "TFAR Setting " + _TYPE],
    [[0,1,2,3,4,5,6,7,8,9], ["0","1","2","3","4","5","6","7","8","9"], 0],
    false, // isGlobal
    {},
    false // needRestart
] call CBA_fnc_addSetting;
