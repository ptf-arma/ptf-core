//UH-1Y
class PTF_UH1Y : RHS_UH1Y_d
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 20;
   ace_cargo_hasCargo = 1;
   armorStructural = 500;
   epeImpulseDamageCoef = 0.1;
   armor=500;
   hullDamageCauseExplosion = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (FFAR/MG) [MAG36]";
   unitInfoType = "PTF_RscUnitInfo_Air_UH1Y";
   unitInfoTypeRTD = "PTF_RscUnitInfo_AirRTDFullDigital_UH1Y";
   weapons[] = {"PTF_weap_mastersafe", "CMFlareLauncher"};
   magazines[] = {"240Rnd_CMFlare_Chaff_Magazine", "240Rnd_CMFlare_Chaff_Magazine", "240Rnd_CMFlare_Chaff_Magazine"};
   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {"rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_ext_co.paa", "rhsusf\addons\rhsusf_a2port_air2\uh1y\data\uh1y_int_co.paa"};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 0;
   LESH_AxisOffsetTarget[] = {0,-7.3,-0.95};
   LESH_WheelOffset[] = {0,2.5};
   AL_canBeMoved = 1;
   AL_HelidollyWeight = 200;
   AL_helidollyAttachpoint[] = {0,-2.2,2.19};
   AL_CraneAttachpoint[] = {0,0.25,0.45};
   class Turrets : Turrets
   {
      class CopilotTurret: CopilotTurret
      {
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_laserDesignator_AI"};
         magazines[] = {"rhs_LaserMag_ai"};
         turretInfoType = "PTF_RscOptics_UH1Y_Observer";
         class OpticsIn
         {
            class Wide
            {
               opticsDisplayName = "W";
               initAngleX = 0;
               minAngleX = -30;
               maxAngleX = 30;
               initAngleY = 0;
               minAngleY = -100;
               maxAngleY = 100;
               initFov = 0.466;
               minFov = 0.0018;
               maxFov = 0.466;
               visionMode[] = {"Normal","NVG","Ti"};
               directionStabilized = 1;
               thermalMode[] = {0,1};
               gunnerOpticsModel = "\rhsusf\addons\rhsusf_optics\data\rhs_uh1_flir";
            };
         };
         gunnerCompartments = "Compartment2";
      };
      class MainTurret : MainTurret
      {
         weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_m134_minigun_1"};
         magazines[] =
             {
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000"
            };
      };
      class RightDoorGun : RightDoorGun
      {
          weapons[] =
             {
                 "PTF_weap_mastersafe",
                 "rhs_weap_m134_minigun_1"};
         magazines[] =
             {
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000",
                 "rhs_mag_762x51_m80a1_4000"
            };

      };
      class CargoTurret_01 : CargoTurret_01{};
      class CargoTurret_02 : CargoTurret_02{};
      class CargoTurret_03 : CargoTurret_03{};
      class CargoTurret_04 : CargoTurret_04{};
      class CargoTurret_05 : CargoTurret_05{};
      class CargoTurret_06 : CargoTurret_06{};
   };
   class UserActions: UserActions
   {
      class TogglePIP
      {
         displayName = "Toggle monitor";
         displayNameDefault = "Toggle monitor";
         condition = "( (call rhsusf_fnc_findPlayer)==driver this) or ((call rhsusf_fnc_findPlayer)==this turretUnit [0]) ";
         statement = "call PTF_fnc_uh1_toggleCam";
         position = "zamerny";
         radius = 1;
         onlyForPlayer = 1;
      };
   };
};
class PTF_UH1Y_Unarmed : RHS_UH1Y_UNARMED_d
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 20;
   ace_cargo_hasCargo = 1;
   armorStructural = 500;
   epeImpulseDamageCoef = 0.1;
   armor=500;
   hullDamageCauseExplosion = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (Trainer) [MAG36]";
   unitInfoType = "PTF_RscUnitInfo_Air_UH1Y";
   unitInfoTypeRTD = "PTF_RscUnitInfo_AirRTDFullDigital_UH1Y";
   weapons[] = {"CMFlareLauncher", "PTF_weap_mastersafe"};
   magazines[] = {"240Rnd_CMFlare_Chaff_Magazine", "240Rnd_CMFlare_Chaff_Magazine","240Rnd_CMFlare_Chaff_Magazine"};
   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\aircraft\uh1y\Trainer\uh1y_ext_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 0;
   LESH_AxisOffsetTarget[] = {0,-7.3,-0.95};
   LESH_WheelOffset[] = {0,2.5};
   AL_canBeMoved = 1;
   AL_CraneAttachpoint[] = {0,0.25,0.45};
   AL_helidollyAttachpoint[] = {0,-2.2,2.19};
   AL_HelidollyWeight = 200;
   class Turrets : Turrets
   {
      class CopilotTurret: CopilotTurret
      {
         turretInfoType = "PTF_RscOptics_UH1Y_Observer";
         class OpticsIn
         {
            class Wide
            {
               opticsDisplayName = "W";
               initAngleX = 0;
               minAngleX = -30;
               maxAngleX = 30;
               initAngleY = 0;
               minAngleY = -100;
               maxAngleY = 100;
               initFov = 0.466;
               minFov = 0.0218;
               maxFov = 0.466;
               visionMode[] = {"Normal","NVG","Ti"};
               directionStabilized = 1;
               thermalMode[] = {0,1};
               gunnerOpticsModel = "\rhsusf\addons\rhsusf_optics\data\rhs_uh1_flir";
            };
         };
      };
      class CargoTurret_01 : CargoTurret_01{};
      class CargoTurret_02 : CargoTurret_02{};
      class CargoTurret_03 : CargoTurret_03{};
      class CargoTurret_04 : CargoTurret_04{};
      class CargoTurret_05 : CargoTurret_05{};
      class CargoTurret_06 : CargoTurret_06{};
      class CargoTurret_07 : CargoTurret_07{};
      class CargoTurret_08 : CargoTurret_08{};
   };
   class UserActions: UserActions
   {
      class TogglePIP
      {
         displayName = "Toggle monitor";
         displayNameDefault = "Toggle monitor";
         condition = "( (call rhsusf_fnc_findPlayer)==driver this) or ((call rhsusf_fnc_findPlayer)==this turretUnit [0]) ";
         statement = "call PTF_fnc_uh1_toggleCam";
         position = "zamerny";
         radius = 1;
         onlyForPlayer = 1;
      };
   };
};
class PTF_UH1Y_HQ : PTF_UH1Y
{
   displayName = "UH-1Y (MAG36 HQ) [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\aircraft\uh1y\HQ\uh1y_ext_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_SCARFACE : PTF_UH1Y
{
   displayName = "UH-1Y (Scarface) [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\Aircraft\UH1Y\Scarface\uh1y_ext_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_SCARFACE_SL : PTF_UH1Y
{
   displayName = "UH-1Y (Scarface SL) [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\Aircraft\UH1Y\ScarfaceSL\uh1y_ext_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_GUNFIGHTERS : PTF_UH1Y
{
   displayName = "UH-1Y (Gunfighters) [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\Aircraft\UH1Y\Gunfighters\uh1y_ext_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_GUNFIGHTERS_SL : PTF_UH1Y
{
   displayName = "UH-1Y (Gunfighters SL) [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\Aircraft\UH1Y\GunfightersSL\uh1y_ext_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
