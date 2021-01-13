//AUTORE: Alessio Gottardo

#include "Transiting_event.h"

Transiting_event::Transiting_event(Simulation* sim, int time, const Treno& treno)
	: Event{ time }, railway_simulation{ sim }, tr{ treno }	{}


void Transiting_event::do_event()
{	
	tr.Incremento();
	std::cout << "COMUNICAZIONE: il treno " << tr.getCodice() << " è in transito attraverso la stazione: " << tr.getCurrent()->get_name() << std::endl;
	railway_simulation->schedule_event(new Starting_event(railway_simulation, time, tr));			//fa partire subito l'evento partenza treno(dato che è solo passato le velocità non cambiano)
}
