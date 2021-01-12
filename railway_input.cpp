//AUTORE: Alessio Gottardo

#include "railway_input.h"

std::list<Station*> stations_input()
{
	std::list<Station*> railway;

	std::ifstream input_file("line_description.txt");

	if (input_file.is_open())
	{
		std::string line;
		std::getline(input_file, line);
		
		railway.push_back(new Main_station(0, line));					//stazione d'origine

		while (std::getline(input_file, line))							//passa alla prossima riga (finchè ce ne sono)
		{
			std::string name;
			int distance;
			int type;

			std::string word;
			std::stringstream ss(line);									//creo uno stringstream con la riga corrente

			while (ss >> word)
			{
				if (std::stringstream(word) >> type)						//sfrutto stringstream per verificare se siamo arrivati al campo indicante la tipologia di stazione (0/1)
				{
					ss >> distance;											//se entra memorizza la distanza 
																			//siamo arrivati a fine riga quindi:
					insert_in_order(railway, name, type, distance);			//inizializza un nuovo nodo della lista nella giusta posizione con i dati ricavati
				}
				else
				{
					name += word + ' ';										//se non ha trovato un numero intero significa che il nome era formato da più parole. le aggiungo
				}
			}
		}
		input_file.close();
	}
	else
	{
		std::cout << "unable to open file.\n";
	}

	return railway;
}



void insert_in_order(std::list<Station*> &my_list, std::string name, int type, int distance)		
{
	std::list<Station*>::iterator begin = my_list.begin();
	std::list<Station*>::iterator end = my_list.end();
	while ((begin != end) && (compare(*begin, distance)))					//incrementa l'iteratore begin se la distanza appena ricevuta è maggiore di quella della stazione puntata
		++begin;

	if (distance - (*(--begin))->get_distance() >= 20)							//se la distanza è minore di 20 ignora la stazione appena inserita
	{
		if (type == 0)															//se è principale
			my_list.insert(++begin, new Main_station(distance, name));			//inizializza l'oggetto Main_station e inserisce il suo puntatore nella posizione indicata da begin

		if (type == 1)															//se è secondaria fa altrettanto
			my_list.insert(++begin, new Local_station(distance, name));
	}
}

bool compare(Station* a, int d) {
	return a->get_distance() <= d ;
}