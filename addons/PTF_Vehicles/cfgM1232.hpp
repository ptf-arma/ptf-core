class PTF_MRAP_M1232_M2 : rhsusf_M1232_MC_M2_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_MRAP";
   ace_cargo_space = 15;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 1500;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1232 (M2) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "pintle", "camo7", "camo8", "camo9"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_RG33L\data\RG33_Body_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_TurretWD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_WD_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_RG33L\data\MCTAGS_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa", "rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class M2_Turret : M2_Turret
      {
         gunnerCompartments = "Compartment1";
         weapons[] = {"RHS_M2"};
         magazines[] = {"rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red", "rhs_mag_100rnd_127x99_mag_Tracer_Red"};
         gunnerAction = "RHS_MCTAGS_Gunner03";
         gunnerInAction = "RHS_MCTAGS_Gunner03_in";
      };
      class CargoTurret_01 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoTurret_02 : CargoTurret_02
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoTurret_03 : CargoTurret_03
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoTurret_04 : CargoTurret_04
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
         textures[] = {"PTF_Textures\vehicles\m1232\RG33_Body_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Chassis_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Accessory2_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Armor_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Turret_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Wheels_s_CO.paa", "PTF_Textures\vehicles\m115x\mk64mount_s_co.paa", "PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "PTF_Textures\vehicles\m1232\camonet_s_co.paa", "rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_TurretD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa", "rhsusf\addons\rhsusf_RG33L\data\MCTAGS_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa", "rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_TurretWD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_WD_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_RG33L\data\MCTAGS_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa", "rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
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
class PTF_MRAP_M1232_MK19 : rhsusf_M1232_MC_MK19_usmc_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_MRAP";
   ace_cargo_space = 15;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 1500;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M1232 (Mk19) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1", "camo2", "camo3", "camo4", "camo5", "pintle", "camo7", "camo8", "camo9"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_RG33L\data\RG33_Body_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_TurretWD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_WD_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_RG33L\data\MCTAGS_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa", "rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class M2_Turret : M2_Turret
      {
         gunnerCompartments = "Compartment1";
         weapons[] = {"RHS_MK19"};
         magazines[] = {"RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M430A1", "RHS_48Rnd_40mm_MK19_M1001", "RHS_48Rnd_40mm_MK19_M1001", "RHS_48Rnd_40mm_MK19_M1001"};
         gunnerAction = "RHS_MCTAGS_Gunner03";
         gunnerInAction = "RHS_MCTAGS_Gunner03_in";
      };
      class CargoTurret_01 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoTurret_02 : CargoTurret_02
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoTurret_03 : CargoTurret_03
      {
         gunnerCompartments = "Compartment1";
      };
      class CargoTurret_04 : CargoTurret_04
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
         textures[] = {"PTF_Textures\vehicles\m1232\RG33_Body_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Chassis_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Accessory2_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Armor_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Turret_s_CO.paa", "PTF_Textures\vehicles\m1232\RG33_Wheels_s_CO.paa", "PTF_Textures\vehicles\m115x\mk64mount_s_co.paa", "PTF_Textures\vehicles\m115x\MCTAGS_s_CO.paa", "PTF_Textures\vehicles\m1232\camonet_s_co.paa", "rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_TurretD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_d_co.paa", "rhsusf\addons\rhsusf_RG33L\data\MCTAGS_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_des_co.paa", "rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {"rhsusf\addons\rhsusf_RG33L\data\RG33_Body_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Chassis_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Accessory2_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Armor_WD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_TurretWD_CO.paa", "rhsusf\addons\rhsusf_RG33L\data\RG33_Wheels_WD_CO.paa", "rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa", "rhsusf\addons\rhsusf_RG33L\data\MCTAGS_WD_CO.paa", "rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa", "rhsusf\addons\rhsusf_RG33L\Decals\RG33_USMC_Decal_ca.paa"};
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