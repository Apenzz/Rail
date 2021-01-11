#include "Stopping_event.h"


Stopping_event::Stopping_event(Simulation* sim, int time, const Train& treno)
	: Event{ time }, railway_simulation{ sim }, tr{ treno }	{}


void Stopping_event::do_event()
{
	int stopping_time = 5;					//tempo salita/discesa passeggeri
	int time_diff = (tr.timetable_time() - time);

	if (time_diff < 0)					//se la differenza tra tempo previsto e tempo corrente è <0 siamo in ritardo
	{
		tr.add_ritardo(-(time_diff));
	}
	else if (time_diff > 5)					//se l'anticipo è <5 minuti viene consumato con la salita/discesa passeggeri
	{
		stopping_time = time_diff;			//se è >5min diventa il tempo di fermata in stazione
	}

	railway_simulation.schedule_event(new Starting_event(railway_simulation, time+stopping_time, tr));
}
