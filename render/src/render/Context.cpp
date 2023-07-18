#include <game/Game.h>
#include <game/GameState.h>
#include <game/Object.h>
#include <render/Context.h>

#include <ftxui/dom/canvas.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>
#include <ranges>

namespace space_invaders::render {

namespace {

void renderObj(const game::Object &obj, ftxui::Canvas &canvas) {
  int i = 0;
  for (auto i = 0; i != obj.raster.rows(); ++i) {
    for (auto j = 0; j != obj.raster.cols(); ++j) {
      if (obj.raster[i][j]) {
        const auto x = j + static_cast<int>(obj.offset.x());
        const auto y = i + static_cast<int>(obj.offset.y());
        canvas.DrawPoint(x, y, ftxui::Color::White);
      }
    }
  }
}

constexpr int borders() { return 2; }

}  // namespace

Context::Context(const game::Vec &dims)
    : m_screen(std::make_unique<ftxui::Screen>(
          static_cast<int>(dims.x() / 2.0) + borders(),
          static_cast<int>(dims.y() / 4.0) + borders())) {}

Context::~Context() = default;

std::string Context::render(const game::Game &game) {
  ftxui::Canvas canvas((m_screen->dimx() + 1) * 2, (m_screen->dimy() + 1) * 4);

  const auto &state = game.state();
  renderObj(*state.player, canvas);
  if (state.bullet) {
    renderObj(*state.bullet, canvas);
  }

  ftxui::Render(*m_screen, ftxui::border(ftxui::canvas(canvas)).get());
  return m_screen->ToString();
}

}  // namespace space_invaders::render
