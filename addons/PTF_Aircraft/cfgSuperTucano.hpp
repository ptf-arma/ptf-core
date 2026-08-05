class PTF_SuperTucano : RHSGREF_A29B_HIDF
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_hasCargo = 0;
   maximumLoad = 375;


   faction = "BLU_F";
   side = 1;

   author = "Paramarine Task Force";
   displayName = "SuperTucano [MAG36]";
	class textureSources
	{
		class PTF_Trainer
		{
			author = "$STR_RHS_AUTHOR_FULL";
			displayName = "PTF_Trainer";
			textures[] = {"\z\PTF\addons\PTF_Textures\aircraft\Super Tucano\Trainer\ST_Fuselage_Navy_co.paa","\z\PTF\addons\PTF_Textures\aircraft\Super Tucano\Trainer\ST_WingsAndStabs_Navy_co.paa","\z\PTF\addons\PTF_Textures\aircraft\Super Tucano\Trainer\ST_EverythingElse_Navy_co.paa",""};
			factions[] = {};
		};
   };
   textureList[] = {"PTF_Trainer",1};
};
