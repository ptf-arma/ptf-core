class CfgPatches
{
	class PTF_Aircraft_f18
	{
		units[]=
		{
			"PTF_F18C",
			"PTF_F18C_CAG",
			"PTF_F18D",
		};
		skipWhenMissingDependencies = 1;
		weapons[]={};
		requiredVersion=1.3200001;
		requiredAddons[]={"PTF_Main","PTF_Textures","FIR_FA18_F"};
		addonRootClass = "PTF_Aircraft";
	};
};


class cfgVehicles
{
#include "cfgF18.hpp"
};	
