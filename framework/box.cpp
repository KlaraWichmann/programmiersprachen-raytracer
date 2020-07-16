#include "box.hpp"

/*
 * Konstruktor der Klasse Box
 */
Box::Box (glm::vec3 minimum, glm::vec3 maximum, std::string name, Color color):
    //Aufrufen des Basis Konstruktors
    Shape (name, color),
    minimum_ {minimum},
    maximum_ {maximum},
    width_ {maximum_.x - minimum_.x},
    height_ {maximum_.y - minimum_.y},
    depth_ {maximum_.z - minimum_.z}
{
    if (minimum.x > maximum.x || minimum.y > maximum.y || minimum.z > maximum.z) {
        std::cout << "Achtung: Das Minimum sollte kleiner als das Maximum sein!\n";
    }
    std::cout << "Konstruktor Box\n";
}
 
/*
* Destruktor der Klasse Box
*/
Box::~Box () {
        std::cout << "Destruktor Box\n";
}

/*
 * Berechnet die Oberfläche des Quaders
 */
float Box::area() const {
    return 2 * (width_ * height_ + height_ * depth_ + width_ * depth_);
}

/*
 * Berechnet das Volumen des Quaders
 */
float Box::volume() const {
    return width_ * height_ * depth_;
}

/*
* Ausgabe der Merkmale des Quaders auf den übergebenden stream
*/
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
