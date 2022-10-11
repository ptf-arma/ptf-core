//Quadbike
class PTF_Quadbike : B_T_Quadbike_01_F
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_UtilityAir";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "Quad Bike [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo1", "camo2"};
   hiddenSelectionsTextures[] = {
       "\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_olive_CO.paa", "\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_wheel_olive_CO.paa"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Black
      {
         displayName = "Black";
         author = "J.Downs";
         textures[] = {"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLACK_CO.paa", "\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLACK_CO.paa"};
         factions[] = {};
      };
      class Blue
      {
         displayName = "Blue";
         author = "J.Downs";
         textures[] = {"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_BLUE_CO.paa", "\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVBLUE_CO.paa"};
         factions[] = {};
      };
      class Red
      {
         displayName = "Red";
         author = "J.Downs";
         textures[] = {"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_RED_CO.paa", "\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVRED_CO.paa"};
         factions[] = {};
      };
      class White
      {
         displayName = "White";
         author = "J.Downs";
         textures[] = {"\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_CIV_WHITE_CO.paa", "\A3\Soft_F_Beta\Quadbike_01\Data\Quadbike_01_wheel_CIVWHITE_CO.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayName = "Desert";
         author = "J.Downs";
         textures[] = {"\A3\Soft_F\Quadbike_01\Data\Quadbike_01_co.paa", "\A3\Soft_F\Quadbike_01\Data\Quadbike_01_wheel_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] = {"\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_olive_CO.paa", "\A3\Soft_F_Exp\Quadbike_01\Data\Quadbike_01_wheel_olive_CO.paa"};
         factions[] = {};
      };
   };
   class VehicleTransport
   {
      class Cargo
      {
         dimensions[] = {"VTV_Cargo_Base", "VTV_Cargo_Corner"};
         parachuteClass = "B_Parachute_02_F";
         canBeTransported = 1;
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
//SDV
class PTF_SDV : B_SDV_01_F
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
   displayName = "SDV [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"Camo1"};
   hiddenSelectionsTextures[] = {
       "\A3\boat_f_beta\SDV_01\data\SDV_ext_CO.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CommanderTurret : NewTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Gunner";
         proxyType = "CPCommander";
         commanding = -1;
         ejectDeadGunner = 0;
         body = "ObsTurret";
         gun = "ObsGun";
         animationSourceBody = "ObsTurret";
         animationSourceGun = "ObsGun";
         gunBeg = "PIP1_dir";
         gunEnd = "PIP1_pos";
         memoryPointGunnerOptics = "PIP1_dir";
         weapons[] = {"Laserdesignator_mounted"};
         magazines[] = {"Laserbatteries"};
         soundServo[] = {"A3\sounds_f\dummysound", 0.01, 1, 10};
         gunnerAction = "commander_SDV";
         gunnergetInAction = "GetInLow";
         gunnergetOutAction = "GetOutLow";
         memoryPointsGetInGunner = "pos commander";
         memoryPointsGetInGunnerDir = "pos commander dir";
         usePip = 1;
         Laser = 1;
         stabilizedInAxes = 4;
         gunnerOpticsModel = "\A3\weapons_f_beta\reticle\reticle_SDV";
         turretInfoType = "RscOptics_SDV_periscope";
         gunnerForceOptics = 0;
         LODTurnedIn = 1100;
         LODTurnedOut = 1100;
         outGunnerMayFire = 1;
         startEngine = 0;
         class ViewOptics : ViewOptics
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
      };
   };
   class textureSources
   {
      class USMC
      {
         displayName = "USMC";
         author = "J.Downs";
         textures[] = {
             "\A3\boat_f_beta\SDV_01\data\SDV_ext_CO.paa"};
         decals[] = {};
         factions[] = {};
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