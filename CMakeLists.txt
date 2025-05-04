cmake_minimum_required(VERSION 4.0)

set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_COMPILER "clang++")

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(MCL LANGUAGES CXX VERSION 1.0.0 DESCRIPTION "A C++ library for launching minecraft" HOMEPAGE_URL "https://github.com/QuantumLS-Studio/MinecraftLauncher-CLI")

include(FetchContent)

# fmt
find_package(fmt QUIET)
if(NOT fmt_FOUND)
    FetchContent_Declare(
        fmt
        GIT_REPOSITORY https://github.com/fmtlib/fmt.git
        GIT_TAG 11.1.4
    )
    FetchContent_MakeAvailable(fmt)
endif()

# spdlog
find_package(spdlog QUIET)
if(NOT spdlog_FOUND)
    FetchContent_Declare(
        spdlog
        GIT_REPOSITORY https://github.com/gabime/spdlog.git
        GIT_TAG v1.15.0
    )
    FetchContent_MakeAvailable(spdlog)
endif()

# nlohmann_json
#find_package(nlohmann_json QUIET)
#if(NOT nlohmann_json_FOUND)
#    FetchContent_Declare(
#        nlohmann_json
#        GIT_REPOSITORY https://github.com/nlohmann/json.git
#        GIT_TAG v3.12
#    )
#    FetchContent_MakeAvailable(nlohmann_json)
#endif()

# tomlplusplus
find_package(tomlplusplus QUIET)
if(NOT tomlplusplus_FOUND)
    FetchContent_Declare(
        tomlplusplus
        GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
        GIT_TAG v3.4.0
    )
    FetchContent_MakeAvailable(tomlplusplus)
endif()

# cpr
find_package(cpr QUIET)
if(NOT cpr_FOUND)
    FetchContent_Declare(
        cpr
        GIT_REPOSITORY https://github.com/libcpr/cpr.git
        GIT_TAG v1.11.0
    )
    FetchContent_MakeAvailable(cpr)
endif()

add_executable(MCL)

file(GLOB SOURCES "src/*.cpp")
target_sources(MCL PRIVATE ${SOURCES})

target_include_directories(MCL PRIVATE src/include)

target_link_libraries(MCL PRIVATE
    fmt::fmt
    spdlog::spdlog
    #nlohmann_json::nlohmann_json
    tomlplusplus::tomlplusplus
    cpr::cpr
)

option(ENABLE_CCACHE "Enable ccache" ON)
if(ENABLE_CCACHE)
    find_program(CCACHE_PROGRAM ccache)
    if(CCACHE_PROGRAM)
        message(STATUS "Using ccache: ${CCACHE_PROGRAM}")
        set_property(GLOBAL PROPERTY CMAKE_CXX_COMPILER_LAUNCHER ${CCACHE_PROGRAM})
    else()
        message(WARNING "ccache not found, disabling ccache")
    endif()
endif()
