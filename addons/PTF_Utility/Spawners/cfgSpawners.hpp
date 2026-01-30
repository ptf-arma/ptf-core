
class PTF_Spawner : Land_MultiScreenComputer_01_black_F {
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
   displayName = "Spawner";
   #include "EdenAttributes.hpp"
class ACE_Actions {
   class ACE_MainActions {
      displayName = "Spawn Vehicles";
      selection = "";
      distance = 1.5;
      condition = "true";

      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\Planes.hpp"
      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\HelicoptersTransport.hpp"
      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\HelicoptersSupply.hpp"
      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\HelicoptersAttack.hpp"
      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\Boat.hpp"
      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\Cougar.hpp"
      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\ForkLift.hpp"
      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\Mrap.hpp"
      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\Hummve.hpp"
      #include "\z\PTF\addons\PTF_Scripts\fnc\spawners\Supplys.hpp"
      };
   };
};
class PTF_Salvage : Land_MultiScreenComputer_01_black_F {
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
   displayName = "Salvage Computer";
   class ACE_Actions {
      class ACE_MainActions {
         displayName = "Salvage Vehicles";
         selection = "";
         distance = 1.5;
         condition = "true";
         class PTF_Salavge {
            statement = "[_target] call PTF_fnc_Salvage";
            displayName = "Salvage Aircraft";
            icon = "a3\ui_f\data\igui\cfg\actions\repair_ca.paa";
         };
      };
   };
};
