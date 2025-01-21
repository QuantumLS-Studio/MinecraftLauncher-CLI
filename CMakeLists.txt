cmake_minimum_required(VERSION 3.16)

project("MLC" VERSION "0.0.1" LANGUAGES CXX)
set(CXX_STANDARD 17)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_COLOR_MAKEFILE ON)

aux_source_directory(src SRC)
include_directories(include)

add_executable(${PROJECT_NAME} ${SRC})
