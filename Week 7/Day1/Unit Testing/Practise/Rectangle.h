#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "IShape.h"
#include <string>

class Rectangle : public IShape {
    double length;
    double breadth;

public:
    Rectangle(double currLen, double currBreadth) 
    : length{currLen}, breadth{currBreadth} {}

    double getArea() override;
    double getPerimeter() override;
    std::string getName() override {
        return "Rectangle";
    }
};

#endif