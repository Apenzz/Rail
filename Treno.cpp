//AUTORE: Leonardo Fasolo

#include "Treno.h"
#include "Station.h"
#include <iostream>
using namespace std;

Treno::Treno(list<Station*>& railway, int cod, int origin, int tipo, vector<int> timetable) {
	if (tipo == 1)
		vMax = 160;
	if (tipo == 2)
		vMax = 240;
	if (tipo == 3) {
		vMax = 300;
	}
	
	codice= cod;
	v = 0;
	ritardo = 0;
	distS = 0;
	timetable_current = 0;
	TabOrari = timetable;
	type = tipo;
	linea_ferroviaria = railway;
	if (origin == 0) {
		current = linea_ferroviaria.begin();
		next = (++(linea_ferroviaria.begin()));
		end = (linea_ferroviaria.rbegin());
	}
	else {
		rcurrent = linea_ferroviaria.rbegin();
		rnext = ++linea_ferroviaria.rbegin();
		rend = linea_ferroviaria.begin();
	}
	std::cout << (*next)->get_name() << std::endl;
}

void Treno::CambioVel(int vel) {
	v = vel;
}

void Treno::Incremento() {
	
	if (origin == 0) {
		current++;
		next++;
	}
	else {
		rcurrent++;
		rnext++;
	}
}

int Treno::timetable_time() {
	return TabOrari[timetable_current];
}

void Treno::next_time() {
	timetable_current++;
}

void Treno::add_ritardo(int rit) {
	ritardo = ritardo + rit;
}

int Treno::getRitardo() { return ritardo; }
int Treno::getCodice() { return codice; }
Station* Treno::getNext() { 
	if (origin == 0) return (*next);
	else return (*rnext);
}
Station* Treno::getCurrent() { 
	Station* st = (*current);
	if (origin == 0) return st;
	else return (*rcurrent);
}
Station* Treno::getEnd() { 
	if (origin == 0) return (*end);
	else return (*rend);
}
int Treno::get_type() { return type; }
int Treno::getVel()	{ return vMax; }