#include <render/Context.h>

#include <ftxui/screen/screen.hpp>
#include <ranges>

namespace space_invaders::render {

Context::Context(const game::Vec& dims)
    : m_screen(std::make_unique<ftxui::Screen>(static_cast<int>(dims.x()),
                                               static_cast<int>(dims.y()))) {}
Context::~Context() = default;

std::string Context::render(const game::Game&) { return {}; }

void Context::render(const game::Raster& raster) {}

}  // namespace space_invaders::render
