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

// --- Flags -----------------------------------------------------------------
// Vanilla flagpole. Inheriting it gives us the pole model and the flag proxy;
// we only override the init handler that calls setFlagTexture.
class FlagCarrierCore;
class FlagChecked_F;
