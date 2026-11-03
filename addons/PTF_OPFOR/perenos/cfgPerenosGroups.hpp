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
//
// Mission feedback said the battalion read as short of machine guns, so the
// MAG is fielded wider now: it walks with the foot patrol, the MG section
// carries two guns, and the static gun and howitzer positions keep one for
// local defence. The checkpoint stays without one on purpose -- bored
// sentries do not get a belt-fed weapon.
//
// The surplus rifles are mixed into the standing groups rather than left in
// the editor for a mission maker to remember. A player who walks into the
// rifle squad meets four ammunition families in one nine-man group, the
// checkpoint has a grease gun on one of its three sentries, and the foot
// patrol carries the M14 marksman and an MP44 conscript. No group changed
// size: these are substitutions inside the existing establishment, because
// the battalion did not get bigger, it just got issued whatever was in the
// shed.
// ---------------------------------------------------------------------------

class PTF_OPFOR_Perenos
{
   name = "los Perenos (7th Infantry Battalion ""Pera"")";

   class Infantry
   {
      name = "Infantry";
      aliveCategory = "Infantry";

      // Four ammunition families in nine men: 7.62x51 on the cadre, the AT
      // man and the gun, 7.62x39 on the AKM and M70 riflemen, 7.92x33 Kurz
      // on the MP44 conscript, which nobody else in the group can feed, and
      // the grenadier off on his own with .45 ACP and 40mm. A squad that
      // cannot cross-load is the brief made visible.
      class PTF_grp_Pereno_squad
      {
         name = "Rifle Squad";
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
         class Unit6 { side = 0; vehicle = "PTF_Pereno_rifleman_m70b1";       rank = "PRIVATE";  position[] = {15, -5, 0}; };
         class Unit7 { side = 0; vehicle = "PTF_Pereno_rifleman_akm";         rank = "PRIVATE";  position[] = {20, -10, 0}; };
         class Unit8 { side = 0; vehicle = "PTF_Pereno_conscript_mp44";       rank = "PRIVATE";  position[] = {25, -10, 0}; };
      };

      class PTF_grp_Pereno_fireteam
      {
         name = "Fire Team";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.9;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_teamleader";     rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_machinegunner";  rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         // The corporal is on 7.62x51 and this man on 7.62x39. Four men and
         // already they cannot share a magazine.
         class Unit2 { side = 0; vehicle = "PTF_Pereno_rifleman_m70";   rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_conscript";      rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };

      // The signature Pereno group: set up properly, then stopped paying
      // attention. Three sentries and one corporal doing all the work.
      class PTF_grp_Pereno_checkpoint
      {
         name = "Checkpoint";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 1.0;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_teamleader";  rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_sentry";      rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         // One grease gun on the gate. It is a hundred-metre weapon on a
         // hundred-metre job, and it is the first thing a player notices is
         // not a rifle.
         class Unit2 { side = 0; vehicle = "PTF_Pereno_sentry_m3a1"; rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_sentry";      rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };

      // Five men walking out is enough to justify carrying the MAG -- the
      // rifleman slot holds the gun now, mission feedback having found too
      // few machine guns in the field.
      //
      // Two of the three conscript slots now hold surplus: the M14 marksman,
      // who is the only reach this group has, and an MP44 man who is carrying
      // ammunition nobody else on the patrol can use. Still five men.
      class PTF_grp_Pereno_patrol
      {
         name = "Foot Patrol";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 1.0;
         icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_teamleader";     rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_machinegunner";  rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_marksman_m14";   rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_conscript";      rank = "PRIVATE";  position[] = {10, -5, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_conscript_mp44"; rank = "PRIVATE";  position[] = {15, -5, 0}; };
      };

      // Two guns, up from one on mission feedback. A single MAG made the
      // "machine gun team" one kill away from being a rifle team; a pair
      // gives it the interlocking fire the name promises.
      class PTF_grp_Pereno_mg_team
      {
         name = "Machine Gun Section";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.6;
         icon = "\A3\ui_f\data\map\markers\nato\o_support.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_teamleader";           rank = "CORPORAL"; position[] = {0, 5, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_machinegunner";        rank = "PRIVATE";  position[] = {-5, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_machinegunner_assist"; rank = "PRIVATE";  position[] = {-10, -5, 0}; };
         class Unit3 { side = 0; vehicle = "PTF_Pereno_machinegunner";        rank = "PRIVATE";  position[] = {5, 0, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_machinegunner_assist"; rank = "PRIVATE";  position[] = {10, -5, 0}; };
      };

      class PTF_grp_Pereno_at_team
      {
         name = "AT Team";
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
         name = "Mortar Team";
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
         name = "HVT - Commander and Escort";
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
         name = "Command Staff";
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
      name = "Motorized";
      aliveCategory = "Motorized";

      class PTF_grp_Pereno_uaz_patrol
      {
         name = "Motorized Patrol (UAZ)";
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
         name = "Truck-Mounted Squad";
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
         name = "Logistics Convoy";
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
      name = "Mechanized";
      aliveCategory = "Mechanized";

      class PTF_grp_Pereno_brdm_recon
      {
         name = "Recon (BRDM-2)";
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
         name = "Mechanized Section (M113)";
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
      name = "Support";
      aliveCategory = "Support";

      class PTF_grp_Pereno_zu23_section
      {
         name = "AA Section (ZU-23)";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.4;
         icon = "\A3\ui_f\data\map\markers\nato\o_air.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_zu23";          rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_zu23";          rank = "CORPORAL"; position[] = {-15, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_teamleader";    rank = "CORPORAL"; position[] = {-5, -10, 0}; };
         // The guns cannot depress into their own perimeter. One MAG for
         // local defence -- part of the wider fix for too few machine guns.
         class Unit3 { side = 0; vehicle = "PTF_Pereno_machinegunner"; rank = "PRIVATE";  position[] = {15, -10, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_conscript";     rank = "PRIVATE";  position[] = {5, -10, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Pereno_conscript";     rank = "PRIVATE";  position[] = {10, -15, 0}; };
      };

      class PTF_grp_Pereno_aa_mobile
      {
         name = "Mobile AA (Ural ZU-23)";
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
         name = "Howitzer Battery (D-30)";
         faction = "PTF_OPFOR_Perenos";
         side = 0;
         rarityGroup = 0.2;
         icon = "\A3\ui_f\data\map\markers\nato\o_art.paa";
         class Unit0 { side = 0; vehicle = "PTF_Pereno_d30";           rank = "SERGEANT"; position[] = {0, 0, 0}; };
         class Unit1 { side = 0; vehicle = "PTF_Pereno_d30";           rank = "CORPORAL"; position[] = {25, 0, 0}; };
         class Unit2 { side = 0; vehicle = "PTF_Pereno_teamleader";    rank = "CORPORAL"; position[] = {10, -10, 0}; };
         // A battery the players are meant to raid gets one MAG watching
         // the approach, same reasoning as the ZU-23 section.
         class Unit3 { side = 0; vehicle = "PTF_Pereno_machinegunner"; rank = "PRIVATE";  position[] = {20, -10, 0}; };
         class Unit4 { side = 0; vehicle = "PTF_Pereno_conscript";     rank = "PRIVATE";  position[] = {5, -15, 0}; };
         class Unit5 { side = 0; vehicle = "PTF_Pereno_conscript";     rank = "PRIVATE";  position[] = {15, -15, 0}; };
      };
   };
};
