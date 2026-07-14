class PTF_Backpack_Air_Carryall_Invis : B_Carryall_cbr
{
   scope = 2;
   side = 1;
   faction = "BLU_F";
   displayName = "[Air] Pilot Carryall (Hidden) [PTF]";
   author = "Paramarine Task Force";
   model = "\A3\weapons_f\empty";
   maximumLoad = 200;
   mass = 50;
   hiddenSelectionsTextures[] = {""};
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 15000;
   isbackpack = 1;
};
