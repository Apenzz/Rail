#include "Event.h"
#include "Simulation.h"
#include "Train.h"

class Starting_event : public Event
{
public:
	Starting_event(Simulation* sim, int time, const Train& treno);

	virtual void do_event();

private:
	Train tr;
	Simulation* railway_simulation;
};