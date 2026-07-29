// ---------------------------------------------------------------------------
// Los Perenos group templates.
//
// Included by config.cpp inside class CfgGroups > class East. Without these
// the faction is invisible to Zeus's group list, the AI spawn modules and
// ALiVE, and mission makers have to hand-place every unit.
//
// Group composition carries the same intent as the unit configs: the rifle
// squad is built around one FN MAG and one RPG, the checkpoint detail is
// mostly sentries with a single NCO holding it together, and every group has
// exactly one leader worth killing.
// ---------------------------------------------------------------------------

class PTF_OPFOR_Perenos
{
   name = "BI-7 ""Pera"" (los Perenos)";

   class Infantry
   {
      name = "Infanteria";
      aliveCategory = "Infantry";

      class PTF_grp_Pereno_squad
      {
         name = "Escuadra de Fusileros";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.8;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_squadleader";          rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_teamleader";           rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_machinegunner";        rank = "PRIVATE";  position[] = {-10, -5, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_machinegunner_assist"; rank = "PRIVATE";  position[] = {-15, -5, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_grenadier";            rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Pereno_at";                   rank = "PRIVATE";  position[] = {10, -5, 0}; };
         class Unit6 { side = 0; vehicle = "PTF_Pereno_rifleman";             rank = "PRIVATE";  position[] = {15, -5, 0}; };
         class Unit7 { side = 0; vehicle = "PTF_Pereno_rifleman_akm";         rank = "PRIVATE";  position[] = {20, -10, 0}; };
         class Unit8 { side = 0; vehicle = "PTF_Pereno_conscript";            rank = "PRIVATE";  position[] = {25, -10, 0}; };
      };

      class PTF_grp_Pereno_fireteam
      {
         name = "Equipo de Fuego";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.9;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_teamleader";    rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_machinegunner"; rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_rifleman";      rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_conscript";     rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };

      // The signature Pereno group: set up properly, then stopped paying
      // attention. Three sentries and one corporal doing all the work.
      class PTF_grp_Pereno_checkpoint
      {
         name = "Puesto de Control";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 1.0;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_teamleader"; rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_sentry";     rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_sentry";     rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_sentry";     rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };

      class PTF_grp_Pereno_patrol
      {
         name = "Patrulla a Pie";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 1.0;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_teamleader"; rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_rifleman";   rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_conscript";  rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_conscript";  rank = "PRIVATE";  position[] = {10, -5, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_conscript";  rank = "PRIVATE";  position[] = {15, -5, 0}; };
      };

      class PTF_grp_Pereno_mg_team
      {
         name = "Equipo de Ametralladora";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.6;
         icon = "\A3\ui_f\data\map\markers\nato\o_support.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_teamleader";           rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_machinegunner";        rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_machinegunner_assist"; rank = "PRIVATE";  position[] = {5, 0, 0}; };
      };

      class PTF_grp_Pereno_at_team
      {
         name = "Equipo Contracarro";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\o_support.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_teamleader"; rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_at";         rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_at";         rank = "PRIVATE";  position[] = {5, 0, 0}; };
      };

      class PTF_grp_Pereno_mortar_crew
      {
         name = "Equipo de Mortero";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_mortar.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_2b14";       rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_teamleader"; rank = "CORPORAL"; position[] = {-5, -5, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_rifleman";   rank = "PRIVATE";  position[] = {5, -5, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_conscript";  rank = "PRIVATE";  position[] = {10, -10, 0}; };
      };

      // The battalion commander and the men who die for him. Place at a
      // headquarters and give the players a reason to come.
      class PTF_grp_Pereno_hvt_detail
      {
         name = "HVT - Comandante y Escolta";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_hvt";         rank = "COLONEL";  position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_squadleader"; rank = "SERGEANT"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_rifleman";    rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_rifleman";    rank = "PRIVATE";  position[] = {10, -5, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_machinegunner"; rank = "PRIVATE"; position[] = {-10, -5, 0}; };
      };

      class PTF_grp_Pereno_command
      {
         name = "Plana Mayor";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_officer";     rank = "LIEUTENANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_squadleader"; rank = "SERGEANT";   position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_medic";       rank = "CORPORAL";   position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_rifleman";    rank = "PRIVATE";    position[] = {10, -5, 0}; };
      };
   };

   class Motorized
   {
      name = "Motorizada";
      aliveCategory = "Motorized";

      class PTF_grp_Pereno_uaz_patrol
      {
         name = "Patrulla Motorizada (UAZ)";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.8;
         icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_uaz_open";    rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_teamleader";  rank = "CORPORAL"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_rifleman";    rank = "PRIVATE";  position[] = {10, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_conscript";   rank = "PRIVATE";  position[] = {5, -15, 0}; };
      };

      class PTF_grp_Pereno_technical
      {
         name = "Technical (DShKM)";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.6;
         icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_uaz_dshkm";  rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_teamleader"; rank = "CORPORAL"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_rifleman";   rank = "PRIVATE";  position[] = {10, -10, 0}; };
      };

      class PTF_grp_Pereno_truck_squad
      {
         name = "Escuadra en Camion";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_ural";                 rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_squadleader";          rank = "SERGEANT"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_teamleader";           rank = "CORPORAL"; position[] = {-15, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_machinegunner";        rank = "PRIVATE";  position[] = {10, -10, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_machinegunner_assist"; rank = "PRIVATE";  position[] = {15, -10, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Pereno_grenadier";            rank = "PRIVATE";  position[] = {5, -15, 0}; };
         class Unit6 { side = 0; vehicle = "PTF_Pereno_at";                   rank = "PRIVATE";  position[] = {20, -15, 0}; };
         class Unit7 { side = 0; vehicle = "PTF_Pereno_rifleman";             rank = "PRIVATE";  position[] = {25, -15, 0}; };
         class Unit8 { side = 0; vehicle = "PTF_Pereno_conscript";            rank = "PRIVATE";  position[] = {30, -20, 0}; };
      };

      // The garrison's supply run: cargo, ammo and fuel with one UAZ riding
      // shotgun. Slow, predictable and worth ambushing.
      class PTF_grp_Pereno_logistics_convoy
      {
         name = "Convoy Logistico";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_zil131";     rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_gaz66_ammo"; rank = "PRIVATE";  position[] = {0, -15, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_kraz_fuel";  rank = "PRIVATE";  position[] = {0, -30, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_uaz_open";   rank = "CORPORAL"; position[] = {0, -45, 0}; };
      };
   };

   class Mechanized
   {
      name = "Blindada";
      aliveCategory = "Mechanized";

      class PTF_grp_Pereno_brdm_recon
      {
         name = "Reconocimiento (BRDM-2)";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_brdm2";      rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_teamleader"; rank = "CORPORAL"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_rifleman";   rank = "PRIVATE";  position[] = {10, -10, 0}; };
      };

      class PTF_grp_Pereno_m113_section
      {
         name = "Seccion Mecanizada (M113)";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_m113_m2";              rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_squadleader";          rank = "SERGEANT"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_teamleader";           rank = "CORPORAL"; position[] = {-15, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_machinegunner";        rank = "PRIVATE";  position[] = {10, -10, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_machinegunner_assist"; rank = "PRIVATE";  position[] = {15, -10, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Pereno_at";                   rank = "PRIVATE";  position[] = {5, -15, 0}; };
         class Unit6 { side = 0; vehicle = "PTF_Pereno_rifleman";             rank = "PRIVATE";  position[] = {20, -15, 0}; };
      };
   };

   // The garrison's air defence is guns only -- no missiles. Anything that
   // locks and launches on the island belongs to Kestrel, and the difference
   // is meant to be felt from the cockpit.
   class Support
   {
      name = "Apoyo";
      aliveCategory = "Support";

      class PTF_grp_Pereno_zu23_section
      {
         name = "Seccion AA (ZU-23)";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_zu23";       rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_zu23";       rank = "CORPORAL"; position[] = {-15, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_teamleader"; rank = "CORPORAL"; position[] = {-5, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_conscript";  rank = "PRIVATE";  position[] = {5, -10, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_conscript";  rank = "PRIVATE";  position[] = {10, -15, 0}; };
      };

      class PTF_grp_Pereno_aa_mobile
      {
         name = "AA Movil (Ural ZU-23)";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_ural_zu23";  rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_gaz66_zu23"; rank = "CORPORAL"; position[] = {0, -15, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_teamleader"; rank = "CORPORAL"; position[] = {-10, -10, 0}; };
      };
   
      // Two guns, one battery, and the men the battalion trusts to serve
      // them. Counter-battery is a player problem now.
      class PTF_grp_Pereno_d30_battery
      {
         name = "Bateria de Obuses (D-30)";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\o_art.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_d30";        rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_d30";        rank = "CORPORAL"; position[] = {25, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_teamleader"; rank = "CORPORAL"; position[] = {10, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_conscript";  rank = "PRIVATE";  position[] = {5, -15, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_conscript";  rank = "PRIVATE";  position[] = {15, -15, 0}; };
      };
   };
};
