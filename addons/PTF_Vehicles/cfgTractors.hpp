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

// REMOVED: the Peral Airfield Logistics tractors (Peral_AS32A_35,
// Peral_Helidolly_14x14, Peral_Helidolly_16x16) used to be given
// faction = "BLU_F" and side = 1 here to surface them in the editor.
//
// They never actually showed up, and the attempt was expensive. Those classes
// derive from thingX -- static props. Exposing a prop as placeable makes the
// engine classify it as a land vehicle and query the whole vehicle property
// set on it: soundEngine, fuelCapacity, armor, transportAmmo, PilotSpec and
// about a hundred more that a prop has no reason to define. Measured, per
// session:
//
//   with the edit        370 Peral_* lines, 106 "'/' is not a value"
//   without              2                  15
//
// scopeCurator = 2 instead of side was tried and is no better (378 lines) --
// any mechanism that makes them placeable triggers the same scan.
//
// If these are wanted in the editor, the fix is a real PTF wrapper class that
// inherits from a vehicle base and sets editorCategory/editorSubcategory --
// see PTF_Tractor at the top of this file for the pattern -- not two
// properties merged onto someone else's prop.
