#ifndef BOX_H
#define BOX_H

#include "shape.hpp"#
#include <iostream>
#include <glm/vec3.hpp>

class Box : public Shape {
public:
    // Konstruktor
    Box(const std::string& name, const std::string& color, glm::vec3 min, glm::vec3 max);

    //überschreibung der virtuellen Funktionen von Shape
    double area() const override;
    double volume() const override;
    std::ostream& print(std::ostream& os) const override;

private:
    glm::vec3 min;
    glm::vec3 max;
};

#endif // BOX_H
