# Multiplayer test without a game window

Runs the mod on a dedicated server with two headless clients, then compares a whole build
against an earlier one. It catches what `hemtt check` can't: things that only go wrong when
machines join, and side effects of a config change on other classes.

## What you need

- Arma 3, Arma 3 Server and the mods in `.hemtt/launch.toml`, from Steam. Set `PTF_STEAM_DIR`
  if Steam isn't in the default folder.
- A built mod folder from `tools\release.ps1`. `-NoSign` is fine, because the test server
  doesn't verify signatures.

## Comparing two builds

`release.ps1` publishes a junction onto `.hemttout\release`. The next build wipes that folder,
so copy the baseline somewhere first, using `robocopy` because of the `[PTF]` in the name.

1. Build `develop` and copy the mod folder to a safe place.
2. Run the test on it:

   ```bash
   python tools/mp-test/run_server.py baseline "C:\somewhere\@[PTF] Paramarine Milsim Core"
   ```

3. Build your branch and run the test again, labelled `fixed`.
4. Compare the two. Add `--no-config-change` for a refactor that should change nothing.

   ```bash
   python tools/mp-test/compare.py .hemttout/mp-test/baseline/server.rpt .hemttout/mp-test/fixed/server.rpt
   ```

The server run takes about 5 minutes, and RPTs land in `.hemttout/mp-test/<label>/`. It uses port
2402, because other local servers tend to be on 2302. Change the port with `--port`.

## What it reports

- **Config:** every class in CfgVehicles, CfgWeapons, CfgMagazines, CfgAmmo and CfgGlasses, about
  70,000 of them. Classes with PTF content also get a hash of all their values, so a change to
  any value shows up, even an inherited one.
- **Crates and arsenals:** contents and ACE actions before anyone joins, after one client joins,
  after placing new ones the way Zeus does, and after a second client joins.
- **Errors:** counts of known RPT problems. The script exits with 1 if any count goes up.

To test more objects, add them to the mission in `ptf_smoke.Stratis`.

## Checks that need an interface

Headless clients have no interface, so they can't open arsenals or use ACE actions on the player.
For those, `run_client.py` plays `ptf_ui.Stratis` once in single player. It opens a game window
for about a minute, and the game closes itself.

```bash
python tools/mp-test/run_client.py fixed "C:\somewhere\@[PTF] Paramarine Milsim Core"
```

Search its `client.rpt` for `PTFUI`.

## What this doesn't cover

- A real player joining a server. A real client started with `-connect` never finished joining
  when this was tried, and the cause is unknown.
- The Zeus and Eden menus.
- Anything that has to be seen, such as textures, models or sound.
