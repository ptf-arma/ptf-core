// ---------------------------------------------------------------------------
// Kestrel Group weapon variants.
//
// Same reason as the Guardia AK-103s: a unit's weapons[] array cannot carry
// attachments, so naming the RHS weapon directly hands the man bare irons.
// The sniper shipped that way in the first build -- no glass, no bipod, on a
// bolt-action rifle. These classes bake the optic and bipod on so the AI
// actually fields them and they appear correctly in the arsenal.
// ---------------------------------------------------------------------------

class rhs_weap_XM2010;
class rhs_weap_M107_w;

// M2010 with its issued day scope and a Harris bipod. Kestrel's precision
// asset should look like it belongs to professionals.
class PTF_weap_kestrel_xm2010: rhs_weap_XM2010
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "XM2010 (Kestrel)";
   baseWeapon = "PTF_weap_kestrel_xm2010";
   class LinkedItems
   {
      class LinkedItemsOptic
      {
         slot = "CowsSlot";
         item = "rhsusf_acc_M2010S";
      };
      class LinkedItemsUnder
      {
         slot = "UnderBarrelSlot";
         item = "rhsusf_acc_harris_bipod";
      };
   };
};

// The anti-materiel rifle wants glass and a bipod for the same reason -- it
// is meant to disable airframes and shipments at range, not be fired offhand.
class PTF_weap_kestrel_m107: rhs_weap_M107_w
{
   author = "Paramarine Task Force";
   scope = 2;
   displayName = "M107 (Kestrel)";
   baseWeapon = "PTF_weap_kestrel_m107";
   class LinkedItems
   {
      class LinkedItemsOptic
      {
         slot = "CowsSlot";
         item = "rhsusf_acc_LEUPOLDMK4";
      };
   };
};
