#ifndef USER_H
#define USER_H

#include "IUser.h"
#include "Constants.h"

class User : public IUser {
protected:
    std::string name;
    Constants::UserRole role;

public:
    std::string getName() {
        return name;
    }

    Constants::UserRole getRole() {
        return role;
    }

    void setName(std::string& name) { 
        this->name = name; 
    }
};

#endif
