//M1152
class PTF_M1152 : rhsusf_m1152_rsv_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Cars";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 5000;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1152 [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo11", "BFT_screen"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_2drcargo_w_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CoDriverTurret : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         showAsCargo = 1;
         lodTurnedIn = 1100;
         lodTurnedOut = 1100;
         gunnerForceOptics = 0;
         gunnerName = "Co-driver";
         proxyIndex = 1;
         isPersonTurret = 0;
         gunnerAction = "RHS_M11XX_CoDriver";
         gunnerinAction = "RHS_M11XX_CoDriver";
         memoryPointsGetInGunner = "pos codriver";
         memoryPointsGetInGunnerDir = "pos codriver dir";
         gunnerDoor = "Door_RF";
         turretInfoType = "RHS_RscMATV_Codriver";
         selectionFireAnim = "";
         class Hitpoints
         {
         };
      };
   };
   class textureSources
   {
      class Desert
      {
         displayName = "Desert";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_2drcargo_d_co.paa"};
         decals[] = {8};
         factions[] = {};
      };
      class Woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_2drcargo_w_co.paa"};
         decals[] = {8};
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
      class Carrier
      {
         cargoBayDimensions[] = {"VTV_cargo_1", "VTV_cargo_2"};
         disableHeightLimit = 0;
         maxLoadMass = 2300;
         cargoAlignment[] = {"center", "front"};
         cargoSpacing[] = {0, 0, 0};
         exits[] = {"VTV_exit"};
         unloadingInterval = 2;
         loadingDistance = 3;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 5;
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
class PTF_M1123 : rhsusf_m998_d_s_2dr_fulltop
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Cars";
   ace_cargo_space = 5;
   ace_cargo_hasCargo = 1;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1123 [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};
   
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