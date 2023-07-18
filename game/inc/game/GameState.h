#pragma once

#include <functional>
#include <optional>
#include <vector>

#include "Metrics.h"
#include "Object.h"

namespace space_invaders::game {

struct GameState {
  Vec dimensions{};
  float enemyAdvanceSpeed{1.0};
  double bulletSpeed{10.0};
  double playerSpeed{5.0};
  std::optional<Object> bullet;
  std::optional<Object> player;
  std::vector<Object> defences;
  std::vector<Object> enemies;
};

}  // namespace space_invaders::game
