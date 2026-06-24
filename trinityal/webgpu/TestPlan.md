# WebGPU Native Dawn Test Plan

## Configure

Start with a Windows x64 manifest build:

```powershell
cmake --preset x64-windows-debug -DBUILD_WEBGPU=ON -DBUILD_TESTING=ON
```

If the local preset name differs, use one of the existing Windows presets and add
`-DBUILD_WEBGPU=ON -DBUILD_TESTING=ON`.

Expected configure results:

- vcpkg enables the `webgpu` feature.
- `find_package(dawn CONFIG REQUIRED)` succeeds.
- CMake generates `TrinityAL_webgpu`, `trinity_webgpu`, and
  `TrinityALTest_webgpu`.

## Build

Build the WebGPU targets first:

```powershell
cmake --build .cmake-build-x64-windows-debug --target TrinityAL_webgpu
cmake --build .cmake-build-x64-windows-debug --target trinity_webgpu
cmake --build .cmake-build-x64-windows-debug --target TrinityALTest_webgpu
```

Expected build results:

- Dawn runtime DLLs are copied beside `TrinityALTest_webgpu`.
- The WebGPU targets compile with `TRINITY_PLATFORM=TRINITY_WEBGPU`.
- Current behavior matches the TrinityAL stub backend while the Dawn resource
  implementation is filled in.

## Smoke Test

Run the test executable:

```powershell
ctest --test-dir .cmake-build-x64-windows-debug -R TrinityALTest_webgpu --output-on-failure
```

If the preset writes to a different build directory, run the generated
`TrinityALTest_webgpu.exe` directly from the target output folder.

Expected smoke-test results:

- Process starts and reports `webgpu` as the platform name in screenshot paths
  and platform-specific output.
- Context/resource lifecycle tests pass at stub parity.
- No Dawn package or runtime DLL loading errors occur.

## Dawn Bring-Up Acceptance

After replacing the scaffolded context with real Dawn ownership, extend the
smoke test so it:

1. Creates a Dawn instance, adapter, device, and queue.
2. Creates a native Win32 surface from `Tr2WindowHandle`.
3. Clears and presents one frame.
4. Creates a shader module from
   `trinityal/tests/Shaders.webgpu/MinimalTriangle.wgsl`.
5. Draws a triangle and exits cleanly.

The browser/WASM test plan should be written separately after this native Dawn
path is stable.
