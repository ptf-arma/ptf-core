// ---------------------------------------------------------------------------
// El Sindicato group templates. Included under CfgGroups > Indep.
//
// Work crews, not squads. The union fights in the numbers it works in.
// ---------------------------------------------------------------------------

class PTF_IND_Sindicato
{
   name = "El Sindicato";

   class Infantry
   {
      name = "Cuadrillas";
      aliveCategory = "Infantry";

      // A work gang that picked up its guns on the way out the gate.
      class PTF_grp_Sind_cuadrilla
      {
         name = "Cuadrilla";
         faction = "PTF_IND_Sindicato";
         side = 2;
         rarityGroup = 0.8;
         icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Sind_cabecilla";  rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Sind_miliciano";  rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Sind_maderero";   rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Sind_estibador";  rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };

      class PTF_grp_Sind_milicia
      {
         name = "Milicia del Puerto";
         faction = "PTF_IND_Sindicato";
         side = 2;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Sind_cabecilla";       rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Sind_enlace";          rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Sind_miliciano";       rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Sind_miliciano_akms";  rank = "PRIVATE";  position[] = {10, -5, 0}; };
         class Unit4 { side = 2; vehicle = "PTF_Sind_contrabandista";  rank = "PRIVATE";  position[] = {-10, -5, 0}; };
         class Unit5 { side = 2; vehicle = "PTF_Sind_cazador";         rank = "PRIVATE";  position[] = {15, -10, 0}; };
         class Unit6 { side = 2; vehicle = "PTF_Sind_sanitario";       rank = "PRIVATE";  position[] = {-15, -10, 0}; };
      };

      // Three men who watch a road the way only locals can.
      class PTF_grp_Sind_piquete
      {
         name = "Piquete";
         faction = "PTF_IND_Sindicato";
         side = 2;
         rarityGroup = 1.0;
         icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Sind_miliciano"; rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Sind_estibador"; rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Sind_cazador";   rank = "PRIVATE";  position[] = {5, 0, 0}; };
      };

      // The demolition detail. Union-audited dynamite, union-decided targets.
      class PTF_grp_Sind_demolicion
      {
         name = "Equipo de Demolicion";
         faction = "PTF_IND_Sindicato";
         side = 2;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\n_support.paa";
         class Unit0 { side = 2; vehicle = "PTF_Sind_dinamitero"; rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Sind_miliciano";  rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Sind_miliciano";  rank = "PRIVATE";  position[] = {5, 0, 0}; };
      };

      // El Capataz never travels alone, and never with fewer than two men he
      // has known for twenty years.
      class PTF_grp_Sind_hvt_detail
      {
         name = "HVT - El Capataz y Escolta";
         faction = "PTF_IND_Sindicato";
         side = 2;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\n_hq.paa";
         class Unit0 { side = 2; vehicle = "PTF_Sind_hvt";            rank = "COLONEL";  position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Sind_cabecilla";      rank = "SERGEANT"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Sind_contrabandista"; rank = "PRIVATE";  position[] = {5, 0, 0}; };
      };
   };

   class Motorized
   {
      name = "Transporte";
      aliveCategory = "Motorized";

      class PTF_grp_Sind_technical
      {
         name = "Camioneta Armada";
         faction = "PTF_IND_Sindicato";
         side = 2;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\n_motor_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Sind_technical"; rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Sind_cabecilla"; rank = "CORPORAL"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Sind_miliciano"; rank = "PRIVATE";  position[] = {10, -10, 0}; };
      };

      // The convoy that feeds half the island, and the reason nobody searches
      // the third truck.
      class PTF_grp_Sind_convoy
      {
         name = "Convoy del Sindicato";
         faction = "PTF_IND_Sindicato";
         side = 2;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\n_motor_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Sind_ural";      rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Sind_van";       rank = "PRIVATE";  position[] = {-18, -15, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Sind_ural_open"; rank = "PRIVATE";  position[] = {18, -15, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Sind_offroad";   rank = "CORPORAL"; position[] = {0, -30, 0}; };
      };
   };
};
