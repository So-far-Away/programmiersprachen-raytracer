#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

class Shape {
public:
    std::string name_;
    std::string color_;

    Shape(const std::string& name, const std::string& color);
    virtual ~Shape() {}

    virtual double area() const = 0;
    virtual double volume() const = 0;

    virtual std::ostream& print(std::ostream& os) const;

    friend std::ostream& operator<<(std::ostream& os, const Shape& s);
};

#endif // SHAPE_H
