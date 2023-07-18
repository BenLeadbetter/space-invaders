#include <game/Helpers.h>

namespace space_invaders::game {

Object makePlayer() {
  static const std::string data =
      "0000001111000000\n"
      "0000110000110000\n"
      "0000111111110000\n"
      "0000111111110000\n"
      "0000011111100000\n"
      "0000111011100000\n"
      "0011000110001100\n"
      "0000001100000000";
  return {
      .raster = Raster::from(data),
      .offset = {},
  };
}

Object makeBullet() {
  static const std::string data = "1\n1";
  return {
      .raster = Raster::from(data),
      .offset = {},
  };
}

}  // namespace space_invaders::game
