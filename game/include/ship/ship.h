#pragma once

#include "framework/actor.h"
#include "framework/world.h"

#include <SFML/Graphics.hpp>

#include <string>

namespace saga {
class Ship : public Actor {
public:
  Ship(World *owner, const std::string &texture_path);
  virtual void tick(float delta_time_s) override;
  sf::Vector2f get_velocity() const;
  void set_velocity(sf::Vector2f vel);

private:
  sf::Vector2f m_velocity;
};
} // namespace saga
