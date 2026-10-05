#pragma once

namespace saga {
class World;
class Actor {
public:
  Actor(World *owner);
  virtual ~Actor() = default;

  void begin_play_internal();
  void tick_internal(float delta_time_s);
  virtual void begin_play();
  virtual void tick(float delta_time_s);

private:
  World *m_owner;
  bool m_has_begun_play;
};
} // namespace saga
