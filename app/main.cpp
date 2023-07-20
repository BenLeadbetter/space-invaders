#include <game/Game.h>
#include <game/GameState.h>
#include <locale.h>
#include <ncurses.h>
#include <render/Context.h>

#include <chrono>
#include <iostream>
#include <ranges>
#include <thread>

constexpr std::chrono::microseconds frameLength() {
  return std::chrono::microseconds(40000);
}

int main() {
  using namespace space_invaders;

  game::Game game;
  render::Context renderer(game.state().dimensions);

  setlocale(LC_ALL, "");
  initscr();
  cbreak();
  keypad(stdscr, TRUE);
  nodelay(stdscr, TRUE);
  scrollok(stdscr, FALSE);
  noecho();

  const auto tick = []() {
    const auto time = std::chrono::system_clock::now().time_since_epoch();
    return std::chrono::duration_cast<std::chrono::microseconds>(time);
  };

  while (true) {
    auto start = tick();

    if (int ch = getch(); ch == 'q') {
      break;
    }

    game.tick();

    clear();
    printw("%s", renderer.render(game).c_str());
    refresh();

    if (const auto end = tick(); end - start < frameLength()) {
      std::this_thread::sleep_for(frameLength() - (end - start));
    }
  }

  endwin();
  return 0;
}
