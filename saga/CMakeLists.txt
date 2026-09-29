add_executable(saga src/main.cpp src/framework/application.cpp)

target_include_directories(saga PRIVATE include)

target_link_libraries(
    saga
    PRIVATE SFML::Graphics SFML::Window SFML::System SFML::Audio
)
