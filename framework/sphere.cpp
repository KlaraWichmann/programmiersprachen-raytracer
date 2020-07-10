#include "sphere.hpp"

Sphere::Sphere (glm::vec3 center, float radius, std::string name, Color color):
    center_ {center},
    radius_ {radius},
    //Aufrufen des Basis Konstruktors
    Shape (name, color)
{}

float Sphere::area() const {
    return 4 * PI * std::pow(radius_, 2);
}

float Sphere::volume() const {
    return 4 / 3 * PI * std::pow(radius_, 3);
}
