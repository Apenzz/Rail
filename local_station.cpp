#include <iostream>
#include "Local_station.h"

using namespace std;

Local_station::Local_station(double distance_origin, const std::string &name)
    : Station(distance_origin, name), transit_tracks(2, false) {}