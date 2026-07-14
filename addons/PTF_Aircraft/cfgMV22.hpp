//MV-22
// The three MV-22 variants share an ~8,550-line body (MFD/turrets/anims/etc.)
// that was previously copy-pasted verbatim into each. That common body now
// lives in cfgMV22_shared.hpp and is #included below; each variant keeps its
// own parent and the handful of properties that actually differ (cargo/sling
// params, displayName, livery textures).
class PTF_MV22_Ramp : DEGA_MV22_Infantry_NATO
{
   scope = 2;
   scopeCurator = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_hasCargo = 0;
   author = "Paramarine Task Force";
   displayName = "MV-22 [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\aircraft\mv22\mv22_1_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\mv22\mv22_2_co.paa"};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 1;
   LESH_AxisOffsetTarget[] = {0,7.5,0.9};
   LESH_WheelOffset[] = {0.35,0};
   class EventHandlers {
      init = "[(_this select 0)] call PTF_fnc_slingloading";
   };
   #include "cfgMV22_shared.hpp"
};
class PTF_MV22_Cargo : DEGA_MV22_Vehicle_NATO
{
   scope = 2;
   scopeCurator = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 60;
   slingLoadMaxCargoMass = 15000;
   slingLoadMinCargoMass = 0;
   ace_cargo_hasCargo = 1;
   author = "Paramarine Task Force";
   displayName = "MV-22 Cargo [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\aircraft\mv22\cargo\mv22_1_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\mv22\cargo\mv22_2_co.paa"};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 1;
   LESH_AxisOffsetTarget[] = {0,7.5,0.9};
   LESH_WheelOffset[] = {0.35,0};
   class EventHandlers {
      init = "[(_this select 0)] call PTF_fnc_slingloading";
   };
   #include "cfgMV22_shared.hpp"
};
class PTF_MV22_Minigun : DEGA_MV22_IDWS_NATO
{
   scope = 2;
   scopeCurator = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 60;
   ace_cargo_hasCargo = 1;
   author = "Paramarine Task Force";
   displayName = "MV-22 Mini [MAG36]";
   hiddenSelectionsTextures[] = {"\z\PTF\addons\PTF_Textures\aircraft\mv22\cargo\mv22_1_co.paa", "\z\PTF\addons\PTF_Textures\aircraft\mv22\cargo\mv22_2_co.paa"};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 1;
   LESH_AxisOffsetTarget[] = {0,7.5,0.9};
   LESH_WheelOffset[] = {0.35,0};
   class EventHandlers {
      init = "[(_this select 0)] call PTF_fnc_slingloading";
   };
   #include "cfgMV22_shared.hpp"
};
