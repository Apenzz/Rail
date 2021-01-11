#include "Treno.h"
#include "Station.h"
#include <iostream>

using namespace std;

Station::Station(int distance_origin, const std::string &name, const std::string &t)
    : distance_to_origin{distance_origin}, station_name{name}, type{t}, free_tracks{4}
{
}

int Station::get_distance() const
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

void Station::add_train(const Treno &tr)
{
    free_tracks -= 1;
}

void Station::remove_train(const Treno &tr)
{
    free_tracks += 1;
}

void Station::add_to_parking(const Treno &tr)
{
    parking_lot.push(tr);
}

Treno &Station::remove_from_parking()
{
    Treno tr = parking_lot.front();
    parking_lot.pop();
    return tr;
}