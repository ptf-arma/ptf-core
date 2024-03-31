class PTF_Backpack_LR_1 : USP_REEBOW_3DAP_ACC9_CBR
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Inf] Reebow 3DAP ACC9 (CBR) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 300;
   mass = 50;
   hiddenSelectionsTextures[] = {""};
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 20000;
   isbackpack = 1;
};