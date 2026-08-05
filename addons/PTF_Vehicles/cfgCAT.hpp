class PTF_M1151CAT_M2 : rhsusf_m1151_m2_v3_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   maximumLoad = 750;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1151 (M2) [CAT]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};
   // PTF_fnc_slingloading mass override: [mass under CH-53, mass under MV-22]
   SlingloadingWeight = "[2900,2800]";
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
         magazines[] = {
            "rhs_mag_200rnd_127x99_SLAP_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_SLAP_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_SLAP_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_SLAP_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_mag_Tracer_red",
            "rhs_mag_200rnd_127x99_mag_Tracer_red",
            };
      };
      class CoDriverTurret : CoDriverTurret
      {
         gunnerCompartments = "Compartment1";
      };
   };
        class TransportBackpacks
                {
                };
         class TransportMagazines {
            class _xx_rhsusf_100Rnd_762x51_m80a1epr {
                magazine="rhsusf_100Rnd_762x51_m80a1epr";
                count = 5;
            };
            class _xx_rhsusf_200Rnd_556x45_box {
                magazine="rhsusf_200Rnd_556x45_box";
                count = 5;
            };
            class _xx_PTF_Mag_556x45_Mk262_PMAG_Mix{
                magazine="PTF_Mag_556x45_Mk262_PMAG_Mix";
                count = 20;
            };
            class _xx_rhs_mag_an_m8hc {
                magazine="rhs_mag_an_m8hc";
                count = 5;
            };
            class _xx_SmokeShellBlue {
                magazine="SmokeShellBlue";
                count = 5;
            };
            class _xx_rhs_mag_m67 {
                magazine="rhs_mag_m67";
                count = 5;
            };
            class _xx_rhs_fim92_mag {
                magazine="rhs_fim92_mag";
                count = 2;
            };
            class _xx_rhs_fgm148_magazine_AT {
                magazine="rhs_fgm148_magazine_AT";
                count = 1;
            };
		};
		class TransportItems{
            class _xx_ACE_elasticBandage {
                name="ACE_elasticBandage";
                count = 20;
            };
            class _xx_ACE_plasmaIV {
                name="ACE_plasmaIV";
                count = 3;
            };
            class _xx_ACE_splint {
                name="ACE_splint";
                count = 4;
            };
            class _xx_ACE_tourniquet {
                name="ACE_tourniquet";
                count = 4;
            };
            class _xx_rhsusf_ANPVS_15 {
                name="rhsusf_ANPVS_15";
                count = 2;
            };
            class _xx_ACE_wirecutter {
                name="ACE_wirecutter";
                count = 2;
            };
            class _xx_ToolKit {
                name="ToolKit";
                count = 1;
            };
            class _xx_ACE_vmm3 {
                name="ACE_vmm3";
                count = 2;
            };
            class _xx_ACE_Clacker {
                name="ACE_Clacker";
                count = 2;
            };
            class _xx_ACE_DefusalKit {
                name="ACE_DefusalKit";
                count = 2;
            };
            class _xx_ACE_EarPlugs {
                name="ACE_EarPlugs";
                count = 5;
            };
		};
		class TransportWeapons
		{
            class _xx_rhs_weap_M136_hp {
                weapon="rhs_weap_M136_hp";
                count = 1;
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
         hiddenselectionstextures[] = {
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
};
class PTF_M1151CAT_MK19 : rhsusf_m1151_mk19_v3_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   maximumLoad = 750;
   side = 1;
   // PTF_fnc_slingloading mass override: [mass under CH-53, mass under MV-22]
   SlingloadingWeight = "[2900,2800]";
   author = "Paramarine Task Force";
   displayName = "M1151 (Mk19) [CAT]";
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
         magazines[] = {
        "RHS_96Rnd_40mm_MK19_M1001",
        "RHS_96Rnd_40mm_MK19_M1001",
        "RHS_96Rnd_40mm_MK19",
        "RHS_96Rnd_40mm_MK19",
        "RHS_96Rnd_40mm_MK19_M430A1",
        "RHS_96Rnd_40mm_MK19_M430A1",
        "RHS_96Rnd_40mm_MK19_M430A1",
        "RHS_96Rnd_40mm_MK19_M430A1",
        "RHS_96Rnd_40mm_MK19_M430A1"
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
         textures[] = {
             "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\m1151_Tire_s_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Int_CO.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1151_Acc_d_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_d_co.paa", "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_d_co.paa", "rhsusf\addons\rhsusf_m11xx\data\rhsusf_M1152M1165_d_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "\z\PTF\addons\PTF_Textures\vehicles\m115x\mk64mount_s_co.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         hiddenselectionstextures[] = {
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
   class TransportBackpacks
                {
                };
            class TransportMagazines {
            class _xx_rhsusf_100Rnd_762x51_m80a1epr {
                magazine="rhsusf_100Rnd_762x51_m80a1epr";
                count = 5;
            };
            class _xx_rhsusf_200Rnd_556x45_box {
                magazine="rhsusf_200Rnd_556x45_box";
                count = 5;
            };
            class _xx_PTF_Mag_556x45_Mk262_PMAG_Mix{
                magazine="PTF_Mag_556x45_Mk262_PMAG_Mix";
                count = 20;
            };
            class _xx_rhs_mag_an_m8hc {
                magazine="rhs_mag_an_m8hc";
                count = 5;
            };
            class _xx_SmokeShellBlue {
                magazine="SmokeShellBlue";
                count = 5;
            };
            class _xx_rhs_mag_m67 {
                magazine="rhs_mag_m67";
                count = 5;
            };
            class _xx_rhs_fim92_mag {
                magazine="rhs_fim92_mag";
                count = 2;
            };
            class _xx_rhs_fgm148_magazine_AT {
                magazine="rhs_fgm148_magazine_AT";
                count = 1;
            };
		};
		class TransportItems{
            class _xx_ACE_elasticBandage {
                name="ACE_elasticBandage";
                count = 20;
            };
            class _xx_ACE_plasmaIV {
                name="ACE_plasmaIV";
                count = 3;
            };
            class _xx_ACE_splint {
                name="ACE_splint";
                count = 4;
            };
            class _xx_ACE_tourniquet {
                name="ACE_tourniquet";
                count = 4;
            };
            class _xx_rhsusf_ANPVS_15 {
                name="rhsusf_ANPVS_15";
                count = 2;
            };
            class _xx_ACE_wirecutter {
                name="ACE_wirecutter";
                count = 2;
            };
            class _xx_ToolKit {
                name="ToolKit";
                count = 1;
            };
            class _xx_ACE_vmm3 {
                name="ACE_vmm3";
                count = 2;
            };
            class _xx_ACE_Clacker {
                name="ACE_Clacker";
                count = 2;
            };
            class _xx_ACE_DefusalKit {
                name="ACE_DefusalKit";
                count = 2;
            };
            class _xx_ACE_EarPlugs {
                name="ACE_EarPlugs";
                count = 5;
            };
		};
		class TransportWeapons
		{
            class _xx_rhs_weap_M136_hp {
                weapon="rhs_weap_M136_hp";
                count = 1;
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
};
class PTF_M1025_tow : rhsusf_m966_w
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_ArmedCars";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 750;
   side = 1;
   // PTF_fnc_slingloading mass override: [mass under CH-53, mass under MV-22]
   SlingloadingWeight = "[2900,2800]";
   author = "Paramarine Task Force";
   displayName = "M966 (TOW) [CAT]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};
   hiddenSelections[]=
        {
            "exterior",
            "interior",
            "A2",
            "wheels",
            "mainbody",
            "hood gratting",
            "camo1",
            "camo2",
            "unitdecals_1",
            "unitdecals_2",
            "ind_wait",
            "ind_brake",
            "ind_highbeam"
        };
        HiddenSelectionsTextures[]=
        {
            "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\textures\m998_interior_w_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\textures\A2_parts_WD_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\textures\wheel_wranglermt_b_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\textures\m998_mainbody_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\textures\gratting_w_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\textures\m1025_w_co.paa",
            "rhsusf\addons\rhsusf_hmmwv\unitdecals\101stab_502reg_2ndbn_a12_w_co.paa",
            ""
        };


   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class TOW_Turret: TOW_Turret
      {
            magazines[] = {
            "rhs_mag_TOW2A",
            "rhs_mag_TOW2A",
            "rhs_mag_TOW2A",
            "rhs_mag_TOW2A",
            "rhs_mag_TOW2b_aero",
            "rhs_mag_TOW2bb",
            "rhs_mag_TOW2bb",
            "rhs_mag_TOW2bb",
             };
     };
    class CargoTurret_01: CargoTurret_01 {};
	class CargoTurret_02: CargoTurret_02 {};
	class CargoTurret_03: CargoTurret_03 {};
   };
         class TransportBackpacks
                {
                };
         class TransportMagazines {
            class _xx_rhsusf_100Rnd_762x51_m80a1epr {
                magazine="rhsusf_100Rnd_762x51_m80a1epr";
                count = 5;
            };
            class _xx_rhsusf_200Rnd_556x45_box {
                magazine="rhsusf_200Rnd_556x45_box";
                count = 5;
            };
            class _xx_PTF_Mag_556x45_Mk262_PMAG_Mix{
                magazine="PTF_Mag_556x45_Mk262_PMAG_Mix";
                count = 20;
            };
            class _xx_rhs_mag_an_m8hc {
                magazine="rhs_mag_an_m8hc";
                count = 5;
            };
            class _xx_SmokeShellBlue {
                magazine="SmokeShellBlue";
                count = 5;
            };
            class _xx_rhs_mag_m67 {
                magazine="rhs_mag_m67";
                count = 5;
            };
            class _xx_rhs_fim92_mag {
                magazine="rhs_fim92_mag";
                count = 2;
            };
            class _xx_rhs_fgm148_magazine_AT {
                magazine="rhs_fgm148_magazine_AT";
                count = 1;
            };
		};
		class TransportItems{
            class _xx_ACE_elasticBandage {
                name="ACE_elasticBandage";
                count = 20;
            };
            class _xx_ACE_plasmaIV {
                name="ACE_plasmaIV";
                count = 3;
            };
            class _xx_ACE_splint {
                name="ACE_splint";
                count = 4;
            };
            class _xx_ACE_tourniquet {
                name="ACE_tourniquet";
                count = 4;
            };
            class _xx_rhsusf_ANPVS_15 {
                name="rhsusf_ANPVS_15";
                count = 2;
            };
            class _xx_ACE_wirecutter {
                name="ACE_wirecutter";
                count = 2;
            };
            class _xx_ToolKit {
                name="ToolKit";
                count = 1;
            };
            class _xx_ACE_vmm3 {
                name="ACE_vmm3";
                count = 2;
            };
            class _xx_ACE_Clacker {
                name="ACE_Clacker";
                count = 2;
            };
            class _xx_ACE_DefusalKit {
                name="ACE_DefusalKit";
                count = 2;
            };
            class _xx_ACE_EarPlugs {
                name="ACE_EarPlugs";
                count = 5;
            };
		};
		class TransportWeapons
		{
            class _xx_rhs_weap_M136_hp {
                weapon="rhs_weap_M136_hp";
                count = 1;
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
};
