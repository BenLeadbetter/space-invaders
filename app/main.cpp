#include <game/Game.h>
#include <game/GameState.h>
#include <ncurses.h>
#include <render/Context.h>

#include <chrono>
#include <iostream>

int main() {
  using namespace space_invaders;

  game::Game game;
  render::Context renderer(game.state().dimensions);

  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  noecho();

  while (true) {
    auto tick = std::chrono::system_clock::now().time_since_epoch();
    clear();
  }

  endwin();
  return 0;
}
