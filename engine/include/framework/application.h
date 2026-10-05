#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <memory>

namespace saga {
class World;
class Application {
public:
  Application();
  virtual ~Application() = default;

  void run();
  virtual void tick(float delta_time_s);
  virtual void render();
  template <typename WorldType> std::weak_ptr<WorldType> load_world();

private:
  sf::RenderWindow m_window;
  float m_target_fps;
  sf::Clock m_tick_clock;
  std::shared_ptr<World> m_current_world;

  void tick_internal(float delta_time_s);
  void render_internal();
};

template <typename WorldType>
std::weak_ptr<WorldType> Application::load_world() {
  auto new_world = std::make_shared<WorldType>(this);
  m_current_world = new_world;
  return m_current_world;
}

std::unique_ptr<Application> create_application();
} // namespace saga
