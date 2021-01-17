project(BomberMan)

add_library(char char.cpp char.hpp)
target_include_directories(char PUBLIC ${CMAKE_SOURCE_DIR})