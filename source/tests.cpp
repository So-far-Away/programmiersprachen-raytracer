#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "shape.hpp"
#include "box.hpp"
#include "sphere.hpp"
#include "hitpoint.hpp"
#include <glm/gtx/intersect.hpp>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>

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

// Tests for intersection of Ray and Sphere
TEST_CASE("intersect_ray_sphere", "[intersect]") {
    Sphere sphere("Test Sphere", "Red", glm::vec3(0.0f, 0.0f, 5.0f), 1.0f);
    Ray ray;
    ray.origin = glm::vec3(0.0f, 0.0f, 0.0f);
    ray.direction = glm::normalize(glm::vec3(0.0f, 0.0f, 1.0f));

    HitPoint hit = sphere.intersect(ray);

    REQUIRE(hit.hit == true);
    REQUIRE(hit.distance == Approx(4.0f).epsilon(0.001));//Sphere center z=5, radius=1, intersection z=4
    REQUIRE(hit.name == "Test Sphere");
    REQUIRE(hit.color == "Red");
    REQUIRE(hit.point == glm::vec3(0.0f, 0.0f, 4.0f));
    REQUIRE(hit.direction == glm::vec3(0.0f, 0.0f, 1.0f));
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
