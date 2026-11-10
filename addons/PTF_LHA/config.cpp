// PTF changes to Peral's LHA (workshop 3596653038).
//
// Peral's PBO is another author's mod and is never edited. Everything here is a
// config patch that loads after it, so it applies to every LHA, including ones
// already placed in missions. A subclass would not work for the vehicle lists:
// Peral's spawner and light scripts read them from the class named "Peral_LHA",
// not from typeOf the ship.
//
// Each patched class keeps the parent Peral gave it (read from the PBO), or the
// patch would reset its inheritance.
class CfgPatches
{
	class PTF_LHA
	{
		name = "PTF Core - LHA";
		units[] = {};
		weapons[] = {};
		requiredVersion = 2.18;
		requiredAddons[] = {"Peral_LHA", "PTF_Sound"};
		// PTF Core without the LHA loaded: skip this addon instead of failing to start.
		skipWhenMissingDependencies = 1;
		author = "Paramarine Task Force";
	};
};

class CfgFunctions
{
	class PTF_LHA
	{
		class main
		{
			file = "\z\PTF\addons\PTF_LHA\functions";
			class shipInit {};
			class setLights {};
			class localLights {};
			class spawnerSelectVehicle {};
			class deckServices {};
			class addActions {};
			class announce {};
			class repairMarkers {};
			class logisticsActions {};
			class logisticsSpawn {};
			class initZeus { postInit = 1; };
		};
		class peral
		{
			// Peral's own spawner script, unchanged, so the PTF version can run it
			// once its extra check passes.
			class peralSpawnerSelectVehicle
			{
				file = "\Peral_LHA\scripts\spawner\fn_lha_spawner_selectVehicle.sqf";
			};
		};
	};

	// Peral's aircraft and amphibious spawners call LHA_fnc_lha_spawner_selectVehicle.
	// Point it at the PTF version, which refuses to replace a vehicle with someone
	// aboard and otherwise runs Peral's script.
	class LHA
	{
		class functions
		{
			class lha_spawner_selectVehicle
			{
				file = "\z\PTF\addons\PTF_LHA\functions\fn_spawnerSelectVehicle.sqf";
			};
		};
	};
};

// The ship's light groups (Peral's names, on Peral_LHA) and the switches that
// control each one. Two switches drive the island lights, so both are moved
// together and always show the same state.
class PTF_LHA_LightGroups
{
	class House
	{
		range = 5;
		switches[] = {{"LHA_house_1", "lvl1_lights_swich"}, {"LHA_house_2", "h_light_swich"}};
	};
	class HangerLVL1
	{
		range = 20;
		switches[] = {{"LHA_house_2", "lvl1_light_swich"}};
	};
	class HangerLVL2
	{
		range = 20;
		switches[] = {{"LHA_house_2", "lvl2_light_swich"}};
	};
	class StairCase
	{
		range = 5;
		switches[] = {{"LHA_house_2", "mh_light_swich"}};
	};
	class BriefingRoom
	{
		range = 5;
		switches[] = {{"LHA_house_2", "br_light_swich"}};
	};
};

// Flight deck and hangar services, set up by fn_deckServices on the server.
// Positions are in the model space of the ship part named with them, measured in
// game (tools/lha-test): the parts are level even when the root object isn't.
class PTF_LHA_Deck
{
	// Invisible helipads on Peral's six deck spawn spots, so AI helicopters have
	// somewhere to land besides Peral's single pad aft. Deck surface height.
	helipads[] = {
		{"LHA_Med_1", {11.626, 3.038, 13.004}},
		{"LHA_Med_1", {11.626, -14.268, 13.004}},
		{"LHA_Med_2", {17.318, 16.597, 12.166}},
		{"LHA_Med_2", {17.318, 0.398, 12.166}},
		{"LHA_Med_4", {12.144, 9.414, 13.003}},
		{"LHA_Med_4", {12.144, -7.923, 13.003}}
	};
	// Peral's deck refuel points: the hose reels modelled at the deck edge. Each
	// gets an ACE fuel hose (a coiled hose on the deck beside the reel) and a
	// vehicle ammo box a little aft along the edge.
	fuelPoints[] = {{"LHA_Bow", "refuelpoint"}, {"LHA_Bow", "refuelpoint2"}, {"LHA_Med_4", "refuelpoint"}};
	fuelProp = "Land_RefuelingHose_01_F";
	// Flight deck height in the parts' model space (Med_1, Med_4 and Bow alike).
	deckHeight = 13.0;
	ammoProp = "Box_NATO_AmmoVeh_F";
	// From the reel: metres inboard and aft.
	fuelOffset[] = {1.2, 0};
	ammoOffset[] = {1.0, -2.6};
	// The hangar is an ACE repair facility: markers on its floors under these light
	// groups' ceiling lights (Peral's names on Peral_LHA), this far below the floor.
	// See fn_repairMarkers.
	repairLights[] = {"HangerLVL1", "HangerLVL2"};
	repairMarkerDepth = 1;
};

// The ship's 1MC. Sounds are PTF_Sound's "navy" lines (tools/sound_lines.json);
// each name is PTF_Sound_<name> in CfgSounds and PTF_Sound_Module_<name> in
// CfgVehicles, which carries its duration.
class PTF_LHA_Announcements
{
	sounds[] = {
		"1mc_flight_quarters",
		"1mc_secure_flight_quarters",
		"1mc_general_quarters",
		"1mc_secure_general_quarters",
		"1mc_away_landing_force",
		"1mc_recover_landing_force",
		"1mc_fod_walkdown",
		"1mc_man_overboard",
		"1mc_reveille",
		"1mc_taps"
	};
	// Speakers: the ship parts the announcement plays from, and how far each carries.
	speakers[] = {"LHA_Bow", "LHA_Med_2", "LHA_Med_4", "LHA_Aft", "LHA_house_2"};
	range = 90;
	// The control panel: beside Peral's light switches at the foot of the island.
	panel[] = {"LHA_house_2", "h_lights_action"};
};

// The ship's logistics console: crates and support vehicles, spawned by the server
// (fn_logisticsSpawn) from an ACE menu in the hangar (fn_logisticsActions). PTF's
// Spawner computer can't serve the ship: it spawns at map markers, at sea level.
//
// Positions are in the model space of the part named with them, measured in game
// (tools/lha-test). In LHA_Med_3's frame the hangar floor is at z 3.77 and the
// flight deck at 12.74; the port aircraft elevator is at x -17.5, y -16.8.
class PTF_LHA_Logistics
{
	displayName = "Ship's Logistics";
	icon = "\a3\ui_f\data\igui\cfg\simpleTasks\types\container_ca.paa";
	// A desk and screen against the port hangar wall, just aft of the port elevator.
	console[] = {"LHA_Med_3", {-10.44, -28.25, 3.77}};
	consoleDir = 90;
	// Stacked bottom to top; the ACE menu is on the top one.
	consoleModels[] = {"Land_PortableDesk_01_black_F", "Land_MultiScreenComputer_01_black_F"};

	// Where things appear. Each spot: x, y, z (floor), direction relative to the
	// ship. A spot is taken while anything loose is within "clear" metres of it.
	class Areas
	{
		class Hangar
		{
			displayName = "in the hangar";
			part = "LHA_Med_3";
			clear = 1.6;
			// A row of six along the port side, aft of the console.
			spots[] = {
				{-6.44, -30.75, 3.77, 0},
				{-6.44, -34.25, 3.77, 0},
				{-6.44, -37.75, 3.77, 0},
				{-6.44, -41.25, 3.77, 0},
				{-6.44, -44.75, 3.77, 0},
				{-6.44, -48.25, 3.77, 0}
			};
		};
		class HangarVehicles
		{
			displayName = "in the hangar";
			part = "LHA_Med_3";
			clear = 4.5;
			// Down the middle of the hangar, facing forward to the port elevator.
			spots[] = {
				{3.56, -32.75, 3.77, 0},
				{3.56, -45.75, 3.77, 0},
				{3.56, -58.75, 3.77, 0}
			};
		};
		class FlightDeck
		{
			displayName = "on the flight deck";
			part = "LHA_Med_3";
			clear = 4;
			// Island row: along the island's port face, inside the foul line.
			spots[] = {
				{3.56, 17.25, 12.74, 0},
				{3.56, 5.25, 12.74, 0},
				{3.56, -6.75, 12.74, 0}
			};
		};
	};

	// The menus, in order. Classes that aren't loaded are left out; labels replace
	// a class's own display name where that is unclear.
	class Menus
	{
		class Cargo
		{
			displayName = "Cargo";
			icon = "\a3\ui_f\data\igui\cfg\simpleTasks\types\box_ca.paa";
			area = "Hangar";
			// The crates on PTF's Spawner computer (PTF_Scripts\fnc\spawners\Supplys.hpp).
			classes[] = {
				"PTF_Cargo_Small_Ammo", "PTF_Cargo_Small_Medical", "PTF_Cargo_Small_Launcher",
				"PTF_Cargo_Small_Explosives", "PTF_Cargo_Small_Humanitarian", "PTF_Cargo_Mortar",
				"PTF_Cargo_Vic", "PTF_Cargo_Small_Repair", "PTF_Cargo_Small_Rearm",
				"PTF_Cargo_Large_Ammo", "PTF_Cargo_Large_Medical", "PTF_Cargo_Large_Launcher",
				"PTF_Cargo_Large_Explosives", "PTF_Cargo_Large_VicBox", "PTF_Cargo_Large_Refuel",
				"PTF_Cargo_VicAmmo", "PTF_Cargo_Fuel_WD", "PTF_Cargo_Fuel_D"
			};
		};
		class HangarEquipment
		{
			displayName = "Hangar Equipment";
			icon = "\a3\ui_f\data\igui\cfg\simpleTasks\types\truck_ca.paa";
			area = "HangarVehicles";
			classes[] = {"PTF_Atlas", "PTF_Kalmar", "Peral_527_58M", "Peral_H2_Forklift", "Peral_USN6", "PTF_Tools_PalletJack"};
		};
		class DeckEquipment
		{
			displayName = "Flight Deck Equipment";
			icon = "\a3\ui_f\data\igui\cfg\simpleTasks\types\heli_ca.paa";
			area = "FlightDeck";
			classes[] = {"Peral_AS32A", "Peral_AS32A_35", "Peral_Helidolly_16x16"};
		};
	};
	class Labels
	{
		Peral_527_58M = "527-58M Heavy Forklift";
		Peral_H2_Forklift = "H3 Forklift";
		Peral_USN6 = "USN6 Forklift";
		Peral_AS32A = "A/S32A Deck Tractor";
		Peral_AS32A_35 = "A/S32A-35 Deck Crane";
		Peral_Helidolly_16x16 = "Helidolly";
	};
};

#include "CfgVehicles.hpp"
