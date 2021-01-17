cmake_minimum_required(VERSION 3.0.0)
project(BomberMan)
find_package(SDL2 REQUIRED)
INCLUDE(FindPkgConfig)

PKG_SEARCH_MODULE(SDL2IMAGE REQUIRED SDL2_image>=2.0.0)

include_directories(${SDL2_INCLUDE_DIRS})
set (CMAKE_CXX_STANDARD 11)

add_subdirectory(Renderer)
add_subdirectory(Scenario)
add_subdirectory(Char)

add_executable(play main.cpp)
string(STRIP ${SDL2_LIBRARIES} SDL2_LIBRARIES)

target_link_libraries(play  PUBLIC ${SDL2_LIBRARIES} ${SDL2IMAGE_LIBRARIES} renderer scenario char)
target_include_directories(play PUBLIC ${CMAKE_SOURCE_DIR})