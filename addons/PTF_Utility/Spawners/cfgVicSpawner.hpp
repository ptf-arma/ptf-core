class PTF_Vic_Spawner : Land_MultiScreenComputer_01_black_F
{
   scope = 2;
   side = 8;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   editorCategory = "PTF_Empty";
   editorSubcategory = "PTF_Tools";
   author = "Paramarine Task Force";
   displayName = "Vic Spawner";

   class EventHandlers
   {
      init = "[(_this select 0)] execVM '\PTF_Scripts\fnc\spawners\VicSpawner_init.sqf';";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
   
   class TransportMagazines
   {
   };
   class TransportWeapons
   {
   };
   class TransportItems
   {
   };
};