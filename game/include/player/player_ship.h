#pragma once

#include "framework/world.h"
#include "ship/ship.h"
#include "weapon/weapon.h"

#include <SFML/Graphics.hpp>

#include <memory>

namespace saga {
class PlayerShip : public Ship {
public:
  PlayerShip(World *owner);
  void tick(float delta_time_s) override;
  void fire();

private:
  sf::Vector2f m_input;
  float m_speed = 1000.f;
  std::unique_ptr<Weapon> m_weapon;

  void handle_input();
  void handle_movement();
  void clamp_position();
};
} // namespace saga
