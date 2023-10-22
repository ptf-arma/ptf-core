class PTF_Supplys {
    displayName = "Supplys";
    condition = "_target distance (nearestObject [_target ,""Land_JumpTarget_f""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "";
        class Small {
            displayName = "Small Supplys";
            icon = "";
				class PTF_SAmmo {
				statement = "createVehicle [""PTF_Cargo_Small_Ammo"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Ammo";
            	icon = ""; 
				};
				class PTF_SMed {
				statement = "createVehicle [""PTF_Cargo_Small_Medical"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Medical";
            	icon = "";
				};
				class PTF_SLauncher {
				statement = "createVehicle [""PTF_Cargo_Small_Launcher"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Launcher";
            	icon = "";
				};
				class PTF_SExplosives {
				statement = "createVehicle [""PTF_Cargo_Small_Explosives"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Explosives";
            	icon = "";
				};
				class PTF_SHumanitarian {
				statement = "createVehicle [""PTF_Cargo_Small_Humanitarian"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Humanitarian";
            	icon = "";
				};
				class PTF_Mortar {
				statement = "createVehicle [""PTF_Cargo_Mortar"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small Mortar";
            	icon = "";
				};
				class PTF_SVic {
				statement = "createVehicle [""PTF_Cargo_Vic"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Small VicBox";
            	icon = "";
				};
            };
			class Large {
            displayName = "Large Supplys";
            icon = "";
				class PTF_Ammo {
				statement = "createVehicle [""PTF_Cargo_Large_Ammo"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Ammo";
            	icon = ""; 
				};
				class PTF_Med {
				statement = "createVehicle [""PTF_Cargo_Large_Medical"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Medical";
            	icon = ""; 
				};
				class PTF_Launcher {
				statement = "createVehicle [""PTF_Cargo_Large_Launcher"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Launcher";
            	icon = "";
				};
				class PTF_Explosives {
				statement = "createVehicle [""PTF_Cargo_Large_Explosives"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Explosives";
            	icon = "";
				};
				class PTF_Vic {
				statement = "createVehicle [""PTF_Cargo_Large_VicBox"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn VicBox";
            	icon = "";
				};
            };
			class Other {
			displayName = "Other";
			icon = "";
				class PTF_VicAmmo {
				statement = "createVehicle [""Box_NATO_AmmoVeh_f"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Vic Ammo";
            	icon = "";
				};
				class PTF_FuelWD {
				statement = "createVehicle [""FlexibleTank_01_forest_F"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Fuel (WD)";
            	icon = "";
				};
				class PTF_FuelS {
				statement = "createVehicle [""FlexibleTank_01_Sand_F"", getPosATL (nearestObject [_player,""Land_JumpTarget_f""])]";
            	displayName = "Spawn Fuel (S)";
            	icon = "";
				};
			};
};
