#ifndef USER_MANAGER_H
#define USER_MANAGER_H

#include "ILogger.h"
#include <string>

class UserManager {
    ILogger* logger;

public:
//Doesn't creates its own but receives from outside
    UserManager(ILogger* newLogger) : logger(newLogger) {}

    void createUser(const std::string& name) {
        logger->log("User created: " + name);
    }
};

#endif
