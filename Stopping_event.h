//AUTORE: Alessio Gottardo

#pragma once
#include "Event.h"
#include "Simulation.h"
#include "Station.h"
#include "Treno.h"
#include "Starting_event.h"
#include<iostream>

class Stopping_event : public Event
{
public:
	Stopping_event(Simulation* sim, int time, const Treno& treno);

	virtual void do_event();

private:
	Treno tr;
	Simulation* railway_simulation;
};
