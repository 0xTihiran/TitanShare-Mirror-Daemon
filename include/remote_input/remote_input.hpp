#pragma once
namespace titan {
class RemoteInput {
public:
    // TODO: Use uinput with explicit permissions and authenticated input events.
    bool initialize();
};
}
