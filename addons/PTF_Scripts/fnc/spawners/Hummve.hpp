class PTF_Hummve {
    displayName = "Hummve";
	condition = "_target getVariable ['HummveSpawnable', false]";
	distance = 1.5;
    enableInside = 1;
    icon = "rhsusf\addons\rhsusf_m11xx\pictures\rhs_m1151_unarmed_pic_ca.paa";
        class Hummve {
            displayName = "Hummves";
            icon = "rhsusf\addons\rhsusf_m11xx\pictures\rhs_m1151_unarmed_pic_ca.paa";
				class PTF_50_Hummve {
				statement = "['PTF_M1151_M2', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn 50 Hummve";
            	icon = "rhsusf\addons\rhsusf_m11xx\pictures\rhs_m1151_ogpk_pic_ca.paa";
				};
				class PTF_MK19_Hummve {
				statement = "['PTF_M1151_MK19', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn MK19 Hummve";
            	icon = "rhsusf\addons\rhsusf_m11xx\pictures\rhs_m1151_mctags_pic_ca.paa";
				};
				class PTF_M240_Hummve {
				statement = "['PTF_M1151_M240', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn 240 Hummve";
            	icon = "rhsusf\addons\rhsusf_m11xx\pictures\rhs_m1151_gpk_pic_ca.paa";
				};
				class PTF_Unarmed_Hummve {
				statement = "['PTF_M1151', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Unarmed Hummve";
            	icon = "rhsusf\addons\rhsusf_m11xx\pictures\rhs_m1151_unarmed_pic_ca.paa";
				};
            };
		class Cat {
			displayName = "CAT";
			icon = "rhsusf\addons\rhsusf_m11xx\pictures\rhs_m1151_unarmed_pic_ca.paa";
				class PTF_Cat50_Hummve {
				statement = "['PTF_M1151CAT_M2', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn 50 Hummve";
            	icon = "rhsusf\addons\rhsusf_m11xx\pictures\rhs_m1151_ogpk_pic_ca.paa";
				};
				class PTF_CatMK19_Hummve {
				statement = "['PTF_M1151CAT_MK19', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn MK19 Hummve";
            	icon = "rhsusf\addons\rhsusf_m11xx\pictures\rhs_m1151_mctags_pic_ca.paa";
				};
				class PTF_Tow_Hummve {
				statement = "['PTF_M1025_tow', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn Tow Hummve";
            	icon = "rhsusf\addons\rhsusf_hmmwv\pictures\rhsusf_m1045_ca.paa";
				};
			};
		};
