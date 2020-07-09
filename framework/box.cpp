#include "box.hpp"

Box::Box (glm::vec3 minimum, glm::vec3 maximum):
    minimum_ {minimum},
    maximum_ {maximum},
    width_ {maximum_.x - minimum_.x},
    height_ {maximum_.y - minimum_.y},
    depth_ {maximum_.z - minimum_.z}
{}

float Box::area() const {
    return 2 * (width_ * height_ + height_ * depth_ + width_ * depth_);
}

float Box::volume() const {
    return width_ * height_ * depth_;
}
