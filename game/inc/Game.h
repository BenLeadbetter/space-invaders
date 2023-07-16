#pragma once

#include <functional>
#include <memory>
#include <optional>
#include <vector>

#include "Input.h"

namespace space_invaders::game {

struct Object;

class Game {
 public:
  Game();

  void tick(std::vector<Input>);

  const Object& player() const { return *m_player; }
  const Object& root() const { return *m_root; }
  const std::optional<std::reference_wrapper<Object>> bullet() const {
    return m_bullet;
  }
  const std::vector<std::reference_wrapper<Object>> defences() const {
    return m_defences;
  }
  const std::vector<std::reference_wrapper<Object>> enemies() const {
    return m_enemies;
  }

 private:
  std::vector<std::unique_ptr<Object>> m_objects;

  float m_enemyAdvanceSpeed{1.0};
  std::optional<std::reference_wrapper<Object>> m_bullet;
  std::optional<std::reference_wrapper<Object>> m_player;
  std::optional<std::reference_wrapper<Object>> m_root;
  std::vector<std::reference_wrapper<Object>> m_defences;
  std::vector<std::reference_wrapper<Object>> m_enemies;
};

}  // namespace space_invaders::game
