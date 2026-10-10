#include "framework/world.h"
#include "framework/actor.h"
#include "framework/application.h"

#include <SFML/Graphics.hpp>

namespace saga {
World::World(Application *owner)
    : m_owner{owner}, m_has_begun_play{false}, m_actors{}, m_pending_actors{} {}

sf::Vector2u World::get_window_size() const {
  return m_owner->get_window_size();
}

void World::begin_play_internal() {
  if (!m_has_begun_play) {
    m_has_begun_play = true;
    begin_play();
  }
}

void World::tick_internal(float delta_time_s) {
  tick(delta_time_s);

  // move and clear pending actors
  for (const auto &pending_actor : m_pending_actors) {
    m_actors.push_back(pending_actor);
    pending_actor->begin_play_internal();
  }
  m_pending_actors.clear();

  // update and destroy actors
  for (auto it = m_actors.begin(); it != m_actors.end();) {
    if (it->get()->is_pending_destroy()) {
      it = m_actors.erase(it);
    } else {
      it->get()->tick_internal(delta_time_s);
      ++it;
    }
  }
}

void World::begin_play() {}

void World::tick(float delta_time_s) {}

void World::render(sf::RenderWindow &window) {
  for (const auto &actor : m_actors) {
    actor->render(window);
  }
}
} // namespace saga
