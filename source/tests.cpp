#define CATCH_CONFIG_RUNNER
#include <catch.hpp>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include <glm/vec3.hpp>
#include "sphere.hpp"
#include "box.hpp"
#include "ray.hpp"
#include "hit_point.hpp"

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

TEST_CASE ("describe_box_print", "[box_print]") {
    std::cout << "---------------------BOX PRINT--------------------------\n";
     // Box minimum = 0, 0, 0, maximum = 0, 0, 0
    Box package {{0.0f, 0.0f, 0.0f}, {0.0f, 0.0f, 0.0f}, "DHL", {255.0f, 255.0f, 255.0f}};
    package.print(std::cout);
    std::cout << "-----------------------------------------------\n";
    // Box minimum = 10, 5.5, 2.2, maximum = 30.5, 22, 4.7
    package =  {{10.0f, 5.5f, 2.2f}, {30.5f, 22.0f, 4.7f}, "UPS", {255.0f, 255.0f, 255.0f}};
    package.print(std::cout);
}

TEST_CASE ("describe_sphere_print", "[sphere_print]") {
    std::cout << "---------------------SPHERE PRINT--------------------------\n";
  // Sphere r = 2.5, center 0, 0, 0
        Sphere planet {{0.0f, 0.0f, 0.0f}, 2.5f, "Pluto", {255.0f, 255.0f, 255.0f}};
        planet.print(std::cout);
        std::cout << "-----------------------------------------------\n";
        // Sphere r = -3.7, center -1, -1, -1
        planet = {{-1.0f, -1.0f, -1.0f}, -3.7f, "Saturn", {255.0f, 255.0f, 255.0f}};
        planet.print(std::cout);
}

TEST_CASE("intersect_ray_sphere", "[intersect]") {
    // Ray
    glm::vec3 ray_origin{0.0f, 0.0f, 0.0f}; // ray direction has to be normalized !
    // you can use:
    // v = glm::normalize(some_vector)
    glm::vec3 ray_direction{0.0f, 0.0f, 1.0f};
    
    // Sphere
    glm::vec3 sphere_center{0.0f ,0.0f, 5.0f};
    float sphere_radius{1.0f};
    
    float distance = 0.0f;
    auto result = glm::intersectRaySphere(
        ray_origin , ray_direction ,
        sphere_center ,
        sphere_radius * sphere_radius, // squared radius !!!
        distance
    );
    REQUIRE(distance == Approx(4.0f));
}

TEST_CASE("intersect2_ray_sphere", "[intersect2]") {
    // Ray
    Ray ray;
    ray.origin = {0.0f, 0.0f, 0.0f};
    ray.direction = {0.0f, 0.0f, 1.0f};
    
    // Sphere r = 1, center 0, 0, 5
    Sphere planet {{0.0f, 0.0f, 5.0f}, 1.0f, "Pluto", {255.0f, 255.0f, 255.0f}};
    
    HitPoint hit = planet.intersect(ray);
    REQUIRE(hit.intersection == 1);
    REQUIRE(hit.distance == Approx(4.0f));
    REQUIRE(hit.name == "Pluto");
    REQUIRE(hit.color.r == 255.0f);
    REQUIRE(hit.color.g == 255.0f);
    REQUIRE(hit.color.b == 255.0f);
    REQUIRE(hit.intersection_point.x == 0.0f);
    REQUIRE(hit.intersection_point.y == 0.0f);
    REQUIRE(hit.intersection_point.z == 4.0f);
    REQUIRE(hit.direction.x == 0.0f);
    REQUIRE(hit.direction.y == 0.0f);
    REQUIRE(hit.direction.z == 1.0f);
}

TEST_CASE("no_intersect_ray_sphere", "[no_intersect]") {
    // Ray
    Ray ray;
    ray.origin = {1.0f, 0.0f, 0.0f};
    ray.direction = {0.0f, 2.0f, 5.0f};
    
    // Sphere r = 2.5, center 0, 0, 0
    Sphere planet {{0.0f, 0.0f, 0.0f}, 1.0f, "Pluto", {255.0f, 255.0f, 255.0f}};
    
    HitPoint hit = planet.intersect(ray);
    REQUIRE(hit.intersection == 0);
    REQUIRE(hit.distance == Approx(0.0f));
    REQUIRE(hit.name == "");
    REQUIRE(hit.color.r == 0.0f);
    REQUIRE(hit.color.g == 0.0f);
    REQUIRE(hit.color.b == 0.0f);
    REQUIRE(hit.intersection_point.x == 0.0f);
    REQUIRE(hit.intersection_point.y == 0.0f);
    REQUIRE(hit.intersection_point.z == 0.0f);
    REQUIRE(hit.direction.x == 0.0f);
    REQUIRE(hit.direction.y == 0.0f);
    REQUIRE(hit.direction.z == 0.0f);
}

int main(int argc, char *argv[])
{
  return Catch::Session().run(argc, argv);
}
