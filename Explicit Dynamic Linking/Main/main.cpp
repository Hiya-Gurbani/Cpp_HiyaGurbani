#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>
#include <dlfcn.h>

namespace operation
{
    using arithmeticFunction = double(*)(double, double);
}

void printMenu() {
    std::cout << "\nOperations: \n";
    std::cout << "1. Addition\n2. Subtraction\n3. Multiplication\n4. Division\n5. Exit\n";
}

unsigned int getChoice() {
    unsigned int choice;

    while (true)
    {
        std::cin >> choice;
        if (std::cin.fail()) 
        {
            std::cin.clear();
            while (getchar() != '\n');
            std::cout << "Invalid Input. Kindly enter a number: ";
        }
        else
        {
            break;
        }   
    }

    return choice;
}

double getOperand() {
    double operand;

    while (true)
    {
        std::cin >> operand;
        if (std::cin.fail()) 
        {
            std::cin.clear();
            while (getchar() != '\n');
            std::cout << "Invalid Input. Kindly enter a number: ";
        }
        else
        {
            break;
        }   
    }

    return operand;
}

void getInputOperands(double& operand1, double& operand2) {
    std::cout << "Enter first operand: ";
    operand1 = getOperand();

    std::cout << "Enter second operand: ";
    operand2 = getOperand();
}

void printResult(double result) {
    std::cout << "Result: " << result << "\n";
}

void* loadLibrary() {
    void* handle = dlopen("./liboperations.so", RTLD_LAZY);
    if (!handle)
    {
        std::cerr << "Cannot Load Library: " << dlerror() << "\n";
    }

    return handle;
}

operation::arithmeticFunction loadFunction(void* handle, const char* functionName) {
    dlerror();
    operation::arithmeticFunction operationFunction = 
                            (operation::arithmeticFunction)dlsym(handle, functionName);

    char* error = dlerror();
    if (error)
    {
        std::cerr << "Cannot Find Function: " << error << "\n";
        dlclose(handle);
        operationFunction = nullptr;
    }

    return operationFunction;
}

double performOperation(const char* functionName, double operand1, double operand2) {
    void* handle = loadLibrary();
    if (!handle)
    {
        return 0;
    }

    operation::arithmeticFunction operationFunction = 
                                        loadFunction(handle, functionName);
    if (!operationFunction)
    {
        return 0;
    }

    double result = operationFunction(operand1, operand2);
    dlclose(handle);

    return result;
}

void handleOperation(const char* functionName) {
    double operand1, operand2;

    getInputOperands(operand1, operand2);
    double result = performOperation(functionName, operand1, operand2);
    printResult(result);
}

void handleDivision() {
    double operand1, operand2;
    getInputOperands(operand1, operand2);

    if (operand2 == 0)
    {
        std::cout << "Error: Division by zero is not allowed.\n";
    }
    else
    {
        double result = performOperation("divideOperands", operand1, operand2);
        printResult(result);
    }
}

bool handleChoice(unsigned int choice) {
    switch (choice) 
    {
        case 1:
        handleOperation("addOperands");
        break;

        case 2:
        handleOperation("subtractOperands");
        break;

        case 3:
        handleOperation("multiplyOperands");
        break;

        case 4:
        handleDivision();
        break;
        
        case 5:
        return false;

        default:
        std::cout << "Invalid Choice! Choice must be in range of 1 to 5.\n";
    }

    return true;
}

int main() {
    unsigned int choice;

    while (true) 
    {
        printMenu();

        std::cout << "\nEnter your choice: ";
        choice = getChoice();

        if (!handleChoice(choice))
        {
            std::cout << "Exiting Program...\n";
            return 0;
        }
    }

    return 0;
}