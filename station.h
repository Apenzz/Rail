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
    Station() {}

private:
    double distance_to_origin;
    vector<Train> default_rail;
    string station_name;
    vector<Train> parking_lot;

    //TODO
};