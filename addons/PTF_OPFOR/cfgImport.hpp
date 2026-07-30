// External base classes, forward-declared so we can inherit from them.
// Declared inside class CfgVehicles by config.cpp -- these are CfgVehicles
// subclasses, so declaring them at root scope would not resolve.


// RHS GREF -- Horizon Islands Defence Force infantry base.
// Chosen because it is RHS's tropical-island garrison: ERDL/OG-107 fatigues,
// M1 steel helmets, ALICE webbing and L1A1 rifles on the guerrilla m93 model.
class rhsgref_hidf_base;

// RHS GREF -- soft-skin and armour we rebadge for the garrison motor pool.
class rhsgref_ins_g_uaz_open;
class rhsgref_ins_g_uaz_dshkm_chdkz;
class rhsgref_ins_g_ural;
class rhsgref_ins_g_ural_open;
class rhsgref_ins_g_gaz66;
class rhsgref_BRDM2_ins_g;
class rhsgref_hidf_m1025;
class rhsgref_hidf_m1025_m2;
class rhsgref_hidf_m113a3_m2;
class rhsgref_hidf_m113a3_unarmed;

// RHS GREF -- static weapons for checkpoints and fixed positions.
class rhsgref_ins_g_DSHKM;
class rhsgref_ins_g_SPG9;
class rhsgref_ins_g_2b14;

// --- La Guardia ------------------------------------------------------------

// RHS GREF -- insurgent base wearing the Spectre-SKWO uniform. Already EAST,
// and uses the EMR body model, which carries a separate vest rather than the
// integrated webbing of the HIDF model los Perenos are built on. That is what
// lets La Guardia wear modern plate carriers.
class rhsgref_ins_uniform_specter;

// RHS USAF -- Eagle A-III assault pack in coyote, the base for the
// machinegunner's belt pack. Coyote because every carrier in the faction is a
// coyote MBAV; nothing else in La Guardia wears a backpack at all.
class rhsusf_assault_eagleaiii_coy;

class rhsgref_ins_g_uaz_ags;
class rhsgref_ins_g_uaz_spg9;
class rhsgref_ins_g_btr70;
class rhsgref_ins_g_bmp2;
class rhsgref_ins_g_AGS30_TriPod;
class rhsgref_ins_g_NSV_TriPod;

// --- Kestrel Group ---------------------------------------------------------

// RHS GREF -- "national" base. Shares the gue_m93 body model across DPM,
// French lizard, US woodland and 3-colour desert textures, which is what lets
// one Kestrel base class field four different national camouflage patterns.
class rhsgref_nat_base;

// Air defence. The ZU-23-2 and the Igla pod are the island's system; Kestrel
// inherited it with the site and know how to run it.
class rhsgref_ins_g_ZU23;
class rhsgref_ins_g_Igla_AA_pod;
class rhsgref_serhat_radar;

// RHS USAF -- woodland HMMWV. Kestrel use this rather than the HIDF green one
// so their vehicles read as brought-in rather than locally sourced, while
// still suiting a tropical island.
class rhsusf_m1025_w_m2;

// --- Roster expansion ------------------------------------------------------
// los Perenos: more trucks, gun-only AA, boats and old utility helicopters.
// rhsgref_ins_* (no _g) is the EAST/ChDKZ set -- natively side = 0.
class rhsgref_ins_zil131;
class rhsgref_ins_kraz255b1_fuel;
class rhsgref_ins_gaz66_ammo;
class rhsgref_ins_ural_Zu23;
class rhsgref_ins_gaz66_zu23;
class rhsgref_ins_ZU23;
class rhsgref_ins_Mi8amt;
class rhsgref_ins_zsu234;
class rhsgref_ins_d30;

// Boats: RHS has NO boats outside the HIDF (BLUFOR) set, so every boat in the
// campaign is a HIDF hull with side/faction/crew overridden.
class rhsgref_hidf_assault_boat;
class rhsgref_hidf_rhib;
class rhsgref_hidf_canoe;

// GREF Hueys -- ex-US aid, exactly what a poor island garrison would fly.
class rhs_uh1h_hidf_unarmed;
class rhs_uh1h_hidf_gunship;

// La Guardia: modern Soviet logistics and air.
class rhs_kamaz5350_msv;
class rhs_kamaz5350_ammo_msv;
class rhs_kamaz5350_open_msv;
class RHS_Ural_Zu23_MSV_01;
class rhsgref_cdf_reg_Mi17Sh;
class rhsgref_cdf_Mi35;

// Kestrel: US contractor kit -- MRZR, cargo HMMWVs, little birds, and their
// own air-defence layer (Stinger pod + a manned P-37 search radar).
class rhsusf_mrzr4_w;
class rhsusf_m998_w_4dr_fulltop;
class rhsusf_m1025_w;
class RHS_Stinger_AA_pod_WD;
class rhs_p37_turret_vpvo;
class RHS_MELB_MH6M;
class RHS_MELB_AH6M_L;

// --- Flags -----------------------------------------------------------------
// Vanilla military flag mast (Mast_F.p3d), the base every Flag_*_F class
// inherits. Gives us the pole model and the flag proxy; we only override the
// init handler that calls setFlagTexture. NOT FlagChecked_F -- that is the
// checkered racing flag and its cloth UV renders the design badly offset.
class FlagCarrierCore;
class FlagCarrier;

// --- El Sindicato ----------------------------------------------------------
// Vanilla FIA guerrilla base (side 2, wears vanilla guerrilla/civ clothing
// models) and the union's civilian vehicles.
class I_G_Soldier_base_F;
class C_Offroad_01_F;
class I_G_Offroad_01_armed_F;
class C_Hatchback_01_F;
class rhsgref_nat_van;
class rhsgref_nat_van_fuel;
class RHS_Ural_Civ_01;
class RHS_Ural_Open_Civ_01;
class rhsgref_civ_canoe;
class C_Boat_Transport_02_F;

// --- Valmeran civilians ----------------------------------------------------
class C_man_sport_1_F_tanoan;
class C_man_sport_2_F_tanoan;
class C_man_sport_3_F_tanoan;
class C_Man_casual_1_F_tanoan;
class C_Man_casual_2_F_tanoan;
class C_Man_casual_3_F_tanoan;
class C_Man_casual_4_F_tanoan;
class C_Man_casual_5_F_tanoan;
class C_Man_casual_6_F_tanoan;
class C_SUV_01_F;
class C_Van_01_transport_F;
class C_Van_01_box_F;
class C_Offroad_02_unarmed_F;
class C_Truck_02_box_F;
class C_Boat_Civil_01_F;

// Vanilla base for the two preloaded AA missile packs.
class B_Carryall_cbr;
