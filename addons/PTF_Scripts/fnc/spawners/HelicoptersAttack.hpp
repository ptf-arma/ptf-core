class PTF_Helicopters_Attack {
    displayName = "Attack";
    condition = "_target distance (nearestObject [_target ,""Land_helipadEmpty_F""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "a3\ui_f\data\gui\cfg\communicationmenu\casheli_ca.paa";
        class AH1Z {
        	statement = "['PTF_AH1Z_GUNFIGHTERS', 'attack'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn AH-1Z Viper";
            icon = "rhsusf\addons\rhsusf_a2port_air\data\ico\rhs_ah1z_pic_ca.paa";
            };
};