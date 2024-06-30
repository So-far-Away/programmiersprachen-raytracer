#ifndef SPHERE_H
#define SPHERE_H

#include "shape.hpp"
#include "hitpoint.hpp"
#include "ray.hpp"
#include <glm/vec3.hpp>

class Sphere : public Shape {
public:
    Sphere(const std::string& name, const std::string& color, const glm::vec3& center, double radius);

    double area() const override;
    double volume() const override;
    std::ostream& print(std::ostream& os) const override;

    HitPoint intersect(const Ray& ray) const;

private:
    glm::vec3 center_;
    double radius_;
};

#endif // SPHERE_H