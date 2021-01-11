#ifndef MAIN_STATION_H
#define MAIN_STATION_H

#include "Station.h"
#include <string>
#include <vector>

class Main_station : public Station
{
private:
    const std::string station_type = "principale";
    int free_tracks; //[0,4] se 0 allora stazione piena
    //std::vector<bool> passenger_tracks;

public:
    Main_station(int distance_origin, const std::string &name);

    virtual std::string get_type();

    virtual bool has_space();
};

#endif