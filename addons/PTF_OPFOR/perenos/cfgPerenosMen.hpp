// ---------------------------------------------------------------------------
// Infantry Battalion No. 7 "Pera" -- los Perenos
//
// Design intent (campaign layer 1): the original Valmeran army garrison.
// Conscripts stiffened by long-service NCOs, all island-born. Ageing rifles,
// no night vision worth the name, poorly paid and paid late.
//
// This is expressed in config rather than left to mission scripting:
//   * NO unit in this faction carries NVGs. Night is the players' advantage.
//   * Conscripts and sentries get LOW `sensitivity` -- they man a checkpoint
//     properly and then stop paying attention. NCOs and officers get high
//     `sensitivity`, because the long-service cadre is the competent part.
//   * Kit quality tiers visibly by rank: conscripts in OG-107 with a field
//     cap, riflemen in mixed OG-107/ERDL with M1 steel, NCOs in full ERDL
//     with a PASGT. A player should be able to read who matters by looking.
//   * Ammunition loads are deliberately thin -- thin against La Guardia's
//     eight polymer magazines, not starvation. Unit feedback after the first
//     missions was that three or four magazines read as a bug rather than as
//     poverty, so line troops now carry five or six; the tier gap is held by
//     La Guardia carrying eight, not by the garrison running dry at first
//     contact.
//   * The rifle rack is deliberately incoherent. The battalion bought from
//     whoever would sell, so alongside the L1A1 there are AKMs, Zastava M70s,
//     a crate of MP44s and a handful of M14s. Three rifle calibres in one
//     squad -- 7.62x51, 7.62x39 and 7.92x33 Kurz -- and none of them feed
//     each other, which is a fact a player learns the first time he picks up
//     a dead man's magazines. The grenadier is a fourth family again on his
//     own, .45 ACP and 40mm. The surplus variants
//     sit alongside the standard classes rather than replacing them, so a
//     mission maker chooses how mismatched a given squad looks.
//   * Grenades are thin and mismatched for the same reason. US M67s came with
//     one shipment, Soviet RGD-5s and F1s with another, and the WWII Mk 2
//     pineapples and AN-M8 smoke out of a depot nobody has counted since the
//     island changed hands. Most fighting men carry one frag; the gun group
//     and the medic carry a white smoke for breaking contact; only the cadre
//     carries coloured smoke, because only the cadre is marking anything for
//     anyone. Unit feedback was that the garrison never threw anything at
//     all, which read as an AI failure rather than as poverty.
//
// Read the capacity note in README.md before adding anything to a magazines[]
// array here. The engine packs Items[] first and then magazines[] in array
// order, trying the uniform for each entry and falling back to the vest, and
// it drops silently whatever fits neither. Every class below shows its own
// per-container arithmetic; several are at their ceiling.
// ---------------------------------------------------------------------------

class PTF_Pereno_base: rhsgref_hidf_base
{
   scope = 0;
   scopeCurator = 0;
   author = "Paramarine Task Force";
   side = 0;                              // EAST
   faction = "PTF_OPFOR_Perenos";
   vehicleClass = "Men";
   editorSubcategory = "EdSubcat_Personnel";
   genericNames = "PTF_ValmeranMen";
   // Island-born, island-recruited: Tanoan-weighted faces, the island
   // voice protocol (the closest Arma has to a Caribbean garrison).
   identityTypes[] = {"LanguageENGFRE_F", "Head_Tanoan", "Head_Tanoan", "Head_African", "Head_Euro"};
   modelSides[] = {0, 1, 2, 3};

   // Conscript baseline: slow to identify a target, slow to notice one.
   accuracy = 1.0;
   sensitivity = 1.2;
   camouflage = 1.5;
   cost = 40000;

   // Declared so child classes can extend the inherited handlers rather than
   // replace them -- the headgear randomiser below hangs off this.
   class EventHandlers;

   uniformClass = "PTF_U_pereno_og107";
   hiddenSelections[] = {"Camo"};
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_tanoa\m93_og107_co.paa"};

   Items[] = {"FirstAidKit"};
   RespawnItems[] = {"FirstAidKit"};

   // No NVG entry here, and none added by any child class. Deliberate.
   linkedItems[] = {"rhsgref_hat_M1951", "rhsgref_alice_webbing", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_hat_M1951", "rhsgref_alice_webbing", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};

   weapons[] = {"rhs_weap_l1a1_wood", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_l1a1_wood", "Throw", "Put"};
   // Six magazines and a grenade: 8 + 99 + 8.8 = 115.8 of the 160 the
   // uniform (40) and ALICE webbing (120) hold, first aid kit packed first.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67"
      };
};

// --- Rank and file ---------------------------------------------------------

// The bottom of the barrel: a teenager on a checkpoint with a rifle, two
// spare magazines and a cap. Lowest sensitivity in the faction.
//
// He keeps the base class's ALICE webbing. The brief is ageing equipment, not
// absent equipment, and stripping the webbing left him with the OG-107
// uniform's 40 as his whole carrying capacity -- a first aid kit is 8 and a
// 20-round FAL magazine is 16.5, so exactly one magazine fitted and the rest
// were dropped at spawn. With the webbing's 120 he carries his three: 8 + 49.5
// against 160. What marks him out is the cap, the sensitivity and the thin
// load, not the absence of a belt order.
//
// One F1 out of the old Soviet shipment, not the rifleman's American M67 --
// he is the last man in the battalion to be handed anything current. Per
// container: the uniform takes the first aid kit (8), magazine 1 (16.5) and
// the grenade (13.2) for 37.7 of 40; magazines 2 and 3 land in the webbing at
// 33 of 120. Nothing dropped, but the uniform has 2.3 left and the grenade is
// the last thing that will fit in it.
class PTF_Pereno_sentry: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Sentry";
   sensitivity = 0.8;
   cost = 25000;
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_f1"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_f1"
      };
};

// The same teenager out of a different crate. The battalion has M3A1 grease
// guns of the same vintage as its helmets, and they went to the men nobody
// expected to shoot past a hundred metres: gate guards, drivers, storemen.
// .45 ACP feeds nothing else in the faction except the crewman's identical
// gun and the officers' pistols, which is the point -- a player who takes
// this man's magazines has taken magazines for one weapon.
//
// The M3A1 accepts no attachments at all, so there is nothing to bake onto a
// custom weapon class the way La Guardia's optics are.
//
// Per container, uniform (40) and ALICE webbing (120), packed in array order
// after the first aid kit (8): magazine 1 (17.47) fills the uniform to 25.47,
// magazines 2 and 3 will not fit past that and land in the webbing (34.94 of
// 120), and the Mk 2 (13.09) closes the uniform out at 38.56 of 40. Nothing
// dropped, and 1.44 spare -- do not add a fourth item expecting the uniform
// to take it.
class PTF_Pereno_sentry_m3a1: PTF_Pereno_sentry
{
   displayName = "Sentry (M3A1)";
   weapons[] = {"rhs_weap_m3a1", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m3a1", "Throw", "Put"};
   // Both arrays overridden. The inherited magazines are 7.62x51 FAL and
   // would not chamber -- a variant that changes the weapon and not the
   // ammunition spawns a man who cannot fire a shot, and nothing warns.
   magazines[] =
      {
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhs_grenade_mkii_mag"
      };
   respawnMagazines[] =
      {
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhs_grenade_mkii_mag"
      };
};

class PTF_Pereno_conscript: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Conscript";
   sensitivity = 1.0;
   cost = 35000;
   // Five, still a magazine short of the rifleman's load, and an F1 out of
   // the Soviet shipment rather than the rifleman's American M67. Per
   // container: the uniform takes the first aid kit (8), magazine 1 (16.5)
   // and the grenade (13.2) for 37.7 of 40; magazines 2 to 5 land in the
   // webbing at 66 of 120.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_f1"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_f1"
      };
};

// The MP44 crate. 7.92x33 Kurz is shared with nothing else on the island, so
// this man cannot be resupplied by anyone he is standing next to and nobody
// can be resupplied off him. That is exactly the kind of purchase the
// battalion makes, and it is why the rifle went to the rear-area conscripts
// rather than to anyone expected to fight a long contact.
//
// Like the M3A1 it takes no attachments, so there is no optic decision here.
//
// Per container, uniform (40) and ALICE webbing (120), after the first aid
// kit (8): magazines 1 and 2 (11.66 each) fill the uniform to 31.32,
// magazines 3 to 5 land in the webbing (34.98 of 120), and the Mk 2 (13.09)
// will not fit the uniform's remaining 8.68 so it rides in the webbing too,
// 48.07 of 120. Nothing dropped.
class PTF_Pereno_conscript_mp44: PTF_Pereno_conscript
{
   displayName = "Conscript (MP44)";
   weapons[] = {"rhs_weap_MP44", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_MP44", "Throw", "Put"};
   // Capitalisation matters: the RHS class is rhs_weap_MP44, not
   // rhs_weap_mp44. And both magazine arrays are overridden because the
   // inherited ones are 7.62x51 FAL, which this rifle cannot chamber.
   magazines[] =
      {
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhs_grenade_mkii_mag"
      };
   respawnMagazines[] =
      {
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhsgref_30Rnd_792x33_SmE_StG",
         "rhs_grenade_mkii_mag"
      };
};

// Helmet is randomised per spawn: bare and painted M1 shells in a mix, so a
// squad looks like it was issued out of a depot rather than a catalogue.
class PTF_Pereno_rifleman: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Rifleman";
   uniformClass = "PTF_U_pereno_og107_erdl";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_tanoa\m93_og107_erdl_co.paa"};
   class EventHandlers: EventHandlers
   {
      init = "if (local (_this select 0)) then {[(_this select 0), [], nil] call BIS_fnc_unitHeadgear;}";
   };
   headgearList[] =
      {
         "rhsgref_helmet_M1_bare", 3,
         "rhsgref_helmet_M1_bare_alt01", 2,
         "rhsgref_helmet_M1_painted", 2,
         "rhsgref_helmet_M1_painted_alt01", 1,
         "rhsgref_hat_M1951", 2
      };
   linkedItems[] = {"rhsgref_helmet_M1_bare", "rhsgref_alice_webbing", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_helmet_M1_bare", "rhsgref_alice_webbing", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
};

// Depot stock is not uniform. A minority of the battalion carries AKMs from
// an older aid shipment, and they do not share magazines with the FAL men.
class PTF_Pereno_rifleman_akm: PTF_Pereno_rifleman
{
   displayName = "Rifleman (AKM)";
   weapons[] = {"rhs_weap_akm", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_akm", "Throw", "Put"};
   // Six steel mags to mirror the FAL men's six. An AK magazine is lighter
   // than a FAL one, so this sits well inside the same 160.
   magazines[] =
      {
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_mag_m67"
      };
   respawnMagazines[] =
      {
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_30Rnd_762x39mm",
         "rhs_mag_m67"
      };
};

// A third shipment, and the only one that was any use to the second. The
// Zastava M70AB2 is an AKM in all but the stamping and eats the same 7.62x39,
// so this man and the AKM rifleman can at least resupply each other -- the
// one place in the battalion where two men holding different rifles are not a
// logistics problem.
//
// He inherits from the AKM rifleman rather than from the FAL one on purpose:
// the 7.62x39 magazine arrays come with him and there is nothing to get
// wrong. A variant that overrode weapons[] and not magazines[] would spawn
// with FAL magazines it cannot chamber, and the engine would not say a word.
// Per container that inherited load is the AKM man's: uniform 35.06 of 40
// (first aid kit 8, two magazines at 13.53), webbing 62.92 of 120 (four
// magazines and the M67, which does not fit the uniform's remaining 4.94).
//
// The rifle takes no optic. Note also rhs_weap_m70ab2_fold is scope 1 -- it
// is the folded model state, not a weapon, and must not be used here.
class PTF_Pereno_rifleman_m70: PTF_Pereno_rifleman_akm
{
   displayName = "Rifleman (M70AB2)";
   weapons[] = {"rhs_weap_m70ab2", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m70ab2", "Throw", "Put"};
};

// Same crate, different furniture: the fixed wood stock next to the
// underfolder. Two silhouettes out of one purchase, which is what a job lot
// actually looks like once it is issued. Magazines and grenade are inherited
// and correct -- both rifles are 7.62x39.
class PTF_Pereno_rifleman_m70b1: PTF_Pereno_rifleman_m70
{
   displayName = "Rifleman (M70B1)";
   weapons[] = {"rhs_weap_m70b1", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m70b1", "Throw", "Put"};
};

// --- Specialists -----------------------------------------------------------

// The RGD-5 goes last in the array and it has to. Per container: the first
// aid kit (8) and grenade rounds 1 to 6 (5.06 each) fill the uniform to
// 38.36 of 40, rounds 7 and 8, the two HEDP and the two pistol magazines
// (5.28 each) go to the webbing at 30.80 of 120, and the RGD-5 (6.82) will
// not fit the uniform's remaining 1.64 so it rides in the webbing at 37.62.
// The uniform is effectively full -- anything else added here lands in the
// webbing, which has room.
class PTF_Pereno_grenadier: PTF_Pereno_rifleman
{
   displayName = "Grenadier (M79)";
   cost = 90000;
   backpack = "rhsgref_hidf_alicepack_gr";
   weapons[] = {"rhs_weap_m79", "rhsusf_weap_m1911a1", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m79", "rhsusf_weap_m1911a1", "Throw", "Put"};
   magazines[] =
      {
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M433_HEDP", "rhs_mag_M433_HEDP",
         "rhsusf_mag_7x45acp_MHP", "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE", "rhs_mag_M441_HE",
         "rhs_mag_M433_HEDP", "rhs_mag_M433_HEDP",
         "rhsusf_mag_7x45acp_MHP", "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_rgd5"
      };
};

// The FN MAG is the battalion's real weapon. It is also the thing most worth
// killing first, and it only has three belts.
// He carries a white smoke as well as the frag. The gun is the thing worth
// killing first, so the gun group is the part of the battalion most likely to
// need to break contact, and AN-M8 out of the WWII depot stock is what there
// is. Per container: a 32.34 belt will not fit the uniform behind the first
// aid kit (8 + 32.34 = 40.30 against 40), so all three belts go to the
// webbing at 97.02 of 120, and the M67 (8.8) and the smoke (8.98) go to the
// uniform at 25.78 of 40. The webbing has 22.98 left, which is not another
// belt -- the spare belts ride in RHS's own preloaded alicepack_mg.
class PTF_Pereno_machinegunner: PTF_Pereno_rifleman
{
   displayName = "Machine Gunner (FN MAG)";
   cost = 130000;
   icon = "iconManMG";
   backpack = "rhsgref_hidf_alicepack_mg";
   weapons[] = {"rhs_weap_fnmag", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_fnmag", "Throw", "Put"};
   magazines[] = {"rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhs_mag_m67", "rhs_mag_an_m8hc"};
   respawnMagazines[] = {"rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhsusf_100Rnd_762x51", "rhs_mag_m67", "rhs_mag_an_m8hc"};
};

// Both arrays are written out rather than inherited, because he carries the
// gunner's white smoke on top of the base class's six magazines and M67 and
// there is no way to add one entry to an inherited array. Per container:
// uniform 33.3 of 40 (first aid kit 8, magazine 1 at 16.5, the M67 at 8.8),
// webbing 91.48 of 120 (magazines 2 to 6, then the smoke, which does not fit
// the uniform's remaining 6.7). Nothing dropped.
class PTF_Pereno_machinegunner_assist: PTF_Pereno_rifleman
{
   displayName = "Assistant Machine Gunner";
   cost = 100000;
   backpack = "rhsgref_hidf_alicepack_mg";
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_an_m8hc"
      };
};

// The AT man's spare rockets. magazines[] can only reach the uniform and the
// webbing, and their 160 is spoken for (see the class below), so rockets past
// the second live in a container the engine will not fill by itself. Same
// mechanism as rhsgref_hidf_alicepack_mg, which already carries the
// machinegunner's spare belts, and PTF_B_guardia_pkp across the fence.
// Two PG-7V is 63 of the ALICE pack's 320.
class PTF_B_pereno_rpg: rhsgref_hidf_alicepack
{
   author = "Paramarine Task Force";
   // Hidden: a loadout component, not something to place. The empty ALICE
   // pack is already in the arsenal if a mission maker wants one.
   scope = 1;
   scopeCurator = 0;
   displayName = "ALICE Pack (RPG)";
   class TransportMagazines
   {
      class _xx_rhs_rpg7_PG7V_mag
      {
         magazine = "rhs_rpg7_PG7V_mag";
         count = 2;
      };
   };
};

// Four rockets: one in the tube, one on the webbing, two in the pack. Mission
// feedback was that the AT man fired once and was finished, which made him a
// prop rather than a threat. The warhead stays PG-7V -- the garrison's RPG is
// a vehicle answer, not a fragmentation one, and the tandem rounds stay
// La Guardia's.
//
// Rockets are listed first: the engine packs Items[] and then magazines[] in
// array order, and a rifle magazine seated ahead of a 31.5-mass rocket would
// push it out. First aid kit (8) + two rockets (63) + five FAL magazines
// (82.5) = 153.5 of the 160 the uniform (40) and ALICE webbing (120) hold.
//
// He is the one fighting man in the faction with no grenade, and that is a
// capacity fact rather than a choice. Per container the uniform holds the
// first aid kit and rocket 1 at 39.46 of 40, and the webbing holds rocket 2
// and five magazines at 114 of 120. The lightest grenade in the addon is the
// RGD-5 at 6.82 and it fits neither 0.54 nor 6. Do not "just add one" -- it
// would be dropped at spawn without a word. If he ever needs one, a magazine
// has to come off the webbing to pay for it.
class PTF_Pereno_at: PTF_Pereno_rifleman
{
   displayName = "AT Rifleman (RPG-7)";
   cost = 120000;
   icon = "iconManAT";
   backpack = "PTF_B_pereno_rpg";
   weapons[] = {"rhs_weap_l1a1_wood", "rhs_weap_rpg7", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_l1a1_wood", "rhs_weap_rpg7", "Throw", "Put"};
   magazines[] =
      {
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_PG7V_mag",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
   respawnMagazines[] =
      {
         "rhs_rpg7_PG7V_mag",
         "rhs_rpg7_PG7V_mag",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal"
      };
};

// L1A1 with the old SUIT sight -- the closest thing the garrison has to a
// precision weapon, and a daylight-only one.
//
// One RGD-5 rather than an F1 or a pineapple: at 6.82 it is the lightest
// grenade in the addon, and a man whose job is to lie still and shoot should
// not be carrying 13. Per container: uniform 31.32 of 40 (first aid kit 8,
// magazine 1 at 16.5, grenade 6.82), webbing 82.5 of 120 (magazines 2 to 6).
class PTF_Pereno_marksman: PTF_Pereno_rifleman
{
   displayName = "Marksman";
   cost = 140000;
   icon = "iconManRecon";
   accuracy = 1.6;
   sensitivity = 2.0;
   weapons[] = {"rhs_weap_l1a1_suit", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_l1a1_suit", "Throw", "Put"};
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_20Rnd_762x51_m61_fnfal",
         "rhs_mag_rgd5"
      };
};

// The other precision rifle, and the best thing in the battalion's armoury:
// an accurized M14 in 7.62x51, on match ball. He stands alongside the SUIT
// man rather than replacing him -- two marksmen, two different rifles, from
// two different sellers, which is the whole faction in one line.
//
// Iron sights, deliberately. weapons[] cannot carry an attachment (the trap
// that put La Guardia's AK-103s and the Kestrel sniper on bare irons at first
// playtest), and the RHS class that mounts glass is rhs_weap_m14_rail, a
// different weapon. Baking an optic onto a custom class the way
// cfgGuardiaWeapons.hpp does would give this faction better glass than its
// own SUIT man, which is the wrong tier. Daylight only, same as everyone.
//
// The classname is the trap here. RHS's rhs_weap_m21* classes are the
// Yugoslav Zastava M21, a modern 5.56 assault rifle -- it would spawn looking
// entirely plausible and be wrong for a 1970s garrison. The US M21 is an
// accurized M14 and RHS ships it in USAF as the M14 family. Verified against
// the derapped rhsusf_c_weapons config: rhs_weap_m14 is scope 2, mass 90.2,
// and its magazines[] are the rhsusf_20Rnd_762x51_*_Mag family at 16.24 each.
// Note that rhs_mag_762x51_M14_20rnd, which turns up in a string dump of the
// same PBO, is a proxy p3d path and not a magazine class. rhsusf_c_weapons is
// already in requiredAddons, so this adds no new dependency.
//
// Per container: uniform 31.06 of 40 (first aid kit 8, magazine 1 at 16.24,
// RGD-5 6.82), webbing 81.2 of 120 (magazines 2 to 6). Nothing dropped.
class PTF_Pereno_marksman_m14: PTF_Pereno_marksman
{
   displayName = "Marksman (M14)";
   weapons[] = {"rhs_weap_m14", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m14", "Throw", "Put"};
   // Both arrays overridden: the inherited magazines are FAL-pattern and do
   // not fit an M14, even though both are 7.62x51.
   magazines[] =
      {
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhsusf_20Rnd_762x51_m118_special_Mag",
         "rhs_mag_rgd5"
      };
};

// He carries a white smoke on top of the base class's load, for the same
// reason the gun group does: getting a casualty out of the open is the other
// job in this battalion that needs a screen. His medical stores are in the
// pack, which magazines[] never reaches, so the arithmetic is the assistant
// gunner's exactly -- uniform 33.3 of 40, webbing 91.48 of 120. Both arrays
// written out because one entry cannot be appended to an inherited array.
class PTF_Pereno_medic: PTF_Pereno_rifleman
{
   displayName = "Medic";
   cost = 160000;
   attendant = 1;
   icon = "iconManMedic";
   backpack = "rhsgref_hidf_alicepack_medic";
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_an_m8hc"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_an_m8hc"
      };
};

// The engine packs per container, not against a combined total, so the sum of
// the uniform and vest capacities is the wrong number to reason with. Items[]
// go in first: the first aid kit (8) and mine detector (20) fill 28 of the
// uniform's 40, and the toolkit (80) plus two FAL magazines (33) fill 113 of
// the webbing's 120. A third magazine is 16.5 and fits neither container --
// 44.5 in the uniform, 129.5 in the webbing -- so it would be dropped at
// spawn without a word. Two is the ceiling. (The ALICE pack does not help:
// the engine only fills the uniform and vest when it distributes
// magazines[].)
//
// A grenade is a different question from a third magazine, and the answer is
// different. The uniform has 12 left after the first aid kit and the mine
// detector, and an RGD-5 is 6.82, so it fits there -- 34.82 of 40 -- with the
// webbing untouched at 113 of 120. It is the RGD-5 specifically and not an
// F1 (13.2) or a Mk 2 (13.09), either of which would be dropped. Re-do this
// arithmetic before changing anything on this class.
class PTF_Pereno_engineer: PTF_Pereno_rifleman
{
   displayName = "Engineer";
   cost = 150000;
   engineer = 1;
   canDeactivateMines = 1;
   icon = "iconManEngineer";
   backpack = "rhsgref_hidf_alicepack";
   Items[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   RespawnItems[] = {"FirstAidKit", "ToolKit", "MineDetector"};
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_rgd5"
      };
};

// The other M3A1 in the battalion, and the reason the sentry variant above
// costs the faction nothing new. No grenade on the crewman or the pilot, on
// purpose rather than for want of room: they are the men who bail out of a
// burning vehicle, not the men who assault a position, and a battalion this
// poor does not hand grenades to people who are not expected to throw them.
class PTF_Pereno_crewman: PTF_Pereno_base
{
   scope = 2;
   scopeCurator = 2;
   displayName = "Crewman";
   cost = 80000;
   weapons[] = {"rhs_weap_m3a1", "Throw", "Put"};
   respawnWeapons[] = {"rhs_weap_m3a1", "Throw", "Put"};
   magazines[] =
      {
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG"
      };
   respawnMagazines[] =
      {
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG",
         "rhsgref_30rnd_1143x23_M1911B_SMG"
      };
};

// --- Cadre -----------------------------------------------------------------
//
// The long-service NCOs are the competent half of the battalion and are
// kitted to show it. High sensitivity: these men are actually watching.
// They are also the intended point of failure -- the garrison is defeated by
// fracture, and fracture starts when the man giving orders goes down.

class PTF_Pereno_teamleader: PTF_Pereno_rifleman
{
   displayName = "Corporal";
   cost = 220000;
   accuracy = 1.8;
   sensitivity = 2.6;
   icon = "iconManLeader";
   uniformClass = "PTF_U_pereno_erdl";
   hiddenSelectionsTextures[] = {"\rhsgref\addons\rhsgref_infantry\data_tanoa\m93_erdl_co.paa"};
   headgearList[] = {"rhsgref_helmet_M1_painted", 2, "rhsgref_helmet_M1_painted_alt01", 1};
   linkedItems[] = {"rhsgref_helmet_M1_painted", "rhsgref_chestrig", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_helmet_M1_painted", "rhsgref_chestrig", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_l1a1", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_l1a1", "Throw", "Put", "Binocular"};
   // Six fit: the chest rig (100) and uniform (40) hold 140, and the first
   // aid kit (8) + six FAL magazines (99) + grenade and smoke (8.8, 11.9)
   // come to 127.7.
   //
   // He is full, and the per-container split is why. Uniform 33.3 of 40
   // (first aid kit, magazine 1, the M67), chest rig 94.38 of 100 (magazines
   // 2 to 6 and the red smoke). That leaves 6.7 and 5.62, and the lightest
   // grenade in the addon is 6.82. A second smoke does not go on the corporal
   // -- it goes on the sergeant, who has the vest for it.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_m18_red"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_m18_red"
      };
};

class PTF_Pereno_squadleader: PTF_Pereno_teamleader
{
   displayName = "Sergeant";
   cost = 320000;
   accuracy = 2.0;
   sensitivity = 3.0;
   headgearList[] = {"rhsgref_helmet_pasgt_erdl", 3, "rhsgref_helmet_pasgt_olive", 1};
   linkedItems[] = {"rhsgref_helmet_pasgt_erdl", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_helmet_pasgt_erdl", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   // Same 140 of capacity as the Corporal, carrying a second smoke on top,
   // but the split is what matters: the uniform is at 33.30 of 40 and the
   // vest at 89.76 of 100. A sixth magazine is 16.5 and fits neither, so it
   // would be dropped at spawn. Five is the ceiling here.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_m18_red",
         "rhs_mag_m18_yellow"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_m67",
         "rhs_mag_m18_red",
         "rhs_mag_m18_yellow"
      };
};

class PTF_Pereno_officer: PTF_Pereno_squadleader
{
   displayName = "Lieutenant";
   cost = 400000;
   sensitivity = 2.8;
   icon = "iconManOfficer";
   headgearList[] = {"rhsgref_hat_M1951", 2, "rhsgref_helmet_pasgt_erdl", 1};
   linkedItems[] = {"rhsgref_hat_M1951", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_hat_M1951", "rhsgref_TacVest_ERDL", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhs_weap_l1a1", "rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhs_weap_l1a1", "rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   // Five rifle magazines now that the line carries six: 8 + 82.5 + two
   // smokes (23.8) is 114.3 of 140, and the two pistol magazines fit in
   // what is left with room to spare.
   //
   // The RGD-5 goes last and lands in the vest, not the uniform. Per
   // container: uniform 35.06 of 40 (first aid kit 8, magazine 1 at 16.5,
   // both pistol magazines at 5.28), ERDL tac vest 96.58 of 100 (magazines 2
   // to 5, both smokes at 11.88, then the grenade at 6.82, which does not fit
   // the uniform's remaining 4.94). That is 3.42 of headroom left in the vest
   // and nothing worth adding fits it.
   magazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_m18_red",
         "rhs_mag_m18_purple",
         "rhs_mag_rgd5"
      };
   respawnMagazines[] =
      {
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhs_mag_20Rnd_762x51_m80_fnfal",
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_m18_red",
         "rhs_mag_m18_purple",
         "rhs_mag_rgd5"
      };
};

// --- HVT -------------------------------------------------------------------
//
// Deliberately readable at a distance so players can pick him out of a group:
// no helmet, a distinct cap, a pistol instead of a rifle, and binoculars.
// The garrison is defeated by fracture, and this is the man whose loss starts
// it -- taking him should feel like it changed something.
//
// He keeps his single red smoke and gets no frag, unlike the lieutenant he
// inherits from. That is the soft silhouette doing its job: a battalion
// commander with a pistol and a signal grenade reads differently from one
// kitted to fight, and the point of him is that he is worth taking alive.
class PTF_Pereno_hvt: PTF_Pereno_officer
{
   displayName = "Battalion Commander (HVT)";
   cost = 900000;
   accuracy = 2.2;
   sensitivity = 3.0;
   icon = "iconManOfficer";
   headgearList[] = {"rhsgref_hat_M1951", 1};
   linkedItems[] = {"rhsgref_hat_M1951", "rhsgref_chestrig", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   respawnLinkedItems[] = {"rhsgref_hat_M1951", "rhsgref_chestrig", "ItemMap", "ItemCompass", "ItemWatch", "ItemRadio"};
   weapons[] = {"rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   respawnWeapons[] = {"rhsusf_weap_m1911a1", "Throw", "Put", "Binocular"};
   magazines[] =
      {
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_m18_red"
      };
   respawnMagazines[] =
      {
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhsusf_mag_7x45acp_MHP",
         "rhs_mag_m18_red"
      };
};

// A crewman who flies. No flight suit, no survival vest -- the battalion's
// pilots dress like everyone else because they are everyone else.
class PTF_Pereno_pilot: PTF_Pereno_crewman
{
   displayName = "Pilot";
   cost = 150000;
};
