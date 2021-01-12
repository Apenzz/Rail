//AUTORE: Alessio Gottardo

#pragma once
#include "Station.h"
#include "Treno.h"
#include "railway_input.h"

std::vector<Treno*> timetable_input(std::list<Station*> railway);