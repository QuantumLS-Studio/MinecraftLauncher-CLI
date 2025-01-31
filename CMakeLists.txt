cmake_minimum_required(VERSION 3.16)

project("MLC" VERSION "0.0.1" LANGUAGES CXX)
set(CXX_STANDARD 17)
set(CMAKE_COLOR_MAKEFILE ON)

aux_source_directory(src SRC)
include_directories(include)

add_executable(${PROJECT_NAME} ${SRC})

include(FetchContent)
FetchContent_Declare(
    tomlplusplus
    GIT_REPOSITORY https://github.com/marzer/tomlplusplus.git
    GIT_TAG        v3.4.0
)
FetchContent_Declare(
    json
    GIT_REPOSITORY https://github.com/nlohmann/json.git
    GIT_TAG        v3.11.3
)
FetchContent_Declare(
    barkeep
    GIT_REPOSITORY https://github.com/oir/barkeep.git
    GIT_TAG        v0.1.5
)
FetchContent_Declare(
    args
    GIT_REPOSITORY https://github.com/taywee/args.git
    GIT_TAG        v6.4.6
)
FetchContent_MakeAvailable(tomlplusplus json barkeep args)

target_link_libraries(${PROJECT_NAME} tomlplusplus::tomlplusplus nlomann_json::nlohmann_json barkeep::barkeep args::args)
