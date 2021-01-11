#ifndef SIMULATION_H
#define SIMULATION_H

#include "Event.h"
#include "eventComparatorCriterial.h" //da definire in un altro file
#include <queue>
#include <vector>

class Simulation
{
public:
    Simulation();

    void run();

    void schedule_event(Event *new_event);

private:
    std::priority_queue<Event *, std::vector<Event *, std::allocator<Event *>>, eventComparatorCriterial> event_queue;
    double time;
};

#endif