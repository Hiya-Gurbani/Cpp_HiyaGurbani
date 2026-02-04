#include <iostream>

class Triangle {
    int length1;
    int length2;
    int length3;

    public:
    Triangle(int tlength1, int tlength2, int tlength3 = 5)
    : length1{tlength1}, length2{tlength2}, length3{tlength3}
    {
        std::cout << "Lengths are: " << length1 << " " << length2 << " "  << length3
        << "\n";
    }
};

int main() {
    Triangle triangle1{2, 4, 10};
    Triangle triangle2{3, 4}; //Uses def arg for 3rd

    //Error: No Matching Fucntion
    // Triangle triangle3; 
    // Triangle triangle3{3};
}