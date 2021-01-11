#include "Starting_event.h"
#include<iostream>

Starting_event::Starting_event(Simulation* sim, int time, const Train& treno)
	: Event{time}, railway_simulation{sim}, tr{treno}	{}


void Starting_event::do_event()
{
	if (tr.getNext()==tr.getEnd())																//se siamo al capolinea non fa nulla
	{
		std::cout << "AVVISO: il treno è arrivato al capolinia, scendere prego.\n";
		std::cout << "COMUNICAZIONE: il ritardo totale accumulato è di " << tr.getRitardo() << " minuti.\n";				//comunica il ritardo totale accumulato
	}
	else
	{
		int section_time;

		if (tr.get_type() == 1)																					//se è regionale si ferma in ogni stazione
		{
			section_time = ((tr.getNext().get_distance() - tr.getCurrent().get_distance() - 10) / 180) * 60;			//tempo in minuti di percorrenza tra le due stazioni
			section_time += (5 / 80) * 60;																		//tempo in min di percorrenza del tratto a velocità limitata della stazione da cui sta partendo
		}

		if (tr.get_type() == 2 || tr.get_type() == 3)
		{
			if (tr.getCurrent().get_type() == "principale")
			{
				section_time = (5 / 80) * 60;																		//se si è appena fermato deve rispettare i limiti di velocità
				if (tr.get_type() == 2)
					section_time += ((tr.getNext().get_distance() - tr.getCurrent().get_distance() - 10) / 240) * 60;		//tempo in min per percorrere la tratta rimanente togliendo i 5km prima
				if (tr.get_type() == 3)
					section_time += ((tr.getNext().get_distance() - tr.getCurrent().get_distance() - 10) / 300) * 60;
			}
			else 																								//se è passato per i binari di transito della locale non ha limiti di velocità
			{
				if (tr.get_type() == 2)
					section_time = ((tr.getNext().get_distance() - tr.getCurrent().get_distance() - 5) / 240) * 60;	//calcolo il tempo lungo tutta la tratta
				if (tr.get_type() == 3)
					section_time = ((tr.getNext().get_distance() - tr.getCurrent().get_distance() - 5) / 300) * 60;
			}
		}

		railway_simulation.schedule_event(new Arriving_event(railway_simulation, time+section_time, tr));       //aggiunge alla coda della simulazione un evento di tipologia arriving

		tr.getCurrent().remove_train();							//aggiorna la variabile che indica i binari liberi della stazione

		if (tr.getCurrent().is_parking_empty())									//se ci sono treni nell'area di parcheggio
		{
			railway_simulation.schedule_event(new Arriving_event(railway_simulation, time, tr.getCurrent().parcking_lot().remove_from_parking()));			//chiama istantaneamente evento del treno che arriva in stazione
		}

		tr.incremento();																			//aggiorna i puntatori
	}
	
}