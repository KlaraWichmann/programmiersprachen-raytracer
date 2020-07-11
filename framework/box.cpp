#include "box.hpp"

Box::Box (glm::vec3 minimum, glm::vec3 maximum, std::string name, Color color):
    minimum_ {minimum},
    maximum_ {maximum},
    width_ {maximum_.x - minimum_.x},
    height_ {maximum_.y - minimum_.y},
    depth_ {maximum_.z - minimum_.z},
    //Aufrufen des Basis Konstruktors
    Shape (name, color)
{}

float Box::area() const {
    return 2 * (width_ * height_ + height_ * depth_ + width_ * depth_);
}

float Box::volume() const {
    return width_ * height_ * depth_;
}

std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);
    os << "Minimum: " << minimum_.x << ", " << minimum_.y << ", " << minimum_.z << std::endl;
    os << "Maximum: " << maximum_.x << ", " << maximum_.y << ", " << maximum_.z << std::endl;
    os << "Breite: " << width_ << std::endl;
    os << "Höhe: " << height_ << std::endl;
    os << "Tiefe: " << depth_ << std::endl;
    os << "Oberfläche: " << this->area() << std::endl;
    os << "Volumen: " << this->volume() << std::endl;
    return os;
}
