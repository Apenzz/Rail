//AUTORE: Alberto Penzo

#include "Main_station.h"
#include <string>
#include <vector>
#include <iostream>

using std::string;

Main_station::Main_station(int distance_origin, const std::string &name)
    : Station(distance_origin, name, "principale")
{
}

string Main_station::get_type()
{
    return station_type;
}
