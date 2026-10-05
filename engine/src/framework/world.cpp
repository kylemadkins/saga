#include "framework/world.h"
#include "framework/actor.h"

namespace saga {
World::World(Application *owner)
    : m_owner{owner}, m_has_begun_play{false}, m_actors{}, m_pending_actors{} {}

void World::begin_play_internal() {
  if (!m_has_begun_play) {
    m_has_begun_play = true;
    begin_play();
  }
}

void World::tick_internal(float delta_time_s) {
  tick(delta_time_s);

  for (const auto &pending_actor : m_pending_actors) {
    m_actors.push_back(pending_actor);
    pending_actor->begin_play_internal();
  }
  m_pending_actors.clear();

  for (const auto &actor : m_actors) {
    actor->tick_internal(delta_time_s);
  }
}

void World::begin_play() {}

void World::tick(float delta_time_s) {}
} // namespace saga
