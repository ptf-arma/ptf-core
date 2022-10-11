class PTF_KC135 : usaf_kc135
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
   faction = "BLU_F";
   side = 1;
   crew = "B_Pilot_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 1000;
   author = "Paramarine Task Force";
   displayName = "KC-135 [MAG36]";

   hiddenSelections[] = {"135_F5", "135_Fuse1_4", "135_lt_wing_bottom", "135_lt_wing_top", "135_rt_wing_bottom", "135_rt_wing_top", "belly_panels", "CFM_N1engine", "CFM_N2engine", "CFM_N3engine", "CFM_N4engine", "H_Stab", "inbd_pylons", "inlet", "outbd_pylons", "tail_left", "tail_right", "w_frame"};
   hiddenSelectionsTextures[] = {"USAF_KC135\txt\135_F5.paa", "USAF_KC135\txt\135_Fuse1-4.paa", "USAF_KC135\txt\135_lt_wing_bottom.paa", "USAF_KC135\txt\135_lt_wing_top.paa", "USAF_KC135\txt\135_rt_wing_bottom.paa", "USAF_KC135\txt\135_rt_wing_top.paa", "USAF_KC135\txt\belly_panels.paa", "USAF_KC135\txt\CFM_#1engine.paa", "USAF_KC135\txt\CFM_#2engine.paa", "USAF_KC135\txt\CFM_#3engine.paa", "USAF_KC135\txt\CFM_#4engine.paa", "USAF_KC135\txt\H_Stab.paa", "USAF_KC135\txt\inbd_pylons.paa", "USAF_KC135\txt\inlet.paa", "USAF_KC135\txt\outbd_pylons.paa", "USAF_KC135\txt\tail_left.paa", "USAF_KC135\txt\tail_right.paa", "USAF_KC135\txt\w_frame.paa"};

   class TextureSources
   {
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