class PTF_Helicopters_Supply {
    displayName = "Supply";
    condition = "_target distance (nearestObject [_target ,""Land_helipadCivil_F""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "";
        class 53Cargo {
        	statement = "createVehicle [""PTF_CH53_CARGO"", getPosATL (nearestObject [_player,""Land_helipadCivil_F""])]";
            displayName = "Spawn CH-53E (Cargo)";
            icon = "";
            };
		class V22Cargo {
        	statement = "createVehicle [""PTF_MV22_Cargo"", getPosATL (nearestObject [_player,""Land_helipadCivil_F""])]";
        	displayName = "Spawn MV-22 (Cargo)";
        	icon = "";
        	};
};