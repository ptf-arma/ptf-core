class FIR_AV8B;

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
   hiddenselectionstextures[] = {"\z\PTF\addons\PTF_Textures\aircraft\AV8B\VMA-542\body_co.paa","\z\PTF\addons\PTF_Textures\aircraft\AV8B\VMA-542\wing_co.paa","",""};
   class TextureSources{
      class VMA_542{
         displayName="VMA-542";
         textures[]={"\z\PTF\addons\PTF_Textures\aircraft\AV8B\VMA-542\body_co.paa","\z\PTF\addons\PTF_Textures\aircraft\AV8B\VMA-542\wing_co.paa"};
				factions[]={BLU_F, PTF};
      };
      class VMA_542_CAG{
         displayName="VMA-542 CAG";
         textures[]={"\z\PTF\addons\PTF_Textures\aircraft\AV8B\VMA-542 CAG\body_co.paa","\z\PTF\addons\PTF_Textures\aircraft\AV8B\VMA-542 CAG\wing_co.paa"};
			factions[]={BLU_F,PTF};
      };
   };
};