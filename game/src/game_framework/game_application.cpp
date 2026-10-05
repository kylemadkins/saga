#include "game_framework/game_application.h"
#include "framework/application.h"
#include "framework/world.h"

#include <memory>

namespace saga {
GameApplication::GameApplication() { load_world<World>(); }

std::unique_ptr<Application> create_application() {
  return std::make_unique<GameApplication>();
}
} // namespace saga
