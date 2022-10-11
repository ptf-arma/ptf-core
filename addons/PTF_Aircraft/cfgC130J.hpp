//C-130J
class PTF_C130J : USAF_C130J
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   driverCanSee = 31;
   gunnerCanSee = 31;
   side = 1;
   crew = "B_Pilot_F";
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 400;
   author = "Paramarine Task Force";
   displayName = "C-130J [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment2"};

   hiddenSelections[] = {"camo1", "camo2", "Decal"};
   hiddenSelectionsTextures[] = {"USAF_C130J\data\tex\c130j_body_co.paa", "USAF_C130J\data\tex\c130j_wings_co.paa", ""};

   class TextureSources
   {
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
class PTF_C130J_Cargo : USAF_C130J_Cargo
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   side = 1;
   crew = "B_Pilot_F";
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 400;
   author = "Paramarine Task Force";
   displayName = "C-130J Cargo [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment2"};

   hiddenSelections[] = {"camo1", "camo2", "Decal"};
   hiddenSelectionsTextures[] = {"USAF_C130J\data\tex\c130j_body_co.paa", "USAF_C130J\data\tex\c130j_wings_co.paa", ""};

   class TextureSources
   {
   };

   class VehicleTransport
   {
      class Carrier
      {
         cargoBayDimensions[] = {"VIV_point_1", "VIV_point_2"};
         disableHeightLimit = 1;
         maxLoadMass = 35900;
         cargoAlignment[] = {"front", "center"};
         cargoSpacing[] = {0, 0, 0};
         exits[] = {"VIV_exit"};
         unloadingInterval = 2;
         loadingDistance = 20;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 5;
      };
      class Cargo
      {
         canBeTransported = 0;
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