class PTF_Vic {
    displayName = "Vics";
    condition = "_target distance (nearestObject [_target ,""Land_helipadRescue_F""]) < 30";
    distance = 1.5;
    enableInside = 1;
    icon = "";
        class Hummve {
            displayName = "Hummves";
            icon = "";
				class PTF_50_Hummve {
				statement = "createVehicle [""PTF_M1151_M2"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn 50 Hummve";
            	icon = ""; 
				};
				class PTF_MK19_Hummve {
				statement = "createVehicle [""PTF_M1151_MK19"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn MK19 Hummve";
            	icon = "";
				};
				class PTF_M240_Hummve {
				statement = "createVehicle [""PTF_M1151_M240"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn 240 Hummve";
            	icon = "";
				};
				class PTF_Unarmed_Hummve {
				statement = "createVehicle [""Y"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn Unarmed Hummve";
            	icon = "";
				};
            };
		class Cat {
			displayName = "CAT";
			icon = "";
				class PTF_Cat50_Hummve {
				statement = "createVehicle [""PTF_M1151CAT_M2"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn 50 Hummve";
            	icon = "";
				};
				class PTF_CatMK19_Hummve {
				statement = "createVehicle [""PTF_M1151CAT_MK19"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn MK19 Hummve";
            	icon = ""; 
				};
				class PTF_Tow_Hummve {
				statement = "createVehicle [""PTF_M1025_tow"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn Tow Hummve";
            	icon = ""; 
				};
			};
		class Mrap {
			displayName = "MRAP";
			icon = "";
				class PTF_50_MRAP {
				statement = "createVehicle [""PTF_MRAP_M1232_M2"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn 50 MRAP";
            	icon = "";
				};
				class PTF_MK19_MRAP {
				statement = "createVehicle [""PTF_MRAP_M1232_MK19"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn MK19 MRAP";
            	icon = ""; 
				};
		};
		class Cougar {
			displayName = "Cougar";
			icon = "";
				class PTF_50_Cougar {
				statement = "createVehicle [""PTF_MRAP_CGRCAT1A2_M2"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn 50 MRAP";
            	icon = ""; 
				};
				class PTF_MK19_Cougar {
				statement = "createVehicle [""PTF_MRAP_CGRCAT1A2_MK19"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn MK19 MRAP";
            	icon = ""; 
				};
			};
		class Air {
			displayName = "Air";
			icon = "";
				class PTF_Atlas {
				statement = "createVehicle [""boxloader_atlas"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn Atlas";
            	icon = ""; 
				};
				class PTF_Kalmar {
				statement = "createVehicle [""boxloader_kalmar"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn Kalmar";
            	icon = ""; 
				};
				class PTF_PalletJack {
				statement = "createVehicle [""PTF_Tools_PalletJack"", getPosATL (nearestObject [_player,""Land_helipadRescue_F""])]";
            	displayName = "Spawn PalletJack";
            	icon = ""; 
				};
			};
		};