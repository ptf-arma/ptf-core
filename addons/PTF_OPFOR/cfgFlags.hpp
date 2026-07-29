// ---------------------------------------------------------------------------
// Placeable flagpoles for the Valmeran campaign.
//
// Base class matters here. These originally inherited FlagChecked_F, which is
// the small CHECKERED RACING flag -- a different model with different cloth
// geometry and UV mapping, which made every design render offset and cropped
// on the pole. FlagCarrier is the proper military mast (Mast_F.p3d) and is
// what every vanilla Flag_*_F class inherits; its cloth maps the texture
// edge to edge, as the 512x256 vanilla flag textures do.
//
// Flag cloth on a FlagCarrier is a proxy, not a hiddenSelection, so the
// texture is applied with setFlagTexture in an init handler -- exactly the
// way vanilla Flag_NATO_F does it. Setting hiddenSelectionsTextures here
// would paint the pole, not the flag.
//
// These are for mission dressing: a Valmeran national flag over a town hall,
// the battalion colour over the Pereno barracks, La Guardia's over Presa
// Alta, Kestrel's over the airport. Useful for telling players who holds
// what before a shot is fired.
// ---------------------------------------------------------------------------

class PTF_Flag_Valmera_F: FlagCarrier
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

class PTF_Flag_Perenos_F: FlagCarrier
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

class PTF_Flag_Guardia_F: FlagCarrier
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

class PTF_Flag_Kestrel_F: FlagCarrier
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
