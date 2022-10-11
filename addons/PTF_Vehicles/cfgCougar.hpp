//MRAPs
class PTF_MRAP_CGRCAT1A2_MK19 : rhsusf_CGRCAT1A2_Mk19_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_MRAP";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "CGRCAT1A2 (Mk19) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "pintle"};
   hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_WD_CO.paa", "rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa", "rhsusf\addons\rhsusf_rg33l\data\MCTAGS_WD_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class M2_Turret : MainTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerLeftHandAnimName = "OtocHlaven";
         gunnerRightHandAnimName = "OtocHlaven";
         gunnerLeftLegAnimName = "gunner_legs";
         gunnerRightLegAnimName = "gunner_legs";
         body = "mainTurret";
         gun = "mainGun";
         animationSourceBody = "mainTurret";
         animationSourceGun = "mainGun";
         animationSourceStickX = "MainTurret_Inertia";
         animationSourceStickY = "MainGun_Inertia";
         turretInfoType = "RHS_RscWeaponZeroing_TurretAdjust";
         discreteDistance[] = {100, 200, 300, 400, 500, 600, 800, 1000, 1100, 1200, 1300, 1400, 1500};
         discreteDistanceInitIndex = 2;
         gunnerForceOptics = 0;
         gunnerOutOpticsShowCursor = 0;
         weapons[] = {"RHS_MK19"};
         magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M1001", "RHS_48Rnd_40mm_MK19_M1001", "RHS_48Rnd_40mm_MK19_M1001"};
         minElev = -10;
         maxElev = 40;
         soundServo[] = {"A3\sounds_f\dummysound", 1e-06, 1};
         gunnerAction = "RHS_MCTAGS_Gunner03";
         gunnerInAction = "RHS_MCTAGS_Gunner03_in";
         lodTurnedIn = 0;
         lodTurnedOut = 1000;
         lodOpticsOut = 1000;
         canhideGunner = 1;
         inGunnerMayFire = 0;
         outGunnerMayFire = 1;
         viewGunnerInExternal = 1;
         gunnerGetInAction = "GetInMRAP_01_cargo";
         gunnerGetOutAction = "GetOutMRAP_01";
         gunnerDoor = "DoorR";
         ejectDeadGunner = 0;
         castGunnerShadow = 1;
         stabilizedInAxes = 0;
         gunBeg = "usti hlavne";
         gunEnd = "konec hlavne";
         memoryPointGunnerOptics = "";
         memoryPointGunnerOutOptics = "gunnerview";
         gunnerOpticsModel = "";
         gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
         optics = 0;
         disableSoundAttenuation = 1;
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
      class CargoTurret_01 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         weapons[] = {"rhsusf_weap_DummyLauncher"};
         gunnerAction = "rhs_cougar_turnout_1";
         gunnerInAction = "RHS_cougar_Cargo01_FFV";
         animationSourceHatch = "hatch1";
         enabledByAnimationSource = "hatch1_door";
         isPersonTurret = 2;
         gunnerGetInAction = "GetInMantis";
         gunnerGetOutAction = "GetOutMantis";
         memoryPointsGetInGunner = "pos cargoFFV1";
         memoryPointsGetInGunnerDir = "pos cargoFFV1 dir";
         rhs_hatch_control = 1;
         gunnerName = "Passenger (Rear Hatch)";
         gunnerDoor = "DoorB";
         memoryPointGunnerOptics = "";
         selectionFireAnim = "";
         canHideGunner = 1;
         commanding = -2;
         LODTurnedIn = 1200;
         LODTurnedOut = 0;
         proxyIndex = 4;
         maxElev = 45;
         minElev = -35;
         maxTurn = 61;
         minTurn = -65;
         class TurnIn
         {
            limitsArrayTop[] = {{0, 0}, {0, 0}};
            limitsArrayBottom[] = {{0, 0}, {0, 0}};
         };
         class TurnOut
         {
            limitsArrayTop[] = {{45.0, -90.1745}, {44.9894, 80.629}};
            limitsArrayBottom[] = {{5.464, -89.894}, {-9.4602, -71.7306}, {-7.5523, -40.9866}, {-16.3809, -30.7844}, {-7.1172, -30.2764}, {-13.0122, -5.9314}, {-12.7133, 26.3332}, {-23.1407, 58.6419}, {-8.5688, 77.4948}, {-7.292, 80.6933}};
         };
         class Hitpoints
         {
         };
      };
   };
   class textureSources
   {
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {"PTF_Textures\vehicles\cgrcat\CGR_Body_s_CO.paa", "rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa", "PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_CO.paa", "rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa", "rhsusf\addons\rhsusf_rg33l\data\MCTAGS_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_WD_CO.paa", "rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa", "rhsusf\addons\rhsusf_rg33l\data\MCTAGS_WD_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
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
         dimensions[] = {};
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
class PTF_MRAP_CGRCAT1A2_M2 : rhsusf_CGRCAT1A2_M2_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_MRAP";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "CGRCAT1A2 (M2) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "pintle"};
   hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_WD_CO.paa", "rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa", "rhsusf\addons\rhsusf_rg33l\data\MCTAGS_WD_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class M2_Turret : MainTurret
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
         magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red"};
         minElev = -10;
         maxElev = 40;
         soundServo[] = {"A3\sounds_f\dummysound", 1e-06, 1};
         gunnerAction = "RHS_MCTAGS_Gunner03";
         gunnerInAction = "RHS_MCTAGS_Gunner03_in";
         lodTurnedIn = 0;
         lodTurnedOut = 1000;
         lodOpticsOut = 1000;
         canhideGunner = 1;
         inGunnerMayFire = 0;
         outGunnerMayFire = 1;
         viewGunnerInExternal = 1;
         gunnerGetInAction = "GetInMRAP_01_cargo";
         gunnerGetOutAction = "GetOutMRAP_01";
         gunnerDoor = "DoorR";
         ejectDeadGunner = 0;
         castGunnerShadow = 1;
         stabilizedInAxes = 0;
         gunBeg = "usti hlavne";
         gunEnd = "konec hlavne";
         memoryPointGunnerOptics = "";
         memoryPointGunnerOutOptics = "gunnerview";
         gunnerOpticsModel = "";
         gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
         optics = 0;
         disableSoundAttenuation = 1;
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
      class CargoTurret_01 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         weapons[] = {"rhsusf_weap_DummyLauncher"};
         gunnerAction = "rhs_cougar_turnout_1";
         gunnerInAction = "RHS_cougar_Cargo01_FFV";
         animationSourceHatch = "hatch1";
         enabledByAnimationSource = "hatch1_door";
         isPersonTurret = 2;
         gunnerGetInAction = "GetInMantis";
         gunnerGetOutAction = "GetOutMantis";
         memoryPointsGetInGunner = "pos cargoFFV1";
         memoryPointsGetInGunnerDir = "pos cargoFFV1 dir";
         rhs_hatch_control = 1;
         gunnerName = "Passenger (Rear Hatch)";
         gunnerDoor = "DoorB";
         memoryPointGunnerOptics = "";
         selectionFireAnim = "";
         canHideGunner = 1;
         commanding = -2;
         LODTurnedIn = 1200;
         LODTurnedOut = 0;
         proxyIndex = 4;
         maxElev = 45;
         minElev = -35;
         maxTurn = 61;
         minTurn = -65;
         class TurnIn
         {
            limitsArrayTop[] = {{0, 0}, {0, 0}};
            limitsArrayBottom[] = {{0, 0}, {0, 0}};
         };
         class TurnOut
         {
            limitsArrayTop[] = {{45.0, -90.1745}, {44.9894, 80.629}};
            limitsArrayBottom[] = {{5.464, -89.894}, {-9.4602, -71.7306}, {-7.5523, -40.9866}, {-16.3809, -30.7844}, {-7.1172, -30.2764}, {-13.0122, -5.9314}, {-12.7133, 26.3332}, {-23.1407, 58.6419}, {-8.5688, 77.4948}, {-7.292, 80.6933}};
         };
         class Hitpoints
         {
         };
      };
   };
   class textureSources
   {
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {"PTF_Textures\vehicles\cgrcat\CGR_Body_s_CO.paa", "rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa", "PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_CO.paa", "rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa", "rhsusf\addons\rhsusf_rg33l\data\MCTAGS_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_cougar\data\CGR_Body_WD_CO.paa", "rhsusf\addons\rhsusf_cougar\data\CGR_Labels_CA.paa", "rhsusf\addons\rhsusf_rg33l\data\MCTAGS_WD_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
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
         dimensions[] = {};
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