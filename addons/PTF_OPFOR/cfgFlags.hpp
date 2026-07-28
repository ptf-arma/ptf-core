// ---------------------------------------------------------------------------
// Placeable flagpoles for the Valmeran campaign.
//
// Flag cloth on a FlagCarrier is a proxy, not a hiddenSelection, so the
// texture is applied with setFlagTexture in an init handler -- the same way
// vanilla FlagChecked_F does it. Setting hiddenSelectionsTextures here would
// paint the pole, not the flag.
//
// These are for mission dressing: a Valmeran national flag over a town hall,
// the battalion colour over the Pereno barracks, La Guardia's over Presa
// Alta, Kestrel's over the airport. Useful for telling players who holds
// what before a shot is fired.
// ---------------------------------------------------------------------------

class PTF_Flag_Valmera_F: FlagChecked_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   displayName = "Flag - Valmera (National)";
   editorSubcategory = "EdSubcat_Flags";
   class EventHandlers
   {
      init = "(_this select 0) setFlagTexture '\z\PTF\addons\PTF_OPFOR\data\flag_valmera_co.paa';";
   };
};

class PTF_Flag_Perenos_F: FlagChecked_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   displayName = "Flag - BI-7 ""Pera""";
   editorSubcategory = "EdSubcat_Flags";
   class EventHandlers
   {
      init = "(_this select 0) setFlagTexture '\z\PTF\addons\PTF_OPFOR\data\flag_perenos_co.paa';";
   };
};

class PTF_Flag_Guardia_F: FlagChecked_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   displayName = "Flag - La Guardia";
   editorSubcategory = "EdSubcat_Flags";
   class EventHandlers
   {
      init = "(_this select 0) setFlagTexture '\z\PTF\addons\PTF_OPFOR\data\flag_guardia_co.paa';";
   };
};

class PTF_Flag_Kestrel_F: FlagChecked_F
{
   author = "Paramarine Task Force";
   scope = 2;
   scopeCurator = 2;
   displayName = "Flag - Kestrel Group";
   editorSubcategory = "EdSubcat_Flags";
   class EventHandlers
   {
      init = "(_this select 0) setFlagTexture '\z\PTF\addons\PTF_OPFOR\data\flag_kestrel_co.paa';";
   };
};
