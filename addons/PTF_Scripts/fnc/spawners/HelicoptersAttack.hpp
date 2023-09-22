class PTF_Helicopters_Attack {
    displayName = "Attack";
    condition = "_target getVariable ['AttackHelicoptersSpawnable', false]";    
    distance = 1.5;
    enableInside = 1;
    icon = "a3\ui_f\data\gui\cfg\communicationmenu\casheli_ca.paa";
        class AH1Z {
        	statement = "['PTF_AH1Z_GUNFIGHTERS', 'Attack','PTF_Ah1zTickets'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn AH-1Z Viper";
            icon = "rhsusf\addons\rhsusf_a2port_air\data\ico\rhs_ah1z_pic_ca.paa";
            };
};