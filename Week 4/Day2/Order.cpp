#include <iostream>

//The order doesn't matter we can use data members and memeber fucntions before 
//they are defined
struct Foo {
    int z() {
        return data;
    }

    int x() {
        return y();
    }

    int data = y();

    int y() {
        return 5;
    }
};

//But data members should be initialised in order of decalration
struct Initialise {
    int num2 = num1;
    int num3 = valueFunction();

    int num1 = 5;

    int valueFunction()
    {
        return num1;
    }
};

int main() {
    Foo f;
    Initialise init;

    //num2 and num3 are 0 : Undefined Behavior
    std::cout << init.num1 << " " << init.num2 << " " << init.num3 << "\n";
}