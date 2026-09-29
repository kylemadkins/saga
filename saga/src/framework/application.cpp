#include "framework/application.h"

saga::Application::Application()
    : m_window(sf::VideoMode({800, 600}), "Saga") {}

void saga::Application::run() {
  while (m_window.isOpen()) {
    while (const std::optional event = m_window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        m_window.close();
      }
    }

    m_window.clear(sf::Color::Black);
    m_window.display();
  }
}
