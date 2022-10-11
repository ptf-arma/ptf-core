class PTF_Snowmobile : xs_Snowmobile_combat
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
   maximumLoad = 375;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "Snowmobile [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1"};
   hiddenSelectionsTextures[] = {
       "xakuda_f\xs_snowmobile\data\body_camo.paa", "xakuda_f\xs_snowmobile\data\koja_camo.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CargoTurret_01 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerAction = "passenger_inside_3";
         memoryPointsGetInGunner = "pos cargo";
         memoryPointsGetInGunnerDir = "pos cargo dir";
         gunnerName = "Passenger";
         proxyIndex = 1;
         isPersonTurret = 1;
         class TurnIn
         {
            limitsArrayTop[] = {{24, -88}, {24, -5}};
            limitsArrayBottom[] = {{-44, -88}, {-44, -5}};
         };
      };
      class CargoTurret_02 : CargoTurret_01
      {
         gunnerCompartments = "Compartment1";
         gunnerAction = "passenger_inside_3";
         memoryPointsGetInGunner = "pos cargo";
         memoryPointsGetInGunnerDir = "pos cargo dir";
         gunnerName = "Rear shooter";
         proxyIndex = 2;
         isPersonTurret = 1;
         class TurnIn
         {
            limitsArrayTop[] = {{54, -88}, {54, 98}};
            limitsArrayBottom[] = {{-64, -88}, {-64, 98}};
         };
      };
   };
   class textureSources
   {
      class Snow
      {
         displayName = "Snow";
         author = "J.Downs";
         textures[] = {
             "xakuda_f\xs_snowmobile\data\body_camo.paa", "xakuda_f\xs_snowmobile\data\koja_camo.paa"};
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
class PTF_Snowmobile_Basket : xs_Snowmobile_sport_camo
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
   maximumLoad = 375;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "Snowmobile (Basket) [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo", "camo1"};
   hiddenSelectionsTextures[] = {
       "xakuda_f\xs_snowmobile\data\body_camo.paa", "xakuda_f\xs_snowmobile\data\koja_camo.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CargoTurret_01 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerAction = "passenger_inside_3";
         memoryPointsGetInGunner = "pos cargo";
         memoryPointsGetInGunnerDir = "pos cargo dir";
         gunnerName = "Passenger";
         proxyIndex = 1;
         isPersonTurret = 1;
         class TurnIn
         {
            limitsArrayTop[] = {{24, -88}, {24, -5}};
            limitsArrayBottom[] = {{-44, -88}, {-44, -5}};
         };
      };
   };
   class textureSources
   {
      class Snow
      {
         displayName = "Snow";
         author = "J.Downs";
         textures[] = {
             "xakuda_f\xs_snowmobile\data\body_camo.paa", "xakuda_f\xs_snowmobile\data\koja_camo.paa"};
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