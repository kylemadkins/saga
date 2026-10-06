add_executable(
    game
    include/game_framework/game_application.h
    src/game_framework/game_application.cpp
)

target_include_directories(game PRIVATE include)

target_link_libraries(game PRIVATE engine)

add_custom_command(
    TARGET game
    POST_BUILD
    COMMAND
        ${CMAKE_COMMAND} -E copy_directory "${CMAKE_CURRENT_SOURCE_DIR}/assets"
        "$<TARGET_FILE_DIR:game>/assets"
)
