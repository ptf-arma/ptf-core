# PTF_Briefing

Live Google Slides on the briefing-room screens of Peral's LHA (workshop 3596653038).
Peral's PBO is never edited: this addon only retextures the two screens (hiddenSelections
0 and 1 on `Peral_LHA`) and hangs ACE actions on the podium laptop.

## Using it

1. In Google Slides, either Share and set General access to "Anyone with the link", or use
   File > Share > Publish to web. Copy that link. (Sheets, Docs and Forms links are refused
   with a message saying so.)
2. In game, walk up to the laptop on the briefing-room podium. ACE interact shows
   **Briefing screens**: Load slides..., Next slide, Previous slide, First slide,
   Blank screens, Reload slides (show edits), Clear slides.
3. Load slides... asks for the link (needs Zeus Enhanced for the dialog). Both screens show
   slide 1 for everyone, including players who join later.
4. Edited the deck during the brief? Reload slides fetches it again and keeps your place.

Only players at the laptop, or a Zeus, can change slides. Loading a deck (Load and Reload)
also needs the Billet permission **Load briefing slides** (`slides_load`): give it to a role
in the unit's Billet settings. billet-link asks Billet about the player's SteamID, taken
from their network connection, before it fetches anything; someone without it is told so.
A server whose billet-link isn't linked to a Billet unit (no `billet_link.toml`) lets anyone
at the laptop load.

## What it needs

- **Server:** billet-link with slide support (`caps` includes `slides`) and the Billet
  permission check (any billet-link release after 0.13.9), loaded as a server mod. It
  downloads the deck from Google and renders it; the source is in the Billet repo,
  `mod/extension/src/slides.rs`. Without it the screens stay as they are and the laptop
  menu says so.
- **Players:** nothing extra. Slides reach them as images over the mission's own network
  traffic, about 100-200 KB per slide, fetched only near the ship: the slide on screen and
  the next one.
- Nothing here needs BattlEye whitelisting: the only DLL runs on the server.
- Missions with a remote-exec whitelist (`CfgRemoteExec` mode 1) must allow these, or
  nothing reaches the server:

  ```cpp
  class CfgRemoteExec {
      class Functions {
          class PTF_Briefing_fnc_requestLoad { allowedTargets = 2; };
          class PTF_Briefing_fnc_setSlide { allowedTargets = 2; };
          class PTF_Briefing_fnc_requestSlide { allowedTargets = 2; };
          class PTF_Briefing_fnc_receiveSlide { allowedTargets = 1; };
          class PTF_Briefing_fnc_notify { allowedTargets = 1; };
      };
  };
  ```

## How it works

| step | where | file |
| --- | --- | --- |
| Laptop action asks to load a link | client to server | `fn_addActions`, `fn_openLoadDialog`, `fn_requestLoad` |
| billet-link downloads the PDF export and renders JPEGs | server DLL | Billet `slides.rs` |
| Callback says ready; slides are read out and kept | server | `fn_onExtension` |
| Ship variables `PTF_Briefing_deck` / `_slide` / `_blank` change | server, public | `fn_setSlide` |
| Each client asks for the slides it needs | client to server to client | `fn_clientLoop`, `fn_requestSlide`, `fn_receiveSlide` |
| A sandboxed browser page draws the slide into each screen's texture | client | `viewer.html`, `fn_clientLoop` |

Things learned the hard way, all checked in game with `tools/briefing-test`:

- Arma's browser can't load web pages on the Stable branch (`allowExternalURL` is
  Development Branch only), so slides travel as JPEG data URLs into a local page.
- UI textures must be power-of-two sizes. The screens are 1.5:1, so `viewer.html`
  corrects for the 2:1 texture (`screens[]` in config holds each screen's shape).
- A UI texture's display only exists once the screen is on camera, and only refreshes
  on `displayUpdate`, which the client loop pumps for a few seconds after each change.
- `entities` doesn't list `Peral_LHA`, so ships are found with `nearestObjects` around
  the camera.
- The laptop proxy's position can't be read with `selectionPosition`, so
  `laptopOffset[]` is measured.
- On a dedicated server `remoteExecutedOwner` came back 0 for a headless client's
  requests, so clients also send their `clientOwner` (`fn_callerOwner`).
- HEMTT 1.22 can't parse `ctrlWebBrowserAction`, so it's compiled from a string in `fn_init`.

## Testing

```bash
python tools/briefing-test/run.py --billet-dll <billet repo>/mod/extension/target/release/billet_link.dll
```

```bash
python tools/briefing-test/mp.py --billet-dll <billet repo>/mod/extension/target/release/billet_link.dll
```

The first plays the LHA in single player and screenshots the screens and the laptop's ACE
menu into `.hemttout/briefing-test/shots`. The second runs a dedicated server and a headless
client and checks every slide arrives intact (`BRIEFMP ... MATCH` in the server RPT).
