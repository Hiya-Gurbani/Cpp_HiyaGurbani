#include <iostream>

class Point {
    private:
    int xCordinate;
    int yCordinate;
    int zCordinate;

    public:
    void setPoint(int x, int y, int z) {
        xCordinate = x;
        yCordinate = y;
        zCordinate = z;
    }

    void getPoint() {
        std::cout << "Point is: " << xCordinate << "," 
        << yCordinate << "," << zCordinate << "\n";
    }

    bool isEqual(const Point& p) {
        return (p.xCordinate == xCordinate) && (p.yCordinate == yCordinate) &&
        (p.zCordinate == zCordinate);
    }
};

int main() {
    Point point1;
    point1.setPoint(12, 51, 3);
    point1.getPoint();

    Point point2;
    point2.setPoint(12, 51, 3);
    point2.getPoint();

    std::cout << "Point 1 and Point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

    point2.setPoint(1, 51, 3);
    std::cout << "Point 1 and Point 2 are" << (point1.isEqual(point2) ? "" : " not") << " equal\n";

}