#include "weapon/projectile.h"
#include "framework/actor.h"

namespace saga {
Projectile::Projectile(World *world, Actor *owner,
                       const std::string &texture_path, float speed,
                       float damage)
    : Actor{world}, m_owner{owner}, m_speed{speed}, m_damage{damage} {
  load_sprite(texture_path);
}

void Projectile::set_speed(float speed) { m_speed = speed; }

void Projectile::set_damage(float damage) { m_damage = damage; }
} // namespace saga
