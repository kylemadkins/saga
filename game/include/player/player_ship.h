#pragma once

#include "framework/world.h"
#include "ship/ship.h"

#include <SFML/Graphics.hpp>

namespace saga {
class PlayerShip : public Ship {
public:
  PlayerShip(World *owner);
  void tick(float delta_time_s) override;

private:
  sf::Vector2f m_input;
  float m_speed = 500.f;

  void handle_input();
};
} // namespace saga
