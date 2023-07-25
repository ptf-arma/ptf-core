class PTF_Aircraft_Spawner : Land_MultiScreenComputer_01_black_F
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
   displayName = "Aircraft Spawner";
   class EventHandlers
   {
      init = "[(_this select 0)] execVM '\PTF_Scripts\fnc\spawners\aircraftSpawner_init.sqf';";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
};
class PTF_Supply_Spawner : PTF_Aircraft_Spawner
{
   displayName = "Supply Spawner";
   class EventHandlers
   {
      init = "[(_this select 0)] remoteExec ['PTF_fnc_supplySpawner_init', 0, true]";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
};
class PTF_Vic_Spawner : PTF_Aircraft_Spawner
{
   displayName = "Vic Spawner";
   class EventHandlers
   {
      init = "[(_this select 0)] execVM '\PTF_Scripts\fnc\spawners\VicSpawner_init.sqf';";
      class CBA_Extended_EventHandlers : CBA_Extended_EventHandlers_base
      {
      };
   };
};