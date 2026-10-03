# Android Photoreal Endless Driving Game (UE5) — Design Brief

## Context
Solo developer (no UE installed yet) wants a high-end Android car game in Unreal Engine 5. Reference video (`reference.mp4`): cinematic dusk coastal highway, low rear chase cam on a dark supercar, red LED taillights, heavy motion blur, palms, ocean horizon. Goal: "satisfaction and ASMR" driving with deep car customization, built from purchased Fab assets and purchased car models.

## Agreed requirements (from user)
- **Build order:** (2) endless driver -> (3) racing with missions -> (1) open-world. Each is its own spec/plan cycle.
- **World:** infinite streaming, unpredictable; turns, U-turns, bridges, ocean crossings, biomes.
- **Driving:** semi-sim physics; 3rd-person chase + cockpit cameras. Landscape orientation.
- **Visuals:** photoreal, dusk look first; full dynamic weather and time-of-day later (layered, cheap stack).
- **Device:** high-end Android, quality presets (Low/Med/High/Ultra) auto-detected + user adjustable. Test device: Galaxy S24 Ultra via USB.
- **Customization:** paint/materials/livery, wheels/rims/tires/ride height, body kits/parts, engine sound + performance tuning.
- **Progression:** distance/score + coins, near-misses, traffic/obstacles, daily rewards/challenges, car unlock tiers.
- **Monetization:** free, IAP for cosmetics + car packs (billing wired late; economy stubbed early).
- **Online:** offline-first; cloud save/leaderboards possible later.
- **Controls:** tilt, on-screen wheel/arrows, gamepad, customizable layout.
- **ASMR priorities:** engine/turbo/exhaust audio, tire/road/wind audio, speed visuals (blur, FOV kick, streaks), haptics + near-miss feedback.
- **Language split:** C++ for core systems (physics glue, world generator, streaming, save, customization data); Blueprints/editor for UI, materials, asset setup, tuning (user does by hand from instructions).
- **Vehicle physics:** buy a Fab vehicle plugin (must have C++ source, Android support, high-speed stability, custom mesh/wheel swap).
- **World gen:** custom C++ chunk generator (spline road graph -> pooled modular chunks streamed ahead of the car).

## Approach: Vertical slice first (approved)
Phase 1 slice = single dusk coastal highway biome, one car, custom chunk generator, vehicle plugin integrated, ASMR audio/visuals, profiled on the S24 Ultra. Biomes, weather, deep customization, IAP are layers added after the slice hits perf targets.

## Architecture (units, one purpose each)
1. **Road/World Generator (C++)** — seeded route graph (straights, curves, U-turns, bridges, ocean spans); emits chunk descriptors. Deterministic by seed.
2. **Chunk Streamer (C++)** — pooled chunk actors, spawn ahead / recycle behind, floating-origin rebasing for infinite distance, HISM/instancing for props.
3. **Biome System** — data assets define materials, prop sets, sky/post presets; blend at chunk boundaries.
4. **Vehicle Layer** — wraps the Fab plugin behind our `IVehicleDriver` interface so the plugin can be swapped; exposes tuning data (power, grip, ride height).
5. **Customization Model (C++ data + UI)** — car = base mesh + slots (wheels, body parts, paint, livery, sound bank); saved as a loadout struct.
6. **Audio (ASMR)** — RPM-layered engine (MetaSounds), turbo/exhaust/backfire, surface-based tires, wind scaling with speed.
7. **Camera/Feel** — chase + cockpit, FOV kick, motion blur, shake, speed-streak Niagara.
8. **Gameplay** — traffic AI, near-miss scoring, coins, daily challenges.
9. **Platform** — save game, settings/presets, haptics, billing stub, input mapping (tilt/touch/gamepad).

## Performance strategy (mobile)
Vulkan, mobile forward renderer, no Lumen/Nanite dependence on Android; baked-style lighting + stylized post for the dusk look; aggressive LODs, HLOD/instancing, texture streaming budgets, material complexity limits, 60 fps target at High on S24 Ultra, scalability presets. Profile every milestone on-device (Unreal Insights, GPU Visualizer, Android GPU Inspector).

## Car asset checklist (before buying)
Separate wheels/body/doors/glass/lights, clean pivots, LOD0-3, roughly <=150k tris at LOD0 for the hero car, PBR textures <=2K for mobile, modular body parts for kits, license allows game use.

## Milestones (Phase 1)
- M0 Setup: install UE 5.x, Android SDK/NDK/Studio, package empty project to S24 Ultra.
- M1 Drive: vehicle plugin + test car on flat road, tilt/touch input.
- M2 World: chunk generator + streamer; straights and curves, then U-turns/bridges/ocean.
- M3 Look: dusk lighting/post, speed visuals, biome-0 props.
- M4 ASMR: engine/tire/wind audio, haptics, near-miss.
- M5 Loop: traffic, score, coins, basic garage (paint + wheels).
- M6 Perf pass + presets on S24 Ultra.

## Open items to resolve in the spec
- Pin exact UE version after checking chosen plugin compatibility.
- Specific Fab vehicle plugin + first car (user shares links or asks for a shortlist).
- Floating-origin vs World Partition tradeoff for infinite distance.
- Weather layering plan and its mobile cost budget.

## Verification
Each milestone: package to S24 Ultra over USB, measure fps/frametime/thermals/memory over a 10-minute run; automated C++ tests for generator determinism and chunk pooling (80%+ coverage on non-render logic).

## Status
Spec written; awaiting user review before invoking writing-plans for the implementation plan.
