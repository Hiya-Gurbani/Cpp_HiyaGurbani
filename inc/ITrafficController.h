#ifndef ITRAFFIC_CONTROLLER_H
#define ITRAFFIC_CONTROLLER_H

#include "Constants.h"
#include "Lane.h"
#include <vector>

class ITrafficController {
public:
    virtual void startTrafficCycle() = 0;
    virtual void stopTrafficCycle() = 0;
    virtual ~ITrafficController() {}
};

#endif
