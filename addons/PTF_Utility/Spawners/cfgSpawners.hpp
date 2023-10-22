
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

class ACE_Actions {
   class ACE_MainActions {
      displayName = "Spawn Vehicles";
      selection = "";
      distance = 1.5;
      condition = "true";

      #include "\PTF_Scripts\fnc\spawners\Planes.hpp"
      #include "\PTF_Scripts\fnc\spawners\HelicoptersTransport.hpp"
      #include "\PTF_Scripts\fnc\spawners\HelicoptersSupply.hpp"
      #include "\PTF_Scripts\fnc\spawners\HelicoptersAttack.hpp"
      #include "\PTF_Scripts\fnc\spawners\Vics.hpp"
      #include "\PTF_Scripts\fnc\spawners\Supplys.hpp"
      
      };
   };
};