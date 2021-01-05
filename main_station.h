#ifndef MAIN_STATION_H
#define MAIN_STATION_H

#include "station.h"
#include <string>
#include <vector>

using std::string;
using std::vector;

class Main_station : public Station
{
private:
    const string station_type = "principale";
    std::vector<bool> passenger_tracks;

public:
    Main_station(double distance_origin, const std::string &name);

    inline std::string get_type();

    virtual bool is_terminus() override;
    //TODO
};

#endif