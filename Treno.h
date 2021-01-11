//AUTORE: Leonardo Fasolo

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Station.h"
#include <list>


class Treno{
public:
	Treno(std::list<Station*>& railway, int codice, int origin, int tipo, std::vector<int> timetable);
	void CambioVel(int vel);
	void Incremento();
	int timetable_time();
	void add_ritardo(int rit);
	int getRitardo();
	Station* getNext();
	Station* getCurrent();
	Station* getEnd();
private:
	int v;
	int distS;
	int ritardo;
	int vMax;
	const int vMedia = 80;
	int CODICE;
	int origin;
	std::vector<int> TabOrari;
	int timetable_current;
	std::list<Station*>::iterator current;
	std::list<Station*>::iterator next;
	std::list<Station*>::iterator end;
};