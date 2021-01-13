//AUTORE: Alberto Penzo

#ifndef SIMULATION_H
#define SIMULATION_H

#include "Event.h"
#include "eventComparatorCriterial.h"
#include <queue>
#include <vector>
#include <memory>

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