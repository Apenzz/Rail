#include <vector>

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
    std::vector<bool> default_rail;

    //TODO
};