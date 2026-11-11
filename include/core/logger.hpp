#pragma once
#include <string_view>

namespace titan {
enum class LogLevel { info, warning, error };
void log(LogLevel level, std::string_view message);
}
