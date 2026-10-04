add_executable(
    game
    include/game_framework/game_application.h
    src/game_framework/game_application.cpp
)

target_include_directories(game PRIVATE include)

target_link_libraries(game PRIVATE engine)
