class CfgPatches
{
	class PTF_Aircraft_f18
	{
		units[]={"PTF_AV8B"};
		weapons[]= {};
		requiredVersion=1.3200001;
		skipWhenMissingDependencies = 1;
		requiredAddons[]={"PTF_Main","PTF_Textures","FIR_AV8B_F"};
		addonRootClass = "PTF_Aircraft";
	};
};

class cfgVehicles
{
#include "cfgAV8B.hpp"
};	

