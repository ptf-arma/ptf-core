// ---------------------------------------------------------------------------
// El Sindicato motor pool: the union's own trucks, requisitioned pickups, and
// exactly one gun truck per work crew. Nothing military except what got
// bolted on.
// ---------------------------------------------------------------------------

class PTF_Sind_offroad: C_Offroad_01_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Sindicato";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Camioneta";
   crew = "PTF_Sind_miliciano";
   typicalCargo[] = {"PTF_Sind_miliciano", "PTF_Sind_estibador"};
};

// The technical: the union's answer to fourteen months of occupation.
class PTF_Sind_technical: I_G_Offroad_01_armed_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Sindicato";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Camioneta (M2)";
   crew = "PTF_Sind_miliciano";
   typicalCargo[] = {"PTF_Sind_miliciano", "PTF_Sind_miliciano_akms"};
};

class PTF_Sind_van: rhsgref_nat_van
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Sindicato";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Furgoneta del Sindicato";
   crew = "PTF_Sind_miliciano";
   typicalCargo[] = {"PTF_Sind_miliciano"};
};

class PTF_Sind_van_fuel: rhsgref_nat_van_fuel
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Sindicato";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Furgoneta (Combustible)";
   crew = "PTF_Sind_miliciano";
   typicalCargo[] = {"PTF_Sind_miliciano"};
};

// The timber trucks. Half the reason anyone negotiates with the union.
class PTF_Sind_ural: RHS_Ural_Civ_01
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Sindicato";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Camion Maderero";
   crew = "PTF_Sind_miliciano";
   typicalCargo[] = {"PTF_Sind_miliciano"};
};

class PTF_Sind_ural_open: RHS_Ural_Open_Civ_01
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Sindicato";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Camion Maderero (Abierto)";
   crew = "PTF_Sind_miliciano";
   typicalCargo[] = {"PTF_Sind_miliciano", "PTF_Sind_maderero"};
};

class PTF_Sind_hatchback: C_Hatchback_01_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Sindicato";
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Coche";
   crew = "PTF_Sind_enlace";
   typicalCargo[] = {"PTF_Sind_enlace"};
};

// --- The port ---------------------------------------------------------------

class PTF_Sind_boat: C_Boat_Transport_02_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Sindicato";
   editorSubcategory = "EdSubcat_Boats";
   displayName = "Lancha del Puerto";
   crew = "PTF_Sind_miliciano";
   typicalCargo[] = {"PTF_Sind_miliciano", "PTF_Sind_estibador"};
};

class PTF_Sind_canoe: rhsgref_civ_canoe
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   side = 2;
   faction = "PTF_IND_Sindicato";
   editorSubcategory = "EdSubcat_Boats";
   displayName = "Canoa";
   crew = "PTF_Sind_miliciano";
};
