#ifndef STATION_H
#define STATION_H

#include <vector>
#include <string>

using std::vector;

class Station
{
public:
    Station(const Station &) = delete;
    Station &operator=(const Station &) = delete;
    virtual ~Station() {}

protected:
    Station(double distance_origin, const std::string &name)
        : distance_to_origin{distance_origin}, station_name{name} {}

    inline virtual bool is_terminus();

private:
    double distance_to_origin;
    std::string station_name;
    vector<int> parking_lot; //int e' un placeholder
    bool terminus;
    //const Station *prev;
    //const Station *next;

    //TODO
};

#endif