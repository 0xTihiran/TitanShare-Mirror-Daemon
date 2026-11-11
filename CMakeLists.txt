cmake_minimum_required(VERSION 3.20)
project(TitanShareMirrorDaemon VERSION 0.1.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(TITANSHARE_BUILD_TESTS "Build tests" OFF)

add_executable(titanshare-daemon
    src/main.cpp
    src/core/daemon.cpp
    src/core/logger.cpp
    src/network/tcp_server.cpp
    src/network/protocol.cpp
    src/discovery/discovery.cpp
    src/security/pairing.cpp
    src/file_sharing/file_sharing.cpp
    src/volume/volume.cpp
    src/power/power.cpp
    src/lock_unlock/lock_unlock.cpp
    src/remote_input/remote_input.cpp
    src/system_monitor/system_monitor.cpp
    src/notification/notification.cpp
    src/screen_mirror/screen_mirror.cpp
)

target_include_directories(titanshare-daemon PRIVATE include)
target_compile_options(titanshare-daemon PRIVATE -Wall -Wextra -Wpedantic)
target_link_libraries(titanshare-daemon PRIVATE pthread)

install(TARGETS titanshare-daemon RUNTIME DESTINATION bin)
