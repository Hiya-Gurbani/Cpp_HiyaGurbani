#include <iostream>

class IntPair {
    int value1;
    int value2;

    public:
    IntPair(int num1, int num2)
        : value1 { num1 }, value2 { num2 } {
    }

    int getValue1() {
        return value1;
    }
    int getValue2() {
        return value2;
    }
};

void print(IntPair p) {
    std::cout << "(" << p.getValue1() << ", " << p.getValue2() << ")\n";
}

int main() {

    IntPair p { 3, 4 };
    print(p);

    // Case 2: Construct temporary IntPair and pass to function
    print(IntPair { 5, 6 } );

    // Case 3: Implicitly convert { 7, 8 } to a temporary Intpair and pass to function
    print( { 7, 8 } );
}