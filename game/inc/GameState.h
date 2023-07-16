#pragma once

#include <functional>
#include <memory>
#include <optional>
#include <vector>

#include "Metrics.h"

namespace space_invaders::game {

struct Object;

struct GameState {
  Vec dimensions{};
  float enemyAdvanceSpeed{1.0};
  double playerSpeed{5.0};
  std::optional<std::reference_wrapper<Object>> bullet;
  std::optional<std::reference_wrapper<Object>> player;
  std::vector<std::reference_wrapper<Object>> defences;
  std::vector<std::reference_wrapper<Object>> enemies;
  std::vector<std::unique_ptr<Object>> objects;
};

}  // namespace space_invaders::game
