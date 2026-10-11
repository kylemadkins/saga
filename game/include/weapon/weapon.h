#pragma once

#include "framework/actor.h"

namespace saga {
class Weapon {
public:
  Actor *get_owner() const;
  void fire();
  virtual bool can_fire() const;
  virtual bool is_on_cooldown() const;

protected:
  Weapon(Actor *owner);

private:
  Actor *m_owner;

  virtual void fire_impl() = 0;
};
} // namespace saga
