class PTF_Forklift {
    displayName = "Airfield Logistics";
    condition = "_target getVariable ['ForkLiftSpawnable', false]";
    distance = 1.5;
    enableInside = 1;
    icon = "\Peral_Airfield_Logistics\Data\UI\AS32A_35_icon_ca.paa";
    class Forklift {
        displayName = "Forklift";
        icon = "";
        class PTF_Atlas {
            statement = "['PTF_Atlas', 'Forklift'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn ATLAS Heavy Forklift";
            icon = ""; 
        };
        class PTF_Kalmar {
            statement = "['PTF_Kalmar', 'Forklift'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn Kalmar Forklift";
            icon = ""; 
        };
        class PTF_PalletJack {
            statement = "['PTF_Tools_PalletJack', 'Forklift'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn PalletJack";
            icon = ""; 
        };
    };
	class Misc {
        displayName = "Miscellaneous";
        icon = "";
        class LightGenerator {
            statement = "['light_generator', 'Forklift'] call PTF_fnc_SpawnFunction";
            displayName = "Light Tower Generator";
            icon = "\Peral_Airfield_Logistics\Data\UI\light_generator_icon_ca.paa"; 
        };
    };
    class Tow {
        displayName = "Towing";
        icon = "";
        class AS32A_Tractor {
            statement = "['Peral_AS32A', 'Forklift'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn A/S32A Deck Tow Tractor";
            icon = "\Peral_Airfield_Logistics\Data\UI\AS32A_icon_ca.paa"; 
        };
		class AS32A_35_Crane {
            statement = "['Peral_AS32A_35', 'Forklift'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn A/S32A-35 Deck Crane";
            icon = "\Peral_Airfield_Logistics\Data\UI\AS32A_35_icon_ca.paa"; 
        };
        class B600_Tractor {
            statement = "['Peral_B600', 'Forklift'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn B-600 Airfield Tow Tractor";
            icon = "\Peral_Airfield_Logistics\Data\UI\B600_icon_ca.paa"; 
        };
        class Helidolly16 {
            statement = "['Peral_Helidolly_16x16', 'Forklift'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn Helidolly";
            icon = "\Peral_Airfield_Logistics\Data\UI\Helidolly_icon_ca.paa"; 
        };
    };
};
