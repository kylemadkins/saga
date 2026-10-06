#include "framework/application.h"
#include "framework/core.h"
#include "framework/world.h"

#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>

#include <cstdint>
#include <memory>

namespace saga {
Application::Application()
    : m_window{sf::VideoMode{{800, 600}}, "Saga Engine",
               sf::Style::Titlebar | sf::Style::Close},
      m_target_fps{60.f}, m_tick_clock{}, m_current_world{nullptr} {
  m_window.setVerticalSyncEnabled(true);
}

Application::Application(unsigned int window_width, unsigned int window_height,
                         const std::string &window_title,
                         std::uint32_t window_style)
    : m_window{sf::VideoMode{{window_width, window_height}}, window_title,
               window_style},
      m_target_fps{60.f}, m_tick_clock{}, m_current_world{nullptr} {
  m_window.setVerticalSyncEnabled(true);
}

void Application::run() {
  m_tick_clock.restart();
  float accumulated_time_s{0.f};
  float target_delta_time_s{1.f / m_target_fps};

  sf::Clock stats_clock;
  int frames{0};
  int ticks{0};

  while (m_window.isOpen()) {
    while (const std::optional event = m_window.pollEvent()) {
      if (event->is<sf::Event::Closed>()) {
        m_window.close();
      }
    }

    // advance the simulation in fixed steps of target_delta_time_s
    // for consistent results on fast and slow machines
    // at 600 fps, renders every frame but only ~1/10 frames runs a tick
    // at 30 fps, each frame runs two ticks before rendering
    float delta_time_s = m_tick_clock.restart().asSeconds();
    accumulated_time_s += delta_time_s;
    while (accumulated_time_s >= target_delta_time_s) {
      accumulated_time_s -= target_delta_time_s;
      tick_internal(target_delta_time_s);
      ticks++;
    }

    render_internal();
    frames++;

    if (stats_clock.getElapsedTime().asSeconds() >= 1.f) {
      // log fps compared to ticks
      SAGA_LOG("application :: %d frames, %d ticks in the last second\n",
               frames, ticks);
      frames = 0;
      ticks = 0;
      stats_clock.restart();
    }
  }
}

void Application::tick_internal(float delta_time_s) {
  tick(delta_time_s);

  if (m_current_world) {
    m_current_world->begin_play_internal();
    m_current_world->tick_internal(delta_time_s);
  }
}

void Application::tick(float delta_time_s) {}

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
