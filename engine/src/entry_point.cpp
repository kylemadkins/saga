#include "framework/application.h"

int main() {
  auto app = saga::create_application();

  app->run();

  return 0;
}
