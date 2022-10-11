//MQ-9
class PTF_RQ4A : USAF_RQ4A
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
   displayName = "RQ-4A [MAG36]";

   driverOpticsModel = "USAF_MQ9\optic_mq9.p3d";

   weapons[] = {"CMFlareLauncher"};
   magazines[] = {"240Rnd_CMFlare_Chaff_Magazine", "240Rnd_CMFlare_Chaff_Magazine", "240Rnd_CMFlare_Chaff_Magazine", "240Rnd_CMFlare_Chaff_Magazine"};

   hiddenSelections[] = {"camo1"};
   hiddenSelectionsTextures[] = {"A3\Drones_F\Air_F_Gamma\UAV_02\Data\UAV_02_CO.paa"};

   class Turrets : Turrets
   {
      class MainTurret : NewTurret
      {
         isCopilot = 0;
         minElev = -85;
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
         gunnerOpticsEffect[] = {"TankCommanderOptics1", "BWTVedit"};
         gunnerForceOptics = "true";
         turretInfoType = "Rsc_USAF_RQ4A_Turret_UI";
         turretCanSee = "1 + 2 + 4 + 8 + 16";
         stabilizedInAxes = 3;
         enableManualFire = 0;
         weapons[] = {"Laserdesignator_mounted"};
         magazines[] = {"Laserbatteries"};
         GunnerCompartments = "Compartment1";
         gunnerInAction = "Disabled";
         gunnerAction = "Disabled";
         class OpticsIn
         {
            class Wide
            {
               opticsDisplayName = "W";
               initAngleX = 0;
               minAngleX = -35;
               maxAngleX = 10;
               initAngleY = 0;
               minAngleY = -100;
               maxAngleY = 100;
               initFov = 0.466;
               minFov = 0.466;
               maxFov = 0.466;
               visionMode[] = {"Normal", "NVG", "Ti"};
               thermalMode[] = {0, 1};
               gunnerOpticsColor[] = {0.15, 1, 0.15, 1};
               gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
               directionStabilized = 1;
               opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
               gunnerOpticsEffect[] = {"TankCommanderOptics1", "BWTVedit"};
            };
            class WideL : Wide
            {
               opticsDisplayName = "WL";
               initFov = 0.2;
               minFov = 0.2;
               maxFov = 0.2;
               gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
               gunnerOpticsColor[] = {0, 0, 0, 1};
               directionStabilized = 1;
               opticsPPEffects[] = {"OpticsCHAbera2", "OpticsBlur2"};
            };
            class Medium : Wide
            {
               opticsDisplayName = "M";
               initFov = 0.1;
               minFov = 0.1;
               maxFov = 0.1;
               directionStabilized = 1;
               gunnerOpticsColor[] = {0, 0, 0, 1};
               gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
            };
            class Narrow : Wide
            {
               opticsDisplayName = "N";
               gunnerOpticsColor[] = {0, 0, 0, 1};
               gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
               directionStabilized = 1;
               initFov = 0.02;
               minFov = 0.02;
               maxFov = 0.02;
            };
            class Narrower : Wide
            {
               opticsDisplayName = "N";
               gunnerOpticsColor[] = {0, 0, 0, 1};
               gunnerOpticsModel = "USAF_MQ9\optic_mq9.p3d";
               directionStabilized = 1;
               initFov = 0.01;
               minFov = 0.01;
               maxFov = 0.01;
            };
            class UltraNarrow : Narrower
            {
               opticsDisplayName = "ULTN";
               gunnerOpticsColor[] = {0, 0, 0, 1};
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
               visionMode[] = {"Normal", "NVG"};
               gunnerOpticsModel = "";
               gunnerOpticsEffect[] = {};
            };
         };
      };
   };
   class TextureSources
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
