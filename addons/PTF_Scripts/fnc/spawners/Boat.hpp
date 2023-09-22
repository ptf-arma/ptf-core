class PTF_Boat {
    displayName = "Boat";
    condition = "_target getVariable ['BoatSpawnable', false]";
    distance = 1.5;
    enableInside = 1;
    icon = "RHICC\addons\data\side_rhicc_ca.paa";
	class boat {
			displayName = "Boat";
			icon = "RHICC\addons\data\side_rhicc_ca.paa";
			class PTF_RHICC_GREEN {
				statement = "['RHICC_GREEN', 'Boat'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn RHICC Green";
            	icon = "RHICC\addons\data\side_rhicc_ca.paa"; 
				};
				class PTF_RHICC_GRAY {
				statement = "['RHICC_GRAY', 'Boat'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn RHICC Gray";
            	icon = "RHICC\addons\data\side_rhicc_ca.paa"; 
				};
		};
	};