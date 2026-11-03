params ["_arsenal"];

// PTF_fnc_arsenalWhitelist allocates ~950 string literals across 16 sub-arrays
// and concatenates them, and this init runs for every arsenal and crate on the
// map. The contents are static, so build it once per machine and reuse it.
//
// The cache lives here rather than inside the whitelist function because that
// file has to stay pure data: tools/check-arsenal.sh treats every quoted string
// in it as a classname, and tests/ interprets it with sqflint.
private _whitelists = missionNamespace getVariable ["PTF_arsenalWhitelistCache", []];
if (_whitelists isEqualTo []) then {
	_whitelists = call PTF_fnc_arsenalWhitelist;
	missionNamespace setVariable ["PTF_arsenalWhitelistCache", _whitelists];
};
_whitelists params ["_standardArsenal", "_psoArsenal"];

private _whitelist = _standardArsenal;

[_arsenal, _whitelist, true] call ace_arsenal_fnc_initBox;

// Registers the PTF role kits with ACE once per machine, not once per box.
call PTF_fnc_registerDefaultLoadouts;
