// ---------------------------------------------------------------------------
// La Corriente group templates. Included under CfgGroups > Indep.
//
// The opposite shape from Kestrel: the cartel is LARGE and spread out. Its
// line groups run eight and nine men because it can always hire more, and
// its smallest group is two men who will never fire a shot -- the lookouts.
// ---------------------------------------------------------------------------

class PTF_IND_Corriente
{
   name = "La Corriente";

   class Infantry
   {
      name = "Gunmen";
      aliveCategory = "Infantry";

      // Two men, a phone and a view of the road. The most common cartel
      // contact in the campaign, and the one the players must decide what
      // to do about -- they are not declared hostile, and shooting them
      // tells every town nearby exactly who did.
      class PTF_grp_Corr_halcones
      {
         name = "Lookout Post";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 1.0;
         icon = "\A3\ui_f\data\map\markers\nato\n_installation.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_halcon"; rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_halcon"; rank = "PRIVATE";  position[] = {-5, 0, 0}; };
      };

      class PTF_grp_Corr_patrulla
      {
         name = "Cartel Patrol";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.8;
         icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_jefe";            rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_miliciano";       rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_miliciano_akms";  rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_fusilero";        rank = "PRIVATE";  position[] = {10, -5, 0}; };
         class Unit4 { side = 2; vehicle = "PTF_Corr_tirador";         rank = "PRIVATE";  position[] = {-10, -5, 0}; };
      };

      // The cartel's line squad: nine men, a belt-fed gun and a rocket.
      // Large on purpose -- see the header.
      class PTF_grp_Corr_seccion
      {
         name = "Cartel Section";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_jefe";            rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_miliciano";       rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_miliciano";       rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_miliciano_akms";  rank = "PRIVATE";  position[] = {10, -5, 0}; };
         class Unit4 { side = 2; vehicle = "PTF_Corr_fusilero";        rank = "PRIVATE";  position[] = {-10, -5, 0}; };
         class Unit5 { side = 2; vehicle = "PTF_Corr_granadero";       rank = "PRIVATE";  position[] = {15, -10, 0}; };
         class Unit6 { side = 2; vehicle = "PTF_Corr_ametrallador";    rank = "CORPORAL"; position[] = {-15, -10, 0}; };
         class Unit7 { side = 2; vehicle = "PTF_Corr_rpg";             rank = "PRIVATE";  position[] = {20, -15, 0}; };
         class Unit8 { side = 2; vehicle = "PTF_Corr_sanitario";       rank = "PRIVATE";  position[] = {-20, -15, 0}; };
      };

      // The quadcopter and the men who keep anyone from walking up to its
      // operator. Kill the drone and the cartel knows where you are; kill
      // the operator and it stops knowing.
      class PTF_grp_Corr_drones
      {
         name = "Drone Team";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\n_uav.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_dronero";   rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_miliciano"; rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_halcon";    rank = "PRIVATE";  position[] = {5, 0, 0}; };
      };

      // Ten men in a village that changed hands last month and will change
      // hands again. The biggest group in the campaign on purpose: the
      // cartel's answer to every problem is more men, and a garrison this
      // size is why the NAC holds "little more than the coast".
      class PTF_grp_Corr_guarnicion
      {
         name = "Village Garrison";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_jefe";            rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_sicario";         rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_miliciano";       rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_miliciano";       rank = "PRIVATE";  position[] = {10, -5, 0}; };
         class Unit4 { side = 2; vehicle = "PTF_Corr_miliciano_akms";  rank = "PRIVATE";  position[] = {-10, -5, 0}; };
         class Unit5 { side = 2; vehicle = "PTF_Corr_fusilero";        rank = "PRIVATE";  position[] = {15, -10, 0}; };
         class Unit6 { side = 2; vehicle = "PTF_Corr_ametrallador";    rank = "PRIVATE";  position[] = {-15, -10, 0}; };
         class Unit7 { side = 2; vehicle = "PTF_Corr_sanitario";       rank = "PRIVATE";  position[] = {20, -15, 0}; };
         class Unit8 { side = 2; vehicle = "PTF_Corr_halcon";          rank = "PRIVATE";  position[] = {-20, -15, 0}; };
         class Unit9 { side = 2; vehicle = "PTF_Corr_halcon";          rank = "PRIVATE";  position[] = {25, -20, 0}; };
      };

      // Kestrel's training, walking. Four men who move like a unit because
      // someone was paid to make them one -- the cartel's only group with no
      // lookout attached, because a sicario cell is not sent to watch.
      class PTF_grp_Corr_sicarios
      {
         name = "Sicario Cell";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\n_recon.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_sicario"; rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_sicario"; rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_sicario"; rank = "CORPORAL"; position[] = {5, 0, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_sicario"; rank = "CORPORAL"; position[] = {10, -5, 0}; };
      };

      // The river boss walks his docks with hired guns, not soldiers. The
      // deck's second priority intelligence requirement, standing on a pier.
      class PTF_grp_Corr_hvt_patron
      {
         name = "HVT - River Boss and Guards";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\n_hq.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_patron";   rank = "COLONEL";  position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_sicario";  rank = "SERGEANT"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_lanchero"; rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_lanchero"; rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };

      // The one named box on the org chart, and never far from his men.
      class PTF_grp_Corr_hvt_detail
      {
         name = "HVT - Machete and Escort";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\n_hq.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_machete";        rank = "COLONEL";  position[] = {0, 5, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_jefe";           rank = "SERGEANT"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_miliciano_akms"; rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_ametrallador";   rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };
   };

   class Support
   {
      name = "Checkpoints";
      aliveCategory = "Support";

      // "Bridges: few, and all are checkpointed." One gun covering the span,
      // a boss to decide who pays, and a lookout who saw the players before
      // the players saw the bridge.
      class PTF_grp_Corr_reten
      {
         name = "River Checkpoint";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\n_installation.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_dshkm";          rank = "CORPORAL"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_jefe";           rank = "SERGEANT"; position[] = {-5, -10, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_miliciano";      rank = "PRIVATE";  position[] = {5, -10, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_miliciano_akms"; rank = "PRIVATE";  position[] = {10, -15, 0}; };
         class Unit4 { side = 2; vehicle = "PTF_Corr_halcon";         rank = "PRIVATE";  position[] = {-10, -15, 0}; };
      };

      // The same idea on a road out of the gray zone: a truck parked
      // sideways, a gun behind it, and a man whose only job is to phone
      // ahead about whoever turns around.
      class PTF_grp_Corr_reten_carretera
      {
         name = "Road Checkpoint";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\n_installation.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_technical";      rank = "CORPORAL"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_jefe";           rank = "SERGEANT"; position[] = {-5, -10, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_miliciano";      rank = "PRIVATE";  position[] = {5, -10, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_fusilero";       rank = "PRIVATE";  position[] = {10, -15, 0}; };
         class Unit4 { side = 2; vehicle = "PTF_Corr_halcon";         rank = "PRIVATE";  position[] = {-10, -15, 0}; };
      };

      // What a crossing looks like when the cartel expects the NAC to try
      // and take it back: the DShKM for the road, the SPG-9 for whatever
      // the road brings.
      class PTF_grp_Corr_defensa_cruce
      {
         name = "Crossing Defence (SPG-9)";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\n_installation.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_spg9";          rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_dshkm";         rank = "CORPORAL"; position[] = {-15, 0, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_sicario";       rank = "CORPORAL"; position[] = {-5, -10, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_miliciano";     rank = "PRIVATE";  position[] = {5, -10, 0}; };
         class Unit4 { side = 2; vehicle = "PTF_Corr_ametrallador";  rank = "PRIVATE";  position[] = {10, -15, 0}; };
      };

      // One tube and the men to feed it. Where this appears, the cartel is
      // not defending -- it is softening something up.
      class PTF_grp_Corr_mortero
      {
         name = "Mortar Team (2B14)";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\n_mortar.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_2b14";      rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_jefe";      rank = "CORPORAL"; position[] = {-5, -10, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_miliciano"; rank = "PRIVATE";  position[] = {5, -10, 0}; };
         class Unit3 { side = 2; vehicle = "PTF_Corr_miliciano"; rank = "PRIVATE";  position[] = {10, -15, 0}; };
      };
   };

   class Motorized
   {
      name = "Roads and Rivers";
      aliveCategory = "Motorized";

      class PTF_grp_Corr_technical
      {
         name = "Technical Patrol";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\n_motor_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_technical"; rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_jefe";      rank = "CORPORAL"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_miliciano"; rank = "PRIVATE";  position[] = {10, -10, 0}; };
      };

      class PTF_grp_Corr_gun_truck
      {
         name = "Gun Truck (SPG-9)";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\n_motor_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_technical_at"; rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_miliciano";    rank = "PRIVATE";  position[] = {-10, -10, 0}; };
      };

      // Two hulls because the deck says the rivers belong to the cartel,
      // and one boat is a sighting where two are a statement.
      class PTF_grp_Corr_rio
      {
         name = "River Patrol";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\n_naval.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_lancha"; rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_bote";   rank = "PRIVATE";  position[] = {-15, -15, 0}; };
      };

      // Product going downriver: the cargo in the slow hulls, the guns in
      // the fast one. Stopping this is how the players make the cartel
      // start a conversation.
      class PTF_grp_Corr_convoy_rio
      {
         name = "River Convoy";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\n_naval.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_bote";   rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_canoe";  rank = "PRIVATE";  position[] = {-15, -15, 0}; };
         class Unit2 { side = 2; vehicle = "PTF_Corr_lancha"; rank = "CORPORAL"; position[] = {15, -25, 0}; };
      };

      // The fuel run every boat on the river depends on. An escort of one
      // technical, because two would say the van matters.
      class PTF_grp_Corr_combustible
      {
         name = "Fuel Run";
         faction = "PTF_IND_Corriente";
         side = 2;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\n_motor_inf.paa";
         class Unit0 { side = 2; vehicle = "PTF_Corr_van_fuel";  rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 2; vehicle = "PTF_Corr_technical"; rank = "CORPORAL"; position[] = {-18, -15, 0}; };
      };
   };
};
