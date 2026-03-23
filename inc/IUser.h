#ifndef IUSER_H
#define IUSER_H

#include <string>
#include "Constants.h"

class IUser {
public:
    virtual bool authenticate(const std::string& credential1, 
                            const std::string& credential2) = 0;

    virtual void displayInformation() = 0;
};

#endif
