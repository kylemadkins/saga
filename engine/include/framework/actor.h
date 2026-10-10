#pragma once

#include "framework/object.h"

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>

namespace saga {
class World;
class Actor : public Object {
public:
  Actor(World *owner);
  virtual ~Actor();

  void load_sprite(const std::string &texture_path);
  void begin_play_internal();
  void tick_internal(float delta_time_s);
  virtual void begin_play();
  virtual void tick(float delta_time_s);
  void render(sf::RenderWindow &window);
  sf::Vector2f get_position() const;
  void set_position(const sf::Vector2f &pos);
  float get_rotation() const;
  void set_rotation(float rot);
  void translate(const sf::Vector2f &amount);
  void rotate(float amount);
  sf::Vector2u get_window_size() const;
  sf::Vector2f get_size() const;

private:
  World *m_owner;
  bool m_has_begun_play;
  std::shared_ptr<sf::Texture> m_texture;
  std::optional<sf::Sprite> m_sprite;

  void center_pivot();
};
} // namespace saga
