class CfgPatches
{
	class PTF_Aircraft_AH1Z_VIS
	{
		units[]={
			"PTF_AH1Z_VIS"
		};
		skipWhenMissingDependencies = 1;
		addonRootClass = "PTF_Aircraft";
		weapons[]={};
		requiredVersion=1.3200001;
		requiredAddons[]={"PTF_Main","Peral_AH1Z"};
	};
};


class cfgVehicles
{
#include "cfgAH1Z.hpp"
};
