#pragma once
namespace titan {
class LockUnlock {
public:
    // TODO: Integrate with supported screen lockers and verify authorization; do not bypass PAM.
    bool initialize();
};
}
