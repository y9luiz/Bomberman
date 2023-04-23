add_library(Map
    STATIC
        api/map.hpp
        api/map_reader.hpp
        api/map_writer.hpp
        src/map.cpp
        src/map_reader.cpp
        src/map_writer.cpp

)

target_include_directories(Map
    PUBLIC
        api/    
)

target_link_libraries(Map
    PUBLIC
        nlohmann_json::nlohmann_json
)

add_subdirectory(tests)