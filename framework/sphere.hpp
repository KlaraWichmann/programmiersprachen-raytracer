#ifndef SPHERE_HPP
#define SPHERE_HPP

#define PI 3.14159265359
#include <cmath>
#include <glm/vec3.hpp>
#include <glm/glm.hpp>
#include <glm/gtx/intersect.hpp>
#include "shape.hpp"
#include "ray.hpp"
#include "hit_point.hpp"

class Sphere : public Shape {
    public:
        Sphere (glm::vec3 center, float radius, std::string name, Color color);
        ~Sphere ();
        float area() const override;
        float volume() const override;
        std::ostream& print(std::ostream& os) const override;
        HitPoint intersect (Ray r);
    private:
        glm::vec3 center_;
        float radius_ = 0.0f;
};

#endif // SPHERE_HPP
