#pragma once
namespace titan {
class SystemMonitor {
public:
    // TODO: Read CPU, memory, thermal, storage and battery metrics from procfs/sysfs.
    bool initialize();
};
}
