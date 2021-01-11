#include <iostream>
#include <string>
#include "Main_station.h"

using std::string;

Main_station::Main_station(int distance_origin, const std::string &name)
    : Station(distance_origin, name, "principale"), free_tracks{4}
{
}

string Main_station::get_type()
{
    return station_type;
}

bool Main_station::has_space()
{
    return free_tracks != 0;
}
