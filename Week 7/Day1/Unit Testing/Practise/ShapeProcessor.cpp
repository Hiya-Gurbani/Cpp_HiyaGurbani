#include "ShapeProcessor.h"
#include "IShape.h"
#include "Circle.h"
#include "Rectangle.h"

IShape* ShapeProcessor::createShape(const std::string& type, double dim1, double dim2) {
    IShape* shape = nullptr;

    if (type == "Circle") {
        shape = new Circle(dim1);
    } 
    else if (type == "Rectangle") {
        shape = new Rectangle(dim1, dim2);
    }
    
    return shape;
}
