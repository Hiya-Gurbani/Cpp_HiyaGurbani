#include <iostream>
#include <string>
#include "IShape.h"
#include "ShapeProcessor.h"

IShape* getShapeFromUser(ShapeProcessor& processor) {
    int choice;
    std::cout << "\nSelect a shape:" << "\n";
    std::cout << "1. Circle" << "\n";
    std::cout << "2. Rectangle" << "\n";
    std::cout << "3. Exit" << "\n";
    std::cout << "Enter choice: ";
    std::cin >> choice;

    IShape* shape = nullptr;

    if (choice == 1) {
        double radius;
        std::cout << "Enter radius: ";
        std::cin >> radius;
        shape = processor.createShape("Circle", radius);
    }
    else if (choice == 2) {
        double width, height;
        std::cout << "Enter width: ";
        std::cin >> width;
        std::cout << "Enter height: ";
        std::cin >> height;
        shape = processor.createShape("Rectangle", width, height);
    }
    else if (choice == 3) {
        return nullptr;   
    }
    else {
        std::cout << "Invalid choice." << "\n";
    }

    return shape;
}

void displayShapeInfo(IShape* shape) {
    if (shape == nullptr) 
    {
        return;
    }

    std::cout << "--------------------" << "\n";
    std::cout << "Shape:     " << shape->getName() << "\n";
    std::cout << "Area:      " << shape->getArea() << "\n";
    std::cout << "Perimeter: " << shape->getPerimeter() << "\n";
    std::cout << "--------------------" << "\n";
}

int main() {
    ShapeProcessor processor;

    while (true) {
        IShape* shape = getShapeFromUser(processor);

        if (shape == nullptr) {
            std::cout << "Goodbye!" << "\n";
            break;
        }

        displayShapeInfo(shape);

        delete shape;   
    }

    return 0;
}