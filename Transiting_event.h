#include "Event.h"
#include "Simulation.h"
#include "Train.h"

class Transiting_event : public Event
{
public:
	Transiting_event(Simulation* sim, int time, const Train& treno);

	virtual void do_event();

private:
	Train tr;
	Simulation* railway_simulation;
};
