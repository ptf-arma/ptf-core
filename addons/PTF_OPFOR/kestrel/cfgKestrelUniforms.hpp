// ---------------------------------------------------------------------------
// Kestrel uniform items.
//
// Same side-lock fix as the Perenos (see cfgPerenosUniforms.hpp): RHS's
// national-camouflage M93 uniforms link to "nationalist" display soldiers
// (side = 2, INDEPENDENT), which the engine refuses on EAST units. Reissued
// here linked to Kestrel's own soldier classes.
// ---------------------------------------------------------------------------

// UniformItem is already declared by cfgPerenosUniforms.hpp, included first.
class rhsgref_uniform_woodland;
class rhsgref_uniform_dpm;
class rhsgref_uniform_altis_lizard;
class rhsgref_uniform_3color_desert;
class rhsgref_uniform_olive;

class PTF_U_kestrel_wdl: rhsgref_uniform_woodland
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "M93 (Woodland, Kestrel)";
   class ItemInfo: UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTF_Kestrel_operator";
      containerClass = "Supply40";
      mass = 40;
   };
};

class PTF_U_kestrel_dpm: rhsgref_uniform_dpm
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "M93 (DPM, Kestrel)";
   class ItemInfo: UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTF_Kestrel_operator_dpm";
      containerClass = "Supply40";
      mass = 40;
   };
};

class PTF_U_kestrel_lizard: rhsgref_uniform_altis_lizard
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "M93 (Lizard, Kestrel)";
   class ItemInfo: UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTF_Kestrel_operator_lizard";
      containerClass = "Supply40";
      mass = 40;
   };
};

class PTF_U_kestrel_desert: rhsgref_uniform_3color_desert
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "M93 (3-Color Desert, Kestrel)";
   class ItemInfo: UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTF_Kestrel_operator_desert";
      containerClass = "Supply40";
      mass = 40;
   };
};

class PTF_U_kestrel_olive: rhsgref_uniform_olive
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "M93 (Olive, Kestrel)";
   class ItemInfo: UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTF_Kestrel_hvt";
      containerClass = "Supply40";
      mass = 40;
   };
};
