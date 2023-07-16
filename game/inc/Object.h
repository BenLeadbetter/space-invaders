#pragma once

#include <vector>

#include "Rect.h"

namespace space_invaders::game {

struct Object {
  std::optional<std::reference_wrapper<Object>> parent;
  std::vector<std::reference_wrapper<Object>> children;
  Rect rect;
};

}  // namespace space_invaders::game
