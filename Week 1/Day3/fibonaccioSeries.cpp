#include <iostream>

void fibonaccioSeries(int number) {
    int a = 0, b = 1, c = 0; //first, second and next

    for (int i = 0; i < number; i++)
    {
        std::cout << c << " ";
        
        a = b;
        b = c;
        c = a + b;
    }
}

int fibonaccio(int count) {
    if (count == 0)
    {
        return 0;
    }
    if (count == 1)
    {
        return 1;
    }
    return fibonaccio(count - 1) + fibonaccio(count - 2);
} 

int main() {
    int number;
    std::cin >> number;

    fibonaccioSeries(number);
    std::cout << std::endl;
    for (int i = 0; i < number; i++)
    {
        std::cout << fibonaccio(i) << " ";
    }
}