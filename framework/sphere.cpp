#include "sphere.hpp"

Sphere::Sphere (glm::vec3 center, float radius):
    center_ {center},
    radius_ {radius}
{}

float Sphere::area() const {
    return 4 * PI * std::pow(radius_, 2);
}

float Sphere::volume() const {
    return 4 / 3 * PI * std::pow(radius_, 3);
}
