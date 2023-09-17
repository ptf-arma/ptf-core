class PTF_Helicopters{ 
    displayName = "Transport";
    condition = "_target distance (nearestObject [_target ,""Land_HelipadCircle_f""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "ca\ui\data\iconhelicopter_ca.paa";
        class Uh1yArmed {
        	statement = "createVehicle [""PTF_UH1Y_GUNFIGHTERS"", getPosATL (nearestObject [_player,""Land_HelipadCircle_f""])]";
            displayName = "Spawn Armed Uh1y";
            icon = "rhsusf\addons\rhsusf_a2port_air\data\ico\rhs_uh1y_pic_ca.paa";
            };
        class Uh1yUnarmed : Uh1yArmed {
            statement = "createVehicle [""PTF_UH1Y_Unarmed"", getPosATL (nearestObject [_player,""Land_HelipadCircle_f""])]";
            displayName = "Spawn Unarmed Uh1y"; 
               };
        class CH53E {
        	statement = "createVehicle [""PTF_CH53_Ramp"", getPosATL (nearestObject [_player,""Land_HelipadCircle_f""])]";
            displayName = "Spawn CH-53E";
            icon = "rhsusf\addons\rhsusf_ch53\data\ui\ch53_picture_ca.paa";
            };
        class MV22 {
        	statement = "createVehicle [""PTF_MV22_Ramp"", getPosATL (nearestObject [_player,""Land_HelipadCircle_f""])]";
            displayName = "Spawn MV-22";
            icon = "dega_vehicles_v22\data\ui\icon_mv22_ca.paa";
            };
};
    
        