#include "game_framework/game_application.h"
#include "framework/actor.h"
#include "framework/application.h"
#include "framework/core.h"
#include "framework/world.h"

#include <memory>
#include <random>

namespace saga {
GameApplication::GameApplication() {
  std::weak_ptr<World> world = load_world<World>();
  std::weak_ptr<Actor> actor;
  if (auto lworld = world.lock()) {
    m_player = lworld->spawn_actor<Actor>();
  }
}

std::unique_ptr<Application> create_application() {
  return std::make_unique<GameApplication>();
}

void GameApplication::tick(float delta_time_s) {
  std::random_device rd;

  std::mt19937 gen(rd());

  std::uniform_int_distribution<> distr(1, 100);

  int random_num = distr(gen);

  if (random_num == 100) {
    if (auto lplayer = m_player.lock()) {
      SAGA_LOG("jackpot. destroying player\n");
      lplayer->destroy();
    }
  }
}
} // namespace saga
