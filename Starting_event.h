//AUTORE: Alessio Gottardo

#pragma once
#include "Event.h"
#include "Simulation.h"
#include "Station.h"
#include "Treno.h"
#include "Arriving_event.h"
#include <iostream>

class Starting_event : public Event
{
public:
	Starting_event(Simulation* sim, int time, const Treno& treno);

	virtual void do_event();

private:
	Treno tr;
	Simulation* railway_simulation;
};