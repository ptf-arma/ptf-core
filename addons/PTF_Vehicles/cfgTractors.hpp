//Build Tractor
class PTF_Tractor : boxloader_tractor_build
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
   maxSpeed = 20;
   fuelCapacity = 10;
   author = "Paramarine Task Force";
   displayName = "Construction Tractor [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"Camo"};
   hiddenSelectionsTextures[] = {
       "\boxloader_tractor\Data\tractor_2_green_co.paa"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Green
      {
         displayname = "Green";
         author = "J.Downs";
         textures[] = {"\boxloader_tractor\Data\tractor_2_green_co.paa"};
         factions[] = {};
      };
      class Red
      {
         displayname = "Red";
         author = "J.Downs";
         textures[] = {"\boxloader_tractor\Data\tractor_2_co.paa"};
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
         parachuteHeightLimit = 15;
      };
      class Carrier
      {
         cargoBayDimensions[] = {"VTV_Carrier_Base_Bucket", "VTV_Carrier_Corner_Bucket"};
         cargoSpacing[] = {0, 0, 0};
         cargoAlignment[] = {"back", "left"};
         maxLoadMass = 1002;
         disableHeightLimit = 1;
         exits[] = {"VTV_exit_1"};
         unloadingInterval = 2;
         loadingDistance = 0;
         loadingAngle = 0;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 10;
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
//Towing Tractor

// Include Peral Airfield Logistics in Zeus menu.
//
// These MUST inherit from themselves (`class X: X`) with a matching forward
// declaration in cfgIMPORT.hpp. Written bare (`class X { ... }`) they are not
// edits to Peral's classes -- they are brand-new parentless root classes that
// erase the whole inheritance chain: model, simulation, crew, cargo and
// CBA_Extended_EventHandlers all vanish. That produced thousands of
// "'/' is not a value" and "No entry ....scope/.transportAmmo" warnings per
// session and cost these vehicles XEH support.
class Peral_AS32A_35: Peral_AS32A_35
{
   faction = "BLU_F";
   side = 1;
};
class Peral_Helidolly_14x14: Peral_Helidolly_14x14
{
   faction = "BLU_F";
   side = 1;
};
class Peral_Helidolly_16x16: Peral_Helidolly_16x16
{
   faction = "BLU_F";
   side = 1;
};
// Peral Airfield Logistics
