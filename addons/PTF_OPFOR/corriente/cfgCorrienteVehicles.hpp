// ---------------------------------------------------------------------------
// La Corriente motor pool -- pickups, gun trucks, river boats and one cheap
// drone. The deck: "technicals, fast river boats and cheap FPV drones", and
// "controls most river crossings on the front".
//
// Nothing armoured, nothing military-painted. The cartel's strength is that
// its vehicles look like everyone else's until the gun comes off the tarp.
// ---------------------------------------------------------------------------

class PTF_Corr_offroad: C_Offroad_01_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Pickup";
   crew = "PTF_Corr_miliciano";
   typicalCargo[] = {"PTF_Corr_miliciano", "PTF_Corr_miliciano_akms"};
};

class PTF_Corr_technical: I_G_Offroad_01_armed_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Technical (M2)";
   crew = "PTF_Corr_miliciano";
   typicalCargo[] = {"PTF_Corr_miliciano", "PTF_Corr_miliciano_akms"};
};

// The push toward the coast, in vehicle form: a recoilless gun in a pickup
// bed. This is the cartel asset the NAC actually fears.
class PTF_Corr_technical_at: I_G_Offroad_01_AT_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Technical (SPG-9)";
   crew = "PTF_Corr_miliciano";
   typicalCargo[] = {"PTF_Corr_miliciano"};
};

class PTF_Corr_van: rhsgref_nat_van
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Van";
   crew = "PTF_Corr_miliciano";
   typicalCargo[] = {"PTF_Corr_miliciano"};
};

// The lookout network's wheels. A hatchback with a halcon in it is the
// cartel's forward observer post, and it looks exactly like every other
// hatchback in town -- which is the point, and the problem.
class PTF_Corr_hatchback: C_Hatchback_01_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Courier Car";
   crew = "PTF_Corr_halcon";
   typicalCargo[] = {"PTF_Corr_halcon"};
};

// The boats do not run on goodwill. Fuel is the cartel's real logistics
// problem in the marshes, which makes this van a better mission objective
// than any gun truck.
class PTF_Corr_van_fuel: rhsgref_nat_van_fuel
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Van (Fuel)";
   crew = "PTF_Corr_miliciano";
   typicalCargo[] = {"PTF_Corr_miliciano"};
};

// Product moves in something that was hauling plantains yesterday.
class PTF_Corr_ural: RHS_Ural_Civ_01
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Cargo Truck";
   crew = "PTF_Corr_miliciano";
   typicalCargo[] = {"PTF_Corr_miliciano"};
};

// And men move in the open one, a dozen at a time, when a village changes
// hands. The gray zone's troop transport.
class PTF_Corr_ural_open: RHS_Ural_Open_Civ_01
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Cargo Truck (Open)";
   crew = "PTF_Corr_miliciano";
   typicalCargo[] = {"PTF_Corr_miliciano", "PTF_Corr_miliciano_akms"};
};

// --- The rivers --------------------------------------------------------------
// "Boats: often the fastest way to move. The cartel controls most river
// traffic." These two hulls are that sentence.

class PTF_Corr_lancha: C_Boat_Transport_02_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Boats";
   displayName = "Fast Boat";
   crew = "PTF_Corr_lanchero";
   typicalCargo[] = {"PTF_Corr_lanchero", "PTF_Corr_miliciano"};
};

// The HIDF hull again -- RHS has no boats outside the HIDF set, so like the
// Pereno boats this is a side/faction/crew rebadge, to Independent this time.
class PTF_Corr_bote: rhsgref_hidf_assault_boat
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Boats";
   displayName = "River Boat";
   crew = "PTF_Corr_lanchero";
   typicalCargo[] = {"PTF_Corr_lanchero", "PTF_Corr_miliciano"};
};

// "Season: dry. Some channels are shallow enough to ford." A canoe goes
// where the fast boat grounds, which is why the product still moves after
// the NAC mines the main channel.
class PTF_Corr_canoe: rhsgref_civ_canoe
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Boats";
   displayName = "Canoe";
   crew = "PTF_Corr_lanchero";
};

// --- The crossings -----------------------------------------------------------

// "Bridges: few, and all are checkpointed." This is what does the
// checkpointing.
class PTF_Corr_dshkm: rhsgref_ins_g_DSHKM
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Turrets";
   displayName = "DShKM";
   crew = "PTF_Corr_miliciano";
};

// The DShKM stops trucks; this stops the NAC's handful of light armour and
// anything on the water bigger than a canoe.
class PTF_Corr_spg9: rhsgref_ins_g_SPG9
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Turrets";
   displayName = "SPG-9";
   crew = "PTF_Corr_miliciano";
};

// The coalition is "pushing toward the coast", and a push needs something
// that reaches over the treeline. One tube, not a battery: cartel indirect
// fire is a statement, not a fire plan.
class PTF_Corr_2b14: rhsgref_ins_g_2b14
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Artillery";
   displayName = "2B14 Mortar (82mm)";
   crew = "PTF_Corr_miliciano";
};

// --- The eyes ----------------------------------------------------------------

// A commercial quadcopter with the serial number filed off. Placeable so a
// mission maker can park one over a checkpoint without fielding the operator.
class PTF_Corr_darter: I_UAV_01_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Corriente";
   editorSubcategory = "EdSubcat_Drones";
   displayName = "Scout Drone (AR-2)";
};
