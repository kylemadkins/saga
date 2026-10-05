#pragma once

namespace saga {
class Object {
public:
  Object();
  virtual ~Object();

  void destroy();
  bool is_pending_destroy() const;

private:
  bool m_is_pending_destroy;
};
} // namespace saga
