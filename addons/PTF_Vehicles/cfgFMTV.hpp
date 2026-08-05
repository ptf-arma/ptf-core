//FMTV
class PTF_M1085A1P2 : rhsusf_M1085A1P2_B_WD_Medical_fmtv_usarmy
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Utility";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1085A1P2 [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] =
       {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo9", "camo10", "camo11", "camo12", "camo13", "camo14", "camo15", "camo16", "camo17", "camo18", "camo19"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Desert
      {
         displayName = "Desert";
         author = "J.Downs";
         textures[] =
             {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_d_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_D_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\rg33_turretd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovchassis_co.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovcab_co.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] =
             {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
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
class PTF_M1078A1P2 : rhsusf_M1078A1P2_WD_fmtv_usarmy
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Cars";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 1500;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1078A1P2 [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] =
       {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo9", "camo10", "camo11", "camo12", "camo13", "camo14", "camo15", "camo16", "camo17", "camo18", "camo19"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CargoTurret_01 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerAction = "passenger_inside_2";
         gunnerGetInAction = "GetInHemttBack";
         gunnerGetOutAction = "GetOutHighZamak";
         memoryPointsGetInGunner = "pos cargo LR";
         memoryPointsGetInGunnerDir = "pos cargo LR dir";
         gunnerName = "Passenger (Left Seat)";
         proxyIndex = 12;
         maxElev = 15;
         minElev = -15;
         maxTurn = -40;
         minTurn = -115;
         isPersonTurret = 1;
         selectionFireAnim = "";
         commanding = -2;
         class Hitpoints
         {
         };
      };
      class CargoTurret_02 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Passenger (Right Seat)";
         memoryPointsGetInGunner = "pos cargo RR";
         memoryPointsGetInGunnerDir = "pos cargo RR dir";
         proxyIndex = 11;
         maxTurn = 95;
         minTurn = 20;
         minElev = -45;
      };
   };
   class textureSources
   {
      class Desert
      {
         displayName = "Desert";
         author = "J.Downs";
         textures[] =
             {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_d_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_D_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\rg33_turretd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovchassis_co.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovcab_co.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] =
             {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
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
class PTF_M1078A1P2_M2 : rhsusf_M1078A1P2_B_M2_WD_fmtv_usarmy
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 1500;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1078A1P2 (M2) [PTF]";

   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] =
       {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo9", "camo10", "camo11", "camo12", "camo13", "camo14", "camo15", "camo16", "camo17", "camo18", "camo19"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class M2_Turret : NewTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerLeftHandAnimName = "OtocHlaven_Shake";
         gunnerRightHandAnimName = "OtocHlaven_Shake";
         gunnerLeftLegAnimName = "gunner_legs";
         gunnerRightLegAnimName = "gunner_legs";
         body = "mainTurret";
         gun = "mainGun";
         animationSourceBody = "mainTurret";
         animationSourceGun = "mainGun";
         animationSourceStickX = "MainTurret_Inertia";
         animationSourceStickY = "MainGun_Inertia";
         turretInfoType = "RHS_RscWeaponZeroing_TurretAdjust";
         discreteDistance[] = {100, 200, 300, 400, 500, 600, 800, 1000, 1200, 1500};
         discreteDistanceInitIndex = 2;
         gunnerForceOptics = 0;
         gunnerOutOpticsShowCursor = 0;
         weapons[] = {"RHS_M2"};
         magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red"};
         minElev = -10;
         maxElev = 40;
         soundServo[] = {"A3\sounds_f\dummysound", 0.01, 1, 10};
         soundServoVertical[] = {"A3\sounds_f\dummysound", 0.01, 1, 10};
         soundAttenuationTurret = "HeliAttenuationGunner";
         disableSoundAttenuation = 0;
         gunnerAction = "RHS_HMMWV_Gunner03";
         gunnerInAction = "RHS_HMMWV_Gunner03_in";
         lodTurnedIn = 0;
         lodTurnedOut = 1000;
         lodOpticsOut = 1000;
         canhideGunner = 1;
         inGunnerMayFire = 0;
         outGunnerMayFire = 1;
         viewGunnerInExternal = 1;
         gunnerGetInAction = "GetInMRAP_01_cargo";
         gunnerGetOutAction = "GetOutMRAP_01";
         gunnerDoor = "Door_RF";
         ejectDeadGunner = 0;
         castGunnerShadow = 1;
         stabilizedInAxes = 0;
         startEngine = 0;
         gunBeg = "usti hlavne";
         gunEnd = "konec hlavne";
         memoryPointGunnerOptics = "";
         memoryPointGunnerOutOptics = "gunnerview";
         gunnerOpticsModel = "";
         gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
         optics = 0;
         memoryPointsGetInGunner = "pos codriver";
         memoryPointsGetInGunnerDir = "pos codriver dir";
         class ViewOptics : ViewOptics
         {
            initFov = 0.7;
            minFov = 0.25;
            maxFov = 1.1;
         };
         class ViewGunner : ViewOptics
         {
         };
      };
      class CargoTurret_01 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoTurret_02 : CargoTurret_02
      {
         gunnerCompartments = "Compartment1";
      };
   };
   class textureSources
   {
      class Desert
      {
         displayName = "Desert";
         author = "J.Downs";
         textures[] =
             {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_d_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_D_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\rg33_turretd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_D_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovchassis_co.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovcab_co.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] =
             {"rhsusf\addons\rhsusf_fmtv\data\FMTV_Cab_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_wheel_wd_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_25TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_BKIT_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis1_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRear_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Canvas2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Shelter_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Hospital_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_5TRearLHC_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_Chassis2_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVChassis_WD_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVCab_W_CO.paa", "rhsusf\addons\rhsusf_fmtv\data\fmtv_sovrear_w_co.paa", "rhsusf\addons\rhsusf_fmtv\data\FMTV_SOVKit_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};
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
