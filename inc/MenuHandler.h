#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#include "Matrix.h"

class MenuHandler {
    static Matrix performMatrixAddition();
    static Matrix performMatrixMultiplication();

public:
    static bool handleChoice(int choice);
};

#endif