// ---------------------------------------------------------------------------
// Pereno uniform items.
//
// The engine only lets a soldier wear a uniform whose ItemInfo.uniformClass
// points at a soldier of the SAME SIDE. RHS's M93 uniforms link to HIDF
// display soldiers (side = 1, BLUFOR), so EAST Perenos wearing them threw
// "Uniform ... is not allowed for soldier class ..." in the RPT and risked
// spawning unclothed. These reissue the same uniforms linked to our own
// EAST soldier classes -- same model, same textures, correct side.
// ---------------------------------------------------------------------------

class UniformItem;
class rhsgref_uniform_og107;
class rhsgref_uniform_og107_erdl;
class rhsgref_uniform_ERDL;

class PTF_U_pereno_og107: rhsgref_uniform_og107
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "M93 (OG-107, Pereno)";
   class ItemInfo: UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTF_Pereno_conscript";
      containerClass = "Supply40";
      mass = 40;
   };
};

class PTF_U_pereno_og107_erdl: rhsgref_uniform_og107_erdl
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "M93 (OG-107/ERDL, Pereno)";
   class ItemInfo: UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTF_Pereno_rifleman";
      containerClass = "Supply40";
      mass = 40;
   };
};

class PTF_U_pereno_erdl: rhsgref_uniform_ERDL
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "M93 (ERDL, Pereno)";
   class ItemInfo: UniformItem
   {
      uniformModel = "-";
      uniformClass = "PTF_Pereno_teamleader";
      containerClass = "Supply40";
      mass = 40;
   };
};
