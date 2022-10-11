class PTF_MD500_Trainer : PTF_MD500
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
   displayName = "MD-500 (Trainer) [MAG36]";

   hiddenSelections[] = {"camo1", "aiming_dot"};
   hiddenSelectionsTextures[] = {
       "\a3\air_f\Heli_Light_01\Data\heli_light_01_ext_blue_co.paa"};
};
class PTF_Cessna_400_Trainer : PTF_Cessna_400
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
   displayName = "Cessna 400 (Trainer) [MAG36]";

   hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4"};
   hiddenSelectionsTextures[] = {
       "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_Tribal_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_co.paa"};
};
class PTF_MD500_HQ : PTF_MD500
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_PersonalAir";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   faction = "BLU_F";
   crew = "B_Pilot_F";
   author = "Paramarine Task Force";
   displayName = "MD-500 (MAG36 HQ) [MAG36]";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 800;

   class Components : Components
   {
      class SensorsManagerComponent
      {
         class Components
         {
            class DataLinkSensorComponent : SensorTemplateDataLink
            {
            };
         };
      };
   };

   reportOwnPosition = true;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   showAllTargets = 2;

   hiddenSelections[] = {"camo1", "aiming_dot"};
   hiddenSelectionsTextures[] = {
       "\a3\air_f\Heli_Light_01\Data\Skins\heli_light_01_ext_graywatcher_co.paa"};
};
class PTF_Cessna_400_HQ : PTF_Cessna_400_Racing
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_PersonalAir";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   side = 1;
   faction = "BLU_F";
   author = "Paramarine Task Force";
   displayName = "Cessna 400 (MAG36 HQ) [MAG36]";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 800;

   class Components : Components
   {
      class SensorsManagerComponent
      {
         class Components
         {
            class DataLinkSensorComponent : SensorTemplateDataLink
            {
            };
         };
      };
   };

   reportOwnPosition = true;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   showAllTargets = 2;
   airBrakeFrictionCoef = 5;
   maxSpeed = 600;

   thrustCoef[] = {1.7, 1.6, 1.5, 1.45, 1.4, 1.35, 1.3, 1.25, 1.2, 1.15, 1.1, 1.05, 1, 0.95, 0.9, 0.85};

   hiddenSelections[] = {"camo1", "camo2", "camo3", "camo4"};
   hiddenSelectionsTextures[] = {
       "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_01_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_ext_02_RedLine_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_01_tan_co.paa", "A3\Air_F_Exp\Plane_Civil_01\Data\btt_int_02_tan_co.paa"};
};
class PTF_AH1Z_GUNFIGHTERS : PTF_AH1Z
{
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   faction = "BLU_F";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   author = "Paramarine Task Force";
   displayName = "AH-1Z (Gunfighters) [MAG36]";
   hiddenSelections[] = {
       "Camo1", "Camo2", "screen", "pip"};
   hiddenSelectionsTextures[] = {
       "\PTF_Textures\Aircraft\AH1Z\Gunfighters\ah1z_body_co.paa", "\PTF_Textures\Aircraft\AH1Z\Gunfighters\ah1z_engines_co.paa", "", ""};
};
class PTF_AH1Z_HQ : PTF_AH1Z
{
   editorCategory = "PTF";
   editorSubcategory = "PTF_PersonalAir";
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   author = "Paramarine Task Force";
   displayName = "AH-1Z (MAG36 HQ) [MAG36]";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 800;

   class Components : Components
   {
      class SensorsManagerComponent
      {
         class Components
         {
            class DataLinkSensorComponent : SensorTemplateDataLink
            {
            };
         };
      };
   };

   reportOwnPosition = true;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   showAllTargets = 2;

   hiddenSelections[] = {
       "Camo1", "Camo2", "screen", "pip"};
   hiddenSelectionsTextures[] = {
       "\PTF_Textures\Aircraft\AH1Z\HQ\ah1z_body_co.paa", "\PTF_Textures\Aircraft\AH1Z\HQ\ah1z_engines_co.paa", "", ""};
};
class PTF_MQ9_SCARFACE : PTF_MQ9
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   crew = "B_UAV_AI";
   author = "Paramarine Task Force";
   displayName = "MQ-9 (Scarface) [MAG36]";

   hiddenSelections[] = {"camo1", "camo2", "camo3", "tail_number_pre", "tail_number0", "tail_number1", "tail_number2", "tail_letter0", "tail_letter1", "tail_logo", "tail_art"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\MQ9\Scarface\USAF_MQ9_co.paa", "\PTF_Textures\Aircraft\MQ9\Scarface\USAF_MQ9_Wing_co.paa", "usaf_mq9\data\usaf_MQ9_hinges_co.paa", "", "\PTF_Textures\aircraft\3_ca.paa", "\PTF_Textures\aircraft\6_ca.paa", "", "", "", "", ""};
};
class PTF_MQ9_HQ : PTF_MQ9
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_PersonalAir";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   crew = "B_UAV_AI";
   author = "Paramarine Task Force";
   displayName = "MQ-9 (MAG36 HQ) [MAG36]";

   class Components : Components
   {
      class SensorsManagerComponent
      {
         class Components
         {
            class DataLinkSensorComponent : SensorTemplateDataLink
            {
            };
         };
      };
   };

   reportOwnPosition = true;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   showAllTargets = 2;

   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\MQ9\HQ\USAF_MQ9_co.paa", "\PTF_Textures\Aircraft\MQ9\HQ\USAF_MQ9_Wing_co.paa", "usaf_mq9\data\usaf_MQ9_hinges_co.paa", "", "\PTF_Textures\aircraft\3_ca.paa", "\PTF_Textures\aircraft\6_ca.paa", "", "", "", "", ""};
};
class PTF_RQ4A_HQ : PTF_RQ4A
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_PersonalAir";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 0;
   ace_cargo_hasCargo = 0;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   crew = "B_UAV_AI";
   author = "Paramarine Task Force";
   displayName = "RQ-4A (MAG36 HQ) [MAG36]";

   hiddenSelections[] = {"camo1"};
   hiddenSelectionsTextures[] = {"A3\Drones_F\Air_F_Gamma\UAV_02\Data\UAV_02_CO.paa"};

   class Components : Components
   {
      class SensorsManagerComponent
      {
         class Components
         {
            class DataLinkSensorComponent : SensorTemplateDataLink
            {
            };
         };
      };
   };

   reportOwnPosition = true;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   showAllTargets = 2;
};
class PTF_UH1Y_HQ : PTF_UH1Y
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_PersonalAir";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (MAG36 HQ) [MAG36]";
   crew = "B_Pilot_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 800;
   armorStructural = 1000;
   amor=1000;
   hullDamageCauseExplosion = 0;
   allowTabLock = 1;
   canUseScanner = 1;
   countermeasureActivationRadius = 10000;
   incomingMissileDetectionSystem = 16;

   class Components : Components
   {
      class SensorsManagerComponent
      {
         class Components
         {
            class DataLinkSensorComponent : SensorTemplateDataLink
            {
            };
         };
      };
   };

   reportOwnPosition = true;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   showAllTargets = 2;
   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\aircraft\uh1y\HQ\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_SCARFACE : PTF_UH1Y
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (Scarface) [MAG36]";
   crew = "B_Pilot_F";
   armorStructural = 1000;
   amor=1000;
   hullDamageCauseExplosion = 0;
   allowTabLock = 1;
   canUseScanner = 1;
   countermeasureActivationRadius = 10000;
   incomingMissileDetectionSystem = 16;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   reportOwnPosition = true;
   showAllTargets = 2;
   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\UH1Y\Scarface\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_SCARFACE_SL : PTF_UH1Y
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_PersonalAir";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (Scarface SL) [MAG36]";
   crew = "B_Pilot_F";
   armorStructural = 1000;
   amor=1000;
   hullDamageCauseExplosion = 0;
   allowTabLock = 1;
   canUseScanner = 1;
   countermeasureActivationRadius = 10000;
   incomingMissileDetectionSystem = 16;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   reportOwnPosition = true;
   showAllTargets = 2;
   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\UH1Y\ScarfaceSL\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_GUNFIGHTERS : PTF_UH1Y
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (Gunfighters) [MAG36]";
   crew = "B_Pilot_F";
   armorStructural = 1000;
   amor=1000;
   hullDamageCauseExplosion = 0;
   allowTabLock = 1;
   canUseScanner = 1;
   countermeasureActivationRadius = 10000;
   incomingMissileDetectionSystem = 16;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   reportOwnPosition = true;
   showAllTargets = 2;
   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\UH1Y\Gunfighters\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};
class PTF_UH1Y_GUNFIGHTERS_SL : PTF_UH1Y
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_PersonalAir";
   side = 1;
   faction = "BLU_F";
   ace_cargo_space = 10;
   ace_cargo_hasCargo = 1;
   ace_cargo_size = 0;
   ace_cargo_canLoad = 0;
   ace_dragging_canCarry = 0;
   ace_dragging_canDrag = 0;
   author = "Paramarine Task Force";
   displayName = "UH-1Y (Gunfighters SL) [MAG36]";
   crew = "B_Pilot_F";
   armorStructural = 1000;
   amor=1000;
   hullDamageCauseExplosion = 0;
   allowTabLock = 1;
   canUseScanner = 1;
   countermeasureActivationRadius = 10000;
   incomingMissileDetectionSystem = 16;
   receiveRemoteTargets = true;
   reportRemoteTargets = true;
   reportOwnPosition = true;
   showAllTargets = 2;
   hiddenSelections[] = {"camo1", "camo2", "rn1", "rn2", "rn3", "rn4", "tn1", "tn2", "tn3", "tn4", "tn5", "tn6", "dn1", "dn2", "dn3", "dn4", "dn5", "dn6", "dn7", "dn8", "dn9", "dn10", "dn11", "dn12", "zn1", "zn2", "zn3"};
   hiddenSelectionsTextures[] = {"\PTF_Textures\Aircraft\UH1Y\GunfightersSL\uh1y_ext_co.paa", "\PTF_Textures\aircraft\uh1y\uh1y_int_co.paa", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", ""};
};