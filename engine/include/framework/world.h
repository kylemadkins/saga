#pragma once

#include <SFML/Graphics.hpp>

#include <memory>
#include <string>
#include <vector>

namespace saga {
class Application;
class Actor;
class World {
public:
  explicit World(Application *owner);
  virtual ~World() = default;

  void begin_play_internal();
  void tick_internal(float delta_time_s);
  virtual void begin_play();
  virtual void tick(float delta_time_s);
  void render(sf::RenderWindow &window);
  template <typename ActorType>
  std::weak_ptr<ActorType> spawn_actor(const std::string &texture_path);

private:
  Application *m_owner;
  bool m_has_begun_play;
  std::vector<std::shared_ptr<Actor>> m_actors;
  std::vector<std::shared_ptr<Actor>> m_pending_actors;
};

template <typename ActorType>
std::weak_ptr<ActorType> World::spawn_actor(const std::string &texture_path) {
  auto new_actor = std::make_shared<ActorType>(this, texture_path);
  m_pending_actors.push_back(new_actor);
  return new_actor;
}
} // namespace saga
