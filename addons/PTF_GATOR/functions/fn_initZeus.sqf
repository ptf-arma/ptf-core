/*
 * Author: Paramarine Task Force
 * Player's machine (postInit): Zeus Enhanced modules under "PTF G/ATOR", for Zeus to give a
 * G/ATOR crew something to do. Without Zeus Enhanced nothing is registered.
 *  - Launch ARM at G/ATOR: an anti-radiation missile from a bearing and range Zeus picks,
 *    homing on the G/ATOR's radar while it transmits (PTF_GATOR_fnc_armLaunch)
 *  - Counter-fire on G/ATOR: an enemy mortar team fires on it as if it had a fix
 *  - Enemy battery: fire mission: a mortar team fires on the spot, then scoots
 *  - Enemy battery: harass: the same, coming back every few minutes from somewhere else
 *  - Stop enemy batteries
 * Enemy batteries are PTF_GATOR_fnc_enemyBattery; CROWS Electronic Warfare's own Zeus modules
 * place the jammers that jam a G/ATOR (PTF_GATOR_fnc_operatorTick).
 */
if (!hasInterface) exitWith {};
if (!isClass (configFile >> "CfgPatches" >> "zen_custom_modules")) exitWith {};

private _gatorAt = {
	params ["_posASL"];
	(nearestObjects [ASLToAGL _posASL, ["PTF_GATOR"], 300]) param [0, objNull]
};
missionNamespace setVariable ["PTF_GATOR_zeusGatorAt", _gatorAt];
private _side = {
	params ["_radar"];
	[east, west, independent, civilian] select (getNumber (configOf _radar >> "side") max 0 min 3)
};
missionNamespace setVariable ["PTF_GATOR_zeusSide", _side];

[
	"PTF G/ATOR",
	"Launch ARM at G/ATOR",
	{
		params ["_posASL"];
		private _radar = [_posASL] call PTF_GATOR_zeusGatorAt;
		if (isNull _radar) exitWith {["Place this on a G/ATOR."] call zen_common_fnc_showMessage};
		[
			"Anti-radiation missile",
			[
				["SLIDER", ["From bearing", "Where it comes from, degrees from north"], [0, 359, round random 360, 0]],
				["SLIDER", ["Range (km)", "How far off it is launched"], [4, 15, 9, 0]]
			],
			{
				params ["_values", "_radar"];
				_values params ["_bearing", "_km"];
				if (isNull (_radar getVariable ["PTF_GATOR_sensor", objNull])) then {
					["The G/ATOR is silent: the missile will have nothing to home on."] call zen_common_fnc_showMessage;
				};
				[_radar, _bearing, _km * 1000] remoteExecCall ["PTF_GATOR_fnc_armLaunch", 2];
			},
			{},
			_radar
		] call zen_dialog_fnc_create;
	},
	"\a3\ui_f\data\igui\cfg\simpleTasks\types\destroy_ca.paa"
] call zen_custom_modules_fnc_register;

[
	"PTF G/ATOR",
	"Counter-fire on G/ATOR",
	{
		params ["_posASL"];
		private _radar = [_posASL] call PTF_GATOR_zeusGatorAt;
		if (isNull _radar) exitWith {["Place this on a G/ATOR."] call zen_common_fnc_showMessage};
		[
			"Enemy counter-fire",
			[
				["SLIDER", ["Rounds", "How many the mortar fires"], [1, 12, 6, 0]],
				["LIST", ["Their fix", "How well the enemy knows where it is: how close the rounds land"],
					[[500, 100, 25], ["Rough (within 500 m)", "Good (within 100 m)", "Locked (within 25 m)"], 1]]
			],
			{
				params ["_values", "_radar"];
				_values params ["_rounds", "_miss"];
				[_radar getPos [random _miss, random 360], round _rounds, 0, [_radar] call PTF_GATOR_zeusSide] remoteExecCall ["PTF_GATOR_fnc_enemyBattery", 2];
				["An enemy mortar team is setting up."] call zen_common_fnc_showMessage;
			},
			{},
			_radar
		] call zen_dialog_fnc_create;
	},
	"\A3\ui_f\data\map\markers\nato\o_mortar.paa"
] call zen_custom_modules_fnc_register;

[
	"PTF G/ATOR",
	"Enemy battery: fire mission",
	{
		params ["_posASL"];
		[
			"Enemy fire mission",
			[
				["SLIDER", ["Rounds", "How many the mortar fires"], [1, 12, 4, 0]],
				["SIDE", ["Fires on", "The side it's an enemy of"], west]
			],
			{
				params ["_values", "_posASL"];
				_values params ["_rounds", "_target"];
				[ASLToAGL _posASL, round _rounds, 0, _target] remoteExecCall ["PTF_GATOR_fnc_enemyBattery", 2];
				["An enemy mortar team is setting up 1.5 to 3.5 km away."] call zen_common_fnc_showMessage;
			},
			{},
			_posASL
		] call zen_dialog_fnc_create;
	},
	"\A3\ui_f\data\map\markers\nato\o_mortar.paa"
] call zen_custom_modules_fnc_register;

[
	"PTF G/ATOR",
	"Enemy battery: harass",
	{
		params ["_posASL"];
		[
			"Enemy harassing fire",
			[
				["SLIDER", ["Rounds a volley", "How many each time"], [1, 12, 3, 0]],
				["SLIDER", ["Minutes between", "From somewhere else each time"], [2, 20, 6, 0]],
				["SIDE", ["Fires on", "The side it's an enemy of"], west]
			],
			{
				params ["_values", "_posASL"];
				_values params ["_rounds", "_every", "_target"];
				[ASLToAGL _posASL, round _rounds, round _every, _target] remoteExecCall ["PTF_GATOR_fnc_enemyBattery", 2];
				["Harassing fire until stopped (Stop enemy batteries)."] call zen_common_fnc_showMessage;
			},
			{},
			_posASL
		] call zen_dialog_fnc_create;
	},
	"\A3\ui_f\data\map\markers\nato\o_mortar.paa"
] call zen_custom_modules_fnc_register;

[
	"PTF G/ATOR",
	"Stop enemy batteries",
	{
		["stop"] remoteExecCall ["PTF_GATOR_fnc_enemyBattery", 2];
		["Every enemy battery has packed up."] call zen_common_fnc_showMessage;
	},
	"\a3\ui_f\data\igui\cfg\simpleTasks\types\exit_ca.paa"
] call zen_custom_modules_fnc_register;
