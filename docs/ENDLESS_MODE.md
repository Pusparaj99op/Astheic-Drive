# Endless Mode: how to build, play and tune

The first vertical slice of the endless coastal highway (Phase 1, milestones M2, M3 and M5 in a lighter form).
All of it is C++ under `AstheticDrive/Source/AstheticDrive/Variant_Endless/`. It runs on the template
sports car and engine basic shapes, so no extra assets are needed to try it.

## What you get
- **Infinite procedural road**: seeded and deterministic. It has straights, curves and S-bends, hills, banked turns,
  **switchback U-turns** and **bridges over the ocean**, with 4 lanes, shoulders, guard rails, lane markings,
  a terrain slope down to the sea, palms, street lamps and bridge pillars.
- **Chunk streaming**: 50 m chunks are built ahead of the car and recycled behind it from a pool.
- **Ocean**: a sea plane that follows the car. Falling in puts you back on the road.
- **Dusk lighting**: low warm sun, sky atmosphere, real-time sky light, fog, bloom, motion blur and vignette.
  It's only spawned if the level has no directional light.
- **Speed feel**: FOV kick with speed, and motion blur on the chase camera.
- **Traffic**: kinematic sports cars in both directions, with lane keeping and simple following.
- **Score loop**: distance × speed multiplier, **near-miss combos** (worth more for oncoming cars), coins,
  crashes (a hard hit ends the run, a light bump breaks the combo), and a run summary with auto restart.
- **Save**: best score, best distance, best combo and total coins (`EndlessProgress` save slot).
- **Haptics**: on near misses and crashes (gamepad rumble / phone vibration).

## First run (about 2 minutes)
1. Pull, then right click `AstheticDrive.uproject` → **Generate Visual Studio project files**.
2. Build the editor once: **Development Editor** (or just open the .uproject and let it compile).
   The `ProceduralMeshComponent` plugin is now enabled in the .uproject, so accept if the editor asks to rebuild.
3. In the editor: **File → New Level → Empty Level**. Save it as `Content/Variant_Endless/Maps/Lvl_Endless`.
   Any map whose name starts with `Lvl_Endless` uses `EndlessGameMode` automatically (see `DefaultEngine.ini`),
   so you don't need to touch World Settings.
4. Press **Play**.

Optional: to make it the startup map, set **Project Settings → Maps & Modes → Editor Startup Map / Game Default Map**
to `Lvl_Endless`. Do this before packaging for Android.

## Android build (primary target)
The project is set up for **Android first** (Galaxy S24 Ultra). Windows is only used to run the editor and compile.
- `DefaultEngine.ini` → `AndroidRuntimeSettings`: package `com.astheticdrive.game`, arm64 only, Vulkan only,
  min SDK 26, target SDK 34, landscape, fullscreen, data packed inside the APK.
- `Config/Android/AndroidEngine.ini`: mobile-only renderer overrides (forward shading with MSAA, no Lumen,
  Nanite, ray tracing or virtual shadow maps, 60 fps cap). The editor keeps the desktop settings.
- **The packaged game boots straight into the endless mode.** `GameDefaultMap` is the engine's empty `Entry` map with
  `LocalMapOptions=?game=Endless`, so you don't need to make a map for device builds.

Steps:
1. Install Android Studio. Then in the editor go to **Platforms → Android → Installed SDK / Turnkey** and let it install
   the SDK/NDK versions UE 5.8 asks for.
2. Plug in the S24 Ultra with USB debugging enabled.
3. **Platforms → Android → Quick Launch** (deploys and runs), or **Package Project** for an APK.

## Controls
These are the template's own mappings: keyboard (W/S or arrows, A/D, Space for handbrake), gamepad, or the on-screen touch
controls on mobile. **Tilt steering** is experimental and off by default. Turn it on with
`bUseTiltSteering=True` under `[/Script/AstheticDrive.EndlessPlayerController]` in `Config/DefaultGame.ini`.
If it steers the wrong way, flip `bInvertTilt`.

## Tuning (in Play: select the actor in the Outliner and edit its Details)
| Actor | Useful settings |
|---|---|
| `EndlessRoadStreamer` | `Seed` (0 = random), `ChunksAhead/Behind`, `MaxBuildsPerTick`, coin row chance, `Biome` |
| `EndlessTrafficManager` | car count, speeds, oncoming chance, near-miss distance and min speed |
| `EndlessEnvironment` | sun elevation, azimuth, intensity, color, fog, exposure, bloom, motion blur |
| `EndlessGameMode` | crash threshold, combo timeout, points, `RoadSeed`, `Biome`, toggles for traffic and environment |
| `EndlessPlayerController` | FOV range, motion blur, tilt settings |

For values that should stick, make a Blueprint child of `EndlessGameMode` and set its defaults there,
then set it as the World Settings game mode override of `Lvl_Endless`.

## Swapping in purchased (Fab) assets
- **Road and props look**: create a Data Asset of type `EndlessBiomeData`. Set the materials (road, terrain, rails,
  ocean...) and optional palm and lamp meshes (pivot at the base), then assign it to `EndlessGameMode → Biome`.
  Empty slots fall back to tinted basic shapes.
- **Player car**: set `DefaultPawnClass` in a Blueprint child of `EndlessGameMode` to your car. It must derive from
  `AstheticDrivePawn`, the same as the template cars.
- **Traffic car meshes**: `AEndlessTrafficCar` uses the template sports car meshes. Replace the mesh paths in its
  constructor or make the meshes editable when real traffic cars are bought.

## Automated tests
**Tools → Session Frontend → Automation**, filter `AstheticDrive.Endless`, then run:
- `RoadGenerator.Determinism`: the same seed gives the same road, different seeds differ, and sampling order doesn't matter.
- `RoadGenerator.Continuity`: no gaps or heading jumps at segment joins (50 km, 4 seeds).
- `RoadGenerator.Bounds`: heading stays in the forward band (the road can't cross itself), elevation stays in range,
  bridges sit at bridge height, every hairpin is paired, and there are no NaNs.
- `RoadGenerator.Prune`: pruning old segments doesn't change the road.

## How it fits together
```
EndlessGameMode ── spawns ──> EndlessEnvironment      (dusk lighting, only if the level has none)
       │                      EndlessRoadStreamer ──> FEndlessRoadGenerator (seeded centerline, plain C++)
       │                             │            └─> pooled EndlessRoadChunk (procedural mesh + instanced props)
       │                             └─> pooled EndlessCoin
       │                      EndlessTrafficManager ─> pooled EndlessTrafficCar (near-miss detection)
       ├── PlayerController: EndlessPlayerController (template controller + FOV, haptics, tilt, fall recovery)
       ├── HUD: EndlessHUD (canvas text, replace with UMG later)
       └── Save: UEndlessSaveGame
```

## Known limits / next steps
- Art is placeholder (basic shapes). Next: buy the road, palm and car packs and plug them in through `EndlessBiomeData`.
- No engine audio yet (M4: MetaSounds RPM layers, tire and wind loops).
- No floating origin yet. UE5 large world coordinates keep things precise for hundreds of km. Revisit if
  physics jitters on very long runs.
- No quality presets / device profiles yet (M6). Profile on the S24 Ultra after the art pass.
- Wheel orientation on traffic cars mirrors the template Blueprint's guess. If the rims face inward, swap the yaw
  signs in `EndlessTrafficCar.cpp`.
