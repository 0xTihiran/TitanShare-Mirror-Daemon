# Android companion app

Planned native Android client (Kotlin + Jetpack Compose).

Suggested packages:
- `discovery/`: NSD/mDNS discovery
- `pairing/`: PIN entry and trusted daemon identity
- `network/`: TLS client, protocol framing, reconnect logic
- `files/`: upload/download UI and progress
- `remote/`: touchpad and keyboard
- `monitor/`: CPU/RAM/temperature/storage/battery dashboard
- `notifications/`: notification display and user-controlled permissions
- `mirror/`: JPEG frame decoder and display surface
- `biometric/`: BiometricPrompt authorization

This folder is a planning scaffold, not a complete Gradle application yet.
Never send biometric templates or fingerprint data to Linux. Android should return a signed/securely bound authorization result, and Linux must validate it.
