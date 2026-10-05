add_library(
    engine
    STATIC
    include/framework/application.h
    src/framework/application.cpp
    include/framework/core.h
    src/framework/core.cpp
    include/framework/world.h
    src/framework/world.cpp
    src/entry_point.cpp
)

target_include_directories(engine PUBLIC include)

target_link_libraries(
    engine
    PUBLIC SFML::Graphics SFML::Window SFML::System SFML::Audio
)
