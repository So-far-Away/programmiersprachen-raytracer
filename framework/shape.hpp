#ifndef SHAPE_H
#define SHAPE_H
#include <string>

class Shape {
public:

    std::string name_;
    std::string color_;

    Shape(const std::string& name, const std::string& color) 
        : name_(name), color_(color) {}

    virtual double area() const = 0;
    virtual double volume() const = 0;
    virtual ~Shape() {}//das ist en virtueller Destruktor

    virtual std::ostream& print(std::ostream& os) const {
        os << "Shape(Name: " << name_ << ", Color: " << color_ << ")";
        return os;
    }

    friend std::ostream& operator<<(std::ostream& os, const Shape& s);
};

// Implementierung des Ausgabeoperators außerhalb der Klassendefinition
inline std::ostream& operator<<(std::ostream& os, const Shape& s) {
    return s.print(os);
}

#endif // SHAPE_H