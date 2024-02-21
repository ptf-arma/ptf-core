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
            icon = "\PTF_Textures\Icons\flagup_ico.paa";
            enableInside = 1;
            class PTF_Flag_Raise
            {
               displayName = "Raise PTF Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = _target call PTF_fnc_PTFflagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
            };
            class USMC_Flag_Raise : PTF_Flag_Raise
            {
               displayName = "Raise USMC Flag";
               statement = "0 = _target call PTF_fnc_USMCFlagRaise";
            };

            class PTF_1st_Squad_Flags : PTF_Flag_Raise
            {
               displayName = "1st Platoon Flags";
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               class 11_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-1 Flag";
                  statement = "0 = _target call PTF_fnc_11FlagRaise";
               };
               class 12_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-2 Flag";
                  statement = "0 = _target call PTF_fnc_12FlagRaise";
               };
               class 13_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-3 Flag";
                  statement = "0 = _target call PTF_fnc_13FlagRaise";
               };
               class 14_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-4 Flag";
                  statement = "0 = _target call PTF_fnc_14FlagRaise";
               };
            };

            class PTF_3rd_Flags : PTF_Flag_Raise
            {
               displayName = "3rd Platoon Flags";
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               class 3_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3rd Platoon Flag";
                  statement = "0 = _target call PTF_fnc_3flagRaise";
               };
               class 3A_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-A Flag";
                  statement = "0 = _target call PTF_fnc_3AflagRaise";
               };
               class 3E_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-E Flag";
                  statement = "0 = _target call PTF_fnc_3EflagRaise";
               };
               
            };

            class PTF_Squadron_Flags : PTF_Flag_Raise
            {
               displayName = "MAG36 Flags";
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               distance = 3;
               enableInside = 1;
               class MAG36_Flag_Raise : PTF_Flag_Raise
               {
               displayName = "Raise MAG36 Flag";
               statement = "0 = _target call PTF_fnc_MAG36FlagRaise";
               };
               class Scarface_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Scarface Flag";
                  statement = "0 = _target call PTF_fnc_scarFlagRaise";
               };
               class Gunfighters_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Gunfighters Flag";
                  statement = "0 = _target call PTF_fnc_gunFlagRaise";
               };
            };
         };

         class PTF_Flag_Remove
         {
            displayName = "Lower PTF Flag";
            distance = 3;
            condition = "alive _target && ((getForcedFlagTexture _target) != '')";
            statement = "0 = _target call PTF_fnc_flagRemove";
            showDisabled = 0;
            priority = 1.1;
            enableInside = 1;
            icon = "\PTF_Textures\Icons\flagdown_ico.paa";
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
            icon = "\PTF_Textures\Icons\flagup_ico.paa";
            enableInside = 1;
            class PTF_Flag_Raise
            {
               displayName = "Raise PTF Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = _target call PTF_fnc_PTFflagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
            };
            class USMC_Flag_Raise : PTF_Flag_Raise
            {
               displayName = "Raise USMC Flag";
               statement = "0 = _target call PTF_fnc_USMCFlagRaise";
            };

            class PTF_1st_Squad_Flags : PTF_Flag_Raise
            {
               displayName = "1st Platon Flags";
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               class 11_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-1 Flag";
                  statement = "0 = _target call PTF_fnc_11FlagRaise";
               };
               class 12_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-2 Flag";
                  statement = "0 = _target call PTF_fnc_12FlagRaise";
               };
               class 13_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-3 Flag";
                  statement = "0 = _target call PTF_fnc_13FlagRaise";
               };
                class 14_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-4 Flag";
                  statement = "0 = _target call PTF_fnc_14FlagRaise";
               };
            };

            class PTF_3rd_Flags : PTF_Flag_Raise
            {
               displayName = "3rd Platoon Flags";
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               class 3_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3rd Platoon Flag";
                  statement = "0 = _target call PTF_fnc_3flagRaise";
               };
               class 3A_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-A Flag";
                  statement = "0 = _target call PTF_fnc_3AflagRaise";
               };
               class 3E_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-E Flag";
                  statement = "0 = _target call PTF_fnc_3EflagRaise";
               };
               
            };
            };

            class PTF_Squadron_Flags : PTF_Flag_Raise
            {
               displayName = "MAG36 Flags";
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               distance = 3;
               enableInside = 1;
               class MAG36_Flag_Raise : PTF_Flag_Raise
               {
               displayName = "Raise MAG36 Flag";
               statement = "0 = _target call PTF_fnc_MAG36FlagRaise";
               };
               class Scarface_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Scarface Flag";
                  statement = "0 = _target call PTF_fnc_scarFlagRaise";
               };
               class Gunfighters_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Gunfighters Flag";
                  statement = "0 = _target call PTF_fnc_gunFlagRaise";
               };
            };
         };

         class PTF_Flag_Remove
         {
            displayName = "Lower PTF Flag";
            distance = 3;
            condition = "alive _target && ((getForcedFlagTexture _target) != '')";
            statement = "0 = _target call PTF_fnc_flagRemove";
            showDisabled = 0;
            priority = 1.1;
            enableInside = 1;
            icon = "\PTF_Textures\Icons\flagdown_ico.paa";
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
            icon = "\PTF_Textures\Icons\flagup_ico.paa";
            enableInside = 1;
            class PTF_Flag_Raise
            {
               displayName = "Raise PTF Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = _target call PTF_fnc_PTFflagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
            };
            class USMC_Flag_Raise : PTF_Flag_Raise
            {
               displayName = "Raise USMC Flag";
               statement = "0 = _target call PTF_fnc_USMCFlagRaise";
            };

            class PTF_1st_Squad_Flags : PTF_Flag_Raise
            {
               displayName = "1st Platon Flags";
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               class 11_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-1 Flag";
                  statement = "0 = _target call PTF_fnc_11FlagRaise";
               };
               class 12_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-2 Flag";
                  statement = "0 = _target call PTF_fnc_12FlagRaise";
               };
               class 13_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-3 Flag";
                  statement = "0 = _target call PTF_fnc_13FlagRaise";
               };
                class 14_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 1-4 Flag";
                  statement = "0 = _target call PTF_fnc_14FlagRaise";
               };
            };
            
            class PTF_3rd_Flags : PTF_Flag_Raise
            {
               displayName = "3rd Platoon Flags";
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               class 3_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3rd Platoon Flag";
                  statement = "0 = _target call PTF_fnc_3flagRaise";
               };
               class 3A_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-A Flag";
                  statement = "0 = _target call PTF_fnc_3AflagRaise";
               };
               class 3E_flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise 3-E Flag";
                  statement = "0 = _target call PTF_fnc_3EflagRaise";
               };
               
            };
            };

            class PTF_Squadron_Flags : PTF_Flag_Raise
            {
               displayName = "MAG36 Flags";
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               distance = 3;
               enableInside = 1;
               class MAG36_Flag_Raise : PTF_Flag_Raise
               {
               displayName = "Raise MAG36 Flag";
               statement = "0 = _target call PTF_fnc_MAG36FlagRaise";
               };
               class Scarface_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Scarface Flag";
                  statement = "0 = _target call PTF_fnc_scarFlagRaise";
               };
               class Gunfighters_Flag_Raise : PTF_Flag_Raise
               {
                  displayName = "Raise Gunfighters Flag";
                  statement = "0 = _target call PTF_fnc_gunFlagRaise";
               };
            };
         };

         class PTF_Flag_Remove
         {
            displayName = "Lower PTF Flag";
            distance = 3;
            condition = "alive _target && ((getForcedFlagTexture _target) != '')";
            statement = "0 = _target call PTF_fnc_flagRemove";
            showDisabled = 0;
            priority = 1.1;
            enableInside = 1;
            icon = "\PTF_Textures\Icons\flagdown_ico.paa";
         };
      };
   };
};




