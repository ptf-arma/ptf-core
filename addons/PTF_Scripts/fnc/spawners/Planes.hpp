class PTF_Planes {
      displayName = "Fixed Wing";
      condition = "_target getVariable ['PlanesSpawnable', false]";
      distance = 1.5;
      enableInside = 1;
      icon = "a3\air_f_jets\plane_fighter_01\data\ui\fighter01_picture_ca.paa";
      class F35B_VIS {
            statement = "['PTF_F35B_VIS', 'Plane', 'PTF_PlaneTickets'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn F-35B (Interactive)";
            icon = "\Peral_F35B\Data\UI\F35B_icon_ca.paa";
      };
	class MQ9 {
            statement = "['PTF_MQ9_SCARFACE', 'Plane','PTF_MQ9Tickets'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn MQ-9";
            icon = "\A3\Drones_F\Air_F_Gamma\UAV_02\Data\UI\Map_UAV_02_CA.paa";
      };
      class RQ4 {
            statement = "['PTF_RQ4A', 'Plane'] call PTF_fnc_SpawnFunction";
            displayName = "Spawn RQ-4";
            icon = "\A3\Drones_F\Air_F_Gamma\UAV_02\Data\UI\Map_UAV_02_CA.paa";
      };
};
