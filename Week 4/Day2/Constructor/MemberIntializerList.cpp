#include <iostream>

class Rectangle {
    int length;
    int breadth;

    public:
    Rectangle(int l, int b)
        : length {l}, breadth {b}
        {
            std::cout << length << " " << breadth << "\n";
        }
};

int main() {
    Rectangle rect(10, 12);
}