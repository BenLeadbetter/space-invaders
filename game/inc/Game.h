#pragma once

#include <memory>

#include "Input.h"

namespace space_invaders::game {

struct GameState;

class Game {
 public:
  Game();
  Game(std::unique_ptr<GameState>);
  ~Game();

  void tick(std::vector<Input> = {});
  const GameState& state() const { return *m_state; }

 private:
  std::unique_ptr<GameState> m_state;
};

}  // namespace space_invaders::game
