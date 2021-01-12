//AUTORE: Alberto Penzo

#ifndef LOCAL_STATION_H
#define LOCAL_STATION_H

#include "Station.h"

class Local_station : public Station
{
public:
    Local_station(int distance_origin, const std::string &name);

private:
    int transit_tracks;
};

#endif