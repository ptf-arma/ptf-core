class PTF_Supplys {
    displayName = "Supplys";
	condition = "_target getVariable ['SupplysSpawnable', false]";
	distance = 1.5;
    enableInside = 1;
    icon = "a3\weapons_f\ammoboxes\data\ui\map_ammobox_f_ca.paa";
        class Small {
            displayName = "Small Supplys";
            icon = "a3\weapons_f\ammoboxes\data\ui\map_wpnsbox_long_f_ca.paa";
				class PTF_SAmmo {
				statement = "['PTF_Cargo_Small_Ammo', 'SmSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Small Ammo";
            	icon = "\z\PTF\addons\PTF_Textures\Icons\Ammobox.paa"; 
				};
				class PTF_SMed {
				statement = "['PTF_Cargo_Small_Medical', 'SmSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Small Medical";
            	icon = "\z\PTF\addons\PTF_Textures\Icons\MedBox.paa";
				};
				class PTF_SLauncher {
				statement = "['PTF_Cargo_Small_Launcher', 'SmSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Small Launcher";
            	icon = "\z\PTF\addons\PTF_Textures\Icons\Launcher.paa";
				};
				class PTF_SExplosives {
				statement = "['PTF_Cargo_Small_Explosives', 'SmSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Small Explosives";
            	icon = "a3\weapons_f\ammoboxes\data\ui\map_grenades_f_ca.paa";
				};
				class PTF_SHumanitarian {
				statement = "['PTF_Cargo_Small_Humanitarian', 'SmSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Small Humanitarian";
            	icon = "a3\supplies_f_exp\ammoboxes\data\ui\icon_uniforms_box_ca.paa";
				};
				class PTF_Mortar {
				statement = "['PTF_Cargo_Mortar', 'SmSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Small Mortar";
            	icon = "\z\PTF\addons\PTF_Textures\Icons\Mortar.paa";
				};
				class PTF_SVic {
				statement = "['PTF_Cargo_Vic', 'SmSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Small VicBox";
            	icon = "a3\supplies_f_exp\ammoboxes\data\ui\icon_equipment_box_ca.paa";
				};
            };
			class Large {
            displayName = "Large Supplys";
            icon = "a3\weapons_f\ammoboxes\data\ui\map_wpnsbox_large_f_ca.paa";
				class PTF_Ammo {
				statement = "['PTF_Cargo_Large_Ammo', 'LgSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Ammo";
            	icon = "\z\PTF\addons\PTF_Textures\Icons\Ammobox.paa"; 
				};
				class PTF_Med {
				statement = "['PTF_Cargo_Large_Medical', 'LgSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Medical";
            	icon = "\z\PTF\addons\PTF_Textures\Icons\MedBox.paa"; 
				};
				class PTF_Launcher {
				statement = "['PTF_Cargo_Large_Launcher', 'LgSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Launcher";
            	icon = "\z\PTF\addons\PTF_Textures\Icons\Launcher.paa";
				};
				class PTF_Explosives {
				statement = "['PTF_Cargo_Large_Explosives', 'LgSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Explosives";
            	icon = "a3\weapons_f\ammoboxes\data\ui\map_grenades_f_ca.paa";
				};
				class PTF_Vic {
				statement = "['PTF_Cargo_Large_VicBox', 'LgSupplys'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn VicBox";
            	icon = "a3\supplies_f_exp\ammoboxes\data\ui\icon_equipment_box_ca.paa";
				};
            };
			class Other {
			displayName = "Other";
			icon = "a3\weapons_f\ammoboxes\data\ui\map_ammoveh_f_ca.paa";
				class PTF_VicAmmo {
				statement = "['Box_NATO_AmmoVeh_f', 'Other'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Vic Ammo";
            	icon = "a3\weapons_f\ammoboxes\data\ui\map_ammoveh_f_ca.paa";
				};
				class PTF_FuelWD {
				statement = "['FlexibleTank_01_forest_F', 'Other'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Fuel (WD)";
            	icon = "ca\ui\data\icon_mission_refuel_ca.paa";
				};
				class PTF_FuelS {
				statement = "['FlexibleTank_01_Sand_F', 'Other'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Fuel (S)";
            	icon = "ca\ui\data\icon_mission_refuel_ca.paa";
				};
			};
};
