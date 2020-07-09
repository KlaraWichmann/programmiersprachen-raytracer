#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE ("describe_sphere_area", "[box_area]") {
    // Sphere r = 2.5, center 0, 0, 0
    Sphere planet {{0.0f, 0.0f, 0.0f}, 2.5f};
    float result = 0.0f;
    float expected = 78.53981f;
    result = planet.area ();
    REQUIRE (Approx(result) == expected);
    // Sphere r = -3.7, center -1, -1, -1
    planet = {{-1.0f, -1.0f, -1.0f}, -3.7f};
    expected = 172.03361f;
    result = planet.area ();
    REQUIRE (Approx(result) == expected);
    // Sphere r = 0, center 1, 1, 1
    planet =  {{1.0f, 1.0f, 1.0f}, 0.0f};
    expected = 0.0f;
    result = planet.area ();
    REQUIRE (Approx(result) == expected);
    // Sphere r = 13.2, center = 255, 255, 255
    planet =  {{255.0f, 255.0f, 255.0f}, 13.2f};
    expected = 2189.56441f;
    result = planet.area ();
    REQUIRE (Approx(result) == expected);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
