#include "Arriving_event.h"
#include "Simulation.h"
#include "Train.h"

Arriving_event::Arriving_event(Simulation *sim, int time, const Train &t)
    : Event{time}, railway_sim{sim}, tr{t} {}

void Arriving_event::do_event()
{
    if (tr.getNext().get_type() == "principale" || (tr.getNext().get_type() == "locale" && tr.get_type() == 1))
    {
        if (tr.getNext().has_space())
        {
            tr.CambioVel(80);
            double t = time + (5 / 80) * 60; //tempo in minuti all'arrivo in stazione
            railway_sim.schedule_event(new Stopping_event(railway_sim, t, tr));
        }
        else
        {
            tr.getNext().add_to_parking(tr);
            //railway_sim.schedule_event(new park_train_event(/*parametri per l'evento parcheggio treno*/));
        }
    }
    else
    {
        double t = time + (5 / tr.get_vel()) * 60; //tempo in minuti al passaggio in stazione a velocita massima
        railway_sim.schedule_event(new Transiting_event(railway_sim, t, tr));
    }
}