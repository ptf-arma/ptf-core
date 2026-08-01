// ---------------------------------------------------------------------------
// La Guardia weapon variants.
//
// "Modern optics" is the single most important thing separating La Guardia
// from the garrison, and a unit's weapons[] array cannot carry attachments --
// naming rhs_weap_ak103 alone would hand them iron sights. These classes bake
// the optic and laser onto the rifle via LinkedItems so the AI actually
// fields them and they show up correctly in the arsenal.
//
// The AK-103 is deliberate: it is the real service rifle of the region's
// cash-rich armies, and it puts La Guardia on a different ammunition family
// from the FAL-armed Perenos.
//
// The Zenitco B-33 dust cover mounts a 1913 rail through CBA's ASDG joint
// rail system, so Western optics mount on the Russian rifle -- which is
// exactly what "paid in hard currency" should look like.
// ---------------------------------------------------------------------------

class rhs_weap_ak103_zenitco01_b33;
class rhs_weap_ak103_gp25;

class PTF_weap_guardia_ak103: rhs_weap_ak103_zenitco01_b33
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "AK-103 (Guardia)";
   baseWeapon = "PTF_weap_guardia_ak103";
   class LinkedItems
   {
      class LinkedItemsOptic
      {
         slot = "CowsSlot";
         item = "rhsusf_acc_eotech_xps3";
      };
      class LinkedItemsAcc
      {
         slot = "PointerSlot";
         item = "rhsusf_acc_anpeq15";
      };
   };
};

// Longer-ranged variant for the veteran tier and the cadre. Same rifle, an
// optic that reaches further -- escalation you can see through binoculars.
class PTF_weap_guardia_ak103_mdo: rhs_weap_ak103_zenitco01_b33
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "AK-103 MDO (Guardia)";
   baseWeapon = "PTF_weap_guardia_ak103_mdo";
   class LinkedItems
   {
      class LinkedItemsOptic
      {
         slot = "CowsSlot";
         item = "rhsusf_acc_ACOG_MDO";
      };
      class LinkedItemsAcc
      {
         slot = "PointerSlot";
         item = "rhsusf_acc_anpeq15";
      };
   };
};

// The GP-25 variant has no rail, so the grenadier runs irons on the rifle.
// Declared here anyway so the faction's weapons are all in one place.
class PTF_weap_guardia_ak103_gp25: rhs_weap_ak103_gp25
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "AK-103 GP-25 (Guardia)";
   baseWeapon = "PTF_weap_guardia_ak103_gp25";
};
