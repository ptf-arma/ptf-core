// Shared by PTF_Clothes and PTF_Helmets.
//
// The usual second texture on a MICH or ACH: the tan accessory sheet. Pass the cover.
#define PTF_MICH_TEXTURES(COVER) \
   hiddenSelectionsTextures[] = {COVER, "rhsusf\addons\rhsusf_infantry\gear\head\data\ach_acc_tan_co.paa"};

// The standard helmet weight and protection. Write the block out for a helmet that differs.
#define PTF_HELMET_ITEMINFO \
   class ItemInfo : ItemInfo \
   { \
      mass = 20; \
      class HitpointsProtectionInfo \
      { \
         class Head \
         { \
            hitpointName = "HitHead"; \
            armor = 6; \
            passThrough = 0.5; \
         }; \
      }; \
   };
