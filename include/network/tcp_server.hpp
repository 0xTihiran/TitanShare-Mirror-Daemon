#pragma once
#include <cstdint>

namespace titan {
class TcpServer {
public:
    explicit TcpServer(std::uint16_t port);
    int run();
private:
    std::uint16_t port_;
};
}
