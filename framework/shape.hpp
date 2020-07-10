#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <string>
#include "color.hpp"

class Shape {
    public:
        Shape (std::string name, Color color):
            name_ {name},
            color_ {color}
        {}
        //Oberflächenberechnung eines Objekts (rein virtuelle Methode)
        virtual float area() const = 0;
        //Volumenberechnung eines Objekts (rein virtuelle Methode)
        virtual float volume() const = 0;
    private:
        std::string name_;
        Color color_;
};

#endif // SHAPE_HPP
