//AUTORE: Alberto Penzo

#ifndef ARRIVING_EVENT_H
#define ARRIVING_EVENT_H

#include "Event.h"
#include "Simulation.h"
#include "Station.h"
#include "Treno.h"
#include "Transiting_event.h"
#include "Stopping_event.h"
#include <iostream>

class Arriving_event : public Event
{
public:
    Arriving_event(Simulation *sim, int time, const Treno &t);

    virtual void do_event();

private:
    Treno tr;
    Simulation *railway_sim;
};

#endif