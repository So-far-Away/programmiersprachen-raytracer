#include "box.hpp"

//Konstruktor
Box::Box(const std::string& name, const std::string& color, glm::vec3 min, glm::vec3 max)
    : Shape(name, color), min(min), max(max) {}

//Berechnung der fläche der Box
double Box::area() const {
    return 2.0 * ((max.x - min.x) * (max.y - min.y) + (max.x - min.x) * (max.z - min.z) + (max.y - min.y) * (max.z - min.z));
}

//Berechnung des Volumens der Box
double Box::volume() const {
    return (max.x - min.x) * (max.y - min.y) * (max.z - min.z);
}

// Druckfunktion für Box,
std::ostream& Box::print(std::ostream& os) const {
    Shape::print(os);// Basisklassen-Methode Name und Farbe zu drucken
    os << ", Min: [" << min.x << ", " << min.y << ", " << min.z
        << "], Max: [" << max.x << ", " << max.y << ", " << max.z << "]";
    return os;
}