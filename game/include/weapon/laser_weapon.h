#include "framework/actor.h"
#include "weapon/weapon.h"

#include <SFML/Graphics.hpp>

namespace saga {
class LaserWeapon : public Weapon {
public:
  LaserWeapon(Actor *owner, float cooldown_time);
  bool is_on_cooldown() const override;

private:
  sf::Clock m_cooldown_clock;
  float m_cooldown_time;
  bool has_fired = false;

  void fire_impl() override;
};
} // namespace saga
