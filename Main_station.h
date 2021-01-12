//AUTORE: Alberto Penzo

#ifndef MAIN_STATION_H
#define MAIN_STATION_H

#include "Station.h"

class Main_station : public Station
{
private:
    const std::string station_type = "principale";
    int free_tracks; //[0,4] se 0 allora stazione piena

public:
    Main_station(int distance_origin, const std::string &name);

    virtual std::string get_type();

};

#endif