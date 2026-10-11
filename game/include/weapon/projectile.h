#pragma once

#include "framework/actor.h"
#include "framework/world.h"

#include <string>

namespace saga {
class Projectile : public Actor {
public:
  Projectile(World *world, Actor *owner, const std::string &texture_path,
             float speed = 600.f, float damage = 10.f);
  void set_speed(float speed);
  void set_damage(float damage);
  void tick(float delta_time_s) override;

private:
  Actor *m_owner;
  float m_speed;
  float m_damage;

  void move(float delta_time_s);
};
} // namespace saga
