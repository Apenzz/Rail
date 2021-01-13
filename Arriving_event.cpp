//AUTORE: Alberto Penzo

#include "Arriving_event.h"

Arriving_event::Arriving_event(Simulation *sim, int time, const Treno &t)
    : Event{time}, railway_sim{sim}, tr{t} {}

void Arriving_event::do_event()
{
    if (tr.getNext()->get_type() == "principale" || (tr.getNext()->get_type() == "locale" && tr.get_type() == 1))
    {
        if (tr.getNext()->has_space())
        {
            tr.CambioVel(80);
            std::cout <<"COMUNICAZIONE "<< tr.getCodice() << " in arrivo alla stazione " << tr.getNext()->get_name() << std::endl;
            
            double dt = ((5.0 / 80) * 60);

            //std::cout << "Arriving calc: " << time + dt+1 << std::endl;
            railway_sim->schedule_event(new Stopping_event(railway_sim, time+dt+1, tr));
        }
        else
        {
            tr.getNext()->add_to_parking(tr);
        }
    }
    else
    {
        double t = time + (5.0 /tr.getVel()) * 60; //tempo in minuti al passaggio in stazione a velocita massima
        railway_sim->schedule_event(new Transiting_event(railway_sim, t, tr));
    }
}   