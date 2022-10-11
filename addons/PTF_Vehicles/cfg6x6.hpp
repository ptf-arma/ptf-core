class PTF_Quadbike_6x6 : NDS_6x6_ATV_MIL
{
   scope = 2;
   faction = "BLU_F";
   editorCategory = "PTF";
   editorSubcategory = "PTF_Utility";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   maximumLoad = 375;
   side = 1;
   author = "Paramarine Task Force";
   displayName = "6x6 Quad Bike [PTF]";
   driverCompartments = "Compartment1";
   cargoCompartments[] = {"Compartment1"};

   hiddenSelections[] = {"camo1", "camo2", "camnetpattern", "camnetpatternr", "pouches", "backpack", "load"};
   hiddenSelectionsTextures[] = {"NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_body_MIL_CAM_CO.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_cam_wheel_co.paa", "NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_cam_ca.paa", "NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_cam_ca.paa", "\A3\Characters_F\blufor\data\vests_khk_co.paa", "\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_oli_co.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_ACC_CO.paa"};

   class Turrets : Turrets
   {
      gunnerCompartments = "Compartment1";
      class CargoTurret_01 : CargoTurret
      {
         gunnerCompartments = "Compartment1";
         gunnerAction = "NDS_ATV_ffv_stance";
         memoryPointsGetInGunner = "pos_ffv";
         memoryPointsGetInGunnerDir = "pos_ffv_dir";
         gunnerGetInAction = "GetInLow";
         gunnerGetOutAction = "GetOutLow";
         getInRadius = 0.1;
         gunnerName = "Fire Position";
         isPersonTurret = 1;
         canHideGunner = 0;
         allowLauncherIn = 1;
         allowLauncherOut = 1;
         showAsCargo = 0;
         dontCreateAI = 1;
         hasGunner = 0;
         ejectDeadGunner = 1;
         canEject = 1;
         maxTurn = 75;
      };
   };
   class textureSources
   {
      class Snow
      {
         displayname = "Snow";
         author = "J.Downs";
         textures[] = {"NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_body_MIL_SNO_CO.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_sno_wheel_co.paa", "NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_sno_ca.paa", "NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_sno_ca.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_pouches_sno_co.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_backpack_lge_sno_co.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_ACC_SNO_CO.paa"};
         factions[] = {};
      };
      class Desert
      {
         displayname = "Desert";
         author = "J.Downs";
         textures[] = {"NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_body_MIL_DES_CO.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_des_wheel_co.paa", "NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_des_ca.paa", "NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_des_ca.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_pouches_des_co.paa", "\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_cbr_co.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_ACC_CO.paa"};
         factions[] = {};
      };
      class Woodland
      {
         displayname = "Woodland";
         author = "J.Downs";
         textures[] = {"NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_body_MIL_CAM_CO.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_cam_wheel_co.paa", "NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_cam_ca.paa", "NDS_6x6_ATV\6x6_ATV_camnet\data\NDS_6x6_ATV_camnet_cam_ca.paa", "\A3\Characters_F\blufor\data\vests_rgr_co.paa", "\A3\weapons_f\ammoboxes\bags\data\backpack_tortila_oli_co.paa", "NDS_6x6_ATV\6x6_ATV\data\NDS_6x6_ACC_CO.paa"};
         factions[] = {};
      };
   };
   class VehicleTransport
   {
      class Cargo
      {
         parachuteClass = "B_Parachute_02_F";
         parachuteHeightLimit = 15;
         canBeTransported = 1;
         dimensions[] = {"BBox_1_1_pos", "BBox_1_2_pos"};
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
