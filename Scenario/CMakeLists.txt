project(BomberMan)

add_library(scenario wall_block.cpp wall_block.hpp ground_block.cpp ground_block.hpp map.cpp map.hpp)
target_include_directories(scenario PUBLIC ${CMAKE_SOURCE_DIR})