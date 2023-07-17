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
      const auto rect = player->rect;
      CHECK(rect.offset.x() + rect.span.x() / 2.0 ==
            Approx(game.state().dimensions.x() / 2.0));
    }
    WHEN("move left on tick") {
      REQUIRE(player);
      const auto xBefore = player->rect.offset.x();
      game.tick({Input::Left});
      THEN("player is moved playerSpeed units left") {
        CHECK(player->rect.offset.x() - xBefore ==
              Approx(-game.state().playerSpeed));
      }
    }
    WHEN("move right on tick") {
      REQUIRE(player);
      const auto xBefore = player->rect.offset.x();
      game.tick({Input::Right});
      THEN("player is moved playerSpeed units right") {
        CHECK(player->rect.offset.x() - xBefore ==
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
      return Game(std::move(state));
    }();
    const auto& player = game.state().player;
    WHEN("move left on tick") {
      REQUIRE(player);
      const auto xBefore = player->rect.offset.x();
      game.tick({Input::Left});
      THEN("player position is unchanged") {
        CHECK(player->rect.offset.x() - xBefore == Approx(0.0));
      }
    }
  }
  GIVEN("a game with the player positioned at the far right of the board") {
    Game game = []() {
      auto state = std::make_unique<GameState>();
      state->dimensions = Vec(100, 100);
      auto player = std::make_unique<Object>();
      player->rect = {
          .offset = Vec(50.0, 0.0),
          .span = Vec(50.0, 25.0),
      };
      state->player = *player;
      return Game(std::move(state));
    }();
    const auto& player = game.state().player;
    WHEN("move right on tick") {
      REQUIRE(player);
      const auto xBefore = player->rect.offset.x();
      game.tick({Input::Right});
      THEN("player position is unchanged") {
        CHECK(player->rect.offset.x() - xBefore == Approx(0.0));
      }
    }
  }
}

SCENARIO("bullet behaviour", "[game][bullet]") {
  GIVEN("a default initialised game") {
    Game game{};
    THEN("there is not bullet") { CHECK(!game.state().bullet); }
  }
  GIVEN("a game with a bullet") {
    Game game = []() {
      auto state = std::make_unique<GameState>();
      state->dimensions = Vec(100, 100);
      auto bullet = std::make_unique<Object>();
      bullet->rect = {
          .offset = Vec(50.0, 50.0),
          .span = Vec(1.0, 1.0),
      };
      state->bulletSpeed = 30.0;
      state->bullet = *bullet;
      return Game(std::move(state));
    }();
    WHEN("game tick") {
      REQUIRE(game.state().bullet);
      auto yBefore = game.state().bullet->rect.offset.y();
      game.tick();
      THEN("bullet has moved upwards by bulletSpeed units") {
        CHECK(yBefore - game.state().bullet->rect.offset.y() ==
              game.state().bulletSpeed);
      }
    }
    WHEN("bullet would move off screen") {
      REQUIRE(game.state().bullet);
      game.tick();
      game.tick();
      THEN("bullet is removed") { CHECK(!game.state().bullet); }
    }
  }
}

}  // namespace space_invaders::game::test
