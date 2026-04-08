#ifndef I_MOCK_INPUT_HANDLER_H
#define I_MOCK_INPUT_HANDLER_H


#include "../../inc/IInputHandler.h"
#include <gmock/gmock.h>

class IMockInputHandler : public IInputHandler {
public:
    MOCK_METHOD(int, inputDimension, (), (override));
    MOCK_METHOD(double, inputElement, (), (override));
    MOCK_METHOD(char, inputChoice, (), (override));
};

#endif
