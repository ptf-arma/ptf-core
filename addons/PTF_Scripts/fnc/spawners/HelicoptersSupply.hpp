class PTF_Helicopters_Supply {
    displayName = "Supply";
    condition = "_target getVariable ['SupplyHelicoptersSpawnable', false]";    
    distance = 1.5;
    enableInside = 1;
    icon = "a3\air_f_heli\heli_transport_04\data\ui\map_heli_transport_04_box_ca.paa";
        class 53Cargo {
        	statement = "['PTF_CH53_CARGO', 'Cargo'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn CH-53E (Cargo)";
            icon = "rhsusf\addons\rhsusf_ch53\data\ui\ch53_picture_ca.paa";
            };
		class V22Cargo {
        	statement = "['PTF_MV22_Cargo', 'Cargo'] call PTF_fnc_SpawnFunction";
        	displayName = "Spawn MV-22 (Cargo)";
        	icon = "dega_vehicles_v22\data\ui\icon_mv22_ca.paa";
        	};
};