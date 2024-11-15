class CfgPatches
{
	class PTF_Aircraft_f35
	{
		units[]={
		"PTF_F35Heavy",
		"PTF_F35Light",
		"PTF_F35Stealth"
		};
		skipWhenMissingDependencies = 1;
		addonRootClass = "PTF_Aircraft";
		weapons[]={};
		requiredVersion=1.3200001;
		requiredAddons[]={"PTF_Main","PTF_Textures","USAF_F35A_C"};
	};
};


class cfgVehicles
{
#include "cfgF35.hpp"
};	
