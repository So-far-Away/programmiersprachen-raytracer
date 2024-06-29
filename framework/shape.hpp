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
};

#endif // SHAPE_H