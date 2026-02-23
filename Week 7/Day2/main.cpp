#include "ConsoleLogger.h"
#include "UserManager.h"

int main() {
    ConsoleLogger realLogger;
    UserManager manager(&realLogger);

    manager.createUser("Alice");

    return 0;
}