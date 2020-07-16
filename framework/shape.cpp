#include "shape.hpp"

/*
 * Konstruktor der Klasse Shape
 */
Shape::Shape(std::string name, Color color):
    name_ {name},
    color_ {color}
{
    std::cout << "Konstruktor Shape\n";
}

/*
 * Destruktor der Klasse Shape
 */
Shape::~Shape() {
    std::cout << "Destruktor Shape\n";
}

/*
 * Virtuelle Methode, die die Mermale des Körpers aud den übergebeneden stream ausgibt
 */
std::ostream& Shape::print(std::ostream& os) const {
    os << "Name: " << name_ << std::endl;
    os << "Farbe: " << color_.r << ", " << color_.g << ", " << color_.b << std::endl;
    return os;
}

/*
 * Überladen des << Operators für die Ausgabe eines Körpers
 */
std::ostream& operator << (std::ostream& os, Shape const& s) {
    return s.print(os);
}
