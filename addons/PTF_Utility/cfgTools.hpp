class PTF_Tools_Toolbox : boxloader_tool_cart
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
   displayName = "Toolbox";
};
class PTF_Tools_PalletJack : boxloader_pallet_jack
{
   scope = 2;
   side = 1;
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
   displayName = "Pallet Jack";
   class VehicleTransport
   {
      class Cargo
      {
         dimensions[] = {"VTV_Cargo_Base", "VTV_Cargo_Corner"};
         parachuteClass = "B_Parachute_02_F";
         canBeTransported = 1;
         parachuteHeightLimit = 10;
      };
      class Carrier
      {
         cargoBayDimensions[] = {"VTV_Carrier_Base", "VTV_Carrier_Corner"};
         cargoSpacing[] = {0, 0, 0};
         cargoAlignment[] = {"front", "center"};
         maxLoadMass = 4000;
         disableHeightLimit = 1;
         exits[] = {"VTV_exit_1"};
         unloadingInterval = 2;
         loadingDistance = 0;
         loadingAngle = 0;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 10000;
      };
   };
};
