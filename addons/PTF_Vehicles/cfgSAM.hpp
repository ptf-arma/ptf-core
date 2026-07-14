class PTF_SAM_DEFENDER : B_SAM_System_03_F
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

   class Components : Components
   {
      class SensorsManagerComponent
      {
         class Components
         {
            class DataLinkSensorComponent : SensorTemplateDataLink
            {
            };
         };
      };
   };

   reportOwnPosition = 1;
   receiveRemoteTargets = 1;
   reportRemoteTargets = 1;
   showAllTargets = 2;

   hiddenSelections[] = {
       "camo1",
       "camo2"};
   hiddenSelectionsTextures[] = {
       "A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_01_CO.paa",
       "A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_02_CO.paa"};

   class TextureSources
   {
      class Desert
      {
         displayName = "$STR_A3_TEXTURESOURCES_SAND0";
         author = "$STR_A3_author_B01";
         factions[] = {"BLU_F"};
         textures[] = {"A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_01_CO.paa", "A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_02_CO.paa"};
      };
      class Olive
      {
         displayName = "$STR_A3_TEXTURESOURCES_OLIVE0";
         author = "$STR_A3_author_B01";
         factions[] = {"BLU_F"};
         textures[] = {"A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_01_olive_CO.paa", "A3\Static_F_Sams\SAM_System_03\Data\sam_system_03_mat_02_olive_CO.paa"};
      };
   };

   class Turrets : Turrets
   {
      class MainTurret : MainTurret
      {
         minelev = 0;
         maxelev = 75;
         minturn = -180;
         maxturn = 180;
         initElev = 0;
         initTurn = 0;
         maxHorizontalRotSpeed = 0.6;
         maxVerticalRotSpeed = 0.6;
         soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best", 1.4125376, 1, 40};
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
               visionMode[] = {"Normal", "NVG", "Ti"};
               thermalMode[] = {0, 1};
               gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
            };
            class Medium : Wide
            {
               opticsDisplayName = "M";
               initFov = 0.093;
               minFov = 0.093;
               maxFov = 0.093;
               gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";
            };
            class Narrow : Wide
            {
               opticsDisplayName = "N";
               gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_n_F";
               initFov = 0.029;
               minFov = 0.029;
               maxFov = 0.029;
            };
         };
         class Components : Components
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
                  class UAVDisplay
                  {
                     componentType = "UAVFeedDisplayComponent";
                  };
                  class SensorDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {16000, 8000, 4000, 2000};
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
                  class UAVDisplay
                  {
                     componentType = "UAVFeedDisplayComponent";
                  };
                  class SensorDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {16000, 8000, 4000, 2000};
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
class PTF_SAM_RADAR : B_Radar_System_01_F
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

   class Components : Components
   {
      class SensorsManagerComponent
      {
         class Components
         {
            class DataLinkSensorComponent : SensorTemplateDataLink
            {
            };
            class PassiveRadarSensorComponent : SensorTemplatePassiveRadar
            {
               animDirection = "mainGun";
            };
            class ActiveRadarSensorComponent : SensorTemplateActiveRadar
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

   reportOwnPosition = 1;
   receiveRemoteTargets = 1;
   reportRemoteTargets = 1;
   showAllTargets = 2;

   hiddenSelections[] = {
       "camo1",
       "camo2"};
   hiddenSelectionsTextures[] = {
       "A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_01_CO.paa",
       "A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_02_CO.paa"};

   class TextureSources
   {
      class Desert
      {
         displayName = "$STR_A3_TEXTURESOURCES_SAND0";
         author = "$STR_A3_author_B01";
         factions[] = {"BLU_F"};
         textures[] = {"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_01_CO.paa", "A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_02_CO.paa"};
      };
      class Olive
      {
         displayName = "$STR_A3_TEXTURESOURCES_OLIVE0";
         author = "$STR_A3_author_B01";
         factions[] = {"BLU_F"};
         textures[] = {"A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_01_olive_CO.paa", "A3\Static_F_Sams\Radar_System_01\Data\Radar_system_01_mat_02_olive_CO.paa"};
      };
   };
   class Turrets : Turrets
   {
      class MainTurret : MainTurret
      {
         minelev = -10;
         maxelev = 75;
         minturn = -180;
         maxturn = 180;
         initElev = 15;
         initTurn = 0;
         maxHorizontalRotSpeed = 1;
         maxVerticalRotSpeed = 1;
         soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best", 1.4125376, 1, 40};
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
               visionMode[] = {"Normal", "NVG", "Ti"};
               thermalMode[] = {0, 1};
               gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_w_F";
            };
            class Medium : Wide
            {
               opticsDisplayName = "M";
               initFov = 0.093;
               minFov = 0.093;
               maxFov = 0.093;
               gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_m_F";
            };
            class Narrow : Wide
            {
               opticsDisplayName = "N";
               gunnerOpticsModel = "\A3\weapons_f\reticle\Optics_Gunner_AAA_01_n_F";
               initFov = 0.029;
               minFov = 0.029;
               maxFov = 0.029;
            };
         };
         class Components : Components
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
                  class UAVDisplay
                  {
                     componentType = "UAVFeedDisplayComponent";
                  };
                  class SensorDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {16000, 8000, 4000, 2000};
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
                  class UAVDisplay
                  {
                     componentType = "UAVFeedDisplayComponent";
                  };
                  class SensorDisplay
                  {
                     componentType = "SensorsDisplayComponent";
                     range[] = {16000, 8000, 4000, 2000};
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
