class PTF_Forklift {
    displayName = "Forklift";
    condition = "_target getVariable ['ForkLiftSpawnable', false]";
    distance = 1.5;
    enableInside = 1;
    icon = "";
	class Forklift {
			displayName = "Forklift";
			icon = "";
				class PTF_Atlas {
				statement = "['boxloader_atlas', 'Forklift'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Atlas";
            	icon = ""; 
				};
				class PTF_Kalmar {
				statement = "['boxloader_kalmar', 'Forklift'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Kalmar";
            	icon = ""; 
				};
				class PTF_PalletJack {
				statement = "['PTF_Tools_PalletJack', 'Forklift'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn PalletJack";
            	icon = ""; 
				};
			};
	};