#ifndef TRAFFIC_CONTROLLER_H
#define TRAFFIC_CONTROLLER_H

#include "ITrafficController.h"
#include "TrafficState.h"
#include "Lane.h"
#include <vector>
#include <semaphore.h>
#include <atomic>

class TrafficController : public ITrafficController {

    TrafficState* trafficState;
    std::vector<Lane> orderedLaneCycle;
    int activeLaneIndex;

    sem_t phaseSemaphore;
    std::atomic<bool> isCyclingActive;

    void initializeLanes();
    void activateNextPhase();
    void countDownCurrentPhase();

public:
    TrafficController(TrafficState* trafficState);
    ~TrafficController();

    const std::vector<Lane>& getOrderedLaneCycle() {
        return orderedLaneCycle;
    }

    void startTrafficCycle() override;
    void stopTrafficCycle() override;
};

#endif
