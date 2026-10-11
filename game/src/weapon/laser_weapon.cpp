#include "weapon/laser_weapon.h"
#include "framework/actor.h"

namespace saga {
LaserWeapon::LaserWeapon(Actor *owner, float cooldown_time)
    : Weapon{owner}, m_cooldown_clock{}, m_cooldown_time{cooldown_time} {}

bool LaserWeapon::can_fire() const {
  return m_cooldown_clock.getElapsedTime().asSeconds() > m_cooldown_time;
}

void LaserWeapon::fire_impl() { m_cooldown_clock.restart(); }
} // namespace saga
