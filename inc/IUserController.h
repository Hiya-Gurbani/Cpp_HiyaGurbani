#ifndef I_USER_CONTROLLER_H
#define I_USER_CONTROLLER_H

#include "IInputHandler.h"
#include "ILogger.h"
#include "ITrafficController.h"
#include "MoveAdvisor.h"
#include "MoveResult.h"
#include "Constants.h"
#include <atomic>
#include <string>

class IUserController {
public:
    virtual void handleUserQueries() = 0;
    virtual ~IUserController() {};
};

#endif

