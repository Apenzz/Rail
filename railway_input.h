#include<iostream>
#include <fstream>
#include<sstream>
#include<vector>
#include<string>
#include <list>
#include"Station.h"
#include "Main_station.h"
#include "Local_station.h"

std::list<Station*> stations_input();					//funzione per inizializzare la linea ferroviaria ricevendo in input "line_description.txt"

void insert_in_order(std::list<Station*>& my_list, std::string name, int type, int distance);	//funzione per inserire una stazione nella linea ferroviaria ordinandola in base alla sua distanza dall'origine

bool compare(Station* a, int d);						//funzione per comparare una distanza appena letta dal file di input con la distanza di una stazione già inizializzata