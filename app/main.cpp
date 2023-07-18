#include <game/Game.h>
#include <game/GameState.h>
#include <render/Context.h>

#include <iostream>

int main() {
  using namespace space_invaders;
  game::Game game;
  render::Context renderer(game.state().dimensions);
  std::cout << renderer.render(game) << std::endl;
  return 0;
}
