#ifndef CIRCLE_H
#define CIRCLE_H

#include "IShape.h"
#include <string>

class Circle : public IShape {
    double radius;
public:
    Circle(double currRadius) : radius{currRadius} {}

    double getArea() override;
    double getPerimeter() override;
    std::string getName() override {
        return "Circle";
    }
};

#endif
