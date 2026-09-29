#include "framework/application.h"

#include <SFML/Graphics.hpp>
#include <memory>

int main() {
  std::unique_ptr<saga::Application> app =
      std::make_unique<saga::Application>();

  app->run();

  return 0;
}
