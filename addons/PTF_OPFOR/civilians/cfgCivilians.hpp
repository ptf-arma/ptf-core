// ---------------------------------------------------------------------------
// Valmeran civilians. Unarmed, indigenous islanders, Caribbean wardrobe.
//
// Built on Apex's Tanoan civilians -- correct faces, correct clothes, correct
// island feel -- rebadged onto a Valmeran faction with the Spanish name pool.
// LanguageFRE_F stays: it is the closest thing Arma has to a Caribbean creole
// voice, and it is what every Tanoan civilian ships with.
//
// No weapons anywhere in this file, deliberately and permanently.
// ---------------------------------------------------------------------------

// --- People ---------------------------------------------------------------

#define PTF_CIV_COMMON \
   author = "Paramarine Task Force"; \
   faction = "PTF_CIV_Valmera"; \
   genericNames = "PTF_ValmeranMen"; \
   editorSubcategory = "EdSubcat_Personnel"; \
   identityTypes[] = {"LanguageFRE_F", "Head_Tanoan", "Head_Tanoan", "Head_African", "G_CIV_exp"}

class PTF_Civ_isleno_1: C_man_sport_1_F_tanoan
{
   PTF_CIV_COMMON;
   scope = 2; scopeCurator = 2;
   displayName = "Islander";
};
class PTF_Civ_isleno_2: C_man_sport_2_F_tanoan
{
   PTF_CIV_COMMON;
   scope = 2; scopeCurator = 2;
   displayName = "Islander (Shirt)";
};
class PTF_Civ_pescador: C_man_sport_3_F_tanoan
{
   PTF_CIV_COMMON;
   scope = 2; scopeCurator = 2;
   displayName = "Fisherman";
};
class PTF_Civ_aldeano_1: C_Man_casual_1_F_tanoan
{
   PTF_CIV_COMMON;
   scope = 2; scopeCurator = 2;
   displayName = "Villager";
};
class PTF_Civ_aldeano_2: C_Man_casual_2_F_tanoan
{
   PTF_CIV_COMMON;
   scope = 2; scopeCurator = 2;
   displayName = "Villager (Guayabera)";
};
class PTF_Civ_agricultor: C_Man_casual_3_F_tanoan
{
   PTF_CIV_COMMON;
   scope = 2; scopeCurator = 2;
   displayName = "Farmer";
};
class PTF_Civ_comerciante: C_Man_casual_4_F_tanoan
{
   PTF_CIV_COMMON;
   scope = 2; scopeCurator = 2;
   displayName = "Shopkeeper";
};
class PTF_Civ_obrero: C_Man_casual_5_F_tanoan
{
   PTF_CIV_COMMON;
   scope = 2; scopeCurator = 2;
   displayName = "Laborer";
};
class PTF_Civ_anciano: C_Man_casual_6_F_tanoan
{
   PTF_CIV_COMMON;
   scope = 2; scopeCurator = 2;
   displayName = "Elder";
};

// --- Vehicles --------------------------------------------------------------

#define PTF_CIVVEH_COMMON \
   author = "Paramarine Task Force"; \
   faction = "PTF_CIV_Valmera"; \
   crew = "PTF_Civ_isleno_1"

class PTF_Civ_hatchback: C_Hatchback_01_F
{
   PTF_CIVVEH_COMMON;
   scope = 2; scopeCurator = 2;
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Old Car";
};
class PTF_Civ_suv: C_SUV_01_F
{
   PTF_CIVVEH_COMMON;
   scope = 2; scopeCurator = 2;
   editorSubcategory = "EdSubcat_Cars";
   displayName = "SUV";
};
class PTF_Civ_van: C_Van_01_transport_F
{
   PTF_CIVVEH_COMMON;
   scope = 2; scopeCurator = 2;
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Van (Passenger)";
};
class PTF_Civ_van_box: C_Van_01_box_F
{
   PTF_CIVVEH_COMMON;
   scope = 2; scopeCurator = 2;
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Van (Cargo)";
};
class PTF_Civ_offroad: C_Offroad_02_unarmed_F
{
   PTF_CIVVEH_COMMON;
   scope = 2; scopeCurator = 2;
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Farm Pickup";
};
class PTF_Civ_truck_box: C_Truck_02_box_F
{
   PTF_CIVVEH_COMMON;
   scope = 2; scopeCurator = 2;
   editorSubcategory = "EdSubcat_Cars";
   displayName = "Delivery Truck";
};

// The island lives off the water.
class PTF_Civ_fishboat: C_Boat_Transport_02_F
{
   PTF_CIVVEH_COMMON;
   scope = 2; scopeCurator = 2;
   editorSubcategory = "EdSubcat_Boats";
   displayName = "Fishing Boat";
};
class PTF_Civ_motorboat: C_Boat_Civil_01_F
{
   PTF_CIVVEH_COMMON;
   scope = 2; scopeCurator = 2;
   editorSubcategory = "EdSubcat_Boats";
   displayName = "Motorboat";
};
class PTF_Civ_canoe: rhsgref_civ_canoe
{
   PTF_CIVVEH_COMMON;
   scope = 2; scopeCurator = 2;
   editorSubcategory = "EdSubcat_Boats";
   displayName = "Canoe";
};
