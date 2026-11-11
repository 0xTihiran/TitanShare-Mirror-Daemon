#include "core/daemon.hpp"
#include "core/logger.hpp"

int main() {
    titan::log(titan::LogLevel::info, "Starting TitanShare & Mirror Daemon");
    titan::Daemon daemon;
    return daemon.run();
}
