class CfgFactionClasses
{
   // Layer 1 of the Valmeran campaign OPFOR: the original army garrison.
   // Conscripts and long-service NCOs, island-born, ageing kit, no night
   // vision. Defeated by fracture rather than attrition.
   class PTF_OPFOR_Perenos
   {
      displayName = "los Perenos (7th Infantry Battalion ""Pera"")";
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
      displayName = "La Guardia (Bastida Special Detachment)";
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
   // The dockworkers' and timber union -- the only structure on the island
   // Bastida didn't build. A partner force: genuinely useful, genuinely
   // inconvenient. INDEPENDENT so missions can set its friendliness per-op.
   class PTF_IND_Sindicato
   {
      displayName = "El Sindicato";
      priority = 3;
      side = 2;   // INDEPENDENT
      icon = "\A3\ui_f\data\map\markers\nato\n_inf.paa";
      flag = "\z\PTF\addons\PTF_OPFOR\data\flag_sindicato_co.paa";
   };

   // The people all of this is happening to.
   class PTF_CIV_Valmera
   {
      displayName = "Valmera (Civilians)";
      priority = 3;
      side = 3;   // CIVILIAN
      icon = "\A3\ui_f\data\map\markers\nato\c_unknown.paa";
      flag = "\z\PTF\addons\PTF_OPFOR\data\flag_valmera_co.paa";
   };
};
