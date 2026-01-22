#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>
#include <dlfcn.h>

void printMenu() {
    std::cout << "\nOperations: \n";
    std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n";
}

void getInputoperands(double& operand1, double& operand2) {
    std::cout << "Enter first operand: ";
    //getValidDouble();
    std::cin >> operand1;

    std::cout << "Enter second operand: ";
    //getValidDouble();
    std::cin >> operand2;
}

void printResult(double result) {
    std::cout << "Result: " << result << "\n";
}

namespace ops
{
    using ArithmeticFunc = double(*)(double, double);
}


void* loadLibrary() {
    void* handle = dlopen("./liboperations.so", RTLD_LAZY);
    if (!handle)
    {
        std::cerr << "Cannot Load Library: " << dlerror() << "\n";
        exit(1);
    }

    return handle;
}

ops::ArithmeticFunc resolveOperation(void* handle, const char* functionName) {
    dlerror();
    ops::ArithmeticFunc operationFunction = (ops::ArithmeticFunc)dlsym(handle, functionName);

    char* error = dlerror();
    if (error)
    {
        std::cerr << "Cannot Find Function: " << error << "\n";
        dlclose(handle);
        exit(1);
    }

    return operationFunction;
}

double performOperation(double operand1, double operand2, const char* functionName) {
    void* handle = loadLibrary();

    ops::ArithmeticFunc operationFunction = resolveOperation(handle, functionName);

    double result = operationFunction(operand1, operand2);
    dlclose(handle);

    return result;
}

bool handleChoice(unsigned int choice) {
    double result;
    bool isDivideByZero = false;

    switch (choice) 
    {
        double operand1, operand2;

        case 1:
        getInputoperands(operand1, operand2);
        result = performOperation(operand1, operand2, "addOperands");
        break;

        case 2:
        getInputoperands(operand1, operand2);
        result = performOperation(operand1, operand2, "subtractOperands");
        break;

        case 3:
        getInputoperands(operand1, operand2);
        result = performOperation(operand1, operand2, "multiplyOperands");
        break;

        case 4:
        getInputoperands(operand1, operand2);

        if (operand2 == 0)
        {
            isDivideByZero = true;
        }
        else
        {
            result = performOperation(operand1, operand2, "divideOperands");
        }
        break;
        
        case 5:
        return false;

        // default:
        // std::cout << "Choice must be between 1 to 5. Enter again: ";
    }

    if (isDivideByZero)
    {
        std::cout << "Error: Division by zero is not allowed.\n";
    }
    else
    {
        printResult(result);
    }

    return true;
}

int main() {
    unsigned int choice;

    while (true) 
    {
        std::string input;
        printMenu();
        std::cout << "\nEnter your choice: ";
        //std::getline(std::cin, input);
        //if (isValidChoice(input))
        //{
            // break;
        //}
        std::cin >> choice;

        if (!handleChoice(choice))
        {
            std::cout << "Exiting Program...\n";
            return 0;
        }
    }

}