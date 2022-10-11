class PTF_SSO_Backpack_Base : Bag_Base
{
};
class PTF_SSO_Backpack : PTF_SSO_Backpack_Base //Backpack Declaration
{
   _generalMacro = "PTF_SSO_Backpack";
   displayName = "SSO Backpack [PTF]";
   author = "Paramarine Task Force";
   picture = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\Data\UI\icon_B_C_UAV_rgr_ca";
   model = "\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\UAV_backpack_F.p3d";
   hiddenSelectionsTextures[] = {"\A3\Drones_F\Weapons_F_Gamma\Ammoboxes\Bags\Data\UAV_backpack_cbr_co.paa"};
   scope = 2;
   side = 1;
   maximumLoad = 0;
   mass = 100;
   class assembleInfo
   {
      primary = 1;
      base = "";
      displayName = "PTF AR-2 Darter";
      assembleTo = "PTF_SSO_AR2";
      dissasembleTo[] = {};
   };
};
