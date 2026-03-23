#include "AdminLoginHandler.h"
#include "Display.h"
#include "Logger.h"
#include "InputHandler.h"

bool AdminLoginHandler::getAndVerifyCredentials() {
    std::string userName;
    Display::printMessage(Logger::MSG_ENTER_USERNAME);
    InputHandler::inputString(userName, Constants::InputType::USERNAME);

    std::string password;
    Display::printMessage(Logger::MSG_ENTER_PASSWORD);
    InputHandler::inputString(password, Constants::InputType::PASSWORD);

    return admin.authenticate(userName, password);
}

Constants::LoginResult AdminLoginHandler::login() {
    Constants::LoginResult result = Constants::LoginResult::FAILED;

    Display::printMessage(Logger::MSG_ADMIN_LOGIN);

    if (getAndVerifyCredentials())
    {
        result = Constants::LoginResult::SUCCESS;
        Display::printMessage(Logger::MSG_LOGIN_SUCCESS);
        if (!adminController->handleMenu())
        {
            logout();
        }
    }

    return result;
}

void AdminLoginHandler::logout() {
    Display::clearScreen();
    Display::printMessage(Logger::MSG_LOGOUT);
}
