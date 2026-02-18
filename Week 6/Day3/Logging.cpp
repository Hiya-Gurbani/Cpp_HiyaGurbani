#include <iostream>
#include <vector>

int divide(int num1, int num2) {
    return num1 / num2; //Bug 1: If num2 == 0
}

int sumVector(std::vector<int>& v) {
    int total = 0;
    for (int index = 0; index <= v.size(); index++) //Bug 2: Out-of-bounds
    {
        total += v[index];
    }

    return total;
}

int main() {
    std::vector<int> numbers = {10, 20, 30};

    int result1 = divide(10, 2);
    std::cout << "Division Result: " << result1 << "\n";
    
    int result2 = sumVector(numbers);
    std::cout << "Sum Result: " << result2 << "\n";

    return 0;
}