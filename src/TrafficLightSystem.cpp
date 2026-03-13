#include "TrafficLightSystem.h"
#include "Constants.h"

TrafficLightSystem::TrafficLightSystem(ITrafficController* trafficController,
    IUserController* userController, IInputHandler* inputHandler, ILogger* logger
)
    : trafficController(trafficController), userController(userController),
    inputHandler(inputHandler), logger(logger) {}

void TrafficLightSystem::start() {
    logger->printMessage(Constants::MSG_WELCOME);
    logger->printMessage(Constants::MSG_ROAD);

    controllerThread = std::thread(&ITrafficController::startTrafficCycle, trafficController);

    inputThread = std::thread(&IUserController::startHandlingUserQueries, userController);

    inputThread.join();

    stop();
}

void TrafficLightSystem::stop() {
    trafficController->stopTrafficCycle();
    if (controllerThread.joinable()) 
    {
        controllerThread.join();
    }
}

TrafficLightSystem::~TrafficLightSystem() {
    stop();
}
