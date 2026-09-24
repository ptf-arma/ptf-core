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
   };
};
