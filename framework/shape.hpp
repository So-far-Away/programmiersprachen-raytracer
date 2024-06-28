#ifndef SHAPE_H
#define SHAPE_H

class Shape {
public:
    virtual double area() const = 0;
    virtual double volume() const = 0;
    virtual ~Shape() {}
};

#endif // SHAPE_H