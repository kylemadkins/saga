#include "framework/physics.h"

namespace saga {
void Physics::check_overlaps(
    const std::vector<std::shared_ptr<Actor>> &actors) {
  // AABB collision detection
  for (auto it_a = actors.begin(); it_a != actors.end(); ++it_a) {
    auto it_b = it_a;
    ++it_b;
    for (; it_b != actors.end(); ++it_b) {
      if (*it_a && *it_b && *it_a != *it_b &&
          it_a->get()->get_bounds().findIntersection(
              it_b->get()->get_bounds())) {
        it_a->get()->on_overlap(it_b->get());
        it_b->get()->on_overlap(it_a->get());
      }
    }
  }
}
} // namespace saga
