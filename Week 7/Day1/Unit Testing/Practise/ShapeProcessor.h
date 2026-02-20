#ifndef SHAPE_PROCESSOR_H
#define SHAPE_PROCESSOR_H

#include "IShape.h"
#include <string>

class ShapeProcessor {
public:
    IShape* createShape(const std::string& type, double dim1, double dim2 = 0);
};

#endif
