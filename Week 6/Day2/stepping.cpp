#include <iostream>

int square(int number) {
    int result = number * number;
    return result;
}

int cube(int number) {
    int result = number * number * number;
    return result;
}

double average(int a, int b, int c) {
    int sum = a + b + c;
    double average = average / 3.0;
    return average;
}


int main() {
    int a = 4;
    int b = 3;
    int c = 7;

    int sq  = square(a);     // use next here → square is executed but we never enter it
    int cu  = cube(b);       // same here . so use step -> to enter the function
    double avg = average(a, b, c);

    return 0;
}

// Used next, step, finish and until