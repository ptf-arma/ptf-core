class CfgPatches
{
    class PTF_Aircraft_F35B_VIS
    {
        units[]={
            "FIR_F35B_Blank1",
            "PTF_F35B_VIS"
        };
        skipWhenMissingDependencies = 1;
        addonRootClass = "PTF_Aircraft";
        weapons[]={};
        requiredVersion=1.3200001;
        requiredAddons[]={"PTF_Main","Peral_F35B"};
    };
};


class cfgVehicles
{
#include "cfgF35B.hpp"
};
