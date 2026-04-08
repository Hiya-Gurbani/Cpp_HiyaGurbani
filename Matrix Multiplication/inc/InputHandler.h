#ifndef INPUT_HANDLER_H
#define INPUT_HANDLER_H

#include "IInputHandler.h"

class InputHandler : public IInputHandler {
public: 
    int inputDimension() override;
    double inputElement() override; 
    char inputChoice() override;
};

#endif
