#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include "Station.h"
#include "Main_station.h"
#include "Local_station.h"

//using namespace std;

void sort(int, std::vector<std::string>&, std::vector<int>&, std::vector<int>&);

int main()
{
    //Local_station st1(0, "venezia");
    //Main_station st2(12, "Padova");
    //st1.get_type();
    //list<Main_station> railway;
    //railway.push_back(st2);
    //cout << st2.has_space();
    //cout << st2.get_type();
    //cout << st1.get_type();

    //-----------------------------------

	std::vector<std::string> stazioni;
	std::vector<int> principali;
	std::vector<int> distanze;

	std::ifstream linea_ferroviaria;
	linea_ferroviaria.open("line_description.txt");

	int i = 1;

	if (linea_ferroviaria.is_open())
	{
		std::string line;
		getline(linea_ferroviaria, line);							//prima riga

		stazioni.push_back(line);			//stazione di partenza
		principali.push_back(0);			//è principale
		distanze.push_back(0);				//distanza = 0km

		while (std::getline(linea_ferroviaria, line)) {				//prossima riga (finchè ce ne sono)

			std::string name;										//variabile "string" di appoggio	
			stazioni.push_back(name);								//eseguo qui un push back "vuoto" cosi inizializza i nomi delle stazioni e nel loop successivo posso usare += nel caso in cui il nome sia formato da più parole
			int integers;											//variabile "int" di appoggio (per verificare il tipo di dato in input)

			std::stringstream ss(line);								//creo uno string stream formato da tutta la linea

			while (ss >> name || !ss.eof())							//loop che prosegue fino a fine linea (!ss.eof() facoltativo, fa >> in automatico)	
			{

				if (std::stringstream(name) >> integers)			//utilizzo uno string stream per verificare se la prossima word è un integer
				{													//se si carica senza problemi entra e prosegue

					principali.push_back(integers);					//se e' entrato significa che ha trovato 0/1 cioè il valore da inserire nell'array "principali"
					ss >> integers;									//passa alla parola(numero) successiva (distanza)
					distanze.push_back(integers);					//inserisco nell'array "distanze"

					if (distanze[i] < distanze[i - 1])				//se la distanza è < della precedente ordino
					{

						sort(i, stazioni, principali, distanze);

					}
				}
				else												//se non e' un numero significa che il nome della stazione e' formato da piu' parole...
				{
					stazioni[i] += name + " ";						//...quindi lo aggiungo
				}
			}
			i++;
		}

		linea_ferroviaria.close();									//chiudo stream di input del file
	}
	else
	{
		std::cout << "Unable to open file.";
	}



	//memorizzato tutto?
	for (int j = 0; j < i; j++)
	{
		std::cout << "stazione: " << stazioni[j];
		std::cout << "; principale? ";
		if (principali[j] == 0)
			std::cout << "SI";
		else
			std::cout << "NO";
		std::cout << "; distanza: " << distanze[j] << "." << std::endl;

	}


	//----------------------------------------------------------

	std::list<Station*> railway;								//linea ferroviaria: lista di puntatori a station

	std::vector<Local_station> locals;
	std::vector<Main_station> mains;

	for (int j = 0; j < stazioni.size(); j++)
	{
		if (principali[j] == 0)
		{
			Main_station st(distanze[j], stazioni[j]);			//inizializzo la main station
			mains.push_back(st);								//la inserisco nel vettore che le memorizza

			railway.push_back(&mains.back());					//ins in railway l'indirizzo dell'ultima main station (quella appena inserita)

			std::cout << "main addr: " << &mains.back() << std::endl;
		}
		else if (principali[j] == 1)
		{
			Local_station st(distanze[j], stazioni[j]);			
			locals.push_back(st);

			railway.push_back(&locals.back());					//ins in railway l'indirizzo dell'ultima local station 

			std::cout << "local addr: " << &locals.back() << std::endl;
		}
	}

	std::cout <<"\ndimensioni vettori: "<< locals.size() << " , " << mains.size() << std::endl;
	std::cout << railway.size() << std::endl;

	if(locals[1].has_space())
		std::cout << "\nhas space, ";
	std::cout << locals[1].get_type()<<"\n\n";

	for (std::list<Station*>::iterator it = railway.begin(); it != railway.end(); ++it) 
	{
		std::cout <<"station address: "<< *it<<"\n";
	}

	
}


void sort(int c, std::vector<std::string>& stazioni, std::vector<int>& principali, std::vector<int>& distanze)
{

	do {

		std::string temp1;
		int temp2;

		temp1 = stazioni[c];								//switch con il precedente
		stazioni[c] = stazioni[c - 1];
		stazioni[c - 1] = temp1;

		temp2 = principali[c];
		principali[c] = principali[c - 1];
		principali[c - 1] = temp2;

		temp2 = distanze[c];
		distanze[c] = distanze[c - 1];
		distanze[c - 1] = temp2;

		c--;

	} while (c != 0 && distanze[c] < distanze[c - 1]);	//ciclo si ripete se la distanza nella sua nuova posizione è ancora < della precedente

}
