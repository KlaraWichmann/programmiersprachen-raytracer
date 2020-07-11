#ifndef SPHERE_HPP
#define SPHERE_HPP

#define PI 3.14159265359
#include <cmath>
#include <glm/vec3.hpp>
#include "shape.hpp"

class Sphere : public Shape {
    public:
        Sphere (glm::vec3 center, float radius, std::string name, Color color);
        //Oberflächenberechnung der Kugel
        float area() const override;
        //Volumenberechnung der Kugel
        float volume() const override;
        //Ausgabe der Kugel
        std::ostream& print(std::ostream& os) const override;
    private:
        glm::vec3 center_;
        float radius_ = 0.0f;
};

#endif // SPHERE_HPP
