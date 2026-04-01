#ifndef I_INPUT_HANDLER_H
#define I_INPUT_HANDLER_H

class IInputHandler {
public: 
    virtual int inputDimension() = 0;
    virtual double inputElement() = 0; 
    virtual char inputChoice() = 0;

    virtual ~IInputHandler() {}
};

#endif
