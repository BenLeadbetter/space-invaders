#include <game/Rect.h>

namespace space_invaders::game {

bool Rect::intersects(const Rect& other) const {
  const bool left = offset.x() + span.x() < other.offset.x();
  const bool right = offset.x() > other.offset.x() + other.span.x();
  const bool above = offset.y() + span.y() < other.offset.y();
  const bool below = offset.y() > other.offset.y() + other.span.y();
  return !(left || right || above || below);
}

Vec Rect::bottomLeft() const { return offset + Vec(0, span(1)); }

Vec Rect::bottomRight() const { return offset + span; }

Vec Rect::topLeft() const { return offset; }

Vec Rect::topRight() const { return offset + Vec(span(0), 0); }

}  // namespace space_invaders::game
