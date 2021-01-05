#ifndef STATION_H
#define STATION_H

#include <vector>
#include <string>

using std::vector;

class Station
{
public:
    //Station(const Station &) = delete;
    //Station &operator=(const Station &) = delete;
    virtual ~Station() {}
    virtual bool has_space();
    virtual double get_distance() const;
    virtual std::string get_name() const;
    virtual std::string get_type() const;

protected:
    Station(double distance_origin, const std::string &name, const std::string &type);

private:
    double distance_to_origin;
    std::string station_name;
    const std::string type;
    int free_tracks;
    vector<int> parking_lot; //int e' un placeholder
    //const Station *prev;
    //const Station *next;

    //TODO
};

#endif