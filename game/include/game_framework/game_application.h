#pragma once

#include "framework/actor.h"
#include "framework/application.h"

#include <memory>

namespace saga {
class GameApplication : public Application {
public:
  GameApplication();
  void tick(float delta_time_s);

private:
  std::weak_ptr<Actor> m_player;
  float timer;
};
} // namespace saga
