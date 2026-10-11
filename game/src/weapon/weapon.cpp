#include "weapon/weapon.h"
#include "framework/actor.h"
#include "framework/core.h"

namespace saga {
Weapon::Weapon(Actor *owner) : m_owner{owner} {}

Actor *Weapon::get_owner() const { return m_owner; }

void Weapon::fire() {
  if (can_fire() && !is_on_cooldown()) {
    SAGA_LOG("weapon :: fire\n");
    fire_impl();
  }
}

bool Weapon::can_fire() const { return true; }

bool Weapon::is_on_cooldown() const { return false; }
} // namespace saga
