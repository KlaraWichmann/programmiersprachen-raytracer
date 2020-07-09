#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape {
   public:
    //Oberflächenberechnung eines Objekts (rein virtuelle Methode)
    virtual float area() const = 0;
    //Volumenberechnung eines Objekts (rein virtuelle Methode)
    virtual float volume() const = 0;
};

#endif // SHAPE_HPP
