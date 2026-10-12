#include "weapon/projectile.h"
#include "framework/actor.h"
#include "framework/core.h"

#include <cmath>

namespace saga {
Projectile::Projectile(World *world, Actor *owner,
                       const std::string &texture_path, float speed,
                       float damage)
    : Actor{world}, m_owner{owner}, m_speed{speed}, m_damage{damage} {
  load_sprite(texture_path);
}

void Projectile::set_speed(float speed) { m_speed = speed; }

void Projectile::set_damage(float damage) { m_damage = damage; }

void Projectile::tick(float delta_time_s) {
  SAGA_LOG("projectile :: tick\n");

  Actor::tick(delta_time_s);
  move(delta_time_s);

  if (is_out_of_bounds()) {
    destroy();
  }
}

void Projectile::move(float delta_time_s) {
  sf::Angle rotation_angle = sf::degrees(m_owner->get_rotation());
  sf::Vector2f forward{std::sin(rotation_angle.asRadians()),
                       -std::cos(rotation_angle.asRadians())};
  translate(forward * m_speed * delta_time_s);
}
} // namespace saga
