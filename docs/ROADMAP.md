# 16-week development roadmap

| Weeks | Work | Exit criteria |
|---|---|---|
| 1-2 | C++20 daemon core, CMake, logging, configuration, systemd packaging | Daemon builds and runs as an unprivileged service |
| 3-4 | TCP protocol, TLS, mDNS/Avahi, rotating PIN pairing, trusted devices | Authenticated Android-to-Linux session |
| 5-6 | Bidirectional file transfer, progress, cancellation, safe paths | Transfers pass functional and large-file tests |
| 7-8 | PipeWire volume, logind power actions, screen lock, biometric-authorized request | Desktop controls work with explicit authorization |
| 9-10 | uinput touchpad/keyboard, CPU/RAM/temperature/storage/battery | Remote input and live metrics work |
| 11-12 | D-Bus notification listener and Android forwarding | Desktop notifications appear on Android |
| 13-14 | GStreamer capture, JPEG encoding, length-prefixed TCP stream, Android renderer | Stable preview with reconnect and performance tests |
| 15-16 | Integration, security review, performance, packaging, docs | Release candidate and demonstration |

## Milestone gates

- Do not enable LAN binding before TLS and pairing are complete.
- Do not implement unlock as a password bypass.
- Do not execute arbitrary shell strings received from the phone.
- Keep screen streaming on a separate worker/pipeline so it cannot starve control messages.
