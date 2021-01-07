#ifndef LOCAL_STATION_H
#define LOCAL_STATION_H

#include "Station.h"
#include <vector>
#include <string>

class Local_station : public Station
{
public:
    Local_station(double distance_origin, const std::string &name);

private:
    int transit_tracks;
    //TODO
};

#endif