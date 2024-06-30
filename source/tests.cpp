#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "../build/framework/box.hpp"

// Tests for Sphere
TEST_CASE("Sphere calculates area and volume correctly", "[Sphere]") {
    Sphere sphere("Test Sphere", "Red", glm::vec3(0.0, 0.0, 0.0), 2.0);

    REQUIRE(sphere.name_ == "Test Sphere");
    REQUIRE(sphere.color_ == "Red");
    REQUIRE(Approx(sphere.area()).epsilon(0.001) == 12.566370614359172);//4*pi*r^2
    REQUIRE(Approx(sphere.volume()).epsilon(0.001) == 4.1887902047863905);//(4/3)*pi*r^3
}

// Tests for Box
TEST_CASE("Box calculates area and volume correctly", "[Box]") {
    Box box("Test Box", "Blue", glm::vec3(0.0, 0.0, 0.0), glm::vec3(1.0, 2.0, 3.0));

    REQUIRE(box.name_ == "Test Box");
    REQUIRE(box.color_ == "Blue");
    REQUIRE(Approx(box.area()).epsilon(0.001) == 6.0);// 2*(1*1 + 1*1 + 1*1)
    REQUIRE(Approx(box.volume()).epsilon(0.001) == 1.0);//1*1*1
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
