#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

namespace saga {
class Application {
public:
  Application();
  virtual ~Application() = default;
  void run();

private:
  sf::RenderWindow m_window;
  float m_target_fps;
  sf::Clock m_tick_clock;
  void tick_internal(float delta_time_s);
  virtual void tick(float delta_time_s);
  void render_internal();
  virtual void render();
};

std::unique_ptr<Application> create_application();
} // namespace saga
