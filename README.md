# TitanShare & Mirror Daemon

Native C++20 daemon starter project for connecting an Android companion app to an Arch Linux desktop.

## Current status

This ZIP is a **starter scaffold**. It includes a buildable daemon foundation, module interfaces/stubs, a basic TCP listener, a line-oriented JSON-free text protocol placeholder, a systemd unit template, and Android project planning files. The nine product features are not yet fully implemented.

## Requirements (Arch Linux)

```bash
sudo pacman -S --needed base-devel cmake git
```

Optional packages needed as corresponding modules are implemented:

```bash
sudo pacman -S --needed avahi pipewire wireplumber \
  gstreamer gst-plugins-base gst-plugins-good \
  qt6-base
```

## Build

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j"$(nproc)"
```

Run in the foreground during development:

```bash
./build/titanshare-daemon
```

The initial TCP listener binds to `127.0.0.1:47650` by default. This is intentionally loopback-only until authentication, TLS, pairing and firewall behavior are implemented. Do not expose it to a LAN or the internet yet.

## Project modules

- `core/`: daemon lifecycle and logging
- `network/`: TCP listener and protocol framing
- `discovery/`: mDNS/Avahi integration placeholder
- `security/`: pairing and trust placeholder
- `file_sharing/`: bidirectional transfer placeholder
- `volume/`: PipeWire integration placeholder
- `power/`: systemd/logind integration placeholder
- `lock_unlock/`: screen lock and authorization placeholder
- `remote_input/`: uinput integration placeholder
- `system_monitor/`: `/proc` and `/sys` monitoring placeholder
- `notification/`: D-Bus notification placeholder
- `screen_mirror/`: GStreamer and length-prefixed JPEG/TCP placeholder
- `android-client/`: Android app implementation plan and protocol notes

## Security notes

1. Do not run the daemon as root.
2. Do not implement remote unlock by bypassing PAM or the active screen locker.
3. Android biometric authentication only proves local user presence to the Android app. The Linux daemon must verify a cryptographically authenticated authorization request.
4. Before LAN use, implement TLS, authenticated pairing, PIN rate limits/expiry, replay protection, per-command authorization and secure file path handling.
5. Power and virtual input operations should use narrowly scoped authorization, not unrestricted shell commands.

## Suggested implementation order

1. Daemon lifecycle and configuration
2. TCP protocol, TLS and authenticated pairing
3. mDNS discovery
4. File sharing
5. Volume and power control
6. System monitoring
7. Remote input
8. Notification sync
9. Screen mirroring
10. Android UI, integration tests and packaging

See `docs/ROADMAP.md` for the 16-week plan.
