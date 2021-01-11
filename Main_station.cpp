#include <iostream>
#include <string>
#include "Main_station.h"

using std::string;

Main_station::Main_station(int distance_origin, const std::string &name)
    : Station(distance_origin, name, "principale")
{
}

string Main_station::get_type()
{
    return station_type;
}
