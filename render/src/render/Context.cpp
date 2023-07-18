#include <game/Game.h>
#include <game/GameState.h>
#include <game/Object.h>
#include <render/Context.h>

#include <ftxui/dom/canvas.hpp>
#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <ranges>

namespace space_invaders::render {

namespace {

void renderObj(const game::Object &obj, ftxui::Canvas &canvas) {
  using Size = game::Raster::size_type;
  Size i = 0;
  Size j = 0;
  for (const auto &row : obj.raster) {
    for (const auto &pix : row) {
      if (pix) {
        canvas.DrawPoint(i + static_cast<int>(obj.offset.x()),
                         j + static_cast<int>(obj.offset.y()),
                         ftxui::Color::White);
      }
      ++j;
    }
    ++i;
  }
}

}  // namespace

Context::Context(const game::Vec &dims)
    : m_screen(std::make_unique<ftxui::Screen>(
          static_cast<int>(dims.x() / 2.0), static_cast<int>(dims.y() / 4.0))) {
}
Context::~Context() = default;

std::string Context::render(const game::Game &game) {
  ftxui::Canvas canvas(m_screen->dimx(), m_screen->dimy());

  const auto &state = game.state();
  renderObj(*state.player, canvas);
  if (state.bullet) {
    renderObj(*state.bullet, canvas);
  }

  ftxui::Render(*m_screen, ftxui::border(ftxui::canvas(canvas)).get());
  return m_screen->ToString();
}

}  // namespace space_invaders::render
