/* Checks if the player attempting to get in pilot seat is both a pilot
  and is whitelisted in the _SOAR list of player UIDs. Add more UIDs to the list as follows
  ["UID", "nextuid", "lastuid"]
*/

_MAGHQ = ["76561198044500463" /* xxx*/
];

_RestrictAir = [ "PTF_MD500_HQ", "PTF_MQ9_HQ", "PTF_UH1Y_HQ", "PTF_RQ4A_HQ", "PTF_Cessna_400_HQ", "PTF_AH1Z_HQ" ];

if (!((getPlayerUID player)in _MAGHQ)
    then
    {
private
   "_v";
   _v = vehicle player;
   _t = typeof _v;
   if (_t in _RestrictAir)
      then
      {
         if (driver _v == player)
            then
            {
               player action["eject", _v];
               player action["engineOff", _v];
               hint "You're not J.Downs";
            };
      };
    };