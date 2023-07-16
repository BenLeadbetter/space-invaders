#include "Game.h"

#include <catch2/catch.hpp>

#include "GameState.h"
#include "Object.h"

namespace space_invaders::game::test {

SCENARIO("player behaviour", "[game][player]") {
  GIVEN("a default initialised game") {
    Game game{};
    const auto& player = game.state().player;
    THEN("there is a player") { CHECK(player); }
    THEN("the player is centred in the board") {
      REQUIRE(player);
      const auto rect = player->get().rect;
      CHECK(rect.offset.x() + rect.span.x() / 2.0 ==
            Approx(game.state().dimensions.x() / 2.0));
    }
    WHEN("move left on tick") {
      REQUIRE(player);
      const auto xBefore = player->get().rect.offset.x();
      game.tick({Input::Left});
      THEN("player is moved playerSpeed units left") {
        CHECK(player->get().rect.offset.x() - xBefore ==
              Approx(-game.state().playerSpeed));
      }
    }
    WHEN("move right on tick") {
      REQUIRE(player);
      const auto xBefore = player->get().rect.offset.x();
      game.tick({Input::Right});
      THEN("player is moved playerSpeed units right") {
        CHECK(player->get().rect.offset.x() - xBefore ==
              Approx(game.state().playerSpeed));
      }
    }
  }
  GIVEN("a game with the player positioned at the far left of the board") {
    Game game = []() {
      auto state = std::make_unique<GameState>();
      state->dimensions = Vec(100, 100);
      auto player = std::make_unique<Object>();
      player->rect = {
          .offset = Vec(0.0, 0.0),
          .span = Vec(50.0, 25.0),
      };
      state->player = *player;
      state->objects.push_back(std::move(player));
      return Game(std::move(state));
    }();
    const auto& player = game.state().player;
    WHEN("move left on tick") {
      REQUIRE(player);
      const auto xBefore = player->get().rect.offset.x();
      game.tick({Input::Left});
      THEN("player position is unchanged") {
        CHECK(player->get().rect.offset.x() - xBefore == Approx(0.0));
      }
    }
  }
}

}  // namespace space_invaders::game::test
