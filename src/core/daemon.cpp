#include "core/daemon.hpp"
#include "core/logger.hpp"
#include "network/tcp_server.hpp"

namespace titan {
int Daemon::run() {
    log(LogLevel::info, "Daemon core initialized");
    log(LogLevel::warning,
        "Starter mode: TCP binds to loopback only; LAN pairing/TLS are not implemented");
    TcpServer server(47650);
    return server.run();
}
}
