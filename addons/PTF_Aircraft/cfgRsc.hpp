class RscInGameUI
{
    class RHS_RscOptics_Heli_Attack_01_gunner;
    class PTF_RscOptics_AH1Z_Gunner: RHS_RscOptics_Heli_Attack_01_gunner
    {
        onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this spawn PTF_fnc_ah1z_gunnerUI";
    };
    class RHS_RscUH1Y_Observer;
    class PTF_RscOptics_UH1Y_Observer: RHS_RscUH1Y_Observer
    {
        onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this spawn PTF_fnc_uh1_obsHandler";
    };
};
