#include "framework/actor.h"
#include "framework/core.h"

#include <SFML/Graphics.hpp>

#include <string>
#include <tuple>

namespace saga {
Actor::Actor(World *owner, const std::string &sprite_path)
    : m_owner{owner}, m_sprite{m_texture}, m_texture{},
      m_has_begun_play{false} {
  load_sprite(sprite_path);
}

Actor::~Actor() { SAGA_LOG("actor :: actor destroyed\n"); }

void Actor::begin_play_internal() {
  if (!m_has_begun_play) {
    m_has_begun_play = true;
    begin_play();
  }
}

void Actor::tick_internal(float delta_time_s) {
  if (is_pending_destroy())
    return;
  tick(delta_time_s);
}

void Actor::begin_play() {}

void Actor::tick(float delta_time_s) { SAGA_LOG("actor :: tick\n"); }

void Actor::render(sf::RenderWindow &window) {
  if (is_pending_destroy())
    return;
  window.draw(m_sprite);
}

void Actor::load_sprite(const std::string &sprite_path) {
  std::ignore = m_texture.loadFromFile(sprite_path);
  m_sprite.setTexture(m_texture);
  int texture_width = m_texture.getSize().x;
  int texture_height = m_texture.getSize().y;
  m_sprite.setTextureRect(
      sf::IntRect{sf::Vector2i{}, sf::Vector2i{texture_width, texture_height}});
}
} // namespace saga
