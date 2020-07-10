#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include "sphere.hpp"
#include "box.hpp"

TEST_CASE ("describe_sphere_area", "[sphere_area]") {
    // Sphere r = 2.5, center 0, 0, 0
    Sphere planet {{0.0f, 0.0f, 0.0f}, 2.5f, "Pluto", {255.0f, 255.0f, 255.0f}};
    float result = 0.0f;
    float expected = 78.53981f;
    result = planet.area ();
    REQUIRE (Approx(result) == expected);
    // Sphere r = -3.7, center -1, -1, -1
    planet = {{-1.0f, -1.0f, -1.0f}, -3.7f, "Pluto", {255.0f, 255.0f, 255.0f}};
    expected = 172.03361f;
    result = planet.area ();
    REQUIRE (Approx(result) == expected);
    // Sphere r = 0, center 1, 1, 1
    planet =  {{1.0f, 1.0f, 1.0f}, 0.0f, "Pluto", {255.0f, 255.0f, 255.0f}};
    expected = 0.0f;
    result = planet.area ();
    REQUIRE (Approx(result) == expected);
    // Sphere r = 13.2, center = 255, 255, 255
    planet =  {{255.0f, 255.0f, 255.0f}, 13.2f, "Pluto", {255.0f, 255.0f, 255.0f}};
    expected = 2189.56441f;
    result = planet.area ();
    REQUIRE (Approx(result) == expected);
}

TEST_CASE ("describe_sphere_volume", "[sphere_volume]") {
    // Sphere r = 2.5, center 0, 0, 0
    Sphere planet {{0.0f, 0.0f, 0.0f}, 2.5f, "Pluto", {255.0f, 255.0f, 255.0f}};
    float result = 0.0f;
    float expected = 65.44984f;
    result = planet.volume ();
    //REQUIRE (Approx(result) == expected);
    // Sphere r = -3.7, center -1, -1, -1
    planet = {{-1.0f, -1.0f, -1.0f}, -3.7f, "Pluto", {255.0f, 255.0f, 255.0f}};
    expected = -212.17479f;
    result = planet.volume ();
    //REQUIRE (Approx(result) == expected);
    // Sphere r = 0, center 1, 1, 1
    planet =  {{1.0f, 1.0f, 1.0f}, 0.0f, "Pluto", {255.0f, 255.0f, 255.0f}};
    expected = 0.0f;
    result = planet.volume ();
    //REQUIRE (Approx(result) == expected);
    // Sphere r = 13.2, center = 255, 255, 255
    planet =  {{255.0f, 255.0f, 255.0f}, 13.2f, "Pluto", {255.0f, 255.0f, 255.0f}};
    expected = 9634.08343f;
    result = planet.volume ();
    //REQUIRE (Approx(result) == expected);
}

TEST_CASE ("describe_box_area", "[box_area]") {
    // Box minimum = 0, 0, 0, maximum = 0, 0, 0
    Box package {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, "DHL", {255.0f, 255.0f, 255.0f}};
    float result = 0.0f;
    float expected = 0.0f;
    result = package.area ();
    REQUIRE (Approx(result) == expected);
    // Box minimum = -1, -1, -1, maximum = 1, 1, 1
    package = {{-1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, "DHL", {255.0f, 255.0f, 255.0f}};
    expected = 24.0f;
    result = package.area ();
    REQUIRE (Approx(result) == expected);
    // Box minimum = 0, 0, 0, maximum = 0.5, 0.5, 0.5
    package =  {{0.0f, 0.0f, 0.0f}, {0.5f, 0.5f, 0.5f}, "DHL", {255.0f, 255.0f, 255.0f}};
    expected = 1.5f;
    result = package.area ();
    REQUIRE (Approx(result) == expected);
    // Box minimum = 10, 5.5, 2.2, maximum = 30.5, 22, 4.7
    package =  {{10.0f, 5.5f, 2.2f}, {30.5f, 22.0f, 4.7f}, "DHL", {255.0f, 255.0f, 255.0f}};
    expected = 861.5f;
    result = package.area ();
    REQUIRE (Approx(result) == expected);
}

TEST_CASE ("describe_box_volume", "[box_volume]") {
     // Box minimum = 0, 0, 0, maximum = 0, 0, 0
    Box package {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, "DHL", {255.0f, 255.0f, 255.0f}};
    float result = 0.0f;
    float expected = 0.0f;
    result = package.volume ();
    REQUIRE (Approx(result) == expected);
    // Box minimum = -1, -1, -1, maximum = 1, 1, 1
    package = {{-1.0f, -1.0f, -1.0f}, {1.0f, 1.0f, 1.0f}, "DHL", {255.0f, 255.0f, 255.0f}};
    expected = 8.0f;
    result = package.volume ();
    REQUIRE (Approx(result) == expected);
    // Box minimum = 0, 0, 0, maximum = 0.5, 0.5, 0.5
    package =  {{0.0f, 0.0f, 0.0f}, {0.5f, 0.5f, 0.5f}, "DHL", {255.0f, 255.0f, 255.0f}};
    expected = 0.125f;
    result = package.volume ();
    REQUIRE (Approx(result) == expected);
    // Box minimum = 10, 5.5, 2.2, maximum = 30.5, 22, 4.7
    package =  {{10.0f, 5.5f, 2.2f}, {30.5f, 22.0f, 4.7f}, "DHL", {255.0f, 255.0f, 255.0f}};
    expected = 845.625;
    result = package.volume ();
    REQUIRE (Approx(result) == expected);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
