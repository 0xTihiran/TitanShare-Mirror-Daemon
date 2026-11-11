#pragma once
#include <string_view>

namespace titan::protocol {
// Starter protocol marker only. Replace with versioned, length-prefixed,
// authenticated messages before enabling network access.
inline constexpr std::string_view kProtocolVersion = "TITAN/0.1";
}
