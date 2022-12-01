//
// Created by NY on 11/30/22.
//

#ifndef ICP_PROJECT2_READFILES_H
#define ICP_PROJECT2_READFILES_H

#include "Path.h"
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
    static vector<Path> validPaths;

    static vector<string> getAirportByCityCountry(const string& city, const string& country);
    static void readAirportFile();
    static void readRouteFile();
    static vector<vector<string>> readInputFile();
    static void addPath(Path path);
    static void writeOutputFile(const string& filename, const string& data);
};


#endif //ICP_PROJECT2_READFILES_H
