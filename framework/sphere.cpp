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

std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os);
    os << "Radius: " << radius_ << std::endl;
    os << "Center: " << center_.x << ", " << center_.y << ", " << center_.z << std::endl;
    os << "Oberfläche: " << this->area() << std::endl;
    os << "Volumen: " << this->volume() << std::endl;
    return os;
}
