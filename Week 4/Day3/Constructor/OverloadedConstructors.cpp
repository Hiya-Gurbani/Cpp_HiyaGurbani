#include <iostream>

class Triangle {
    int length1;
    int length2;
    int length3;

    public:
    Triangle() {
        std::cout << "Lengths are: " << length1 << " " << length2 << " "  << length3
        << "\n";
    }

    //Ambiguous because it is default
    // Triangle(int tlength1 = 1, int tlength2 = 3, int tlength3 = 5)
    // : length1{tlength1}, length2{tlength2}, length3{tlength3}
    // {
    //     std::cout << "Lengths are: " << length1 << " " << length2 << " "  << length3
    //     << "\n";
    // }

    Triangle(int tlength1, int tlength2, int tlength3 = 5)
    : length1{tlength1}, length2{tlength2}, length3{tlength3}
    {
        std::cout << "Lengths are: " << length1 << " " << length2 << " "  << length3
        << "\n";
    }

    //Overloading of const is done when we have reference or pointers
    // Triangle(const int tlength1, int tlength2 = 3, int tlength3 = 5)
    // : length1{tlength1}, length2{tlength2}, length3{tlength3}
    // {
    //     std::cout << "Lengths are: " << length1 << " " << length2 << " "  << length3
    //     << "\n";
    // }
};

int main() {
    Triangle triangle1{2, 4, 10};
    Triangle triangle2{3, 4}; //Uses def arg for 3rd
    Triangle triangle3; 
    // Triangle triangle4{3};
}