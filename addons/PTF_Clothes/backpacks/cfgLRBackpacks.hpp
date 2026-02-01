class PTF_Backpack_LR_1 : USP_REEBOW_3DAP_ACC9_CBR
{
   displayName = "[Inf LR] Reebow 3DAP ACC9 (CBR) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 200;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 10000;
};

// The class name on these ILBE backpacks needs to retain the same structure as the original one because some of their functionality relies on string parsing, including colors
// Failure to do so will result in: Whip extension not apperaing in ACE interactions, not being able to change antennas and backpacks disappearing when switching antennas
class PTF_Backpack_blade_coy : tfw_ilbe_blade_coy
{
   displayName = "[Inf LR] ASIP + Blade (Coy) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 180;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 15000;
};

class PTF_Backpack_blade_d : tfw_ilbe_blade_d
{
   displayName = "[Inf LR] ASIP + Blade (D) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 180;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 15000;
};

class PTF_Backpack_blade_wd2 : tfw_ilbe_blade_wd2
{
   displayName = "[Inf LR] ASIP + Blade (WD) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 180;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 15000;
};

class PTF_Backpack_blade_alpine : tfw_ilbe_blade_alpine
{
   displayName = "[Inf LR] ASIP + Blade (Alpine) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 180;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 15000;
};

class PTF_Backpack_whip_coy : tfw_ilbe_whip_coy
{
   displayName = "[Inf LR] ASIP + Whip (Coy) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 100;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 16000;
};

class PTF_Backpack_whipext_coy : tfw_ilbe_whipext_coy
{
   displayName = "[Inf LR] ASIP + Whip Antenna Extended (Coy) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 100;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 21000;
};

class PTF_Backpack_whip_alpine : tfw_ilbe_whip_alpine
{
   displayName = "[Inf LR] ASIP + Whip (Alpine) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 100;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 16000;
};

class PTF_Backpack_whipext_alpine : tfw_ilbe_whipext_alpine
{
   displayName = "[Inf LR] ASIP + Whip Antenna Extended (Alpine) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 100;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 21000;
};

class PTF_Backpack_whip_d : tfw_ilbe_whip_d
{
   displayName = "[Inf LR] ASIP + Whip (D) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 100;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 16000;
};

class PTF_Backpack_whipext_d : tfw_ilbe_whipext_d
{
   displayName = "[Inf LR] ASIP + Whip Antenna Extended (D) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 100;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 21000;
};

class PTF_Backpack_whip_wd2 : tfw_ilbe_whip_wd2
{
   displayName = "[Inf LR] ASIP + Whip (WD) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 100;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 16000;
};

class PTF_Backpack_whipext_wd2 : tfw_ilbe_whipext_wd2
{
   displayName = "[Inf LR] ASIP + Whip Antenna Extended (WD) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 100;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 21000;
};

class PTF_Backpack_DD_wd2 : tfw_ilbe_DD_wd2
{
   displayName = "[Inf LR] ASIP + VHF/UHF (WD) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 150;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 16000;
};

class PTF_Backpack_DD_d : tfw_ilbe_DD_d
{
   displayName = "[Inf LR] ASIP + VHF/UHF (D) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 150;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 16000;
};

class PTF_Backpack_DD_coy : tfw_ilbe_DD_coy
{
   displayName = "[Inf LR] ASIP + VHF/UHF (Coy) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 150;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 16000;
};

class PTF_Backpack_DD_alpine : tfw_ilbe_DD_alpine
{
   displayName = "[Inf LR] ASIP + VHF/UHF (Alpine) [PTF]";
   author = "Paramarine Task Force";
   maximumLoad = 150;
   mass = 50;
   tf_encryptionCode = "tf_west_radio_code";
   tf_dialog = "rt1523g_radio_dialog";
   tf_subtype = "digital_lr";
   tf_dialogUpdate = "call TFAR_fnc_updateLRDialogToChannel";
   tf_hasLRradio = 1;
   tf_range = 16000;
};