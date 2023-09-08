class PTF_Helicopters{ 
    displayName = "Transport";
    condition = "_target distance (nearestObject [_target ,""Land_HelipadCircle_f""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "";
        class Uh1yArmed {
        	statement = "createVehicle [""PTF_UH1Y_GUNFIGHTERS"", getPosATL (nearestObject [_player,""Land_HelipadCircle_f""])]";
            displayName = "Spawn Armed Uh1y";
            icon = "";
            };
        class Uh1yUnarmed : Uh1yArmed {
            statement = "createVehicle [""PTF_UH1Y_Unarmed"", getPosATL (nearestObject [_player,""Land_HelipadCircle_f""])]";
            displayName = "Spawn Unarmed Uh1y"; 
               };
        class CH53E {
        	statement = "createVehicle [""PTF_CH53_Ramp"", getPosATL (nearestObject [_player,""Land_HelipadCircle_f""])]";
            displayName = "Spawn CH-53E";
            icon = "";
            };
        class MV22 {
        	statement = "createVehicle [""PTF_MV22_Ramp"", getPosATL (nearestObject [_player,""Land_HelipadCircle_f""])]";
            displayName = "Spawn MV-22";
            icon = "";
            };
};
    
        