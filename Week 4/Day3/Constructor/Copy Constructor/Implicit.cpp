#include <iostream>

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    Fraction(int currNumerator = 0, int currDenominator = 1)
        : numerator{currNumerator}, denominator{currDenominator}
    {
    }

    void print()
    {
        std::cout << "Fraction(" << numerator << ", " << denominator << ")\n";
    }
};

int main()
{
    Fraction fraction {5, 3};
    Fraction fCopy {fraction}; 

    fraction.print();

    //Implicit 
    fCopy.print();

    return 0;
}