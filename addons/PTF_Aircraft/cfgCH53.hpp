//CH-53E
class PTF_CH53_Ramp : rhsusf_CH53E_USMC_GAU21_D
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 30;
   ace_cargo_hasCargo = 1;
   author = "Paramarine Task Force";
   displayName = "CH-53E GAU-21 [MAG36]";
   slingLoadMaxCargoMass = 16329;
   weapons[] = {"CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\aircraft\ch53\ch53_1_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\ch53\ch53_acc_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\3_ca.paa", "\z\PTF\addons\PTF_Textures\aircraft\6_ca.paa"};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 1;
   LESH_AxisOffsetTarget[] = {0,12,-3.5};
   LESH_WheelOffset[] = {0,4};
    class EventHandlers {
      init = "[(_this select 0)] call PTF_fnc_slingloading";
   };

   class Turrets: Turrets
   {
      class CopilotTurret: CopilotTurret
      {
         gunnerCompartments = "Compartment2";
      };
      class GAU21: GAU21
      {
         gunnerType = "rhsusf_usmc_marpat_d_helicrew";
      };
   };
};

class PTF_CH53_Cargo : rhsusf_CH53e_USMC_D_cargo
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 60;
   ace_cargo_hasCargo = 1;
   side = 1;
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "CH-53E Cargo [MAG36]";
   slingLoadMaxCargoMass = 16329;
   weapons[] = {"CMFlareLauncher"};
   magazines[] = {
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine",
       "240Rnd_CMFlare_Chaff_Magazine"};
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\aircraft\ch53\ch53_1_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\ch53\ch53_acc_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\3_ca.paa", "\z\PTF\addons\PTF_Textures\aircraft\6_ca.paa"};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 1;
   LESH_AxisOffsetTarget[] = {0,12,-3.5};
   LESH_WheelOffset[] = {0,4};
    class EventHandlers {
      init = "[(_this select 0)] call PTF_fnc_slingloading";
   };

   class Turrets: Turrets
   {
      class CopilotTurret: CopilotTurret
      {
         gunnerCompartments = "Compartment2";
      };
   };
};
