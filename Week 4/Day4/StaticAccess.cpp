#include <iostream>

class MathUtils {
    static int multiplier;
    int value = 5;
    
public:
    static void setMultiplier(int m) {
        multiplier = m;  // Can access static variables
        // value++; Can't access non-static members
    }

    static int square(int x) {
        return x * x; 
    }

    int square() {
        return multiplier * value; // Can access both static and non-static
    }
};

int MathUtils::multiplier;

int main() {
    std::cout << MathUtils::square(10) << "\n";
    MathUtils::setMultiplier(5); //Need to define multiplier
}