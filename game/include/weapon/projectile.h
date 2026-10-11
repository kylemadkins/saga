#pragma once

#include "framework/actor.h"
#include "framework/world.h"

#include <string>

namespace saga {
class Projectile : public Actor {
public:
  Projectile(World *world, Actor *owner, const std::string &texture_path,
             float speed, float damage);
  void set_speed(float speed);
  void set_damage(float damage);

private:
  Actor *m_owner;
  float m_speed;
  float m_damage;
};
} // namespace saga
