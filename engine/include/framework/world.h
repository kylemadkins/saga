#pragma once

namespace saga {
class Application;
class World {
public:
  explicit World(Application *owner);
  virtual ~World() = default;

  void begin_play_internal();
  void tick_internal(float delta_time_s);
  virtual void begin_play();
  virtual void tick(float delta_time_s);

private:
  Application *m_owner;
  bool m_has_begun_play{false};
};
} // namespace saga
