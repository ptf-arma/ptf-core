class PTF_MRAP {
    displayName = "MRAP";
	condition = "_target getVariable ['MrapSpawnable', false]";
	distance = 1.5;
    enableInside = 1;
    icon = "rhsusf\addons\rhsusf_rg33l\pictures\rhs_rg33l_armed_pic_ca.paa";
	class Mrap {
			displayName = "MRAP";
			icon = "rhsusf\addons\rhsusf_rg33l\pictures\rhs_rg33l_armed_pic_ca.paa";
				class PTF_50_MRAP {
				statement = "['PTF_MRAP_M1232_M2', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn 50 MRAP";
            	icon = "rhsusf\addons\rhsusf_rg33l\pictures\rhs_rg33l_armed_pic_ca.paa";
				};
				class PTF_MK19_MRAP {
				statement = "['PTF_MRAP_M1232_MK19', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn MK19 MRAP";
            	icon = "rhsusf\addons\rhsusf_rg33l\pictures\rhs_rg33l_armed_pic_ca.paa"; 
				};
		};
	};
