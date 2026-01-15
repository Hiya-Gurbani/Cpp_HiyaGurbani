#include <iostream>
using namespace std;

int globalVariable = 100;

void displayVariable() {
    int localVariable = 10;

    static int staticVariable = 50;

    cout << "Local variable: " << localVariable << "\n";
    cout << "Static variable: " << staticVariable << "\n";

    localVariable += 5;
    staticVariable += 5;
}

int main() {
    cout << "Global variable: " << globalVariable << "\n";

    cout << "\nFirst: " << endl;
    displayVariable();

    cout << "\nSecond: " << endl;
    displayVariable();

    cout << "\nThird: " << endl;
    displayVariable();

    return 0;
}
