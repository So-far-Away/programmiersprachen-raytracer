#include "Shape.hpp"

Shape::Shape(const std::string& name, const std::string& color) : name_(name), color_(color) {}

std::ostream& Shape::print(std::ostream& os) const {
    os << "Shape(Name: " << name_ << ", Color: " << color_ << ")";
    return os;
}

std::ostream& operator<<(std::ostream& os, const Shape& s) {
    return s.print(os);
}