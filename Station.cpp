#include <iostream>
#include "Station.h"

using namespace std;

Station::Station(double distance_origin, const std::string &name, const std::string &t)
    : distance_to_origin{distance_origin}, station_name{name}, type{t}
{
}

double Station::get_distance() const
{
    return distance_to_origin;
}

string Station::get_name() const
{
    return station_name;
}

string Station::get_type() const
{
    return type;
}

bool Station::has_space()
{
    return free_tracks != 0;
}