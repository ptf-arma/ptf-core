// Shared PTF infantry-vest definition.
//
// Every PTF infantry vest below re-armours a DIFFERENT external base vest
// (USP CRYE, RHS MBAV/SPC, Peral JPC, ...) to the same PTF standard:
//   scope/side/faction/author, containerClass "Supply250", mass 40, and an
//   identical Chest/Diaphragm/Body HitpointsProtectionInfo override.
//
// A shared *base class* cannot be used here: each vest must keep its own
// external parent (single inheritance), and `class HitpointsProtectionInfo {}`
// with no explicit parent implicitly inherits the parent vest's protection
// info. Redirecting it to a PTF base with `: PTF_Base {}` would silently drop
// any hitpoints the (unseen, binarised) external parents define beyond the
// three overridden here, changing armour behaviour. A macro expands to the
// exact same tokens the file had before, so behaviour is preserved verbatim.
#define PTF_VEST_ARMOR_BASE(NAME) \
   scope = 2; \
   side = 1; \
   faction = "BLU_F"; \
   displayName = NAME; \
   author = "Paramarine Task Force"; \
   class ItemInfo : ItemInfo \
   { \
      containerClass = "Supply250"; \
      mass = 40; \
      class HitpointsProtectionInfo \
      { \
         class Chest { HitpointName = "HitChest"; armor = 28; PassThrough = 0.1; }; \
         class Diaphragm { HitpointName = "HitDiaphragm"; armor = 28; PassThrough = 0.1; }; \
         class Body { hitpointName = "HitBody"; passThrough = 0.4; }; \
      }; \
   };

class PTF_Vest_Infantry_CRYE : USP_CRYE_CPC
{
   PTF_VEST_ARMOR_BASE("[Inf] Crye [PTF]")
};
class PTF_Vest_Infantry_CRYE_Comms : USP_CRYE_CPC_COMMS
{
   PTF_VEST_ARMOR_BASE("[Inf] Crye (Comms) [PTF]")
};
class PTF_Vest_Infantry_CRYE_Fast : USP_CRYE_CPC_FAST_BELT
{
   PTF_VEST_ARMOR_BASE("[Inf] Crye (FAST) [PTF]")
};
class PTF_Vest_Infantry_CRYE_Lead : USP_CRYE_CPC_LEAD_BELT
{
   PTF_VEST_ARMOR_BASE("[Inf] Crye (Leader) [PTF]")
};
class PTF_Vest_Infantry_CRYE_Light : USP_CRYE_CPC_LIGHT_BELT
{
   PTF_VEST_ARMOR_BASE("[Inf] Crye (Light) [PTF]")
};
class PTF_Vest_Infantry_CRYE_Medic : USP_CRYE_CPC_MEDIC
{
   PTF_VEST_ARMOR_BASE("[Inf] Crye (Medic) [PTF]")
};
class PTF_Vest_Infantry_CRYE_Rifleman : USP_CRYE_CPC_WEAPON
{
   PTF_VEST_ARMOR_BASE("[Inf] Crye (Rifleman) [PTF]")
};
class PTF_Vest_Infantry_MBAV : rhsusf_mbav
{
   PTF_VEST_ARMOR_BASE("[Inf] MBAV [PTF]")
};
class PTF_Vest_Infantry_MBAV_Grenadier : rhsusf_mbav_grenadier
{
   PTF_VEST_ARMOR_BASE("[Inf] MBAV (Grenadier) [PTF]")
};
class PTF_Vest_Infantry_MBAV_Light : rhsusf_mbav_light
{
   PTF_VEST_ARMOR_BASE("[Inf] MBAV (Light) [PTF]")
};
class PTF_Vest_Infantry_MBAV_MG : rhsusf_mbav_mg
{
   PTF_VEST_ARMOR_BASE("[Inf] MBAV (MG) [PTF]")
};
class PTF_Vest_Infantry_MBAV_Medic : rhsusf_mbav_medic
{
   PTF_VEST_ARMOR_BASE("[Inf] MBAV (Medic) [PTF]")
};
class PTF_Vest_Infantry_MBAV_Rifleman : rhsusf_mbav_rifleman
{
   PTF_VEST_ARMOR_BASE("[Inf] MBAV (Rifleman) [PTF]")
};
class PTF_Vest_Infantry_SPC : rhsusf_spc
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC [PTF]")
};
class PTF_Vest_Infantry_SPC_Medic : rhsusf_spc_corpsman
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC (Medic) [PTF]")
};
class PTF_Vest_Infantry_SPC_Crewman : rhsusf_spc_crewman
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC (Crewman) [PTF]")
};
class PTF_Vest_Infantry_SPC_IAR : rhsusf_spc_iar
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC (IAR) [PTF]")
};
class PTF_Vest_Infantry_SPC_Light : rhsusf_spc_light
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC (Light) [PTF]")
};
class PTF_Vest_Infantry_SPC_Marksman : rhsusf_spc_marksman
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC (Marksman) [PTF]")
};
class PTF_Vest_Infantry_SPC_Rifleman : rhsusf_spc_rifleman
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC (Rifleman) [PTF]")
};
class PTF_Vest_Infantry_SPC_Sniper : rhsusf_spc_sniper
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC (Sniper) [PTF]")
};
class PTF_Vest_Infantry_SPC_SquadLeader : rhsusf_spc_squadleader
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC (Squad Leader) [PTF]")
};
class PTF_Vest_Infantry_SPC_TeamLeader : rhsusf_spc_teamleader
{
   PTF_VEST_ARMOR_BASE("[Inf] SPC (Team Leader) [PTF]")
};

class PTF_Vest_Infantry_Strandhogg : USP_VEST_STRANDHOGG2_CBR
{
   PTF_VEST_ARMOR_BASE("[Inf] Strandhogg [PTF]")
};

class PTF_Vest_Infantry_JPC_JTAC_Tan : JPC_2_JTAC_Tan
{
   PTF_VEST_ARMOR_BASE("[Inf] JPC (JTAC) [PTF]")
};

class PTF_Vest_Infantry_JPC_Marksman_Tan : JPC_2_Marksman_Tan
{
   PTF_VEST_ARMOR_BASE("[Inf] JPC (Marksman) [PTF]")
};

class PTF_Vest_Infantry_JPC_SL_Tan : JPC_2_SL_Tan
{
   PTF_VEST_ARMOR_BASE("[Inf] JPC (Squad Leader) [PTF]")
};

#undef PTF_VEST_ARMOR_BASE
