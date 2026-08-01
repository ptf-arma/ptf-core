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
       "\z\PTF\addons\PTF_Textures\objects\arsenal\equipment_box_blufor_co.paa",
       "\z\PTF\addons\PTF_Textures\objects\arsenal\equipment_box_blufor_ca.paa"};
   class EventHandlers
   {
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      init = "[(_this select 0)] remoteExec ['PTF_fnc_arsenal_init', 0, true]";
      };
   };
   class Transportitems : Transportitems{};
   class Transportbackpacks : Transportbackpacks{};
   class Transportmagazines : Transportmagazines{};
   class Transportweapons : Transportweapons{};
};
class PTF_Standard_Arsenal_No_Ammo : PTF_Standard_Arsenal
{
   displayname = "Standard Arsenal (No ammo) [PTF]";
   class EventHandlers
   {
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
       init = "[(_this select 0)] remoteExec ['PTF_fnc_arsenalnoammo_init', 0, true]";
      };
   };
};
class PTF_Pso_Arsenal : PTF_Standard_Arsenal
{
   displayname = "PSO Arsenal [PTF]";
   hiddenselections[] = {
       "camo",
       "camo_signs"};
   hiddenselectionstextures[] = {
       "\z\PTF\addons\PTF_Textures\objects\arsenal\equipment_box_blufor_co.paa",
       "\z\PTF\addons\PTF_Textures\objects\arsenal\PSO_equipment_box_blufor_ca.paa"};
   class EventHandlers
   {
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
       init = "[(_this select 0)] remoteExec ['PTF_fnc_arsenalPSO_init', 0, true]";
      };
   };
};
