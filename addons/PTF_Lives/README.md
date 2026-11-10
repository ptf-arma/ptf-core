# PTF_Lives

Every player gets a set number of lives for the mission. Run out, and you spectate until an
admin gives you one back.

## The rules

- Each player starts with the **starting lives** value the first time they join the mission.
  Leaving and rejoining keeps the count (it is kept by SteamID until the mission ends).
- A life is used when the player:
  - dies, including the pause menu's **Respawn** (which kills the unit), or
  - leaves the game while unconscious, by any means (quitting, a crash, a dropped connection).
- Leaving while conscious costs nothing.
- Using the last life puts the player in ACE's spectator instead of respawning. Through TFAR
  they hear the people around the spectator camera, and living players can't hear them
  (other spectators can). As soon as they have a life again, they respawn on their own, through
  the mission's normal respawn (its positions, menu and loadouts).
- A player who comes back after running out is put straight back into the spectator.
- While Lives is **off**, dying is free, and anyone spectating for lack of lives respawns.
- While Lives is **on**, the vanilla side ticket pool (the Respawn Tickets module) is kept
  full, so it can never block a respawn. Lives replaces it.

## Where players see it

On the Billet tablet or Rugged Phone (the `@billet_link_tablet` client mod), the **Home**
screen shows a Lives panel: your own lives, and everyone's, with who is down, respawning,
spectating or gone. It is hidden while Lives is off. Players without the tablet mod get a
notice in the corner when they use a life and when an admin changes theirs.

## Admins

Admins get a **Lives** tab on the tablet's left rail:

- switch Lives on or off,
- set the starting lives for players joining for the first time from now on,
- give (+) or take (-) a life from any player, including players who have left.

An admin is:

- the server's logged-in admin (`#login`), or the host of a player-hosted game, or
- anyone holding Billet's **Manage lives** permission (billet.gg, Settings, Roles). The server
  asks Billet when that player opens their tablet, at most once a minute. This needs
  billet-link on the server with `blk_fnc_role` (the release after 0.14.0).

Every change is checked again on the server and written to the server RPT
(`[PTF_Lives] <admin> set <player> to 2 lives`).

## Settings

Addon Options, Server, Paramarine Task Force, Lives. These only set the start of a mission:

| setting | default |
| --- | --- |
| Lives on at mission start | off |
| Starting lives | 3 |

A mission can force them in its `cba_settings.sqf`:

```sqf
force PTF_Lives_onSetting = true;
force PTF_Lives_startSetting = 2;
```

## Missions that whitelist remote execution

Missions with `CfgRemoteExec` mode 1 must allow these, or nothing reaches the server:

```cpp
class CfgRemoteExec {
    class Functions {
        class PTF_Lives_fnc_hello { allowedTargets = 2; };
        class PTF_Lives_fnc_askAdmin { allowedTargets = 2; };
        class PTF_Lives_fnc_admin { allowedTargets = 2; };
        class PTF_Lives_fnc_notify { allowedTargets = 1; };
    };
};
```

## How it works

| what | where | file |
| --- | --- | --- |
| The book of lives (SteamID: name, lives, lives used), deaths, unconscious disconnects, the side pool | server | `fn_serverInit`, `fn_charge` |
| Everyone's lives, status and the admin list, sent when they change | server, public | `fn_publish` |
| Admin check: `#login`, host, or Billet's answer to `lives_role` | server | `fn_isAdmin`, `fn_askAdmin` |
| A fresh body with no lives behind it is hidden and killed, at no cost | server | `fn_hello`, `fn_retire` |
| Holding a player dead (the respawn timer set out of reach, as the vanilla Tickets template does) and the spectator | client | `fn_clientInit`, `fn_spectate` |
| The tablet's Home panel and Lives tab | client | `fn_tablet` (through Billet's add-on slot, `class blk_tabletApps` in `config.cpp`) |

A client holds itself the instant it dies on its last life, before the server's count arrives,
so a short respawn delay can't slip past. If a respawn ever does, the server retires the new
body.

## Testing

```bash
python tools/lives-test/ui.py --billet <Billet repo or worktree>
```

Single player, in the background: the Home panel, the admin's Lives tab clicked through the
page (give and take, starting lives, search, off and on) and the Rugged Phone. Pictures of the
game window land in `.hemttout/mp-test/lives-ui`.

`tools/lives-test/run.py` is the multiplayer version (deaths, spectating, a crash while
unconscious and a rejoin, with a stand-in Billet granting "Manage lives"), but a game on the
same PC as the test server was refused by Steam, so it hasn't run yet. Until it does, check
those by hand on a server.
