class PTF_Planes {
      displayName = "Fixed Wing";
      condition = "_target getVariable ['PlanesSpawnable', false]";
      distance = 1.5;
      enableInside = 1;
      icon = "a3\air_f_jets\plane_fighter_01\data\ui\fighter01_picture_ca.paa";
        class f18Cag {
            statement = "['PTF_F18C_CAG', 'Plane','PTF_PlaneTickets'] call PTF_fnc_SpawnFunction"
            displayName = "Spawn F-18 CAG";
            icon = "FIR_FA18\ui\f18_ui_ca.paa";
            };
		class f18D {
            statement = "['PTF_F18D', 'Plane','PTF_PlaneTickets'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn F-18";
            icon = "FIR_FA18\ui\f18_ui_ca.paa";
            };
		class EA18 {
            statement = "['FIR_EA6B_VMAQ4', 'Plane','PTF_PlaneTickets'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn EA18";
            icon = "FIR_EA6B\ui\ea6b_loadout_eden.paa";
            };
		class MQ9 {
            statement = "['PTF_MQ9_SCARFACE', 'Plane',PTF_MQ9Tickets] call PTF_fnc_SpawnFunction";
            displayName = "Spawn MQ9";
            icon = "FIR_EA6B\ui\ea6b_loadout_eden.paa";
            };
		};



     