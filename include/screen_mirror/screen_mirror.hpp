#pragma once
namespace titan {
class ScreenMirror {
public:
    // TODO: Build a GStreamer capture/encode pipeline and length-prefixed JPEG/TCP transport.
    bool initialize();
};
}
