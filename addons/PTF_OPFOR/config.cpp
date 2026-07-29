class cfgPatches
{
   class PTF_OPFOR
   {
      units[] =
         {
            // Batallon de Infanteria No. 7 "Pera" -- infantry
            "PTF_Pereno_sentry",
            "PTF_Pereno_conscript",
            "PTF_Pereno_rifleman",
            "PTF_Pereno_rifleman_akm",
            "PTF_Pereno_grenadier",
            "PTF_Pereno_machinegunner",
            "PTF_Pereno_machinegunner_assist",
            "PTF_Pereno_at",
            "PTF_Pereno_marksman",
            "PTF_Pereno_medic",
            "PTF_Pereno_engineer",
            "PTF_Pereno_crewman",
            "PTF_Pereno_teamleader",
            "PTF_Pereno_squadleader",
            "PTF_Pereno_officer",
            "PTF_Pereno_hvt",
            // Batallon de Infanteria No. 7 "Pera" -- vehicles and emplacements
            "PTF_Pereno_uaz_open",
            "PTF_Pereno_uaz_dshkm",
            "PTF_Pereno_ural",
            "PTF_Pereno_ural_open",
            "PTF_Pereno_gaz66",
            "PTF_Pereno_m1025",
            "PTF_Pereno_m1025_m2",
            "PTF_Pereno_brdm2",
            "PTF_Pereno_m113_unarmed",
            "PTF_Pereno_m113_m2",
            "PTF_Pereno_dshkm",
            "PTF_Pereno_spg9",
            "PTF_Pereno_2b14",
            "PTF_Pereno_pilot",
            "PTF_Pereno_zil131",
            "PTF_Pereno_gaz66_ammo",
            "PTF_Pereno_kraz_fuel",
            "PTF_Pereno_zu23",
            "PTF_Pereno_ural_zu23",
            "PTF_Pereno_gaz66_zu23",
            "PTF_Pereno_boat",
            "PTF_Pereno_canoe",
            "PTF_Pereno_mi8",
            "PTF_Pereno_uh1h",
            "PTF_Pereno_uh1h_gunship",
            // La Guardia (Destacamento Especial Bastida) -- infantry
            "PTF_Guardia_rifleman",
            "PTF_Guardia_rifleman_vet",
            "PTF_Guardia_grenadier",
            "PTF_Guardia_machinegunner",
            "PTF_Guardia_at",
            "PTF_Guardia_marksman",
            "PTF_Guardia_medic",
            "PTF_Guardia_engineer",
            "PTF_Guardia_crewman",
            "PTF_Guardia_teamleader",
            "PTF_Guardia_squadleader",
            "PTF_Guardia_officer",
            "PTF_Guardia_hvt",
            // La Guardia -- vehicles and emplacements
            "PTF_Guardia_uaz_ags",
            "PTF_Guardia_uaz_spg9",
            "PTF_Guardia_ural",
            "PTF_Guardia_btr70",
            "PTF_Guardia_bmp2",
            "PTF_Guardia_ags30",
            "PTF_Guardia_nsv",
            "PTF_Guardia_pilot",
            "PTF_Guardia_kamaz",
            "PTF_Guardia_kamaz_ammo",
            "PTF_Guardia_kamaz_open",
            "PTF_Guardia_ural_zu23",
            "PTF_Guardia_zsu234",
            "PTF_Guardia_rhib",
            "PTF_Guardia_mi17",
            "PTF_Guardia_mi35",
            // Kestrel Group -- contractors
            "PTF_Kestrel_operator",
            "PTF_Kestrel_operator_dpm",
            "PTF_Kestrel_operator_lizard",
            "PTF_Kestrel_operator_desert",
            "PTF_Kestrel_machinegunner",
            "PTF_Kestrel_marksman",
            "PTF_Kestrel_sniper",
            "PTF_Kestrel_antimateriel",
            "PTF_Kestrel_aa_stinger",
            "PTF_Kestrel_aa_igla",
            "PTF_Kestrel_medic",
            "PTF_Kestrel_breacher",
            "PTF_Kestrel_crewman",
            "PTF_Kestrel_teamleader",
            "PTF_Kestrel_commander",
            "PTF_Kestrel_hvt",
            // Kestrel Group -- air defence and site assets
            "PTF_Kestrel_zu23",
            "PTF_Kestrel_igla_pod",
            "PTF_Kestrel_radar",
            "PTF_Kestrel_m1025_m2",
            "PTF_Kestrel_pilot",
            "PTF_Kestrel_mrzr",
            "PTF_Kestrel_m998",
            "PTF_Kestrel_m1025",
            "PTF_Kestrel_stinger_pod",
            "PTF_Kestrel_p37",
            "PTF_Kestrel_mh6",
            "PTF_Kestrel_ah6",
            // Flags
            "PTF_Flag_Valmera_F",
            "PTF_Flag_Perenos_F",
            "PTF_Flag_Guardia_F",
            "PTF_Flag_Kestrel_F"
         };
      weapons[] =
         {
            "PTF_weap_guardia_ak103",
            "PTF_weap_guardia_ak103_mdo",
            "PTF_weap_guardia_ak103_gp25",
            "PTF_weap_kestrel_xm2010",
            "PTF_weap_kestrel_m107",
            "PTF_U_pereno_og107",
            "PTF_U_pereno_og107_erdl",
            "PTF_U_pereno_erdl",
            "PTF_U_kestrel_wdl",
            "PTF_U_kestrel_dpm",
            "PTF_U_kestrel_lizard",
            "PTF_U_kestrel_desert",
            "PTF_U_kestrel_olive"
         };
      requiredVersion = "0.1";
      requiredAddons[] =
         {
            "PTF_Main",
            "A3_Characters_F",
            "A3_Weapons_F",
            "A3_Structures_F_Mil_Flags",
            "rhsgref_c_troops",
            "rhsgref_c_weapons",
            "rhsgref_c_vehicles_ret",
            "rhsgref_c_a2port_armor",
            "rhsgref_c_radar",
            "rhs_c_weapons",
            "rhsusf_c_weapons",
            "rhsusf_c_troops",
            "rhsusf_c_hmmwv",
            // Roster expansion
            "rhsgref_c_canoe",
            "rhsgref_c_air",
            "rhs_c_kamaz",
            "rhs_c_a2port_car",
            "rhs_c_radars",
            "rhsusf_c_statics",
            "rhsusf_c_melb",
            "rhsusf_c_mrzr"
         };
   };
};

#include "cfgFactions.hpp"
#include "cfgNames.hpp"

class CfgWeapons
{
#include "guardia\cfgGuardiaWeapons.hpp"
#include "kestrel\cfgKestrelWeapons.hpp"
#include "perenos\cfgPerenosUniforms.hpp"
#include "kestrel\cfgKestrelUniforms.hpp"
};

class CfgVehicles
{
   // External base classes must be declared in the scope they are used in.
#include "cfgImport.hpp"
#include "perenos\cfgPerenosMen.hpp"
#include "perenos\cfgPerenosVehicles.hpp"
#include "guardia\cfgGuardiaMen.hpp"
#include "guardia\cfgGuardiaVehicles.hpp"
#include "kestrel\cfgKestrelMen.hpp"
#include "kestrel\cfgKestrelVehicles.hpp"
#include "cfgFlags.hpp"
};

class CfgGroups
{
   class East
   {
#include "perenos\cfgPerenosGroups.hpp"
#include "guardia\cfgGuardiaGroups.hpp"
#include "kestrel\cfgKestrelGroups.hpp"
   };
};
