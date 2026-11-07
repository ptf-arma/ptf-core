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
      // A config init already runs on every machine, including JIP, so set the box up
      // locally with no network traffic. It sits beside the XEH subclass, not inside it:
      // an init in there replaces CBA's own and stops every XEH handler on this class.
      init = "if (!is3DEN) then {[_this select 0, false] call PTF_fnc_arsenal_init}";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
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
      // A config init already runs on every machine, including JIP, so set the box up
      // locally with no network traffic. It sits beside the XEH subclass, not inside it:
      // an init in there replaces CBA's own and stops every XEH handler on this class.
      init = "if (!is3DEN) then {[_this select 0, false] call PTF_fnc_arsenalnoammo_init}";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
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
      // A config init already runs on every machine, including JIP, so set the box up
      // locally with no network traffic. It sits beside the XEH subclass, not inside it:
      // an init in there replaces CBA's own and stops every XEH handler on this class.
      init = "if (!is3DEN) then {[_this select 0, false] call PTF_fnc_arsenalPSO_init}";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
};
class PTF_Limited_Arsenal : PTF_Standard_Arsenal
{
   displayname = "Limited Arsenal [PTF]";
   class EventHandlers
   {
      // A config init already runs on every machine, including JIP, so set the box up
      // locally with no network traffic. It sits beside the XEH subclass, not inside it:
      // an init in there replaces CBA's own and stops every XEH handler on this class.
      init = "if (!is3DEN) then {[_this select 0, false] call PTF_fnc_arsenalLimited_init}";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
};
