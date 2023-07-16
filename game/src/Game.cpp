#include "Game.h"

#include <ranges>

#include "GameState.h"
#include "Object.h"

namespace space_invaders::game {

namespace {

void makePlayer(std::optional<std::reference_wrapper<Object>>& playerState,
                std::vector<std::unique_ptr<Object>>& objects,
                const Vec& gameDims) {
  auto player = std::make_unique<Object>();
  const auto dims = Vec(50, 25);
  player->rect = {
      .offset = Vec((gameDims.x() - dims.x()) / 2.0, dims.y()),
      .span = dims,
  };
  playerState = *player;
  objects.push_back(std::move(player));
}

}  // namespace

Game::Game() {
  m_state = std::make_unique<GameState>();
  m_state->dimensions = Vec(300, 400);
  makePlayer(m_state->player, m_state->objects, m_state->dimensions);
}

Game::Game(std::unique_ptr<GameState> state) : m_state(std::move(state)) {}

Game::~Game() = default;

void Game::tick(std::vector<Input> input) {
  if (std::ranges::find(input, Input::Left) != input.cend()) {
    auto& rect = m_state->player->get().rect;
    rect.offset += Vec(-m_state->playerSpeed, 0.0);
    if (rect.offset.x() < 0) {
      rect.offset.x() = 0;
    }
  }
  if (std::ranges::find(input, Input::Right) != input.cend()) {
    auto& rect = m_state->player->get().rect;
    rect.offset += Vec(m_state->playerSpeed, 0.0);
    if (rect.offset.x() + rect.span.x() > m_state->dimensions.x()) {
      rect.offset.x() = m_state->dimensions.x() - rect.span.x();
    }
  }
}

}  // namespace space_invaders::game
