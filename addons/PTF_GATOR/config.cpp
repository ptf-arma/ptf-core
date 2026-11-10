// AN/TPS-80 G/ATOR radar trailer: stows for travel, deploys on site.
//
// The model and textures are a purchased model and live in ptf_gator_data.pbo, which is
// built outside git by tools/gator/build_data.py and ships with the external PBOs. This
// addon is the config and scripts. Without the data PBO it skips itself.
class CfgPatches
{
	class PTF_GATOR
	{
		name = "PTF Core - G/ATOR radar";
		units[] = {"PTF_GATOR", "PTF_GATOR_Sensor", "PTF_GATOR_SensorJammed"};
		weapons[] = {};
		requiredVersion = 2.18;
		requiredAddons[] = {"PTF_Main", "ptf_gator_data", "A3_Soft_F", "A3_Static_F_Sams_Radar_System_01", "cba_main", "ace_interaction"};
		skipWhenMissingDependencies = 1;
		author = "Paramarine Task Force";
	};
};

class CfgFunctions
{
	class PTF_GATOR
	{
		class main
		{
			file = "\z\PTF\addons\PTF_GATOR\functions";
			class setDeployed {};
			class canSetDeployed {};
			class setSpinning {};
			class canSetSpinning {};
			class setLeg {};
			class canSetLeg {};
			class setPower {};
			class canSetPower {};
			class powerState {};
			class soundLoop {};
			class fuelLoop {};
			class towHitchPoint {};
			class towFindVehicle {};
			class towHitch {};
			class towLoop {};
			class radarLoop {};
			class legState {};
			class legsDown {};
			class legReach {};
			class groundUnder {};
			class level {};
			class hearGenerator {};
			class alertGroup {};
			class fuelReport {};
			class cbFired {};
			class cbWatch {};
			class cbReport {};
			class cbPublish {};
			class cbImpact {};
			class cbErase {};
			class satcom {};
			class task {};
			class halt {};
			class gatorLayer {};
			class cbLayer {};
			class airLayer {};
			class cbClear {};
			class operator {};
			class operatorTick {};
			class splashWarn {};
			class armWatch {};
			class armReport {};
			class armLaunch {};
			class enemyBattery {};
			class initZeus { postInit = 1; };
			class computer {};
			class sweep {};
			class facing {};
			class console {};
			class initComputer { postInit = 1; };
		};
	};
};

#include "CfgVehicles.hpp"
#include "CfgSounds.hpp"

// Counter-battery: every gun's rounds are checked against the transmitting G/ATORs
// (PTF_GATOR_fnc_cbFired; one variable check per shot while none transmits).
class Extended_FiredBIS_EventHandlers
{
	class AllVehicles
	{
		class PTF_GATOR_cb
		{
			firedBIS = "_this call PTF_GATOR_fnc_cbFired";
		};
	};
};

// On the Billet tablet: map layers of their own (Billet's map layer slot), each with a section
// in the map's Tracks list beside Groups. Without Billet nothing reads these.
class blk_tabletLayers
{
	class ptf_gator
	{
		title = "G/ATOR";
		note = "Networked G/ATORs, their sensor arcs and reach";
		function = "PTF_GATOR_fnc_gatorLayer";
		on = 1;
	};
	class ptf_counterbattery
	{
		title = "Counter-battery";
		note = "Enemy firing points traced by G/ATOR";
		function = "PTF_GATOR_fnc_cbLayer";
		on = 1;
	};
	class ptf_airtracks
	{
		title = "Air tracks";
		note = "Aircraft the G/ATOR radar sees, 10 km out";
		function = "PTF_GATOR_fnc_airLayer";
		on = 1;
	};
};

// The operator computer's console on Billet's console slot: the tablet's map full screen with
// the G/ATOR's controls (PTF_GATOR_fnc_console), opened at the computer. Without Billet nothing
// reads this, and the computer offers manual and automatic control by ACE only.
class blk_tabletConsoles
{
	class ptf_gator
	{
		title = "G/ATOR operator console";
		function = "PTF_GATOR_fnc_console";
		layers[] = {"ptf_gator", "ptf_counterbattery", "ptf_airtracks"};
		range = 3;
	};
};

class Extended_PreInit_EventHandlers
{
	class PTF_GATOR
	{
		init = "call compile preprocessFileLineNumbers '\z\PTF\addons\PTF_GATOR\XEH_preInit.sqf'";
	};
};

class Extended_Init_EventHandlers
{
	class PTF_GATOR
	{
		class PTF_GATOR_sounds
		{
			init = "if (hasInterface) then {_this spawn PTF_GATOR_fnc_soundLoop}";
		};
		class PTF_GATOR_fuel
		{
			init = "_this call PTF_GATOR_fnc_fuelLoop";
		};
		class PTF_GATOR_tow
		{
			init = "_this call PTF_GATOR_fnc_towLoop";
		};
		class PTF_GATOR_radar
		{
			init = "if (isServer) then {_this call PTF_GATOR_fnc_radarLoop}";
		};
		// Its anchor (while leveled), its SATCOM antenna and its computer go with it, and its CROWS signal.
		class PTF_GATOR_cleanup
		{
			init = "if (isServer) then {(_this select 0) addEventHandler ['Deleted', {params ['_radar']; deleteVehicle (_radar getVariable ['PTF_GATOR_anchor', objNull]); deleteVehicle (_radar getVariable ['PTF_GATOR_antenna', objNull]); deleteVehicle (_radar getVariable ['PTF_GATOR_computer', objNull]); if (_radar getVariable ['PTF_GATOR_beacon', false]) then {['crowsEW_spectrum_removeBeacon', [_radar, 'zeus']] call CBA_fnc_serverEvent}}]}";
		};
	};
};
