#include <iostream>

struct Rectangle {
    int length;
    int breadth;

    int perimeter() {
        return (2 * (length + breadth));
    }
};

int main() {
    Rectangle rectangle = {10, 20};
    std::cout << sizeof(Rectangle) << "\n";
    std::cout << sizeof(rectangle) << "\n"; 
    std::cout << rectangle.perimeter();
    return 0;
}