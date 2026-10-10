#pragma once

#include "framework/application.h"
#include "player/player_ship.h"

#include <memory>

namespace saga {
class GameApplication : public Application {
public:
  GameApplication();
  void tick(float delta_time_s);

private:
  std::weak_ptr<PlayerShip> m_player;
  float timer;
};
} // namespace saga
