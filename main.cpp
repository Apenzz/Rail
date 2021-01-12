//AUTORE: Alessio Gottardo

#include "Station.h"
#include "Treno.h"
#include "railway_input.h"
#include "trains_input.h"
#include "Simulation.h"
#include "Starting_event.h"
#include <iostream>
#include <list>
#include <vector>

int main()
{	
	std::list<Station*> railway = stations_input();														//inizializzo tutte le stazioni

	for (std::list<Station*>::iterator itr = railway.begin(); itr != railway.end(); itr++)				//prova di stampa RAILWAY
	{
		std::cout << " -nome: " << (*itr)->get_name();
		std::cout << "-tipo: " << (*itr)->get_type();
		std::cout << " -distanza: " << (*itr)->get_distance();
		std::cout << " -indirizzo: " << (*itr) <<"\n";
	}

	std::vector<Treno*> trains = timetable_input(railway);												//inizializzo tutti i treni

	for (int i = 0; i < railway.size(); i++)																//rpova
	{
		
		std::cout << "Treno " << i << " in partenza alle ore: " << trains[0]->timetable_time() << "\n";
		//trains[0]->next_time();
	}

	Simulation* day=new Simulation();

	for (int i = 0; i < trains.size(); i++)
	{
		day->schedule_event(new Starting_event(day, trains[i]->timetable_time(), (*trains[i])));
	}

	std::cout << "\n--- AVVIO SIMULAZIONE ---\n";
	day->run();
	
	delete day;
}


