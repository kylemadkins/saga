#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "framework/object.h"

#include <SFML/Graphics.hpp>

#include <string>

namespace saga {
class World;
class Actor : public Object {
public:
  Actor(World *owner, const std::string &sprite_path);
  virtual ~Actor();

  void begin_play_internal();
  void tick_internal(float delta_time_s);
  virtual void begin_play();
  virtual void tick(float delta_time_s);
  void render(sf::RenderWindow &window);
  void load_sprite(const std::string &sprite_path);

private:
  World *m_owner;
  bool m_has_begun_play;
  sf::Sprite m_sprite;
  sf::Texture m_texture;
};
} // namespace saga
