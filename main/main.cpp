#include "TrafficLightSystemFactory.h"
#include "TrafficLightSystem.h"

int main()
{
    TrafficLightSystemFactory factory;
    TrafficLightSystem* system = factory.create();
    system->start();
    delete system;
    return 0;
}
