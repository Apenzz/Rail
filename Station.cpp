#include <iostream>
#include "Station.h"

using namespace std;

Station::Station(double distance_origin, const std::string &name)
    : distance_to_origin{distance_origin}, station_name{name}
{
    (distance_to_origin == 0) ? terminus = true : terminus = false;
}

bool Station::is_terminus()
{
    return distance_to_origin == 0;
}