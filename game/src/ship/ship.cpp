#include "ship/ship.h"
#include "framework/world.h"

#include <SFML/Graphics.hpp>

#include <string>

namespace saga {
Ship::Ship(World *owner, const std::string &texture_path)
    : Actor{owner, texture_path} {}

void Ship::tick(float delta_time_s) {
  Actor::tick(delta_time_s);
  translate(m_velocity * delta_time_s);
}

sf::Vector2f Ship::get_velocity() const { return m_velocity; }

void Ship::set_velocity(sf::Vector2f vel) { m_velocity = vel; }
} // namespace saga
