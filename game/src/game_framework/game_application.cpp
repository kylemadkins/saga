#include "game_framework/game_application.h"
#include "framework/application.h"

#include <memory>

namespace saga {
GameApplication::GameApplication() {
  // init game-specific systems
}

std::unique_ptr<Application> create_application() {
  return std::make_unique<GameApplication>();
}
} // namespace saga
