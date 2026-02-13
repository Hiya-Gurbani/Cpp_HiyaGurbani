#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "Validator.h"
#include <string>

class InputHandler {
public:
    static double& inputValue(double& value);
    static int& inputValue(int& value);
    static void removeLeadingAndTrailingWhitespaces(std::string& input);
    static void inputString(std::string& input);                          
};

#endif
