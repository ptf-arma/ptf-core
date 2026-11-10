// Light switch actions call PTF's light functions in place of Peral's (see
// fn_setLights.sqf), and their names are spelled out properly.
class CfgVehicles
{
	class StaticShip;
	class Peral_LHA: StaticShip
	{
		// What the deck and well-deck spawners offer. Peral's lists named three F-35
		// classes and an FIR one that no mod defines (the spawner skips those), and
		// missed several PTF variants. PTF variants only, so nothing is listed twice.
		Aircraft[] = {
			"PTF_UH1Y",
			"PTF_UH1Y_Unarmed",
			"PTF_UH1Y_HQ",
			"PTF_UH1Y_GUNFIGHTERS",
			"PTF_UH1Y_GUNFIGHTERS_SL",
			"PTF_UH1Y_SCARFACE",
			"PTF_UH1Y_SCARFACE_SL",
			"PTF_AH1Z",
			"PTF_AH1Z_HQ",
			"PTF_AH1Z_GUNFIGHTERS",
			"PTF_AH1Z_VIS",
			"PTF_CH53_Ramp",
			"PTF_CH53_Cargo",
			"PTF_MV22_Ramp",
			"PTF_MV22_Cargo",
			"PTF_MV22_Minigun",
			"PTF_F35B_VIS",
			"PTF_MD500",
			"PTF_MD500_HQ",
			"PTF_MD500_Trainer",
			"PTF_MQ9",
			"PTF_MQ9_HQ",
			"PTF_MQ9_SCARFACE"
		};
		Amphibious[] = {
			"PTF_ACV",
			"PTF_ACV_MK19",
			"PTF_ACV_30",
			"PTF_ACV_E",
			"PTF_ACV_R",
			"PTF_Badger",
			"PTF_Badger_D"
		};

		// Peral's textures, with the PTF flag in the "Unit Flag" slot (index 4,
		// empty in Peral's). A mission that sets Unit Flag in Eden still wins.
		hiddenSelectionsTextures[] = {
			"Peral_LHA\data\clear_empty_ca.paa",
			"Peral_LHA\data\clear_empty_ca.paa",
			"Peral_LHA\data\clear_empty_ca.paa",
			"\A3\Data_F\Flags\flag_us_co.paa",
			"\z\PTF\addons\PTF_Textures\Flags\ptfflag.paa"
		};

		// Hull number painted on the island. Peral's draws one digit and picks a
		// random one each mission unless Eden's "Ship Number" is set; that setting
		// still wins. 8: the well deck makes this a Flight I America class, like
		// LHA-8 Bougainville.
		PTF_LHA_hullNumber = "8";

		// Runs beside Peral's own init. Event handler subclasses add to the class's
		// handlers instead of replacing them.
		class EventHandlers
		{
			class PTF_LHA
			{
				init = "_this call PTF_LHA_fnc_shipInit";
			};
		};
	};

	class LHA_Base;

	// Stern: Peral's turrets with the AI crews left out of the Praetorian CIWS and
	// both SAM launchers, so the ship doesn't fire on aircraft by itself. Players
	// can still take them over with a UAV terminal, and Zeus can crew them.
	// Fields: class, memory point, direction, spawn crew, keep attached.
	class LHA_Aft: LHA_Base
	{
		turrets[] = {
			{"B_AAA_System_01_F", "aaa_spawn", 180, 0, 0},
			{"B_SAM_System_01_F", "sam_spawn", 180, 0, 0},
			{"B_SAM_System_02_F", "sam2_spawn", 180, 0, 0},
			{"B_HMG_02_high_F", "m2_spawn1", 180, 0, 1},
			{"B_HMG_02_high_F", "m2_spawn2", 270, 0, 1},
			{"B_HMG_02_high_F", "m2_spawn3", 90, 0, 1}
		};
	};

	// Island: the second CIWS, also uncrewed. Its light switch (Peral's "Trun On
	// Lights") drives the island lights, Peral's "House" group.
	class LHA_house_1: LHA_Base
	{
		turrets[] = {{"B_AAA_System_01_F", "aaa_spawn", 0, 0, 0}};
		class UserActions
		{
			class lvl1_lights_on
			{
				displayName = "Turn On Island Lights";
				statement = "[this, 'House', 1] call PTF_LHA_fnc_setLights;";
			};
			class lvl1_lights_off
			{
				displayName = "Turn Off Island Lights";
				statement = "[this, 'House', 0] call PTF_LHA_fnc_setLights;";
			};
		};
	};

	// The light switch panel.
	class LHA_house_2: LHA_Base
	{
		class UserActions
		{
			class h_lights_on
			{
				displayName = "Turn On Island Lights";
				statement = "[this, 'House', 1] call PTF_LHA_fnc_setLights;";
			};
			class h_lights_off
			{
				displayName = "Turn Off Island Lights";
				statement = "[this, 'House', 0] call PTF_LHA_fnc_setLights;";
			};
			class lvl1_lights_on
			{
				displayName = "Turn On Hangar Level 1 Lights";
				statement = "[this, 'HangerLVL1', 1] call PTF_LHA_fnc_setLights;";
			};
			class lvl1_lights_off
			{
				displayName = "Turn Off Hangar Level 1 Lights";
				statement = "[this, 'HangerLVL1', 0] call PTF_LHA_fnc_setLights;";
			};
			class lvl2_lights_on
			{
				displayName = "Turn On Hangar Level 2 Lights";
				statement = "[this, 'HangerLVL2', 1] call PTF_LHA_fnc_setLights;";
			};
			class lvl2_lights_off
			{
				displayName = "Turn Off Hangar Level 2 Lights";
				statement = "[this, 'HangerLVL2', 0] call PTF_LHA_fnc_setLights;";
			};
			class mh_lights_on
			{
				displayName = "Turn On Main Hallway Lights";
				statement = "[this, 'StairCase', 1] call PTF_LHA_fnc_setLights;";
			};
			class mh_lights_off
			{
				displayName = "Turn Off Main Hallway Lights";
				statement = "[this, 'StairCase', 0] call PTF_LHA_fnc_setLights;";
			};
			class br_lights_on
			{
				displayName = "Turn On Briefing Room Lights";
				statement = "[this, 'BriefingRoom', 1] call PTF_LHA_fnc_setLights;";
			};
			class br_lights_off
			{
				displayName = "Turn Off Briefing Room Lights";
				statement = "[this, 'BriefingRoom', 0] call PTF_LHA_fnc_setLights;";
			};
		};
	};
};
