add_library(GameSession
    STATIC
        api/game_session.hpp
        src/game_session.cpp
)

target_include_directories(GameSession
    PUBLIC
        api/    
)

target_link_libraries(GameSession
    PRIVATE
        Map
)