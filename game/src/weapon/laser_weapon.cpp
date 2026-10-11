#include "weapon/laser_weapon.h"
#include "framework/actor.h"
#include "framework/world.h"
#include "weapon/projectile.h"

namespace saga {
LaserWeapon::LaserWeapon(Actor *owner, float cooldown_time)
    : Weapon{owner}, m_cooldown_clock{}, m_cooldown_time{cooldown_time} {}

bool LaserWeapon::is_on_cooldown() const {
  return has_fired &&
         m_cooldown_clock.getElapsedTime().asSeconds() <= m_cooldown_time;
}

void LaserWeapon::fire_impl() {
  if (!has_fired)
    has_fired = true;

  std::weak_ptr<Projectile> projectile =
      get_owner()->get_world()->spawn_actor<Projectile>(
          get_owner(),
          "kenney_space-shooter-remastered/PNG/Lasers/laserBlue04.png");
  projectile.lock()->set_position(get_owner()->get_position());
  projectile.lock()->set_rotation(get_owner()->get_rotation());

  m_cooldown_clock.restart();
}
} // namespace saga
