#ifndef LOCAL_STATION_H
#define LOCAL_STATION_H

#include "Station.h"
#include <vector>
#include <string>

class Local_station : public Main_station
{
public:
    Local_station(double distance_origin, const std::string &name);

private:
    std::vector<bool> transit_tracks;
    //TODO
};

#endif