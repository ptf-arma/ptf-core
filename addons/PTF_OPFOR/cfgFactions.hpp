class CfgFactionClasses
{
   // Layer 1 of the Valmeran campaign OPFOR: the original army garrison.
   // Conscripts and long-service NCOs, island-born, ageing kit, no night
   // vision. Defeated by fracture rather than attrition.
   class PTF_OPFOR_Perenos
   {
      displayName = "BI-7 ""Pera"" (los Perenos)";
      priority = 3;
      side = 0;   // EAST
      icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
      flag = "\z\PTF\addons\PTF_OPFOR\data\flag_perenos_co.paa";
   };

   // Layer 2: Bastida's praetorians. Hand-picked, paid in hard currency,
   // modern optics and working night vision. ~140 strong, garrisoning exactly
   // two places. Defeated by killing them.
   class PTF_OPFOR_Guardia
   {
      displayName = "La Guardia (Destacamento Especial Bastida)";
      priority = 4;
      side = 0;   // EAST
      icon = "\A3\ui_f\data\map\markers\nato\o_inf.paa";
      flag = "\z\PTF\addons\PTF_OPFOR\data\flag_guardia_co.paa";
   };

   // Layer 3: foreign contractors on Marenco's payroll. ~50 ex-special-forces
   // from four or five countries who hold the airport and the research
   // compound, and who own the island's air defence. Defeated by economics --
   // but EAST like the rest, since withdrawal is campaign scripting.
   class PTF_OPFOR_Kestrel
   {
      displayName = "Kestrel Group";
      priority = 5;
      side = 0;   // EAST
      icon = "\A3\ui_f\data\map\markers\nato\o_recon.paa";
      flag = "\z\PTF\addons\PTF_OPFOR\data\flag_kestrel_co.paa";
   };
};
