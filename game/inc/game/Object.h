#pragma once

#include <game/Metrics.h>
#include <game/Raster.h>
#include <game/Rect.h>

#include <vector>

namespace space_invaders::game {

struct Object {
  Rect rect() const;
  Vec span() const;

  Raster raster{};
  Vec offset{};
};

}  // namespace space_invaders::game
