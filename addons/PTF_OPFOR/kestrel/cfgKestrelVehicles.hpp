// ---------------------------------------------------------------------------
// Kestrel Group -- air defence and site assets.
//
// "They hold the airport and the research compound, and -- critically -- they
// own the island's air defence: MANPADS, a radar, and the professionalism to
// use both."
//
// This is the layer that changes how the players plan rather than how they
// shoot. The ZU-23-2 and the Igla pod make low approaches expensive; the
// radar is what makes those two coordinated rather than lucky. Taking the
// radar down should be worth doing on its own.
// ---------------------------------------------------------------------------

class PTF_Kestrel_zu23: rhsgref_ins_g_ZU23
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_Turrets";
   displayName = "ZU-23-2";
   crew = "PTF_Kestrel_crewman";
};

class PTF_Kestrel_igla_pod: rhsgref_ins_g_Igla_AA_pod
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_AAs";
   displayName = "Igla AA Pod";
   crew = "PTF_Kestrel_aa_igla";
};

// RHS ships the SERHAT radar as scenery: NonStrategic, destrType "DestructNo",
// no sensors. As a set piece that is fine, but the campaign needs the radar to
// be a target the players can service, so this variant is made damageable.
//
// The model has no destruction LOD, so expect it to stop working rather than
// visibly collapse. VERIFY IN-GAME that it actually takes damage -- if the
// p3d has no fire geometry this override will not be enough, and the fallback
// is a mission-side trigger on a satchel placed at the site.
class PTF_Kestrel_radar: rhsgref_serhat_radar
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_Military";
   displayName = "Kestrel Air Search Radar";
   destrType = "DestructDefault";
   armor = 250;
};

// --- Light vehicles --------------------------------------------------------

// The contractor's actual daily driver: fast, unarmoured, and cheap to lose.
class PTF_Kestrel_mrzr: rhsusf_mrzr4_w
{
   // Kill RHS texture randomization -- textureList re-rolls a stock skin at
   // spawn and silently wipes hiddenSelectionsTextures (the M113 M2 bug).
   textureList[] = {};

   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "MRZR-4";
   crew = "PTF_Kestrel_crewman";
   typicalCargo[] = {"PTF_Kestrel_crewman", "PTF_Kestrel_operator"};
   // Emblem on the front clip (slot 0); other four sheets stock.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_mrzr_camo_co.paa",
         "\rhsusf\addons\rhsusf_mrzr\data\yel_tan_pnt1_co.paa",
         "\rhsusf\addons\rhsusf_mrzr\data\red_tan_pnt1_co.paa",
         "\rhsusf\addons\rhsusf_mrzr\data\grn_tan_pnt1_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_mrzr_merged_co.paa"
      };
};

class PTF_Kestrel_m998: rhsusf_m998_w_4dr_fulltop
{
   // Kill RHS texture randomization -- textureList re-rolls a stock skin at
   // spawn and silently wipes hiddenSelectionsTextures (the M113 M2 bug).
   textureList[] = {};

   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "M998 (Carga)";
   crew = "PTF_Kestrel_crewman";
   typicalCargo[] = {"PTF_Kestrel_crewman"};
   // Full 11-entry array from rhsusf_m998_w_4dr; only index 9 changes -- the
   // stock 101st Airborne decal sheet becomes Kestrel's.
   hiddenSelectionsTextures[] =
      {
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_interior_w_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\A2_parts_WD_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\wheel_wranglermt_b_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_mainbody_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\gratting_w_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_interior_wood_w_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_m998_cargo_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_decals_co.paa",
         ""
      };
};

class PTF_Kestrel_m1025: rhsusf_m1025_w
{
   // Kill RHS texture randomization -- textureList re-rolls a stock skin at
   // spawn and silently wipes hiddenSelectionsTextures (the M113 M2 bug).
   textureList[] = {};

   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "M1025 (Desarmado)";
   crew = "PTF_Kestrel_crewman";
   typicalCargo[] = {"PTF_Kestrel_crewman", "PTF_Kestrel_operator"};
   // 10-entry array from rhsusf_m1025_w; index 8 swaps 101st decals for ours.
   hiddenSelectionsTextures[] =
      {
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_interior_w_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\A2_parts_WD_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\wheel_wranglermt_b_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_mainbody_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\gratting_w_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_m1025_body_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_decals_co.paa",
         ""
      };
};

// RHS USAF woodland HMMWV rather than the HIDF green one los Perenos use:
// still visibly a brought-in US-pattern vehicle rather than something drawn
// from the island's motor pool, but in a scheme that suits a tropical island.
// Kestrel are professionals -- they would not run desert paint through
// jungle. A real livery difference from an existing RHS texture set, no
// custom art involved. See LIVERIES.md.
class PTF_Kestrel_m1025_m2: rhsusf_m1025_w_m2
{
   // Kill RHS texture randomization -- textureList re-rolls a stock skin at
   // spawn and silently wipes hiddenSelectionsTextures (the M113 M2 bug).
   textureList[] = {};

   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "M1025 (M2)";
   crew = "PTF_Kestrel_crewman";
   typicalCargo[] = {"PTF_Kestrel_crewman", "PTF_Kestrel_operator"};

   // Kestrel markings in place of RHS's stock 101st Airborne 2/502 decals,
   // which are plainly wrong on a contractor vehicle. RHS exposes
   // "unitdecals_1" for exactly this, so only index 8 changes -- the painted
   // body texture underneath is untouched, keeping all of RHS's panel detail
   // and weathering. See LIVERIES.md.
   //
   // Both arrays are restated in full: a partial override leaves the
   // remaining selections untextured. Textures are 10 entries against 13
   // selections because the three indicator selections are driven by the
   // lighting config, not by a texture -- this mirrors RHS exactly.
   hiddenSelections[] =
      {
         "exterior", "interior", "A2", "wheels", "mainbody", "hood gratting",
         "camo1", "camo2", "unitdecals_1", "unitdecals_2",
         "ind_wait", "ind_brake", "ind_highbeam"
      };
   hiddenSelectionsTextures[] =
      {
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_exterior_w_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_interior_w_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\A2_parts_WD_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\wheel_wranglermt_b_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\m998_mainbody_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\gratting_w_co.paa",
         "rhsusf\addons\rhsusf_hmmwv\textures\tile_exmetal_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_m1025_body_co.paa",
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_decals_co.paa",
         ""
      };
};

// --- Expanded air defence --------------------------------------------------

// Kestrel's own procurement, next to the island's inherited Igla pod: the
// contract bought Stingers.
class PTF_Kestrel_stinger_pod: RHS_Stinger_AA_pod_WD
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_AAs";
   displayName = "Stinger AA Pod";
   crew = "PTF_Kestrel_aa_stinger";
};

// A crewed, working search radar -- unlike the SERHAT prop, this is a vehicle
// with a gunner seat, so it can be manned, suppressed and destroyed like any
// other position. This is the radar the campaign should be fought over; the
// SERHAT stays as set dressing.
class PTF_Kestrel_p37: rhs_p37_turret_vpvo
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_AAs";
   displayName = "P-37 Search Radar (Manned)";
   crew = "PTF_Kestrel_crewman";
};

// --- Helicopters -----------------------------------------------------------
// Little birds: the definitive contractor airframe. One lifts, one shoots.

class PTF_Kestrel_mh6: RHS_MELB_MH6M
{
   // Kill RHS texture randomization -- textureList re-rolls a stock skin at
   // spawn and silently wipes hiddenSelectionsTextures (the M113 M2 bug).
   textureList[] = {};

   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_Helicopters";
   displayName = "MH-6M (Bancos)";
   crew = "PTF_Kestrel_pilot";
   typicalCargo[] = {"PTF_Kestrel_pilot"};
   // US ARMY boom text patched out; kestrel emblem, wordmark and callsign on
   // the boom band. Shared sheet -- both little birds brand identically.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_melb_ext_co.paa",
         "rhsusf\addons\rhsusf_melb\data\decals\SN\blank_ca.paa"
      };
};

class PTF_Kestrel_ah6: RHS_MELB_AH6M_L
{
   // Kill RHS texture randomization -- textureList re-rolls a stock skin at
   // spawn and silently wipes hiddenSelectionsTextures (the M113 M2 bug).
   textureList[] = {};

   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 0;
   faction = "PTF_OPFOR_Kestrel";
   editorSubcategory = "EdSubcat_Helicopters";
   displayName = "AH-6M (Ligero)";
   crew = "PTF_Kestrel_pilot";
   typicalCargo[] = {"PTF_Kestrel_pilot"};
   // US ARMY boom text patched out; kestrel emblem, wordmark and callsign on
   // the boom band. Shared sheet -- both little birds brand identically.
   hiddenSelectionsTextures[] =
      {
         "\z\PTF\addons\PTF_OPFOR\data\kestrel_melb_ext_co.paa",
         "rhsusf\addons\rhsusf_melb\data\decals\SN\blank_ca.paa"
      };
};
