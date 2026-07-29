class CfgPatches
{
	class BettIR_RHSUSAF_Compat
	{
		requiredAddons[]=
		{
			"BettIR_Core",
			"PTF_Clothes",
			// The nine CompatibleAttachments entries below key off RHS
			// attachment classnames; rhsusf_c_weapons is the RHS PBO that
			// defines rhsusf_acc_anpeq15_top and the wmx/anpeq16a variants.
			// (Their config parent, BettIR_Config >> CompatibleAttachments >>
			// rhsusf_acc_anpeq15_top, comes from BettIR_Core, so this is a
			// correctness/intent declaration rather than a parse-order fix.)
			"rhsusf_c_weapons"
		};
		requiredVersion=0.1;
		units[]={};
		weapons[]={};
		magazines[]={};
		ammo[]={};
	};
};
class BettIR_Config
{
    class CompatibleNightvisionGoggles
    {
         class PTF_Nightvision_PVS15_WP
         {
              offset[] = {0.1, 0.15,0.3};
         };
         class PTF_Nightvision_PVS15_GN
         {
              offset[] = {0.1, 0.15,0.3};
         };
    };
	class CompatibleAttachments
	{
		class rhsusf_acc_anpeq15_top;
		class rhsusf_acc_anpeq15_wmx: rhsusf_acc_anpeq15_top
		{
		};
		class rhsusf_acc_anpeq15_wmx_light: rhsusf_acc_anpeq15_top
		{
		};
		class rhsusf_acc_anpeq15_wmx_sc: rhsusf_acc_anpeq15_top
		{
		};
		class rhsusf_acc_anpeq15_wmx_light_sc: rhsusf_acc_anpeq15_top
		{
		};
		class rhsusf_acc_anpeq15_wmx_h: rhsusf_acc_anpeq15_top
		{
		};
		class rhsusf_acc_anpeq15_wmx_light_h: rhsusf_acc_anpeq15_top
		{
		};
		class rhsusf_acc_anpeq15a : rhsusf_acc_anpeq15_top
		{
		};
		class rhsusf_acc_anpeq16a_light : rhsusf_acc_anpeq15_top
		{
		};
		class rhsusf_acc_anpeq16a_light_top : rhsusf_acc_anpeq15_top
		{
		};
	};
};
class cfgMods
{
	author="Kommandant [PTF]";
	timepacked="1675710209";
};
