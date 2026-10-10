#include "player/player_ship.h"
#include "framework/world.h"

#include <SFML/Graphics.hpp>

namespace saga {
PlayerShip::PlayerShip(World *owner) : Ship{owner}, m_input{} {
  Actor::load_sprite(
      "kenney_space-shooter-remastered/PNG/playerShip1_blue.png");
}

void PlayerShip::tick(float delta_time_s) {
  Ship::tick(delta_time_s);
  handle_input();
  set_velocity({m_input.x * m_speed, m_input.y * m_speed});
}

void PlayerShip::handle_input() {
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W)) {
    m_input.y = -1.f;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S)) {
    m_input.y = 1.f;
  } else {
    m_input.y = 0.f;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A)) {
    m_input.x = -1.f;
  } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D)) {
    m_input.x = 1.f;
  } else {
    m_input.x = 0.f;
  }
  if (m_input != sf::Vector2f{0.f, 0.f}) {
    m_input = m_input.normalized();
  }
}
} // namespace saga
