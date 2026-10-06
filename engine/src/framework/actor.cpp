#include "framework/actor.h"
#include "framework/core.h"

namespace saga {
Actor::Actor(World *owner) : m_owner{owner}, m_has_begun_play{false} {}

Actor::~Actor() { SAGA_LOG("actor :: actor destroyed\n"); }

void Actor::begin_play_internal() {
  if (!m_has_begun_play) {
    m_has_begun_play = true;
    begin_play();
  }
}

void Actor::tick_internal(float delta_time_s) { tick(delta_time_s); }

void Actor::begin_play() {}

void Actor::tick(float delta_time_s) { SAGA_LOG("actor :: tick\n"); }
} // namespace saga
