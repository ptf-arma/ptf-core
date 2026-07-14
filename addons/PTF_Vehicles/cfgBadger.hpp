//Badger
class PTF_Badger : B_APC_Wheeled_01_cannon_F
{
	scope = 2;
	faction = "BLU_F";
    editorCategory = "PTF";
    editorSubcategory = "PTF_Armor";
    ace_cargo_space = 6;
    ace_cargo_hasCargo = 1;
    ace_cargo_size = 0;
    ace_cargo_canLoad = 0;
    ace_dragging_canCarry = 0;
    ace_dragging_canDrag = 0;
    ace_hunterkiller[] = {{{0}, 3}, {{0,0}, 3}};
    maximumLoad = 3250;
    side = 1;
	SlingloadingWeight = "[2900,2800]";
	armor = 700;
    author = "Paramarine Task Force";
    displayName = "Badger Woodland [PTF]";
    hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\vehicles\badger\base_wd.paa", "\z\PTF\addons\PTF_Textures\vehicles\badger\acc_wd.paa", "\z\PTF\addons\PTF_Textures\vehicles\badger\turret_wd.paa", "a3\Armor_F\Data\camonet_NATO_Green_CO.paa", "a3\Armor_F\Data\cage_olive_CO.paa"};

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
		class _xx_RHS_weap_fgm148
		{
			weapon = "RHS_weap_fgm148";
			count = 1;
		};
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
	class HitPoints: HitPoints
	{
		class HitLFWheel: HitLFWheel
		{
			radius=0.33000001;
			visual="wheel_1_1_hide";
			armorComponent="wheel_1_1_hide";
			armor=-350;
			minimalHit=-0.016000001;
			explosionShielding=4;
			passThrough=0;
		};
		class HitLF2Wheel: HitLF2Wheel
		{
			radius=0.33000001;
			visual="wheel_1_2_hide";
			armorComponent="wheel_1_2_hide";
			armor=-350;
			minimalHit=-0.016000001;
			explosionShielding=4;
			passThrough=0;
		};
		class HitLMWheel: HitLMWheel
		{
			radius=0.33000001;
			visual="wheel_1_3_hide";
			armorComponent="wheel_1_3_hide";
			armor=-350;
			minimalHit=-0.016000001;
			explosionShielding=4;
			passThrough=0;
		};
		class HitLBWheel: HitLBWheel
		{
			radius=0.33000001;
			visual="wheel_1_4_hide";
			armorComponent="wheel_1_4_hide";
			armor=-350;
			minimalHit=-0.016000001;
			explosionShielding=4;
			passThrough=0;
		};
		class HitRFWheel: HitRFWheel
		{
			radius=0.33000001;
			visual="wheel_2_1_hide";
			armorComponent="wheel_2_1_hide";
			armor=-350;
			minimalHit=-0.016000001;
			explosionShielding=4;
			passThrough=0;
		};
		class HitRF2Wheel: HitRF2Wheel
		{
			radius=0.33000001;
			visual="wheel_2_2_hide";
			armorComponent="wheel_2_2_hide";
			armor=-350;
			minimalHit=-0.016000001;
			explosionShielding=4;
			passThrough=0;
		};
		class HitRMWheel: HitRMWheel
		{
			radius=0.33000001;
			visual="wheel_2_3_hide";
			armorComponent="wheel_2_3_hide";
			armor=-350;
			minimalHit=-0.016000001;
			explosionShielding=4;
			passThrough=0;
		};
		class HitRBWheel: HitRBWheel
		{
			radius=0.33000001;
			visual="wheel_2_4_hide";
			armorComponent="wheel_2_4_hide";
			armor=-350;
			minimalHit=-0.016000001;
			explosionShielding=4;
			passThrough=0;
		};
	};
};
class PTF_Badger_D : PTF_Badger
{
    displayName = "Badger Desert [PTF]";
    hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\vehicles\badger\base_d.paa", "\z\PTF\addons\PTF_Textures\vehicles\badger\acc_d.paa", "\z\PTF\addons\PTF_Textures\vehicles\badger\turret_d.paa", "a3\Armor_F\Data\camonet_NATO_Desert_CO.paa", "a3\Armor_F\Data\cage_sand_CO.paa"};
};
