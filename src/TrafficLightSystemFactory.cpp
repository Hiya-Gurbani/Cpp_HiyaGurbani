#include "TrafficLightSystemFactory.h"
#include "TrafficController.h"
#include "UserController.h"
#include "InputHandler.h"
#include "Logger.h"

TrafficLightSystem* TrafficLightSystemFactory::create()
{
    ILogger* logger = new Logger();
    IInputHandler* inputHandler = new InputHandler(logger);
    ITrafficController* trafficController = new TrafficController();
    UserController* userController = new UserController(inputHandler, logger, trafficController);

    return new TrafficLightSystem(trafficController, userController, logger);
}

~TrafficLightSystemFactory() {
    delete userController;
    delete trafficController;
    delete inputHandler;
    delete logger;          
}
