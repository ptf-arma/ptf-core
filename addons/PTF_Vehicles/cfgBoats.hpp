class PTF_MKVSOC : rhsusf_mkvsoc
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

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MainTurret : NewTurret
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
         soundServo[] = {"A3\sounds_f\dummysound", 0.0056234132, 1.0};
         gunBeg = "m2_p_beginBarrel";
         gunEnd = "m2_p_endBarrel";
         weapons[] = {"RHS_MKV_M2_p"};
         magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red"};
         turretInfoType = "RHS_RscWeaponZeroing";
         discreteDistance[] = {100, 200, 300, 400, 500, 600, 800, 1000, 1200, 1500};
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
         class m2_p_ViewOptics : ViewOptics
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
         class m2_p_ViewGunner : ViewOptics
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
      class m2_s_gunTurret : MainTurret
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
      class m134_p_gunTurret : MainTurret
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
         magazines[] = {"2000Rnd_762x51_Belt_T_Red", "2000Rnd_762x51_Belt_T_Red"};
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
         class m134_p_ViewOptics : ViewOptics
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
         class m134_p_ViewGunner : ViewOptics
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
      class mk19_s_gunTurret : MainTurret
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
         magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1"};
         discreteDistance[] = {300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500};
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
         class mk19_s_ViewOptics : ViewOptics
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
         class mk19_s_ViewGunner : ViewOptics
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
      class camera_b_gunTurret : MainTurret
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
         soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best", 0.01, 1, 50};
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
         class camera_b_ViewOptics : ViewOptics
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
            visionMode[] = {"Normal", "NVG", "Ti"};
            thermalMode[] = {2, 3, 4};
         };
         class camera_b_ViewGunner : ViewOptics
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
         class HitPoints
         {
         };
      };
      class rem_spotL_gunTurret : MainTurret
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
         soundServo[] = {"A3\Sounds_F\vehicles\armor\noises\servo_best", 0.2, 1, 1.0};
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
         class rem_spotL_ViewOptics : ViewOptics
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
         class rem_spotL_ViewGunner : ViewOptics
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
         class HitPoints
         {
         };
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
