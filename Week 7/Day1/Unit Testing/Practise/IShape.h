#ifndef SHAPE_H
#define SHAPE_H

#include <string>

class IShape {
public:
    virtual double getArea() = 0;
    virtual double getPerimeter() = 0;
    virtual std::string getName() = 0;
};

#endif