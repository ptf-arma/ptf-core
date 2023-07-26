//RHS & Vanilla
class PTF_Helmet_Air_Black : H_PilotHelmetFighter_B
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Air] HGU-56P (Black) [PTF]";
   author = "Paramarine Task Force";
   model = "rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\rhs_hgu56_visor";
   hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_blk_co.paa"};
   class ItemInfo : ItemInfo
   {
      uniformModel = "rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\rhs_hgu56_visor";
      mass = 20;
      class HitpointsProtectionInfo
      {
         class Head
         {
            hitpointName = "HitHead";
            armor = 6;
            passThrough = 0.5;
         };
      };
   };
};
class PTF_Helmet_Air_Green : PTF_Helmet_Air_Black
{
   displayName = "[Air] HGU-56P (Green) [PTF]";
   hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_green_co.paa"};
};
class PTF_Helmet_Air_Tan : PTF_Helmet_Air_Black
{
   displayName = "[Air] HGU-56P (Tan) [PTF]";
   hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_tan_co.paa"};
};
class PTF_Helmet_Air_Olive : PTF_Helmet_Air_Black
{
   displayName = "[Air] HGU-56P (Olive) [PTF]";
   hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_olv_co.paa"};
   
};
class PTF_Helmet_Air_Pink : PTF_Helmet_Air_Black
{ 
   displayName = "[Air] HGU-56P (Pink) [PTF]";
   hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_pink_co.paa"};
};
class PTF_Helmet_Air_White : PTF_Helmet_Air_Black
{
   displayName = "[Air] HGU-56P (White) [PTF]";
   hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_white_co.paa"};
};
class PTF_Helmet_Air_USA : PTF_Helmet_Air_Black
{
   displayName = "[Air] HGU-56P (USA) [PTF]";
   hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_usa_co.paa"};
};
class PTF_Helmet_Air_Smiley : PTF_Helmet_Air_Black
{
   displayName = "[Air] HGU-56P (Smiley) [PTF]";
   model = "rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\rhs_hgu56_visor_mask";
   hiddenSelectionsTextures[] = {"\rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\Data\rhs_hgu56_smiley_co.paa"};
   class ItemInfo: ItemInfo
	{
		uniformModel = "rhsusf\addons\rhsusf_infantry2\gear\head\hgu56\rhs_hgu56_visor_mask";
	};
};
class PTF_Helmet_Air_HMDS : PTF_Helmet_Air_Black
{
   
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_range = 15000;
   tf_hasLRradio = 1;
   displayName = "[Air] HMDS (Gen3) [PTF]";
   author = "Paramarine Task Force";
   class ItemInfo : ItemInfo
   {
      mass = 20;
      class HitpointsProtectionInfo
      {
         class Head
         {
            hitpointName = "HitHead";
            armor = 6;
            passThrough = 0.5;
         };
      };
   };
};