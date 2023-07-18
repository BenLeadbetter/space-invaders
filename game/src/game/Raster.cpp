#include <game/Raster.h>

#include <algorithm>
#include <ranges>

namespace space_invaders::game {
Raster Raster::makeEmpty(std::size_t rows, std::size_t cols) {
  return Raster(rows, raster::Row(cols, std::nullopt));
}

Raster Raster::from(std::string_view str) {
  const auto toPix = [](char c) -> std::optional<raster::Pixel> {
    if (c == '0') {
      return std::nullopt;
    } else {
      return raster::Pixel{};
    }
  };
  std::vector<raster::Row> rows;
  for (const auto row : std::views::split(str, "\n")) {
    const auto range = row | std::views::transform(toPix);
    rows.emplace_back(range.begin(), range.end());
    if (rows.size() > 1 && rows.back().size() != rows.front().size()) {
      throw std::runtime_error(
          "error passing raster string. "
          "all rows should be the same length");
    }
  }
  return {rows.begin(), rows.end()};
}

Raster::size_type Raster::rows() const { return size(); }

Raster::size_type Raster::cols() const { return empty() ? 0 : front().size(); }

}  // namespace space_invaders::game
