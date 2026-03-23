#ifndef ILOGIN_HANDLER_H
#define ILOGIN_HANDLER_H

#include "Constants.h"

class ILoginHandler {
public:
    virtual Constants::LoginResult login() = 0;
    virtual void logout() = 0;
    virtual ~ILoginHandler() {}
};

#endif
