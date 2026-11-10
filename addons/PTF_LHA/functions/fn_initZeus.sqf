/*
 * Player's machine (postInit): a Zeus Enhanced module, "PTF LHA" > "1MC
 * Announcement". Place it on or near an LHA, pick an announcement, and the ship
 * plays it. Without Zeus Enhanced nothing is registered.
 */
if (!hasInterface) exitWith {};
if (!isClass (configFile >> "CfgPatches" >> "zen_custom_modules")) exitWith {};

[
	"PTF LHA",
	"1MC Announcement",
	{
		params ["_posASL"];
		private _ship = (nearestObjects [ASLToAGL _posASL, ["Peral_LHA"], 300]) param [0, objNull];
		if (isNull _ship) exitWith {["Place this on an LHA."] call zen_common_fnc_showMessage};

		private _sounds = getArray (configFile >> "PTF_LHA_Announcements" >> "sounds");
		private _names = _sounds apply {getText (configFile >> "CfgVehicles" >> ("PTF_Sound_Module_" + _x) >> "displayName")};
		[
			"1MC Announcement",
			[["LIST", "Announcement", [_sounds, _names, 0, 10], true]],
			{
				params ["_values", "_ship"];
				[_ship, _values select 0] remoteExecCall ["PTF_LHA_fnc_announce", 2];
			},
			{},
			_ship
		] call zen_dialog_fnc_create;
	},
	"\a3\ui_f\data\igui\cfg\simpleTasks\types\talk_ca.paa"
] call zen_custom_modules_fnc_register;
