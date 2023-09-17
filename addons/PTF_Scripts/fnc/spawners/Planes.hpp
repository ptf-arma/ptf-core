class PTF_Planes {
    displayName = "Fixed Wing";
    condition = "_target distance (nearestObject [_target ,""Land_helipadSquare_F""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "a3\air_f_jets\plane_fighter_01\data\ui\fighter01_picture_ca.paa";
        class f18Cag {
        	statement = "createVehicle [""PTF_F18C_CAG"", getPosATL (nearestObject [_player,""Land_helipadSquare_F""])] call PTF_fnc_PylonRemoval";
            displayName = "Spawn F-18 CAG";
            icon = "FIR_FA18\ui\f18_ui_ca.paa";
            };
		class f18D {
        	statement = "createVehicle [""PTF_F18D"", getPosATL (nearestObject [_player,""Land_helipadSquare_F""])] call PTF_fnc_PylonRemoval";
            displayName = "Spawn F-18";
            icon = "FIR_FA18\ui\f18_ui_ca.paa";
            };
		class EA18 {
        	statement = "createVehicle [""FIR_EA6B_VMAQ4"", getPosATL (nearestObject [_player,""Land_helipadSquare_F""])] call PTF_fnc_PylonRemoval";
            displayName = "Spawn EA18";
            icon = "FIR_EA6B\ui\ea6b_loadout_eden.paa";
            };
		class MQ9 {
        	statement = "createVehicle [""PTF_MQ9_SCARFACE"", getPosATL (nearestObject [_player,""Land_helipadSquare_F""])] call PTF_fnc_PylonRemoval";
            displayName = "Spawn MQ9";
            icon = "FIR_EA6B\ui\ea6b_loadout_eden.paa";
            };
		};



     