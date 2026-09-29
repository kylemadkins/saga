#pragma once

#include <SFML/Graphics.hpp>

namespace saga {
class Application {
public:
  Application();
  void run();

private:
  sf::RenderWindow m_window;
};
} // namespace saga
