#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"
#include <iostream>
#include <dlfcn.h>
#include <optional>

namespace operation
{
    using arithmeticFunction = double(*)(double, double);
}

enum class ExitStatus {
    CONTINUE,
    USER_EXIT,
    ERROR_EXIT
};

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
        else if (choice < 1 || choice > 5) 
        {
            std::cout << "Choice must be between 1 and 5. Enter again: ";
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

std::optional<double> performOperation(const char* functionName, double operand1, double operand2) {
    std::optional<double> result = std::nullopt;
    
    void* handle = loadLibrary();
    if (handle)
    {
        operation::arithmeticFunction operationFunction = 
                                        loadFunction(handle, functionName);
        if (operationFunction)
        {
            result = operationFunction(operand1, operand2);
        }
        dlclose(handle);
    }

    return result;
}

bool handleOperation(const char* functionName) {
    double operand1, operand2;
    bool shouldContinue = false;

    getInputOperands(operand1, operand2);
    std::optional<double> result = performOperation(functionName, operand1, operand2);

    if (result.has_value())
    {
        printResult(result.value());
        shouldContinue = true;
    }
    
    return shouldContinue;
}

bool handleDivision() {
    bool shouldContinue = false;
    double operand1, operand2;
    getInputOperands(operand1, operand2);

    if (operand2 == 0)
    {
        std::cout << "Error: Division by zero is not allowed.\n";
    }
    else
    {
        std::optional<double> result = 
                                performOperation("divideOperands", operand1, operand2);

        if (result.has_value())
        {
            printResult(result.value());
            shouldContinue = true;
        }
    }

    return shouldContinue;
}

ExitStatus handleChoice(unsigned int choice) {
    ExitStatus status = ExitStatus::CONTINUE;

    switch (choice) 
    {
        case 1:
        if (!handleOperation("addOperands"))
        {
            status = ExitStatus::ERROR_EXIT;
        }
        break;

        case 2:
        if (!handleOperation("subtractOperands"))
        {
            status = ExitStatus::ERROR_EXIT;
        }
        break;

        case 3:
        if (!handleOperation("multiplyOperands"))
        {
            status = ExitStatus::ERROR_EXIT;
        }
        break;

        case 4:
        if (!handleDivision())
        {
            status = ExitStatus::ERROR_EXIT;
        }
        break;
        
        case 5:
        status = ExitStatus::USER_EXIT;
        break;

        default:
        std::cout << "Invalid Choice! Choice must be in range of 1 to 5.\n";
    }

    return status;
}

int main() {
    unsigned int choice;
    ExitStatus status;

    while (true) 
    {
        printMenu();

        std::cout << "\nEnter your choice: ";
        choice = getChoice();

        status = handleChoice(choice);

        if (status != ExitStatus::CONTINUE)
        {
            std::cout << "Exiting Program...\n";
            break;
        }
    }

    return (status == ExitStatus::ERROR_EXIT) ? 1 : 0;
}