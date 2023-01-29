class PTF_SSO_AR2 : B_UAV_01_F
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   maxSpeed = 25;
   fuelCapacity = 10;
   armor = 2.5;
   class HitPoints: HitPoints
		{
			class HitHull: HitHull
			{
				armor = 0.5;
			};
			class HitHRotor: HitHRotor
			{
				armor = 1.5;
			};
		};
   class Viewoptics : ViewOptics
   {
      initAngleX = 0;
      minAngleX = 0;
      maxAngleX = 0;
      initAngleY = 0;
      minAngleY = 0;
      maxAngleY = 0;
      minFov = 0.25;
      maxFov = 1.25;
      initFov = 0.75;
      visionMode[] = {"Normal", "NVG"};
      thermalMode[] = {0, 1};
   };
   class assembleInfo
   {
      primary = 0;
      base = "";
      assembleTo = "";
      displayName = "PTF Infantry SSO Kit";
      dissasembleTo[] = {"PTF_SSO_Backpack"};
   };
   class Turrets : Turrets
   {
      class MainTurret : MainTurret
      {
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
               initFov = 0.5;
               minFov = 0.5;
               maxFov = 0.5;
               directionStabilized = 1;
               visionMode[] = {"Normal", "NVG"};
               thermalMode[] = {0, 1};
               gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_wide_F.p3d";
            };
            class Medium : Wide
            {
               opticsDisplayName = "M";
               initFov = 0.1;
               minFov = 0.1;
               maxFov = 0.1;
               gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_medium_F.p3d";
            };
            class Narrow : Wide
            {
               opticsDisplayName = "N";
               initFov = 0.0286;
               minFov = 0.0286;
               maxFov = 0.0286;
               gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UAV_Optics_Gunner_narrow_F.p3d";
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
               visionMode[] = {"Normal"};
               gunnerOpticsModel = "";
               gunnerOpticsEffect[] = {};
            };
         };
         inGunnerMayFire = 1;
         outGunnerMayFire = 1;
         commanding = -1;
         primaryGunner = 1;
         memoryPointGun = "PIP0_dir";
         memoryPointGunnerOptics = "PIP0_pos";
         gunnerOpticsModel = "A3\drones_f\Weapons_F_Gamma\Reticle\UGV_01_Optics_Gunner_F.p3d";
         gunnerForceOptics = 1;
         turretInfoType = "RscOptics_UAV_gunner";
         stabilizedInAxes = 3;
         weapons[] = {"Laserdesignator_mounted"};
         magazines[] = {"Laserbatteries"};
         soundServo[] = {"A3\Sounds_F\vehicles\air\noises\servo_drone_turret_2", 0.031622775, 0.5, 10};
         soundServoVertical[] = {"A3\Sounds_F\vehicles\air\noises\servo_drone_turret_2", 0.031622775, 0.5, 10};
         GunnerCompartments = "Compartment1";
         LODTurnedIn = -1;
         LODTurnedOut = -1;
      };
   };
};
