#include "Game.h"

#include "Object.h"

namespace space_invaders::game {

namespace {

auto makeRoot() { return std::make_unique<Object>(); }

auto makePlayer() { return std::make_unique<Object>(); }

}  // namespace

Game::Game() {
  {
    auto root = makeRoot();
    m_root = *root;
    m_objects.push_back(std::move(root));
  }

  {
    auto player = makePlayer();
    m_player = *player;
    m_objects.push_back(std::move(player));
  }
}

void Game::tick(std::vector<Input>) {}

}  // namespace space_invaders::game
