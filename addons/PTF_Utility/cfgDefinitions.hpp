#define mag_xx(a, b) \
   class _xx_##a     \
   {                 \
      magazine = #a; \
      count = b;     \
   }
#define weap_xx(a, b) \
   class _xx_##a      \
   {                  \
      weapon = #a;    \
      count = b;      \
   }
#define item_xx(a, b) \
   class _xx_##a      \
   {                  \
      name = #a;      \
      count = b;      \
   }
#define backpack_xx(a, b) \
   class _xx_##a          \
   {                      \
      backpack = #a;      \
      count = b;          \
   }

// Shared with PTF_Vehicles and PTF_Aircraft. These set ACE cargo and dragging together:
// a vehicle that holds nothing, can't be loaded into anything and can't be dragged...
#define PTF_ACE_NO_CARGO \
   ace_cargo_space = 0; \
   ace_cargo_hasCargo = 0; \
   ace_cargo_size = 0; \
   ace_cargo_canLoad = 0; \
   ace_dragging_canCarry = 0; \
   ace_dragging_canDrag = 0;
// ...and the same, except that it holds SPACE units of ACE cargo.
#define PTF_ACE_CARGO_SPACE(SPACE) \
   ace_cargo_space = SPACE; \
   ace_cargo_hasCargo = 1; \
   ace_cargo_size = 0; \
   ace_cargo_canLoad = 0; \
   ace_dragging_canCarry = 0; \
   ace_dragging_canDrag = 0;
