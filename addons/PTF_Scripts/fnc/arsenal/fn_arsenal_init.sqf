params ["_arsenal"];

call PTF_fnc_arsenalWhitelist params ["_standardArsenal", "_psoArsenal"];

private _whitelist = _standardArsenal;

[_arsenal, _whitelist, true] call ace_arsenal_fnc_initBox;

#include "\z\PTF\addons\PTF_Scripts\fnc\arsenal\defaultloadouts.hpp"













































