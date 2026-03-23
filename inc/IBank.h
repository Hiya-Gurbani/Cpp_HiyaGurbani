#ifndef IBANK_H
#define IBANK_H

#include "Constants.h"
#include <string>
#include <vector>

class Customer; 

class IBank {
public:
    virtual ~IBank() {};
    
    virtual void handleMenu() = 0;
    virtual bool login(Constants::UserRole role) = 0;
};

#endif
