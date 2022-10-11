//M977A4s
class PTF_M977A4_M2 : rhsusf_M977A4_REPAIR_BKIT_M2_usarmy_wd
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Utility";
   ace_cargo_space = 20;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   ace_repair_canRepair = 0;
   maximumLoad = 10000;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "M977A4 (M2/Cargo) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   HiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\BKIT_CO.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CARGO_CO.paa","rhsusf\addons\rhsusf_rg33l\data\rg33_turretwd_co.paa","rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa","rhsusf\addons\rhsusf_hmmwv\textures\mk64mount_w_co.paa","rhsusf\addons\rhsusf_rg33l\Data\rhsusf_camonet_wdl_co.paa"};

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
class PTF_M977A4_Refuel : rhsusf_M978A4_usarmy_wd
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
   transportFuel = 22000;
   author = "Paramarine Task Force";
   displayName = "M977A4 (Refuel) [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {
       "Camo", "Camo3", "Camo5"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO_Des.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_DES_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_DES_CO.paa"};
      };
      factions[] = {};
   };
   class VehicleTransport
   {
      class Cargo
      {
         dimensions[] = {};
         parachuteClass = "B_Parachute_02_F";
         canBeTransported = 0;
         parachuteHeightLimit = 15;
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
class PTF_M977A4_Repair : rhsusf_M977A4_REPAIR_usarmy_wd
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
   displayName = "M977A4 (Repair) [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {
       "Camo", "Camo3", "Camo5"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CARGO_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO_Des.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_DES_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_DES_CO.paa"};
      };
      factions[] = {};
   };
   class VehicleTransport
   {
      class Cargo
      {
         dimensions[] = {};
         parachuteClass = "B_Parachute_02_F";
         canBeTransported = 0;
         parachuteHeightLimit = 15;
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
class PTF_M977A4_Ammo : rhsusf_M977A4_AMMO_usarmy_wd
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
   displayName = "M977A4 (Ammo) [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {
       "Camo", "Camo3", "Camo5"};
   hiddenSelectionsTextures[] = {
       "rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CARGO_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_CO.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {
             "rhsusf\addons\rhsusf_hemtt_a4\data\CAB_CO_Des.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\FUEL_DES_CO.paa", "rhsusf\addons\rhsusf_hemtt_a4\data\CHASSIS_DES_CO.paa"};
      };
      factions[] = {};
   };
   class VehicleTransport
   {
      class Cargo
      {
         dimensions[] = {};
         parachuteClass = "B_Parachute_02_F";
         canBeTransported = 0;
         parachuteHeightLimit = 15;
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