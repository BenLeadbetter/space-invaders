#include <game/Game.h>
#include <game/GameState.h>
#include <game/Helpers.h>
#include <game/Object.h>

#include <catch2/catch.hpp>

namespace space_invaders::game::test {

SCENARIO("player behaviour", "[game][player]") {
  GIVEN("a default initialised game") {
    Game game{};
    const auto& player = game.state().player;
    THEN("there is a player") { CHECK(player); }
    THEN("the player is centred in the board") {
      REQUIRE(player);
      const auto rect = player->rect();
      CHECK(rect.offset.x() + rect.span.x() / 2.0 ==
            Approx(game.state().dimensions.x() / 2.0));
    }
    THEN("the player is at the bottom of the board") {
      REQUIRE(player);
      const auto rect = player->rect();
      CHECK(rect.offset.y() + rect.span.y() ==
            Approx(game.state().dimensions.y()));
    }
    WHEN("move left on tick") {
      REQUIRE(player);
      const auto xBefore = player->offset.x();
      game.tick({Input::Left});
      THEN("player is moved playerSpeed units left") {
        CHECK(player->offset.x() - xBefore ==
              Approx(-game.state().playerSpeed));
      }
    }
    WHEN("move right on tick") {
      REQUIRE(player);
      const auto xBefore = player->offset.x();
      game.tick({Input::Right});
      THEN("player is moved playerSpeed units right") {
        CHECK(player->offset.x() - xBefore == Approx(game.state().playerSpeed));
      }
    }
  }
  GIVEN("a game with the player positioned at the far left of the board") {
    Game game = []() {
      auto state = std::make_unique<GameState>();
      state->dimensions = Vec(100, 100);
      state->player = Object{
          .raster = {},
          .offset = Vec(0.0, 0.0),
      };
      return Game(std::move(state));
    }();
    const auto& player = game.state().player;
    WHEN("move left on tick") {
      REQUIRE(player);
      const auto xBefore = player->offset.x();
      game.tick({Input::Left});
      THEN("player position is unchanged") {
        CHECK(player->offset.x() - xBefore == Approx(0.0));
      }
    }
  }
  GIVEN("a game with the player positioned at the far right of the board") {
    Game game = []() {
      auto state = std::make_unique<GameState>();
      state->dimensions = Vec(100, 100);
      state->player = makePlayer();
      state->player->offset.x() =
          state->dimensions.x() - state->player->span().x();
      return Game(std::move(state));
    }();
    const auto& player = game.state().player;
    WHEN("move right on tick") {
      REQUIRE(player);
      const auto xBefore = player->offset.x();
      game.tick({Input::Right});
      THEN("player position is unchanged") {
        CHECK(player->offset.x() - xBefore == Approx(0.0));
      }
    }
  }
}

SCENARIO("bullet behaviour", "[game][bullet]") {
  GIVEN("a default initialised game") {
    Game game{};
    THEN("there is not bullet") { CHECK(!game.state().bullet); }
    WHEN("fire on tick") {
      game.tick({Input::Fire});
      THEN("a bullet is spawned") { CHECK(game.state().bullet); }
    }
  }
  GIVEN("a game with a bullet") {
    Game game = []() {
      auto state = std::make_unique<GameState>();
      state->player = makePlayer();
      state->player->offset.y() = 80;
      state->dimensions = Vec(100, 100);
      state->bullet = makeBullet();
      state->bullet->offset.y() = 50.0;
      state->bulletSpeed = 30.0;
      return Game(std::move(state));
    }();
    WHEN("game tick") {
      REQUIRE(game.state().bullet);
      auto yBefore = game.state().bullet->offset.y();
      game.tick();
      THEN("bullet has moved upwards by bulletSpeed units") {
        REQUIRE(game.state().bullet);
        CHECK(yBefore - game.state().bullet->offset.y() ==
              game.state().bulletSpeed);
      }
    }
    WHEN("bullet would move off screen") {
      REQUIRE(game.state().bullet);
      game.tick();
      game.tick();
      THEN("bullet is removed") { CHECK(!game.state().bullet); }
    }
    WHEN("fire on game tick") {
      REQUIRE(game.state().bullet);
      auto yBefore = game.state().bullet->offset.y();
      game.tick({Input::Fire});
      THEN("no new bullet is fired") {
        REQUIRE(game.state().bullet);
        CHECK(game.state().bullet->offset.y() ==
              yBefore - game.state().bulletSpeed);
      }
    }
  }
}

}  // namespace space_invaders::game::test
