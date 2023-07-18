#include <game/Game.h>
#include <game/GameState.h>
#include <game/Helpers.h>
#include <game/Object.h>

#include <ranges>

namespace space_invaders::game {

namespace {

void initPlayer(Object& player, Vec& gameDims) {
  player.offset.x() = (gameDims.x() - player.span().x()) / 2.0;
  player.offset.y() = player.span().y();
}

}  // namespace

Game::Game() {
  m_state = std::make_unique<GameState>();
  m_state->dimensions = Vec(300, 400);
  m_state->player = makePlayer();
  initPlayer(*m_state->player, m_state->dimensions);
}

Game::Game(std::unique_ptr<GameState> state) : m_state(std::move(state)) {}

Game::~Game() = default;

void Game::tick(std::vector<Input> input) {
  if (std::ranges::find(input, Input::Left) != input.cend()) {
    auto& offset = m_state->player->offset;
    offset += Vec(-m_state->playerSpeed, 0.0);
    if (offset.x() < 0) {
      offset.x() = 0;
    }
  }
  if (std::ranges::find(input, Input::Right) != input.cend()) {
    auto& offset = m_state->player->offset;
    offset += Vec(m_state->playerSpeed, 0.0);
    if (offset.x() + m_state->player->span().x() > m_state->dimensions.x()) {
      m_state->player->offset.x() =
          m_state->dimensions.x() - m_state->player->span().x();
    }
  }
  if (m_state->bullet) {
    m_state->bullet->offset.y() -= m_state->bulletSpeed;
    if (m_state->bullet->offset.y() < 0) {
      m_state->bullet = std::nullopt;
    }
  }
}

}  // namespace space_invaders::game
