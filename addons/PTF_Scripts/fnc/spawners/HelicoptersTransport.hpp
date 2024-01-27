class PTF_Helicopters{ 
    displayName = "Transport";
    condition = "_target getVariable ['TransportHelicoptersSpawnable', false]";    
    distance = 1.5;
    enableInside = 1;
    icon = "ca\ui\data\iconhelicopter_ca.paa";
        class Uh1yArmed {
            statement = "['PTF_UH1Y_GUNFIGHTERS', 'Transport', 'PTF_Uh1yTickets'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn Armed Uh1y";
            icon = "rhsusf\addons\rhsusf_a2port_air\data\ico\rhs_uh1y_pic_ca.paa";
            };
        class Uh1yUnarmed : Uh1yArmed {
            statement = "['PTF_UH1Y_Unarmed', 'Transport'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn Unarmed Uh1y"; 
               };
        class CH53E {
            statement = "['PTF_CH53_Ramp', 'Transport'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn CH-53E";
            icon = "rhsusf\addons\rhsusf_ch53\data\ui\ch53_picture_ca.paa";
            };
        class MV22 {
            statement = "['PTF_MV22_Ramp', 'Transport'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn MV-22";
            icon = "dega_vehicles_v22\data\ui\icon_mv22_ca.paa";
            };
};
    
        