#include "trains_input.h"

vector<Treno> timetable_input(std::list<Station*>& railway)				//const??
{
	vector<Treno> trains;

	std::ifstream timetables("timetables.txt");

	if (timetables.is_open())
	{
		int train_code;						//numero treno
		int train_start;					//stazione partenza
		int train_type;						//tipologia treno
		int minutes;						//tempi nella timetable	
		std::string line;

		while (getline(timetables, line))					//leggo tutte le righe del file
		{
			std::stringstream ss(line);	
			
			vector<int> timeline;
			ss >> train_code;
			ss >> train_start;
			ss >> train_type;
			ss >> minutes;
			timeline.push_back(minutes);					//orario di partenza
			std::list<Station*>::iterator it = railway.begin();
			double expected_time = minutes;
			while (ss >> minutes && it != --railway.end())		//se il numero di orari supera il numero di stazioni gli ignoro
			{
				std::list<Station*>::iterator current = it;
				if (train_type == 1)
				{
					expected_time += (((double)(*(++it))->get_distance() - (*(current))->get_distance() - 10) / 160) * 60 + ((10 / 80) * 60);		//tempo previsto per regionale
				}
				else 
				{
					while ((*++it)->get_type() != "principale") { }		//passo alla prossima stazione principale
					if (train_type == 2)
					{
						expected_time += (((double)(*(it))->get_distance() - (*(current))->get_distance() - 10) / 240) * 60 + ((10 / 80) * 60);		//tempo previsto per alta velocità
						
					}
					else if (train_type == 3)
					{
						expected_time += (((double)(*(it))->get_distance() - (*(current))->get_distance() - 10) / 300) * 60 + ((10 / 80)*60);		//tempo previsto per alta velocità super
					}					
				}
				if(minutes<expected_time)																				//se non corrispondono, cambio la timetable
				{
					minutes = expected_time + 11;																				//aggiungo 10 minuti di margine
					std::cout << "AVVISO: timetable modificata perche' tempi non compatibili-\n";
				}
				
				timeline.push_back(minutes);																					//inserisco nella timeline del treno
																														//prossima stazione
			}

			trains.push_back(Treno(railway, train_code, train_start, train_type, timeline));								//inizializzo il treno e lo aggiungo al vettore che li memorizza
		
		}
	}
	else
	{
		std::cout << "Errore apertura file\n";
	}
	//return trains;
	return trains;
}