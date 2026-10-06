#include "framework/actor.h"
#include "framework/asset_manager.h"
#include "framework/core.h"

#include <SFML/Graphics.hpp>

#include <string>

namespace saga {
Actor::Actor(World *owner, const std::string &path)
    : m_owner{owner}, m_has_begun_play{false},
      m_texture{AssetManager::get().load_texture(path)}, m_sprite{*m_texture} {}

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
} // namespace saga
