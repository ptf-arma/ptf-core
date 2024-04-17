//M1151
class PTF_M1151 : rhsusf_m1151_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Cars";
   ace_cargo_space = 15;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1151 [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "BFT_screen"};
   hiddenSelectionTextures[] = {
       "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa"};

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
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {
             "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa"};
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
         disableHeightLimit = 1;
         maxLoadMass = 1500;
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
class PTF_M1151_MK19 : rhsusf_m1151_mk19_v3_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 15;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1151 (Mk19) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo19", "BFT_screen"};
   hiddenSelectionTextures[] = {
       "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MCTAGS_Turret : MCTAGS_Turret
      {
         gunnerCompartments = "Compartment1";
         discreteDistance[] = {100, 200, 300, 400, 500, 600, 800, 1000, 1200, 1500};
         discreteDistanceInitIndex = 2;
         gunnerLeftHandAnimName = "OtocHlaven";
         gunnerRightHandAnimName = "OtocHlaven";
         weapons[] = {"RHS_MK19"};
         magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M1001", "RHS_48Rnd_40mm_MK19_M1001", "RHS_48Rnd_40mm_MK19_M1001"};
      };
      class CoDriverTurret : CoDriverTurret
      {
         gunnerCompartments = "Compartment1";
      };
   };
   class textureSources
   {
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {
             "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
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
         disableHeightLimit = 1;
         maxLoadMass = 1500;
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
class PTF_M1151_M240 : rhsusf_m1151_m240_v3_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 15;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1151 (M240) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo19", "BFT_screen"};
   hiddenSelectionTextures[] = {
       "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_wd_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MCTAGS_Turret : MCTAGS_Turret
      {
         gunnerCompartments = "Compartment1";
         gunnerAction = "RHS_MATV_Gunner_M240";
         gunnerInAction = "RHS_HMMWV_Gunner03_in";
         gunnerLeftHandAnimName = "OtocHlaven";
         gunnerRightHandAnimName = "OtocHlaven";
         discreteDistance[] = {100, 200, 300, 400, 500, 600, 700, 800, 900, 1000, 1100, 1200, 1300, 1400, 1500};
         discreteDistanceInitIndex = 2;
         selectionFireAnim = "zasleh";
         memoryPointGunnerOptics = "gunnerview";
         memoryPointGunnerOutOptics = "gunnerview";
         minElev = -18;
         maxElev = 40;
         weapons[] = {"rhs_weap_m240_m113"};
         magazines[] = {"rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200", "rhs_mag_762x51_M240_200"};
      };
      class CoDriverTurret : CoDriverTurret
      {
         gunnerCompartments = "Compartment1";
      };
   };
   class textureSources
   {
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {
             "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\mk64mount_s_co.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\m11165a1_gmv_h246mount_s_co.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa", "rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_des_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_m1165\data\rhsusf_m11165a1_gmv_h246mount_wd_co.paa"};
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
         disableHeightLimit = 1;
         maxLoadMass = 1500;
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
class PTF_M1151_M2 : rhsusf_m1151_m2_v3_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 15;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1151 (M2) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo19", "BFT_screen"};
   hiddenSelectionTextures[] = {
       "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class MCTAGS_Turret : MCTAGS_Turret
      {
         gunnerCompartments = "Compartment1";
         discreteDistance[] = {100, 200, 300, 400, 500, 600, 800, 1000, 1200, 1500};
         discreteDistanceInitIndex = 2;
         gunnerLeftHandAnimName = "OtocHlaven";
         gunnerRightHandAnimName = "OtocHlaven";
         weapons[] = {"RHS_M2"};
         magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red"};
      };
      class CoDriverTurret : CoDriverTurret
      {
         gunnerCompartments = "Compartment1";
      };
   };
   class textureSources
   {
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {
             "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_rg33l\data\mctags_wd_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa"};
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
         disableHeightLimit = 1;
         maxLoadMass = 1500;
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
class PTF_M1151_M2_LRAS : rhsusf_m1151_m2_lras3_v1_usarmy_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 15;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1151 (M2\LRAS) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo10", "BFT_screen"};
   hiddenSelectionTextures[] = {
       "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_GPK_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_stryker\data\rhsusf_lras3_co.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class GPK_Turret : GPK_Turret
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Gunner";
         gunnerAction = "RHS_M11XX_LRAS_Gunner1_out";
         gunnerInAction = "RHS_M11XX_LRAS_Gunner1_in";
         gunnerForceOptics = 0;
         gunnerOutOpticsShowCursor = 0;
         viewGunnerInExternal = 1;
         LODTurnedOut = 1000;
         LODTurnedin = 1000;
         LODOpticsIn = 0;
         LODOpticsOut = 0;
         animationSourceHatch = "Hatch_Gunner_A";
         castGunnerShadow = 1;
         stabilizedInAxes = 0;
         startEngine = 0;
         usePip = 0;
         weapons[] = {};
         magazines[] = {};
         inGunnerMayFire = 1;
         outGunnerMayFire = 1;
         gunBeg = "";
         gunEnd = "";
         memoryPointGunnerOptics = "";
         memoryPointGunnerOutOptics = "gunnerview";
         memoryPointsGetInGunner = "pos cargo";
         memoryPointsGetInGunnerDir = "pos cargo dir";
         selectionFireAnim = "";
         gunnerOpticsModel = "";
         gunnerOutOpticsModel = "\A3\weapons_f\reticle\optics_empty";
         optics = 0;
         disableSoundAttenuation = 0;
      };
      class Turret_Weapon : GPK_Turret
      {
         gunnerCompartments = "Compartment1";
         soundServo[] = {"", 0.398107, 1, 30};
         soundServoVertical[] = {"", 0.398107, 1, 30};
         gunnerName = "Turret (M2)";
         gunnerDoor = "";
         gunnerAction = "RHS_M11XX_LRAS_Gunner2";
         isPersonTurret = 0;
         dontCreateAI = 1;
         personturretAction = "";
         proxyIndex = 2;
         canHideGunner = 0;
         initTurn = -20;
         minTurn = -180;
         maxTurn = 180;
         minElev = -9;
         maxElev = 30;
         maxhorizontalrotspeed = 0.6;
         maxverticalrotspeed = 0.44;
         inGunnerMayFire = 1;
         outGunnerMayFire = 1;
         LODTurnedOut = 1000;
         LODTurnedin = 1000;
         LODOpticsIn = 1000;
         LODOpticsOut = 1000;
         body = "Weapon_Turret";
         gun = "Weapon_Gun";
         animationSourceBody = "Weapon_Turret";
         animationSourceGun = "Weapon_Gun";
         gunnerLeftHandAnimName = "Weapon_Gun";
         gunnerRightHandAnimName = "Weapon_Gun";
         gunnerLeftLegAnimName = "Gunner_Weapon_Legs";
         gunnerRightLegAnimName = "Gunner_Weapon_Legs";
         animationSourceStickX = "Weapon_Turret_inertia";
         animationSourceStickY = "Weapon_Gun_Inertia";
         gunBeg = "usti hlavne";
         gunEnd = "konec hlavne";
         memoryPointGunnerOutOptics = "Weapon_GunnerView";
         selectionFireAnim = "muzzleFlash";
         discreteDistance[] = {100, 150, 200, 250, 300, 350, 400, 450, 500, 550, 600, 650, 700, 750, 800, 850, 900, 950, 1000, 1050, 1100, 1150, 1200, 1250, 1300, 1350, 1400, 1450, 1500, 1550, 1600, 1650, 1700, 1750, 1800, 1850, 1900, 1950, 2000};
         discreteDistanceInitIndex = 2;
         weapons[] = {"RHS_M2"};
         magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red"};
         class ViewGunner : ViewOptics
         {
            initAngleX = -1;
            initAngleY = 0;
            initFov = 0.9;
            minFov = 0.25;
            maxFov = 1.25;
            minAngleX = -65;
            maxAngleX = 85;
            minAngleY = -150;
            maxAngleY = 150;
            minMoveX = -0.075;
            maxMoveX = 0.075;
            minMoveY = -0.075;
            maxMoveY = 0.075;
            minMoveZ = -0.075;
            maxMoveZ = 0.1;
         };
         class Hitpoints
         {
            class HitTurret_M2
            {
               armor = -120;
               minimalHit = -0.13;
               explosionShielding = 0.5;
               name = "Hit_M2_Turret";
               visual = "-";
               armorComponent = "Hit_M2_Turret";
               passThrough = 0;
               radius = 0.2;
            };
            class HitGun_M2
            {
               armor = -120;
               minimalHit = -0.13;
               explosionShielding = 0.5;
               name = "Hit_M2_Gun";
               visual = "-";
               armorComponent = "Hit_M2_Gun";
               passThrough = 0;
               radius = 0.2;
            };
         };
      };
      class Turret_LRAS : Turret_Weapon
      {
         gunnerCompartments = "Compartment1";
         gunnerName = "Turret (LRAS3)";
         gunnerAction = "RHS_M11XX_LRAS_Gunner3";
         proxyIndex = 3;
         initTurn = 20;
         minTurn = -180;
         maxTurn = 180;
         minElev = -20;
         maxElev = 30;
         inGunnerMayFire = 1;
         outGunnerMayFire = 1;
         gunnerForceOptics = 0;
         body = "LRAS3_Turret";
         gun = "LRAS3_Gun";
         animationSourceBody = "LRAS3_Turret";
         animationSourceGun = "LRAS3_Gun";
         gunnerLeftHandAnimName = "LRAS3";
         gunnerRightHandAnimName = "LRAS3";
         gunnerLeftLegAnimName = "Gunner_LRAS_Legs";
         gunnerRightLegAnimName = "Gunner_LRAS_Legs";
         animationSourceStickX = "";
         animationSourceStickY = "";
         memoryPointGunnerOutOptics = "LRAS3_GunnerView";
         gunBeg = "LRAS3_GunnerView_Dir";
         gunEnd = "LRAS3_GunnerView";
         selectionFireAnim = "";
         weapons[] = {"rhs_weap_laserDesignator_AI"};
         magazines[] = {"rhs_LaserMag_ai"};
         class ViewGunner : ViewOptics
         {
            initAngleX = -5;
            initAngleY = 0;
            initFov = 0.9;
            minFov = 0.25;
            maxFov = 1.25;
            minAngleX = -65;
            maxAngleX = 85;
            minAngleY = -150;
            maxAngleY = 150;
            minMoveX = -0.075;
            maxMoveX = 0.075;
            minMoveY = -0.075;
            maxMoveY = 0.075;
            minMoveZ = -0.075;
            maxMoveZ = 0.1;
         };
         class Components
         {
         };
         gunnerOutOpticsModel = "\rhsusf\addons\rhsusf_optics\data\rhsusf_LRAS3";
         turretInfoType = "RHS_RscLRAS3";
         class OpticsIn
         {
            class Wide : ViewOptics
            {
               opticsDisplayName = "4";
               initFov = 0.175;
               minFov = 0.175;
               maxFov = 0.175;
               visionMode[] = {"TI"};
               thermalMode[] = {2, 3};
               gunnerOpticsModel = "\rhsusf\addons\rhsusf_optics\data\rhsusf_CITV_w";
               hitpoint = "Hit_Optic_LRAS3";
            };
            class WideZoom : Wide
            {
               opticsDisplayName = "8";
               initFov = 0.0875;
               minFov = 0.0875;
               maxFov = 0.0875;
            };
            class Narrow : Wide
            {
               opticsDisplayName = "12";
               initFov = 0.0583333;
               minFov = 0.0583333;
               maxFov = 0.0583333;
            };
            class NarrowZoom : Wide
            {
               opticsDisplayName = "24";
               initFov = 0.0291667;
               minFov = 0.0291667;
               maxFov = 0.0291667;
            };
            class NarrowDoubleZoom : Wide
            {
               opticsDisplayName = "48";
               initFov = 0.0145833;
               minFov = 0.0145833;
               maxFov = 0.0145833;
            };
         };
         class OpticsOut
         {
            class Wide : ViewOptics
            {
               initFov = 0.9;
               minFov = 0.25;
               maxFov = 1.25;
               gunnerOpticsModel = "\rhsusf\addons\rhsusf_optics\data\rhsusf_LRAS3";
               hitpoint = "Hit_Optic_LRAS3";
            };
         };
         class Hitpoints
         {
            class HitTurret_LRAS3
            {
               armor = -120;
               minimalHit = -0.13;
               explosionShielding = 0.5;
               name = "Hit_LRAS3_Turret";
               visual = "vis_LRAS3_Turret";
               armorComponent = "Hit_LRAS3_Turret";
               passThrough = 0;
               radius = 0.1;
            };
            class HitGun_LRAS3
            {
               armor = -120;
               minimalHit = -0.13;
               explosionShielding = 0.5;
               name = "Hit_LRAS3_Gun";
               visual = "vis_LRAS3_Gun";
               armorComponent = "Hit_LRAS3_Gun";
               passThrough = 0;
               radius = 0.1;
            };
         };
      };
      class CoDriverTurret : CoDriverTurret
      {
         gunnerCompartments = "Compartment1";
      };
   };
   class textureSources
   {
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {"\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\M1152M1165_d_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\M1151_GPK_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\mk64mount_s_co.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\lras3_s_co.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_GPK_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa", "rhsusf\addons\rhsusf_stryker\data\rhsusf_lras3_d_co.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Ext_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Tire_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_wd_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_GPK_wd_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_stryker\data\rhsusf_lras3_co.paa"};
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
         disableHeightLimit = 1;
         maxLoadMass = 1500;
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