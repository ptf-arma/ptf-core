class PTF_F18C : FIR_F18C
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_hasCargo = 0;
   faction = "BLU_F";
   side = 1;
   author = "Paramarine Task Force";
   displayName = "F-18C Hornet [MAG36]";
   hiddenselectionstextures[] = {"PTF_Textures\aircraft\FA18C\VMFA 542\body_co.paa","PTF_Textures\aircraft\FA18C\VMFA 542\wing_co.paa","",""};
   #include "\PTF_Aircraft\FM\F-18FM.hpp"
   class ACE_Actions : ACE_Actions {
      class ACE_MainActions : ACE_MainActions {
         class F18_Loadouts {
            displayName = "Loadouts";
            statement = "";
            icon = "";
            class F18_Normal {
            displayName = "Normal";
            statement = "";
            icon = "";
            #include "\PTF_Scripts\fnc\Ace actions\air\F-18 normal.hpp"
         };
            class F18_Endurance {
             displayName = "Endurance";
            statement = "";
            icon = "";
            #include "\PTF_Scripts\fnc\Ace actions\air\F-18 Endurance.hpp"
         };
         };
      };
   };
};;
class PTF_F18C_CAG : PTF_F18C 
{
   displayName = "F-18C Hornet CAG [MAG36]";
   hiddenselectionstextures[] = {"PTF_Textures\aircraft\FA18C\VMFA 542 CAG\body_co.paa","PTF_Textures\aircraft\FA18C\VMFA 542 CAG\wing_co.paa","",""};
};
class PTF_F18D : FIR_F18D
{
   scope = 2;
   editorCategory = "PTF";
   editorSubcategory = "PTF_Air";
   ace_cargo_hasCargo = 0;
   faction = "BLU_F";
   side = 1;
   author = "Paramarine Task Force";
   displayName = "F-18D Hornet [MAG36]";
   hiddenselectionstextures[] = {"PTF_Textures\aircraft\FA18D\VMFA 542\body_co.paa","PTF_Textures\aircraft\FA18D\VMFA 542\wing_co.paa","",""};		
};