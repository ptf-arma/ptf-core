class PTF_Cargo_Industrial_Static_Cargo : B_Slingload_01_Cargo_F
{
   scope = 2;
   side = 8;
   faction = "BLU_F";
   PTF_ACE_NO_CARGO
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Industrial";
   author = "Paramarine Task Force";
   displayName = "Static - Cargo";
   hiddenSelections[] = {
       "camo",
       "camo_signs"};
   hiddenSelectionsTextures[] = {
       ""};
   class VehicleTransport
   {
      class Cargo
      {
         dimensions[] = {"VTV_Cargo_Base", "VTV_Cargo_Corner"};
         parachuteClass = "B_Parachute_02_F";
         canBeTransported = 1;
         parachuteHeightLimit = 15;
      };
   };
   class TransportMagazines{};
   class TransportWeapons{};
   class TransportItems{};
};

class PTF_Buiding_RepairDepot : Land_RepairDepot_01_green_F
{
   scope = 2;
   side = 8;
   faction = "BLU_F";
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Fortifications";
   author = "Paramarine Task Force";
   displayName = "Repair Depot";
   vehicleClass = "Structures_Infrastructure";
};
