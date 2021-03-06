//AUTORE: Alberto Penzo

#ifndef STATION_H
#define STATION_H

#include "Treno.h"
#include <iostream>
#include <vector>
#include <string>
#include <queue>

class Station
{
public:
    virtual ~Station() {}
    virtual bool has_space();
    virtual int get_distance() const;
    virtual std::string get_name() const;
    virtual std::string get_type() const;
    virtual void add_train();
    virtual void remove_train();
    virtual void add_to_parking(const Treno &tr);
    virtual Treno &remove_from_parking();
    virtual bool is_parking_empty();

protected:
    Station(int distance_origin, const std::string &name, const std::string &type);

private:
    int distance_to_origin;
    std::string station_name;
    const std::string type;
    int free_tracks;
    std::queue<Treno> parking_lot;
};

#endif