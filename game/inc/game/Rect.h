#pragma once

#include "Metrics.h"

namespace space_invaders::game {

struct Rect {
  Vec offset;
  Vec span;

  bool intersects(const Rect& other) const;

  Vec bottomLeft() const;
  Vec bottomRight() const;
  Vec topLeft() const;
  Vec topRight() const;
};

}  // namespace space_invaders::game
