#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "Station.h"
#include "Main_station.h"
#include "Local_station.h"

using namespace std;

int main()
{
    Local_station st1(0, "venezia");
    Main_station st2(12, "Padova");
    st1.get_type();
    list<Main_station> railway;
    railway.push_back(st2);
    cout << st2.has_space();
    cout << st2.get_type();
    cout << st1.get_type();
}