class PTF_LAV25B : CUP_B_LAV25M240_USMC
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Armor";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 1500;
   side = 1;
   maxSpeed = 20;
   fuelCapacity = 10;
   model = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\cup_lav25m240.p3d";
   author = "Paramarine Task Force";
   displayName = "LAV-25B [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"Camo1","Camo2","Camo3","camoAlfa"};
   hiddenSelectionsTextures[] =
       {"\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody2_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lav_hq_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavalfa_ca.paa"};

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
class PTF_LAV25B_CMD : CUP_B_LAV25_USMC
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Armor";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 1500;
   side = 1;
   maxSpeed = 20;
   fuelCapacity = 10;
   model = "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\CUP_LAV25.p3d";
   author = "Paramarine Task Force";
   displayName = "LAV-25B Command [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"Camo1","Camo2","Camo3","camoAlfa"};
   hiddenSelectionsTextures[] =
       {"\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavbody2_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lav_hq_co.paa", "\cup\wheeledvehicles\cup_wheeledvehicles_lav25\data\lavalfa_ca.paa"};

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