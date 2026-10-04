#include "framework/application.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <iostream>

namespace saga {
Application::Application()
    : m_window{sf::VideoMode{{800, 600}}, "Saga"}, m_target_fps{60.0f},
      m_tick_clock{} {}

void Application::run() {
  m_tick_clock.restart();
  float accumulated_time_s{0.f};
  float target_delta_time_s{1.f / m_target_fps};

  while (m_window.isOpen()) {
    while (const std::optional event = m_window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        m_window.close();
      }
    }

    accumulated_time_s += m_tick_clock.restart().asSeconds();
    while (accumulated_time_s >= target_delta_time_s) {
      accumulated_time_s -= target_delta_time_s;
      tick_internal(target_delta_time_s);
    }

    render_internal();
  }
}

void Application::tick_internal(float delta_time_s) { tick(delta_time_s); }

void Application::tick(float delta_time_s) { std::cout << "tick\n"; }

void Application::render_internal() {
  m_window.clear(sf::Color::Black);
  render();
  m_window.display();
}

void Application::render() {
  sf::RectangleShape rect{sf::Vector2f{100.f, 100.f}};
  rect.setOrigin(sf::Vector2f{50.f, 50.f});
  rect.setPosition(
      sf::Vector2f{m_window.getSize().x / 2.f, m_window.getSize().y / 2.f});
  rect.setFillColor(sf::Color::Red);
  m_window.draw(rect);
}
} // namespace saga
