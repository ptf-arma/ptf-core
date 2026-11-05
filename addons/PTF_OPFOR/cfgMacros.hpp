// Sets a unit's magazines and its respawn magazines to the same list, so they can't drift
// apart. Define the list, use this macro, then undefine it:
//
//    #define PTF_MAGS \
//       "first_magazine", \
//       "last_magazine"
//    PTF_KIT_MAGAZINES
//    #undef PTF_MAGS
//
// Array order still matters. See the capacity note in README.md.
#define PTF_KIT_MAGAZINES \
   magazines[] = {PTF_MAGS}; \
   respawnMagazines[] = {PTF_MAGS};
