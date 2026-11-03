class CfgWeapons {
    // --- Restore vanilla parents --------------------------------------------
    // Both PBOs meant to forward-declare these, but wrote them with a body
    // (`class X { class ItemInfo; };`), which resets the vanilla parent:
    // - Peral_M4A1: InventoryOpticsItem_Base_F loses InventoryItem_Base_F.
    //   It is the base of every optic attachment in the game.
    // - Peral_USMC_Gear: Vest_Camo_Base loses ItemCore.
    // An empty body with the right parent puts the inheritance back without
    // touching anything either PBO added.
    class InventoryItem_Base_F;
    class InventoryOpticsItem_Base_F: InventoryItem_Base_F {};

    class ItemCore;
    class Vest_Camo_Base: ItemCore {};
};
