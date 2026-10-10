#include "player/player_ship.h"
#include "framework/world.h"

#include <SFML/Graphics.hpp>

#include <algorithm>

namespace saga {
PlayerShip::PlayerShip(World *owner) : Ship{owner}, m_input{} {
  Actor::load_sprite(
      "kenney_space-shooter-remastered/PNG/playerShip1_blue.png");
}

void PlayerShip::tick(float delta_time_s) {
  Ship::tick(delta_time_s);
  handle_input();
  handle_movement();
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

void PlayerShip::handle_movement() {
  set_velocity({m_input.x * m_speed, m_input.y * m_speed});
  clamp_position();
}

void PlayerShip::clamp_position() {
  sf::Vector2f position = get_position();
  sf::Vector2u window_size = get_window_size();
  sf::Vector2f player_size = get_size();

  float clamped_x =
      std::clamp(position.x, 0.f + player_size.x / 2.f,
                 static_cast<float>(window_size.x) - player_size.x / 2.f);
  float clamped_y =
      std::clamp(position.y, 0.f + player_size.y / 2.f,
                 static_cast<float>(window_size.y) - player_size.y / 2.f);

  set_position({clamped_x, clamped_y});
}
} // namespace saga
