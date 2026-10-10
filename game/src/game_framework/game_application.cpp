#include "game_framework/game_application.h"
#include "config.h"
#include "framework/application.h"
#include "framework/world.h"
#include "ship/ship.h"

#include <memory>

namespace saga {
GameApplication::GameApplication()
    : Application{1920, 1080, "Saga", sf::Style::Titlebar | sf::Style::Close},
      timer{0.f} {
  std::weak_ptr<World> world = load_world<World>();
  if (auto lworld = world.lock()) {
    m_player = lworld->spawn_actor<Ship>(
        get_resource_directory() +
        "kenney_space-shooter-remastered/PNG/playerShip1_blue.png");
    m_player.lock()->set_position(sf::Vector2f{1920 / 2.f, 1080 / 2.f});
    m_player.lock()->set_rotation(45.f);
    m_player.lock()->set_velocity(sf::Vector2f{200.f, -200.f});
  }
}

void GameApplication::tick(float delta_time_s) {
  timer += delta_time_s;
  if (timer >= 2.f) {
    if (auto lplayer = m_player.lock()) {
      lplayer->destroy();
    }
  }
}

std::unique_ptr<Application> create_application() {
  return std::make_unique<GameApplication>();
}
} // namespace saga
