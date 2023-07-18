#pragma once

#include <game/Metrics.h>

#include <memory>
#include <string>

namespace space_invaders::game {
class Game;
class Object;
}  // namespace space_invaders::game
namespace ftxui {
class Screen;
}

namespace space_invaders::render {

class Context {
 public:
  Context(const game::Vec &);
  ~Context();
  std::string render(const game::Game &);

 private:
  void render(const game::Object &);

  std::unique_ptr<ftxui::Screen> m_screen;
};

}  // namespace space_invaders::render
