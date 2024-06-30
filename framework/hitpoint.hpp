#ifndef HIT_POINT_H
#define HIT_POINT_H

#include <string>
#include <glm/vec3.hpp>

struct HitPoint {
    bool hit;
    float distance;
    std::string name;
    std::string color;
    glm::vec3 point;
    glm::vec3 direction;

    HitPoint() : hit(false), distance(0.0f) {}
};

#endif // HIT_POINT_H