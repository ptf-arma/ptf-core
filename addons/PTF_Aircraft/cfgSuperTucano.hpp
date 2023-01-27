class PTF_SuperTucano : RHSGREF_A29B_HIDF
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
   maximumLoad = 375;
   driverCanSee = 31;
   gunnerCanSee = 31;
   faction = "BLU_F";
   side = 1;
   crew = "B_Pilot_F";
   fuelConsumptionRate = 0.1;
   fuelCapacity = 500;
   author = "Paramarine Task Force";
   displayName = "SuperTucano [MAG36]";

	class textureSources
	{
		class PTF_Trainer
		{
			author = "$STR_RHS_AUTHOR_FULL";
			displayName = "PTF_Trainer";
			textures[] = {"PTF_Textures\aircraft\Super Tucano\Trainer\ST_Fuselage_Navy_co.paa","PTF_Textures\aircraft\Super Tucano\Trainer\ST_WingsAndStabs_Navy_co.paa","PTF_Textures\aircraft\Super Tucano\Trainer\ST_EverythingElse_Navy_co.paa",""};		
			factions[] = {};
		};
   };

   textureList[] = {"PTF_Trainer",1};

};