class PTF_Cargo_Small : Boxloader_SmallPallet_Ammo
{
   scope = 2;
   side = 8;
   armor = 500;
   epeImpulseDamageCoef = 100;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 5;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 1;
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayname = "Small - Empty";
   hiddenselections[] = {
       "camo",
       "camo_signs"};
   hiddenselectionstextures[] = {
       "PTF_Utility\data\cargo\PTF_Cargo_Small_ammo\Boxloader_SmallPallet_ammo_co.paa",
       "PTF_Cargo\Data\PTF_Cargo_Small_ammo\Boxloader_SmallPallet_ammo_ca.paa"};
   class vehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {
             "BBox_Base", "BBox_Corner"};
      };
   };
   class Transportmagazines{};
   class Transportweapons{};
   class Transportitems{};
};

class PTF_Cargo_Small_Humanitarian : PTF_Cargo_Small
{
   displayname = "Small - Humanitarian";
   class Transportitems
   {
      item_xx(ACE_Banana, 30);
      item_xx(ACE_Can_Franta, 30);
      item_xx(ACE_Can_RedGull, 30);
      item_xx(ACE_Can_Spirit, 30);
      item_xx(ACE_Canteen, 30);
      item_xx(ACE_Humanitarian_Ration, 100);
      item_xx(ACE_WaterBottle, 100);
   };
};

class PTF_Cargo_Mortar : PTF_Cargo_Small
{
   displayname = "Small - Mortar";
   class TransportMagazines
   {
      mag_xx(NDS_M_6Rnd_60mm_HE   , 4);
      mag_xx(avm224_M_6Rnd_60mm_SMOKE_csw, 4);
      mag_xx(NDS_M_6Rnd_60mm_HE_0, 2);
      mag_xx(avm224_M_6Rnd_60mm_ILLUM_IR_csw, 24);
      mag_xx(avm224_M_6Rnd_60mm_ILLUM_csw, 4);
   };
};

class PTF_Cargo_Vic : PTF_Cargo_Small
{
   ace_cargo_space = 40;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 5;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 1;
   displayname = "Small - Vic Box";
   class EventHandlers
   {
      init = "[(_this select 0)] remoteExec ['PTF_fnc_SmallVicBox_init', 0, true]";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
};

class PTF_Cargo_Tracks : PTF_Cargo_Small
{
   ace_cargo_space = 40;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 5;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 1;
   displayname = "Track Box";
   class EventHandlers
   {
      init = "[(_this select 0)] remoteExec ['PTF_fnc_Tracks_init', 0, true]";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
};

class PTF_Cargo_Ammo : NATO_Box_Base
{
   scope = 2;
   side = 8;
   armor = 500;
   epeImpulseDamageCoef = 100;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 2;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 1;
   ace_dragging_candrag = 1;
   maximumLoad = 375;
   model = "\A3\weapons_F\ammoBoxes\ammoBox_F";
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayname = "Ammo Box";

   hiddenselections[] = {
       "Camo_Signs ",
       "Camo"};
   hiddenselectionstextures[] = {
       "A3\weapons_F\ammoboxes\data\ammoBox_signs_CA.paa",
       "A3\weapons_F\ammoboxes\data\ammoBox_CO.paa"};

   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {
             "BBox_Base", "BBox_Corner"};
      };
   };

   class TransportMagazines{};
   class TransportWeapons{};
   class TransportItems {};
   class TransportBackpacks{};
};
class PTF_Cargo_Small_Repair : PTF_Cargo_Small
{
   displayname = "Small - Repair";
   class VehicleTransport
      {
         class Cargo
         {
            parachuteClass = "B_Parachute_02_F";
            parachuteHeightLimit = 40;
            canBeTransported = 1;
            dimensions[] = {"BBox_Base0","BBox_Corner_1m"};
         };
         class Carrier{};
      };
   model = "\boxloader\mdl\boxloader_crate1.p3d";
   supplyRadius = 10;
   transportRepair = 200000000;
};
class PTF_Cargo_Small_Rearm : PTF_Cargo_Small
{
   displayname = "Small - Rearm";
   supplyRadius = 10;
   transportAmmo = 200000000;
};
class PTF_Cargo_Tiny_Ammo : Land_Ammobox_rounds_F
{
   scope = 2;
   side = 8;
   armor = 500;
   epeImpulseDamageCoef = 100;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 2;
   ace_cargo_canload = 1;
   ace_dragging_canCarry = 1;
   ace_dragging_candrag = 1;
   maximumLoad = 133;
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Cargo";
   author = "Paramarine Task Force";
   displayname = "Tiny Ammo Box";

   class TransportMagazines
   {
   };
   class TransportWeapons
   {
   };
   class TransportItems
   {
   };
   class TransportBackpacks
   {
   };
};
