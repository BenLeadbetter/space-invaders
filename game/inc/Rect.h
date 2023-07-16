#pragma once

#include <Eigen/Geometry>

namespace space_invaders::game {

struct Rect {
  Eigen::Affine2d transform;
  Eigen::Vector2<double> span;
};

}  // namespace space_invaders::game
