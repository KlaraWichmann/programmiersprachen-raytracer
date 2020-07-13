#include "sphere.hpp"

Sphere::Sphere (glm::vec3 center, float radius, std::string name, Color color):
    //Aufrufen des Basis Konstruktors
    Shape (name, color),
    center_ {center},
    radius_ {radius}
    {}

float Sphere::area() const {
    return 4 * PI * std::pow(radius_, 2);
}

float Sphere::volume() const {
    return 4.0f / 3.0f * PI * std::pow(radius_, 3);
}

std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os);
    os << "Radius: " << radius_ << std::endl;
    os << "Center: " << center_.x << ", " << center_.y << ", " << center_.z << std::endl;
    os << "Oberfläche: " << this->area() << std::endl;
    os << "Volumen: " << this->volume() << std::endl;
    return os;
}

HitPoint Sphere::intersect (Ray r) {
    HitPoint hit;
    float distance = 0.0f;
    glm::vec3 point = {0.0f, 0.0f, 0.0f};
    glm::vec3 normal = {0.0f, 0.0f, 0.0f};
    bool result = glm::intersectRaySphere (
        r.origin , glm::normalize(r.direction) ,
        center_ ,
        radius_ * radius_,
        distance
    );
    glm::intersectRaySphere (
        r.origin , glm::normalize(r.direction) ,
        center_ ,
        radius_ * radius_,
        point,
        normal
    );
    hit.intersection = result;
    if (result) {
        hit.distance = distance;
        hit.name = name_;
        hit.color = color_;
        hit.intersection_point = point;
        hit.direction = glm::normalize(r.direction);
    }
    return hit;
    
}
