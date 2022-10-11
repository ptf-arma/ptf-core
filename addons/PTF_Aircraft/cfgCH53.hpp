//CH-53E
class PTF_CH53_Ramp : rhsusf_CH53E_USMC_GAU21_D
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 400;
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   driverCanSee = 31;
   gunnerCanSee = 31;
   author = "Paramarine Task Force";
   displayName = "CH-53E GAU-21 [MAG36]";
   crew = "B_Pilot_F";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment2"};

   weapons[] = {"CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {"camo", "camo1", "n1", "n2"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\aircraft\ch53\ch53_1_co.paa", "\PTF_Textures\aircraft\ch53\ch53_acc_co.paa", "\PTF_Textures\aircraft\3_ca.paa", "\PTF_Textures\aircraft\6_ca.paa"};

   class MFD
   {
#include "rotarymfd.hpp"
   };
   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CopilotTurret : MainTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerAction = "RHS_CH53_Pilot";
         gunnerInAction = "RHS_CH53_Pilot";
         memoryPointsGetInGunner = "pos codriver";
         memoryPointsGetInGunnerDir = "pos codriver dir";
         gunnerGetInAction = "GetInLow";
         gunnerGetOutAction = "GetOutLow";
         GunnerDoor = "";     //door_back_L but i don't think we need this
         LODTurnedIn = 1000;  //view_gunner
         LODTurnedOut = 1000; //do not change
         body = "ObsTurret";
         gun = "ObsGun";
         animationSourceBody = "ObsTurret";
         animationSourceGun = "ObsGun";
         gunBeg = "flir_end";   //gunBeg=endpoint of the gun
         gunEnd = "flir_begin"; //gunEnd=chamber of the gun
         memoryPointGun = "flir_end";
         memoryPointGunnerOptics = "commanderview";
         stabilizedInAxes = 3;
         minElev = -90;
         maxElev = 38.2;
         initElev = 0;
         minTurn = -70; //THIS IS TO AVOID SHOWING HOLES IN THE 3D MODEL, DO NOT CHANGE WITHOUT TESTING
         maxTurn = 70;  //THIS IS TO AVOID SHOWING HOLES IN THE 3D MODEL, DO NOT CHANGE WITHOUT TESTING
         initTurn = 0;
         gunnerName = "Co-Pilot";
         isCopilot = 1;
         turretInfoType = "RscOptics_GENERAL_FLIR";
         soundServo[] = {"", 0.01, 1.0, 30};
         weapons[] = {"rhs_weap_laserDesignator_AI"};
         magazines[] = {"rhs_LaserMag_ai"};
         inGunnerMayFire = 1;
         precisegetinout = 0;
         gunnerOpticsEffect[] = {};
         gunnerOpticsModel = "";
         gunnerLeftHandAnimName = "lever_copilot"; //these don't work for now, anims and inverse kinematics need to be added
         gunnerRightHandAnimName = "stick_copilot";
         gunnerLeftLegAnimName = "pedalL";
         gunnerRightLegAnimName = "pedalR";
         usePiP = 1;
         CanEject = 1;
         primaryGunner = 1;
         proxyIndex = 1;
         commanding = -1;
         gunnerOpticsShowCursor = 1;
         showgunneroptics = 1;
         gunnerForceOptics = 0;
         gunnerOpticsColor[] = {0.227, 0.769, 0.24, 1};
         gunnerForceOutOptics = 0;
         gunnerUsesPilotView = 0;
         hasGunner = 1;
         hideWeaponsGunner = 1;
         lockWhenDriverOut = 0;
         enableManualFire = 1;
         maxHorizontalRotSpeed = 3.2;
         maxVerticalRotSpeed = 3.2;
         outGunnerMayFire = 1;
         showHMD = 0;
         class MFD
         {
#include "rotarymfd.hpp"
         };
         class OpticsIn
         {
#include "rotaryoptics.hpp"
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
               visionMode[] = {"Normal", "NVG"};
               gunnerOpticsModel = "";
               gunnerOpticsEffect[] = {};
            };
         };
         startEngine = 0;
         gunnerHasFlares = 0;
      };
      class GAU21 : MainTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerType = "rhsusf_usmc_marpat_wd_helicrew";
         usePiP = 0;
         isCopilot = 0;
         showAsCargo = 1;
         proxyIndex = 2;
         animationSourceBody = "mainTurret";
         animationSourceGun = "mainGun";
         body = "mainTurret";
         gun = "mainGun";
         minElev = -60;
         maxElev = 7;
         initElev = 0;
         minTurn = 90;
         maxTurn = 270;
         initTurn = 180;
         lodturnedout = 1200;
         lodturnedin = 1200;
         lodopticsout = 1200;
         lodopticsin = 1200;
         soundServo[] =
             {
                 "",
                 0.01,
                 1};
         gunnerLeftHandAnimName = "OtocHlaven_1";
         gunnerRightHandAnimName = "OtocHlaven_1";
         gunnerLeftLegAnimName = "gunner_1_leg_left";
         gunnerRightLegAnimName = "gunner_1_legs";
         gunnerAction = "RHS_Ch53_Gunner_Ramp";
         gunnerInAction = "RHS_Ch53_Gunner_Ramp";
         animationSourceHatch = "";
         stabilizedInAxes = "StabilizedInAxesNone";
         gunBeg = "muzzle_1";
         gunEnd = "chamber_1";
         selectionFireAnim = "zasleh_1";
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_gau21_1"};
         magazines[] =
             {
                 "rhs_mag_300rnd_127x99_mag_Tracer_Red",
                 "rhs_mag_300rnd_127x99_mag_Tracer_Red",
                 "rhs_mag_300rnd_127x99_mag_Tracer_Red",
                 "rhs_mag_300rnd_127x99_mag_Tracer_Red",
                 "rhs_mag_300rnd_127x99_mag_Tracer_Red"};
         gunnerName = "Ramp Gunner";
         gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
         gunnerOutOpticsShowCursor = 1;
         gunnerOpticsShowCursor = 1;
         memoryPointsGetInGunner = "pos cargo";
         memoryPointsGetInGunnerDir = "pos cargo dir";
         gunnerGetInAction = "GetInLow";
         gunnerGetOutAction = "GetOutLow";
         preciseGetInOut = 0;
         turretInfoType = "RscWeaponZeroing";
         commanding = -2;
         playerPosition = 1;
         primaryGunner = 0;
         class MFD
         {
#include "rotarymfd.hpp"
         };
      };
   };
   class textureSources
   {
      class USMC
      {
         displayName = "USMC";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_ch53\data\ch53_1_co.paa", "rhsusf\addons\rhsusf_ch53\data\ch53_acc_co.paa"};
         decals[] = {};
         factions[] = {};
      };
      class PTF
      {
         displayName = "PTF";
         author = "J.Downs";
         textures[] = {
             "\PTF_Textures\aircraft\ch53\ch53.paa", "\PTF_Textures\aircraft\ch53\acc.paa", "\PTF_Textures\aircraft\ch53\3_ca.paa", "\PTF_Textures\aircraft\ch53\6_ca.paa"};
         decals[] = {};
         factions[] = {};
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
class PTF_CH53_Cargo : rhsusf_CH53e_USMC_D_cargo
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 60;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   driverCanSee = 31;
   gunnerCanSee = 31;
   side = 1;
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 400;
   author = "Paramarine Task Force";
   displayName = "CH-53E Cargo [MAG36]";
   crew = "B_Pilot_F";
   driverCompartments = "Compartment1";

   weapons[] = {"CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {"camo", "camo1", "n1", "n2"};
   hiddenSelectionsTextures[] = {
       "\PTF_Textures\aircraft\ch53\cargo\ch53_1_co.paa", "\PTF_Textures\aircraft\ch53\cargo\ch53_acc_co.paa", "\PTF_Textures\aircraft\3_ca.paa", "\PTF_Textures\aircraft\6_ca.paa"};

   class MFD
   {
#include "rotarymfd.hpp"
   };
   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CopilotTurret : MainTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerAction = "RHS_CH53_Pilot";
         gunnerInAction = "RHS_CH53_Pilot";
         memoryPointsGetInGunner = "pos codriver";
         memoryPointsGetInGunnerDir = "pos codriver dir";
         gunnerGetInAction = "GetInLow";
         gunnerGetOutAction = "GetOutLow";
         GunnerDoor = "";     //door_back_L but i don't think we need this
         LODTurnedIn = 1000;  //view_gunner
         LODTurnedOut = 1000; //do not change
         body = "ObsTurret";
         gun = "ObsGun";
         animationSourceBody = "ObsTurret";
         animationSourceGun = "ObsGun";
         gunBeg = "flir_end";   //gunBeg=endpoint of the gun
         gunEnd = "flir_begin"; //gunEnd=chamber of the gun
         memoryPointGun = "flir_end";
         memoryPointGunnerOptics = "commanderview";
         stabilizedInAxes = 3;
         minElev = -90;
         maxElev = 38.2;
         initElev = 0;
         minTurn = -70; //THIS IS TO AVOID SHOWING HOLES IN THE 3D MODEL, DO NOT CHANGE WITHOUT TESTING
         maxTurn = 70;  //THIS IS TO AVOID SHOWING HOLES IN THE 3D MODEL, DO NOT CHANGE WITHOUT TESTING
         initTurn = 0;
         gunnerName = "$STR_A3_COPILOT";
         isCopilot = 1;
         turretInfoType = "RscOptics_GENERAL_FLIR";
         soundServo[] = {"", 0.01, 1.0, 30};
         weapons[] = {"rhs_weap_laserDesignator_AI"};
         magazines[] = {"rhs_LaserMag_ai"};
         inGunnerMayFire = 1;
         precisegetinout = 0;
         gunnerOpticsEffect[] = {};
         gunnerOpticsModel = "";
         gunnerLeftHandAnimName = "lever_copilot"; //these don't work for now, anims and inverse kinematics need to be added
         gunnerRightHandAnimName = "stick_copilot";
         gunnerLeftLegAnimName = "pedalL";
         gunnerRightLegAnimName = "pedalR";
         usePiP = 1;
         CanEject = 1;
         primaryGunner = 1;
         proxyIndex = 1;
         commanding = -1;
         gunnerOpticsShowCursor = 1;
         showgunneroptics = 1;
         gunnerForceOptics = 0;
         gunnerOpticsColor[] = {0.227, 0.769, 0.24, 1};
         gunnerForceOutOptics = 0;
         gunnerUsesPilotView = 0;
         hasGunner = 1;
         hideWeaponsGunner = 1;
         lockWhenDriverOut = 0;
         enableManualFire = 1;
         maxHorizontalRotSpeed = 3.2;
         maxVerticalRotSpeed = 3.2;
         outGunnerMayFire = 1;
         showHMD = 0;
         class MFD
         {
#include "rotarymfd.hpp"
         };
         class OpticsIn
         {
#include "rotaryoptics.hpp"
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
               visionMode[] = {"Normal", "NVG"};
               gunnerOpticsModel = "";
               gunnerOpticsEffect[] = {};
            };
         };
         startEngine = 0;
         gunnerHasFlares = 0;
      };
   };
   class textureSources
   {
      class USMC
      {
         displayName = "USMC";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_ch53\data\ch53_1_co.paa", "rhsusf\addons\rhsusf_ch53\data\ch53_acc_co.paa"};
         decals[] = {};
         factions[] = {};
      };
      class PTF
      {
         displayName = "PTF";
         author = "J.Downs";
         textures[] = {
             "\PTF_Textures\aircraft\ch53\ch53.paa", "\PTF_Textures\aircraft\ch53\acc.paa", "\PTF_Textures\aircraft\ch53\3_ca.paa", "\PTF_Textures\aircraft\ch53\6_ca.paa"};
         decals[] = {};
         factions[] = {};
      };
   };
   class VehicleTransport
   {
      class Carrier
      {
         cargoBayDimensions[] = {"VTV_limit_1_big", "VTV_limit_2_big"};
         disableHeightLimit = 1;
         maxLoadMass = 9000;
         cargoAlignment[] = {"front", "center"};
         cargoSpacing[] = {0.075, 0.075, 0.075};
         exits[] = {"VTV_exit_1"};
         unloadingInterval = 2;
         loadingDistance = 20;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 25;
      };
      class Cargo
      {
         canBeTransported = 0;
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