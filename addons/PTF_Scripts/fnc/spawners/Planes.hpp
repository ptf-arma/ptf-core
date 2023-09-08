class PTF_Planes {
    displayName = "Fixed Wing";
    condition = "_target distance (nearestObject [_target ,""Land_helipadSquare_F""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "";
        class f18Cag {
        	statement = "createVehicle [""PTF_F18C_CAG"", getPosATL (nearestObject [_player,""Land_helipadSquare_F""])]";
            displayName = "Spawn F-18 CAG";
            icon = "";
            };
		class f18D {
        	statement = "createVehicle [""PTF_F18D"", getPosATL (nearestObject [_player,""Land_helipadSquare_F""])]";
            displayName = "Spawn F-18";
            icon = "";
            };
		class EA18 {
        	statement = "createVehicle [""FIR_EA6B_VMAQ4"", getPosATL (nearestObject [_player,""Land_helipadSquare_F""])]";
            displayName = "Spawn EA18";
            icon = "";
            };
		class MQ9 {
        	statement = "createVehicle [""PTF_MQ9_SCARFACE"", getPosATL (nearestObject [_player,""Land_helipadSquare_F""])]";
            displayName = "Spawn MQ9";
            icon = "";
            };
		};



     