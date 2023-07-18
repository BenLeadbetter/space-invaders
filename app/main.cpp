#include <game/Game.h>
#include <gui/Render.h>

#include <iostream>

int main() {
  using namespace space_invaders;
  game::Game game;
  const auto frame = gui::render(game);
  std::cout << frame << std::endl;
  return 0;
}
