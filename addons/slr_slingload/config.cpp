#include "script_component.hpp"

class CfgPatches {
    class ADDON {
        name = COMPONENT_NAME;
        units[] = {
            "slr_slingload_apexFitting",
            "slr_slingload_wreckDummy"
        };
        weapons[] = {};
        requiredVersion = REQUIRED_VERSION;
        requiredAddons[] = {"ace_interaction", "ace_refuel", "ace_explosives", "ace_trenches"}; // ace_trenches: ACE_EntrenchingTool, parent of the cargo sling
        author = "";
        authors[] = {""};
        VERSION_CONFIG;
    };
};

#include "CfgEventHandlers.hpp"
#include "CfgVehicles.hpp"
#include "CfgNonAIVehicles.hpp"
#include "CfgWeapons.hpp"
