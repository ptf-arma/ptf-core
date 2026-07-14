class LandVehicle;
class Car : LandVehicle
{
   class ACE_Actions
   {
      class ACE_MainActions
      {
         class PTF_Flags
         {
            displayName = "Flags";
            distance = 3;
            icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
            enableInside = 1;
            class PTF_Flag_Raise
            {
               displayName = "Raise PTF Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = [_target, ""ptfflag.paa""] call PTF_fnc_FlagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
            };
            class USMC_Flag_Raise : PTF_Flag_Raise
            {
               displayName = "Raise USMC Flag";
               statement = "0 = [_target, ""usmcflag.paa""] call PTF_fnc_FlagRaise";
            };

            class PTF_1st_Squad_Flags : PTF_Flag_Raise
            {
               displayName = "1st Platoon Flags";
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
               class 11_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-1 Flag";
                  statement = "0 = [_target, ""11flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 12_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-2 Flag";
                  statement = "0 = [_target, ""12flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 13_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-3 Flag";
                  statement = "0 = [_target, ""13flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 14_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-4 Flag";
                  statement = "0 = [_target, ""14flag.paa""] call PTF_fnc_FlagRaise";
               };
            };

            class PTF_3rd_Flags : PTF_Flag_Raise
            {
               displayName = "3rd Platoon Flags";
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
               class 3_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3rd Platoon Flag";
                  statement = "0 = [_target, ""3flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3A_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-A Flag";
                  statement = "0 = [_target, ""3Aflag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3B_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-B Flag";
                  statement = "0 = [_target, ""3Bflag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3C_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-C Flag";
                  statement = "0 = [_target, ""3Cflag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3E_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-E Flag";
                  statement = "0 = [_target, ""3Eflag.paa""] call PTF_fnc_FlagRaise";
               };

            };

            class PTF_Squadron_Flags : PTF_Flag_Raise
            {
               displayName = "MAG36 Flags";
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
               distance = 3;
               enableInside = 1;
               class MAG36_Flag_Raise : PTF_Flag_Raise
               {
               displayName = "Raise MAG36 Flag";
               statement = "0 = [_target, ""mag36flag.paa""] call PTF_fnc_FlagRaise";
               };
               class Scarface_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Scarface Flag";
                  statement = "0 = [_target, ""scarflag.paa""] call PTF_fnc_FlagRaise";
               };
               class Gunfighters_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Gunfighters Flag";
                  statement = "0 = [_target, ""gunflag.paa""] call PTF_fnc_FlagRaise";
               };
            };
         };

         class PTF_Flag_Remove
         {
            displayName = "Lower PTF Flag";
            distance = 3;
            condition = "alive _target && ((getForcedFlagTexture _target) != '')";
            statement = "0 = [_target, """"] call PTF_fnc_FlagRaise";
            showDisabled = 0;
            priority = 1.1;
            enableInside = 1;
            icon = "\z\PTF\addons\PTF_Textures\Icons\flagdown_ico.paa";
         };
      };
   };
};

class Tank;
class Tank_F : Tank
{
   class ACE_Actions
   {
      class ACE_MainActions
      {
           class PTF_Flags
         {
            displayName = "Flags";
            distance = 3;
            icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
            enableInside = 1;
            class PTF_Flag_Raise
            {
               displayName = "Raise PTF Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = [_target, ""ptfflag.paa""] call PTF_fnc_FlagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
            };
            class USMC_Flag_Raise : PTF_Flag_Raise
            {
               displayName = "Raise USMC Flag";
               statement = "0 = [_target, ""usmcflag.paa""] call PTF_fnc_FlagRaise";
            };

            class PTF_1st_Squad_Flags : PTF_Flag_Raise
            {
               displayName = "1st Platoon Flags";
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
               class 11_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-1 Flag";
                  statement = "0 = [_target, ""11flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 12_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-2 Flag";
                  statement = "0 = [_target, ""12flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 13_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-3 Flag";
                  statement = "0 = [_target, ""13flag.paa""] call PTF_fnc_FlagRaise";
               };
                class 14_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-4 Flag";
                  statement = "0 = [_target, ""14flag.paa""] call PTF_fnc_FlagRaise";
               };
            };

            class PTF_3rd_Flags : PTF_Flag_Raise
            {
               displayName = "3rd Platoon Flags";
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
               class 3_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3rd Platoon Flag";
                  statement = "0 = [_target, ""3flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3A_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-A Flag";
                  statement = "0 = [_target, ""3Aflag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3B_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-B Flag";
                  statement = "0 = [_target, ""3Bflag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3C_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-C Flag";
                  statement = "0 = [_target, ""3Cflag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3E_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-E Flag";
                  statement = "0 = [_target, ""3Eflag.paa""] call PTF_fnc_FlagRaise";
               };

            };

            class PTF_Squadron_Flags : PTF_Flag_Raise
            {
               displayName = "MAG36 Flags";
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
               distance = 3;
               enableInside = 1;
               class MAG36_Flag_Raise : PTF_Flag_Raise
               {
               displayName = "Raise MAG36 Flag";
               statement = "0 = [_target, ""mag36flag.paa""] call PTF_fnc_FlagRaise";
               };
               class Scarface_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Scarface Flag";
                  statement = "0 = [_target, ""scarflag.paa""] call PTF_fnc_FlagRaise";
               };
               class Gunfighters_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Gunfighters Flag";
                  statement = "0 = [_target, ""gunflag.paa""] call PTF_fnc_FlagRaise";
               };
            };
         };

         class PTF_Flag_Remove
         {
            displayName = "Lower PTF Flag";
            distance = 3;
            condition = "alive _target && ((getForcedFlagTexture _target) != '')";
            statement = "0 = [_target, """"] call PTF_fnc_FlagRaise";
            showDisabled = 0;
            priority = 1.1;
            enableInside = 1;
            icon = "\z\PTF\addons\PTF_Textures\Icons\flagdown_ico.paa";
         };
      };
   };
};

class Ship;
class Ship_F : Ship
{
   class ACE_Actions
   {
      class ACE_MainActions
      {
            class PTF_Flags
         {
            displayName = "Flags";
            distance = 3;
            icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
            enableInside = 1;
            class PTF_Flag_Raise
            {
               displayName = "Raise PTF Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = [_target, ""ptfflag.paa""] call PTF_fnc_FlagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
            };
            class USMC_Flag_Raise : PTF_Flag_Raise
            {
               displayName = "Raise USMC Flag";
               statement = "0 = [_target, ""usmcflag.paa""] call PTF_fnc_FlagRaise";
            };

            class PTF_1st_Squad_Flags : PTF_Flag_Raise
            {
               displayName = "1st Platoon Flags";
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
               class 11_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-1 Flag";
                  statement = "0 = [_target, ""11flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 12_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-2 Flag";
                  statement = "0 = [_target, ""12flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 13_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-3 Flag";
                  statement = "0 = [_target, ""13flag.paa""] call PTF_fnc_FlagRaise";
               };
                class 14_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-4 Flag";
                  statement = "0 = [_target, ""14flag.paa""] call PTF_fnc_FlagRaise";
               };
            };

            class PTF_3rd_Flags : PTF_Flag_Raise
            {
               displayName = "3rd Platoon Flags";
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
               class 3_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3rd Platoon Flag";
                  statement = "0 = [_target, ""3flag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3A_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-A Flag";
                  statement = "0 = [_target, ""3Aflag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3B_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-B Flag";
                  statement = "0 = [_target, ""3Bflag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3C_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-C Flag";
                  statement = "0 = [_target, ""3Cflag.paa""] call PTF_fnc_FlagRaise";
               };
               class 3E_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-E Flag";
                  statement = "0 = [_target, ""3Eflag.paa""] call PTF_fnc_FlagRaise";
               };

            };
            class PTF_Squadron_Flags : PTF_Flag_Raise
            {
               displayName = "MAG36 Flags";
               icon = "\z\PTF\addons\PTF_Textures\Icons\flagup_ico.paa";
               distance = 3;
               enableInside = 1;
               class MAG36_Flag_Raise : PTF_Flag_Raise
               {
               displayName = "Raise MAG36 Flag";
               statement = "0 = [_target, ""mag36flag.paa""] call PTF_fnc_FlagRaise";
               };
               class Scarface_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Scarface Flag";
                  statement = "0 = [_target, ""scarflag.paa""] call PTF_fnc_FlagRaise";
               };
               class Gunfighters_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Gunfighters Flag";
                  statement = "0 = [_target, ""gunflag.paa""] call PTF_fnc_FlagRaise";
               };
            };
         };

         class PTF_Flag_Remove
         {
            displayName = "Lower PTF Flag";
            distance = 3;
            condition = "alive _target && ((getForcedFlagTexture _target) != '')";
            statement = "0 = [_target, """"] call PTF_fnc_FlagRaise";
            showDisabled = 0;
            priority = 1.1;
            enableInside = 1;
            icon = "\z\PTF\addons\PTF_Textures\Icons\flagdown_ico.paa";
         };
      };
   };
};

class Man;
class CAManBase : Man {
   class ACE_SelfActions {
      class Markers {
         displayName = "Markers";
         icon = "\A3\ui_f\data\map\markers\handdrawn\objective_CA.paa";
         priority = 0.9;
            class lz {
            displayName = "Place Lz Marker";
            Icon = "\A3\ui_f\data\map\markers\handdrawn\pickup_CA.paa";
            statement = "[_player] call PTF_Fnc_lz";
            };
            class re {
            displayName = "Place Resupply Marker";
            Icon = "\a3\ui_f\data\igui\cfg\simpletasks\types\rearm_ca.paa";
            statement = "[_player] call PTF_Fnc_re";
            };
            class ccp {
            displayName = "Place CCP Marker";
            Icon = "\A3\ui_f_orange\data\cfgmarkers\redcrystal_ca.paa";
            statement = "[_player] call PTF_Fnc_ccp";
            };
            class Dot {
            displayName = "Place Dot Marker";
            icon = "\A3\ui_f\data\map\markers\handdrawn\dot_CA.paa";
            statement = "call PTF_Fnc_Dot";
         };
      };
   };
};




