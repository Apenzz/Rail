//AUTORE: Alberto Penzo

#include "Local_station.h"
#include <vector>
#include <string>
#include <iostream>

using namespace std;

Local_station::Local_station(int distance_origin, const std::string &name)
    : Station(distance_origin, name, "locale"), transit_tracks{2} {}