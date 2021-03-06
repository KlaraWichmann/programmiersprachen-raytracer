#ifndef BOX_HPP
#define BOX_HPP

#include <glm/vec3.hpp>
#include "shape.hpp"

class Box : public Shape {
    public:
        Box (glm::vec3 minimum, glm::vec3 maximum, std::string name, Color color);
        ~Box ();
        float area() const override;
        float volume() const override;
        std::ostream& print(std::ostream& os) const override;
    private:
        glm::vec3 minimum_;
        glm::vec3 maximum_;
        float width_;
        float height_;
        float depth_;
};

#endif // BOX_HPP
