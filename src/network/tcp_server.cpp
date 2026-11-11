#include "network/tcp_server.hpp"
#include "core/logger.hpp"

#include <arpa/inet.h>
#include <cerrno>
#include <cstring>
#include <netinet/in.h>
#include <sys/socket.h>
#include <unistd.h>

namespace titan {
TcpServer::TcpServer(std::uint16_t port) : port_(port) {}

int TcpServer::run() {
    const int fd = ::socket(AF_INET, SOCK_STREAM, 0);
    if (fd < 0) {
        log(LogLevel::error, std::string("socket(): ") + std::strerror(errno));
        return 1;
    }

    int reuse = 1;
    (void)::setsockopt(fd, SOL_SOCKET, SO_REUSEADDR, &reuse, sizeof(reuse));

    sockaddr_in address{};
    address.sin_family = AF_INET;
    address.sin_port = htons(port_);
    // Intentionally loopback-only until security is implemented.
    address.sin_addr.s_addr = htonl(INADDR_LOOPBACK);

    if (::bind(fd, reinterpret_cast<sockaddr*>(&address), sizeof(address)) < 0) {
        log(LogLevel::error, std::string("bind(): ") + std::strerror(errno));
        ::close(fd);
        return 1;
    }
    if (::listen(fd, 8) < 0) {
        log(LogLevel::error, std::string("listen(): ") + std::strerror(errno));
        ::close(fd);
        return 1;
    }

    log(LogLevel::info, "Listening on 127.0.0.1:47650 (development-only)");
    for (;;) {
        sockaddr_in peer{};
        socklen_t peer_len = sizeof(peer);
        const int client = ::accept(fd, reinterpret_cast<sockaddr*>(&peer), &peer_len);
        if (client < 0) {
            if (errno == EINTR) continue;
            log(LogLevel::error, std::string("accept(): ") + std::strerror(errno));
            continue;
        }
        constexpr char response[] =
            "TITAN/0.1 STARTER_ONLY - pairing and TLS not implemented\\n";
        (void)::send(client, response, sizeof(response) - 1, MSG_NOSIGNAL);
        ::close(client);
    }
}
}
