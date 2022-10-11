//MQ-9
class PTF_MQ9 : USAF_MQ9
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   faction = "BLU_F";
   crew = "B_UAV_AI";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 600;
   author = "Paramarine Task Force";
   displayName = "MQ-9 [MAG36]";

   driverOpticsModel = "USAF_MQ9\optic_mq9.p3d";

   weapons[] = {"CMFlareLauncher"};
   magazines[] = {"240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {"camo1", "camo2", "camo3", "tail_number_pre", "tail_number0", "tail_number1", "tail_number2", "tail_letter0", "tail_letter1", "tail_logo", "tail_art"};
   hiddenSelectionsTextures[] = {"USAF_MQ9\data\USAF_MQ9_co.paa", "USAF_MQ9\data\USAF_MQ9_Wing_co.paa", "usaf_mq9\data\usaf_MQ9_hinges_co.paa", "", "\PTF_Textures\aircraft\3_ca.paa", "\PTF_Textures\aircraft\6_ca.paa", "", "", "", "", ""};

   class TextureSources
   {
   };

	class Turrets
		{
			class MainTurret: NewTurret
			{
				isCopilot = 0;
				minElev = -90;
				maxElev = 10;
				initElev = 0;
				minTurn = -360;
				maxTurn = 360;
				initTurn = 0;
				outGunnerMayFire = "true";
				inGunnerMayFire = "true";
				commanding = -1;
				body = "mainTurret";
				gun = "mainGun";
				animationSourceBody = "mainTurret";
				animationSourceGun = "mainGun";
				memoryPointGun = "mainGun";
				memoryPointGunnerOptics = "mainGun";
				gunBeg = "laser_end";
				gunEnd = "laser_start";
				gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
				gunnerOpticsEffect[] = {"TankCommanderOptics1","BWTVedit"};
				gunnerForceOptics = "true";
				turretInfoType = "Rsc_USAF_RQ4A_Turret_UI";
				turretCanSee = "1 + 2 + 4 + 8 + 16";
				stabilizedInAxes = 3;
				enableManualFire = 1;
				weapons[] = {"Laserdesignator_mounted"};
				magazines[] = {"Laserbatteries"};
				GunnerCompartments = "Compartment1";
				gunnerInAction = "Disabled";
				gunnerAction = "Disabled";
				startEngine = 0;
				class OpticsIn
				{
					class Wide
					{
						opticsDisplayName = "ULTW";
						initAngleX = 0;
						minAngleX = -35;
						maxAngleX = 10;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 0.466;
						minFov = 0.466;
						maxFov = 0.466;
						visionMode[] = {"Normal","NVG","Ti"};
						thermalMode[] = {0,1};
						gunnerOpticsColor[] = {0.15,1,0.15,1};
						gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
						directionStabilized = 1;
						opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
						gunnerOpticsEffect[] = {"TankCommanderOptics1","BWTVedit"};
					};
					class WideL: Wide
					{
						opticsDisplayName = "WIDE";
						initFov = 0.2;
						minFov = 0.2;
						maxFov = 0.2;
						gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
						gunnerOpticsColor[] = {0,0,0,1};
						directionStabilized = 1;
						opticsPPEffects[] = {"OpticsCHAbera2","OpticsBlur2"};
					};
					class Medium: Wide
					{
						opticsDisplayName = "MED";
						initFov = 0.1;
						minFov = 0.1;
						maxFov = 0.1;
						directionStabilized = 1;
						gunnerOpticsColor[] = {0,0,0,1};
						gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
					};
					class Narrow: Wide
					{
						opticsDisplayName = "NM";
						gunnerOpticsColor[] = {0,0,0,1};
						gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
						directionStabilized = 1;
						initFov = 0.02;
						minFov = 0.02;
						maxFov = 0.02;
					};
					class Narrower: Wide
					{
						opticsDisplayName = "NAR";
						gunnerOpticsColor[] = {0,0,0,1};
						gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
						directionStabilized = 1;
						initFov = 0.01;
						minFov = 0.01;
						maxFov = 0.01;
					};
					class UltraNarrow: Narrower
					{
						opticsDisplayName = "ULTN";
						gunnerOpticsColor[] = {0,0,0,1};
						gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
						directionStabilized = 1;
						initFov = 0.0005;
						minFov = 0.0005;
						maxFov = 0.0005;
					};
				};
				class OpticsOut
				{
					class Monocular
					{
						initAngleX = 0;
						minAngleX = -30;
						maxAngleX = 30;
						initAngleY = 0;
						minAngleY = -100;
						maxAngleY = 100;
						initFov = 1.1;
						minFov = 0.133;
						maxFov = 1.1;
						visionMode[] = {"Normal","NVG"};
						gunnerOpticsModel = "";
						gunnerOpticsEffect[] = {};
					};
				};
				class Components
				{
					class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftPilot
					{
						componentType = "VehicleSystemsDisplayManager";
						defaultDisplay = "EmptyDisplay";
						left = 1;
						x = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFOLEFT_X"",	(safezoneX + 0.5 * (((safezoneW / safezoneH) min 1.2) / 40))])";
						y = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFOLEFT_Y"",	(safezoneY + safezoneH - 21 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
					};
					class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsDisplayManagerComponentLeft
					{
						left = 0;
						right = 1;
						defaultDisplay = "EmptyDisplay";
						x = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFORIGHT_X"", ((safezoneX + safezoneW) - ((10 * (((safezoneW / safezoneH) min 1.2) / 40)) + 0.5 * (((safezoneW / safezoneH) min 1.2) / 40)))])";
						y = "(profilenamespace getvariable [""IGUI_GRID_CUSTOMINFORIGHT_Y"", (safezoneY + safezoneH - 21 * ((((safezoneW / safezoneH) min 1.2) / 1.2) / 25))])";
					};
				};
			};
		};

   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
