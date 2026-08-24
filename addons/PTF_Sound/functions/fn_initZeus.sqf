/*
	Per-client setup (postInit): registers the "Place Loudspeaker..." browse
	module with ZEN's custom modules framework. Registration is local to each
	client, hence postInit on every machine with an interface. Soft
	dependency - without ZEN nothing is registered and the per-sound modules
	still work.
*/
if (!hasInterface) exitWith {};
if (!isClass (configFile >> "CfgPatches" >> "zen_custom_modules")) exitWith {};

[
	"PTF Loudspeakers",
	"Place Loudspeaker...",
	{_this call PTF_Sound_fnc_browseDialog},
	"\a3\ui_f\data\igui\cfg\simpleTasks\types\talk_ca.paa"
] call zen_custom_modules_fnc_register;
