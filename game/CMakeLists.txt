add_executable(
    game
    include/game_framework/game_application.h
    src/game_framework/game_application.cpp
    include/ship/ship.h
    src/ship/ship.cpp
    include/player/player_ship.h
    src/player/player_ship.cpp
)

target_include_directories(game PRIVATE include)

target_link_libraries(game PRIVATE engine)

set(RESOURCE_DIR_NAME "assets")
set(RESOURCE_SRC_DIR "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_DIR_NAME}")

add_custom_command(
    TARGET game
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory
        "${CMAKE_CURRENT_SOURCE_DIR}/${RESOURCE_DIR_NAME}"
        "$<TARGET_FILE_DIR:game>/${RESOURCE_DIR_NAME}"
)

configure_file(
    "config.h.in"
    "${CMAKE_CURRENT_SOURCE_DIR}/include/config.h"
    ESCAPE_QUOTES
)
