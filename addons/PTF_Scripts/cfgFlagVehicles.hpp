//class PTF_M1151;
//class PTF_M1151_MK19;
//class PTF_M1151_M240;
//class PTF_M1151_M2;
//class PTF_M1151_M2_LRAS;
//class PTF_M1152
//class PTF_M1123
//class PTF_MRAP_M1232_M2
//class PTF_MRAP_M1232_MK19
//class PTF_MRZR4
//class PTF_MTVR_Repair
//class PTF_MTVR_Ammo
//class PTF_MTVR_Refuel
//class PTF_Snowmobile
//class PTF_Snowmobile_Basket
//class PTF_Tractor
//class PTF_TowingTractor
//class PTF_M977A4_M2
//class PTF_M977A4_Refuel
//class PTF_M977A4_Repair
//class PTF_M977A4_Ammo

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
            class MAG36_Flag_Raise
            {
               displayName = "Raise MAG36 Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = _target call PTF_fnc_MAG36FlagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
            };
            class USMC_Flag_Raise
            {
               displayName = "Raise USMC Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = _target call PTF_fnc_USMCFlagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
            };

            class PTF_Squad_Flags
            {
               displayName = "Squad Flags";
               distance = 3;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               enableInside = 1;
               class 11_Flag_Raise
               {
                  displayName = "Raise 1-1 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_11FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class 12_Flag_Raise
               {
                  displayName = "Raise 1-2 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_12FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class 13_Flag_Raise
               {
                  displayName = "Raise 1-3 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_13FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class 14_Flag_Raise
               {
                  displayName = "Raise 1-4 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_14FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
            };
            class PTF_Squadron_Flags
            {
               displayName = "Squadron Flags";
               distance = 3;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               enableInside = 1;
               class Scarface_Flag_Raise
               {
                  displayName = "Raise Scarface Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_scarFlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class Gunfighters_Flag_Raise
               {
                  displayName = "Raise Gunfighters Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_gunFlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
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
            class MAG36_Flag_Raise
            {
               displayName = "Raise MAG36 Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = _target call PTF_fnc_MAG36FlagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
            };
            class USMC_Flag_Raise
            {
               displayName = "Raise USMC Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = _target call PTF_fnc_USMCFlagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
            };

            class PTF_Squad_Flags
            {
               displayName = "Squad Flags";
               distance = 3;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               enableInside = 1;
               class 11_Flag_Raise
               {
                  displayName = "Raise 1-1 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_11FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class 12_Flag_Raise
               {
                  displayName = "Raise 1-2 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_12FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class 13_Flag_Raise
               {
                  displayName = "Raise 1-3 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_13FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class 14_Flag_Raise
               {
                  displayName = "Raise 1-4 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_14FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
            };
            class PTF_Squadron_Flags
            {
               displayName = "Squadron Flags";
               distance = 3;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               enableInside = 1;
               class Scarface_Flag_Raise
               {
                  displayName = "Raise Scarface Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_scarFlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class Gunfighters_Flag_Raise
               {
                  displayName = "Raise Gunfighters Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_gunFlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
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
            class MAG36_Flag_Raise
            {
               displayName = "Raise MAG36 Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = _target call PTF_fnc_MAG36FlagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
            };
            class USMC_Flag_Raise
            {
               displayName = "Raise USMC Flag";
               distance = 3;
               condition = "alive _target && ((getForcedFlagTexture _target) == '')";
               statement = "0 = _target call PTF_fnc_USMCFlagRaise";
               showDisabled = 0;
               priority = 1.1;
               enableInside = 1;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
            };

            class PTF_Squad_Flags
            {
               displayName = "Squad Flags";
               distance = 3;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               enableInside = 1;
               class 11_Flag_Raise
               {
                  displayName = "Raise 1-1 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_11FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class 12_Flag_Raise
               {
                  displayName = "Raise 1-2 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_12FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class 13_Flag_Raise
               {
                  displayName = "Raise 1-3 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_13FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class 14_Flag_Raise
               {
                  displayName = "Raise 1-4 Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_14FlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
            };
            class PTF_Squadron_Flags
            {
               displayName = "Squadron Flags";
               distance = 3;
               icon = "\PTF_Textures\Icons\flagup_ico.paa";
               enableInside = 1;
               class Scarface_Flag_Raise
               {
                  displayName = "Raise Scarface Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_scarFlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
               };
               class Gunfighters_Flag_Raise
               {
                  displayName = "Raise Gunfighters Flag";
                  distance = 3;
                  condition = "alive _target && ((getForcedFlagTexture _target) == '')";
                  statement = "0 = _target call PTF_fnc_gunFlagRaise";
                  showDisabled = 0;
                  priority = 1.1;
                  enableInside = 1;
                  icon = "\PTF_Textures\Icons\flagup_ico.paa";
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