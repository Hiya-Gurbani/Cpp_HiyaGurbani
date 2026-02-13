#ifndef IBANK_H
#define IBANK_H

#include "Constants.h"

class IBank {
public:
    virtual ~IBank() = default;
    virtual void handleMenu() = 0;
    virtual bool handleChoice(int choice) = 0;
    virtual bool login(Constants::UserRole role) = 0;
    virtual void logout() = 0;
};

#endif
