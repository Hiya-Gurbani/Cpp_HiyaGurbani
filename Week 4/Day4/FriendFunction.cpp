#include <iostream>

class Box;

class Display {
public:
    void showBox(const Box& b);
};

class Box {
private:
    double width;
    double height;
    
public:
    Box(double w, double h) 
    : width(w), height(h) {
    }
    
    // Friend function declaration inside the class
    // Its both friend and forward declaration of fucntion
    friend double calculateArea(const Box& b);
    
    // Friend function from another class
    //Can't introduce this
    friend void Display::showBox(const Box& b);
};

void Display::showBox(const Box& b) {
    std::cout << b.width << " " << b.height << "\n";  
}

double calculateArea(const Box& b) {
    //Access private members width and height
    return b.width * b.height;
}

int main() {
    Box myBox(5.0, 3.0);
    std::cout << "Area: " << calculateArea(myBox);  // Works fine
}