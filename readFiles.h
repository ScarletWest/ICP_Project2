//
// Created by NY on 11/30/22.
//

#ifndef ICP_PROJECT2_READFILES_H
#define ICP_PROJECT2_READFILES_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <string>
#include <cstring>
#include <stdlib.h>
#include <list>
#include <algorithm>
#include <map>
#include <stdexcept>
#include <cstring>
#include <queue>
#include <unordered_set>
using namespace std;

class readFiles {
public:
    static vector<vector<string>> airportInfo;
    static vector<vector<string>> routeInfo;

    static vector<string> getAirportByCityCountry(const string& city, const string& country);
    static void readAirportFile();
    static void readRouteAirline();
};


#endif //ICP_PROJECT2_READFILES_H
