class CfgPatches
{
	class PTF_Aircraft_f35
	{
		units[]={"PTF_F35a"};
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
