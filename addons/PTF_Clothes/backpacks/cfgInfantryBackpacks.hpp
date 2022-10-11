class PTF_Backpack_Infantry_Corpsman_LR : TFAR_Bag_Base
{
   displayName="[PTF] Corpsman LR Backpack";
   descriptionShort="RT-1523G (ASIP) + VHF/ UHF Antenna (15km)";
   author="Paramarines Task Force";
   scope=2;
   scopeCurator=2;
   scopeArsenal=2;
   editorPreview="";
   model="y\tfw_radios\addons\ilbe\data\model\dd\tfw_dd_ilbe.p3d";
   hiddenSelections[]=
   {
      "camo"
   };
   maximumLoad=500;
   mass=50;
   isbackpack=1;
   picture="y\tfw_radios\addons\ilbe\data\icons\ilbe_icon_coy.paa";
   hiddenSelectionsTextures[]=
   {
      "y\tfw_radios\addons\ilbe\data\model\ilbe_coy_co.paa"
   };

   //TFAR shit
   tf_encryptionCode="tf_west_radio_code";
   tf_dialog="rt1523g_radio_dialog";
   tf_subtype="digital_lr";
   tf_range=15000;
};
class PTF_Backpack_Infantry_Kitbag : B_Kitbag_cbr
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Kitbag [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 400;
   mass = 40;
};
class PTF_Backpack_Infantry_Corpsman_Kitbag_Red : B_Kitbag_cbr
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Corpsman Kitbag (Red) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 500;
   mass = 50;
   hiddenSelectionsTextures[] =
       {
           "\PTF_Textures\gear\backpacks\PTF_Corpsman_Kitbag_Red_co.paa"};
};
class PTF_Backpack_Infantry_Corpsman_Kitbag_Black : B_Kitbag_cbr
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Corpsman Kitbag (Black) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 500;
   mass = 50;
   hiddenSelectionsTextures[] =
       {
           "\PTF_Textures\gear\backpacks\PTF_Corpsman_Kitbag_Black_co.paa"};
};
class PTF_Backpack_Infantry_Carryall : B_Carryall_cbr
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Carryall [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 500;
   mass = 50;
};
class PTF_Backpack_Infantry_Assault : B_AssaultPack_cbr
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Assault [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 300;
   mass = 30;
};
class PTF_Backpack_Infantry_Assault_Invis : B_AssaultPack_cbr
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Assault (Hidden) [PTF]";
   author = "Paramarine Task Force";
   model = "\A3\weapons_f\empty";
   hiddenSelectionsTextures[] = {""};
   maximumLoad = 300;
   mass = 30;
};
//RHS BAGS
class PTF_Backpack_Infantry_Falcon : rhsusf_falconii_coy
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Falcon-II [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 300;
   mass = 30;
};
class PTF_Backpack_Infantry_Eagle : rhsusf_assault_eagleaiii_coy
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Eagle-III [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 400;
   mass = 40;
};
//USP Bags
class PTF_Backpack_Infantry_Crye : USP_CRYE_BELT_PACK
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Crye Belt [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 200;
   mass = 20;
};
class PTF_Backpack_Infantry_Crye_Zipon : USP_ZIPON_PANEL_CBR
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Crye Zipon [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 200;
   mass = 20;
};
class PTF_Backpack_Infantry_Crye_Breacher : USP_PACK_BREACHER_CBR
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Crye Breacher [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 200;
   mass = 20;
};
class PTF_Backpack_Infantry_Crye_Patrol : USP_PATROL_PACK_CBR
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Crye Patrol [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 300;
   mass = 30;
};
class PTF_Backpack_Infantry_Crye_Hydro : USP_HYDROPACK_CBR
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Crye Hydro [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 200;
   mass = 20;
};
class PTF_Backpack_Infantry_Crye_LAAW : USP_LAAW_CLIP
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Crye LAAW [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 200;
   mass = 20;
};