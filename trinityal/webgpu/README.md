WebGPU backend bring-up
=======================

This directory tracks the native Dawn WebGPU backend work.

The initial `TrinityAL_webgpu` target is intentionally conservative: it builds
as a distinct `TRINITY_WEBGPU` platform and links Dawn, but routes the TrinityAL
resource surface through the existing stub implementation. That gives the
engine a real WebGPU build/test target before the backend owns Dawn devices,
surfaces, command encoders, bind groups, pipelines, and WGSL shader modules.

Next implementation steps:

1. Replace stub context routing with a WebGPU render context that creates a
   Dawn instance, adapter, device, and queue.
2. Add native-window surface creation and present handling.
3. Replace buffer, texture, sampler, shader, resource set, and pipeline stubs
   with Dawn-backed implementations.
4. Use `trinityal/tests/Shaders.webgpu/MinimalTriangle.wgsl` for the first
   clear/draw smoke test before integrating Trinity's effect compiler.
