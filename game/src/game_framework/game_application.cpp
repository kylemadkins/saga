#include "game_framework/game_application.h"
#include "framework/actor.h"
#include "framework/application.h"
#include "framework/world.h"

#include <memory>

namespace saga {
GameApplication::GameApplication() {
  std::weak_ptr<World> world = load_world<World>();
  if (auto lworld = world.lock()) {
    lworld->spawn_actor<Actor>();
  }
}

std::unique_ptr<Application> create_application() {
  return std::make_unique<GameApplication>();
}
} // namespace saga
