#include <iostream>

class Shape {
public:
    virtual void draw() {
        std::cout << "Drawing a generic shape" << "\n";
    }
    
    virtual double area() = 0;  //Pure virtual function
    
    virtual ~Shape() {}  //Virtual destructor
};

class Circle : public Shape {
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    void draw() override {
        std::cout << "Drawing a circle" << "\n";
    }
    
    double area() override {
        return 3.14 * radius * radius;
    }
};

class Rectangle : public Shape {
    double width, height;
public:
    Rectangle(double w, double h) : width(w), height(h) {}
    
    void draw() override {
        std::cout << "Drawing a rectangle" << "\n";
    }
    
    double area() override {
        return width * height;
    }
};

int main() {
    Shape* shape1 = new Circle(5.0);
    Shape* shape2 = new Rectangle(4.0, 6.0);

    shape1->draw();  //calls circle's draw 

    delete shape1;
    delete shape2;
}