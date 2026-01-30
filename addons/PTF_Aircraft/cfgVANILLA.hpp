//MD-500
class PTF_MD500 : C_Heli_Light_01_civil_F
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_hasCargo = 0;
   side = 1;
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "MD-500 [MAG36]";
   hiddenSelectionsTextures[] = {"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"};
   LESH_canBeTowed = 1;
   LESH_towFromFront = 0;
   LESH_AxisOffsetTarget[] = {0.1,-3.15,0.25};
   LESH_WheelOffset[] = {0,1.5};
   AL_canBeMoved = 1;
   AL_CraneAttachpoint[] = {-1,0.25,-0.25};
   AL_HelidollyWeight = 100;
   AL_HelidollyAttachpoint[] = {0,-1,0.62};
   class TextureSources
   {
      class PTF
      {
         displayName = "PTF";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa"};
         factions[] = {};
      };
      class HQ
      {
         displayName = "MAG36 HQ";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa"};
         factions[] = {};
      };
   };
};
//Cessna
class PTF_Cessna_400 : C_Plane_Civil_01_F
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_hasCargo = 0;
   side = 1;
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "Cessna 400 [MAG36]";
   hiddenSelectionsTextures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
};
class PTF_Cessna_400_Racing : C_Plane_Civil_01_racing_F
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_hasCargo = 0;
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "Cessna 400 (Racing) [MAG36]";
   hiddenSelectionsTextures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
};
class PTF_MD500_Trainer : PTF_MD500
{
   displayName = "MD-500 (Trainer) [MAG36]";
   hiddenSelectionsTextures[] = {"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"};
};
class PTF_Cessna_400_Trainer : PTF_Cessna_400
{
   displayName = "Cessna 400 (Trainer) [MAG36]";
   hiddenSelectionsTextures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
};
class PTF_MD500_HQ : PTF_MD500
{
   displayName = "MD-500 (MAG36 HQ) [MAG36]";
   hiddenSelectionsTextures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_graywatcher_co.paa"};
};
class PTF_Cessna_400_HQ : PTF_Cessna_400_Racing
{
   displayName = "Cessna 400 (MAG36 HQ) [MAG36]";
   hiddenSelectionsTextures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
};
