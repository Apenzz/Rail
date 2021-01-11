//AUTORE: Alberto Penzo

#include "Simulation.h"

Simulation::Simulation()
    : time{0}, event_queue{} {}

void Simulation::run()
{
    while (!event_queue.empty())
    {
        Event *next_event = event_queue.top();
        event_queue.pop();
        time = next_event->get_time();
        next_event->do_event();
        delete next_event;
    }
}

void Simulation::schedule_event(Event *new_event)
{
    event_queue.push(new_event);
}