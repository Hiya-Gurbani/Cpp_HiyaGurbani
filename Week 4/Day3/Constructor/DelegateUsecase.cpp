#include <iostream>

//Can't do using Default Arguments

class Triangle {
    int angle1;
    int angle2;
    int angle3;

public:
    Triangle(int tangle1, int tangle2, int tangle3)
        : angle1(tangle1), angle2(tangle2), angle3(tangle3) {
        std::cout << angle1 << " " << angle2 << " " << angle3 << "\n";
    }

    Triangle(int tangle1, int tangle2)
        : Triangle(tangle1, tangle2, 180 - (tangle1 + tangle2)) {}
};

int main() {
    Triangle triangle1 {90, 45};
}