// ---------------------------------------------------------------------------
// Kestrel Group templates.
//
// The smallest groups in the campaign, deliberately. There are ~50 Kestrel on
// the island and they are not paid to hold ground in depth -- a Kestrel
// contact should be four very good men, not a section. The largest group here
// is six, and it is the site-defence group for the airfield.
//
// Compare: los Perenos field nine-man squads and lose them; La Guardia field
// eight to ten and mean it; Kestrel field four and expect to leave.
// ---------------------------------------------------------------------------

class PTF_OPFOR_Kestrel
{
   name = "Kestrel Group";

   class Infantry
   {
      name = "Contractors";
      aliveCategory = "Infantry";

      class PTF_grp_Kestrel_team
      {
         name = "Kestrel Team";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.6;
         icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_teamleader";      rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_machinegunner";   rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_operator_dpm";    rank = "CORPORAL"; position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Kestrel_operator_lizard"; rank = "CORPORAL"; position[] = {10, -5, 0}; };
      };

      class PTF_grp_Kestrel_sniper_pair
      {
         name = "Kestrel Sniper Pair";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_sniper";   rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_marksman"; rank = "CORPORAL"; position[] = {-5, 0, 0}; };
      };

      // For the airfield and the shipments. Two men and a rifle that ends
      // vehicles.
      class PTF_grp_Kestrel_interdiction
      {
         name = "Kestrel Interdiction Team";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_antimateriel"; rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_operator";     rank = "CORPORAL"; position[] = {-5, 0, 0}; };
      };

      class PTF_grp_Kestrel_site_defence
      {
         name = "Kestrel Site Defence";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_teamleader";       rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_machinegunner";    rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_marksman";         rank = "CORPORAL"; position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Kestrel_operator_desert";  rank = "CORPORAL"; position[] = {10, -5, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Kestrel_operator_dpm";     rank = "CORPORAL"; position[] = {15, -5, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Kestrel_medic";            rank = "CORPORAL"; position[] = {20, -10, 0}; };
      };

      // The contract manager and his close protection. Killing him does not
      // end the contract -- but the paperwork he carries might.
      class PTF_grp_Kestrel_hvt_detail
      {
         name = "HVT - Contract Manager + PSD";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_hvt";          rank = "COLONEL";  position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_teamleader";   rank = "SERGEANT"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_operator_dpm"; rank = "CORPORAL"; position[] = {5, 0, 0}; };
      };

      class PTF_grp_Kestrel_command
      {
         name = "Kestrel Site Command";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_commander"; rank = "COLONEL";  position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_operator";  rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_breacher";  rank = "CORPORAL"; position[] = {5, 0, 0}; };
      };
   };

   // --- The layer that matters ---------------------------------------------

   class Support
   {
      name = "Defensa Aerea";
      aliveCategory = "Support";

      class PTF_grp_Kestrel_manpads_stinger
      {
         name = "MANPADS Team (FIM-92)";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_aa_stinger"; rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_aa_stinger"; rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_operator";   rank = "CORPORAL"; position[] = {5, 0, 0}; };
      };

      class PTF_grp_Kestrel_manpads_igla
      {
         name = "MANPADS Team (Igla)";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_aa_igla";  rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_aa_igla";  rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_operator";  rank = "CORPORAL"; position[] = {5, 0, 0}; };
      };

      // A gun, a launcher and the men who service them. This is what an
      // airfield approach costs.
      class PTF_grp_Kestrel_aa_battery
      {
         name = "Bateria AA (ZU-23-2 / Igla)";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_zu23";       rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_igla_pod";   rank = "CORPORAL"; position[] = {-15, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_teamleader"; rank = "SERGEANT"; position[] = {-5, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Kestrel_aa_stinger"; rank = "CORPORAL"; position[] = {5, -10, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Kestrel_operator";   rank = "CORPORAL"; position[] = {10, -15, 0}; };
      };

      // The radar site the campaign is meant to attack -- crewed, defended,
      // and worth a mission on its own.
      class PTF_grp_Kestrel_radar_site
      {
         name = "Air Search Site (P-37)";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_p37";             rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_stinger_pod";     rank = "CORPORAL"; position[] = {-15, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_teamleader";      rank = "SERGEANT"; position[] = {-5, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Kestrel_operator";        rank = "CORPORAL"; position[] = {5, -10, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Kestrel_operator_desert"; rank = "CORPORAL"; position[] = {10, -15, 0}; };
      };

      class PTF_grp_Kestrel_manpads_mobile
      {
         name = "MANPADS Overwatch (MRZR)";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_mrzr";         rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_aa_stinger";   rank = "CORPORAL"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_operator_dpm"; rank = "CORPORAL"; position[] = {10, -10, 0}; };
      };
   };

   class Motorized
   {
      name = "Motorized";
      aliveCategory = "Motorized";

      class PTF_grp_Kestrel_patrol
      {
         name = "Kestrel Vehicle Patrol";
         faction = "PTF_OPFOR_Kestrel";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Kestrel_m1025_m2";     rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Kestrel_teamleader";   rank = "SERGEANT"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Kestrel_operator_dpm"; rank = "CORPORAL"; position[] = {10, -10, 0}; };
      };
   };
};
