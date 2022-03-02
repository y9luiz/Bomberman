project(BomberMan)

add_library(renderer renderer_window.cpp)
target_include_directories(renderer PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${CMAKE_SOURCE_DIR} ${SDL2_INCLUDE_DIR})