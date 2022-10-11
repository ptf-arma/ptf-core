//UH-1Y
class PTF_UH1Y : RHS_UH1Y_d
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 300;
   ace_fastroping_enabled = 2;
   ace_fastroping_friesType = "ACE_friesAnchorBar";
   ace_fastroping_onCut = "ace_fastroping_fnc_onCutCommon";
   ace_fastroping_onPrepare = "ace_fastroping_fnc_onPrepareCommon";
   ace_fastroping_ropeOrigins[] = {"ropeOriginLeft", "ropeOriginRight"};
   ace_cargo_space = 20;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 10;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   armorStructural = 1000;
   armor=1000;
   hullDamageCauseExplosion = 0;
   maximumLoad = 375;
   driverCanSee = 31;
   gunnerCanSee = 31;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (FFAR/MG) [MAG36]";
   crew = "B_Pilot_F";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};
   weapons[] = {
       "PTF_weap_mastersafe",
       "CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_ext_co.paa", "rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_int_co.paa"};

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
         class MFD
         {
#include "rotarymfd.hpp"
         };
         primaryObserver = 0;
         slingLoadOperator = 1;
         primaryGunner = 1;
         primary = 1;
         playerPosition = 0;
         isCopilot = 1;
         usePiP = 1;
         gunnerName = "Co-Pilot";
         weapons[] = {"rhs_weap_laserDesignator_AI"};
         magazines[] = {"rhs_LaserMag_ai"};
         gunnerAction = "RHS_UH1Y_Copilot";
         gunnerInAction = "RHS_UH1Y_Copilot";
         body = "ObsTurret";
         gun = "ObsGun";
         animationSourceBody = "ObsTurret";
         animationSourceGun = "ObsGun";
         gunBeg = "gun_end";
         gunEnd = "gun_begin";
         memoryPointGun = "gun_end";
         memoryPointGunnerOptics = "commanderview";
         turretInfoType = "RscOptics_GENERAL_FLIR";
         initElev = 0;
         minElev = -80;
         maxElev = 30;
         minTurn = -180;
         maxTurn = 180;
         CanEject = 0;
         memoryPointsGetInGunner = "pos codriver";
         memoryPointsGetInGunnerDir = "pos codriver dir";
         gunnerGetInAction = "copilot_Heli_Light_02_Enter";
         gunnerGetOutAction = "copilot_Heli_Light_02_Exit";
         selectionFireAnim = "";
         preciseGetInOut = 1;
         GunnerDoor = "DoorL";
         gunnerLeftHandAnimName = "lever_copilot";
         gunnerRightHandAnimName = "stick_copilot";
         gunnerLeftLegAnimName = "";
         gunnerRightLegAnimName = "";
         proxyIndex = 1;
         commanding = -1;
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
      };
      class MainTurret : MainTurret
      {
         gunnerCompartments = "Compartment1";
         usePiP = 0;
         isCopilot = 0;
         showAsCargo = 1;
         proxyIndex = 2;
         animationSourceBody = "mainTurret";
         animationSourceGun = "mainGun";
         body = "mainTurret";
         gun = "mainGun";
         minElev = -55;
         maxElev = 20;
         initElev = 0;
         minTurn = 0;
         maxTurn = 170;
         initTurn = 0;
         soundServo[] =
             {
                 "",
                 0.01,
                 1};
         gunnerLeftHandAnimName = "gunner_1_hand_l";
         gunnerRightHandAnimName = "gunner_1_hand_r";
         gunnerLeftLegAnimName = "gunner_1_leg_left";
         gunnerRightLegAnimName = "gunner_1_leg_right";
         animationSourceStickX = "MainTurret_1_Inertia";
         animationSourceStickY = "MainGun_1_Inertia";
         gunnerAction = "RHS_UH1Y_Gunner_L";
         gunnerInAction = "RHS_UH1Y_Gunner_L";
         animationSourceHatch = "";
         stabilizedInAxes = StabilizedInAxesNone;
         gunBeg = "muzzle_1";
         gunEnd = "chamber_1";
         selectionFireAnim = "zasleh";
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_m134_minigun_1"};
         magazines[] =
             {
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000"};
         gunnerName = "Left Door Gunner";
         gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
         gunnerOutOpticsShowCursor = 1;
         gunnerOpticsShowCursor = 1;
         gunnerGetInAction = "GetInHeli_Transport_01Cargo";
         gunnerGetOutAction = "RHS_Heli_Cargo_Exit";
         preciseGetInOut = 0;
         turretInfoType = "RscWeaponZeroing";
         commanding = -2;
         playerPosition = 1;
         primaryGunner = 0;
         class ViewOptics
         {
            initanglex = 0;
            initangley = 0;
            initfov = 0.7;
            maxanglex = 75;
            maxangley = 100;
            maxfov = 1.1;
            minanglex = -75;
            minangley = -100;
            minfov = 0.25;
         };
         class ViewGunner : ViewOptics
         {
            initanglex = 0;
            initangley = 0;
            initfov = 0.7;
            maxanglex = 75;
            maxangley = 100;
            maxfov = 1.1;
            minanglex = -75;
            minangley = -100;
            minfov = 0.25;
            visionMode[] = {};
         };
         class OpticsIn
         {
            class ViewOptics : ViewGunner
            {
               gunnerOpticsModel = "\A3\weapons_f\reticle\optics_empty";
               gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
            };
         };
         memoryPointGun = "machinegun";
         memoryPointGunnerOptics = "gunnerview_1";
         soundAttenuationTurret = "HeliAttenuationGunner";
         //gunnerDoor="DoorLB";
         class Reflectors
         {
         };
         class Components
         {
         };
         class Hitpoints
         {
         };
      };
      class RightDoorGun : MainTurret
      {
         gunnerCompartments = "Compartment1";
         body = "Turret_2";
         gun = "Gun_2";
         animationSourceBody = "Turret_2";
         animationSourceGun = "Gun_2";
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_m134_minigun_2"};
         stabilizedInAxes = StabilizedInAxesNone;
         selectionFireAnim = "zasleh_1";
         proxyIndex = 3;
         playerPosition = 1;
         gunnerName = "Right Door Gunner";
         commanding = -3;
         minElev = -55;
         maxElev = 20;
         initElev = 0;
         minTurn = -173;
         maxTurn = -0;
         initTurn = -170;
         gunBeg = "muzzle_2";
         gunEnd = "chamber_2";
         primaryGunner = 0;
         memoryPointGun = "machinegun_1";
         memoryPointGunnerOptics = "gunnerview_2";
         gunnerLeftHandAnimName = "gunner_2_hand_l";
         gunnerRightHandAnimName = "gunner_2_hand_r";
         gunnerLeftLegAnimName = "gunner_2_leg_left";
         gunnerRightLegAnimName = "gunner_2_legs";
         animationSourceStickX = "MainTurret_2_inertia";
         animationSourceStickY = "MainGun_2_Inertia";
         gunnerAction = "RHS_UH1Y_Gunner_R";
         gunnerInAction = "RHS_UH1Y_Gunner_R";
         //gunnerDoor="DoorRB";
      };
      class CargoTurret_01 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         weapons[] = {"rhsusf_weap_DummyLauncher"};
         gunnerAction = "passenger_inside_2";
         gunnerGetInAction = "GetInHeli_Transport_01Cargo";
         gunnerGetOutAction = "RHS_Heli_Cargo_Exit";
         memoryPointsGetInGunner = "pos cargo R";
         memoryPointsGetInGunnerDir = "pos cargo R dir";
         gunnerName = "Passenger (Right Rear)";
         memoryPointGunnerOptics = "";
         proxyIndex = 1;
         maxElev = 15;
         minElev = -45;
         maxTurn = -48;
         minTurn = -104;
         isPersonTurret = 1;
         gunnerUsesPilotView = 1;
         selectionFireAnim = "";
         gunnerCanEject = 1;
         cantCreateAI = 1;
         commanding = -1;
         playerPosition = 1;
         soundAttenuationTurret = "HeliAttenuationRamp";
         disableSoundAttenuation = 0;
         class Hitpoints
         {
         };
      };
      class CargoTurret_02 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Right Front)";
         memoryPointsGetInGunner = "pos cargo R4";
         memoryPointsGetInGunnerDir = "pos cargo R4 dir";
         proxyIndex = 3;
         maxTurn = 47;
         minTurn = 22;
      };
      class CargoTurret_03 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Right Middle)";
         memoryPointsGetInGunner = "pos cargo R2";
         memoryPointsGetInGunnerDir = "pos cargo R2 dir";
         proxyIndex = 6;
         maxTurn = 70;
         minTurn = 22;
      };
      class CargoTurret_04 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
         memoryPointsGetInGunner = "pos cargo L";
         memoryPointsGetInGunnerDir = "pos cargo L dir";
         gunnerName = "Passenger (Left Middle)";
         proxyIndex = 2;
         maxTurn = 104;
         minTurn = 58;
      };
      class CargoTurret_05 : CargoTurret_04
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Left Front)";
         memoryPointsGetInGunner = "pos cargo L4";
         memoryPointsGetInGunnerDir = "pos cargo L4 dir";
         proxyIndex = 4;
         maxTurn = -16;
         minTurn = -40;
      };
      class CargoTurret_06 : CargoTurret_04
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Left Rear)";
         memoryPointsGetInGunner = "pos cargo L2";
         memoryPointsGetInGunnerDir = "pos cargo L2 dir";
         proxyIndex = 7;
         maxTurn = 3;
         minTurn = -55;
      };
   };
   class textureSources
   {
      class USMC
      {
         displayName = "USMC";
         author = "S4 Logistics";
         textures[] = {
             "rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_ext_co.paa", "rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_int_co.paa"};
         decals[] = {};
         factions[] = {};
      };
      class HQ
      {
         displayName = "HQ";
         author = "S4 Logistics";
         textures[] = {
             "\PTF_Textures\Aircraft\UH1Y\HQ\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa"};
         decals[] = {};
         factions[] = {};
      };
      class GunfightersSL
      {
         displayName = "Gunfighters SL";
         author = "S4 Logistics";
         textures[] = {
             "\PTF_Textures\Aircraft\UH1Y\GunfightersSL\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa"};
         decals[] = {};
         factions[] = {};
      };
      class Gunfighters
      {
         displayName = "Gunfighters";
         author = "S4 Logistics";
         textures[] = {
             "\PTF_Textures\Aircraft\UH1Y\Gunfighters\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa"};
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
class PTF_UH1Y_Unarmed : RHS_UH1Y_UNARMED_d
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_AIR";
   side = 1;
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 300;
   ace_fastroping_enabled = 2;
   ace_fastroping_friesType = "ACE_friesAnchorBar";
   ace_fastroping_onCut = "ace_fastroping_fnc_onCutCommon";
   ace_fastroping_onPrepare = "ace_fastroping_fnc_onPrepareCommon";
   ace_fastroping_ropeOrigins[] = {"ropeOriginLeft", "ropeOriginRight"};
   ace_cargo_space = 20;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 10;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   armorStructural = 1000;
   armor=1000;
   hullDamageCauseExplosion = 0;
   maximumLoad = 375;
   driverCanSee = 31;
   gunnerCanSee = 31;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (Trainer) [MAG36]";
   crew = "B_Pilot_F";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};
   weapons[] = {"CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {
       "\PTF_Textures\aircraft\uh1y\Trainer\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

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
         primaryObserver = 0;
         slingLoadOperator = 1;
         primaryGunner = 1;
         primary = 1;
         playerPosition = 0;
         isCopilot = 1;
         usePiP = 1;
         class MFD
         {
#include "rotarymfd.hpp"
         };
         gunnerName = "Co-Pilot";
         weapons[] = {"rhs_weap_laserDesignator_AI"};
         magazines[] = {"rhs_LaserMag_ai"};
         gunnerAction = "RHS_UH1Y_Copilot";
         gunnerInAction = "RHS_UH1Y_Copilot";
         body = "ObsTurret";
         gun = "ObsGun";
         animationSourceBody = "ObsTurret";
         animationSourceGun = "ObsGun";
         gunBeg = "gun_end";
         gunEnd = "gun_begin";
         memoryPointGun = "gun_end";
         memoryPointGunnerOptics = "commanderview";
         turretInfoType = "RscOptics_GENERAL_FLIR";
         initElev = 0;
         minElev = -80;
         maxElev = 30;
         minTurn = -180;
         maxTurn = 180;
         CanEject = 0;
         memoryPointsGetInGunner = "pos codriver";
         memoryPointsGetInGunnerDir = "pos codriver dir";
         gunnerGetInAction = "copilot_Heli_Light_02_Enter";
         gunnerGetOutAction = "copilot_Heli_Light_02_Exit";
         selectionFireAnim = "";
         preciseGetInOut = 1;
         GunnerDoor = "DoorL";
         gunnerLeftHandAnimName = "lever_copilot";
         gunnerRightHandAnimName = "stick_copilot";
         gunnerLeftLegAnimName = "";
         gunnerRightLegAnimName = "";
         proxyIndex = 1;
         commanding = -1;
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
         class Reflectors
         {
            class cabin
            {
               color[] = {830, 100, 100};
               ambient[] = {5, 0, 0};
               intensity = 4;
               size = 1;
               innerAngle = 90;
               outerAngle = 165;
               coneFadeCoef = 1;
               position = "cabin_light";
               direction = "cabin_light_dir";
               hitpoint = "cabin_light";
               selection = "cabin_light";
               useFlare = 1;
               flareSize = 1;
               flareMaxDistance = 5;
               dayLight = 1;
               blinking = 0;
               class Attenuation
               {
                  start = 0;
                  constant = 0;
                  linear = 1;
                  quadratic = 50;
                  hardLimitStart = 1;
                  hardLimitEnd = 1.5;
               };
            };
            class cargo_light_1 : cabin
            {
               color[] = {830, 100, 100};
               //color[]={800,900,750};
               position = "cargo_light_1";
               direction = "cargo_light_1_dir";
               hitpoint = "cargo_light_1";
               selection = "cargo_light_1";
               intensity = 7;
               useFlare = 0;
               coneFadeCoef = .1;
               class Attenuation
               {
                  start = 0;
                  constant = 0;
                  linear = 1;
                  quadratic = 70;
                  hardLimitStart = 1;
                  hardLimitEnd = 1.5;
               };
            };
            class cargo_light_2 : cargo_light_1
            {
               position = "cargo_light_2";
               direction = "cargo_light_2_dir";
               hitpoint = "cargo_light_2";
               selection = "cargo_light_2";
            };
         };
         class Components
         {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft
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
                  class CrewDisplay
                  {
                     componentType = "CrewDisplayComponent";
                     resource = "RscCustomInfoCrew";
                  };
                  class SensorDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {8000, 16000, 20000, 50000};
                     resource = "RscCustomInfoSensors";
                  };
               };
            };
            class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight
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
                  class CrewDisplay
                  {
                     componentType = "CrewDisplayComponent";
                     resource = "RscCustomInfoCrew";
                  };
                  class SensorDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {8000, 16000, 20000, 50000};
                     resource = "RscCustomInfoSensors";
                  };
               };
            };
         };
      };
      class CargoTurret_01 : CargoTurret
      {
         enableGPS = 0;
         gunnerCompartments = "Compartment1";
         weapons[] = {"rhsusf_weap_DummyLauncher"};
         gunnerAction = "passenger_inside_2";
         gunnerGetInAction = "GetInHeli_Transport_01Cargo";
         gunnerGetOutAction = "RHS_Heli_Cargo_Exit";
         memoryPointsGetInGunner = "pos cargo R";
         memoryPointsGetInGunnerDir = "pos cargo R dir";
         gunnerName = "Passenger (Right Rear)";
         memoryPointGunnerOptics = "";
         proxyIndex = 1;
         maxElev = 15;
         minElev = -45;
         maxTurn = -48;
         minTurn = -104;
         isPersonTurret = 1;
         gunnerUsesPilotView = 1;
         selectionFireAnim = "";
         gunnerCanEject = 1;
         cantCreateAI = 1;
         commanding = -1;
         playerPosition = 1;
         soundAttenuationTurret = "HeliAttenuationRamp";
         disableSoundAttenuation = 0;
         class Hitpoints
         {
         };
      };
      class CargoTurret_02 : CargoTurret_01
      {
         enableGPS = 0;
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Right Front)";
         memoryPointsGetInGunner = "pos cargo R4";
         memoryPointsGetInGunnerDir = "pos cargo R4 dir";
         proxyIndex = 3;
         maxTurn = 47;
         minTurn = 22;
      };
      class CargoTurret_03 : CargoTurret_01
      {
         enableGPS = 0;
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Right Front Center)";
         memoryPointsGetInGunner = "pos cargo R2";
         memoryPointsGetInGunnerDir = "pos cargo R2 dir";
         proxyIndex = 6;
         maxTurn = 70;
         minTurn = 22;
      };
      class CargoTurret_04 : CargoTurret_01
      {
         enableGPS = 0;
         gunnerCompartments = "Compartment1";
         memoryPointsGetInGunner = "pos cargo L";
         memoryPointsGetInGunnerDir = "pos cargo L dir";
         gunnerName = "Passenger (Left Front Center)";
         proxyIndex = 2;
         maxTurn = 104;
         minTurn = 58;
      };
      class CargoTurret_05 : CargoTurret_04
      {
         enableGPS = 0;
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Left Front)";
         memoryPointsGetInGunner = "pos cargo L4";
         memoryPointsGetInGunnerDir = "pos cargo L4 dir";
         proxyIndex = 4;
         maxTurn = -16;
         minTurn = -40;
      };
      class CargoTurret_06 : CargoTurret_04
      {
         enableGPS = 0;
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Left Rear)";
         memoryPointsGetInGunner = "pos cargo L2";
         memoryPointsGetInGunnerDir = "pos cargo L2 dir";
         proxyIndex = 7;
         maxTurn = 3;
         minTurn = -55;
      };
      class CargoTurret_07 : CargoTurret_01
      {
         enableGPS = 0;
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Right Rear Center)";
         memoryPointsGetInGunner = "pos cargo R3";
         memoryPointsGetInGunnerDir = "pos cargo R3 dir";
         proxyIndex = 9;
         maxTurn = 55;
         minTurn = -27;
      };
      class CargoTurret_08 : CargoTurret_04
      {
         enableGPS = 0;
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Left Rear Center)";
         memoryPointsGetInGunner = "pos cargo L3";
         memoryPointsGetInGunnerDir = "pos cargo L3 dir";
         proxyIndex = 8;
         maxTurn = 43;
         minTurn = -40;
      };
   };
   class textureSources
   {
      class USMC
      {
         displayName = "USMC";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_ext_co.paa", "rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_int_co.paa"};
         decals[] = {};
         factions[] = {};
      };
      class PTF
      {
         displayName = "PTF";
         author = "J.Downs";
         textures[] = {
             "\PTF_Textures\aircraft\uh1y\Unarmed\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa"};
         decals[] = {};
         factions[] = {};
      };
      class Medevac
      {
         displayName = "MEDEVAC";
         author = "J.Downs";
         textures[] = {
             "\PTF_Textures\aircraft\uh1y\medevac\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa"};
         decals[] = {};
         factions[] = {};
      };
      class OCTOBER
      {
         displayName = "October";
         author = "J.Downs";
         textures[] = {
             "\PTF_Textures\aircraft\uh1y\uh1y_ext_co_october.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa"};
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
class PTF_UH1Y_Medevac : CUP_B_UH1Y_MEV_USMC
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_AIR";
   side = 1;
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 300;
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   armorStructural = 1000;
   armor=1000;
   hullDamageCauseExplosion = 0;
   maximumLoad = 750;
   driverCanSee = 31;
   gunnerCanSee = 31;
   cyclicAsideForceCoef = 1;
   cyclicForwardForceCoef = 0.9;
   mainRotorSpeed = 1.2;
   backRotorSpeed = 6.1;
   driverDoor = "doorR";
   mainBladeRadius = 7.00;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (Medevac) [MAG36]";
   crew = "B_Pilot_F";
   cargoProxyIndexes[] = {1, 2, 5, 6};
   getInProxyOrder[] = {1, 2, 3, 4, 5, 6};
   cargoAction[] = {"passenger_injured_medevac_truck02", "passenger_injured_medevac_truck02", "CUP_UH1Y_Cargo03", "CUP_UH1Y_Cargo03"};
   cargoIsCoDriver[] = {"false", "false", "false", "false", "false", "false"};
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};
   weapons[] = {"CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {"camo1", "camo2"};
   hiddenSelectionsTextures[] = {
       "\PTF_Textures\aircraft\uh1y\medevac\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

   class RotorLibHelicopterProperties
   {
      RTDconfig = "rhsusf\addons\rhsusf_c_a2port_air\UH1Y\RTD_UH1Y.xml";
      defaultCollective = 0.75;
      autoHoverCorrection[] = {5, 2.4, 0};
      maxTorque = 1280;
      maxMainRotorStress = 130000;
      maxTailRotorStress = 50000;
      retreatBladeStallWarningSpeed = 87.4556;
      horizontalWingsAngleCollMin = 0;
      horizontalWingsAngleCollMax = 0;
      maxHorizontalStabilizerLeftStress = 10000;
      maxHorizontalStabilizerRightStress = 10000;
      maxVerticalStabilizerStress = 10000;
      stressDamagePerSec = 0.0033333332;
   };
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
         primaryObserver = 0;
         slingLoadOperator = 1;
         primaryGunner = 1;
         primary = 1;
         playerPosition = 0;
         isCopilot = 1;
         usePiP = 1;
         class MFD
         {
#include "rotarymfd.hpp"
         };
         gunnerName = "Co-Pilot";
         weapons[] = {"rhs_weap_laserDesignator_AI"};
         magazines[] = {"rhs_LaserMag_ai"};
         gunnerAction = "RHS_UH1Y_Copilot";
         gunnerInAction = "RHS_UH1Y_Copilot";
         body = "ObsTurret";
         gun = "ObsGun";
         animationSourceBody = "ObsTurret";
         animationSourceGun = "ObsGun";
         gunBeg = "gun_end";
         gunEnd = "gun_begin";
         memoryPointGun = "gun_end";
         memoryPointGunnerOptics = "commanderview";
         turretInfoType = "RscOptics_GENERAL_FLIR";
         initElev = 0;
         minElev = -80;
         maxElev = 30;
         minTurn = -180;
         maxTurn = 180;
         CanEject = 0;
         memoryPointsGetInGunner = "pos codriver";
         memoryPointsGetInGunnerDir = "pos codriver dir";
         gunnerGetInAction = "copilot_Heli_Light_02_Enter";
         gunnerGetOutAction = "copilot_Heli_Light_02_Exit";
         selectionFireAnim = "";
         preciseGetInOut = 1;
         GunnerDoor = "DoorL";
         gunnerLeftHandAnimName = "lever_copilot";
         gunnerRightHandAnimName = "stick_copilot";
         gunnerLeftLegAnimName = "";
         gunnerRightLegAnimName = "";
         proxyIndex = 1;
         commanding = -1;
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
         class Reflectors
         {
            class cabin
            {
               color[] = {830, 100, 100};
               ambient[] = {5, 0, 0};
               intensity = 4;
               size = 1;
               innerAngle = 90;
               outerAngle = 165;
               coneFadeCoef = 1;
               position = "cabin_light";
               direction = "cabin_light_dir";
               hitpoint = "cabin_light";
               selection = "cabin_light";
               useFlare = 1;
               flareSize = 1;
               flareMaxDistance = 5;
               dayLight = 1;
               blinking = 0;
               class Attenuation
               {
                  start = 0;
                  constant = 0;
                  linear = 1;
                  quadratic = 50;
                  hardLimitStart = 1;
                  hardLimitEnd = 1.5;
               };
            };
            class cargo_light_1 : cabin
            {
               color[] = {830, 100, 100};
               //color[]={800,900,750};
               position = "cargo_light_1";
               direction = "cargo_light_1_dir";
               hitpoint = "cargo_light_1";
               selection = "cargo_light_1";
               intensity = 7;
               useFlare = 0;
               coneFadeCoef = .1;
               class Attenuation
               {
                  start = 0;
                  constant = 0;
                  linear = 1;
                  quadratic = 70;
                  hardLimitStart = 1;
                  hardLimitEnd = 1.5;
               };
            };
            class cargo_light_2 : cargo_light_1
            {
               position = "cargo_light_2";
               direction = "cargo_light_2_dir";
               hitpoint = "cargo_light_2";
               selection = "cargo_light_2";
            };
         };
         class Components
         {
            class VehicleSystemsDisplayManagerComponentLeft : DefaultVehicleSystemsDisplayManagerLeft
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
                  class CrewDisplay
                  {
                     componentType = "CrewDisplayComponent";
                     resource = "RscCustomInfoCrew";
                  };
                  class SensorDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {8000, 16000, 20000, 50000};
                     resource = "RscCustomInfoSensors";
                  };
               };
            };
            class VehicleSystemsDisplayManagerComponentRight : DefaultVehicleSystemsDisplayManagerRight
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
                  class CrewDisplay
                  {
                     componentType = "CrewDisplayComponent";
                     resource = "RscCustomInfoCrew";
                  };
                  class SensorDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {8000, 16000, 20000, 50000};
                     resource = "RscCustomInfoSensors";
                  };
               };
            };
         };
      };
      class CargoTurret_01 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerAction = "passenger_inside_2";
         memoryPointsGetInGunner = "pos Cargo4";
         memoryPointsGetInGunnerDir = "pos Cargo dir4";
         gunnerName = "Rear Right";
         proxyIndex = 4;
         maxElev = 10;
         minElev = -65;
         maxTurn = 60;
         minTurn = -30;
         isPersonTurret = 1;
         ejectDeadGunner = 0;
         memoryPointGunnerOptics = "eye";
         class dynamicViewLimits
         {
         };
      };
      class CargoTurret_02 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
         memoryPointsGetInGunner = "pos Cargo3";
         memoryPointsGetInGunnerDir = "pos Cargo dir3";
         gunnerName = "Rear Left";
         proxyIndex = 3;
         maxTurn = 30;
         minTurn = -60;
         class dynamicViewLimits
         {
         };
      };
   };
   class textureSources
   {
   };

   class TransportMagazines : TransportMagazines
   {
      mag_xx(SmokeShellPurple, 40);
   };
   class TransportItems : TransportItems
   {
      item_xx(ACE_fieldDressing, 300);
      item_xx(ACE_quikclot, 300);
      item_xx(ACE_elasticBandage, 300);
      item_xx(ACE_packingBandage, 300);
      item_xx(ACE_epinephrine, 100);
      item_xx(ACE_adenosine, 50);
      item_xx(ACE_morphine, 50);
      item_xx(ACE_bodyBag, 20);
      item_xx(ACE_surgicalKit, 10);
      item_xx(ACE_CableTie, 20);
      item_xx(ACE_salineIV, 30);
      item_xx(ACE_salineIV_250, 60);
      item_xx(ACE_salineIV_500, 60);
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
