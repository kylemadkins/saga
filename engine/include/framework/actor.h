#pragma once

#include "SFML/Graphics/RenderWindow.hpp"
#include "framework/object.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

namespace saga {
class World;
class Actor : public Object {
public:
  Actor(World *owner, const std::string &path);
  virtual ~Actor();

  void begin_play_internal();
  void tick_internal(float delta_time_s);
  virtual void begin_play();
  virtual void tick(float delta_time_s);
  void render(sf::RenderWindow &window);
  sf::Vector2f get_position();
  void set_position(const sf::Vector2f &pos);
  float get_rotation();
  void set_rotation(float rot);

private:
  World *m_owner;
  bool m_has_begun_play;
  std::shared_ptr<sf::Texture> m_texture;
  sf::Sprite m_sprite;

  void center_pivot();
};
} // namespace saga
