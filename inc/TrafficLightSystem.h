#ifndef TRAFFIC_LIGHT_SYSTEM_H
#define TRAFFIC_LIGHT_SYSTEM_H

#include "ITrafficController.h"
#include "IUserController.h"
#include "InputHandler.h"
#include "ILogger.h"
#include <thread>

class TrafficLightSystem {
    IInputHandler* inputHandler;
    ILogger* logger;
    ITrafficController* trafficController;
    IUserController* userController;

    std::thread controllerThread;
    std::thread inputThread;
    
    void stop();

public:
    TrafficLightSystem( ITrafficController* controller, 
        IInputHandler* inputHandler, ILogger* logger);

    void start();

    ~TrafficLightSystem();
};

#endif
