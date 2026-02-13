#include <iostream>

class Point {
    int x, y;

public:
    Point(int x, int y) : x(x), y(y) {}

    friend std::ostream& operator<<(std::ostream& os, const Point& p);
};

std::ostream& operator<<(std::ostream& os, const Point& p) {
    os << "(" << p.x << ", " << p.y << ")";
    return os;  
}

int main() {
    Point p(2, 3);
    std::cout << p << "\n";
}
