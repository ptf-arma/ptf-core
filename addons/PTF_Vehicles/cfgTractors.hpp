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
// Written bare, with no parent. That is deliberate and it is the correct
// idiom: config classes merge by path, so this adds two properties to Peral's
// existing class and leaves its parent, model, simulation, crew and cargo
// intact. What makes the merge safe is the load-order guarantee -- the
// "Peral_Airfield_Logistics" entry in config.cpp requiredAddons[] -- not any
// inheritance written here.
//
// Do NOT "fix" these into `class X: X`. A class cannot inherit from itself;
// that is a circular reference which Arma dumps to the RPT on every lookup.
// It is what filled a 221 MB log in ninety seconds and hung the game on load.
class Peral_AS32A_35
{
   faction = "BLU_F";
   side = 1;
};
class Peral_Helidolly_14x14
{
   faction = "BLU_F";
   side = 1;
};
class Peral_Helidolly_16x16
{
   faction = "BLU_F";
   side = 1;
};
// Peral Airfield Logistics
