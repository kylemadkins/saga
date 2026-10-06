#include "game_framework/game_application.h"
#include "framework/actor.h"
#include "framework/application.h"
#include "framework/world.h"

#include <memory>

namespace saga {
GameApplication::GameApplication() : timer{0.f} {
  std::weak_ptr<World> world = load_world<World>();
  std::weak_ptr<Actor> actor;
  if (auto lworld = world.lock()) {
    m_player = lworld->spawn_actor<Actor>();
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
