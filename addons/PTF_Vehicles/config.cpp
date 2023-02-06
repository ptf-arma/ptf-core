class cfgPatches
{
	class PTF_Vehicles
	{
		units[] = {"PTF_F450_S7Training","PTF_F450_AirOperations","PTF_F450_Tow","PTF_F450_EMS","PTF_M1151_MK19","PTF_M1151_M240","PTF_M1151_M2","PTF_M1078A1P2_M2","PTF_Quadbike","PTF_SDV","PTF_Rhib","PTF_Rhib_MK19","PTF_Zodiac","PTF_LCU1600","PTF_MKVSOC","PTF_Atlas","PTF_Kalmar","PTF_Tractor","PTF_Command_MRZR_HQ","PTF_Command_MRZR_1ST","PTF_Command_MRZR_2ND","PTF_Command_MRZR_MAG36","PTF_MRZR4","PTF_M1151","PTF_M1152","PTF_MRAP_CGRCAT1A2_MK19","PTF_MRAP_CGRCAT1A2_M2","PTF_MRAP_M1232_M2","PTF_MRAP_M1232_MK19","PTF_M977A4_Refuel","PTF_M977A4_Repair","PTF_M977A4_Ammo","PTF_M1085A1P2","PTF_M1078A1P2","PTF_MTVR_Repair","PTF_MTVR_Ammo","PTF_MTVR_Refuel","PTF_TowingTractor","PTF_M1151_M2_LRAS","PTF_Snowmobile","PTF_Snowmobile_Basket","PTF_Quadbike_6x6","PTF_AAV","PTF_AAV_CMD","PTF_SAM_RADAR","PTF_SAM_DEFENDER","PTF_M1123"};
		weapons[] = {"PTF_weap_mastersafe","PTF_Vlmg_M240_veh"};
		magazines[] = {"PTF_400rnd_TE1_Red_Tracer_762x51_M240_M"};
		requiredVersion = "0.1";
		requiredAddons[] = {"A3_Weapons_F","A3_Armor_F_Tank","PTF_Main","PTF_Textures","PTF_Models","d3s_fseries_15","d3s_cars_core","d3s_cars_core_18","CUP_WheeledVehicles_Core","CUP_WheeledVehicles_LAV25","CUP_WaterVehicles_RHIB","CUP_WheeledVehicles_MTVR","boxloader_tractor","rhsusf_c_mrzr","CUP_WaterVehicles_LCU1600","rhsusf_c_fmtv","CUP_TrackedVehicles_AAV","rhsusf_c_m11xx","rhsusf_c_hemtt_a4","rhsusf_c_cougar","rhsusf_c_rg33l","A3_Data_F_Oldman_Loadorder","A3_Soft_F_Exp","A3_Boat_F_Beta","CUP_WheeledVehicles_TowingTractor","CUP_WaterVehicles_Zodiac"};
	};
};
class rhsusf_m998_w_4dr_fulltop;
class rhsusf_m1025_w : rhsusf_m998_w_4dr_fulltop {
    class turrets;
};
class rhsusf_m966_w : rhsusf_m1025_w {
    class turrets : turrets {
    class TOW_Turret;
    class CargoTurret_01;
	class CargoTurret_02; 
	class CargoTurret_03;  
 };
};
class boxloader_tractor_build;
class boxloader_kalmar;
class boxloader_atlas;
class CUP_B_MTVR_Repair_USMC;
class CUP_B_MTVR_Ammo_USMC;
class CUP_B_MTVR_Refuel_USMC;
class CUP_B_TowingTractor_USA;
class CUP_B_RHIB_USMC;
class CUP_B_RHIB2Turret_USMC;
class CUP_B_Zodiac_USMC;
class CUP_B_LCU1600_USMC;
class CUP_B_AAV_USMC;
class CUP_B_AAV_Unarmed_USMC;
class CUP_B_LAV25M240_USMC;
class CUP_B_LAV25_USMC;
class Turrets;
class MainTurret;
class RCWSOptics;
class HitPoints;
class NewTurret;
class WeaponFireGun;
class WeaponCloudsGun;
class WeaponFireMGun;
class WeaponCloudsMGun;
class Mode_SemiAuto;
class Mode_Burst;
class Mode_FullAuto;
class HighROF;
class LowROF;
class CUP_Vacannon_M242_veh_LAV25;
class CUP_Vacannon_M242_veh;
class CUP_Vlmg_M240_veh;
class VehicleMagazine;
class d3s_fseries_LTD_17;
class d3s_fseries_17_TOW;
class d3s_fseries_17_EMS;
class HitLFWheel;
class HitLF2Wheel;
class HitRFWheel;
class HitRF2Wheel;
class HitFuel;
class HitHull;
class HitEngine;
class HitBody;
class HitGlass1;
class HitGlass2;
class HitGlass3;
class HitGlass4;
class HitGlass5;
class HitGlass6;
class Reflectors;
class LightCarHeadL01;
class UserActions;
class code2;
class R_on;
class R_off;
class OpenDoor_1;
class CloseDoor_1;
class OpenDoor_2;
class CloseDoor_2;
class ems_load_vehicle;
class ems_unload_vehicle;
class GurneyTabl;
class Components;
class SensorTemplateDataLink;
class SensorTemplatePassiveRadar;
class SensorTemplateActiveRadar;
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;
class rhsusf_mrzr4_d;
class rhsusf_CGRCAT1A2_Mk19_usmc_wd;
class rhsusf_CGRCAT1A2_M2_usmc_wd;
class rhsusf_M1232_MC_M2_usmc_wd;
class rhsusf_M1232_MC_MK19_usmc_wd;
class rhsusf_M1085A1P2_B_WD_Medical_fmtv_usarmy;
class rhsusf_M1078A1P2_WD_fmtv_usarmy;
class rhsusf_M978A4_usarmy_wd;
class rhsusf_M977A4_REPAIR_usarmy_wd;
class rhsusf_M977A4_AMMO_usarmy_wd;
class rhsusf_m1151_usmc_wd;
class rhsusf_m1152_rsv_usmc_wd;
class rhsusf_m1151_mk19_v3_usmc_wd;
class rhsusf_m1151_m240_v3_usmc_wd;
class rhsusf_m1151_m2_v3_usmc_wd;
class rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy;
class rhsusf_mkvsoc;
class rhsusf_m1151_m2_lras3_v1_usarmy_wd;
class rhsusf_M977A4_REPAIR_BKIT_M2_usarmy_wd;
class B_T_Quadbike_01_F;
class B_SDV_01_F;
class VehicleTransport;
class TransportItems;
class TransportBackpacks;
class TransportWeapons;
class TransportMagazines;
class CargoTurret;
class CargoTurret_01;
class CargoTurret_02;
class CargoTurret_03;
class CargoTurret_04;
class ViewOptics;
class CommanderTurret;
class CargoGunner_1;
class CargoGunner_2;
class CargoGunner_3;
class CargoGunner_4;
class CargoGunner_5;
class CargoGunner_6;
class MCTAGS_Turret;
class CoDriverTurret;
class GPK_Turret;
class M2_Turret;
class Default;
class US85_LAV25;
class US85_vehicleNtltyM;
class US85_vehicleArmorUnits;
class US85_vehicleEmblems;
class HitLMWheel;
class HitLBWheel;
class HitRMWheel;
class HitRBWheel;
class DefaultEventHandlers;
class NDS_6x6_ATV_MIL;
class NDS_6x6_ATV_MIL2;
class xs_Snowmobile_combat;
class xs_Snowmobile_sport_camo;
class B_SAM_System_03_F;
class B_Radar_System_01_F;
class B_APC_Wheeled_01_cannon_F;
class rhsusf_m998_d_s_2dr_fulltop;
class cfgWeapons

{
	class PTF_weap_mastersafe: Default
	{
		scope = 1;
		displayName = "MASTERSAFE";
		descriptionShort = "MASTERSAFE";
		showToPlayer = 1;
		modes[] = {"this"};
		magazines[] = {};
		minRange = 0;
		minRangeProbab = 0.001;
		midRange = 0.001;
		midRangeProbab = 0.001;
		maxRange = 0.001;
		maxRangeProbab = 0.001;
	};
	class VehicleMagazine;
	class HighROF;
	class LowROF;
	class PTF_Vlmg_M240_veh: CUP_Vlmg_M240_veh
	{
		magazines[] = {"PTF_400rnd_TE1_Red_Tracer_762x51_M240_M"};
	};
	class PTF_weap_M242: CUP_Vacannon_M242_veh
	{
		muzzles[] = {"this","CUP_Vacannon_M242_veh_LAV25_SecondaryBin"};
		displayName = "$STR_CUP_DN_M242_PrimaryBin";
		ballisticsComputer = "1+16";
		canLock = 2;
		discreteDistance[] = {600};
		discreteDistanceInitIndex = 0;
		FCSZeroingDelay = 0.5;
		magazineReloadTime = 15;
		magazines[] = {"CUP_150Rnd_TE1_Red_Tracer_25mm_M242_APDS","CUP_150Rnd_TE1_Red_Tracer_25mm_M242_APFSDS","CUP_150Rnd_TE1_Red_Tracer_25mm_M242_HE"};
		class HighROF: HighROF
		{
			displayName = "$STR_CUP_DN_M242_PrimaryBin";
			reloadTime = 0.3;
			textureType = "fullAuto";
			showToPlayer = 1;
		};
		class LowROF: LowROF
		{
			displayName = "$STR_CUP_DN_M242_PrimaryBin";
			reloadTime = 0.6;
			textureType = "dual";
			showToPlayer = 1;
		};
		modes[] = {"LowROF","HighROF"};
		class CUP_Vacannon_M242_veh_LAV25_SecondaryBin: CUP_Vacannon_M242_veh
		{
			displayName = "$STR_CUP_DN_M242_SecondaryBin";
			ballisticsComputer = 16;
			canLock = 2;
			discreteDistance[] = {1000};
			discreteDistanceInitIndex = 0;
			FCSZeroingDelay = 0.5;
			magazineReloadTime = 8;
			magazines[] = {"CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APDS","CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APFSDS","CUP_60Rnd_TE1_Red_Tracer_25mm_M242_HE"};
			class HighROF: HighROF
			{
				displayName = "$STR_CUP_DN_M242_SecondaryBin";
				reloadTime = 0.3;
				textureType = "fullAuto";
				showToPlayer = 1;
			};
			class LowROF: LowROF
			{
				displayName = "$STR_CUP_DN_M242_SecondaryBin";
				reloadTime = 0.6;
				textureType = "dual";
				showToPlayer = 1;
			};
			modes[] = {"LowROF","HighROF"};
		};
	};
};
class cfgMagazines
{
	class PTF_400rnd_TE1_Red_Tracer_762x51_M240_M: VehicleMagazine
	{
		scope = 2;
		displayName = "M240";
		displayNameShort = "7.62x51mm";
		ammo = "B_762x51_Tracer_Red";
		initSpeed = 900;
		maxLeadSpeed = 200;
		nameSound = "mgun";
		count = 400;
		tracersEvery = 1;
	};
};
class cfgVehicles
{
	class PTF_Rhib: CUP_B_RHIB_USMC
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Boat";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "RHIB [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"cup\watervehicles\cup_watervehicles_rhib\data\rhib_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class MainTurret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.8;
						material = 60;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 0.6;
						material = 60;
						name = "zbran";
						visual = "zbran";
						passThrough = 1;
					};
				};
				stabilizedInAxes = 0;
				body = "MainTurret";
				gun = "MainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				gunnerAction = "gunner_standup01";
				gunnerGetInAction = "GetInMedium";
				gunnerGetOutAction = "GetOutMedium";
				ejectDeadGunner = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 0;
				minElev = -25;
				maxElev = 60;
				initElev = 0;
				minTurn = -135;
				maxTurn = 135;
				initTurn = 0;
				soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best","db-40",1,50};
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				weapons[] = {"CUP_Vhmg_M2_veh"};
				magazines[] = {"CUP_100Rnd_TE4_Red_Tracer_127x99_M","CUP_100Rnd_TE4_Red_Tracer_127x99_M","CUP_100Rnd_TE4_Red_Tracer_127x99_M"};
				gunnerName = "$STR_CUP_POSITION_Core_FFV_FG";
				gunnerOpticsModel = "\a3\weapons_f\Reticle\optics_empty";
				gunnerForceOptics = 0;
				startEngine = 0;
				commanding = 2;
				primaryGunner = 1;
				primaryObserver = 1;
				gunnerLeftHandAnimName = "OtocHlaven_shake";
				gunnerRightHandAnimName = "OtocHlaven_shake";
				turretInfoType = "RscOptics_Offroad_01";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex = 2;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
			};
		};
		class textureSources
		{
			class USMC
			{
				displayName = "USMC";
				author = "J.Downs";
				textures[] = {"cup\watervehicles\cup_watervehicles_rhib\data\rhib_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Rhib_Mk19: CUP_B_RHIB2Turret_USMC
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Boat";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "RHIB (Mk19) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo"};
		hiddenSelectionsTextures[] = {"cup\watervehicles\cup_watervehicles_rhib\data\rhib_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class MainTurret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				class HitPoints
				{
					class HitTurret
					{
						armor = 0.8;
						material = 60;
						name = "vez";
						visual = "vez";
						passThrough = 1;
					};
					class HitGun
					{
						armor = 0.6;
						material = 60;
						name = "zbran";
						visual = "zbran";
						passThrough = 1;
					};
				};
				stabilizedInAxes = 0;
				body = "MainTurret";
				gun = "MainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				gunnerAction = "gunner_standup01";
				gunnerGetInAction = "GetInMedium";
				gunnerGetOutAction = "GetOutMedium";
				ejectDeadGunner = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 0;
				minElev = -25;
				maxElev = 60;
				initElev = 0;
				minTurn = -135;
				maxTurn = 135;
				initTurn = 0;
				soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best","db-40",1,50};
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				weapons[] = {"CUP_Vhmg_M2_veh"};
				magazines[] = {"CUP_100Rnd_TE4_Red_Tracer_127x99_M","CUP_100Rnd_TE4_Red_Tracer_127x99_M","CUP_100Rnd_TE4_Red_Tracer_127x99_M"};
				gunnerName = "$STR_CUP_POSITION_Core_FFV_FG";
				gunnerOpticsModel = "\a3\weapons_f\Reticle\optics_empty";
				gunnerForceOptics = 0;
				startEngine = 0;
				commanding = 2;
				primaryGunner = 1;
				primaryObserver = 1;
				gunnerLeftHandAnimName = "OtocHlaven_shake";
				gunnerRightHandAnimName = "OtocHlaven_shake";
				turretInfoType = "RscOptics_Offroad_01";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex = 2;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewGunner
				{
					initAngleX = 0;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
			};
		};
		class textureSources
		{
			class USMC
			{
				displayName = "USMC";
				author = "J.Downs";
				textures[] = {"cup\watervehicles\cup_watervehicles_rhib\data\rhib_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Zodiac: CUP_B_Zodiac_USMC
	{
		scope = 2;
		vehicleClass = "Ship";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Boat";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "Zodiac [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo1"};
		hiddenSelectionsTextures[] = {"\A3\boat_F\Boat_Transport_01\data\boat_transport_01_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class CargoTurret_01: CargoTurret_01
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_02: CargoTurret_02
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_03: CargoTurret_03
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_04: CargoTurret_04
			{
				gunnerCompartments = "Compartment1";
			};
		};
		class textureSources
		{
			class USMC
			{
				displayName = "USMC";
				author = "J.Downs";
				textures[] = {"\A3\boat_F\Boat_Transport_01\data\boat_transport_01_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_LCU1600: CUP_B_LCU1600_USMC
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Boat";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "LCU-1610 [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo1","camo2","camo3","num_1","num_2","num_3","num_4"};
		hiddenSelectionsTextures[] = {"\cup\watervehicles\cup_watervehicles_lcu1600\data\lcu1600_1_co.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\lcu1600_2_co.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\lcu1600_3_co.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\hull_num_1_ca.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\hull_num_6_ca.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\hull_num_1_ca.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\hull_num_0_ca.paa"};
		class Turrets: Turrets{};
		class TextureSources
		{
			class USMC
			{
				displayName = "USMC";
				author = "J.Downs";
				factions[] = {};
				textures[] = {"\cup\watervehicles\cup_watervehicles_lcu1600\data\lcu1600_1_co.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\lcu1600_2_co.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\lcu1600_3_co.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\hull_num_1_ca.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\hull_num_6_ca.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\hull_num_1_ca.paa","\cup\watervehicles\cup_watervehicles_lcu1600\data\hull_num_0_ca.paa"};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 10;
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_limit_1","VTV_limit_2"};
				disableHeightLimit = 1;
				maxLoadMass = 200000;
				cargoAlignment[] = {"right","back"};
				cargoSpacing[] = {0,0,0};
				exits[] = {"VTV_exit_1"};
				unloadingInterval = 3;
				loadingDistance = 10;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 50;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_MKVSOC: rhsusf_mkvsoc
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Boat";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "Mk.V SOC [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo1"};
		hiddenselectionstextures[] = {"rhsusf\addons\rhsusf_markvsoc\data\hull_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class MainTurret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerType = "rhsusf_socom_swcc_crewman";
				stabilizedInAxes = 3;
				proxyType = "CPGunner";
				proxyindex = 1;
				body = "mainTurret";
				gun = "mainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				gunnerAction = "RHS_MKVSOC_Gunner";
				gunnerGetInAction = "";
				gunnerGetOutAction = "";
				gunnerReversedGetOut = 0;
				memoryPointsGetInGunner = "gunner_pos_s_m2";
				memoryPointsGetInGunnerDir = "gunner_dir_s_m2";
				ejectDeadGunner = 1;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				soundServo[] = {"A3\sounds_f\dummysound",0.0056234132,1};
				gunBeg = "m2_p_beginBarrel";
				gunEnd = "m2_p_endBarrel";
				weapons[] = {"RHS_MKV_M2_p"};
				magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red"};
				turretInfoType = "RHS_RscWeaponZeroing";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex = 2;
				gunnerName = "Port M2";
				memoryPointGunnerOptics = "m2_p_sight";
				gunnerLeftHandAnimName = "m2_p_hand_l";
				gunnerRightHandAnimName = "m2_p_hand_r";
				gunnerLeftLegAnimName = "m2_p_leg_l";
				gunnerRightLegAnimName = "m2_p_leg_r";
				gunnerOpticsModel = "a3\weapons_f\Reticle\optics_empty";
				gunnerForceOptics = 0;
				startEngine = 0;
				commanding = 0;
				primaryGunner = 0;
				primaryObserver = 0;
				usePip = 0;
				LODOpticsIn = 1000;
				LODOpticsOut = 1000;
				lodTurnedIn = 1000;
				lodTurnedOut = 1000;
				minElev = -45;
				maxElev = 45;
				initElev = 45;
				minTurn = 5;
				maxTurn = 145;
				initTurn = 65;
				class m2_p_ViewOptics: ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class m2_p_ViewGunner: ViewOptics
				{
					initAngleX = 5;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				disableSoundAttenuation = 1;
				maxHorizontalRotSpeed = 1.8;
				maxVerticalRotSpeed = 1.2;
				class HitPoints
				{
					class HitTurret1
					{
						isTurret = 1;
						armor = 0.8;
						material = 60;
						name = "hit_gunTurret_m2_1";
						visual = "gunTurret_m2_1";
						passThrough = 0;
					};
					class HitGun1
					{
						isGun = 1;
						armor = 0.6;
						material = 60;
						name = "hit_gunBarrel_m2_1";
						visual = "gunBarrel_m2_1";
						passThrough = 0;
					};
				};
			};
			class m2_s_gunTurret: MainTurret
			{
				gunnerCompartments = "Compartment1";
				proxyindex = 2;
				body = "m2_s_gunTurret";
				gun = "m2_s_gun";
				animationSourceBody = "m2_s_gunTurret";
				animationSourceGun = "m2_s_gun";
				gunnerAction = "RHS_MKVSOC_Gunner04";
				memoryPointsGetInGunner = "gunner_pos_p_m2";
				memoryPointsGetInGunnerDir = "gunner_dir_p_m2";
				gunBeg = "m2_s_beginBarrel";
				gunEnd = "m2_s_endBarrel";
				weapons[] = {"RHS_MKV_M2_s"};
				gunnerName = "Stbd M2";
				memoryPointGunnerOptics = "m2_s_sight";
				gunnerLeftHandAnimName = "m2_s_hand_l";
				gunnerRightHandAnimName = "m2_s_hand_r";
				gunnerLeftLegAnimName = "m2_s_leg_l";
				gunnerRightLegAnimName = "m2_s_leg_r";
				minElev = -45;
				maxElev = 45;
				initElev = 45;
				minTurn = -145;
				maxTurn = -5;
				initTurn = -65;
				class HitPoints
				{
					class HitTurret2
					{
						isTurret = 1;
						armor = 0.8;
						material = 60;
						name = "m2_s_turret";
						visual = "-";
						passThrough = 0;
					};
					class HitGun2
					{
						isGun = 1;
						armor = 0.6;
						material = 60;
						name = "m2_s_barrels";
						visual = "-";
						passThrough = 0;
					};
				};
			};
			class m134_p_gunTurret: MainTurret
			{
				gunnerCompartments = "Compartment1";
				proxyindex = 3;
				body = "m134_p_gunTurret";
				gun = "m134_p_gun";
				animationSourceBody = "m134_p_gunTurret";
				animationSourceGun = "m134_p_gun";
				gunnerAction = "RHS_MKVSOC_Gunner02";
				memoryPointsGetInGunner = "gunner_pos_m134";
				memoryPointsGetInGunnerDir = "gunner_dir_m134";
				gunBeg = "m134_p_beginBarrel";
				gunEnd = "m134_p_endBarrel";
				weapons[] = {"RHS_MKV_M134"};
				magazines[] = {"2000Rnd_762x51_Belt_T_Red","2000Rnd_762x51_Belt_T_Red"};
				discreteDistance[] = {300};
				discreteDistanceInitIndex = 2;
				gunnerName = "Port M134";
				memoryPointGunnerOptics = "m134_p_sight";
				gunnerLeftHandAnimName = "m134_p_hand_l";
				gunnerRightHandAnimName = "m134_p_hand_r";
				gunnerLeftLegAnimName = "m134_p_leg_l";
				gunnerRightLegAnimName = "m134_p_leg_r";
				minElev = -45;
				maxElev = 35;
				initElev = 45;
				minTurn = 35;
				maxTurn = 140;
				initTurn = 65;
				class m134_p_ViewOptics: ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class m134_p_ViewGunner: ViewOptics
				{
					initAngleX = 5;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				maxHorizontalRotSpeed = 1.8;
				maxVerticalRotSpeed = 1.2;
				class HitPoints
				{
					class HitTurret3
					{
						armor = 0.8;
						material = 60;
						name = "m134_p_turret";
						visual = "m134_p_gunTurret";
						passThrough = 0;
					};
					class HitGun3
					{
						armor = 0.6;
						material = 60;
						name = "m134_p_barrels";
						visual = "m134_p_gun";
						passThrough = 0;
					};
				};
			};
			class mk19_s_gunTurret: MainTurret
			{
				gunnerCompartments = "Compartment1";
				proxyindex = 4;
				body = "mk19_s_gunTurret";
				gun = "mk19_s_gun";
				animationSourceBody = "mk19_s_gunTurret";
				animationSourceGun = "mk19_s_gun";
				gunnerAction = "RHS_MKVSOC_Gunner03";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				memoryPointsGetInGunner = "gunner_pos_mk19";
				memoryPointsGetInGunnerDir = "gunner_dir_mk19";
				gunBeg = "mk19_s_beginBarrel";
				gunEnd = "mk19_s_endBarrel";
				weapons[] = {"RHS_MKV_MK19"};
				magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1"};
				discreteDistance[] = {300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex = 2;
				gunnerName = "Stbd Mk19";
				memoryPointGunnerOptics = "mk19_s_sight";
				gunnerLeftHandAnimName = "mk19_s_hand_l";
				gunnerRightHandAnimName = "mk19_s_hand_r";
				gunnerLeftLegAnimName = "mk19_s_leg_l";
				gunnerRightLegAnimName = "mk19_s_leg_r";
				minElev = -45;
				maxElev = 55;
				initElev = 45;
				minTurn = -137;
				maxTurn = -35;
				initTurn = -65;
				class mk19_s_ViewOptics: ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class mk19_s_ViewGunner: ViewOptics
				{
					initAngleX = 5;
					minAngleX = -65;
					maxAngleX = 85;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class HitPoints
				{
					class HitTurret4
					{
						isTurret = 1;
						armor = 0.8;
						material = 60;
						name = "m134_p_turret";
						visual = "m134_p_gunTurret";
						passThrough = 0;
					};
					class HitGun4
					{
						isGun = 1;
						armor = 0.6;
						material = 60;
						name = "m134_p_barrels";
						visual = "m134_p_gun";
						passThrough = 0;
					};
				};
			};
			class camera_b_gunTurret: MainTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerType = "rhsusf_socom_swcc_officer";
				stabilizedInAxes = 3;
				proxyType = "CPCommander";
				proxyindex = 1;
				body = "camera_b_gunTurret";
				gun = "camera_b_gun";
				animationSourceBody = "camera_b_gunTurret";
				animationSourceGun = "camera_b_gun";
				gunnerAction = "RHS_MKVSOC_Commander";
				gunnerGetInAction = "GetInMedium";
				gunnerGetOutAction = "GetOutMedium";
				ejectDeadGunner = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best",0.01,1,50};
				gunBeg = "axis_camera_b_dir";
				gunEnd = "axis_camera_b_pos";
				memoryPointGunnerOptics = "axis_camera_b_pos";
				memoryPointsGetInGunner = "comm_pos";
				memoryPointsGetInGunnerDir = "comm_dir";
				weapons[] = {"Laserdesignator_mounted"};
				magazines[] = {"Laserbatteries"};
				gunnerLeftHandAnimName = "cmdr_hand_l";
				gunnerRightHandAnimName = "cmdr_hand_r";
				gunnerLeftLegAnimName = "cmdr_leg_l";
				gunnerRightLegAnimName = "cmdr_leg_r";
				gunnerName = "Commander";
				gunnerOpticsModel = "\A3\weapons_f_beta\reticle\reticle_SDV";
				gunnerForceOptics = 0;
				startEngine = 0;
				commanding = 0;
				primaryGunner = 0;
				primaryObserver = 1;
				usePip = 1;
				laser = 1;
				minElev = -30;
				maxElev = 60;
				initElev = 60;
				minTurn = -180;
				maxTurn = 180;
				initTurn = 0;
				class camera_b_ViewOptics: ViewOptics
				{
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = -180;
					maxAngleY = 180;
					initFov = 0.14;
					minFov = 0.0175;
					maxFov = 0.14;
					visionMode[] = {"Normal","NVG","Ti"};
					thermalMode[] = {2,3,4};
				};
				class camera_b_ViewGunner: ViewOptics
				{
					initAngleX = -15;
					minAngleX = -45;
					maxAngleX = 45;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.9;
					minFov = 0.42;
					maxFov = 0.9;
					visionMode[] = {};
				};
				maxHorizontalRotSpeed = 1.8;
				maxVerticalRotSpeed = 1.2;
				class HitPoints{};
			};
			class rem_spotL_gunTurret: MainTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerType = "rhsusf_socom_swcc_officer";
				stabilizedInAxes = 4;
				proxyType = "CPCommander";
				proxyindex = 2;
				body = "rem_spotL_gunTurret";
				gun = "rem_spotL_gun";
				animationSourceBody = "rem_spotL_gunTurret";
				animationSourceGun = "rem_spotL_gun";
				gunnerAction = "RHS_MKVSOC_Commander02";
				gunnerGetInAction = "GetInMedium";
				gunnerGetOutAction = "GetOutMedium";
				ejectDeadGunner = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 0;
				soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best",0.2,1,1};
				gunBeg = "axis_rem_spotL_dir";
				gunEnd = "axis_rem_spotL_pos";
				memoryPointGunnerOptics = "rem_spotL_sight";
				memoryPointsGetInGunner = "gunner_pos";
				memoryPointsGetInGunnerDir = "gunner_dir";
				weapons[] = {};
				magazines[] = {};
				gunnerName = "Technician";
				gunnerOpticsModel = "a3\weapons_f\Reticle\optics_empty";
				gunnerForceOptics = 0;
				startEngine = 0;
				commanding = 0;
				primaryGunner = 0;
				primaryObserver = 0;
				usePip = 0;
				laser = 0;
				minElev = -7.5;
				maxElev = 60;
				initElev = 0;
				minTurn = -145;
				maxTurn = 145;
				initTurn = 0;
				class rem_spotL_ViewOptics: ViewOptics
				{
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.14;
					minFov = 0.0175;
					maxFov = 0.14;
					visionMode[] = {};
					thermalMode[] = {};
				};
				class rem_spotL_ViewGunner: ViewOptics
				{
					initAngleX = -15;
					minAngleX = -45;
					maxAngleX = 45;
					initAngleY = 0;
					minAngleY = -150;
					maxAngleY = 150;
					initFov = 0.9;
					minFov = 0.42;
					maxFov = 0.9;
					visionMode[] = {};
				};
				maxHorizontalRotSpeed = 1.8;
				maxVerticalRotSpeed = 1.2;
				class HitPoints{};
			};
		};
		class textureSources
		{
			class USMC
			{
				displayName = "USMC";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_markvsoc\data\hull_co.paa"};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_MRAP_CGRCAT1A2_MK19: rhsusf_CGRCAT1A2_Mk19_usmc_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_MRAP";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 750;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "CGRCAT1A2 (Mk19) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","pintle"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_WD_CO.paa","rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa","rhsusf\addons\rhsusf_rg33l\data\MCTAGS_WD_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class M2_Turret: MainTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerLeftHandAnimName = "OtocHlaven";
				gunnerRightHandAnimName = "OtocHlaven";
				gunnerLeftLegAnimName = "gunner_legs";
				gunnerRightLegAnimName = "gunner_legs";
				body = "mainTurret";
				gun = "mainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				animationSourceStickX = "MainTurret_Inertia";
				animationSourceStickY = "MainGun_Inertia";
				turretInfoType = "RHS_RscWeaponZeroing_TurretAdjust";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex = 2;
				gunnerForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				weapons[] = {"RHS_MK19"};
				magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M1001","RHS_48Rnd_40mm_MK19_M1001","RHS_48Rnd_40mm_MK19_M1001"};
				minElev = -10;
				maxElev = 40;
				soundServo[] = {"A3\sounds_f\dummysound",1e-06,1};
				gunnerAction = "RHS_MCTAGS_Gunner03";
				gunnerInAction = "RHS_MCTAGS_Gunner03_in";
				lodTurnedIn = 0;
				lodTurnedOut = 1000;
				lodOpticsOut = 1000;
				canhideGunner = 1;
				inGunnerMayFire = 0;
				outGunnerMayFire = 1;
				viewGunnerInExternal = 1;
				gunnerGetInAction = "GetInMRAP_01_cargo";
				gunnerGetOutAction = "GetOutMRAP_01";
				gunnerDoor = "DoorR";
				ejectDeadGunner = 0;
				castGunnerShadow = 1;
				stabilizedInAxes = 0;
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGunnerOptics = "";
				memoryPointGunnerOutOptics = "gunnerview";
				gunnerOpticsModel = "";
				gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
				optics = 0;
				disableSoundAttenuation = 1;
				memoryPointsGetInGunner = "pos codriver";
				memoryPointsGetInGunnerDir = "pos codriver dir";
				class ViewOptics: ViewOptics
				{
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewGunner: ViewOptics{};
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				weapons[] = {"rhsusf_weap_DummyLauncher"};
				gunnerAction = "rhs_cougar_turnout_1";
				gunnerInAction = "RHS_cougar_Cargo01_FFV";
				animationSourceHatch = "hatch1";
				enabledByAnimationSource = "hatch1_door";
				isPersonTurret = 2;
				gunnerGetInAction = "GetInMantis";
				gunnerGetOutAction = "GetOutMantis";
				memoryPointsGetInGunner = "pos cargoFFV1";
				memoryPointsGetInGunnerDir = "pos cargoFFV1 dir";
				rhs_hatch_control = 1;
				gunnerName = "Passenger (Rear Hatch)";
				gunnerDoor = "DoorB";
				memoryPointGunnerOptics = "";
				selectionFireAnim = "";
				canHideGunner = 1;
				commanding = -2;
				LODTurnedIn = 1200;
				LODTurnedOut = 0;
				proxyIndex = 4;
				maxElev = 45;
				minElev = -35;
				maxTurn = 61;
				minTurn = -65;
				class TurnIn
				{
					limitsArrayTop[] = {{0,0},{0,0}};
					limitsArrayBottom[] = {{0,0},{0,0}};
				};
				class TurnOut
				{
					limitsArrayTop[] = {{45,-90.1745},{44.9894,80.629}};
					limitsArrayBottom[] = {{5.464,-89.894},{-9.4602,-71.7306},{-7.5523,-40.9866},{-16.3809,-30.7844},{-7.1172,-30.2764},{-13.0122,-5.9314},{-12.7133,26.3332},{-23.1407,58.6419},{-8.5688,77.4948},{-7.292,80.6933}};
				};
				class Hitpoints{};
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\cgrcat\CGR_Body_s_CO.paa","rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa","PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa","PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_CO.paa","rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa","rhsusf\addons\rhsusf_rg33l\data\MCTAGS_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_WD_CO.paa","rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa","rhsusf\addons\rhsusf_rg33l\data\MCTAGS_WD_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_MRAP_CGRCAT1A2_M2: rhsusf_CGRCAT1A2_M2_usmc_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_MRAP";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 750;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "CGRCAT1A2 (M2) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","pintle"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_WD_CO.paa","rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa","rhsusf\addons\rhsusf_rg33l\data\MCTAGS_WD_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class M2_Turret: MainTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerLeftHandAnimName = "OtocHlaven_Shake";
				gunnerRightHandAnimName = "OtocHlaven_Shake";
				gunnerLeftLegAnimName = "gunner_legs";
				gunnerRightLegAnimName = "gunner_legs";
				body = "mainTurret";
				gun = "mainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				animationSourceStickX = "MainTurret_Inertia";
				animationSourceStickY = "MainGun_Inertia";
				turretInfoType = "RHS_RscWeaponZeroing_TurretAdjust";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex = 2;
				gunnerForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				weapons[] = {"RHS_M2"};
				magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red"};
				minElev = -10;
				maxElev = 40;
				soundServo[] = {"A3\sounds_f\dummysound",1e-06,1};
				gunnerAction = "RHS_MCTAGS_Gunner03";
				gunnerInAction = "RHS_MCTAGS_Gunner03_in";
				lodTurnedIn = 0;
				lodTurnedOut = 1000;
				lodOpticsOut = 1000;
				canhideGunner = 1;
				inGunnerMayFire = 0;
				outGunnerMayFire = 1;
				viewGunnerInExternal = 1;
				gunnerGetInAction = "GetInMRAP_01_cargo";
				gunnerGetOutAction = "GetOutMRAP_01";
				gunnerDoor = "DoorR";
				ejectDeadGunner = 0;
				castGunnerShadow = 1;
				stabilizedInAxes = 0;
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGunnerOptics = "";
				memoryPointGunnerOutOptics = "gunnerview";
				gunnerOpticsModel = "";
				gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
				optics = 0;
				disableSoundAttenuation = 1;
				memoryPointsGetInGunner = "pos codriver";
				memoryPointsGetInGunnerDir = "pos codriver dir";
				class ViewOptics: ViewOptics
				{
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewGunner: ViewOptics{};
			};
			class CargoTurret_01: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				weapons[] = {"rhsusf_weap_DummyLauncher"};
				gunnerAction = "rhs_cougar_turnout_1";
				gunnerInAction = "RHS_cougar_Cargo01_FFV";
				animationSourceHatch = "hatch1";
				enabledByAnimationSource = "hatch1_door";
				isPersonTurret = 2;
				gunnerGetInAction = "GetInMantis";
				gunnerGetOutAction = "GetOutMantis";
				memoryPointsGetInGunner = "pos cargoFFV1";
				memoryPointsGetInGunnerDir = "pos cargoFFV1 dir";
				rhs_hatch_control = 1;
				gunnerName = "Passenger (Rear Hatch)";
				gunnerDoor = "DoorB";
				memoryPointGunnerOptics = "";
				selectionFireAnim = "";
				canHideGunner = 1;
				commanding = -2;
				LODTurnedIn = 1200;
				LODTurnedOut = 0;
				proxyIndex = 4;
				maxElev = 45;
				minElev = -35;
				maxTurn = 61;
				minTurn = -65;
				class TurnIn
				{
					limitsArrayTop[] = {{0,0},{0,0}};
					limitsArrayBottom[] = {{0,0},{0,0}};
				};
				class TurnOut
				{
					limitsArrayTop[] = {{45,-90.1745},{44.9894,80.629}};
					limitsArrayBottom[] = {{5.464,-89.894},{-9.4602,-71.7306},{-7.5523,-40.9866},{-16.3809,-30.7844},{-7.1172,-30.2764},{-13.0122,-5.9314},{-12.7133,26.3332},{-23.1407,58.6419},{-8.5688,77.4948},{-7.292,80.6933}};
				};
				class Hitpoints{};
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\cgrcat\CGR_Body_s_CO.paa","rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa","PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa","PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_CO.paa","rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa","rhsusf\addons\rhsusf_rg33l\data\MCTAGS_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_WD_CO.paa","rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa","rhsusf\addons\rhsusf_rg33l\data\MCTAGS_WD_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_F450: d3s_fseries_LTD_17
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Cars";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "F450 [PTF]";
		crew = "B_Pilot_F";
		maxSpeed = 100;
		enginePower = 350;
		peakTorque = 350;
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo9","camo10","camo11","camo12","camo13","camo14","camo15","camo16","camo17","camo18","camo19","camo20","license1","license2","license3","license4","license5","license6","license7"};
		hiddenSelectionsTextures[] = {"d3s_fseries_15\data\f450.paa","d3s_fseries_15\data\base.paa","d3s_cars_core\data\glass_black.paa","d3s_cars_core\data\glass.paa","d3s_fseries_15\data\wheel.paa","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
		class Turrets: Turrets{};
		class textureSources
		{
			class S7
			{
				displayname = "S7";
				author = "J.Downs";
				textures[] = {"\PTF_Textures\vehicles\f450\f450_s7training.paa","d3s_fseries_15\data\base.paa","d3s_fseries_15\data\Window.paa","d3s_cars_core\data\glass.paa","d3s_fseries_15\data\wheel.paa","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
				factions[] = {};
			};
			class MAG36
			{
				displayname = "MAG36";
				author = "J.Downs";
				textures[] = {"\PTF_Textures\vehicles\f450\f450_airoperations.paa","d3s_fseries_15\data\base.paa","d3s_fseries_15\data\Window.paa","d3s_cars_core\data\glass.paa","d3s_fseries_15\data\wheel.paa","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_F450_Tow: d3s_fseries_17_TOW
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Utility";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "F450 (Tow) [PTF]";
		crew = "B_Pilot_F";
		maxSpeed = 100;
		enginePower = 350;
		peakTorque = 350;
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo9","camo10","camo11","camo12","camo13","camo14","camo15","camo16","camo17","camo18","camo19","camo20","license1","license2","license3","license4","license5","license6","license7"};
		hiddenSelectionsTextures[] = {"\PTF_Textures\vehicles\f450\f550_tow.paa","d3s_fseries_15\data\gmc_6500_base.paa","d3s_fseries_15\data\Wheel.paa","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
		class Turrets: Turrets{};
		class textureSources
		{
			class Tow
			{
				displayname = "Tow";
				author = "J.Downs";
				textures[] = {"\PTF_Textures\vehicles\f450\f550_tow.paa","d3s_fseries_15\data\gmc_6500_base.paa","d3s_fseries_15\data\Wheel.paa","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 10;
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_limit_1","VTV_limit_2"};
				disableHeightLimit = 1;
				maxLoadMass = 6500;
				cargoAlignment[] = {"front","center"};
				cargoSpacing[] = {0,0.15,0};
				exits[] = {"VTV_exit_1"};
				unloadingInterval = 2;
				loadingDistance = 10;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 50;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_F450_EMS: d3s_fseries_17_EMS
	{
		displayName = "F450 (EMS) [PTF]";
		crew = "B_Pilot_F";
		side = 1;
		scope = 2;
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Utility";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo9","camo10","camo11","camo12","camo13","camo14","camo15","camo16","camo17","camo18","camo19","camo20","license1","license2","license3","license4","license5","license6","license7"};
		hiddenSelectionsTextures[] = {"PTF_Textures\vehicles\f450\ems\front.paa","PTF_Textures\vehicles\f450\ems\back.paa","d3s_fseries_15\data\Wheel.paa","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
		class Turrets: Turrets{};
		class textureSources
		{
			class EMS
			{
				displayname = "EMS";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\f450\ems\front.paa","PTF_Textures\vehicles\f450\ems\back.paa","d3s_fseries_15\data\Wheel.paa","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
				factions[] = {};
			};
			class Cancer
			{
				displayname = "Cancer Awareness Month";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\f450\ems\fp5.paa","PTF_Textures\vehicles\f450\ems\bp1.paa","d3s_fseries_15\data\Wheel.paa","","","","","","","","","","","","","","","","","","","","","","","","","","","","","","",""};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 10;
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_limit_1","VTV_limit_2"};
				disableHeightLimit = 1;
				maxLoadMass = 1000;
				cargoAlignment[] = {"front","center"};
				cargoSpacing[] = {0,0.15,0};
				exits[] = {"VTV_exit_1"};
				unloadingInterval = 2;
				loadingDistance = 10;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 50;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1085A1P2: rhsusf_M1085A1P2_B_WD_Medical_fmtv_usarmy
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Utility";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1085A1P2 [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo9","camo10","camo11","camo12","camo13","camo14","camo15","camo16","camo17","camo18","camo19"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Desert
			{
				displayName = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_d_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_D_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovchassis_co.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovcab_co.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1078A1P2: rhsusf_M1078A1P2_WD_fmtv_usarmy
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Cars";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 1500;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1078A1P2 [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo9","camo10","camo11","camo12","camo13","camo14","camo15","camo16","camo17","camo18","camo19"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class CargoTurret_01: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerAction = "passenger_inside_2";
				gunnerGetInAction = "GetInHemttBack";
				gunnerGetOutAction = "GetOutHighZamak";
				memoryPointsGetInGunner = "pos cargo LR";
				memoryPointsGetInGunnerDir = "pos cargo LR dir";
				gunnerName = "Passenger (Left Seat)";
				proxyIndex = 12;
				maxElev = 15;
				minElev = -15;
				maxTurn = -40;
				minTurn = -115;
				isPersonTurret = 1;
				selectionFireAnim = "";
				commanding = -2;
				class Hitpoints{};
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerCompartments = "Compartment1";
				gunnerName = "Passenger (Right Seat)";
				memoryPointsGetInGunner = "pos cargo RR";
				memoryPointsGetInGunnerDir = "pos cargo RR dir";
				proxyIndex = 11;
				maxTurn = 95;
				minTurn = 20;
				minElev = -45;
			};
		};
		class textureSources
		{
			class Desert
			{
				displayName = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_d_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_D_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovchassis_co.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovcab_co.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1078A1P2_M2: rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_ArmedCars";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 1500;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1078A1P2 (M2) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo9","camo10","camo11","camo12","camo13","camo14","camo15","camo16","camo17","camo18","camo19"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class M2_Turret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerLeftHandAnimName = "OtocHlaven_Shake";
				gunnerRightHandAnimName = "OtocHlaven_Shake";
				gunnerLeftLegAnimName = "gunner_legs";
				gunnerRightLegAnimName = "gunner_legs";
				body = "mainTurret";
				gun = "mainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				animationSourceStickX = "MainTurret_Inertia";
				animationSourceStickY = "MainGun_Inertia";
				turretInfoType = "RHS_RscWeaponZeroing_TurretAdjust";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex = 2;
				gunnerForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				weapons[] = {"RHS_M2"};
				magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red"};
				minElev = -10;
				maxElev = 40;
				soundServo[] = {"A3\sounds_f\dummysound",0.01,1,10};
				soundServoVertical[] = {"A3\sounds_f\dummysound",0.01,1,10};
				soundAttenuationTurret = "HeliAttenuationGunner";
				disableSoundAttenuation = 0;
				gunnerAction = "RHS_HMMWV_Gunner03";
				gunnerInAction = "RHS_HMMWV_Gunner03_in";
				lodTurnedIn = 0;
				lodTurnedOut = 1000;
				lodOpticsOut = 1000;
				canhideGunner = 1;
				inGunnerMayFire = 0;
				outGunnerMayFire = 1;
				viewGunnerInExternal = 1;
				gunnerGetInAction = "GetInMRAP_01_cargo";
				gunnerGetOutAction = "GetOutMRAP_01";
				gunnerDoor = "Door_RF";
				ejectDeadGunner = 0;
				castGunnerShadow = 1;
				stabilizedInAxes = 0;
				startEngine = 0;
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGunnerOptics = "";
				memoryPointGunnerOutOptics = "gunnerview";
				gunnerOpticsModel = "";
				gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
				optics = 0;
				memoryPointsGetInGunner = "pos codriver";
				memoryPointsGetInGunnerDir = "pos codriver dir";
				class ViewOptics: ViewOptics
				{
					initFov = 0.7;
					minFov = 0.25;
					maxFov = 1.1;
				};
				class ViewGunner: ViewOptics{};
			};
			class CargoTurret_01: CargoTurret_01
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_02: CargoTurret_02
			{
				gunnerCompartments = "Compartment1";
			};
		};
		class textureSources
		{
			class Desert
			{
				displayName = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_d_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_D_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_D_CO.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovchassis_co.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovcab_co.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa","rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa","rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Atlas: boxloader_atlas
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		maxSpeed = 20;
		fuelCapacity = 10;
		author = "Paramarine Task Force";
		displayName = "Atlas Forklift [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"#(rgb,8,8,3)color(0.2,0.235,0.184,1,co)"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"#(rgb,8,8,3)color(0.2,0.235,0.184,1,co)"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"#(rgb,8,8,3)color(0.498,0.4313,0.352,1,co)"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {"VTV_Cargo_Base","VTV_Cargo_Corner"};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 1;
				parachuteHeightLimit = 15;
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_Carrier_Base","VTV_Carrier_Corner"};
				cargoSpacing[] = {0,0,0};
				cargoAlignment[] = {"back","center"};
				maxLoadMass = 12000;
				disableHeightLimit = 1;
				exits[] = {"VTV_exit_1"};
				unloadingInterval = 2;
				loadingDistance = 10;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Kalmar: boxloader_kalmar
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		maxSpeed = 20;
		fuelCapacity = 10;
		author = "Paramarine Task Force";
		displayName = "Kalmar Forklift [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"#(rgb,8,8,3)color(0.498,0.4313,0.352,1,co)"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"#(rgb,8,8,3)color(0.2,0.235,0.184,1,co)"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"#(rgb,8,8,3)color(0.498,0.4313,0.352,1,co)"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {"VTV_Cargo_Base","VTV_Cargo_Corner"};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 1;
				parachuteHeightLimit = 15;
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_Carrier_Base","VTV_Carrier_Corner"};
				cargoSpacing[] = {0,0,0};
				cargoAlignment[] = {"back","center"};
				maxLoadMass = 8000;
				disableHeightLimit = 1;
				exits[] = {"VTV_exit_1"};
				unloadingInterval = 2;
				loadingDistance = 10;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M977A4_M2: rhsusf_M977A4_REPAIR_BKIT_M2_usarmy_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Utility";
		ace_cargo_space = 20;
		ace_cargo_hasCargo = 1;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		ace_repair_canRepair = 0;
		maximumLoad = 10000;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M977A4 (M2/Cargo) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		HiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\BKIT_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CARGO_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M977A4_Refuel: rhsusf_M978A4_usarmy_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		transportFuel = 22000;
		author = "Paramarine Task Force";
		displayName = "M977A4 (Refuel) [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo","Camo3","Camo5"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO_Des.paa","rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_DES_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_DES_CO.paa"};
			};
			factions[] = {};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 15;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M977A4_Repair: rhsusf_M977A4_REPAIR_usarmy_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M977A4 (Repair) [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo","Camo3","Camo5"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CARGO_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO_Des.paa","rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_DES_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_DES_CO.paa"};
			};
			factions[] = {};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 15;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M977A4_Ammo: rhsusf_M977A4_AMMO_usarmy_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M977A4 (Ammo) [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo","Camo3","Camo5"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CARGO_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO_Des.paa","rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_DES_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_DES_CO.paa"};
			};
			factions[] = {};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 15;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1151: rhsusf_m1151_usmc_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Cars";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 750;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1151 [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6","BFT_screen"};
		hiddenSelectionTextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class CoDriverTurret: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				showAsCargo = 1;
				lodTurnedIn = 1100;
				lodTurnedOut = 1100;
				gunnerForceOptics = 0;
				gunnerName = "Co-driver";
				proxyIndex = 1;
				isPersonTurret = 0;
				gunnerAction = "RHS_M11XX_CoDriver";
				gunnerinAction = "RHS_M11XX_CoDriver";
				memoryPointsGetInGunner = "pos codriver";
				memoryPointsGetInGunnerDir = "pos codriver dir";
				gunnerDoor = "Door_RF";
				turretInfoType = "RHS_RscMATV_Codriver";
				selectionFireAnim = "";
				class Hitpoints{};
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\m115x\m1151_s_CO.paa","PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				hiddenselectionstextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_cargo_1","VTV_cargo_2"};
				disableHeightLimit = 1;
				maxLoadMass = 1500;
				cargoAlignment[] = {"center","front"};
				cargoSpacing[] = {0,0,0};
				exits[] = {"VTV_exit"};
				unloadingInterval = 2;
				loadingDistance = 3;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 5;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1151_MK19: rhsusf_m1151_mk19_v3_usmc_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_ArmedCars";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 750;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1151 (Mk19) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo19","BFT_screen"};
		hiddenSelectionTextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class MCTAGS_Turret: MCTAGS_Turret
			{
				gunnerCompartments = "Compartment1";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex = 2;
				gunnerLeftHandAnimName = "OtocHlaven";
				gunnerRightHandAnimName = "OtocHlaven";
				weapons[] = {"RHS_MK19"};
				magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M1001","RHS_48Rnd_40mm_MK19_M1001","RHS_48Rnd_40mm_MK19_M1001"};
			};
			class CoDriverTurret: CoDriverTurret
			{
				gunnerCompartments = "Compartment1";
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\m115x\m1151_s_CO.paa","PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa","PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa","PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				hiddenselectionstextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa","rhsusf\addons\rhsusf_rg33l\data\mctags_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_cargo_1","VTV_cargo_2"};
				disableHeightLimit = 1;
				maxLoadMass = 1500;
				cargoAlignment[] = {"center","front"};
				cargoSpacing[] = {0,0,0};
				exits[] = {"VTV_exit"};
				unloadingInterval = 2;
				loadingDistance = 3;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 5;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1151_M240: rhsusf_m1151_m240_v3_usmc_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_ArmedCars";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 750;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1151 (M240) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo19","BFT_screen"};
		hiddenSelectionTextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_wd_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class MCTAGS_Turret: MCTAGS_Turret
			{
				gunnerCompartments = "Compartment1";
				gunnerAction = "RHS_MATV_Gunner_M240";
				gunnerInAction = "RHS_HMMWV_Gunner03_in";
				gunnerLeftHandAnimName = "OtocHlaven";
				gunnerRightHandAnimName = "OtocHlaven";
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500};
				discreteDistanceInitIndex = 2;
				selectionFireAnim = "zasleh";
				memoryPointGunnerOptics = "gunnerview";
				memoryPointGunnerOutOptics = "gunnerview";
				minElev = -18;
				maxElev = 40;
				weapons[] = {"rhs_weap_m240_m113"};
				magazines[] = {"rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200","rhs_mag_762x51_M240_200"};
			};
			class CoDriverTurret: CoDriverTurret
			{
				gunnerCompartments = "Compartment1";
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\m115x\m1151_s_CO.paa","PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa","PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa","PTF_Textures\vehicles\m115x\mk64mount_s_co.paa","PTF_Textures\vehicles\m115x\m11165a1_gmv_h246mount_s_co.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				hiddenselectionstextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa","rhsusf\addons\rhsusf_rg33l\data\mctags_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa","rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_des_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_wd_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_cargo_1","VTV_cargo_2"};
				disableHeightLimit = 1;
				maxLoadMass = 1500;
				cargoAlignment[] = {"center","front"};
				cargoSpacing[] = {0,0,0};
				exits[] = {"VTV_exit"};
				unloadingInterval = 2;
				loadingDistance = 3;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 5;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1151_M2: rhsusf_m1151_m2_v3_usmc_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_ArmedCars";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 750;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1151 (M2) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo19","BFT_screen"};
		hiddenSelectionTextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class MCTAGS_Turret: MCTAGS_Turret
			{
				gunnerCompartments = "Compartment1";
				discreteDistance[] = {100,200,300,400,500,600,800,1000,1200,1500};
				discreteDistanceInitIndex = 2;
				gunnerLeftHandAnimName = "OtocHlaven";
				gunnerRightHandAnimName = "OtocHlaven";
				weapons[] = {"RHS_M2"};
				magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red"};
			};
			class CoDriverTurret: CoDriverTurret
			{
				gunnerCompartments = "Compartment1";
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\m115x\m1151_s_CO.paa","PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa","PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa","PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				hiddenselectionstextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa","rhsusf\addons\rhsusf_rg33l\data\mctags_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_cargo_1","VTV_cargo_2"};
				disableHeightLimit = 1;
				maxLoadMass = 1500;
				cargoAlignment[] = {"center","front"};
				cargoSpacing[] = {0,0,0};
				exits[] = {"VTV_exit"};
				unloadingInterval = 2;
				loadingDistance = 3;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 5;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1151_M2_LRAS: rhsusf_m1151_m2_lras3_v1_usarmy_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_ArmedCars";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 750;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1151 (M2\LRAS) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6","camo7","camo8","camo10","BFT_screen"};
		hiddenSelectionTextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_GPK_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_stryker\data\rhsusf_lras3_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class GPK_Turret: GPK_Turret
			{
				gunnerCompartments = "Compartment1";
				gunnerName = "Gunner";
				gunnerAction = "RHS_M11XX_LRAS_Gunner1_out";
				gunnerInAction = "RHS_M11XX_LRAS_Gunner1_in";
				gunnerForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				viewGunnerInExternal = 1;
				LODTurnedOut = 1000;
				LODTurnedin = 1000;
				LODOpticsIn = 0;
				LODOpticsOut = 0;
				animationSourceHatch = "Hatch_Gunner_A";
				castGunnerShadow = 1;
				stabilizedInAxes = 0;
				startEngine = 0;
				usePip = 0;
				weapons[] = {};
				magazines[] = {};
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				gunBeg = "";
				gunEnd = "";
				memoryPointGunnerOptics = "";
				memoryPointGunnerOutOptics = "gunnerview";
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				selectionFireAnim = "";
				gunnerOpticsModel = "";
				gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
				optics = 0;
				disableSoundAttenuation = 0;
			};
			class Turret_Weapon: GPK_Turret
			{
				gunnerCompartments = "Compartment1";
				soundServo[] = {"",0.398107,1,30};
				soundServoVertical[] = {"",0.398107,1,30};
				gunnerName = "Turret (M2)";
				gunnerDoor = "";
				gunnerAction = "RHS_M11XX_LRAS_Gunner2";
				isPersonTurret = 0;
				dontCreateAI = 1;
				personturretAction = "";
				proxyIndex = 2;
				canHideGunner = 0;
				initTurn = -20;
				minTurn = -180;
				maxTurn = 180;
				minElev = -9;
				maxElev = 30;
				maxhorizontalrotspeed = 0.6;
				maxverticalrotspeed = 0.44;
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				LODTurnedOut = 1000;
				LODTurnedin = 1000;
				LODOpticsIn = 1000;
				LODOpticsOut = 1000;
				body = "Weapon_Turret";
				gun = "Weapon_Gun";
				animationSourceBody = "Weapon_Turret";
				animationSourceGun = "Weapon_Gun";
				gunnerLeftHandAnimName = "Weapon_Gun";
				gunnerRightHandAnimName = "Weapon_Gun";
				gunnerLeftLegAnimName = "Gunner_Weapon_Legs";
				gunnerRightLegAnimName = "Gunner_Weapon_Legs";
				animationSourceStickX = "Weapon_Turret_inertia";
				animationSourceStickY = "Weapon_Gun_Inertia";
				gunBeg = "usti hlavne";
				gunEnd = "konec hlavne";
				memoryPointGunnerOutOptics = "Weapon_GunnerView";
				selectionFireAnim = "muzzleFlash";
				discreteDistance[] = {100,150,200,250,300,350,400,450,500,550,600,650,700,750,800,850,900,950,1000,1050,1100,1150,1200,1250,1300,1350,1400,1450,1500,1550,1600,1650,1700,1750,1800,1850,1900,1950,2000};
				discreteDistanceInitIndex = 2;
				weapons[] = {"RHS_M2"};
				magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red"};
				class ViewGunner: ViewOptics
				{
					initAngleX = -1;
					initAngleY = 0;
					initFov = 0.9;
					minFov = 0.25;
					maxFov = 1.25;
					minAngleX = -65;
					maxAngleX = 85;
					minAngleY = -150;
					maxAngleY = 150;
					minMoveX = -0.075;
					maxMoveX = 0.075;
					minMoveY = -0.075;
					maxMoveY = 0.075;
					minMoveZ = -0.075;
					maxMoveZ = 0.1;
				};
				class Hitpoints
				{
					class HitTurret_M2
					{
						armor = -120;
						minimalHit = -0.13;
						explosionShielding = 0.5;
						name = "Hit_M2_Turret";
						visual = "-";
						armorComponent = "Hit_M2_Turret";
						passThrough = 0;
						radius = 0.2;
					};
					class HitGun_M2
					{
						armor = -120;
						minimalHit = -0.13;
						explosionShielding = 0.5;
						name = "Hit_M2_Gun";
						visual = "-";
						armorComponent = "Hit_M2_Gun";
						passThrough = 0;
						radius = 0.2;
					};
				};
			};
			class Turret_LRAS: Turret_Weapon
			{
				gunnerCompartments = "Compartment1";
				gunnerName = "Turret (LRAS3)";
				gunnerAction = "RHS_M11XX_LRAS_Gunner3";
				proxyIndex = 3;
				initTurn = 20;
				minTurn = -180;
				maxTurn = 180;
				minElev = -20;
				maxElev = 30;
				inGunnerMayFire = 1;
				outGunnerMayFire = 1;
				gunnerForceOptics = 0;
				body = "LRAS3_Turret";
				gun = "LRAS3_Gun";
				animationSourceBody = "LRAS3_Turret";
				animationSourceGun = "LRAS3_Gun";
				gunnerLeftHandAnimName = "LRAS3";
				gunnerRightHandAnimName = "LRAS3";
				gunnerLeftLegAnimName = "Gunner_LRAS_Legs";
				gunnerRightLegAnimName = "Gunner_LRAS_Legs";
				animationSourceStickX = "";
				animationSourceStickY = "";
				memoryPointGunnerOutOptics = "LRAS3_GunnerView";
				gunBeg = "LRAS3_GunnerView_Dir";
				gunEnd = "LRAS3_GunnerView";
				selectionFireAnim = "";
				weapons[] = {"rhs_weap_laserDesignator_AI"};
				magazines[] = {"rhs_LaserMag_ai"};
				class ViewGunner: ViewOptics
				{
					initAngleX = -5;
					initAngleY = 0;
					initFov = 0.9;
					minFov = 0.25;
					maxFov = 1.25;
					minAngleX = -65;
					maxAngleX = 85;
					minAngleY = -150;
					maxAngleY = 150;
					minMoveX = -0.075;
					maxMoveX = 0.075;
					minMoveY = -0.075;
					maxMoveY = 0.075;
					minMoveZ = -0.075;
					maxMoveZ = 0.1;
				};
				class Components{};
				gunnerOutOpticsModel = "\rhsusf\addons\rhsusf_optics\data\rhsusf_LRAS3";
				turretInfoType = "RHS_RscLRAS3";
				class OpticsIn
				{
					class Wide: ViewOptics
					{
						opticsDisplayName = "4";
						initFov = 0.175;
						minFov = 0.175;
						maxFov = 0.175;
						visionMode[] = {"TI"};
						thermalMode[] = {2,3};
						gunnerOpticsModel = "\rhsusf\addons\rhsusf_optics\data\rhsusf_CITV_w";
						hitpoint = "Hit_Optic_LRAS3";
					};
					class WideZoom: Wide
					{
						opticsDisplayName = "8";
						initFov = 0.0875;
						minFov = 0.0875;
						maxFov = 0.0875;
					};
					class Narrow: Wide
					{
						opticsDisplayName = "12";
						initFov = 0.0583333;
						minFov = 0.0583333;
						maxFov = 0.0583333;
					};
					class NarrowZoom: Wide
					{
						opticsDisplayName = "24";
						initFov = 0.0291667;
						minFov = 0.0291667;
						maxFov = 0.0291667;
					};
					class NarrowDoubleZoom: Wide
					{
						opticsDisplayName = "48";
						initFov = 0.0145833;
						minFov = 0.0145833;
						maxFov = 0.0145833;
					};
				};
				class OpticsOut
				{
					class Wide: ViewOptics
					{
						initFov = 0.9;
						minFov = 0.25;
						maxFov = 1.25;
						gunnerOpticsModel = "\rhsusf\addons\rhsusf_optics\data\rhsusf_LRAS3";
						hitpoint = "Hit_Optic_LRAS3";
					};
				};
				class Hitpoints
				{
					class HitTurret_LRAS3
					{
						armor = -120;
						minimalHit = -0.13;
						explosionShielding = 0.5;
						name = "Hit_LRAS3_Turret";
						visual = "vis_LRAS3_Turret";
						armorComponent = "Hit_LRAS3_Turret";
						passThrough = 0;
						radius = 0.1;
					};
					class HitGun_LRAS3
					{
						armor = -120;
						minimalHit = -0.13;
						explosionShielding = 0.5;
						name = "Hit_LRAS3_Gun";
						visual = "vis_LRAS3_Gun";
						armorComponent = "Hit_LRAS3_Gun";
						passThrough = 0;
						radius = 0.1;
					};
				};
			};
			class CoDriverTurret: CoDriverTurret
			{
				gunnerCompartments = "Compartment1";
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\m115x\m1151_s_CO.paa","PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\M1152M1165_d_CO.paa","PTF_Textures\vehicles\m115x\M1151_GPK_s_CO.paa","PTF_Textures\vehicles\m115x\mk64mount_s_co.paa","PTF_Textures\vehicles\m115x\lras3_s_co.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				hiddenselectionstextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_GPK_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa","rhsusf\addons\rhsusf_stryker\data\rhsusf_lras3_d_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_GPK_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_stryker\data\rhsusf_lras3_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_cargo_1","VTV_cargo_2"};
				disableHeightLimit = 1;
				maxLoadMass = 1500;
				cargoAlignment[] = {"center","front"};
				cargoSpacing[] = {0,0,0};
				exits[] = {"VTV_exit"};
				unloadingInterval = 2;
				loadingDistance = 3;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 5;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1152: rhsusf_m1152_rsv_usmc_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Cars";
		ace_cargo_space = 10;
		ace_cargo_hasCargo = 1;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 5000;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1152 [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","camo6","camo11","BFT_screen"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_2drcargo_w_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class CoDriverTurret: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				showAsCargo = 1;
				lodTurnedIn = 1100;
				lodTurnedOut = 1100;
				gunnerForceOptics = 0;
				gunnerName = "Co-driver";
				proxyIndex = 1;
				isPersonTurret = 0;
				gunnerAction = "RHS_M11XX_CoDriver";
				gunnerinAction = "RHS_M11XX_CoDriver";
				memoryPointsGetInGunner = "pos codriver";
				memoryPointsGetInGunnerDir = "pos codriver dir";
				gunnerDoor = "Door_RF";
				turretInfoType = "RHS_RscMATV_Codriver";
				selectionFireAnim = "";
				class Hitpoints{};
			};
		};
		class textureSources
		{
			class Desert
			{
				displayName = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_2drcargo_d_co.paa"};
				decals[] = {8};
				factions[] = {};
			};
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa","rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa","rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\m998_2drcargo_w_co.paa"};
				decals[] = {8};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_cargo_1","VTV_cargo_2"};
				disableHeightLimit = 0;
				maxLoadMass = 2300;
				cargoAlignment[] = {"center","front"};
				cargoSpacing[] = {0,0,0};
				exits[] = {"VTV_exit"};
				unloadingInterval = 2;
				loadingDistance = 3;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 5;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_M1123: rhsusf_m998_d_s_2dr_fulltop
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Cars";
		ace_cargo_space = 5;
		ace_cargo_hasCargo = 1;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1123 [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_MRAP_M1232_M2: rhsusf_M1232_MC_M2_usmc_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_MRAP";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 1500;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1232 (M2) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","pintle","camo7","camo8","camo9"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_TurretWD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_WD_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_RG33L\data\MCTAGS_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa","rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class M2_Turret: M2_Turret
			{
				gunnerCompartments = "Compartment1";
				weapons[] = {"RHS_M2"};
				magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red","rhs_mag_100rnd_127x99_mag_Tracer_Red"};
				gunnerAction = "RHS_MCTAGS_Gunner03";
				gunnerInAction = "RHS_MCTAGS_Gunner03_in";
			};
			class CargoTurret_01: CargoTurret_01
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_02: CargoTurret_02
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_03: CargoTurret_03
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_04: CargoTurret_04
			{
				gunnerCompartments = "Compartment1";
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\m1232\RG33_Body_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Chassis_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Accessory2_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Armor_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Turret_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Wheels_s_CO.paa","PTF_Textures\vehicles\m115x\mk64mount_s_co.paa","PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa","PTF_Textures\vehicles\m1232\camonet_s_co.paa","rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_TurretD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa","rhsusf\addons\rhsusf_RG33L\data\MCTAGS_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa","rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_TurretWD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_WD_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_RG33L\data\MCTAGS_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa","rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_MRAP_M1232_MK19: rhsusf_M1232_MC_MK19_usmc_wd
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_MRAP";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 1500;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "M1232 (Mk19) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camo4","camo5","pintle","camo7","camo8","camo9"};
		hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_TurretWD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_WD_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_RG33L\data\MCTAGS_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa","rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class M2_Turret: M2_Turret
			{
				gunnerCompartments = "Compartment1";
				weapons[] = {"RHS_MK19"};
				magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M430A1","RHS_48Rnd_40mm_MK19_M1001","RHS_48Rnd_40mm_MK19_M1001","RHS_48Rnd_40mm_MK19_M1001"};
				gunnerAction = "RHS_MCTAGS_Gunner03";
				gunnerInAction = "RHS_MCTAGS_Gunner03_in";
			};
			class CargoTurret_01: CargoTurret_01
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_02: CargoTurret_02
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_03: CargoTurret_03
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoTurret_04: CargoTurret_04
			{
				gunnerCompartments = "Compartment1";
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"PTF_Textures\vehicles\m1232\RG33_Body_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Chassis_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Accessory2_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Armor_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Turret_s_CO.paa","PTF_Textures\vehicles\m1232\RG33_Wheels_s_CO.paa","PTF_Textures\vehicles\m115x\mk64mount_s_co.paa","PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa","PTF_Textures\vehicles\m1232\camonet_s_co.paa","rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_TurretD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa","rhsusf\addons\rhsusf_RG33L\data\MCTAGS_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa","rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_WD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_TurretWD_CO.paa","rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_WD_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_RG33L\data\MCTAGS_WD_CO.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa","rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_MRZR4: rhsusf_mrzr4_d
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Cars";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "MRZR4 [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1","camo2","camo3","camomerged","decal_hood_main","decal_hood_1","decal_hood_2","decal_hood_3","decal_hood_4","sticker_mid","sticker_rear"};
		hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_mrzr\data\blue_tan_co.paa","\rhsusf\addons\rhsusf_mrzr\data\yel_tan_co.paa","\rhsusf\addons\rhsusf_mrzr\data\red_tan_co.paa","\rhsusf\addons\rhsusf_mrzr\data\grn_tan_co.paa","\rhsusf\addons\rhsusf_mrzr\data\merged\orng_tan_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class CargoTurret_01: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				memoryPointsGetInGunner = "pos cargo RF";
				memoryPointsGetInGunnerDir = "pos cargo RF dir";
				gunnerAction = "passenger_inside_1";
				gunnerName = "Passenger (Front Seat)";
				isPersonTurret = 1;
				enableFFVWeaponObstruction = 1;
				proxyIndex = 2;
				class TurnOut
				{
					limitsArrayTop[] = {{28.7267,-86.447},{26.7899,-30.4307},{10.0909,-16.9596},{5.3567,-1.3237},{3.7548,54.7238}};
					limitsArrayBottom[] = {{-8.7914,-95.7334},{-26.2615,-38.6995},{-24.1625,-23.4721},{-12.2238,-3.9537},{-10.9171,46.5569},{-8.2158,49.7788}};
				};
				class TurnIn: TurnOut{};
				ejectDeadGunner = 0;
				soundAttenuationTurret = "";
				disableSoundAttenuation = 1;
				playerPosition = 2;
				gunnerGetInAction = "ChopperLight_R_In_H";
				gunnergetOutAction = "GetOutLow";
				usePreciseGetInAction = 1;
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerCompartments = "Compartment1";
				canHideGunner = 0;
				gunnerName = "Passenger (Left Seat)";
				gunnerAction = "rhs_mrzr_passenger";
				gunnerInAction = "rhs_mrzr_passenger";
				animationSourceHatch = "FFV_turn_L";
				gunnerLeftLegAnimName = "FFV_LB_LF";
				gunnerRightLegAnimName = "FFV_LB_RF";
				memoryPointsGetInGunner = "pos cargo LB";
				memoryPointsGetInGunnerDir = "pos cargo LB dir";
				proxyIndex = 3;
				class TurnOut
				{
					limitsArrayTop[] = {{35.4526,63.7415},{32.4939,116.493}};
					limitsArrayBottom[] = {{-18.7593,73.6969},{-23.6628,109.831}};
				};
				class TurnIn: TurnOut{};
				playerPosition = 3;
				gunnerGetInAction = "ChopperLight_L_In_H";
			};
			class CargoTurret_03: CargoTurret_02
			{
				gunnerCompartments = "Compartment1";
				gunnerName = "Passenger (Right Seat)";
				gunnerAction = "rhs_mrzr_passenger";
				gunnerInAction = "rhs_mrzr_passenger";
				animationSourceHatch = "FFV_turn_R";
				gunnerLeftLegAnimName = "FFV_RB_LF";
				gunnerRightLegAnimName = "FFV_RB_RF";
				memoryPointsGetInGunner = "pos cargo RB";
				memoryPointsGetInGunnerDir = "pos cargo RB dir";
				proxyIndex = 4;
				class TurnOut
				{
					limitsArrayTop[] = {{32.7761,-88.5404},{34.2324,-49.191}};
					limitsArrayBottom[] = {{-29.9524,-99.7416},{-16.9604,-47.9381}};
				};
				class TurnIn: TurnOut{};
				playerPosition = 4;
				gunnerGetInAction = "ChopperLight_R_In_H";
			};
			class CargoTurret_04: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerName = "Passenger (Right Seat 2)";
				gunnerAction = "passenger_flatground_2";
				gunnerInAction = "passenger_flatground_2";
				memoryPointsGetInGunner = "pos cargo R";
				memoryPointsGetInGunnerDir = "pos cargo R dir";
				proxyIndex = 5;
				canHideGunner = 0;
				allowLauncherIn = 0;
				allowLauncherOut = 0;
				class TurnIn
				{
					limitsArrayTop[] = {{33.8208,-93.9616},{40.8906,66.5705}};
					limitsArrayBottom[] = {{-9.4643,-94.5753},{-8.3683,-67.6867},{-9.7173,43.6372},{-10.1082,78.9166}};
				};
				class dynamicViewLimits
				{
					CargoTurret_05[] = {-65,75};
				};
				playerPosition = 5;
			};
			class CargoTurret_05: CargoTurret_04
			{
				gunnerCompartments = "Compartment1";
				gunnerName = "Passenger (Left Seat 2)";
				gunnerAction = "passenger_flatground_4";
				gunnerInAction = "passenger_flatground_4";
				proxyIndex = 6;
				class TurnIn
				{
					limitsArrayTop[] = {{37.1488,-71.9003},{36.4967,92.2757}};
					limitsArrayBottom[] = {{-22.1832,-70.0989},{-13.9068,-22.8107},{-7.1236,75.6849},{-7.8564,102.583}};
				};
				class dynamicViewLimits
				{
					CargoTurret_04[] = {-75,65};
				};
				playerPosition = 6;
			};
		};
		class textureSources
		{
			class Desert
			{
				displayName = "Desert";
				author = "J.Downs";
				textures[] = {"\rhsusf\addons\rhsusf_mrzr\data\blue_tan_co.paa","\rhsusf\addons\rhsusf_mrzr\data\yel_tan_co.paa","\rhsusf\addons\rhsusf_mrzr\data\red_tan_co.paa","\rhsusf\addons\rhsusf_mrzr\data\grn_tan_co.paa","\rhsusf\addons\rhsusf_mrzr\data\merged\orng_tan_co.paa"};
				decals[] = {};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VVT_cargo_1","VVT_cargo_2"};
				disableHeightLimit = 1;
				maxLoadMass = 25000;
				cargoAlignment[] = {"left","front"};
				cargoSpacing[] = {0,0,0};
				exits[] = {"VVT_exit"};
				unloadingInterval = 2;
				loadingDistance = 5;
				loadingAngle = 60;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 5;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Command_MRZR_HQ: PTF_MRZR4
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Personal";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "MRZR (Unit HQ) [PTF]";
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Command_MRZR_1ST: PTF_MRZR4
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Personal";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "MRZR (1stPlt HQ) [PTF]";
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Command_MRZR_2ND: PTF_MRZR4
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Personal";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "MRZR (2ndPlt HQ) [PTF]";
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Command_MRZR_MAG36: PTF_MRZR4
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_PersonalAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "MRZR (MAG36 HQ) [PTF]";
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_MTVR_Repair: CUP_B_MTVR_Repair_USMC
	{
		scope = 2;
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		crew = "B_Pilot_F";
		vehicleClass = "Support";
		faction = "BLU_F";
		author = "Paramarine Task Force";
		displayName = "MTVR (Repair) [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
		hiddenSelectionsTextures[] = {"CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\MTVR_interier_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\ural_repair_usmc_co.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\MTVR_interier_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\ural_repair_usmc_co.paa"};
				decals[] = {};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_MTVR_Ammo: CUP_B_MTVR_Ammo_USMC
	{
		scope = 2;
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		crew = "B_Pilot_F";
		vehicleClass = "Support";
		faction = "BLU_F";
		author = "Paramarine Task Force";
		displayName = "MTVR (Ammo) [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
		hiddenSelectionsTextures[] = {"CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_interier_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_tarp_co.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_interier_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_tarp_co.paa"};
				decals[] = {};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_MTVR_Refuel: CUP_B_MTVR_Refuel_USMC
	{
		scope = 2;
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		crew = "B_Pilot_F";
		vehicleClass = "Support";
		faction = "BLU_F";
		transportFuel = 11000;
		author = "Paramarine Task Force";
		displayName = "MTVR (Refuel) [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo1","Camo2","Camo3","Camo4"};
		hiddenSelectionsTextures[] = {"CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\MTVR_interier_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_fuel_co.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\MTVR_interier_co.paa","CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_fuel_co.paa"};
				decals[] = {};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Tractor: boxloader_tractor_build
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		maxSpeed = 20;
		fuelCapacity = 10;
		author = "Paramarine Task Force";
		displayName = "Construction Tractor [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo"};
		hiddenSelectionsTextures[] = {"\boxloader_tractor\Data\tractor_2_green_co.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Green
			{
				displayname = "Green";
				author = "J.Downs";
				textures[] = {"\boxloader_tractor\Data\tractor_2_green_co.paa"};
				factions[] = {};
			};
			class Red
			{
				displayname = "Red";
				author = "J.Downs";
				textures[] = {"\boxloader_tractor\Data\tractor_2_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {"VTV_Cargo_Base","VTV_Cargo_Corner"};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 1;
				parachuteHeightLimit = 15;
			};
			class Carrier
			{
				cargoBayDimensions[] = {"VTV_Carrier_Base_Bucket","VTV_Carrier_Corner_Bucket"};
				cargoSpacing[] = {0,0,0};
				cargoAlignment[] = {"back","left"};
				maxLoadMass = 1002;
				disableHeightLimit = 1;
				exits[] = {"VTV_exit_1"};
				unloadingInterval = 2;
				loadingDistance = 0;
				loadingAngle = 0;
				parachuteClassDefault = "B_Parachute_02_F";
				parachuteHeightLimitDefault = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_TowingTractor: CUP_B_TowingTractor_USA
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		maxSpeed = 20;
		side = 1;
		fuelCapacity = 10;
		author = "Paramarine Task Force";
		displayName = "Towing Tractor [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"\CUP\WheeledVehicles\CUP_WheeledVehicles_TowingTractor\data\towingtractor_co.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class USMC
			{
				displayname = "USMC";
				author = "J.Downs";
				textures[] = {"\CUP\WheeledVehicles\CUP_WheeledVehicles_TowingTractor\data\towingtractor_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Quadbike: B_T_Quadbike_01_F
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "Quad Bike [MAG36]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_olive_CO.paa","\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_wheel_olive_CO.paa"};
		class Turrets: Turrets{};
		class textureSources
		{
			class Black
			{
				displayName = "Black";
				author = "J.Downs";
				textures[] = {"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLACK_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLACK_CO.paa"};
				factions[] = {};
			};
			class Blue
			{
				displayName = "Blue";
				author = "J.Downs";
				textures[] = {"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLUE_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLUE_CO.paa"};
				factions[] = {};
			};
			class Red
			{
				displayName = "Red";
				author = "J.Downs";
				textures[] = {"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_RED_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVRED_CO.paa"};
				factions[] = {};
			};
			class White
			{
				displayName = "White";
				author = "J.Downs";
				textures[] = {"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_WHITE_CO.paa","\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVWHITE_CO.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayName = "Desert";
				author = "J.Downs";
				textures[] = {"\A3\Soft_F\Quadbike_01\Data\Quadbike_01_co.paa","\A3\Soft_F\Quadbike_01\Data\Quadbike_01_wheel_co.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_olive_CO.paa","\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_wheel_olive_CO.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {"VTV_Cargo_Base","VTV_Cargo_Corner"};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 1;
				parachuteHeightLimit = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_SDV: B_SDV_01_F
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Boat";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "SDV [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo1"};
		hiddenSelectionsTextures[] = {"\A3\boat_f_beta\SDV_01\data\SDV_ext_CO.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class CommanderTurret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerName = "Gunner";
				proxyType = "CPCommander";
				commanding = -1;
				ejectDeadGunner = 0;
				body = "ObsTurret";
				gun = "ObsGun";
				animationSourceBody = "ObsTurret";
				animationSourceGun = "ObsGun";
				gunBeg = "PIP1_dir";
				gunEnd = "PIP1_pos";
				memoryPointGunnerOptics = "PIP1_dir";
				weapons[] = {"Laserdesignator_mounted"};
				magazines[] = {"Laserbatteries"};
				soundServo[] = {"A3\sounds_f\dummysound",0.01,1,10};
				gunnerAction = "commander_SDV";
				gunnergetInAction = "GetInLow";
				gunnergetOutAction = "GetOutLow";
				memoryPointsGetInGunner = "pos commander";
				memoryPointsGetInGunnerDir = "pos commander dir";
				usePip = 1;
				Laser = 1;
				stabilizedInAxes = 4;
				gunnerOpticsModel = "\A3\weapons_f_beta\reticle\reticle_SDV";
				turretInfoType = "RscOptics_SDV_periscope";
				gunnerForceOptics = 0;
				LODTurnedIn = 1100;
				LODTurnedOut = 1100;
				outGunnerMayFire = 1;
				startEngine = 0;
				class ViewOptics: ViewOptics
				{
					initAngleX = 0;
					minAngleX = 0;
					maxAngleX = 0;
					initAngleY = 0;
					minAngleY = -180;
					maxAngleY = 180;
					initFov = 0.14;
					minFov = 0.0175;
					maxFov = 0.14;
					visionMode[] = {"Normal","NVG","Ti"};
					thermalMode[] = {2,3,4};
				};
			};
		};
		class textureSources
		{
			class USMC
			{
				displayName = "USMC";
				author = "J.Downs";
				textures[] = {"\A3\boat_f_beta\SDV_01\data\SDV_ext_CO.paa"};
				decals[] = {};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				dimensions[] = {};
				parachuteClass = "B_Parachute_02_F";
				canBeTransported = 0;
				parachuteHeightLimit = 10;
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Stretcher: GurneyTabl
	{
		displayName = "Stretcher";
	};
	class PTF_Quadbike_6x6: NDS_6x6_ATV_MIL
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Utility";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "6x6 Quad Bike [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo1","camo2","camnetpattern","camnetpatternr","pouches","backpack","load"};
		hiddenSelectionsTextures[] = {"NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_body_MIL_CAM_CO.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_cam_wheel_co.paa","NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_cam_ca.paa","NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_cam_ca.paa","\A3\Characters_F\blufor\data\vests_khk_co.paa","\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_oli_co.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_ACC_CO.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class CargoTurret_01: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerAction = "NDS_ATV_ffv_stance";
				memoryPointsGetInGunner = "pos_ffv";
				memoryPointsGetInGunnerDir = "pos_ffv_dir";
				gunnerGetInAction = "GetInLow";
				gunnerGetOutAction = "GetOutLow";
				getInRadius = 0.1;
				gunnerName = "Fire Position";
				isPersonTurret = 1;
				canHideGunner = 0;
				allowLauncherIn = 1;
				allowLauncherOut = 1;
				showAsCargo = 0;
				dontCreateAI = 1;
				hasGunner = 0;
				ejectDeadGunner = 1;
				canEject = 1;
				maxTurn = 75;
			};
		};
		class textureSources
		{
			class Snow
			{
				displayname = "Snow";
				author = "J.Downs";
				textures[] = {"NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_body_MIL_SNO_CO.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_sno_wheel_co.paa","NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_sno_ca.paa","NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_sno_ca.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_pouches_sno_co.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_backpack_lge_sno_co.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_ACC_SNO_CO.paa"};
				factions[] = {};
			};
			class Desert
			{
				displayname = "Desert";
				author = "J.Downs";
				textures[] = {"NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_body_MIL_DES_CO.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_des_wheel_co.paa","NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_des_ca.paa","NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_des_ca.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_pouches_des_co.paa","\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_cbr_co.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_ACC_CO.paa"};
				factions[] = {};
			};
			class Woodland
			{
				displayname = "Woodland";
				author = "J.Downs";
				textures[] = {"NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_body_MIL_CAM_CO.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_cam_wheel_co.paa","NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_cam_ca.paa","NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_cam_ca.paa","\A3\Characters_F\blufor\data\vests_rgr_co.paa","\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_oli_co.paa","NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_ACC_CO.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_AAV: CUP_B_AAV_USMC
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Armor";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 1500;
		side = 1;
		mass = 14000;
		author = "Paramarine Task Force";
		displayName = "AAV [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext_co.paa","CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext2_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class MainTurret: MainTurret
			{
				gunnerCompartments = "Compartment1";
				turretInfoType = "CUP_RscOptics_gunner_LAV25";
				castGunnerShadow = 1;
				viewGunnerShadow = 1;
				weapons[] = {"CUP_Vgmg_MK19_AAV","CUP_Vhmg_M2_AAV_Noeject"};
				magazines[] = {"CUP_96Rnd_40mm_MK19_M","CUP_96Rnd_40mm_MK19_M","CUP_96Rnd_40mm_MK19_M","CUP_96Rnd_40mm_MK19_M","CUP_96Rnd_40mm_MK19_M","CUP_96Rnd_40mm_MK19_M","CUP_96Rnd_40mm_MK19_M","CUP_96Rnd_40mm_MK19_M","CUP_200Rnd_TE1_Red_Tracer_127x99_M","CUP_200Rnd_TE1_Red_Tracer_127x99_M","CUP_200Rnd_TE1_Red_Tracer_127x99_M","CUP_200Rnd_TE1_Red_Tracer_127x99_M","CUP_200Rnd_TE1_Red_Tracer_127x99_M","CUP_200Rnd_TE1_Red_Tracer_127x99_M"};
				discreteDistance[] = {100,200,300,400,500,600,700,800,900,1000,1100,1200,1300,1400,1500,1600,1700,1800,1900,2000,2100,2200,2300,2400,2500,2600,2700,2800,2900,3000,3100,3200,3300,3400,3500,3600,3700,3800,3900,4000,4100,4200,4300,4400,4500,4600,4700,4800,4900,5000};
				discreteDistanceInitIndex = 3;
				outGunnerMayFire = 0;
				gunnerForceOptics = 1;
				gunnerAction = "vehicle_turnout_2";
				gunnerInAction = "CUP_AAV_Gunner";
				forceHideGunner = 0;
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				ispersonturret = 1;
				minOutElev = -30;
				maxOutElev = 40;
				initOutElev = 0;
				minOutTurn = -90;
				maxOutTurn = 90;
				initOutTurn = 0;
				minElev = -8;
				maxElev = 45;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				LODTurnedIn = 1000;
				LODTurnedOut = 1;
				memoryPointGun = "machinegun";
				selectionFireAnim = "";
				gunBeg = "gmg_start";
				gunEnd = "gmg_end";
				gunnerOpticsModel = "CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\optika_stryker_gunner.p3d";
				gunnerOpticsEffect[] = {};
				gunnerOutOpticsEffect[] = {};
				gunnerOutOpticsModel = "\a3\weapons_f\Reticle\optics_empty";
				ace_fcs_enabled = 0;
				class Turrets{};
				class GunFire: WeaponCloudsMGun
				{
					interval = 0.01;
				};
				class OpticsIn
				{
					class Periscope: ViewOptics
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.4;
						minFov = 0.4;
						maxFov = 0.4;
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "\a3\weapons_f\reticle\Optics_Driver_01_f";
					};
					class Narrow
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.057;
						minFov = 0.057;
						maxFov = 0.057;
						visionMode[] = {"Normal"};
						gunnerOpticsModel = "CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\optika_stryker_gunner.p3d";
						gunnerOpticsEffect[] = {};
					};
					class NOD
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.057;
						minFov = 0.057;
						maxFov = 0.057;
						visionMode[] = {"NVG"};
						gunnerOpticsModel = "CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\optika_stryker_gunner.p3d";
						gunnerOpticsEffect[] = {};
					};
				};
				class HitPoints
				{
					class HitTurret
					{
						armor = 1;
						material = -1;
						name = "main_turret";
						visual = "vez";
						passThrough = 0;
						minimalHit = 0.2;
						explosionShielding = 0.09;
						radius = 0.25;
					};
					class HitGun
					{
						armor = 0.6;
						material = -1;
						name = "main_gun";
						visual = "main_gun";
						passThrough = 0;
						minimalHit = 0.2;
						explosionShielding = 0.09;
						radius = 0.25;
					};
				};
				startEngine = 0;
				stabilizedInAxes = 0;
			};
			class CommanderTurret: NewTurret
			{
				gunnerCompartments = "Compartment1";
				turretInfoType = "CUP_RscOptics_commander_ECO";
				proxyType = "CPCommander";
				proxyIndex = 1;
				gunnerName = "$STR_POSITION_COMMANDER";
				primaryGunner = 0;
				primaryObserver = 1;
				gunnerForceOptics = 0;
				body = "ObsTurret";
				gun = "ObsGun";
				animationSourceBody = "obsTurret";
				animationSourceGun = "obsGun";
				gunnerAction = "vehicle_turnout_2";
				gunnerInAction = "CUP_AAV_Commander";
				ispersonturret = 1;
				minOutElev = -20;
				maxOutElev = 40;
				initOutElev = 0;
				minOutTurn = -90;
				maxOutTurn = 90;
				initOutTurn = 0;
				LODTurnedIn = 1000;
				LODTurnedOut = 1;
				soundServo[] = {"","db-50",1};
				gunBeg = "";
				gunEnd = "";
				commanding = 2;
				gunnerOpticsModel = "\CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\2Dscope_com2";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerOutOpticsModel = "";
				gunnerOutOpticsShowCursor = 0;
				memoryPointGunnerOutOptics = "commander_weapon_view";
				memoryPointGunnerOptics = "optics_commander";
				memoryPointsGetInGunner = "pos commander";
				memoryPointsGetInGunnerDir = "pos commander dir";
				gunnerGetInAction = "GetInHigh";
				gunnerGetOutAction = "GetOutHigh";
				animationSourceHatch = "hatchCommander";
				minElev = -10;
				maxElev = 35;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				weapons[] = {"SmokeLauncher"};
				magazines[] = {"SmokeLauncherMag","SmokeLauncherMag"};
				outGunnerMayFire = 1;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.4;
					minFov = 0.4;
					maxFov = 0.4;
				};
				startEngine = 0;
				stabilizedInAxes = 0;
			};
			class CargoGunner_1: NewTurret
			{
				gunnerCompartments = "Compartment1";
				weapons[] = {};
				magazines[] = {};
				proxyType = "CPCargo";
				proxyIndex = 3;
				gunnerName = "$STR_A3_TURRETS_CARGOTURRET_R";
				primaryGunner = 0;
				primaryObserver = 0;
				gunnerOpticsShowCursor = 0;
				body = "";
				gun = "";
				animationSourceBody = "";
				animationSourceGun = "";
				animationSourceHatch = "CargoGunner_1";
				soundServo[] = {"","db-50",1};
				startEngine = 0;
				hideWeaponsGunner = 0;
				gunnerGetInAction = "GetInHigh";
				gunnerGetOutAction = "GetOutHigh";
				gunnerAction = "vehicle_turnout_2";
				gunnerInAction = "passenger_low01";
				ispersonturret = 1;
				dontCreateAI = 1;
				minOutElev = -10;
				maxOutElev = 40;
				initOutElev = 0;
				minOutTurn = -80;
				maxOutTurn = 80;
				initOutTurn = 0;
				minElev = -15;
				maxElev = 50;
				initElev = 0;
				minTurn = -120;
				maxTurn = 120;
				initTurn = 0;
				commanding = -1;
				viewGunnerInExternal = 1;
				gunnerOpticsModel = "";
				gunnerOutOpticsColor[] = {0,0,0,1};
				gunnerForceOptics = 0;
				gunnerOutForceOptics = 0;
				gunnerOutOpticsShowCursor = 0;
				memoryPointGunnerOptics = "";
				memoryPointsGetInGunner = "pos frontright";
				memoryPointsGetInGunnerDir = "pos frontright dir";
				gunnerOpticsEffect[] = {};
				outGunnerMayFire = 1;
				inGunnerMayFire = 0;
				stabilizedInAxes = 0;
			};
			class CargoGunner_2: CargoGunner_1
			{
				gunnerCompartments = "Compartment1";
				proxyIndex = 13;
				gunnerName = "$STR_A3_TURRETS_CARGOTURRET_R1";
				animationSourceHatch = "CargoGunner_2";
				memoryPointsGetInGunner = "pos midright";
				memoryPointsGetInGunnerDir = "pos midright dir";
			};
			class CargoGunner_3: CargoGunner_1
			{
				gunnerCompartments = "Compartment1";
				proxyIndex = 5;
				gunnerName = "$STR_A3_TURRETS_CARGOTURRET_RR";
				animationSourceHatch = "CargoGunner_3";
				memoryPointsGetInGunner = "pos backright";
				memoryPointsGetInGunnerDir = "pos backright dir";
			};
			class CargoGunner_4: CargoGunner_1
			{
				gunnerCompartments = "Compartment1";
				proxyIndex = 7;
				gunnerName = "$STR_A3_TURRETS_CARGOTURRET_L";
				animationSourceHatch = "CargoGunner_4";
				memoryPointsGetInGunner = "pos frontleft";
				memoryPointsGetInGunnerDir = "pos frontleft dir";
			};
			class CargoGunner_5: CargoGunner_1
			{
				gunnerCompartments = "Compartment1";
				proxyIndex = 4;
				gunnerName = "$STR_A3_TURRETS_CARGOTURRET_L1";
				animationSourceHatch = "CargoGunner_5";
				memoryPointsGetInGunner = "pos midleft";
				memoryPointsGetInGunnerDir = "pos midleft dir";
			};
			class CargoGunner_6: CargoGunner_1
			{
				gunnerCompartments = "Compartment1";
				proxyIndex = 8;
				gunnerName = "$STR_A3_TURRETS_CARGOTURRET_RL";
				animationSourceHatch = "CargoGunner_6";
				memoryPointsGetInGunner = "pos backleft";
				memoryPointsGetInGunnerDir = "pos backleft dir";
			};
		};
		class textureSources
		{
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext_co.paa","CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext2_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_AAV_CMD: CUP_B_AAV_Unarmed_USMC
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Armor";
		ace_cargo_space = 10;
		ace_cargo_hasCargo = 1;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 1500;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "AAV Command [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"Camo1","Camo2"};
		hiddenSelectionsTextures[] = {"CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext_co.paa","CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext2_co.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class MainTurret: CommanderTurret
			{
				gunnerCompartments = "Compartment1";
				proxyType = "CPGunner";
				proxyIndex = 1;
				gunnerName = "$STR_POSITION_GUNNER";
				primaryGunner = 1;
				primaryObserver = 0;
				gunnerForceOptics = 0;
				body = "mainturret";
				gun = "maingun";
				animationSourceBody = "mainturret";
				animationSourceGun = "maingun";
				memoryPointsGetInGunner = "pos gunner";
				memoryPointsGetInGunnerDir = "pos gunner dir";
				gunnerAction = "vehicle_turnout_2";
				gunnerInAction = "CUP_AAV_Commander";
				ispersonturret = 1;
				minOutElev = -20;
				maxOutElev = 40;
				initOutElev = 0;
				minOutTurn = -90;
				maxOutTurn = 90;
				initOutTurn = 0;
				soundServo[] = {"","db-50",1};
				gunBeg = "";
				gunEnd = "";
				commanding = 2;
				gunnerOpticsModel = "\CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\2Dscope_com2";
				gunnerOpticsColor[] = {1,1,1,1};
				gunnerOutOpticsModel = "";
				gunnerOutOpticsShowCursor = 0;
				memoryPointGunnerOutOptics = "commander_weapon_view";
				memoryPointGunnerOptics = "gunnerview";
				gunnerGetInAction = "GetInHigh";
				gunnerGetOutAction = "GetOutHigh";
				animationSourceHatch = "hatchGunner";
				minElev = -10;
				maxElev = 35;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				LODTurnedIn = 1100;
				LODTurnedOut = 1;
				weapons[] = {};
				magazines[] = {};
				outGunnerMayFire = 1;
				class ViewOptics
				{
					initAngleX = 0;
					minAngleX = -30;
					maxAngleX = 30;
					initAngleY = 0;
					minAngleY = -100;
					maxAngleY = 100;
					initFov = 0.466;
					minFov = 0.466;
					maxFov = 0.466;
				};
				startEngine = 0;
				stabilizedInAxes = 0;
			};
			class CommanderTurret: CommanderTurret
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoGunner_1: CargoGunner_1
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoGunner_2: CargoGunner_2
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoGunner_3: CargoGunner_3
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoGunner_4: CargoGunner_4
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoGunner_5: CargoGunner_5
			{
				gunnerCompartments = "Compartment1";
			};
			class CargoGunner_6: CargoGunner_6
			{
				gunnerCompartments = "Compartment1";
			};
		};
		class textureSources
		{
			class Woodland
			{
				displayName = "Woodland";
				author = "J.Downs";
				textures[] = {"CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext_co.paa","CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext2_co.paa"};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {"BBox_1_1_pos","BBox_1_2_pos"};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Snowmobile: xs_Snowmobile_combat
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Utility";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "Snowmobile [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1"};
		hiddenSelectionsTextures[] = {"xakuda_f\xs_snowmobile\data\body_camo.paa","xakuda_f\xs_snowmobile\data\koja_camo.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class CargoTurret_01: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerAction = "passenger_inside_3";
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerName = "Passenger";
				proxyIndex = 1;
				isPersonTurret = 1;
				class TurnIn
				{
					limitsArrayTop[] = {{24,-88},{24,-5}};
					limitsArrayBottom[] = {{-44,-88},{-44,-5}};
				};
			};
			class CargoTurret_02: CargoTurret_01
			{
				gunnerCompartments = "Compartment1";
				gunnerAction = "passenger_inside_3";
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerName = "Rear shooter";
				proxyIndex = 2;
				isPersonTurret = 1;
				class TurnIn
				{
					limitsArrayTop[] = {{54,-88},{54,98}};
					limitsArrayBottom[] = {{-64,-88},{-64,98}};
				};
			};
		};
		class textureSources
		{
			class Snow
			{
				displayName = "Snow";
				author = "J.Downs";
				textures[] = {"xakuda_f\xs_snowmobile\data\body_camo.paa","xakuda_f\xs_snowmobile\data\koja_camo.paa"};
				decals[] = {};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_Snowmobile_Basket: xs_Snowmobile_sport_camo
	{
		scope = 2;
		faction = "BLU_F";
		editorCategory = "PTF";
		editorSubcategory = "PTF_Utility";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 0;
		ace_cargo_canLoad = 0;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 0;
		maximumLoad = 375;
		side = 1;
		author = "Paramarine Task Force";
		displayName = "Snowmobile (Basket) [PTF]";
		driverCompartments = "Compartment1";
		cargoCompartments[] = {"Compartment1"};
		hiddenSelections[] = {"camo","camo1"};
		hiddenSelectionsTextures[] = {"xakuda_f\xs_snowmobile\data\body_camo.paa","xakuda_f\xs_snowmobile\data\koja_camo.paa"};
		class Turrets: Turrets
		{
			gunnerCompartments = "Compartment1";
			class CargoTurret_01: CargoTurret
			{
				gunnerCompartments = "Compartment1";
				gunnerAction = "passenger_inside_3";
				memoryPointsGetInGunner = "pos cargo";
				memoryPointsGetInGunnerDir = "pos cargo dir";
				gunnerName = "Passenger";
				proxyIndex = 1;
				isPersonTurret = 1;
				class TurnIn
				{
					limitsArrayTop[] = {{24,-88},{24,-5}};
					limitsArrayBottom[] = {{-44,-88},{-44,-5}};
				};
			};
		};
		class textureSources
		{
			class Snow
			{
				displayName = "Snow";
				author = "J.Downs";
				textures[] = {"xakuda_f\xs_snowmobile\data\body_camo.paa","xakuda_f\xs_snowmobile\data\koja_camo.paa"};
				decals[] = {};
				factions[] = {};
			};
		};
		class VehicleTransport
		{
			class Cargo
			{
				parachuteClass = "B_Parachute_02_F";
				parachuteHeightLimit = 15;
				canBeTransported = 1;
				dimensions[] = {};
			};
		};
		class TransportItems: TransportItems{};
		class TransportBackpacks: TransportBackpacks{};
		class TransportMagazines: TransportMagazines{};
		class TransportWeapons: TransportWeapons{};
	};
	class PTF_SAM_DEFENDER: B_SAM_System_03_F
	{
		scope = 2;
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 15;
		ace_cargo_canLoad = 1;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		side = 1;
		faction = "BLU_F";
		crew = "B_UAV_AI";
		author = "Paramarine Task Force";
		displayName = "MIM-145 [MAG36]";
		mass = 5000;
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class DataLinkSensorComponent: SensorTemplateDataLink{};
				};
			};
		};
		reportOwnPosition = "true";
		receiveRemoteTargets = "true";
		reportRemoteTargets = "true";
		showAllTargets = 2;
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_01_CO.paa","A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_02_CO.paa"};
		class TextureSources
		{
			class Desert
			{
				displayName = "$STR_A3_TEXTURESOURCES_SAND0";
				author = "$STR_A3_author_B01";
				factions[] = {"BLU_F"};
				textures[] = {"A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_01_CO.paa","A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_02_CO.paa"};
			};
			class Olive
			{
				displayName = "$STR_A3_TEXTURESOURCES_OLIVE0";
				author = "$STR_A3_author_B01";
				factions[] = {"BLU_F"};
				textures[] = {"A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_01_olive_CO.paa","A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_02_olive_CO.paa"};
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minelev = 0;
				maxelev = 75;
				minturn = -180;
				maxturn = 180;
				initElev = 0;
				initTurn = 0;
				maxHorizontalRotSpeed = 0.6;
				maxVerticalRotSpeed = 0.6;
				soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best",1.4125376,1,40};
				hasGunner = 1;
				gunnerName = "$STR_A3_SAM_System_03_operator_displayName";
				primary = 1;
				primaryGunner = 1;
				startEngine = 0;
				enableManualFire = 1;
				turretinfotype = "RscOptics_SAM_01";
				forceHideGunner = 1;
				gunnerforceoptics = 1;
				gunnerOutForceOptics = 1;
				viewgunnerinExternal = 0;
				gunnerOpticsShowCursor = 0;
				gunnerOutOpticsShowCursor = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				castGunnerShadow = 0;
				showAllTargets = 2;
				body = "MainTurret";
				gun = "MainGun";
				animationSourceBody = "MainTurret";
				animationSourceGun = "MainGun";
				uavCameraGunnerPos = "pos_gunner_view";
				uavCameraGunnerDir = "pos_gunner_view_dir";
				memoryPointGunnerOptics = "pos_gunner_view";
				selectionFireAnim = "zasleh";
				missileBeg = "pos_missile";
				missileEnd = "pos_missile_end";
				gunnerlefthandanimname = "";
				gunnerrighthandanimname = "";
				weapons[] = {"weapon_mim145Launcher"};
				magazines[] = {"magazine_Missile_mim145_x4"};
				optics = 1;
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.466;
						minFov = 0.466;
						maxFov = 0.466;
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
					};
					class Medium: Wide
					{
						opticsDisplayName = "M";
						initFov = 0.093;
						minFov = 0.093;
						maxFov = 0.093;
						gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "N";
						gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_n_F";
						initFov = 0.029;
						minFov = 0.029;
						maxFov = 0.029;
					};
				};
				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
						class Components
						{
							class EmptyDisplay
							{
								componentType = "EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType = "MinimapDisplayComponent";
								resource = "RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType = "UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {16000,8000,4000,2000};
								resource = "RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
					{
						defaultDisplay = "SensorDisplay";
						class Components
						{
							class EmptyDisplay
							{
								componentType = "EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType = "MinimapDisplayComponent";
								resource = "RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType = "UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {16000,8000,4000,2000};
								resource = "RscCustomInfoSensors";
							};
						};
					};
				};
				class HitTurret
				{
					armor = 0.3;
					name = "vez";
					visual = "turret";
					radius = 0.25;
					passThrough = 0;
					minimalHit = 0.1;
					explosionShielding = 1.2;
					material = -1;
					class DestructionEffects
					{
						class Smoke
						{
							simulation = "particles";
							type = "WeaponWreckSmoke";
							position = "turretdestruct_pos";
							intensity = 1;
							interval = 1;
							lifeTime = 5;
						};
					};
				};
				class HitGun
				{
					armor = 0.3;
					name = "zbran";
					visual = "gun";
					radius = 0.25;
					passThrough = 0;
					minimalHit = 0.1;
					explosionShielding = 1.2;
					material = -1;
					class DestructionEffects
					{
						class Smoke
						{
							simulation = "particles";
							type = "WeaponWreckSmoke";
							position = "turretdestruct_pos";
							intensity = 1;
							interval = 1;
							lifeTime = 5;
						};
					};
				};
			};
		};
	};
	class PTF_SAM_RADAR: B_Radar_System_01_F
	{
		scope = 2;
		editorCategory = "PTF";
		editorSubcategory = "PTF_UtilityAir";
		ace_cargo_space = 0;
		ace_cargo_hasCargo = 0;
		ace_cargo_size = 15;
		ace_cargo_canLoad = 1;
		ace_dragging_canCarry = 0;
		ace_dragging_canDrag = 1;
		side = 1;
		faction = "BLU_F";
		crew = "B_UAV_AI";
		author = "Paramarine Task Force";
		displayName = "AN/MPQ-105 [MAG36]";
		mass = 5000;
		class Components: Components
		{
			class SensorsManagerComponent
			{
				class Components
				{
					class DataLinkSensorComponent: SensorTemplateDataLink{};
					class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
					{
						animDirection = "mainGun";
					};
					class ActiveRadarSensorComponent: SensorTemplateActiveRadar
					{
						class AirTarget
						{
							minRange = 16000;
							maxRange = 16000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						class GroundTarget
						{
							minRange = 12000;
							maxRange = 12000;
							objectDistanceLimitCoef = -1;
							viewDistanceLimitCoef = -1;
						};
						animDirection = "mainGun";
						typeRecognitionDistance = 12000;
						maxTrackableSpeed = 1388.89;
					};
				};
			};
		};
		reportOwnPosition = "true";
		receiveRemoteTargets = "true";
		reportRemoteTargets = "true";
		showAllTargets = 2;
		hiddenSelections[] = {"camo1","camo2"};
		hiddenSelectionsTextures[] = {"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_01_CO.paa","A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_02_CO.paa"};
		class TextureSources
		{
			class Desert
			{
				displayName = "$STR_A3_TEXTURESOURCES_SAND0";
				author = "$STR_A3_author_B01";
				factions[] = {"BLU_F"};
				textures[] = {"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_01_CO.paa","A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_02_CO.paa"};
			};
			class Olive
			{
				displayName = "$STR_A3_TEXTURESOURCES_OLIVE0";
				author = "$STR_A3_author_B01";
				factions[] = {"BLU_F"};
				textures[] = {"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_01_olive_CO.paa","A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_02_olive_CO.paa"};
			};
		};
		class Turrets: Turrets
		{
			class MainTurret: MainTurret
			{
				minelev = -10;
				maxelev = 75;
				minturn = -180;
				maxturn = 180;
				initElev = 15;
				initTurn = 0;
				maxHorizontalRotSpeed = 1;
				maxVerticalRotSpeed = 1;
				soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best",1.4125376,1,40};
				hasGunner = 1;
				canUseScanners = 1;
				gunnerName = "$STR_A3_Radar_System_01_operator_displayName";
				primary = 1;
				primaryGunner = 1;
				startEngine = 0;
				enableManualFire = 1;
				turretinfotype = "RscOptics_Radar_02";
				forceHideGunner = 1;
				gunnerforceoptics = 1;
				gunnerOutForceOptics = 1;
				viewgunnerinExternal = 0;
				gunnerOpticsShowCursor = 0;
				gunnerOutOpticsShowCursor = 0;
				outGunnerMayFire = 1;
				inGunnerMayFire = 1;
				castGunnerShadow = 0;
				showAllTargets = 2;
				body = "MainTurret";
				gun = "MainGun";
				animationSourceBody = "MainTurret";
				animationSourceGun = "MainGun";
				uavCameraGunnerPos = "pos_gunner_view";
				uavCameraGunnerDir = "pos_gunner_view_dir";
				memoryPointGunnerOptics = "pos_gunner_view";
				selectionFireAnim = "zasleh";
				missileBeg = "pos_missile";
				missileEnd = "pos_missile_end";
				gunnerlefthandanimname = "";
				gunnerrighthandanimname = "";
				weapons[] = {"FakeWeapon"};
				magazines[] = {};
				optics = 1;
				gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName = "W";
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.466;
						minFov = 0.466;
						maxFov = 0.466;
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {0,1};
						gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
					};
					class Medium: Wide
					{
						opticsDisplayName = "M";
						initFov = 0.093;
						minFov = 0.093;
						maxFov = 0.093;
						gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "N";
						gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_n_F";
						initFov = 0.029;
						minFov = 0.029;
						maxFov = 0.029;
					};
				};
				class Components: Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: DefaultVehicleSystemsDisplayManagerLeft
					{
						class Components
						{
							class EmptyDisplay
							{
								componentType = "EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType = "MinimapDisplayComponent";
								resource = "RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType = "UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {16000,8000,4000,2000};
								resource = "RscCustomInfoSensors";
							};
						};
					};
					class VehicleSystemsDisplayManagerComponentRight: DefaultVehicleSystemsDisplayManagerRight
					{
						defaultDisplay = "SensorDisplay";
						class Components
						{
							class EmptyDisplay
							{
								componentType = "EmptyDisplayComponent";
							};
							class MinimapDisplay
							{
								componentType = "MinimapDisplayComponent";
								resource = "RscCustomInfoMiniMap";
							};
							class UAVDisplay
							{
								componentType = "UAVFeedDisplayComponent";
							};
							class SensorDisplay
							{
								componentType = "SensorsDisplayComponent";
								range[] = {16000,8000,4000,2000};
								resource = "RscCustomInfoSensors";
							};
						};
					};
				};
				class HitTurret
				{
					armor = 0.3;
					name = "vez";
					visual = "turret";
					radius = 0.25;
					passThrough = 0;
					minimalHit = 0.1;
					explosionShielding = 1.2;
					material = -1;
					class DestructionEffects
					{
						class Smoke
						{
							simulation = "particles";
							type = "WeaponWreckSmoke";
							position = "turretdestruct_pos";
							intensity = 1;
							interval = 1;
							lifeTime = 5;
						};
					};
				};
			};
		};
	};
	    class PTF_M1151CAT_M2 : rhsusf_m1151_m2_v3_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1151 (M2) [CAT]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo19", "BFT_screen"};
   hiddenSelectionTextures[] = {
       "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
    class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MCTAGS_Turret : MCTAGS_Turret
      {
         gunnerCompartments = "Compartment1";
         discreteDistance[] = {100, 200, 300, 400, 500, 600, 800, 1000, 1200, 1500};
         discreteDistanceInitIndex = 2;
         gunnerLeftHandAnimName = "OtocHlaven";
         gunnerRightHandAnimName = "OtocHlaven";
         weapons[] = {"RHS_M2"};
         magazines[] = {
            "rhs_mag_200rnd_127x99_SLAP_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_SLAP_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_SLAP_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_SLAP_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_mag_Tracer_red",
            };
      };
      class CoDriverTurret : CoDriverTurret
      {
         gunnerCompartments = "Compartment1";
      };
   };
        class TransportBackpacks
                {
                };
         class TransportMagazines {
            class _xx_rhsusf_100Rnd_762x51_m80a1epr {
                magazine="rhsusf_100Rnd_762x51_m80a1epr";
                count = 5;
            };
            class _xx_rhsusf_200Rnd_556x45_box {
                magazine="rhsusf_200Rnd_556x45_box";
                count = 5;
            };
            class _xx_PTF_Mag_556x45_Mk262_PMAG_Mix{
                magazine="PTF_Mag_556x45_Mk262_PMAG_Mix";
                count = 20;
            };
            class _xx_rhs_mag_an_m8hc {
                magazine="rhs_mag_an_m8hc";
                count = 5;
            };
            class _xx_SmokeShellBlue {
                magazine="SmokeShellBlue";
                count = 5;
            };
            class _xx_rhs_mag_m67 {
                magazine="rhs_mag_m67";
                count = 5;
            };
            class _xx_rhs_fim92_mag {
                magazine="rhs_fim92_mag";
                count = 2;
            };
            class _xx_rhs_fgm148_magazine_AT {
                magazine="rhs_fgm148_magazine_AT";
                count = 1;
            };
		};
		class TransportItems{
            class _xx_ACE_elasticBandage {
                name="ACE_elasticBandage";
                count = 20;
            };
            class _xx_ACE_bloodIV {
                name="ACE_bloodIV";
                count = 3;
            };
            class _xx_ACE_splint {
                name="ACE_splint";
                count = 4;
            };
            class _xx_ACE_tourniquet {
                name="ACE_tourniquet";
                count = 4;
            };
            class _xx_rhsusf_ANPVS_15 {
                name="rhsusf_ANPVS_15";
                count = 2;
            };
            class _xx_ACE_wirecutter {
                name="ACE_wirecutter";
                count = 2;
            };
            class _xx_ToolKit {
                name="ToolKit";
                count = 1;
            };
            class _xx_MineDetector {
                name="MineDetector";
                count = 2;
            };
            class _xx_ACE_Clacker {
                name="ACE_Clacker";
                count = 2;
            };
            class _xx_ACE_DefusalKit {
                name="ACE_DefusalKit";
                count = 2;
            };
            class _xx_ACE_EarPlugs {
                name="ACE_EarPlugs";
                count = 5;
            };
		};
		class TransportWeapons
		{
            class _xx_rhs_weap_M136_hp {
                weapon="rhs_weap_M136_hp"
                count = 1
            };
		};
   class textureSources
   {
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {
             "PTF_Textures\vehicles\m115x\m1151_s_CO.paa", "PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         hiddenselectionstextures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
         factions[] = {};
      };
   };
};
class PTF_M1151CAT_MK19 : rhsusf_m1151_mk19_v3_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1151 (Mk19) [CAT]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo19", "BFT_screen"};
   hiddenSelectionTextures[] = {
       "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MCTAGS_Turret : MCTAGS_Turret
      {
         gunnerCompartments = "Compartment1";
         discreteDistance[] = {100, 200, 300, 400, 500, 600, 800, 1000, 1200, 1500};
         discreteDistanceInitIndex = 2;
         gunnerLeftHandAnimName = "OtocHlaven";
         gunnerRightHandAnimName = "OtocHlaven";
         weapons[] = {"RHS_MK19"};
         magazines[] = {
        "RHS_96Rnd_40mm_MK19_M1001",
        "RHS_96Rnd_40mm_MK19_M1001",
        "RHS_96Rnd_40mm_MK19",
        "RHS_96Rnd_40mm_MK19",
        "RHS_96Rnd_40mm_MK19_M430A1",
        "RHS_96Rnd_40mm_MK19_M430A1",
        "RHS_96Rnd_40mm_MK19_M430A1",
        "RHS_96Rnd_40mm_MK19_M430A1",
        "RHS_96Rnd_40mm_MK19_M430A1"
         };
      };
      class CoDriverTurret : CoDriverTurret
      {
         gunnerCompartments = "Compartment1";
      };
   };
   class textureSources
   {
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {
             "PTF_Textures\vehicles\m115x\m1151_s_CO.paa", "PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         hiddenselectionstextures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
         factions[] = {};
      };
   };
   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {"BBox_1_1_pos", "BBox_1_2_pos"};
      };
      class Carrier
      {
         cargoBayDimensions[] = {"VTV_cargo_1", "VTV_cargo_2"};
         disableHeightLimit = 1;
         maxLoadMass = 1500;
         cargoAlignment[] = {"center", "front"};
         cargoSpacing[] = {0, 0, 0};
         exits[] = {"VTV_exit"};
         unloadingInterval = 2;
         loadingDistance = 3;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 5;
      };
   };
};
class PTF_M1025_tow : rhsusf_m966_w
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1151 (TOW) [CAT]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};
   hiddenSelections[] = {};
   hiddenSelectionTextures[] = {};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class TOW_Turret: TOW_Turret
      {
            magazines[] = {  
			"rhs_mag_TOW2A",
			"rhs_mag_TOW2A",
			"rhs_mag_TOW2A",
            "rhs_mag_TOW2A",
            "rhs_mag_TOW2A",
            "rhs_mag_TOW2A",
			"rhs_mag_TOW2b_aero",
            "rhs_mag_TOW2b_aero",
			"rhs_mag_TOW2bb",
			"rhs_mag_TOW2bb",
            "rhs_mag_TOW2bb",
            "rhs_mag_TOW2bb",
             };
     };
    class CargoTurret_01: CargoTurret_01 {};
	class CargoTurret_02: CargoTurret_02 {};
	class CargoTurret_03: CargoTurret_03 {};
   };
         class TransportBackpacks
                {
                };
         class TransportMagazines {
            class _xx_rhsusf_100Rnd_762x51_m80a1epr {
                magazine="rhsusf_100Rnd_762x51_m80a1epr";
                count = 5;
            };
            class _xx_rhsusf_200Rnd_556x45_box {
                magazine="rhsusf_200Rnd_556x45_box";
                count = 5;
            };
            class _xx_PTF_Mag_556x45_Mk262_PMAG_Mix{
                magazine="PTF_Mag_556x45_Mk262_PMAG_Mix";
                count = 20;
            };
            class _xx_rhs_mag_an_m8hc {
                magazine="rhs_mag_an_m8hc";
                count = 5;
            };
            class _xx_SmokeShellBlue {
                magazine="SmokeShellBlue";
                count = 5;
            };
            class _xx_rhs_mag_m67 {
                magazine="rhs_mag_m67";
                count = 5;
            };
            class _xx_rhs_fim92_mag {
                magazine="rhs_fim92_mag";
                count = 2;
            };
            class _xx_rhs_fgm148_magazine_AT {
                magazine="rhs_fgm148_magazine_AT";
                count = 1;
            };
		};
		class TransportItems{
            class _xx_ACE_elasticBandage {
                name="ACE_elasticBandage";
                count = 20;
            };
            class _xx_ACE_bloodIV {
                name="ACE_bloodIV";
                count = 3;
            };
            class _xx_ACE_splint {
                name="ACE_splint";
                count = 4;
            };
            class _xx_ACE_tourniquet {
                name="ACE_tourniquet";
                count = 4;
            };
            class _xx_rhsusf_ANPVS_15 {
                name="rhsusf_ANPVS_15";
                count = 2;
            };
            class _xx_ACE_wirecutter {
                name="ACE_wirecutter";
                count = 2;
            };
            class _xx_ToolKit {
                name="ToolKit";
                count = 1;
            };
            class _xx_MineDetector {
                name="MineDetector";
                count = 2;
            };
            class _xx_ACE_Clacker {
                name="ACE_Clacker";
                count = 2;
            };
            class _xx_ACE_DefusalKit {
                name="ACE_DefusalKit";
                count = 2;
            };
            class _xx_ACE_EarPlugs {
                name="ACE_EarPlugs";
                count = 5;
            };
		};
		class TransportWeapons
		{
            class _xx_rhs_weap_M136_hp {
                weapon="rhs_weap_M136_hp"
                count = 1
            };
		};
    class textureSources
      {
      };
   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {"BBox_1_1_pos", "BBox_1_2_pos"};
      };
      class Carrier
      {
         cargoBayDimensions[] = {"VTV_cargo_1", "VTV_cargo_2"};
         disableHeightLimit = 1;
         maxLoadMass = 1500;
         cargoAlignment[] = {"center", "front"};
         cargoSpacing[] = {0, 0, 0};
         exits[] = {"VTV_exit"};
         unloadingInterval = 2;
         loadingDistance = 3;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 5;
      };
   };
  };
};
class cfgMods
{
	author = "3S-15 | M.Hawkins";
	timepacked = "1655154207";
};
