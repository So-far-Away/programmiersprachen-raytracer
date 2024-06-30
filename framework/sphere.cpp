#define _USE_MATH_DEFINES
#include "sphere.hpp"
#include "hitpoint.hpp"
#include <cmath>
#include <string>
#include <numbers>
#include <glm/gtx/intersect.hpp>
#include <glm/glm.hpp>
#include <glm/vec3.hpp>



Sphere::Sphere(const std::string& name, const std::string& color, const glm::vec3& center, double radius)
    : Shape(name, color), center_(center), radius_(radius) {}

double Sphere::area() const {
    return 4 * M_PI * std::pow(radius_, 2);
}

double Sphere::volume() const {
    return (4.0 / 3.0) * M_PI * std::pow(radius_, 3);
}

std::ostream& Sphere::print(std::ostream& os) const {
    Shape::print(os);
    os << ", Center: [" << center_.x << ", " << center_.y << ", " << center_.z << "]"
        << ", Radius: " << radius_ << ")";
    return os;
}

HitPoint Sphere::intersect(const Ray& ray) const {
    HitPoint hit;
    float distance;
    bool result = glm::intersectRaySphere(
        ray.origin, glm::normalize(ray.direction), center_,
        radius_ * radius_, distance
    );

    if (result) {
        hit.hit = true;
        hit.distance = distance;
        hit.name = name_;
        hit.color = color_;
        hit.point = ray.origin + ray.direction * distance;
        hit.direction = ray.direction;
    }

    return hit;
}