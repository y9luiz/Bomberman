cmake_minimum_required(VERSION 3.0.0)
project(BomberMan)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/cmake)
set (CMAKE_CXX_STANDARD 14)

find_package(SDL2 REQUIRED)
find_package(SDL2_image REQUIRED)

add_subdirectory(Renderer)
add_subdirectory(Scenario)
add_subdirectory(Char)

add_executable(play main.cpp)
target_link_libraries(play  PUBLIC SDL2::SDL2 SDL2::SDL2main ${SDL2IMAGE_LIBRARY}  renderer scenario char)
target_include_directories(play PUBLIC ${CMAKE_SOURCE_DIR})