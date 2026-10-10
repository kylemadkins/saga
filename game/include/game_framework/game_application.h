#pragma once

#include "framework/application.h"
#include "ship/ship.h"

#include <memory>

namespace saga {
class GameApplication : public Application {
public:
  GameApplication();
  void tick(float delta_time_s);

private:
  std::weak_ptr<Ship> m_player;
  float timer;
};
} // namespace saga
