class PTF_Cougar {
    displayName = "Cougar";
    condition = "_target getVariable ['CougarSpawnable', false]";
    distance = 1.5;
    enableInside = 1;
    icon = "rhsusf\addons\rhsusf_cougar\pictures\rhs_cgrcat1a2_armed_pic_ca.paa";
	class Cougar {
			displayName = "Cougar";
			icon = "rhsusf\addons\rhsusf_cougar\pictures\rhs_cgrcat1a2_armed_pic_ca.paa";
				class PTF_50_Cougar {
				statement = "['PTF_MRAP_CGRCAT1A2_M2', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn 50 MRAP";
            	icon = "rhsusf\addons\rhsusf_cougar\pictures\rhs_cgrcat1a2_armed_pic_ca.paa"; 
				};
				class PTF_MK19_Cougar {
				statement = "['PTF_MRAP_CGRCAT1A2_MK19', 'Vic'] call PTF_fnc_SpawnFunction";
            	displayName = "Spawn MK19 MRAP";
            	icon = "rhsusf\addons\rhsusf_cougar\pictures\rhs_cgrcat1a2_armed_pic_ca.paa"; 
				};
			};
	};
