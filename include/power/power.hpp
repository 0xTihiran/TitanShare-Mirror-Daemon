#pragma once
namespace titan {
class Power {
public:
    // TODO: Request approved power actions through systemd-logind; never execute arbitrary shell input.
    bool initialize();
};
}
