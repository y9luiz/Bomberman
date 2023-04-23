cmake_minimum_required(VERSION 3.10.0)
project(Bomberman)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set (CMAKE_CXX_STANDARD 17)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include(dependencies)

add_subdirectory(project)

add_executable(GameLauncher main.cpp)
