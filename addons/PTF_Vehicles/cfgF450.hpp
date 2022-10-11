//F450s
class PTF_F450 : d3s_fseries_LTD_17
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Cars";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "F450 [PTF]";
   crew = "B_Pilot_F";
   maxSpeed = 100;
   enginePower = 350;
   peakTorque = 350;
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] =
       {"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo9", "camo10", "camo11", "camo12", "camo13", "camo14", "camo15", "camo16", "camo17", "camo18", "camo19", "camo20", "license1", "license2", "license3", "license4", "license5", "license6", "license7"};
   hiddenSelectionsTextures[] =
       {"d3s_fseries_15\data\f450.paa", "d3s_fseries_15\data\base.paa", "d3s_cars_core\data\glass_black.paa", "d3s_cars_core\data\glass.paa", "d3s_fseries_15\data\wheel.paa", , "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class S7
      {
         displayname = "S7";
         author = "J.Downs";
         textures[] =
             {"\PTF_Textures\vehicles\f450\f450_s7training.paa", "d3s_fseries_15\data\base.paa", "d3s_fseries_15\data\Window.paa", "d3s_cars_core\data\glass.paa", "d3s_fseries_15\data\wheel.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
         factions[] = {};
      };
      class MAG36
      {
         displayname = "MAG36";
         author = "J.Downs";
         textures[] =
             {"\PTF_Textures\vehicles\f450\f450_airoperations.paa", "d3s_fseries_15\data\base.paa", "d3s_fseries_15\data\Window.paa", "d3s_cars_core\data\glass.paa", "d3s_fseries_15\data\wheel.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
         factions[] = {};
      };
   };
   class VehicleTransport
   {
      class Cargo
      {
         dimensions[] = {};
         parachuteClass = "B_Parachute_02_F";
         canBeTransported = 0;
         parachuteHeightLimit = 10;
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
class PTF_F450_Tow : d3s_fseries_17_TOW
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Utility";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "F450 (Tow) [PTF]";
   crew = "B_Pilot_F";
   maxSpeed = 100;
   enginePower = 350;
   peakTorque = 350;

   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] =
       {"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo9", "camo10", "camo11", "camo12", "camo13", "camo14", "camo15", "camo16", "camo17", "camo18", "camo19", "camo20", "license1", "license2", "license3", "license4", "license5", "license6", "license7"};
   hiddenSelectionsTextures[] =
       {"\PTF_Textures\vehicles\f450\f550_tow.paa", "d3s_fseries_15\data\gmc_6500_base.paa", "d3s_fseries_15\data\Wheel.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class Tow
      {
         displayname = "Tow";
         author = "J.Downs";
         textures[] =
             {"\PTF_Textures\vehicles\f450\f550_tow.paa", "d3s_fseries_15\data\gmc_6500_base.paa", "d3s_fseries_15\data\Wheel.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
         factions[] = {};
      };
   };
   class VehicleTransport
   {
      class Cargo
      {
         dimensions[] = {};
         parachuteClass = "B_Parachute_02_F";
         canBeTransported = 0;
         parachuteHeightLimit = 10;
      };
      class Carrier
      {
         cargoBayDimensions[] =
             {
                 "VTV_limit_1",
                 "VTV_limit_2"};
         disableHeightLimit = 1;
         maxLoadMass = 6500;
         cargoAlignment[] =
             {
                 "front",
                 "center"};
         cargoSpacing[] = {0, 0.15000001, 0};
         exits[] =
             {
                 "VTV_exit_1"};
         unloadingInterval = 2;
         loadingDistance = 10;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 50;
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
class PTF_F450_EMS : d3s_fseries_17_EMS
{
   displayName = "F450 (EMS) [PTF]";
   crew = "B_Pilot_F";
   side = 1;
   scope = 2;
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Utility";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] =
       {"camo1", "camo2", "camo3", "camo4", "camo5", "camo6", "camo7", "camo8", "camo9", "camo10", "camo11", "camo12", "camo13", "camo14", "camo15", "camo16", "camo17", "camo18", "camo19", "camo20", "license1", "license2", "license3", "license4", "license5", "license6", "license7"};
   hiddenSelectionsTextures[] =
       {"PTF_Textures\vehicles\f450\ems\front.paa", "PTF_Textures\vehicles\f450\ems\back.paa", "d3s_fseries_15\data\Wheel.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};

   class Turrets : Turrets
   {
   };
   class textureSources
   {
      class EMS
      {
         displayname = "EMS";
         author = "J.Downs";
         textures[] =
             {"PTF_Textures\vehicles\f450\ems\front.paa", "PTF_Textures\vehicles\f450\ems\back.paa", "d3s_fseries_15\data\Wheel.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
         factions[] = {};
      };
      class Cancer
      {
         displayname = "Cancer Awareness Month";
         author = "J.Downs";
         textures[] =
             {"PTF_Textures\vehicles\f450\ems\fp5.paa", "PTF_Textures\vehicles\f450\ems\bp1.paa", "d3s_fseries_15\data\Wheel.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
         factions[] = {};
      };
   };
   class VehicleTransport
   {
      class Cargo
      {
         dimensions[] = {};
         parachuteClass = "B_Parachute_02_F";
         canBeTransported = 0;
         parachuteHeightLimit = 10;
      };
      class Carrier
      {
         cargoBayDimensions[] =
             {
                 "VTV_limit_1",
                 "VTV_limit_2"};
         disableHeightLimit = 1;
         maxLoadMass = 1000;
         cargoAlignment[] =
             {
                 "front",
                 "center"};
         cargoSpacing[] = {0, 0.15000001, 0};
         exits[] =
             {
                 "VTV_exit_1"};
         unloadingInterval = 2;
         loadingDistance = 10;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 50;
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
