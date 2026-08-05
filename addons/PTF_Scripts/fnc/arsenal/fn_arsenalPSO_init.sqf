params ["_arsenal"];

// Cached once per machine -- see the note in fn_arsenal_init.sqf.
private _whitelists = missionNamespace getVariable ["PTF_arsenalWhitelistCache", []];
if (_whitelists isEqualTo []) then {
	_whitelists = call PTF_fnc_arsenalWhitelist;
	missionNamespace setVariable ["PTF_arsenalWhitelistCache", _whitelists];
};
_whitelists params ["_standardArsenal", "_psoArsenal"];

private _whitelist = _psoArsenal;

[_arsenal, _whitelist, true] call ace_arsenal_fnc_initBox;

#include "\z\PTF\addons\PTF_Scripts\fnc\arsenal\defaultloadouts.hpp"













































