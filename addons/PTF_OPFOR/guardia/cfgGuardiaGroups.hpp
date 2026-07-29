// ---------------------------------------------------------------------------
// La Guardia group templates.
//
// Fewer and smaller than the garrison's -- there are only ~140 of them and
// they hold two places. There is no checkpoint group here on purpose: La
// Guardia do not stand bored roadblocks, and their appearance anywhere other
// than Presa Alta or Tagua should tell the players that Bastida considers
// something important.
//
// The three assault groups form the escalation ladder the brief asks for:
//   Equipo de Asalto      -- first contact, a nasty surprise in a routine op
//   Seccion de Asalto     -- the mid-campaign standard
//   Seccion Reforzada     -- veterans throughout, by which point they should
//                            be the reason the campaign is hard
// ---------------------------------------------------------------------------

class PTF_OPFOR_Guardia
{
   name = "La Guardia (Destacamento Especial Bastida)";

   class Infantry
   {
      name = "Infanteria";
      aliveCategory = "Infantry";

      class PTF_grp_Guardia_fireteam
      {
         name = "Equipo de Asalto";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.8;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_teamleader";    rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_machinegunner"; rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_rifleman";      rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Guardia_at";            rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };

      class PTF_grp_Guardia_squad
      {
         name = "Seccion de Asalto";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.6;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_squadleader";    rank = "SERGEANT";  position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_teamleader";     rank = "CORPORAL";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_machinegunner";  rank = "PRIVATE";   position[] = {-10, -5, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Guardia_grenadier";      rank = "PRIVATE";   position[] = {5, 0, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Guardia_at";             rank = "PRIVATE";   position[] = {10, -5, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Guardia_rifleman";       rank = "PRIVATE";   position[] = {15, -5, 0}; };
         class Unit6 { side = 0; vehicle = "PTF_Guardia_rifleman_vet";   rank = "CORPORAL";  position[] = {20, -10, 0}; };
         class Unit7 { side = 0; vehicle = "PTF_Guardia_medic";          rank = "PRIVATE";   position[] = {25, -10, 0}; };
      };

      // The late-campaign version. Veterans throughout -- dual-tube night
      // vision and ranged optics on every man in the group.
      class PTF_grp_Guardia_squad_reinforced
      {
         name = "Seccion Reforzada";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_officer";        rank = "LIEUTENANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_squadleader";    rank = "SERGEANT";   position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_machinegunner";  rank = "CORPORAL";   position[] = {-10, -5, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Guardia_machinegunner";  rank = "PRIVATE";    position[] = {-15, -5, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Guardia_marksman";       rank = "CORPORAL";   position[] = {5, 0, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Guardia_at";             rank = "PRIVATE";    position[] = {10, -5, 0}; };
         class Unit6 { side = 0; vehicle = "PTF_Guardia_grenadier";      rank = "PRIVATE";    position[] = {15, -5, 0}; };
         class Unit7 { side = 0; vehicle = "PTF_Guardia_rifleman_vet";   rank = "CORPORAL";   position[] = {20, -10, 0}; };
         class Unit8 { side = 0; vehicle = "PTF_Guardia_rifleman_vet";   rank = "CORPORAL";   position[] = {25, -10, 0}; };
         class Unit9 { side = 0; vehicle = "PTF_Guardia_medic";          rank = "PRIVATE";    position[] = {30, -15, 0}; };
      };

      class PTF_grp_Guardia_sniper_team
      {
         name = "Equipo de Tiradores";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_marksman";     rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_rifleman_vet"; rank = "CORPORAL"; position[] = {-5, 0, 0}; };
      };

      class PTF_grp_Guardia_at_team
      {
         name = "Equipo Contracarro";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_support.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_teamleader"; rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_at";         rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_at";         rank = "PRIVATE";  position[] = {5, 0, 0}; };
      };

      // Night vision on every man is the whole point of this group.
      class PTF_grp_Guardia_night_patrol
      {
         name = "Patrulla Nocturna";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.6;
         icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_teamleader";   rank = "SERGEANT"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_rifleman_vet"; rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_rifleman_vet"; rank = "CORPORAL"; position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Guardia_marksman";     rank = "CORPORAL"; position[] = {10, -5, 0}; };
      };

      // Bastida's senior officer moves with veterans only.
      class PTF_grp_Guardia_hvt_detail
      {
         name = "HVT - Oficial Superior y Escolta";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_hvt";          rank = "COLONEL";  position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_rifleman_vet"; rank = "CORPORAL"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_rifleman_vet"; rank = "CORPORAL"; position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Guardia_machinegunner"; rank = "PRIVATE"; position[] = {10, -5, 0}; };
      };

      class PTF_grp_Guardia_command
      {
         name = "Destacamento de Mando";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\o_hq.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_officer";      rank = "COLONEL";  position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_squadleader";  rank = "SERGEANT"; position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_rifleman_vet"; rank = "CORPORAL"; position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Guardia_medic";        rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };
   };

   class Motorized
   {
      name = "Motorizada";
      aliveCategory = "Motorized";

      class PTF_grp_Guardia_technical_ags
      {
         name = "Technical (AGS-30)";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.6;
         icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_uaz_ags";    rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_teamleader"; rank = "CORPORAL"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_rifleman";   rank = "PRIVATE";  position[] = {10, -10, 0}; };
      };

      class PTF_grp_Guardia_technical_spg9
      {
         name = "Technical (SPG-9)";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.5;
         icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_uaz_spg9";   rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_teamleader"; rank = "CORPORAL"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_at";         rank = "PRIVATE";  position[] = {10, -10, 0}; };
      };

      // La Guardia's resupply moves with a gun truck, because Bastida's own
      // convoys are the one thing he will not let travel unescorted.
      class PTF_grp_Guardia_kamaz_convoy
      {
         name = "Convoy (KamAZ)";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_motor_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_kamaz";      rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_kamaz_ammo"; rank = "PRIVATE";  position[] = {0, -15, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_uaz_ags";    rank = "CORPORAL"; position[] = {0, -30, 0}; };
      };
   };

   class Mechanized
   {
      name = "Blindada";
      aliveCategory = "Mechanized";

      class PTF_grp_Guardia_btr_section
      {
         name = "Seccion Mecanizada (BTR-70)";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_btr70";         rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_squadleader";   rank = "SERGEANT"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_machinegunner"; rank = "CORPORAL"; position[] = {-15, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Guardia_at";            rank = "PRIVATE";  position[] = {10, -10, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Guardia_grenadier";     rank = "PRIVATE";  position[] = {15, -10, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Guardia_rifleman_vet";  rank = "CORPORAL"; position[] = {20, -15, 0}; };
      };

      // The one that changes how a fight feels.
      class PTF_grp_Guardia_bmp_section
      {
         name = "Seccion Mecanizada (BMP-2)";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\o_mech_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_bmp2";          rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_squadleader";   rank = "SERGEANT"; position[] = {-10, -10, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_machinegunner"; rank = "CORPORAL"; position[] = {-15, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Guardia_at";            rank = "PRIVATE";  position[] = {10, -10, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Guardia_rifleman_vet";  rank = "CORPORAL"; position[] = {15, -10, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Guardia_rifleman_vet";  rank = "CORPORAL"; position[] = {20, -15, 0}; };
      };
   };

   class Support
   {
      name = "Apoyo";
      aliveCategory = "Support";

      // The Shilka is the campaign's only self-propelled AA -- when it shows
      // up, the air plan changes. Its appearance should mean something.
      class PTF_grp_Guardia_aa_battery_mobile
      {
         name = "Bateria AA Movil";
         faction = "PTF_OPFOR_Guardia";
         side = 0;
         rarityGroup = 0.3;
         icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
         class Unit0 { side = 0; vehicle = "PTF_Guardia_zsu234";       rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Guardia_ural_zu23";    rank = "CORPORAL"; position[] = {0, -15, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Guardia_teamleader";   rank = "CORPORAL"; position[] = {-10, -10, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Guardia_rifleman_vet"; rank = "CORPORAL"; position[] = {10, -10, 0}; };
      };
   };
};
