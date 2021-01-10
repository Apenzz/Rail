#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include "Station.h"
#include "Main_station.h"
#include "Local_station.h"
#include "railway_input.h"

//using namespace std;



int main()
{
	std::list<Station*> railway = stations_input();

	for (std::list<Station*>::iterator itr = railway.begin(); itr != railway.end(); itr++)				//prova di stampa RAILWAY
	{
		std::cout << " -nome: " << (*itr)->get_name();
		std::cout << "-tipo: " << (*itr)->get_type();
		std::cout << " -distanza: " << (*itr)->get_distance();
		std::cout << " -indirizzo: " << *itr<<"\n";
	}
}


