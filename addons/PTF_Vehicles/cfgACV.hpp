//ACV M2
class PTF_ACV : Peral_ACV
{
	scope = 2;
	faction = "BLU_F";
    editorCategory = "PTF";
    editorSubcategory = "PTF_Armor";
    ace_cargo_space = 15;
    ace_cargo_hasCargo = 1;
    ace_cargo_size = 0;
    ace_cargo_canLoad = 0;
    ace_dragging_canCarry = 0;
    ace_dragging_canDrag = 0;
    ace_hunterkiller[] = {{{0}, 3}, {{0,0}, 3}};
    maximumLoad = 3250;
    side = 1;
	// Sling-load mass override read by PTF_fnc_slingloading ([mass under CH-53,
	// mass under MV-22]). Left disabled deliberately -- cfgBadger.hpp sets the
	// same values live; uncomment only if the ACVs should be liftable.
	//SlingloadingWeight = "[2900,2800]";
    author = "Paramarine Task Force";
    displayName = "ACV (M2) [PTF]";

	class TransportMagazines
	{
		class _xx_rhsusf_100rnd_762x51_m80a1epr
		{
			magazine = "rhsusf_100rnd_762x51_m80a1epr";
			count = 15;
		};
		class _xx_rhsusf_100Rnd_556x45_mixed_soft_pouch
		{
			magazine = "rhsusf_200Rnd_556x45_mixed_soft_pouch";
			count = 10;
		};
		class _xx_PTF_Mag_556x45_M855A1_PMAG_Mix
		{
			magazine = "PTF_Mag_556x45_M855A1_PMAG_Mix";
			count = 30;
		};
		class _xx_rhs_fgm148_magazine_AT
		{
			magazine = "rhs_fgm148_magazine_AT";
			count = 2;
		};
		class _xx_DemoCharge_Remote_Mag
		{
			magazine = "DemoCharge_Remote_Mag";
			count = 2;
		};
		class _xx_rhs_mag_m67
		{
			magazine = "rhs_mag_m67";
			count = 8;
		};
		class _xx_SmokeShellRed
		{
			magazine = "SmokeShellRed";
			count = 2;
		};
		class _xx_SmokeShellBlue
		{
			magazine = "SmokeShellBlue";
			count = 2;
		};
		class _xx_SmokeShellGreen
		{
			magazine = "SmokeShellGreen";
			count = 2;
		};
		class _xx_SmokeShell
		{
			magazine = "SmokeShell";
			count = 4;
		};
	};
	class TransportItems
	{
   		class _xx_ACE_fieldDressing
		{
			name = "ACE_fieldDressing";
			count = 30;
		};
  		class _xx_ACE_elasticBandage
		{
			name = "ACE_elasticBandage";
			count = 30;
		};
   		class _xx_ACE_packingBandage
		{
			name = "ACE_packingBandage";
			count = 30;
		};
   		class _xx_ACE_quikclot
		{
			name = "ACE_quikclot";
			count = 30;
		};
   		class _xx_ACE_plasmaIV
		{
			name = "ACE_plasmaIV";
			count = 5;
		};
   		class _xx_ACE_plasmaIV_500
		{
			name = "ACE_plasmaIV_500";
			count = 5;
		};
  		class _xx_ACE_Chemlight_HiGreen
		{
			name = "ACE_Chemlight_HiGreen";
			count = 3;
		};
  		class _xx_ACE_Chemlight_HiRed
		{
			name = "ACE_Chemlight_HiRed";
			count = 3;
		};
  		class _xx_ACE_EarPlugs
		{
			name = "ACE_EarPlugs";
			count = 2;
		};
   		class _xx_ToolKit
		{
			name = "ToolKit";
			count = 1;
		};
   		class _xx_ACE_IR_Strobe_Item
		{
			name = "ACE_IR_Strobe_Item";
			count = 2;
		};
   		class _xx_ACE_Clacker
		{
			name = "ACE_Clacker";
			count = 1;
		};
   		class _xx_ACE_rope15
		{
			name = "ACE_rope15";
			count = 1;
		};
   		class _xx_ACE_splint
		{
			name = "ACE_splint";
			count = 8;
		};
		class _xx_ACE_UAVBattery
		{
			name = "ACE_UAVBattery";
			count = 3;
		};
	};
	class TransportWeapons
	{
		class _xx_rhs_weap_m240B
		{
			weapon = "rhs_weap_m240B";
			count = 1;
		};
		class _xx_ACE_VMH3
		{
			weapon = "ACE_VMH3";
			count = 1;
		};
		class _xx_rhs_weap_m72a7
		{
			weapon = "rhs_weap_m72a7";
			count = 2;
		};
	};
};

//ACV M2
class PTF_ACV_MK19 : Peral_ACV_MK19
{
	scope = 2;
	faction = "BLU_F";
    editorCategory = "PTF";
    editorSubcategory = "PTF_Armor";
    ace_cargo_space = 15;
    ace_cargo_hasCargo = 1;
    ace_cargo_size = 0;
    ace_cargo_canLoad = 0;
    ace_dragging_canCarry = 0;
    ace_dragging_canDrag = 0;
    ace_hunterkiller[] = {{{0}, 3}, {{0,0}, 3}};
    maximumLoad = 3250;
    side = 1;
	// Sling-load mass override read by PTF_fnc_slingloading ([mass under CH-53,
	// mass under MV-22]). Left disabled deliberately -- cfgBadger.hpp sets the
	// same values live; uncomment only if the ACVs should be liftable.
	//SlingloadingWeight = "[2900,2800]";
    author = "Paramarine Task Force";
    displayName = "ACV (MK19) [PTF]";

	class TransportMagazines
	{
		class _xx_rhsusf_100rnd_762x51_m80a1epr
		{
			magazine = "rhsusf_100rnd_762x51_m80a1epr";
			count = 15;
		};
		class _xx_rhsusf_100Rnd_556x45_mixed_soft_pouch
		{
			magazine = "rhsusf_200Rnd_556x45_mixed_soft_pouch";
			count = 10;
		};
		class _xx_PTF_Mag_556x45_M855A1_PMAG_Mix
		{
			magazine = "PTF_Mag_556x45_M855A1_PMAG_Mix";
			count = 30;
		};
		class _xx_rhs_fgm148_magazine_AT
		{
			magazine = "rhs_fgm148_magazine_AT";
			count = 2;
		};
		class _xx_DemoCharge_Remote_Mag
		{
			magazine = "DemoCharge_Remote_Mag";
			count = 2;
		};
		class _xx_rhs_mag_m67
		{
			magazine = "rhs_mag_m67";
			count = 8;
		};
		class _xx_SmokeShellRed
		{
			magazine = "SmokeShellRed";
			count = 2;
		};
		class _xx_SmokeShellBlue
		{
			magazine = "SmokeShellBlue";
			count = 2;
		};
		class _xx_SmokeShellGreen
		{
			magazine = "SmokeShellGreen";
			count = 2;
		};
		class _xx_SmokeShell
		{
			magazine = "SmokeShell";
			count = 4;
		};
	};
	class TransportItems
	{
   		class _xx_ACE_fieldDressing
		{
			name = "ACE_fieldDressing";
			count = 30;
		};
  		class _xx_ACE_elasticBandage
		{
			name = "ACE_elasticBandage";
			count = 30;
		};
   		class _xx_ACE_packingBandage
		{
			name = "ACE_packingBandage";
			count = 30;
		};
   		class _xx_ACE_quikclot
		{
			name = "ACE_quikclot";
			count = 30;
		};
   		class _xx_ACE_plasmaIV
		{
			name = "ACE_plasmaIV";
			count = 5;
		};
   		class _xx_ACE_plasmaIV_500
		{
			name = "ACE_plasmaIV_500";
			count = 5;
		};
  		class _xx_ACE_Chemlight_HiGreen
		{
			name = "ACE_Chemlight_HiGreen";
			count = 3;
		};
  		class _xx_ACE_Chemlight_HiRed
		{
			name = "ACE_Chemlight_HiRed";
			count = 3;
		};
  		class _xx_ACE_EarPlugs
		{
			name = "ACE_EarPlugs";
			count = 2;
		};
   		class _xx_ToolKit
		{
			name = "ToolKit";
			count = 1;
		};
   		class _xx_ACE_IR_Strobe_Item
		{
			name = "ACE_IR_Strobe_Item";
			count = 2;
		};
   		class _xx_ACE_Clacker
		{
			name = "ACE_Clacker";
			count = 1;
		};
   		class _xx_ACE_rope15
		{
			name = "ACE_rope15";
			count = 1;
		};
   		class _xx_ACE_splint
		{
			name = "ACE_splint";
			count = 8;
		};
		class _xx_ACE_UAVBattery
		{
			name = "ACE_UAVBattery";
			count = 3;
		};
	};
	class TransportWeapons
	{
		class _xx_rhs_weap_m240B
		{
			weapon = "rhs_weap_m240B";
			count = 1;
		};
		class _xx_ACE_VMH3
		{
			weapon = "ACE_VMH3";
			count = 1;
		};
		class _xx_rhs_weap_m72a7
		{
			weapon = "rhs_weap_m72a7";
			count = 2;
		};
	};
};

//ACV M2
class PTF_ACV_30 : Peral_ACV_30
{
	scope = 2;
	faction = "BLU_F";
    editorCategory = "PTF";
    editorSubcategory = "PTF_Armor";
    ace_cargo_space = 15;
    ace_cargo_hasCargo = 1;
    ace_cargo_size = 0;
    ace_cargo_canLoad = 0;
    ace_dragging_canCarry = 0;
    ace_dragging_canDrag = 0;
    ace_hunterkiller[] = {{{0}, 3}, {{0,0}, 3}};
    maximumLoad = 3250;
    side = 1;
	// Sling-load mass override read by PTF_fnc_slingloading ([mass under CH-53,
	// mass under MV-22]). Left disabled deliberately -- cfgBadger.hpp sets the
	// same values live; uncomment only if the ACVs should be liftable.
	//SlingloadingWeight = "[2900,2800]";
    author = "Paramarine Task Force";
    displayName = "ACV (30MM) [PTF]";

	class TransportMagazines
	{
		class _xx_rhsusf_100rnd_762x51_m80a1epr
		{
			magazine = "rhsusf_100rnd_762x51_m80a1epr";
			count = 15;
		};
		class _xx_rhsusf_100Rnd_556x45_mixed_soft_pouch
		{
			magazine = "rhsusf_200Rnd_556x45_mixed_soft_pouch";
			count = 10;
		};
		class _xx_PTF_Mag_556x45_M855A1_PMAG_Mix
		{
			magazine = "PTF_Mag_556x45_M855A1_PMAG_Mix";
			count = 30;
		};
		class _xx_rhs_fgm148_magazine_AT
		{
			magazine = "rhs_fgm148_magazine_AT";
			count = 2;
		};
		class _xx_DemoCharge_Remote_Mag
		{
			magazine = "DemoCharge_Remote_Mag";
			count = 2;
		};
		class _xx_rhs_mag_m67
		{
			magazine = "rhs_mag_m67";
			count = 8;
		};
		class _xx_SmokeShellRed
		{
			magazine = "SmokeShellRed";
			count = 2;
		};
		class _xx_SmokeShellBlue
		{
			magazine = "SmokeShellBlue";
			count = 2;
		};
		class _xx_SmokeShellGreen
		{
			magazine = "SmokeShellGreen";
			count = 2;
		};
		class _xx_SmokeShell
		{
			magazine = "SmokeShell";
			count = 4;
		};
	};
	class TransportItems
	{
   		class _xx_ACE_fieldDressing
		{
			name = "ACE_fieldDressing";
			count = 30;
		};
  		class _xx_ACE_elasticBandage
		{
			name = "ACE_elasticBandage";
			count = 30;
		};
   		class _xx_ACE_packingBandage
		{
			name = "ACE_packingBandage";
			count = 30;
		};
   		class _xx_ACE_quikclot
		{
			name = "ACE_quikclot";
			count = 30;
		};
   		class _xx_ACE_plasmaIV
		{
			name = "ACE_plasmaIV";
			count = 5;
		};
   		class _xx_ACE_plasmaIV_500
		{
			name = "ACE_plasmaIV_500";
			count = 5;
		};
  		class _xx_ACE_Chemlight_HiGreen
		{
			name = "ACE_Chemlight_HiGreen";
			count = 3;
		};
  		class _xx_ACE_Chemlight_HiRed
		{
			name = "ACE_Chemlight_HiRed";
			count = 3;
		};
  		class _xx_ACE_EarPlugs
		{
			name = "ACE_EarPlugs";
			count = 2;
		};
   		class _xx_ToolKit
		{
			name = "ToolKit";
			count = 1;
		};
   		class _xx_ACE_IR_Strobe_Item
		{
			name = "ACE_IR_Strobe_Item";
			count = 2;
		};
   		class _xx_ACE_Clacker
		{
			name = "ACE_Clacker";
			count = 1;
		};
   		class _xx_ACE_rope15
		{
			name = "ACE_rope15";
			count = 1;
		};
   		class _xx_ACE_splint
		{
			name = "ACE_splint";
			count = 8;
		};
		class _xx_ACE_UAVBattery
		{
			name = "ACE_UAVBattery";
			count = 3;
		};
	};
	class TransportWeapons
	{
		class _xx_rhs_weap_m240B
		{
			weapon = "rhs_weap_m240B";
			count = 1;
		};
		class _xx_ACE_VMH3
		{
			weapon = "ACE_VMH3";
			count = 1;
		};
		class _xx_rhs_weap_m72a7
		{
			weapon = "rhs_weap_m72a7";
			count = 2;
		};
	};
};

class PTF_ACV_E : Peral_ACV_E
{
	scope = 2;
	faction = "BLU_F";
	editorCategory = "PTF";
	editorSubcategory = "PTF_Armor";
	ace_cargo_space = 15;
	ace_cargo_hasCargo = 1;
	ace_cargo_size = 0;
	ace_cargo_canLoad = 0;
	ace_dragging_canCarry = 0;
	ace_dragging_canDrag = 0;
	ace_hunterkiller[] = {{{0}, 3}, {{0,0}, 3}};
	maximumLoad = 3250;
	side = 1;
	// Sling-load mass override read by PTF_fnc_slingloading ([mass under CH-53,
	// mass under MV-22]). Left disabled deliberately -- cfgBadger.hpp sets the
	// same values live; uncomment only if the ACVs should be liftable.
	//SlingloadingWeight = "[2900,2800]";
	author = "Paramarine Task Force";
	displayName = "ACV-E (MK19) [PTF]";

	class TransportMagazines
	{
		mag_xx(rhsusf_100rnd_762x51,4);
		mag_xx(PTF_Mag_556x45_M855A1_PMAG_Mix,19);
		mag_xx(crayon_box,1);
		mag_xx(DemoCharge_Remote_Mag,4);
		mag_xx(SatchelCharge_Remote_Mag,3);
		mag_xx(SmokeShell,10);
	};
	class TransportItems
	{
		item_xx(ACE_vmm3,1);
		item_xx(ACE_DefusalKit,2);
		item_xx(ACE_EntrenchingTool,1);
		item_xx(ACE_Clacker,2);
		item_xx(ACE_rope12,1); // One rope seems to be added automagically so we add one here to get a total of 2
		item_xx(tfw_rf3080Item,1);
		item_xx(ToolKit,1);
		item_xx(ACE_UAVBattery,2);
	};
	class TransportWeapons
	{
		weap_xx(rhs_weap_M136_hedp,2);
		weap_xx(rhs_weap_m240B,1);
	};
	class TransportBackpacks
	{
		backpack_xx(PTF_SSO_Backpack,1);
		backpack_xx(B_UGV_02_Demining_backpack_F,1);
		backpack_xx(MD_APOBS_backpack,3);
	};
};

class PTF_ACV_R : Peral_ACV_R
{
	scope = 2;
	faction = "BLU_F";
	editorCategory = "PTF";
	editorSubcategory = "PTF_Armor";
	ace_cargo_space = 15;
	ace_cargo_hasCargo = 1;
	ace_cargo_size = 0;
	ace_cargo_canLoad = 0;
	ace_dragging_canCarry = 0;
	ace_dragging_canDrag = 0;
	ace_hunterkiller[] = {{{0}, 3}, {{0,0}, 3}};
	maximumLoad = 3250;
	side = 1;
	// Sling-load mass override read by PTF_fnc_slingloading ([mass under CH-53,
	// mass under MV-22]). Left disabled deliberately -- cfgBadger.hpp sets the
	// same values live; uncomment only if the ACVs should be liftable.
	//SlingloadingWeight = "[2900,2800]";
	author = "Paramarine Task Force";
	displayName = "ACV-R (MK19) [PTF]";

	class TransportMagazines
	{
		mag_xx(DemoCharge_Remote_Mag,2);
		mag_xx(rhsusf_100rnd_762x51_m80a1epr,15);
		mag_xx(rhsusf_200rnd_556x45_soft_pouch,10);
		mag_xx(PTF_Mag_556x45_M855A1_PMAG_Mix,30);
		mag_xx(SmokeShellBlue,2);
		mag_xx(SmokeShellGreen,2);
		mag_xx(SmokeShellRed,2);
		mag_xx(SmokeShell,4);
		mag_xx(HandGrenade,8);
	};
	class TransportItems
	{
		item_xx(ACE_vmm3,1);
		item_xx(ACE_EntrenchingTool,2);
		item_xx(ToolKit,2);
		item_xx(tfw_rf3080Item,1);
		item_xx(ACE_rope15,2);
		item_xx(ACE_UAVBattery,3);
		item_xx(ACE_fieldDressing,30);
		item_xx(ACE_elasticBandage,30);
		item_xx(ACE_packingBandage,30);
		item_xx(ACE_quikclot,30);
		item_xx(ACE_bodyBag,2);
		item_xx(ACE_IR_Strobe_Item,2);
		item_xx(ACE_Clacker,1);
		item_xx(ACE_plasmaIV,5);
		item_xx(ACE_plasmaIV_500,5);
		item_xx(ACE_splint,8);

	};
	class TransportWeapons
	{
		weap_xx(rhs_weap_m240B,1);
		weap_xx(rhs_weap_m72a7,2);
	};
};
