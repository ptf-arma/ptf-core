//Forklifts
class PTF_Atlas : boxloader_atlas
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
   displayName = "Atlas Forklift [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"Camo"};
   hiddenSelectionsTextures[] =
       {"#(rgb,8,8,3)color(0.2,0.235,0.184,1,co)"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] =
             {"#(rgb,8,8,3)color(0.2,0.235,0.184,1,co)"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] =
             {"#(rgb,8,8,3)color(0.498,0.4313,0.352,1,co)"};
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
         cargoBayDimensions[] = {"VTV_Carrier_Base", "VTV_Carrier_Corner"};
         cargoSpacing[] = {0, 0, 0};
         cargoAlignment[] = {"back", "center"};
         maxLoadMass = 12000;
         disableHeightLimit = 1;
         exits[] = {"VTV_exit_1"};
         unloadingInterval = 2;
         loadingDistance = 10;
         loadingAngle = 60;
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
class PTF_Kalmar : boxloader_kalmar
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
   displayName = "Kalmar Forklift [MAG36]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"Camo"};
   hiddenSelectionsTextures[] =
       {"#(rgb,8,8,3)color(0.498,0.4313,0.352,1,co)"};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] =
             {"#(rgb,8,8,3)color(0.2,0.235,0.184,1,co)"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] =
             {"#(rgb,8,8,3)color(0.498,0.4313,0.352,1,co)"};
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
         cargoBayDimensions[] = {"VTV_Carrier_Base", "VTV_Carrier_Corner"};
         cargoSpacing[] = {0, 0, 0};
         cargoAlignment[] = {"back", "center"};
         maxLoadMass = 8000;
         disableHeightLimit = 1;
         exits[] = {"VTV_exit_1"};
         unloadingInterval = 2;
         loadingDistance = 10;
         loadingAngle = 60;
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
