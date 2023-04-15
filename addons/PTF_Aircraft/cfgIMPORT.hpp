//Super Tucano
class rhsgref_c_a29;
//AH-1Z
class Heli_Attack_01_base_F;
class RHS_AH1Z_base : Heli_Attack_01_base_F
{
 class turrets;
};
class RHS_AH1Z : RHS_AH1Z_base
{
 class turrets
 {
 class MainTurret;
 };
};
//C-130J
class RHS_C130J;
class RHS_C130J_Cargo;
//CH-53E
class rhsusf_CH53E_USMC_D;
class rhsusf_CH53E_USMC_GAU21_D;
class rhsusf_CH53e_USMC_D_cargo;
//MD-500
class C_Heli_Light_01_civil_F;
//Cessna TTx
class C_Plane_Civil_01_F;
class C_Plane_Civil_01_racing_F;
//MQ-9
class CUP_B_USMC_DYN_MQ9;
//MV-22
class CUP_B_MV22_USMC;
class CUP_B_MV22_USMC_RAMPGUN;
class CUP_B_MV22_VIV_USMC;
// "UH-1Y (FFAR/MG) [MAG36]"
class RHS_UH1Y_US_Base;
class RHS_UH1Y : RHS_UH1Y_US_Base
{
 class turrets;
};
class RHS_UH1Y_d : RHS_UH1Y // "UH-1Y (FFAR/MG) [MAG36]"
{
 class turrets : turrets
 {
 class MainTurret;
 class RightDoorGun;
 class CargoTurret_01;
 class CargoTurret_02;
 class CargoTurret_03;
 class CargoTurret_04;
 class CargoTurret_05;
 class CargoTurret_06;
 class CargoTurret_07;
 class CargoTurret_08;
 };
};
class RHS_UH1Y_FFAR;
class RHS_UH1Y_UNARMED : RHS_UH1Y_FFAR
{
 class turrets;
};
class RHS_UH1Y_UNARMED_d : RHS_UH1Y_UNARMED //"UH-1Y (Trainer) [MAG36]"
{
 class turrets : turrets
 {
 class CargoTurret_01;
 class CargoTurret_02;
 class CargoTurret_03;
 class CargoTurret_04;
 class CargoTurret_05;
 class CargoTurret_06;
 class CargoTurret_07;
 class CargoTurret_08;
 };
};

class CUP_B_UH1Y_Base;
class CUP_B_UH1Y_UNA_Base : CUP_B_UH1Y_Base
{
 class Turrets;
};
class CUP_B_UH1Y_MEV_USMC : CUP_B_UH1Y_UNA_Base //"UH-1Y (Medevac) [MAG36]"
{
 class Turrets : turrets
 {
    class CargoTurret_01;
    class CargoTurret_02;
 };
};
//Mastersafe
class PTF_weap_mastersafe;
//F-35B
class FIR_F35B_Standard;
//MQ-8
class Helicopter_Base_F;
class ViewOptics;
//AV-8B Harrier
class FIR_AV8B;
//F-18 Hornets
class FIR_F18C;
class FIR_F18D;
//Super Tucano
class RHSGREF_A29B_HIDF;
//Misc.
class MainTurret;
class AnimationSources;
class hmg_hide;
class Ramp;
class NewTurret;
class Turrets;
class components;
class DefaultVehicleSystemsDisplayManagerLeft;
class DefaultVehicleSystemsDisplayManagerRight;
class CargoTurret;
class VehicleTransport;
class VehicleSystemsDisplayManagerComponentLeft;
class CopilotTurret;
class CargoTurret_01;
class TransportItems;
class TransportBackpacks;
class TransportMagazines;
class TransportWeapons;
class ViewGunner;
class CUP_B_L39_CZ_GREY;
class UserActions;
class ViewPilot;

class USAF_MQ9;
class USAF_C17;
class usaf_kc135;
class USAF_RQ4A;
class USAF_C130J;
class USAF_C130J_Cargo;

class VehicleSystemsTemplateLeftPilot;

class SensorTemplateDataLink;
