#pragma once

#include <cstdio>

namespace saga {
template <typename... Args> inline void log(const char *msg, Args... args) {
  std::printf(msg, args...);
}
} // namespace saga
