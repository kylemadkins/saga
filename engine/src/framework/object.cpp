#include "framework/object.h"
#include "framework/core.h"

namespace saga {
Object::Object() : m_is_pending_destroy{false} {}

Object::~Object() { SAGA_LOG("object :: object destroyed\n"); }

void Object::destroy() { m_is_pending_destroy = true; }

bool Object::is_pending_destroy() const { return m_is_pending_destroy; }
} // namespace saga
