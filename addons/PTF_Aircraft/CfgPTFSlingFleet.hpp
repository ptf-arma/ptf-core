// The aircraft the "Sling info" readout (PTF_fnc_slingInfo, PTF_Scripts)
// checks cargo against, in display order. `vehicle` is a representative class;
// its slingLoadMaxCargoMass is the rating shown, and its class prefix decides
// which SlingloadingWeight entry applies. Variants with a different rating
// need their own entry (the ramp/minigun MV-22s inherit SLR's 13 t VTOL
// default, the cargo MV-22 is rated 15 t).
class CfgPTFSlingFleet {
    class CH53 {
        displayName = "CH-53E";
        vehicle = "PTF_CH53_Cargo";
    };
    class MV22_Cargo {
        displayName = "MV-22 Cargo";
        vehicle = "PTF_MV22_Cargo";
    };
    class MV22 {
        displayName = "MV-22";
        vehicle = "PTF_MV22_Ramp";
    };
    class UH1Y {
        displayName = "UH-1Y";
        vehicle = "PTF_UH1Y";
    };
};
