class PTF_AV8B : FIR_AV8B
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_hasCargo = 0;
   faction = "BLU_F";
   side = 1;
   author = "Paramarine Task Force";
   displayName = "AV-8B Harrier [MAG36]";
   weapons[] = {"FIR_MasterArm","FIR_GAU12","FIR_CMLauncher"};
   magazines[] = {"FIR_GAU12_300rnd_M","FIR_240rnd_CMFlare_Chaff_Magazine"};
   hiddenselectionstextures[] = {"PTF_Textures\aircraft\AV8B\VMA-542\body_co.paa","PTF_Textures\aircraft\AV8B\VMA-542\wing_co.paa","",""};
   class TextureSources{
      class VMA_542{
         displayName="VMA-542";
         textures[]=
				{
					"PTF_Textures\aircraft\AV8B\VMA-542\body_co.paa",
					"PTF_Textures\aircraft\AV8B\VMA-542\wing_co.paa"
				};
				factions[]=
				{
					BLU_F,
               PTF
				};
      };
      class VMA_542_CAG{
         displayName="VMA-542 CAG";
         textures[]=
				{
					"PTF_Textures\aircraft\AV8B\VMA-542 CAG\body_co.paa",
					"PTF_Textures\aircraft\AV8B\VMA-542 CAG\wing_co.paa"
				};
				factions[]=
				{
					BLU_F,
               PTF
				};
      };
   };		
   fir_av8b_na_custom_skin = 1;
   fir_av8b_custom_name = "Blank";
   fir_av8b_custom_code = "FIR_AV8B_NA_Blank";
   editorPreview = "FIR_AV8B\ui\preview\NA_standard.jpg";			
};