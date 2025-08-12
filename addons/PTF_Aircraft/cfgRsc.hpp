class RscInGameUI
{
    // AH-1Z
    class RHS_RscOptics_Heli_Attack_01_gunner;
    class PTF_RscOptics_AH1Z_Gunner: RHS_RscOptics_Heli_Attack_01_gunner
    {
        onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this spawn PTF_fnc_ah1z_gunnerUI";
    };

    // UH-1Y
    class RHSUSF_RscUnitInfoAir_UH1Y;
    class PTF_RscUnitInfo_Air_UH1Y: RHSUSF_RscUnitInfoAir_UH1Y
	{
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay');['jet',17] spawn RHSUSF_fnc_randomRadio;_this call PTF_fnc_uh1_handler;_this call rhsusf_fnc_announcer;_this spawn rhs_fnc_dynamicObjectDrawing_loop;[] call RHS_fnc_UI_Options";
	};
    class RHSUSF_RscUnitInfoAirRTDFullDigital_UH1Y;
    class PTF_RscUnitInfo_AirRTDFullDigital_UH1Y: RHSUSF_RscUnitInfoAirRTDFullDigital_UH1Y
	{
		onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay');['jet',17] spawn RHSUSF_fnc_randomRadio;_this call PTF_fnc_uh1_handler;_this call rhsusf_fnc_announcer;_this spawn rhs_fnc_dynamicObjectDrawing_loop;[] call RHS_fnc_UI_Options";
	};
    class RHS_RscUH1Y_Observer;
    class PTF_RscOptics_UH1Y_Observer: RHS_RscUH1Y_Observer
    {
        onLoad="['onLoad',_this,'RscUnitInfo','IGUI'] call (uinamespace getvariable 'BIS_fnc_initDisplay'); _this spawn PTF_fnc_uh1_obsHandler";
    };
};
