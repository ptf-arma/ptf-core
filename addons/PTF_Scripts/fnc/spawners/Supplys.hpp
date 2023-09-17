class PTF_Supplys {
    displayName = "Supplys";
    condition = "_target distance (nearestObject [_target ,""Land_JumpTarget_f""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "a3\weapons_f\ammoboxes\data\ui\map_ammobox_f_ca.paa";
        class Small {
            displayName = "Small Supplys";
            icon = "a3\weapons_f\ammoboxes\data\ui\map_wpnsbox_long_f_ca.paa";
				class PTF_SAmmo {
				statement = "createVehicle [""PTF_Cargo_Small_Ammo"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Ammo";
            	icon = "\PTF_Textures\Icons\Ammobox.paa"; 
				};
				class PTF_SMed {
				statement = "createVehicle [""PTF_Cargo_Small_Medical"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Medical";
            	icon = "\PTF_Textures\Icons\MedBox.paa";
				};
				class PTF_SLauncher {
				statement = "createVehicle [""PTF_Cargo_Small_Launcher"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Launcher";
            	icon = "\PTF_Textures\Icons\Launcher.paa";
				};
				class PTF_SExplosives {
				statement = "createVehicle [""PTF_Cargo_Small_Explosives"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Explosives";
            	icon = "a3\weapons_f\ammoboxes\data\ui\map_grenades_f_ca.paa";
				};
				class PTF_SHumanitarian {
				statement = "createVehicle [""PTF_Cargo_Small_Humanitarian"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Humanitarian";
            	icon = "a3\supplies_f_exp\ammoboxes\data\ui\icon_uniforms_box_ca.paa";
				};
				class PTF_Mortar {
				statement = "createVehicle [""PTF_Cargo_Mortar"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Mortar";
            	icon = "\PTF_Textures\Icons\Mortar.paa";
				};
				class PTF_SVic {
				statement = "createVehicle [""PTF_Cargo_Vic"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small VicBox";
            	icon = "";
				};
            };
			class Large {
            displayName = "Large Supplys";
            icon = "a3\weapons_f\ammoboxes\data\ui\map_wpnsbox_large_f_ca.paa";
				class PTF_Ammo {
				statement = "createVehicle [""PTF_Cargo_Large_Ammo"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Ammo";
            	icon = "\PTF_Textures\Icons\Ammobox.paa"; 
				};
				class PTF_Med {
				statement = "createVehicle [""PTF_Cargo_Large_Medical"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Medical";
            	icon = "\PTF_Textures\Icons\MedBox.paa"; 
				};
				class PTF_Launcher {
				statement = "createVehicle [""PTF_Cargo_Large_Launcher"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Launcher";
            	icon = "\PTF_Textures\Icons\Launcher.paa";
				};
				class PTF_Explosives {
				statement = "createVehicle [""PTF_Cargo_Large_Explosives"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Explosives";
            	icon = "a3\weapons_f\ammoboxes\data\ui\map_grenades_f_ca.paa";
				};
				class PTF_Vic {
				statement = "createVehicle [""PTF_Cargo_Large_VicBox"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn VicBox";
            	icon = "a3\supplies_f_exp\ammoboxes\data\ui\icon_equipment_box_ca.paa";
				};
            };
			class Other {
			displayName = "Other";
			icon = "a3\weapons_f\ammoboxes\data\ui\map_ammoveh_f_ca.paa";
				class PTF_VicAmmo {
				statement = "createVehicle [""Box_NATO_AmmoVeh_f"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Vic Ammo";
            	icon = "a3\weapons_f\ammoboxes\data\ui\map_ammoveh_f_ca.paa";
				};
				class PTF_FuelWD {
				statement = "createVehicle [""FlexibleTank_01_forest_F"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Fuel (WD)";
            	icon = "ca\ui\data\icon_mission_refuel_ca.paa";
				};
				class PTF_FuelS {
				statement = "createVehicle [""FlexibleTank_01_Sand_F"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Fuel (S)";
            	icon = "ca\ui\data\icon_mission_refuel_ca.paa";
				};
			};
};
