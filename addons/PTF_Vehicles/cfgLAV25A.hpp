/* class SensorTemplatePassiveRadar;
class SensorTemplateAntiRadiation;
class SensorTemplateActiveRadar;
class SensorTemplateIR;
class SensorTemplateVisual;
class SensorTemplateMan;
class SensorTemplateLaser;
class SensorTemplateNV;
class SensorTemplateDataLink; */

/* //class DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftDriver: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightDriver: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftCommander: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightCommander: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
class VehicleSystemsTemplateLeftGunner: DefaultVehicleSystemsDisplayManagerLeft
{
	class components;
};
class VehicleSystemsTemplateRightGunner: DefaultVehicleSystemsDisplayManagerRight
{
	class components;
};
 */

class PTF_LAV25A : CUP_B_LAV25M240_USMC
{

   /*    *class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{
				class LaserSensorComponent : SensorTemplateLaser
				{
				   componentType ="LaserSensorComponent";
				   angleRangeHorizontal = 180;
				   animDirection = "MainGun";
				};
				class DataLinkSensorComponent : SensorTemplateDataLink
				{
					componentType ="DataLinkSensorComponent";
				};
			};
		};
	}; */
   crewCrashProtection = 0.005000001;
   damageResistance = 0.006;
   armor = 550;
   armorStructural = 10;
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 1500;
   scope = 2;
   mass = 14000;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Armor";
   driverCompartments = "Compartment1";
   side = 1;
   author = "Paramarine Task Force";
   displayName = "LAV-25A [PTF]";
   rudderForceCoef = 2;
   rudderForceCoefAtMaxSpeed = 1;
   enginePower = 300;
   peakTorque = 1520;

   cargoCompartments[] =
       {
           "Compartment1"};

   class textureSources
   {
      class woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] = {"\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody2_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lav_hq_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavalfa_ca.paa"};
         factions[] = {};
      };
      class desert
      {
         displayName = "Desert";
         author = "J.Downs";
         textures[] = {"\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody_desert_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody2_desert_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lav_hq_desert_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavalfa_desert_ca.paa"};
         factions[] = {};
      };
      class snow
      {
         displayName = "Snow";
         author = "J.Downs";
         textures[] = {"\PTF_Textures\vehicles\lav25a\lavbody_snow_co.paa", "\PTF_Textures\vehicles\lav25a\lavbody2_snow_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lav_hq_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavalfa_ca.paa"};
         factions[] = {};
      };
   };

   class Turrets : Turrets
   {
      class MainTurret : NewTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerHasFlares = 1;
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "PTF_weap_M242",
                 "PTF_Vlmg_M240_veh",
                 "SmokeLauncher"};
         magazines[] =
             {
                 "CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APDS",
                 "CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APDS",
                 "CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APDS",
                 "CUP_150Rnd_TE1_Red_Tracer_25mm_M242_HE",
                 "CUP_150Rnd_TE1_Red_Tracer_25mm_M242_HE",
                 "CUP_150Rnd_TE1_Red_Tracer_25mm_M242_HE",
                 "PTF_400rnd_TE1_Red_Tracer_762x51_M240_M",
                 "PTF_400rnd_TE1_Red_Tracer_762x51_M240_M",
                 "PTF_400rnd_TE1_Red_Tracer_762x51_M240_M",
                 "SmokeLauncherMag"};
         soundServo[] =
             {
                 "A3\sounds_f\dummysound",
                 "db-35",
                 1,
                 15};
         minElev = -8;
         maxElev = 50;
         initElev = 0;
         minTurn = -360;
         maxTurn = 360;
         initTurn = 0;
         gunnerAction = "CUP_LAV25_Gunner_out";
         gunnerInAction = "CUP_LAV25_Gunner";
         personTurretAction = "vehicle_turnout_2";
         gunnerGetInAction = "GetInHigh";
         gunnerGetOutAction = "GetOutHigh";
         forceHideGunner = 0;
         gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_3x";
         turretInfoType = "CUP_RscOptics_gunner_LAV25";
         discreteDistance[] = {200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900, 4000, 4100, 4200, 4300, 4400, 4500, 4600, 4700, 4800, 4900, 5000, 5100, 5200, 5300, 5400, 5500, 5600, 5700, 5800, 5900, 6000, 6100, 6200, 6300, 6400, 6500, 6600, 6700, 6800, 6900, 7000, 7100, 7200, 7300, 7400, 7500, 7600, 7700, 7800, 7900, 8000, 8100, 8200, 8300, 8400, 8500, 8600, 8700, 8800, 8900, 9000, 9100, 9200, 9300, 9400, 9500, 9600, 9700, 9800, 9900, 10000};
         discreteDistanceInitIndex = 3;
         ispersonturret = 1;
         minOutElev = -70;
         maxOutElev = 40;
         initOutElev = 0;
         minOutTurn = -90;
         maxOutTurn = 90;
         initOutTurn = 0;
         proxyType = "CPGunner";
         proxyIndex = 1;
         ace_fcs_enabled = 1;
         ace_fcs_minDistance = 200;
         ace_fcs_maxDistance = 6000;
         ace_fcs_distanceInterval = 5;
         gunnerOutOpticsModel = "";
         memoryPointGun = "machinegun";
         gunBeg = "muzzle_1";
         gunEnd = "chamber_1";
         particlesdir = "muzzle_1";
         particlespos = "chamber_1";
         missileBeg = "muzzle_1";
         missileEnd = "chamber_1";
         body = "MainTurret";
         gun = "MainGun";
         memoryPointsGetInGunner = "pos gunner";
         memoryPointsGetInGunnerDir = "pos gunner dir";
         animationSourceBody = "MainTurret";
         animationSourceGun = "MainGun";
         gunnerForceOptics = 1;
         outGunnerMayFire = 0;
         startEngine = 1;
         primaryGunner = 1;
         stabilizedInAxes = 3;
         class ViewOptics : RCWSOptics
         {
            visionMode[] =
                {
                    "Normal",
                    "NVG"};
            thermalMode[] = {};
            initAngleX = 0;
            minAngleX = -30;
            maxAngleX = 30;
            initAngleY = 0;
            minAngleY = -100;
            maxAngleY = 100;
            initFov = 0.2;
            minFov = 0.050000001;
            maxFov = 0.2;
         };
         class OpticsIn
         {
            class Wide : ViewOptics
            {
               initFov = 0.133;
               minFov = 0.133;
               maxFov = 0.133;
               gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_3x";
            };
            class Narrow : Wide
            {
               initFov = 0.039999999;
               minFov = 0.039999999;
               maxFov = 0.039999999;
               gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_10x";
            };
         };
         class HitPoints : HitPoints
         {
            class HitTurret
            {
               armor = 1.6;
               material = -1;
               name = "otocvez";
               visual = "otocvez";
               passThrough = 1;
            };
         };
         selectionFireAnim = "zasleh_1";
         class ViewGunner
         {
            initAngleX = 5;
            minAngleX = -65;
            maxAngleX = 85;
            initAngleY = 0;
            minAngleY = -150;
            maxAngleY = 150;
            initFov = 0.69999999;
            minFov = 0.25;
            maxFov = 1.1;
         };

         class Turrets
         {
            class CommanderOptics : NewTurret
            {
               weapons[] =
                   {
                       "PTF_weap_mastersafe",
                       "CUP_Vlmg_M240_veh3",
                       "SmokeLauncher"};
               magazines[] =
                   {
                       "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                       "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                       "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                       "CUP_200Rnd_TE4_LRT4_Red_Tracer_762x51_Belt_M",
                       "SmokeLauncherMag",
                       "SmokeLauncherMag"};
               minElev = -10;
               maxElev = 20;
               initElev = 0;
               minTurn = -60;
               maxTurn = 60;
               initTurn = 0;
               gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_com1";
               gunnerOutOpticsColor[] = {0, 0, 0, 1};
               gunnerForceOptics = 1;
               gunnerOutForceOptics = 0;
               proxyType = "CPCommander";
               proxyIndex = 1;
               gunnerName = "Commander";
               viewGunnerInExternal = 0;
               animationSourceHatch = "hatchCommander";
               body = "obsTurret";
               gun = "obsGun";
               memoryPointGun = "usti hlavne3";
               gunBeg = "usti hlavne3";
               gunEnd = "konec hlavne3";
               animationSourceBody = "obsTurret";
               animationSourceGun = "obsGun";
               memoryPointsGetInGunner = "pos commander";
               memoryPointsGetInGunnerDir = "pos commander dir";
               class ViewGunner
               {
                  initAngleX = 5;
                  minAngleX = -65;
                  maxAngleX = 85;
                  initAngleY = 0;
                  minAngleY = -150;
                  maxAngleY = 150;
                  initFov = 0.69999999;
                  minFov = 0.25;
                  maxFov = 1.1;
               };
               gunnerOpticsEffect[] =
                   {
                       "TankGunnerOptics2",
                       "OpticsBlur1",
                       "OpticsCHAbera1"};
               gunnerInAction = "CUP_LAV25_Commander";
               stabilizedInAxes = 3;
               LODTurnedIn = "View_Gunner";
               LODTurnedOut = 1;
               ispersonturret = 0;
               minOutElev = -20;
               maxOutElev = 20;
               initOutElev = 0;
               minOutTurn = -60;
               maxOutTurn = 60;
               initOutTurn = 0;
               gunnerLeftHandAnimName = "OtocHlaven_Shake";
               gunnerRightHandAnimName = "OtocHlaven_Shake";
               memoryPointGunnerOutOptics = "comgunview";
               memoryPointGunnerOptics = "commanderview";
               gunnerOutOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\proxies\optika_empty";
               gunnerAction = "CUP_LAV25_Commander_out_mg";
               selectionFireAnim = "zasleh_2";
               InGunnerMayFire = 1;
               outGunnerMayFire = 1;
               gunnerOutOpticsShowCursor = 0;
               gunnerOpticsShowCursor = 0;
               discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200};
               discreteDistanceInitIndex = 2;
               turretInfoType = "CUP_RscOptics_commander_NBECO";
               primaryGunner = 0;
               primaryObserver = 1;
               soundServo[] =
                   {
                       "",
                       "db-50",
                       1};
               startEngine = 0;
               commanding = 2;
               class ViewOptics
               {
                  visionMode[] =
                      {
                          "Normal",
                          "NVG",
                          "TI"};
                  thermalMode[] = {2};
                  initAngleX = 0;
                  minAngleX = -30;
                  maxAngleX = 30;
                  initAngleY = 0;
                  minAngleY = -100;
                  maxAngleY = 100;
                  initFov = 0.30000001;
                  minFov = 0.025;
                  maxFov = 0.30000001;
               };
               gunnerGetInAction = "GetInHigh";
               gunnerGetOutAction = "GetOutHigh";
            };
            class CommanderGunSight : NewTurret
            {
               dontCreateAI = false;
               hasGunner = false;
               forceHideGunner = true;
               proxyType = "CPCommander";
               proxyIndex = 2;
               gunnerName = "Commander Aux Gun Sight";
               primaryGunner = 0;
               primaryObserver = 0;
               gunnerOpticsShowCursor = 0;
               animationSourceHatch = "hatchCommander";
               soundServo[] =
                   {
                       "",
                       "db-50",
                       1};
               startEngine = 0;
               body = "MainTurret";
               gun = "MainGun";
               animationSourceBody = "obsTurret";
               animationSourceGun = "obsGun";
               lodturnedin = 1;
               lodturnedout = 1;
               gunBeg = "";
               gunEnd = "";
               minElev = -4;
               maxElev = 20;
               initElev = 0;
               minTurn = -360;
               maxTurn = 360;
               initTurn = 0;
               commanding = 2;
               viewGunnerInExternal = 0;
               gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_3x";
               turretInfoType = "CUP_RscOptics_gunner_LAV25";
               memoryPointGunnerOutOptics = "commander_weapon_view";
               memoryPointGunnerOptics = "commanderview";
               memoryPointsGetInGunner = "pos commander";
               memoryPointsGetInGunnerDir = "pos commander dir";
               class ViewGunner
               {
                  visionMode[] =
                      {
                          "Normal",
                          "NVG",
                      };
                  thermalMode[] = {};
                  initAngleX = 5;
                  minAngleX = -65;
                  maxAngleX = 85;
                  initAngleY = 0;
                  minAngleY = -150;
                  maxAngleY = 150;
                  initFov = 0.69999999;
                  minFov = 0.25;
                  maxFov = 1.1;
               };
               gunnerOpticsEffect[] =
                   {
                       "TankGunnerOptics2",
                       "OpticsBlur1",
                       "OpticsCHAbera1"};
               class ViewOptics
               {
                  initAngleX = 0;
                  minAngleX = -30;
                  maxAngleX = 30;
                  initAngleY = 0;
                  minAngleY = -100;
                  maxAngleY = 100;
                  initFov = 0.30000001;
                  minFov = 0.025;
                  maxFov = 0.30000001;
               };
               class OpticsIn
               {
                  class Wide : ViewOptics
                  {
                     initFov = 0.133;
                     minFov = 0.133;
                     maxFov = 0.133;
                     gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_3x";
                  };
                  class Narrow : Wide
                  {
                     initFov = 0.039999999;
                     minFov = 0.039999999;
                     maxFov = 0.039999999;
                     gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_10x";
                  };
               };
               gunnerInAction = "CUP_LAV25_Commander";
               gunnerAction = "CUP_LAV25_Commander";
               personTurretAction = "CUP_LAV25_Commander_out";
               gunnerGetInAction = "GetInHigh";
               gunnerGetOutAction = "GetOutHigh";
               outGunnerMayFire = 1;
               InGunnerMayFire = 1;
               weapons[] =
                   {
                       "SmokeLauncher"};
               magazines[] =
                   {
                       "SmokeLauncherMag",
                   };
               ispersonturret = 0;
               minOutElev = -70;
               maxOutElev = 40;
               initOutElev = 0;
               minOutTurn = -90;
               maxOutTurn = 90;
               initOutTurn = 0;
               stabilizedInAxes = 3;
            };
         };
      };
      class CargoGunner_1 : NewTurret
      {
         gunnerCompartments = "Compartment1";
         weapons[] = {};
         magazines[] = {};
         proxyType = "CPCargo";
         proxyIndex = 5;
         gunnerName = "$STR_A3_TURRETS_CARGOTURRET_RL";
         primaryGunner = 0;
         primaryObserver = 0;
         gunnerOpticsShowCursor = 0;
         body = "";
         gun = "";
         animationSourceBody = "";
         animationSourceGun = "";
         animationSourceHatch = "hatchleft";
         soundServo[] =
             {
                 "",
                 "db-50",
                 1};
         startEngine = 0;
         hideWeaponsGunner = 0;
         gunnerGetInAction = "GetInHigh";
         gunnerGetOutAction = "GetOutHigh";
         gunnerAction = "vehicle_turnout_2";
         gunnerInAction = "passenger_apc_narrow_generic02";
         ispersonturret = 1;
         dontCreateAI = 1;
         minOutElev = -10;
         maxOutElev = 40;
         initOutElev = 0;
         minOutTurn = -60;
         maxOutTurn = 80;
         initOutTurn = 0;
         minElev = -15;
         maxElev = 50;
         initElev = 0;
         minTurn = -120;
         maxTurn = 120;
         initTurn = 0;
         commanding = -1;
         viewGunnerInExternal = 0;
         gunnerOpticsModel = "";
         gunnerOutOpticsColor[] = {0, 0, 0, 1};
         gunnerForceOptics = 0;
         gunnerOutForceOptics = 0;
         gunnerOutOpticsShowCursor = 0;
         memoryPointGunnerOptics = "";
         gunnerOpticsEffect[] = {};
         outGunnerMayFire = 1;
         inGunnerMayFire = 0;
         stabilizedInAxes = 0;
         LODTurnedOut = -1;
         LODTurnedIn = 1000;
         LODOpticsIn = 1000;
         LODOpticsOut = -1;
         memoryPointsGetInGunner = "pos cargoleft";
         memoryPointsGetInGunnerDir = "pos cargoleft dir";
      };
      class CargoGunner_2 : NewTurret
      {
         gunnerCompartments = "Compartment1";
         weapons[] = {};
         magazines[] = {};
         proxyType = "CPCargo";
         proxyIndex = 6;
         gunnerName = "$STR_A3_TURRETS_CARGOTURRET_RR";
         primaryGunner = 0;
         primaryObserver = 0;
         gunnerOpticsShowCursor = 0;
         body = "";
         gun = "";
         animationSourceBody = "";
         animationSourceGun = "";
         animationSourceHatch = "hatchright";
         soundServo[] =
             {
                 "",
                 "db-50",
                 1};
         startEngine = 0;
         hideWeaponsGunner = 0;
         gunnerGetInAction = "GetInHigh";
         gunnerGetOutAction = "GetOutHigh";
         gunnerAction = "vehicle_turnout_2";
         gunnerInAction = "passenger_apc_narrow_generic01";
         ispersonturret = 1;
         dontCreateAI = 1;
         minOutElev = -10;
         maxOutElev = 40;
         initOutElev = 0;
         minOutTurn = -100;
         maxOutTurn = 80;
         initOutTurn = 0;
         minElev = -15;
         maxElev = 50;
         initElev = 0;
         minTurn = -120;
         maxTurn = 120;
         initTurn = 0;
         commanding = -1;
         viewGunnerInExternal = 0;
         gunnerOpticsModel = "";
         gunnerOutOpticsColor[] = {0, 0, 0, 1};
         gunnerForceOptics = 0;
         gunnerOutForceOptics = 0;
         gunnerOutOpticsShowCursor = 0;
         memoryPointGunnerOptics = "";
         gunnerOpticsEffect[] = {};
         outGunnerMayFire = 1;
         inGunnerMayFire = 0;
         stabilizedInAxes = 0;
         LODTurnedOut = -1;
         LODTurnedIn = 1000;
         LODOpticsIn = 1000;
         LODOpticsOut = -1;
         memoryPointsGetInGunner = "pos cargoright";
         memoryPointsGetInGunnerDir = "pos cargoright dir";
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
   class TransportMagazines
   {
      class _xx_rhsusf_100rnd_762x51_m80a1epr
      {
         magazine = "rhsusf_100rnd_762x51_m80a1epr";
         count = 2;
      };
      class _xx_rhsusf_200rnd_556x45_mixed_soft_pouch_coyote
      {
         magazine = "rhsusf_200rnd_556x45_mixed_soft_pouch_coyote";
         count = 2;
      };
      class _xx_rhs_mag_20rnd_SCAR_762x51_mk316_special
      {
         magazine = "rhs_mag_20rnd_SCAR_762x51_mk316_special";
         count = 8;
      };
      class _xx_rhsusf_20rnd_762x51_SR25_m993_mag
      {
         magazine = "rhsusf_20rnd_762x51_SR25_m993_mag";
         count = 4;
      };
      class _xx_rhsusf_20rnd_762x51_SR25_mk316_special_mag
      {
         magazine = "rhsusf_20rnd_762x51_SR25_mk316_special_mag";
         count = 4;
      };
      class _xx_PTF_mag_556x45_mk318_stanag_mix
      {
         magazine = "PTF_mag_556x45_mk318_stanag_mix";
         count = 15;
      };
      class _xx_rhs_fgm148_magazine_at
      {
         magazine = "rhs_fgm148_magazine_at";
         count = 1;
      };
      class _xx_rhs_fim92_mag
      {
         magazine = "rhs_fim92_mag";
         count = 1;
      };
      class _xx_rhs_mag_m433_HEDP
      {
         magazine = "rhs_mag_m433_HEDP";
         count = 5;
      };
      class _xx_rhs_mag_m67
      {
         magazine = "rhs_mag_m67";
         count = 5;
      };
      class _xx_rhs_mag_m714_white
      {
         magazine = "rhs_mag_m714_white";
         count = 5;
      };
      class _xx_smokeshell
      {
         magazine = "smokeshell";
         count = 5;
      };
      class _xx_democharge_remote_mag
      {
         magazine = "democharge_remote_mag";
         count = 2;
      };
      class _xx_satchelcharge_remote_mag
      {
         magazine = "satchelcharge_remote_mag";
         count = 1;
      };
   };
   class TransportItems
   {
      class _xx_ToolKit
      {
         name = "ToolKit";
         count = 1;
      };
      class _xx_Ace_clacker
      {
         name = "Ace_clacker";
         count = 1;
      };
   };
   class TransportWeapons
   {
      class _xx_RHS_weap_fgm148
      {
         weapon = "RHS_weap_fgm148";
         count = 1;
      };
      class _xx_RHS_weap_fim92
      {
         weapon = "RHS_weap_fim92";
         count = 1;
      };
   };
   class TransportBackpacks
   {
   };
};

class PTF_LAV25A_CMD : CUP_B_LAV25_USMC
{
   /* 	radarType=2;
	countermeasureActivationRadius = 2000;
	incomingMissileDetectionSystem = 16;
	lockdetectionsystem = 12; */
   /* class Components: Components
	{
		class SensorsManagerComponent
		{
			class Components
			{

				class PassiveRadarSensorComponent: SensorTemplatePassiveRadar
				{
					typeRecognitionDistance = 1000;
					angleRangeHorizontal 	= 300;
					angleRangeVertical 		= 120;
					maxGroundNoiseDistance 	= 250;
					minSpeedThreshold 		= 0;	
					animDirection="MainGun";
					componentType = "PassiveRadarSensorComponent";
					class AirTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
					class GroundTarget
					{
						minRange=8000;
						maxRange=8000;
						objectDistanceLimitCoef=-1;
						viewDistanceLimitCoef=-1;
					};
				};
				
				class IRSensorComponent : SensorTemplateIR
				{
					componentType = "IRSensorComponent";
				   class GroundTargeT
				   {
					  minRange = 100;
					  maxRange = 3000;
					  viewDistanceLimitCoef = -1;
					  objectDistanceLimitCoef = -1;
				   };
				   class AirTargeT
				   {
					  minRange = 100;
					  maxRange = 3000;
					  viewDistanceLimitCoef = -1;
					  objectDistanceLimitCoef = -1;
				   };
				   typeRecognitionDistance = 2000;
				   animDirection = "MainGun";
				};
				class LaserSensorComponent : SensorTemplateLaser
				{
				   componentType ="LaserSensorComponent";
				   angleRangeHorizontal = 180;
				   animDirection = "MainGun";
				};
				class DataLinkSensorComponent : SensorTemplateDataLink
				{
					componentType ="DataLinkSensorComponent";
				};
				class VisualSensorComponent: SensorTemplateVisual
				{
					componentType ="VisualSensorComponent";
					aimDown=0;
					animDirection="MainGun";
					angleRangeHorizontal=30;
					angleRangeVertical=30;
					maxTrackableSpeed=110;
					typeRecognitionDistance=1000;
					class AirTarget
					{
						maxRange=2000;
						minRange=50;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
					class GroundTarget
					{
						maxRange=500;
						minRange=50;
						objectDistanceLimitCoef=1;
						viewDistanceLimitCoef=1;
					};
				};

			};
		};
	}; */
   crewCrashProtection = 0.005000001;
   damageResistance = 0.006;
   armor = 550;
   armorStructural = 10;
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 1500;
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Armor";
   driverCompartments = "Compartment1";
   side = 1;
   author = "Paramarine Task Force";
   displayName = "LAV-25A Command [PTF]";

   rudderForceCoef = 2;
   rudderForceCoefAtMaxSpeed = 1;
   enginePower = 300;
   peakTorque = 1520;

   cargoCompartments[] =
       {
           "Compartment1"};

   reportOwnPosition = true;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;

   class Turrets : Turrets
   {
      class MainTurret : MainTurret
      {

         gunnerCompartments = "Compartment1";
         gunnerHasFlares = 1;
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "PTF_weap_M242",
                 "PTF_Vlmg_M240_veh",
             };
         magazines[] =
             {
                 "CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APDS",
                 "CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APDS",
                 "CUP_60Rnd_TE1_Red_Tracer_25mm_M242_APDS",
                 "CUP_150Rnd_TE1_Red_Tracer_25mm_M242_HE",
                 "CUP_150Rnd_TE1_Red_Tracer_25mm_M242_HE",
                 "CUP_150Rnd_TE1_Red_Tracer_25mm_M242_HE",
                 "PTF_400rnd_TE1_Red_Tracer_762x51_M240_M",
                 "PTF_400rnd_TE1_Red_Tracer_762x51_M240_M",
                 "PTF_400rnd_TE1_Red_Tracer_762x51_M240_M",
             };
         soundServo[] =
             {
                 "A3\sounds_f\dummysound",
                 "db-35",
                 1,
                 15};
         minElev = -8;
         maxElev = 50;
         initElev = 0;
         minTurn = -360;
         maxTurn = 360;
         initTurn = 0;
         gunnerAction = "CUP_LAV25_Gunner_out";
         gunnerInAction = "CUP_LAV25_Gunner";
         personTurretAction = "vehicle_turnout_2";
         gunnerGetInAction = "GetInHigh";
         gunnerGetOutAction = "GetOutHigh";
         forceHideGunner = 0;
         gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_3x";
         turretInfoType = "CUP_RscOptics_gunner_LAV25";
         discreteDistance[] = {200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500, 1600, 1700, 1800, 1900, 2000, 2100, 2200, 2300, 2400, 2500, 2600, 2700, 2800, 2900, 3000, 3100, 3200, 3300, 3400, 3500, 3600, 3700, 3800, 3900, 4000, 4100, 4200, 4300, 4400, 4500, 4600, 4700, 4800, 4900, 5000, 5100, 5200, 5300, 5400, 5500, 5600, 5700, 5800, 5900, 6000, 6100, 6200, 6300, 6400, 6500, 6600, 6700, 6800, 6900, 7000, 7100, 7200, 7300, 7400, 7500, 7600, 7700, 7800, 7900, 8000, 8100, 8200, 8300, 8400, 8500, 8600, 8700, 8800, 8900, 9000, 9100, 9200, 9300, 9400, 9500, 9600, 9700, 9800, 9900, 10000};
         discreteDistanceInitIndex = 3;
         ispersonturret = 1;
         minOutElev = -70;
         maxOutElev = 40;
         initOutElev = 0;
         minOutTurn = -90;
         maxOutTurn = 90;
         initOutTurn = 0;
         proxyType = "CPGunner";
         proxyIndex = 1;
         ace_fcs_enabled = 1;
         ace_fcs_minDistance = 200;
         ace_fcs_maxDistance = 6000;
         ace_fcs_distanceInterval = 5;
         gunnerOutOpticsModel = "";
         memoryPointGun = "machinegun";
         gunBeg = "muzzle_1";
         gunEnd = "chamber_1";
         particlesdir = "muzzle_1";
         particlespos = "chamber_1";
         missileBeg = "muzzle_1";
         missileEnd = "chamber_1";
         body = "MainTurret";
         gun = "MainGun";
         memoryPointsGetInGunner = "pos gunner";
         memoryPointsGetInGunnerDir = "pos gunner dir";
         animationSourceBody = "MainTurret";
         animationSourceGun = "MainGun";
         gunnerForceOptics = 1;
         outGunnerMayFire = 0;
         startEngine = 1;
         primaryGunner = 1;
         stabilizedInAxes = 3;

         /* 			class Components
			{
				class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftGunner
				{
					class Components: components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightGunner
				{
					defaultDisplay="SensorDisplay";
					class Components: components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
					};
				};
			};
			 */

         class ViewOptics : RCWSOptics
         {
            visionMode[] =
                {
                    "Normal",
                    "NVG",
                    "TI"};
            thermalMode[] = {2};
            initAngleX = 0;
            minAngleX = -30;
            maxAngleX = 30;
            initAngleY = 0;
            minAngleY = -100;
            maxAngleY = 100;
            initFov = 0.2;
            minFov = 0.050000001;
            maxFov = 0.2;
         };
         class OpticsIn
         {
            class UltraWide : ViewOptics
            {
               initFov = 0.5;
               minFov = 0.5;
               maxFov = 0.5;
               gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_com1";
            };
            class Wide : ViewOptics
            {
               initFov = 0.133;
               minFov = 0.133;
               maxFov = 0.133;
               gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_3x";
            };
            class Narrow : Wide
            {
               initFov = 0.039999999;
               minFov = 0.039999999;
               maxFov = 0.039999999;
               gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_10x";
            };
         };
         class HitPoints : HitPoints
         {
            class HitTurret
            {
               armor = 1.6;
               material = -1;
               name = "otocvez";
               visual = "otocvez";
               passThrough = 1;
            };
         };
         selectionFireAnim = "zasleh_1";
         class ViewGunner
         {
            initAngleX = 5;
            minAngleX = -65;
            maxAngleX = 85;
            initAngleY = 0;
            minAngleY = -150;
            maxAngleY = 150;
            initFov = 0.69999999;
            minFov = 0.25;
            maxFov = 1.1;
         };

         /* class Components
			{
				class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
				{
					class Components: components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
					};
				};
				class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightCommander
				{
					defaultDisplay="SensorDisplay";
					class Components: components
					{
						class SensorDisplay
						{
							componentType="SensorsDisplayComponent";	
							range[]={4000,2000,1000,500};
							resource="RscCustomInfoSensors";
						};
					};
				};
			}; */

         class Turrets
         {
            class CommanderOptics : NewTurret
            {

               // class Components
               // {
               // class VehicleSystemsDisplayManagerComponentLeft: VehicleSystemsTemplateLeftCommander
               // {
               // class Components: components
               // {
               // class SensorDisplay
               // {
               // componentType="SensorsDisplayComponent";
               // range[]={4000,2000,1000,8000};
               // resource="RscCustomInfoSensors";
               // };
               // };
               // };
               // class VehicleSystemsDisplayManagerComponentRight: VehicleSystemsTemplateRightCommander
               // {
               // defaultDisplay="SensorDisplay";
               // class Components: components
               // {
               // class SensorDisplay
               // {
               // componentType="SensorsDisplayComponent";
               // range[]={4000,2000,1000,8000};
               // resource="RscCustomInfoSensors";
               // };
               // };
               // };
               // };

               proxyType = "CPCommander";
               proxyIndex = 1;
               gunnerName = "$STR_POSITION_COMMANDER";
               primaryGunner = 0;
               primaryObserver = 1;
               gunnerOpticsShowCursor = 0;
               animationSourceHatch = "hatchCommander";
               soundServo[] =
                   {
                       "",
                       "db-50",
                       1};
               startEngine = 0;
               body = "obsTurret";
               gun = "obsGun";
               animationSourceBody = "obsTurret";
               animationSourceGun = "obsGun";
               lodturnedin = 1;
               lodturnedout = 1;
               gunBeg = "";
               gunEnd = "";
               minElev = -4;
               maxElev = 20;
               initElev = 0;
               minTurn = -360;
               maxTurn = 360;
               initTurn = 0;
               commanding = 2;
               viewGunnerInExternal = 0;
               gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_com1";
               gunnerOutOpticsModel = "";
               gunnerOutOpticsColor[] = {0, 0, 0, 1};
               gunnerOutForceOptics = 0;
               gunnerOutOpticsShowCursor = 0;
               memoryPointGunnerOutOptics = "commander_weapon_view";
               memoryPointGunnerOptics = "commanderview";
               memoryPointsGetInGunner = "pos commander";
               memoryPointsGetInGunnerDir = "pos commander dir";
               class ViewGunner
               {
                  initAngleX = 5;
                  minAngleX = -65;
                  maxAngleX = 85;
                  initAngleY = 0;
                  minAngleY = -150;
                  maxAngleY = 150;
                  initFov = 0.69999999;
                  minFov = 0.25;
                  maxFov = 1.1;
               };
               gunnerOpticsEffect[] =
                   {
                       "TankGunnerOptics2",
                       "OpticsBlur1",
                       "OpticsCHAbera1"};
               class ViewOptics
               {
                  visionMode[] =
                      {
                          "Normal",
                          "NVG",
                          "TI",
                      };
                  thermalMode[] = {2};
                  initAngleX = 0;
                  minAngleX = -30;
                  maxAngleX = 30;
                  initAngleY = 0;
                  minAngleY = -100;
                  maxAngleY = 100;
                  initFov = 0.50000001;
                  minFov = 0.02;
                  maxFov = 0.50000001;
               };
               gunnerInAction = "CUP_LAV25_Commander";
               gunnerAction = "CUP_LAV25_Commander_out";
               personTurretAction = "vehicle_turnout_2";
               gunnerGetInAction = "GetInHigh";
               gunnerGetOutAction = "GetOutHigh";
               outGunnerMayFire = 1;
               InGunnerMayFire = 1;
               weapons[] =
                   {
                       "SmokeLauncher"};
               magazines[] =
                   {
                       "SmokeLauncherMag",
                       "SmokeLauncherMag"};
               ispersonturret = 1;
               minOutElev = -70;
               maxOutElev = 40;
               initOutElev = 0;
               minOutTurn = -90;
               maxOutTurn = 90;
               initOutTurn = 0;
               turretInfoType = "CUP_RscOptics_commander_NBECO";
               stabilizedInAxes = 3;
            };
            class CommanderGunSight : NewTurret
            {
               dontCreateAI = false;
               hasGunner = false;
               forceHideGunner = true;
               proxyType = "CPCommander";
               proxyIndex = 2;
               gunnerName = "Commander Aux Gun Sight";
               primaryGunner = 0;
               primaryObserver = 0;
               gunnerOpticsShowCursor = 0;
               animationSourceHatch = "hatchCommander";
               soundServo[] =
                   {
                       "",
                       "db-50",
                       1};
               startEngine = 0;
               body = "MainTurret";
               gun = "MainGun";
               animationSourceBody = "obsTurret";
               animationSourceGun = "obsGun";
               lodturnedin = 1;
               lodturnedout = 1;
               gunBeg = "";
               gunEnd = "";
               minElev = -4;
               maxElev = 20;
               initElev = 0;
               minTurn = -360;
               maxTurn = 360;
               initTurn = 0;
               commanding = 2;
               viewGunnerInExternal = 0;
               gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_3x";
               turretInfoType = "CUP_RscOptics_gunner_LAV25";
               memoryPointGunnerOutOptics = "commander_weapon_view";
               memoryPointGunnerOptics = "commanderview";
               memoryPointsGetInGunner = "pos commander";
               memoryPointsGetInGunnerDir = "pos commander dir";
               class ViewGunner
               {
                  visionMode[] =
                      {
                          "Normal",
                          "NVG",
                          "TI"};
                  thermalMode[] = {2};
                  initAngleX = 5;
                  minAngleX = -65;
                  maxAngleX = 85;
                  initAngleY = 0;
                  minAngleY = -150;
                  maxAngleY = 150;
                  initFov = 0.69999999;
                  minFov = 0.25;
                  maxFov = 1.1;
               };
               gunnerOpticsEffect[] =
                   {
                       "TankGunnerOptics2",
                       "OpticsBlur1",
                       "OpticsCHAbera1"};
               class ViewOptics
               {
                  initAngleX = 0;
                  minAngleX = -30;
                  maxAngleX = 30;
                  initAngleY = 0;
                  minAngleY = -100;
                  maxAngleY = 100;
                  initFov = 0.30000001;
                  minFov = 0.025;
                  maxFov = 0.30000001;
               };
               class OpticsIn
               {
                  class Wide : ViewOptics
                  {
                     initFov = 0.133;
                     minFov = 0.133;
                     maxFov = 0.133;
                     gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_3x";
                  };
                  class Narrow : Wide
                  {
                     initFov = 0.039999999;
                     minFov = 0.039999999;
                     maxFov = 0.039999999;
                     gunnerOpticsModel = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\2dscope_lav_10x";
                  };
               };
               gunnerInAction = "CUP_LAV25_Commander";
               gunnerAction = "CUP_LAV25_Commander";
               personTurretAction = "CUP_LAV25_Commander_out";
               gunnerGetInAction = "GetInHigh";
               gunnerGetOutAction = "GetOutHigh";
               outGunnerMayFire = 1;
               InGunnerMayFire = 1;
               weapons[] =
                   {
                       "SmokeLauncher"};
               magazines[] =
                   {
                       "SmokeLauncherMag",
                       "SmokeLauncherMag"};
               ispersonturret = 0;
               minOutElev = -70;
               maxOutElev = 40;
               initOutElev = 0;
               minOutTurn = -90;
               maxOutTurn = 90;
               initOutTurn = 0;
               stabilizedInAxes = 3;
            };
         };
      };
      class CargoGunner_1 : NewTurret
      {
         gunnerCompartments = "Compartment1";
         weapons[] = {};
         magazines[] = {};
         proxyType = "CPCargo";
         proxyIndex = 5;
         gunnerName = "$STR_A3_TURRETS_CARGOTURRET_RL";
         primaryGunner = 0;
         primaryObserver = 0;
         gunnerOpticsShowCursor = 0;
         body = "";
         gun = "";
         animationSourceBody = "";
         animationSourceGun = "";
         animationSourceHatch = "hatchleft";
         soundServo[] =
             {
                 "",
                 "db-50",
                 1};
         startEngine = 0;
         hideWeaponsGunner = 0;
         gunnerGetInAction = "GetInHigh";
         gunnerGetOutAction = "GetOutHigh";
         gunnerAction = "vehicle_turnout_2";
         gunnerInAction = "passenger_apc_narrow_generic02";
         ispersonturret = 1;
         dontCreateAI = 1;
         minOutElev = -10;
         maxOutElev = 40;
         initOutElev = 0;
         minOutTurn = -60;
         maxOutTurn = 80;
         initOutTurn = 0;
         minElev = -15;
         maxElev = 50;
         initElev = 0;
         minTurn = -120;
         maxTurn = 120;
         initTurn = 0;
         commanding = -1;
         viewGunnerInExternal = 0;
         gunnerOpticsModel = "";
         gunnerOutOpticsColor[] = {0, 0, 0, 1};
         gunnerForceOptics = 0;
         gunnerOutForceOptics = 0;
         gunnerOutOpticsShowCursor = 0;
         memoryPointGunnerOptics = "";
         gunnerOpticsEffect[] = {};
         outGunnerMayFire = 1;
         inGunnerMayFire = 0;
         stabilizedInAxes = 0;
         LODTurnedOut = -1;
         LODTurnedIn = 1000;
         LODOpticsIn = 1000;
         LODOpticsOut = -1;
         memoryPointsGetInGunner = "pos cargoleft";
         memoryPointsGetInGunnerDir = "pos cargoleft dir";
         canUseScanner = 0;
      };
      class CargoGunner_2 : NewTurret
      {
         gunnerCompartments = "Compartment1";
         weapons[] = {};
         magazines[] = {};
         proxyType = "CPCargo";
         proxyIndex = 6;
         gunnerName = "$STR_A3_TURRETS_CARGOTURRET_RR";
         primaryGunner = 0;
         primaryObserver = 0;
         gunnerOpticsShowCursor = 0;
         body = "";
         gun = "";
         animationSourceBody = "";
         animationSourceGun = "";
         animationSourceHatch = "hatchright";
         soundServo[] =
             {
                 "",
                 "db-50",
                 1};
         startEngine = 0;
         hideWeaponsGunner = 0;
         gunnerGetInAction = "GetInHigh";
         gunnerGetOutAction = "GetOutHigh";
         gunnerAction = "vehicle_turnout_2";
         gunnerInAction = "passenger_apc_narrow_generic01";
         ispersonturret = 1;
         dontCreateAI = 1;
         minOutElev = -10;
         maxOutElev = 40;
         initOutElev = 0;
         minOutTurn = -100;
         maxOutTurn = 80;
         initOutTurn = 0;
         minElev = -15;
         maxElev = 50;
         initElev = 0;
         minTurn = -120;
         maxTurn = 120;
         initTurn = 0;
         commanding = -1;
         viewGunnerInExternal = 0;
         gunnerOpticsModel = "";
         gunnerOutOpticsColor[] = {0, 0, 0, 1};
         gunnerForceOptics = 0;
         gunnerOutForceOptics = 0;
         gunnerOutOpticsShowCursor = 0;
         memoryPointGunnerOptics = "";
         gunnerOpticsEffect[] = {};
         outGunnerMayFire = 1;
         inGunnerMayFire = 0;
         stabilizedInAxes = 0;
         LODTurnedOut = -1;
         LODTurnedIn = 1000;
         LODOpticsIn = 1000;
         LODOpticsOut = -1;
         memoryPointsGetInGunner = "pos cargoright";
         memoryPointsGetInGunnerDir = "pos cargoright dir";
         canUseScanner = 0;
      };
   };
   class textureSources
   {
      class woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] = {"\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody2_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lav_hq_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavalfa_ca.paa"};
         factions[] = {};
      };
      class desert
      {
         displayName = "Desert";
         author = "J.Downs";
         textures[] = {"\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody_desert_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody2_desert_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lav_hq_desert_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavalfa_desert_ca.paa"};
         factions[] = {};
      };
      class snow
      {
         displayName = "Snow";
         author = "J.Downs";
         textures[] = {"\PTF_Textures\vehicles\lav25a\lavbody_snow_co.paa", "\PTF_Textures\vehicles\lav25a\lavbody2_snow_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lav_hq_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavalfa_ca.paa"};
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
   class TransportMagazines
   {
      class _xx_rhsusf_100rnd_762x51_m80a1epr
      {
         magazine = "rhsusf_100rnd_762x51_m80a1epr";
         count = 2;
      };
      class _xx_rhsusf_200rnd_556x45_mixed_soft_pouch_coyote
      {
         magazine = "rhsusf_200rnd_556x45_mixed_soft_pouch_coyote";
         count = 2;
      };
      class _xx_rhs_mag_20rnd_SCAR_762x51_mk316_special
      {
         magazine = "rhs_mag_20rnd_SCAR_762x51_mk316_special";
         count = 8;
      };
      class _xx_rhsusf_20rnd_762x51_SR25_m993_mag
      {
         magazine = "rhsusf_20rnd_762x51_SR25_m993_mag";
         count = 4;
      };
      class _xx_rhsusf_20rnd_762x51_SR25_mk316_special_mag
      {
         magazine = "rhsusf_20rnd_762x51_SR25_mk316_special_mag";
         count = 4;
      };
      class _xx_PTF_mag_556x45_mk318_stanag_mix
      {
         magazine = "PTF_mag_556x45_mk318_stanag_mix";
         count = 15;
      };
      class _xx_rhs_fgm148_magazine_at
      {
         magazine = "rhs_fgm148_magazine_at";
         count = 1;
      };
      class _xx_rhs_fim92_mag
      {
         magazine = "rhs_fim92_mag";
         count = 1;
      };
      class _xx_rhs_mag_m433_HEDP
      {
         magazine = "rhs_mag_m433_HEDP";
         count = 5;
      };
      class _xx_rhs_mag_m67
      {
         magazine = "rhs_mag_m67";
         count = 5;
      };
      class _xx_rhs_mag_m714_white
      {
         magazine = "rhs_mag_m714_white";
         count = 5;
      };
      class _xx_smokeshell
      {
         magazine = "smokeshell";
         count = 5;
      };
      class _xx_democharge_remote_mag
      {
         magazine = "democharge_remote_mag";
         count = 2;
      };
      class _xx_satchelcharge_remote_mag
      {
         magazine = "satchelcharge_remote_mag";
         count = 1;
      };
   };
   class TransportItems
   {
      class _xx_ToolKit
      {
         name = "ToolKit";
         count = 1;
      };
      class _xx_Ace_clacker
      {
         name = "Ace_clacker";
         count = 1;
      };
   };
   class TransportWeapons
   {
      class _xx_RHS_weap_fgm148
      {
         weapon = "RHS_weap_fgm148";
         count = 1;
      };
      class _xx_RHS_weap_fim92
      {
         weapon = "RHS_weap_fim92";
         count = 1;
      };
   };
   class TransportBackpacks
   {
   };
};