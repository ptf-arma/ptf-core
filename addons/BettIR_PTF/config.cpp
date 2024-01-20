class CfgPatches
{
	class BettIR_RHSUSAF_Compat
	{
		requiredAddons[]=
		{
			"BettIR_Core",
			"PTF_Clothes"
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
