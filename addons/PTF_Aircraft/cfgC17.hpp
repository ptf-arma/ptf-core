class PTF_C17 : USAF_C17
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   driverCanSee = 31;
   gunnerCanSee = 31;
   faction = "BLU_F";
   side = 1;
   crew = "B_Pilot_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 1000;
   author = "Paramarine Task Force";
   displayName = "C-17 [MAG36]";
   cargoCompartments[] = {"Compartment2"};

   hiddenSelections[] = {"c17-1", "c17-2", "c17-3", "c17-5", "c17-6", "c17-7_t", "c17-8", "eng_t", "lwng", "rwng", "tail", "hourformat1", "hourformat2", "minformat1", "minformat2", "secformat1", "secformat2", "n_gear", "l_gear_1", "l_gear_2", "r_gear_1", "r_gear_2"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\C17\C17-1_co.paa", "\PTF_Textures\Aircraft\C17\C17-2_co.paa", "\PTF_Textures\Aircraft\C17\C17-3_co.paa", "\PTF_Textures\Aircraft\C17\C17-5_co.paa", "\PTF_Textures\Aircraft\C17\C17-6_co.paa", "\PTF_Textures\Aircraft\C17\C17-7_t_co.paa", "\PTF_Textures\Aircraft\C17\C17-8_co.paa", "\PTF_Textures\Aircraft\C17\C17-eng_co.paa", "\PTF_Textures\Aircraft\C17\Lwng_co.paa", "\PTF_Textures\Aircraft\C17\Rwng_co.paa", "\PTF_Textures\Aircraft\C17\Tail_co.paa"};

   class TextureSources
   {
   };

   class VehicleTransport
   {
      class Carrier
      {
         cargoBayDimensions[] = {"VIV_point_1", "VIV_point_2"};
         disableHeightLimit = 1;
         maxLoadMass = 137250;
         cargoAlignment[] = {"front", "center"};
         cargoSpacing[] = {0, 0, 0};
         exits[] = {"VIV_exit"};
         unloadingInterval = 2;
         loadingDistance = 20;
         loadingAngle = 60;
         parachuteClassDefault = "B_Parachute_02_F";
         parachuteHeightLimitDefault = 5;
      };
      class Cargo
      {
         canBeTransported = 0;
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