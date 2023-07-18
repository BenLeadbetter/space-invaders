#include <game/Raster.h>

namespace space_invaders::game {
Raster Raster::make(std::size_t rows, std::size_t cols) {
  return Raster(rows, raster::Row(cols, std::nullopt));
}

Raster::size_type Raster::rows() const { return size(); }

Raster::size_type Raster::cols() const { return empty() ? 0 : front().size(); }

}  // namespace space_invaders::game
