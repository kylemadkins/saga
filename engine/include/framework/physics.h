#pragma once

#include "framework/actor.h"

#include <vector>

namespace saga {
class Physics {
public:
  static void check_overlaps(const std::vector<std::shared_ptr<Actor>> &actors);
};
} // namespace saga
