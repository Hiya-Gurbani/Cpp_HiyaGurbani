#ifndef TRAFFIC_LIGHT_SYSTEM_FACTORY_H
#define TRAFFIC_LIGHT_SYSTEM_FACTORY_H

#include "TrafficLightSystem.h"

class TrafficLightSystemFactory {
public:
    TrafficLightSystem* create();
    ~TrafficLightSystemFactory();
};

#endif
