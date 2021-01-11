#include "Transiting_event.h"


Transiting_event::Transiting_event(Simulation* sim, int time, const Train& treno)
	: Event{ time }, railway_simulation{ sim }, tr{ treno }	{}


void Transiting_event::do_event()
{	
	railway_simulation.schedule_event(new Starting_event(railway_simulation, time, tr));			//fa partire subito l'evento partenza treno(dato che è solo passato le velocità non cambiano)
}
