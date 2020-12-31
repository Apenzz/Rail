#include "Station.h"
#include <vector>
#include <string>

using std::string;
using std::vector;

class Local_station : public Station
{
public:
private:
    const string station_type = "locale";
    vector<Train> transit_rail; //Train e' un placeholder
    //TODO
};