add_executable(test_map test_map.cpp)
target_link_libraries(test_map
    PRIVATE
        gmock_main
        Map
)