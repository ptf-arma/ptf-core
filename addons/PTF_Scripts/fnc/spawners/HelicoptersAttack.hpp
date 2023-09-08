class PTF_Helicopters_Attack {
    displayName = "Attack";
    condition = "_target distance (nearestObject [_target ,""Land_helipadEmpty_F""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "";
        class AH1Z {
        	statement = "createVehicle [""PTF_AH1Z_GUNFIGHTERS"", getPosATL (nearestObject [_player,""Land_helipadEmpty_F""])]";
            displayName = "Spawn AH-1Z Viper";
            icon = "";
            };
};