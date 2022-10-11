//MTVR
class PTF_MTVR_Repair : CUP_B_MTVR_Repair_USMC
{
   scope = 2;
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
   crew = "B_Pilot_F";
   vehicleClass = "Support";
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "MTVR (Repair) [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"Camo1", "Camo2", "Camo3", "Camo4"};
   hiddenSelectionsTextures[] = {
       "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\MTVR_interier_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\ural_repair_usmc_co.paa"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] = {
             "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\MTVR_interier_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\ural_repair_usmc_co.paa"};
         decals[] = {};
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
class PTF_MTVR_Ammo : CUP_B_MTVR_Ammo_USMC
{
   scope = 2;
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
   crew = "B_Pilot_F";
   vehicleClass = "Support";
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "MTVR (Ammo) [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"Camo1", "Camo2", "Camo3", "Camo4"};
   hiddenSelectionsTextures[] = {
       "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_interier_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_tarp_co.paa"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] = {
             "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_interier_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_tarp_co.paa"};
         decals[] = {};
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
class PTF_MTVR_Refuel : CUP_B_MTVR_Refuel_USMC
{
   scope = 2;
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
   crew = "B_Pilot_F";
   vehicleClass = "Support";
   faction = "BLU_F";
   transportFuel = 11000;
   author = "Paramarine Task Force";
   displayName = "MTVR (Refuel) [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"Camo1", "Camo2", "Camo3", "Camo4"};
   hiddenSelectionsTextures[] = {
       "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\MTVR_interier_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_fuel_co.paa"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Woodland
      {
         displayName = "Woodland";
         author = "J.Downs";
         textures[] = {
             "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_body2_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\MTVR_interier_co.paa", "CUP\WheeledVehicles\CUP_WheeledVehicles_MTVR\Data\mtvr_fuel_co.paa"};
         decals[] = {};
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
