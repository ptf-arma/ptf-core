class PTF_AAV : CUP_B_AAV_USMC
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

   hiddenSelections[] = {"Camo1", "Camo2"};
   hiddenSelectionsTextures[] = {"CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext_co.paa", "CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext2_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MainTurret : MainTurret
      {
         gunnerCompartments = "Compartment1";
         turretInfoType = "CUP_RscOptics_gunner_LAV25";
         castGunnerShadow = 1;
         viewGunnerShadow = 1;
         weapons[] = {"CUP_Vgmg_MK19_AAV", "CUP_Vhmg_M2_AAV_Noeject"};
         magazines[] = {"CUP_96Rnd_40mm_MK19_M", "CUP_96Rnd_40mm_MK19_M", "CUP_96Rnd_40mm_MK19_M", "CUP_96Rnd_40mm_MK19_M", "CUP_96Rnd_40mm_MK19_M", "CUP_96Rnd_40mm_MK19_M", "CUP_96Rnd_40mm_MK19_M", "CUP_96Rnd_40mm_MK19_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M", "CUP_200Rnd_TE1_Red_Tracer_127x99_M"};
         discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900, 4000, 4100, 4200, 4300, 4400, 4500, 4600, 4700, 4800, 4900, 5000};
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
         class Turrets
         {
         };
         class GunFire : WeaponCloudsMGun
         {
            interval = 0.01;
         };
         class OpticsIn
         {
            class Periscope : ViewOptics
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
      class CommanderTurret : NewTurret
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
         soundServo[] = {"", "db-50", 1.0};
         gunBeg = "";
         gunEnd = "";
         commanding = 2;
         gunnerOpticsModel = "\CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\2Dscope_com2";
         gunnerOpticsColor[] = {1, 1, 1, 1};
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
         magazines[] = {"SmokeLauncherMag", "SmokeLauncherMag"};
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
      class CargoGunner_1 : NewTurret
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
         soundServo[] = {"", "db-50", 1.0};
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
         gunnerOutOpticsColor[] = {0, 0, 0, 1};
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
      class CargoGunner_2 : CargoGunner_1
      {
         gunnerCompartments = "Compartment1";
         proxyIndex = 13;
         gunnerName = "$STR_A3_TURRETS_CARGOTURRET_R1";
         animationSourceHatch = "CargoGunner_2";
         memoryPointsGetInGunner = "pos midright";
         memoryPointsGetInGunnerDir = "pos midright dir";
      };
      class CargoGunner_3 : CargoGunner_1
      {
         gunnerCompartments = "Compartment1";
         proxyIndex = 5;
         gunnerName = "$STR_A3_TURRETS_CARGOTURRET_RR";
         animationSourceHatch = "CargoGunner_3";
         memoryPointsGetInGunner = "pos backright";
         memoryPointsGetInGunnerDir = "pos backright dir";
      };
      class CargoGunner_4 : CargoGunner_1
      {
         gunnerCompartments = "Compartment1";
         proxyIndex = 7;
         gunnerName = "$STR_A3_TURRETS_CARGOTURRET_L";
         animationSourceHatch = "CargoGunner_4";
         memoryPointsGetInGunner = "pos frontleft";
         memoryPointsGetInGunnerDir = "pos frontleft dir";
      };
      class CargoGunner_5 : CargoGunner_1
      {
         gunnerCompartments = "Compartment1";
         proxyIndex = 4;
         gunnerName = "$STR_A3_TURRETS_CARGOTURRET_L1";
         animationSourceHatch = "CargoGunner_5";
         memoryPointsGetInGunner = "pos midleft";
         memoryPointsGetInGunnerDir = "pos midleft dir";
      };
      class CargoGunner_6 : CargoGunner_1
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
         textures[] = {"CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext_co.paa", "CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext2_co.paa"};
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
class PTF_AAV_CMD : CUP_B_AAV_Unarmed_USMC
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

   hiddenSelections[] = {"Camo1", "Camo2"};
   hiddenSelectionsTextures[] = {"CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext_co.paa", "CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext2_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MainTurret : CommanderTurret
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
         soundServo[] = {"", "db-50", 1.0};
         gunBeg = "";
         gunEnd = "";
         commanding = 2;
         gunnerOpticsModel = "\CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\2Dscope_com2";
         gunnerOpticsColor[] = {1, 1, 1, 1};
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
      class CommanderTurret : CommanderTurret
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoGunner_1 : CargoGunner_1
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoGunner_2 : CargoGunner_2
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoGunner_3 : CargoGunner_3
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoGunner_4 : CargoGunner_4
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoGunner_5 : CargoGunner_5
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoGunner_6 : CargoGunner_6
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
         textures[] = {"CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext_co.paa", "CUP\TrackedVehicles\CUP_TrackedVehicles_AAV\data\aav_ext2_co.paa"};
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