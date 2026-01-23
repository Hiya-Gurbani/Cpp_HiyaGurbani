#include <iostream>
using namespace std;

int& getLargerNumber(int &firstNumber, int &secondNumber) {
    return (firstNumber > secondNumber) ? firstNumber : secondNumber;
}

int main() {
    int num1 = 10;
    int num2 = 20;

    // Reference to larger number
    int &largerNumber = getLargerNumber(num1, num2);

    largerNumber = 30;

    cout << "After modification:" << endl;
    cout << "num1 = " << num1 << ", num2 = " << num2 << endl;

    return 0;
}
