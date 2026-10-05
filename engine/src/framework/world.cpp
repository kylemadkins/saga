#include "framework/world.h"
#include "framework/core.h"

namespace saga {
World::World(Application *owner) : m_owner{owner}, m_has_begun_play{false} {}

void World::begin_play_internal() {
  if (!m_has_begun_play) {
    m_has_begun_play = true;
    SAGA_LOG("world :: has begun play\n");
    begin_play();
  }
}

void World::tick_internal(float delta_time_s) { tick(delta_time_s); }

void World::begin_play() {}

void World::tick(float delta_time_s) {}
} // namespace saga
