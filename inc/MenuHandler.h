#ifndef MENU_HANDLER_H
#define MENU_HANDLER_H

#include "Matrix.h"

class MenuHandler {
    Matrix performMatrixAddition();
    Matrix performMatrixMultiplication();

public:
    bool handleChoice(int choice);
};

#endif
