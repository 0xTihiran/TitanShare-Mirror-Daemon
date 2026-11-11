#include "core/logger.hpp"
#include <iostream>

namespace titan {
void log(LogLevel level, std::string_view message) {
    const char* label = "INFO";
    if (level == LogLevel::warning) label = "WARN";
    if (level == LogLevel::error) label = "ERROR";
    std::clog << "[TitanShare][" << label << "] " << message << '\n';
}
}
