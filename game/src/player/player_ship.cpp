#include "player/player_ship.h"
#include "framework/world.h"

namespace saga {
PlayerShip::PlayerShip(World *owner) : Ship{owner} {
  Actor::load_sprite(
      "kenney_space-shooter-remastered/PNG/playerShip1_blue.png");
}
} // namespace saga
