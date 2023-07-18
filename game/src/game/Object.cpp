#include <game/Object.h>

namespace space_invaders::game {

Rect Object::rect() const {
  return {
      .offset = offset,
      .span = raster.span(),
  };
}

Vec Object::span() const { return raster.span(); }

}  // namespace space_invaders::game
