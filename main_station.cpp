#include <iostream>
#include <string>
#include "Main_station.h"

using std::string;

Main_station::Main_station(double distance_origin, const std::string &name)
    : Station(distance_origin, name), passenger_tracks(4, false)
{
    if (distance_origin == 0)
    {
    }
}

string Main_station::get_type()
{
    return station_type;
}