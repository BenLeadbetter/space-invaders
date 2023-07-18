#pragma once

#include <game/FixedSizeVec.h>
#include <game/Metrics.h>

#include <optional>
#include <vector>

namespace space_invaders::game {

namespace raster {
struct Pixel {};
using Row = FixedSizeVec<std::optional<raster::Pixel>>;
using Base = FixedSizeVec<Row>;
}  // namespace raster

class Raster : public raster::Base {
 public:
  using raster::Base::Base;

  static Raster make(std::size_t rows, std::size_t cols);
  size_type cols() const;
  size_type rows() const;
  Vec span() const { return {cols(), rows()}; }
};

}  // namespace space_invaders::game
