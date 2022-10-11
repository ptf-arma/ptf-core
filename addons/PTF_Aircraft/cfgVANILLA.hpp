//MD-500
class PTF_MD500 : C_Heli_Light_01_civil_F
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 200;
   crew = "B_Pilot_F";
   author = "Paramarine Task Force";
   displayName = "MD-500 [MAG36]";

   hiddenSelections[] = {"camo1", "aiming_dot"};
   hiddenSelectionsTextures[] = {
       "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"};

   class TextureSources
   {
      class Blue
      {
         displayName = "Blue";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"};
         factions[] = {};
      };
      class Red
      {
         displayName = "Red";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_co.paa"};
         factions[] = {};
      };
      class Ion
      {
         displayName = "Ion";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_ion_co.paa"};
         factions[] = {};
      };
      class BlueLine
      {
         displayName = "BlueLine";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_blueLine_co.paa"};
         factions[] = {};
      };
      class Digital
      {
         displayName = "Digital";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_digital_co.paa"};
         factions[] = {};
      };
      class Elliptical
      {
         displayName = "Elliptical";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_elliptical_co.paa"};
         factions[] = {};
      };
      class Furious
      {
         displayName = "Furious";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_furious_co.paa"};
         factions[] = {};
      };
      class Graywatcher
      {
         displayName = "Graywatcher";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_graywatcher_co.paa"};
         factions[] = {};
      };
      class Jeans
      {
         displayName = "Jeans";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_jeans_co.paa"};
         factions[] = {};
      };
      class Light
      {
         displayName = "Light";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_light_co.paa"};
         factions[] = {};
      };
      class Shadow
      {
         displayName = "Shadow";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_shadow_co.paa"};
         factions[] = {};
      };
      class Sheriff
      {
         displayName = "Sheriff";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sheriff_co.paa"};
         factions[] = {};
      };
      class Speedy
      {
         displayName = "Speedy";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_speedy_co.paa"};
         factions[] = {};
      };
      class Sunset
      {
         displayName = "Sunset";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_sunset_co.paa"};
         factions[] = {};
      };
      class Vrana
      {
         displayName = "Vrana";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_vrana_co.paa"};
         factions[] = {};
      };
      class Wasp
      {
         displayName = "Wasp";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wasp_co.paa"};
         factions[] = {};
      };
      class Wave
      {
         displayName = "Wave";
         author = "J.Downs";
         textures[] = {"\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_wave_co.paa"};
         factions[] = {};
      };
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

   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
//Cessna
class PTF_Cessna_400 : C_Plane_Civil_01_F
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   faction = "BLU_F";
   crew = "B_Pilot_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 200;
   author = "Paramarine Task Force";
   displayName = "Cessna 400 [MAG36]";

   hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4"};
   hiddenSelectionsTextures[] = {
       "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};

   class TextureSources
   {
      class Racer_1
      {
         displayName = "Racing (Tan Interior)";
         author = "J.Downs";
         textures[] = {
             "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
         factions[] = {};
      };
      class Racer_2
      {
         displayName = "Racing";
         author = "J.Downs";
         textures[] = {
             "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
         factions[] = {};
      };
      class RedLine_1
      {
         displayName = "Red Line (Tan Interior)";
         author = "J.Downs";
         textures[] = {
             "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
         factions[] = {};
      };
      class RedLine_2
      {
         displayName = "Red Line";
         author = "J.Downs";
         textures[] = {
             "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
         factions[] = {};
      };
      class Wave_1
      {
         displayName = "Blue Wave (Tan Interior)";
         author = "J.Downs";
         textures[] = {
             "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
         factions[] = {};
      };
      class Wave_2
      {
         displayName = "Blue Wave";
         author = "J.Downs";
         textures[] = {
             "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
         factions[] = {};
      };
      class Tribal_1
      {
         displayName = "Tribal (Tan Interior)";
         author = "J.Downs";
         textures[] = {
             "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
         factions[] = {};
      };
      class Tribal_2
      {
         displayName = "Tribal";
         author = "J.Downs";
         textures[] = {
             "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
         factions[] = {};
      };
   };

   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
class PTF_Cessna_400_Racing : C_Plane_Civil_01_racing_F
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   faction = "BLU_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 300;
   author = "Paramarine Task Force";
   displayName = "Cessna 400 (Racing) [MAG36]";

   hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4"};
   hiddenSelectionsTextures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};

   class TextureSources
   {
      class Racer_1
      {
         displayName = "Racing (Tan Interior)";
         author = "J.Downs";
         textures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
         factions[] = {};
      };
      class Racer_2
      {
         displayName = "Racing";
         author = "J.Downs";
         textures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Racer_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Racer_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
         factions[] = {};
      };
      class RedLine_1
      {
         displayName = "Red Line (Tan Interior)";
         author = "J.Downs";
         textures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
         factions[] = {};
      };
      class RedLine_2
      {
         displayName = "Red Line";
         author = "J.Downs";
         textures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
         factions[] = {};
      };
      class Wave_1
      {
         displayName = "Blue Wave (Tan Interior)";
         author = "J.Downs";
         textures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
         factions[] = {};
      };
      class Wave_2
      {
         displayName = "Blue Wave";
         author = "J.Downs";
         textures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Wave_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Wave_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
         factions[] = {};
      };
      class Tribal_1
      {
         displayName = "Tribal (Tan Interior)";
         author = "J.Downs";
         textures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
         factions[] = {};
      };
      class Tribal_2
      {
         displayName = "Tribal";
         author = "J.Downs";
         textures[] = {"A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
         factions[] = {};
      };
   };

   class TransportItems : TransportItems
   {
   };
   class TransportBackpacks : TransportBackpacks
   {
   };
   class TransportMagazines : TransportMagazines
   {
   };
   class TransportWeapons : TransportWeapons
   {
   };
};
