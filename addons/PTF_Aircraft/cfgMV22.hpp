//MV-22
class PTF_MV22_Ramp : CUP_B_MV22_USMC_RAMPGUN
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
   author = "Paramarine Task Force";
   picture = "\cup\airvehicles\cup_airvehicles_mv22\data\UI\picture_MV22_CA.paa";
   icon = "\cup\airvehicles\cup_airvehicles_mv22\data\UI\icon_MV22_CA.paa";
   displayName = "MV-22 (RampGun)[MAG36]";
   crew = "B_Pilot_F";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment2"};

   weapons[] = {"CMFlareLauncher"};
   magazines[] = {"240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {"camo1", "camo2"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\aircraft\mv22\mv22_1_co.paa", "\PTF_Textures\aircraft\mv22\mv22_2_co.paa"};

   class MFD
   {
#include "vtolmfd.hpp"
   };
   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CopilotTurret : CopilotTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Co-Pilot";
         CanEject = 0;
         gunnerAction = "CUP_MV22_Pilot";
         gunnerInAction = "CUP_MV22_Pilot";
         memoryPointsGetInGunner = "pos driver";
         memoryPointsGetInGunnerDir = "pos driver dir";
         gunnerGetInAction = "GetInHeli_Transport_01Cargo";
         gunnerGetOutAction = "GetOutLow";
         preciseGetInOut = 0;
         GunnerDoor = "";
         gunnerLeftHandAnimName = "";
         gunnerRightHandAnimName = "stick_copilot";
         gunnerLeftLegAnimName = "pedal_l_copilot";
         gunnerRightLegAnimName = "pedal_r_copilot";
         proxyIndex = 1;
         LODTurnedIn = 1100;
         LODTurnedOut = -1;
         commanding = -1;
         isCopilot = 1;
         slingLoadOperator = 0;
         startEngine = 0;
         turretCanSee = 15;
         gunnerNotSpawned = 0;
         gunnerUsePilotView = 1;
         body = "ObsTurret";
         gun = "ObsGun";
         animationSourceBody = "ObsTurret";
         animationSourceGun = "ObsGun";
         outGunnerMayFire = 1;
         InGunnerMayFire = 0;
         gunBeg = "gun_end";
         gunEnd = "gun_begin";
         memoryPointGun = "gun_end";
         weapons[] = {"CUP_Laserdesignator_mounted"};
         magazines[] = {"Laserbatteries"};
         memoryPointGunnerOptics = "commanderview";
         turretInfoType = "RscOptics_GENERAL_FLIR";
         class MFD
         {
#include "vtolmfd.hpp"
         };
         class Components
         {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft
            {
               defaultDisplay = "EmptyDisplay";
               class Components
               {
                  class SensorsDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {16000, 8000, 4000, 2000};
                     resource = "RscCustomInfoSensors";
                  };
                  class CrewDisplay
                  {
                     componentType = "CrewDisplayComponent";
                     resource = "RscCustomInfoCrew";
                  };
                  class MinimapDisplay
                  {
                     componentType = "MinimapDisplayComponent";
                     resource = "RscCustomInfoMiniMap";
                  };
                  class EmptyDisplay
                  {
                     componentType = "EmptyDisplayComponent";
                  };
               };
            };
            class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight
            {
               defaultDisplay = "SensorsDisplay";
               class Components
               {
                  class SensorsDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {16000, 8000, 4000, 2000};
                     resource = "RscCustomInfoSensors";
                  };
                  class CrewDisplay
                  {
                     componentType = "CrewDisplayComponent";
                     resource = "RscCustomInfoCrew";
                  };
                  class MinimapDisplay
                  {
                     componentType = "MinimapDisplayComponent";
                     resource = "RscCustomInfoMiniMap";
                  };
                  class EmptyDisplay
                  {
                     componentType = "EmptyDisplayComponent";
                  };
               };
            };
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
         gunnerHasFlares = 0;
      };
      class RightDoorGun : NewTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Ramp Gunner";
         commanding = -1;
         weapons[] = {"CUP_Vlmg_M240_veh"};
         magazines[] = {"CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M", "CUP_100Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M"};
         selectionFireAnim = "zasleh";
         soundServo[] = {"", 1, 1};
         startEngine = 0;
         hasGunner = 1;
         gunnerAction = "CUP_CH47_Gunner01";
         gunnerInAction = "CUP_CH47_Gunner01";
         minElev = -85;
         maxElev = 15;
         initElev = 0;
         initTurn = 180;
         minTurn = 80;
         maxTurn = 270;
         maxHorizontalRotSpeed = 1.2;
         maxVerticalRotSpeed = 1.2;
         class ViewOptics
         {
            initAngleX = 0;
            minAngleX = -85;
            maxAngleX = 15;
            initAngleY = 180;
            minAngleY = 85;
            maxAngleY = 275;
            initFov = 0.5;
            minFov = 0.5;
            maxFov = 0.5;
         };
         class ViewGunner
         {
            initAngleX = 0;
            minAngleX = -85;
            maxAngleX = 15;
            initAngleY = 0;
            minAngleY = -90;
            maxAngleY = 90;
            initFov = 0.5;
            minFov = 0.5;
            maxFov = 0.5;
         };
         gunnerOpticsModel = "\A3\Weapons_F\Reticle\optics_empty";
         gunnerForceOptics = 0;
         gunnerOpticsShowCursor = 0;
         memoryPointsGetInGunner = "pos cargo";
         memoryPointsGetInGunnerDir = "pos cargo dir";
         memoryPointGunnerOptics = "gunnerview";
         memoryPointGunnerOutOptics = "gunnerview_2";
         body = "mainTurret";
         gun = "mainGun";
         gunBeg = "usti hlavne";
         gunEnd = "konec hlavne";
         animationSourceBody = "mainTurret";
         animationSourceGun = "mainGun";
         turretInfoType = "RscWeaponRangeFinder";
         stabilizedInAxes = "StabilizedInAxesNone";
         castGunnerShadow = 0;
         viewGunnerShadow = 0;
         outGunnerMayFire = 1;
         proxyIndex = 3;
         class MFD
         {
#include "vtolmfd.hpp"
         };
      };
   };
   class textureSources
   {
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
class PTF_MV22_Cargo : CUP_B_MV22_VIV_USMC
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 400;
   ace_cargo_space = 60;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   author = "Paramarine Task Force";
   picture = "\cup\airvehicles\cup_airvehicles_mv22\data\UI\picture_MV22_CA.paa";
   icon = "\cup\airvehicles\cup_airvehicles_mv22\data\UI\icon_MV22_CA.paa";
   displayName = "MV-22 Cargo [MAG36]";
   crew = "B_Pilot_F";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment2"};

   weapons[] = {"CMFlareLauncher"};
   magazines[] = {"240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {"camo1", "camo2"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\aircraft\mv22\cargo\mv22_1_co.paa", "\PTF_Textures\aircraft\mv22\cargo\mv22_2_co.paa"};

   class MFD
   {
#include "vtolmfd.hpp"
   };
   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CopilotTurret : CopilotTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Co-Pilot";
         CanEject = 0;
         gunnerAction = "CUP_MV22_Pilot";
         gunnerInAction = "CUP_MV22_Pilot";
         memoryPointsGetInGunner = "pos driver";
         memoryPointsGetInGunnerDir = "pos driver dir";
         gunnerGetInAction = "GetInHeli_Transport_01Cargo";
         gunnerGetOutAction = "GetOutLow";
         preciseGetInOut = 0;
         GunnerDoor = "";
         gunnerLeftHandAnimName = "";
         gunnerRightHandAnimName = "stick_copilot";
         gunnerLeftLegAnimName = "pedal_l_copilot";
         gunnerRightLegAnimName = "pedal_r_copilot";
         proxyIndex = 1;
         LODTurnedIn = 1100;
         LODTurnedOut = -1;
         commanding = -1;
         isCopilot = 1;
         slingLoadOperator = 0;
         startEngine = 0;
         turretCanSee = 15;
         gunnerNotSpawned = 0;
         gunnerUsePilotView = 1;
         body = "ObsTurret";
         gun = "ObsGun";
         animationSourceBody = "ObsTurret";
         animationSourceGun = "ObsGun";
         outGunnerMayFire = 1;
         InGunnerMayFire = 0;
         gunBeg = "gun_end";
         gunEnd = "gun_begin";
         memoryPointGun = "gun_end";
         weapons[] = {"CUP_Laserdesignator_mounted"};
         magazines[] = {"Laserbatteries"};
         memoryPointGunnerOptics = "commanderview";
         turretInfoType = "RscOptics_GENERAL_FLIR";
         class MFD
         {
#include "vtolmfd.hpp"
         };
         class Components
         {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft
            {
               defaultDisplay = "EmptyDisplay";
               class Components
               {
                  class SensorsDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {16000, 8000, 4000, 2000};
                     resource = "RscCustomInfoSensors";
                  };
                  class CrewDisplay
                  {
                     componentType = "CrewDisplayComponent";
                     resource = "RscCustomInfoCrew";
                  };
                  class MinimapDisplay
                  {
                     componentType = "MinimapDisplayComponent";
                     resource = "RscCustomInfoMiniMap";
                  };
                  class EmptyDisplay
                  {
                     componentType = "EmptyDisplayComponent";
                  };
               };
            };
            class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight
            {
               defaultDisplay = "SensorsDisplay";
               class Components
               {
                  class SensorsDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {16000, 8000, 4000, 2000};
                     resource = "RscCustomInfoSensors";
                  };
                  class CrewDisplay
                  {
                     componentType = "CrewDisplayComponent";
                     resource = "RscCustomInfoCrew";
                  };
                  class MinimapDisplay
                  {
                     componentType = "MinimapDisplayComponent";
                     resource = "RscCustomInfoMiniMap";
                  };
                  class EmptyDisplay
                  {
                     componentType = "EmptyDisplayComponent";
                  };
               };
            };
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
         gunnerHasFlares = 0;
      };
   };
   class textureSources
   {
   };
   class VehicleTransport
   {
      class Carrier
      {
         cargoBayDimensions[] = {"VTV_limit_1", "VTV_limit_2"};
         disableHeightLimit = 1;
         maxLoadMass = 9000;
         cargoAlignment[] = {"center", "front"};
         cargoSpacing[] = {0, 0, 0};
         exits[] = {"VTV_exit_1"};
         unloadingInterval = 2;
         loadingDistance = 20;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 50;
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