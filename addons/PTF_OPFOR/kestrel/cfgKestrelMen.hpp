// ---------------------------------------------------------------------------
// Kestrel Group
//
// Design intent (campaign layer 3): ~50 foreign contractors on Marenco's
// payroll. Ex-special-forces from four or five countries, individually
// excellent, collectively uninterested in dying for a mining concession.
// They hold the airport and the research compound, and they own the island's
// air defence. Defeated by economics, not by attrition.
//
// The third silhouette. Where los Perenos are numerous and poor and La
// Guardia are well-funded and disciplined, Kestrel are FEW and EXPENSIVE:
//   * Highest accuracy and sensitivity in the campaign -- individually, these
//     are the best soldiers on the island.
//   * The smallest groups in the campaign, by design (see cfgKestrelGroups).
//     Kestrel do not mass. Four men who are each better than anything the
//     players have met, and no ninth man behind them.
//   * `cost` is set very high. Beyond AI targeting priority it is a note to
//     the mission maker: every one of these is a line item on a contract, and
//     the campaign's win condition is making that contract unprofitable.
//   * Four national camouflage patterns across the roster -- DPM, French
//     lizard, US woodland, 3-colour desert -- because nobody issued these men
//     anything. They each kept the kit they left their old army in.
//
// Note on "defeated by economics": withdrawal is campaign scripting and
// cannot live in a unit config. What config does is make Kestrel expensive to
// grind down and obviously finite, so that attrition reads as the wrong tool.
// ---------------------------------------------------------------------------


// Preloaded missile packs for the two AA specialists.
//
// magazines[] reaches the uniform and vest only, and a Stinger/Igla round is
// far too large for either -- so the rounds have to live in a container the
// engine fills for us. TransportMagazines does exactly that, declaratively.
//
// An earlier attempt used a CBA_Extended_EventHandlers init calling
// addItemToBackpack. It worked, but declaring CBA_Extended_EventHandlers_base
// in this addon cost ~375 RPT warning lines per session against a baseline of
// one, so it was replaced with the same TransportMagazines approach the
// Guardia machinegunner uses for his spare belts.
class PTF_B_kestrel_fim92: B_Carryall_cbr
{
   author = "Paramarine Task Force";
   scope = 1;
   scopeCurator = 0;
   displayName = "Carryall (FIM-92)";
   class TransportMagazines
   {
      class _xx_rhs_fim92_mag
      {
         magazine = "rhs_fim92_mag";
         count = 2;
      };
   };
};

class PTF_B_kestrel_igla: B_Carryall_cbr
{
   author = "Paramarine Task Force";
   scope = 1;
   scopeCurator = 0;
   displayName = "Carryall (9K38)";
   class TransportMagazines
   {
      class _xx_rhs_mag_9k38_rocket
      {
         magazine = "rhs_mag_9k38_rocket";
         count = 2;
      };
   };
};

class PTF_Kestrel_base: rhsgref_nat_base
{
   // rhsgref_nat_base names an editor-preview image that does not exist in
   // RHS's editorpreviews PBO ("Cannot load texture ... rhsgref_nat_base.paa"
   // in-game). Blank it; children inherit the blank.
   editorPreview = "";
   scope = 0;
   scopeCurator = 0;
   author = "Paramarine Task Force";
   side = 0;                              // EAST
   faction = "PTF_OPFOR_Kestrel";
   vehicleClass = "Men";
   editorSubcategory = "EdSubcat_Personnel";
   // Ex-special-forces from four or five countries: NATO, African and
   // European faces, English and British-English voices.
   identityTypes[] = {"LanguageENG_F", "LanguageENGB_F", "Head_NATO", "Head_African", "Head_Euro"};
   modelSides[] = {0, 1, 2, 3};

   // Best individual soldiers in the campaign. Compare PTF_Pereno_base at
   // 1.0 / 1.2 and PTF_Guardia_base at 2.6 / 3.2.
   accuracy = 3.6;
   sensitivity = 4.2;
   camouflage = 1.0;
   cost = 800000;

   class EventHandlers;

   uniformClass = "PTF_U_kestrel_wdl";
   hiddenSelections[] = {"Camo"};
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_us_woodland_co.paa"};

   Items[] = {"FirstAidKit"};
   RespawnItems[] = {"FirstAidKit"};

   // Every role below overrides this with its own carrier. Kestrel are
   // individually equipped rather than issued as a unit, so a fireteam should
   // show four different rigs, not four copies of one.
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};

   weapons[] = {"rhs_weap_mk18_eotech_sup", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_mk18_eotech_sup", "rhsusf_weap_glock17g4", "Throw", "Put"};
   // Grenades and smoke, faction-wide. Unit feedback was that OPFOR never
   // threw either; for Kestrel the missing half was smoke, because the M67
   // was already here and nothing to screen with was not.
   //
   // Two smokes, two jobs, and the split is deliberate so the comments below
   // can say which one a class is short of:
   //   * rhs_mag_m18_green (11.88) -- coloured, for marking. Leaders carry a
   //     second in another colour, so a player can tell a mark from a screen.
   //   * rhs_mag_an_m8hc (8.98) -- AN-M8 HC white, for screening and breaking
   //     contact. It is the lighter of the two, which is what gets it into
   //     the classes with almost no room left.
   //
   // Worn load here: first aid kit (8), seven Stanags (7 x 9.35 = 65.45), two
   // Glock magazines (12), the M67 (8.8), the M18 (11.88) and the AN-M8
   // (8.98) is 115.11. The thinnest carrier any operator variant wears is the
   // DPM man's SPC patchless at 100, and with the uniform's 40 that is 140.
   // Per container it clears either way round: magazines alone are 107.11, so
   // at worst one item spills into the uniform's 32 free.
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
};

// --- Operators -------------------------------------------------------------
//
// Four men, four old armies. Mechanically identical -- the variation is
// entirely visual, and it is the point: a Kestrel fireteam should not look
// like a unit, it should look like a contract.

class PTF_Kestrel_operator: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Operator (Woodland)";
};

class PTF_Kestrel_operator_dpm: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Operator (DPM)";
   uniformClass = "PTF_U_kestrel_dpm";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_dpm_co.paa"};
   linkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class PTF_Kestrel_operator_lizard: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Operator (Lizard)";
   uniformClass = "PTF_U_kestrel_lizard";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_altis_lizard_co.paa"};
   linkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_plateframe_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_plateframe_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

class PTF_Kestrel_operator_desert: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Operator (3-Color Desert)";
   uniformClass = "PTF_U_kestrel_desert";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_3color_desert_co.paa"};
   linkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_rifleman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

// --- Specialists -----------------------------------------------------------

// The machinegunner's belt pack -- same mechanism as the AA carryalls above
// and PTF_B_guardia_pkp: magazines[] only reaches the uniform and vest, so
// the sustainment belts ride in a pack the engine preloads for us.
//
// Eagle A-III holds 240; four 100-round soft pouches at 26.9 each is 107.6
// of it. Four worn plus four in the pack is 800 rounds -- the tier-3 answer
// to the Pereno gunner's 700 of 7.62 NATO and the Guardia gunner's 500 of
// 7.62x54R. A Kestrel gun going quiet first would read as wrong.
class PTF_B_kestrel_m249: rhsusf_assault_eagleaiii_coy
{
   author = "Paramarine Task Force";
   // Hidden: a loadout component, not something to place. The empty Eagle
   // A-III is already in the arsenal if a mission maker wants one.
   scope = 1;
   scopeCurator = 0;
   displayName = "Eagle A-III (M249)";
   class TransportMagazines
   {
      class _xx_rhsusf_100Rnd_556x45_soft_pouch
      {
         magazine = "rhsusf_100Rnd_556x45_soft_pouch";
         count = 4;
      };
   };
};

// Worn load: the MG plateframe's 160 plus the uniform's 40 hold the first
// aid kit (8), four belts (4 x 26.9 = 107.6), a pistol magazine (6), the M67
// (8.8), the M18 (11.88) and the AN-M8 (8.98) -- 151.26 of 200, no overflow.
// The per-container check is the one that matters: even with every magazine
// in the carrier and nothing but the kit in the uniform, that is 143.26 of
// the plateframe's 160. The other four belts are in the pack above.
class PTF_Kestrel_machinegunner: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Machine Gunner (M249)";
   cost = 900000;
   icon = "iconManMG";
   backpack = "PTF_B_kestrel_m249";
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_machinegunner", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_machinegunner", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   uniformClass = "PTF_U_kestrel_dpm";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_dpm_co.paa"};
   weapons[] = {"rhs_weap_m249_light_L_elcan", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m249_light_L_elcan", "rhsusf_weap_glock17g4", "Throw", "Put"};
   magazines[] =
      {
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_100Rnd_556x45_soft_pouch",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
};

class PTF_Kestrel_marksman: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Marksman";
   cost = 950000;
   accuracy = 4.0;
   icon = "iconManRecon";
   linkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_plateframe_marksman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_plateframe_marksman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_mk18_SU230", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_mk18_SU230", "rhsusf_weap_glock17g4", "Throw", "Put"};
   // He is the other half of the sniper pair, and the half whose job when the
   // shooting starts is to move both of them, so he carries a second AN-M8
   // rather than the base load. His marksman plateframe (160) and uniform
   // (40) hold the first aid kit (8), seven Stanags (65.45), two Glock
   // magazines (12), the M67 (8.8), the M18 (11.88) and two AN-M8 (17.96) --
   // 124.09 of 200, and 116.09 of that is magazines, so it would fit in the
   // plateframe on its own.
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc",
         "rhs_mag_an_m8hc"
      };
};

class PTF_Kestrel_sniper: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Sniper (XM2010)";
   cost = 1100000;
   accuracy = 4.2;
   icon = "iconManRecon";
   sensitivity = 4.5;
   camouflage = 0.6;
   uniformClass = "PTF_U_kestrel_lizard";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_altis_lizard_co.paa"};
   linkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_spc_sniper", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_M2010S", "rhsusf_acc_harris_bipod"};
   respawnLinkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_spc_sniper", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_M2010S", "rhsusf_acc_harris_bipod"};
   weapons[] = {"rhs_weap_XM2010_wd_leu", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_XM2010_wd_leu", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   // He had no grenade and no smoke at all: six rifle magazines, a pistol and
   // nothing to break a compromise with, which is a poor showing for the man
   // most likely to be found alone.
   //
   // The SPC Sniper carrier is the smallest rig in the faction at 80, but a
   // .300 magazine is only 1.56, so there is room and then some. First aid
   // kit (8), six magazines (9.36), two Glock magazines (12), the M67 (8.8),
   // the M18 (11.88) and two AN-M8 (17.96) is 68.00 of the 120 his uniform
   // and carrier hold, and the 60.00 of magazines would fit in the carrier by
   // itself. Second screening smoke for the same reason as the marksman: the
   // pair works detached, and nobody is coming to cover their move.
   magazines[] =
      {
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_5Rnd_300winmag_xm2010",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc",
         "rhs_mag_an_m8hc"
      };
};

// M107 with Mk211 multipurpose. This is the man who makes an airframe
// unflyable without anyone taking off, and he cuts both ways -- if the
// players can take him, they can use the same logic on Kestrel's shipments.
class PTF_Kestrel_antimateriel: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Anti-Materiel (M107)";
   cost = 1200000;
   accuracy = 4.0;
   icon = "iconManRecon";
   linkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_plateframe_marksman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_LEUPOLDMK4"};
   respawnLinkedItems[] = {"rhsgref_Booniehat_alpen", "rhsusf_plateframe_marksman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio", "rhsusf_acc_LEUPOLDMK4"};
   weapons[] = {"rhs_weap_M107_w_leu", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_M107_w_leu", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   // A 10-round .50 BMG box is 41.14 mass, so not one of them will go in the
   // uniform's 40 -- the plateframe's 160 is his entire magazine capacity and
   // it holds exactly three. The five declared here before meant two were
   // dropped at spawn.
   //
   // Walk the containers by the real rule -- Items[] first, then magazines[]
   // in array order, trying the uniform for each entry and falling back to
   // the vest. The first aid kit (8) takes the uniform. The three .50 boxes
   // are 41.14 apiece and cannot fit the uniform's remaining 32, so all three
   // go to the plateframe at 123.42 of 160. Everything after them is small
   // enough that the uniform takes it: the Glock magazine (6), the M67 (8.8)
   // and the AN-M8 (8.98) land there for 31.78 of 40. That leaves the
   // plateframe with 36.58 free and the uniform with 8.22.
   //
   // The M18 (11.88) would fit -- it is not a capacity limit, it is a choice.
   // He is a one-shot-and-move class carrying the heaviest magazines in the
   // addon, and 36 of headroom in the carrier is what lets a mission maker
   // hand him a fourth box or a demo charge without silently dropping
   // something. One frag and one screening smoke, and the margin stays.
   // Total worn is 155.20 of 200.
   magazines[] =
      {
         "rhsusf_mag_10Rnd_STD_50BMG_mk211",
         "rhsusf_mag_10Rnd_STD_50BMG_mk211",
         "rhsusf_mag_10Rnd_STD_50BMG_M33",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhsusf_mag_10Rnd_STD_50BMG_mk211",
         "rhsusf_mag_10Rnd_STD_50BMG_mk211",
         "rhsusf_mag_10Rnd_STD_50BMG_M33",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_an_m8hc"
      };
};

// --- Air defence -----------------------------------------------------------
//
// The reason Kestrel matter. "They own the island's air defence: MANPADS, a
// radar, and the professionalism to use both."
//
// Two flavours on purpose. The Stinger is Kestrel's own procurement -- what
// the contract bought. The Igla is the island's, inherited with the site and
// now operated by people who actually know how. Fielding both tells the
// players that Kestrel did not just arrive, they took something over.

// THE MISSILES ARE NOT IN magazines[], AND MUST NOT BE PUT BACK.
//
// A FIM-92 round is 120 mass. When the engine distributes a soldier's
// magazines[] it fills the UNIFORM and VEST only -- never the backpack --
// so a 120-mass round has to fit inside a 160-capacity carrier that is
// already holding the rifle magazines and the first aid kit. It does not,
// and the engine drops what will not fit silently: this class was spawning
// with a launcher and no rounds at all, which defeats the entire point of
// Kestrel's air defence. (Adding a backpack alone does NOT fix this. See
// PTF_Pereno_engineer, which has had one the whole time and still
// overflowed.)
//
// So the rounds ride in a 320-capacity carryall instead, preloaded through
// TransportMagazines -- see PTF_B_kestrel_fim92 at the top of this file.
// Two rounds is 240 of it, and the AI feeds the launcher from the pack.
//
// Six rifle magazines, up from four: the SPC IAR's 160 plus the uniform's
// 40 hold the first aid kit (8), six Stanags (6 x 9.35 = 56.1), a pistol
// magazine (6), the M67 (8.8), the M18 (11.88) and the AN-M8 (8.98) -- 99.76
// of 200, no overflow, and the 91.76 of magazines fits in the SPC IAR on its
// own. Four magazines was a self-defence ration, and the feedback said these
// men die with dry rifles long before anyone gets to use the launcher
// argument.
class PTF_Kestrel_aa_stinger: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel AA Specialist (FIM-92)";
   cost = 1400000;
   icon = "iconManAT";
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_spc_iar", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_spc_iar", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   backpack = "PTF_B_kestrel_fim92";
   weapons[] = {"rhs_weap_mk18_eotech_sup", "rhs_weap_fim92", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_mk18_eotech_sup", "rhs_weap_fim92", "rhsusf_weap_glock17g4", "Throw", "Put"};
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
};

// Same treatment as the Stinger above, and for the same reason: a 9K38
// round is 100 mass and his SPC Light carrier holds 100 in total. Two rounds
// in a 320-capacity carryall, preloaded through TransportMagazines
// (PTF_B_kestrel_igla).
//
// Six rifle magazines, up from four, same as the Stinger man: first aid kit
// (8), six Stanags (56.1), a pistol magazine (6), the M67 (8.8), the M18
// (11.88) and the AN-M8 (8.98) is 99.76 of the 140 his uniform and SPC Light
// hold between them. His is the thinner carrier of the two AA men, so it is
// worth saying that the 91.76 of magazines still clears the SPC Light's 100
// on its own -- nothing here depends on the uniform taking a share.
class PTF_Kestrel_aa_igla: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel AA Specialist (Igla)";
   cost = 1300000;
   icon = "iconManAT";
   linkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_light", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   uniformClass = "PTF_U_kestrel_desert";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_3color_desert_co.paa"};
   backpack = "PTF_B_kestrel_igla";
   weapons[] = {"rhs_weap_mk18_eotech_sup", "rhs_weap_igla", "rhsusf_weap_glock17g4", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_mk18_eotech_sup", "rhs_weap_igla", "rhsusf_weap_glock17g4", "Throw", "Put"};
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
};

// --- Support ---------------------------------------------------------------

class PTF_Kestrel_medic: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Medic";
   cost = 900000;
   attendant = 1;
   icon = "iconManMedic";
   linkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_medic", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01", "rhsusf_plateframe_medic", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   Items[] = {"FirstAidKit", "Medikit"};
   RespawnItems[] = {"FirstAidKit", "Medikit"};
   // Six rifle magazines rather than the operator's seven: the Medikit is
   // 80 mass, and Items[] are packed into the uniform and carrier before
   // magazines[] are. The budget still clears -- kits (88) plus six Stanags
   // (56.1), a pistol magazine (6), the M67 (8.8), the M18 (11.88) and the
   // AN-M8 (8.98) is 179.76 of the 200 his uniform and medic plateframe hold.
   //
   // He is the class where the screening smoke earns its place most obviously,
   // so it is worth walking the containers rather than trusting the total.
   // Items[] first: the first aid kit (8) goes to the uniform, the Medikit
   // (80) cannot go anywhere but the plateframe. Then magazines[] in order,
   // uniform first each time -- three Stanags (9.35 each) fill the uniform to
   // 36.05, the next three fall through to the plateframe at 108.05, and the
   // Glock magazine (6), the M67 (8.8), the M18 (11.88) and the AN-M8 (8.98)
   // follow them there because the uniform has only 3.95 left. Final state:
   // uniform 36.05 of 40, plateframe 143.71 of 160. Nothing dropped, and the
   // carrier still has 16.29 spare.
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
};

class PTF_Kestrel_breacher: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Breacher";
   cost = 950000;
   linkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless_radio", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless_radio", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   engineer = 1;
   canDeactivateMines = 1;
   icon = "iconManEngineer";
   uniformClass = "PTF_U_kestrel_dpm";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_dpm_co.paa"};
   Items[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   RespawnItems[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   // Toolkit (80), mine detector (20) and first aid kit (8) are 108 of the
   // 180 his uniform and radio carrier hold between them, and the engine
   // packs Items[] first. Five rifle magazines is the per-container ceiling:
   // the toolkit has to go in the carrier (140), which then takes four
   // Stanags (37.4), the pistol magazine (6) and the M67 (8.8) for 132.2,
   // while the uniform holds the kit (8), the detector (20) and the fifth
   // Stanag (9.35). A sixth Stanag would push the M67 past 140 and the
   // engine would drop it silently.
   //
   // He is the one man in the faction with no smoke, and that is a decision
   // rather than an oversight. After the walkthrough above there are 2.65 free
   // in the uniform and 7.80 free in the carrier; the lightest smoke Kestrel
   // carry is the AN-M8 at 8.98, and it fits in neither. Capacity is checked
   // per container, never against the 10.45 those two happen to add up to, so
   // declaring one here would buy nothing but a silent drop. Nothing gets
   // traded away to make room either: five rifle magazines is already the
   // floor for a man expected to fight his way back off an objective. If the
   // breacher ever needs smoke it goes in a preloaded backpack, the way every
   // other overflow in this addon was solved.
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67"
      };
};

// The SPC Crewman carrier is cut down to fit a vehicle hatch and holds only
// 80, against 140-160 for the operators' rigs. Four magazines rather than
// seven; a crewman fights out of a vehicle, not on foot.
//
// He keeps both smokes all the same, because the moment a crewman needs one
// is the moment he is standing next to a burning vehicle. First aid kit (8),
// four Stanags (37.4), a pistol magazine (6), the M67 (8.8), the M18 (11.88)
// and the AN-M8 (8.98) is 81.06 of 120, and the 73.06 of magazines would fit
// in the crewman carrier alone.
class PTF_Kestrel_crewman: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Crewman";
   cost = 800000;
   linkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_crewman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_crewman", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc"
      };
};

class PTF_Kestrel_teamleader: PTF_Kestrel_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Kestrel Team Leader";
   cost = 1300000;
   accuracy = 4.0;
   sensitivity = 4.5;
   icon = "iconManLeader";
   linkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_plateframe_teamleader", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_opscore_01_tan", "rhsusf_plateframe_teamleader", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   uniformClass = "PTF_U_kestrel_dpm";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_dpm_co.paa"};
   weapons[] = {"rhs_weap_mk18_eotech_sup", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_mk18_eotech_sup", "rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   // The base load plus a red M18. He is the man who marks a target or a
   // landing point for somebody else, and green is what everyone in the
   // faction already carries, so the mark has to be a colour nobody else
   // throws or it says nothing.
   //
   // His teamleader plateframe holds 160 and the uniform 40. First aid kit
   // (8), seven Stanags (65.45), two Glock magazines (12), the M67 (8.8), the
   // green M18 (11.88), the AN-M8 (8.98) and the red M18 (11.88) is 126.99 of
   // 200 -- and the 118.99 of magazines fits in the plateframe by itself, so
   // there is no per-container question to answer here at all.
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc",
         "rhs_mag_m18_red"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc",
         "rhs_mag_m18_red"
      };
};

// Kestrel's senior man on the island. Killing him does not end the contract;
// making the contract unprofitable does.
class PTF_Kestrel_commander: PTF_Kestrel_teamleader
{
   displayName = "Kestrel Site Commander";
   cost = 1600000;
   icon = "iconManOfficer";
   uniformClass = "PTF_U_kestrel_desert";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_3color_desert_co.paa"};
   linkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_squadleader", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_patrolcap_ocp", "rhsusf_spc_squadleader", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   // Purple where the team leader throws red, for the same reason the team
   // leader is not throwing green: on a site holding several teams, a mark
   // that could have come from any of them is not a mark. Same 126.99 of
   // worn load as the team leader, against the 180 his uniform and SPC
   // Squad Leader hold, and again the 118.99 of magazines clears the carrier
   // (140) unaided.
   magazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc",
         "rhs_mag_m18_purple"
      };
   respawnMagazines[] =
      {
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhs_mag_30Rnd_556x45_Mk318_Stanag",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhsusf_mag_17Rnd_9x19_JHP",
         "rhs_mag_m67",
         "rhs_mag_m18_green",
         "rhs_mag_an_m8hc",
         "rhs_mag_m18_purple"
      };
};

// --- HVT -------------------------------------------------------------------
//
// Not a soldier -- the man who administers the contract. Kestrel are defeated
// by economics, and he is the paperwork made flesh: the one carrying the terms
// the players are meant to find in Op 3. Civilian-ish silhouette on purpose,
// so he reads as out of place among the operators guarding him.
class PTF_Kestrel_hvt: PTF_Kestrel_commander
{
   displayName = "Kestrel Contract Manager (HVT)";
   cost = 1500000;
   accuracy = 2.4;
   sensitivity = 3.4;
   // Plain silhouette, overriding the commander's officer icon: he is not a
   // soldier, and the map should say so before the players' optics do.
   icon = "iconMan";
   uniformClass = "PTF_U_kestrel_olive";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_gue\m93_olive_co.paa"};
   linkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsusf_bowman_cap", "rhsusf_spc_patchless", "rhsusf_ANPVS_15", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhsusf_weap_glock17g4", "Throw", "Put", "Binocular"};
   // He keeps a smoke and no frag while the rest of the faction gained both,
   // and that is the point: a man who marks a pickup and leaves, not a man who
   // fights. Two Glock magazines (12) and the M18 (11.88) on top of the first
   // aid kit (8) is 31.88 of the 140 his uniform and SPC patchless hold, so
   // the room was there and was deliberately not used.
   magazines[] = {"rhsusf_mag_17Rnd_9x19_JHP", "rhsusf_mag_17Rnd_9x19_JHP", "rhs_mag_m18_green"};
   respawnMagazines[] = {"rhsusf_mag_17Rnd_9x19_JHP", "rhsusf_mag_17Rnd_9x19_JHP", "rhs_mag_m18_green"};
};

class PTF_Kestrel_pilot: PTF_Kestrel_crewman
{
   displayName = "Kestrel Pilot";
   cost = 1000000;
};
