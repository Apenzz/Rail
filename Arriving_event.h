#ifndef ARRIVING_EVENT_H
#define ARRIVING_EVENT_H

#include "Event.h"

class Arriving_event : public Event
{
public:
    Arriving_event(Simulation *sim, int time, const Train &t);

    virtual void do_event();

private:
    Train tr;
    Simulation *railway_sim;
};

#endif