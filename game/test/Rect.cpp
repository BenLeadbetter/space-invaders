#include <game/Rect.h>

#include <catch2/catch.hpp>

namespace space_invaders::game::test {

SCENARIO("intersecting rectangles", "[Rect]") {
  GIVEN("an rect") {
    Rect rect{
        .offset = Vec(30.0, 40.0),
        .span = Vec(10.0, 20.0),
    };

    THEN("topLeft return top left in parent coords") {
      const auto calculated = rect.topLeft();
      const auto expected = Vec(30.0, 40.0);
      CHECK(calculated(0) == Approx(expected(0)));
      CHECK(calculated(1) == Approx(expected(1)));
    }

    THEN("topRight return top right in parent coords") {
      const auto calculated = rect.topRight();
      const auto expected = Vec(40.0, 40.0);
      CHECK(calculated(0) == Approx(expected(0)));
      CHECK(calculated(1) == Approx(expected(1)));
    }

    THEN("it intersects itself") { CHECK(rect.intersects(rect)); }

    THEN("it intersects an overlapping rect") {
      CHECK(rect.intersects({
          .offset = Vec(35.0, 45.0),
          .span = Vec(20.0, 20.0),
      }));
    }

    THEN("doesn't intersect a disjoint rect") {
      CHECK(!rect.intersects({
          .offset = Vec(0.0, 0.0),
          .span = Vec(20.0, 20.0),
      }));
    }
  }
}

}  // namespace space_invaders::game::test
