//AUTORE: Leonardo Fasolo

#pragma once

#include <iostream>
#include <string>
#include <vector>
#include <list>

class Station;

class Treno{
public:
	Treno(std::list<Station*>& railway, int codice, int origin, int tipo, std::vector<int> timetable);
	void CambioVel(int vel);
	void Incremento();
	int timetable_time();
	void next_time();
	void add_ritardo(int rit);
	int getRitardo();
	int get_type();
	int getCodice();
	int getVel();
	Station* getNext();
	Station* getCurrent();
	Station* getEnd();

private:
	int v;
	int distS;
	int type;
	int ritardo;
	int vMax;
	const int vMedia = 80;
	int codice;
	int origin;
	std::vector<int> TabOrari;
	int timetable_current;
	std::list<Station*>::iterator current;
	std::list<Station*>::reverse_iterator rcurrent;
	std::list<Station*>::iterator next;
	std::list<Station*>::reverse_iterator rnext;
	std::list<Station*>::iterator rend;
	std::list<Station*>::reverse_iterator end;
	std::list<Station*> linea_ferroviaria;
};