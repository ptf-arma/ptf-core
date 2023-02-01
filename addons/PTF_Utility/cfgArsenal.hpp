class PTF_Standard_Arsenal : Box_NATO_Equip_F
{
   scope = 2;
   side = 8;
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canload = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 0;
   faction = "BLU_F";
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Arsenal";
   author = "Paramarine Task Force";
   displayname = "Standard Arsenal [PTF]";
   hiddenselections[] = {
       "camo",
       "camo_signs"};
   hiddenselectionstextures[] = {
       "PTF_textures\objects\arsenal\equipment_box_blufor_co.paa",
       "PTF_textures\objects\arsenal\equipment_box_blufor_ca.paa"};

   class EventHandlers
   {
      init = "[(_this select 0)] execVM '\PTF_Scripts\fnc\arsenal\arsenal_init.sqf';";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };

   class Transportitems : Transportitems
   {
   };
   class Transportbackpacks : Transportbackpacks
   {
   };
   class Transportmagazines : Transportmagazines
   {
   };
   class Transportweapons : Transportweapons
   {
   };
};
class PTF_Standard_Arsenal_No_Ammo : Box_NATO_Equip_F
{
   scope = 2;
   side = 8;
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canload = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_candrag = 0;
   faction = "BLU_F";
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Arsenal";
   author = "Paramarine Task Force";
   displayname = "Standard Arsenal (No ammo) [PTF]";
   hiddenselections[] = {
       "camo",
       "camo_signs"};
   hiddenselectionstextures[] = {
       "PTF_textures\objects\arsenal\equipment_box_blufor_co.paa",
       "PTF_textures\objects\arsenal\equipment_box_blufor_ca.paa"};

   class EventHandlers
   {
      init = "[(_this select 0)] execVM '\PTF_Scripts\fnc\arsenal\arsenalnoammo_init.sqf';";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };

   class Transportitems : Transportitems
   {
   };
   class Transportbackpacks : Transportbackpacks
   {
   };
   class Transportmagazines : Transportmagazines
   {
   };
   class Transportweapons : Transportweapons
   {
   };
};