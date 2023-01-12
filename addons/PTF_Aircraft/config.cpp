class CfgPatches
{
   class PTF_Aircraft
   {
      units[] = {
          "PTF_C130J",
          "PTF_C130J_Cargo",
          "PTF_CH53_Ramp",
          "PTF_CH53_Cargo",
          "PTF_UH1Y_Unarmed",
          "PTF_UH1Y_Medevac",
          "PTF_MV22_Ramp",
          "PTF_MV22_Cargo",
          "PTF_MD500",
          "PTF_Cessna_400",
          "PTF_MD500_Trainer",
          "PTF_Cessna_400_Trainer",
          "PTF_MD500_HQ",
          "PTF_Cessna_400_HQ",
          "PTF_AH1Z_GUNFIGHTERS",
          "PTF_AH1Z_HQ",
          "PTF_MQ9_SCARFACE",
          "PTF_MQ9_HQ",
          "PTF_UH1Y_HQ",
          "PTF_UH1Y_SCARFACE",
          "PTF_UH1Y_SCARFAFCE_SL",
          "PTF_UH1Y_GUNFIGHTERS",
          "PTF_UH1Y_GUNFIGHTERS_SL",
          "PTF_RQ4A_HQ",
          "PTF_C17",
          "PTF_KC135",
          "PTF_AV8B",
		  "PTF_F18C",
		  "PTF_F18C_CAG",
		  "PTF_F18D",
		  "PTF_F18D_CAG"
          };
      weapons[] = {
          "PTF_weap_mastersafe"};
      requiredVersion = 1.32;
      requiredAddons[] = {
          "PTF_Main",
          "PTF_Textures",
          "PTF_Models",
          "rhsusf_a2port_air2",
          "CUP_AirVehicles_Core",
          "CUP_Creatures_Military_USMC",
          "CUP_AirVehicles_CH47",
          "rhsusf_ch53",
          "A3_Air_F_Exp",
          "A3_Air_F",
          "CUP_AirVehicles_MV22",
          "CUP_AirVehicles_MQ9",
          "ace_interaction",
          "USAF_C130J",
          "FIR_AV8B_F"
          };
   };
};

#include "cfgImport.hpp"
#include "cfgDefinitions.hpp"
class cfgVehicles
{
#include "cfgAH1Z.hpp"
#include "cfgC130J.hpp"
#include "cfgCH53.hpp"
#include "cfgF18.hpp"
#include "cfgMQ9.hpp"
#include "cfgC17.hpp"
#include "cfgKC135.hpp"
#include "cfgMV22.hpp"
#include "cfgUH1Y.hpp"
#include "cfgAV8B.hpp"
#include "cfgVanilla.hpp"
#include "cfgRQ4A.hpp"
#include "cfgCustom.hpp"
};
