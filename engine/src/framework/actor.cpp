#include "framework/actor.h"
#include "framework/asset_manager.h"
#include "framework/core.h"

#include <SFML/Graphics.hpp>

#include <string>

namespace saga {
Actor::Actor(World *owner)
    : m_owner{owner}, m_has_begun_play{false}, m_texture{}, m_sprite{} {}

Actor::~Actor() { SAGA_LOG("actor :: actor destroyed\n"); }

void Actor::load_sprite(const std::string &texture_path) {
  m_texture = AssetManager::get().load_texture(texture_path);
  if (m_texture) {
    m_sprite = sf::Sprite{*m_texture};
    center_pivot();
  }
}

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
  window.draw(*m_sprite);
}

sf::Vector2f Actor::get_position() const { return m_sprite->getPosition(); }

void Actor::set_position(const sf::Vector2f &pos) {
  m_sprite->setPosition(pos);
}

float Actor::get_rotation() const {
  return m_sprite->getRotation().asDegrees();
}

void Actor::set_rotation(float rot) { m_sprite->setRotation(sf::degrees(rot)); }

void Actor::translate(sf::Vector2f amount) {
  set_position(get_position() + amount);
}

void Actor::rotate(float amount) { set_rotation(get_rotation() + amount); }

void Actor::center_pivot() {
  m_sprite->setOrigin(m_sprite->getGlobalBounds().getCenter());
}
} // namespace saga
