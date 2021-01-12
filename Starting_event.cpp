//AUTORE: Alessio Gottardo

#include "Starting_event.h"

Starting_event::Starting_event(Simulation* sim, int time, const Treno& treno)
	: Event{time}, railway_simulation{sim}, tr{treno}	{}


void Starting_event::do_event()
{
	if (tr.getCurrent()==tr.getEnd())																//se siamo al capolinea non fa nulla
	{
		std::cout << "AVVISO: il treno "<< tr.getCodice()<< "è arrivato al capolinia, scendere prego.\n";
		std::cout << "COMUNICAZIONE: il ritardo totale accumulato dal treno "<< tr.getCodice()<<" è di " << tr.getRitardo() << " minuti.\n";				//comunica il ritardo totale accumulato
	}
	else
	{
		int section_time;

		if (tr.get_type() == 1)																					//se è regionale si ferma in ogni stazione
		{
			section_time = (1.0*(tr.getNext()->get_distance() - tr.getCurrent()->get_distance() - 10) / tr.getVel()) * 60;			//tempo in minuti di percorrenza tra le due stazioni
			section_time += (5.0 / 80) * 60;																		//tempo in min di percorrenza del tratto a velocità limitata della stazione da cui sta partendo
		}

		else
		{
			if (tr.getCurrent()->get_type() == "principale")
			{
				section_time = (5.0 / 80) * 60;																		//se si è appena fermato deve rispettare i limiti di velocità
				section_time += (1.0*(tr.getNext()->get_distance() - tr.getCurrent()->get_distance() - 10) / tr.getVel()) * 60;		//tempo in min per percorrere la tratta rimanente togliendo i 5km prima
			}
			else 																								//se è passato per i binari di transito della locale non ha limiti di velocità
			{
				section_time = (1.0*(tr.getNext()->get_distance() - tr.getCurrent()->get_distance() - 5) / tr.getVel()) * 60;	//calcolo il tempo lungo tutta la tratta
			}
		}

		//std::cout<<"Starting calc: "<< time+section_time << std::endl;
		if(tr.get_type()==1 || tr.getCurrent()->get_type() == "principale" )
		std::cout << "AVVISO: Il treno " << tr.getCodice() << " è in partenza da "<<tr.getCurrent()->get_name() <<" alle ore: "<< time << std::endl;				//comunicazione treno in partenza

		railway_simulation->schedule_event(new Arriving_event(railway_simulation, time+section_time, tr));       //aggiunge alla coda della simulazione un evento di tipologia arriving

		tr.getCurrent()->remove_train();							//aggiorna la variabile che indica i binari liberi della stazione

		if (!tr.getCurrent()->is_parking_empty())									//se ci sono treni nell'area di parcheggio
		{
			railway_simulation->schedule_event(new Arriving_event(railway_simulation, time, tr.getCurrent()->remove_from_parking()));			//chiama istantaneamente evento del treno che arriva in stazione
		}

		tr.Incremento();																			//aggiorna i puntatori
	}
	
}