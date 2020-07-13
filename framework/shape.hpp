#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "color.hpp"

class Shape {
    public:
        Shape (std::string name, Color color);
        //Oberflächenberechnung eines Objekts (rein virtuelle Methode)
        virtual float area() const = 0;
        //Volumenberechnung eines Objekts (rein virtuelle Methode)
        virtual float volume() const = 0;
        //Ausgabe eines Objekts (virtuelle Methode)
        virtual std::ostream& print(std::ostream& os) const;
    protected:
        std::string name_;
        Color color_;
};

std::ostream& operator << (std::ostream& os, Shape const& s);

#endif // SHAPE_HPP
