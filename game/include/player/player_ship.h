#pragma once

#include "framework/world.h"
#include "ship/ship.h"

namespace saga {
class PlayerShip : public Ship {
public:
  PlayerShip(World *owner);
};
} // namespace saga
