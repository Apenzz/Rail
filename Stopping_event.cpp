//AUTORE: Alessio Gottardo

#include "Stopping_event.h"

Stopping_event::Stopping_event(Simulation* sim, int time, const Treno& treno)
	: Event{ time }, railway_simulation{ sim }, tr{ treno }	{}


void Stopping_event::do_event()
{
	tr.Incremento();
	std::cout << "AVVISO: il treno " << tr.getCodice() << " è arrivato a " << tr.getCurrent()->get_name() << " alle ore: " << time << std::endl;

	int stopping_time = 5;					//tempo salita/discesa passeggeri
	tr.next_time();
	int time_diff = (time - tr.timetable_time());
	

	tr.add_ritardo(time_diff);
	//std::cout << "COMUNICAZIONE: il ritardo del treno " << tr.getCodice() << " è aumentato di " << time_diff << " minuti in totale è " << tr.getRitardo() << std::endl;
	



	//std::cout << "Stopping calc: " << time + stopping_time << std::endl;
	railway_simulation->schedule_event(new Starting_event(railway_simulation, time+stopping_time, tr));				//prossimo evento: treno in partenza
}
