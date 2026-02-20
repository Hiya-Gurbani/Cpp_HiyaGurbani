#include "Rectangle.h"

double Rectangle::getArea() {
    return length * breadth;
}

double Rectangle::getPerimeter() {
    return 2 * (length + breadth);
}

